#include "/home/is/unicc/unicc.c"
///------------------------------------------------------------	

/*																	
int main(int argc, char** argv){

return 0;
						}
*/


#define MAX_REQ_LINE 	 1024
#define LISTENQ          1024
#define SERVER_PORT      8080

//----------------------------------------------------------------------
/*  Change this string to change the root directory that
    the server will use, i.e. /index.html will translate
    here to /home/httpd/html/index.html                   */

static char server_root[1000] = "/home/is/unicc/web/www/index.html";

//----------------------------------------------------------------------
enum Req_Method {GET,HEAD,POST,PUT,UNSUPPORTED};
enum Req_Type   {SIMPLE, FULL};

struct ReqInfo {
    enum Req_Method method;
    enum Req_Type   type;
    char           *referer;
    char           *useragent;
    char           *resource;
    int             status;
};
//----------------------------------------------------------------------
void    Error_Quit(char const * msg);
int     Trim      (char * buffer);
int     StrUpper  (char * buffer);
void    CleanURL  (char * buffer);
size_t Readline  (int sockd, void *vptr, size_t maxlen);
size_t Writeline (int sockd, const void *vptr, size_t n);
int Service_Request(int conn);
int  Parse_HTTP_Header(char * buffer, struct ReqInfo * reqinfo);
int  Get_Request      (int conn, struct ReqInfo * reqinfo);
void InitReqInfo      (struct ReqInfo * reqinfo);
void FreeReqInfo      (struct ReqInfo * reqinfo);
int Return_Resource (int conn, int resource, struct ReqInfo * reqinfo);
int Check_Resource  (struct ReqInfo * reqinfo);
int Return_Error_Msg(int conn, struct ReqInfo * reqinfo);
//----------------------------------------------------------------------
/*  Prints an error message and quits  */

void Error_Quit(char const * msg) {
    printf("WEBSERV: %s\n", msg);
    exit(1);
}

//----------------------------------------------------------------------
/*  Read a line from a socket  */

size_t Readline(int sockd, void *vptr, size_t maxlen) {
    size_t n, rc;
    char    c, *buffer;

    buffer = vptr;

    for ( n = 1; n < maxlen; n++ ) {
	
	if ( (rc = read(sockd, &c, 1)) == 1 ) {
	    *buffer++ = c;
	    if ( c == '\n' )
		break;
	}else if ( rc == 0 ) {
	    if ( n == 1 )
		return 0;
	    else
		break;
	}else{
	    //if ( errno == EINTR )
		continue;
	    Error_Quit("Error in Readline()");
	}
    }

    *buffer = 0;
    return n;
}

//----------------------------------------------------------------------
/*  Write a line to a socket  */

size_t Writeline(int sockd, const void *vptr, size_t n) {
    size_t      nleft;
    size_t     nwritten;
    const char *buffer;

    buffer = vptr;
    nleft  = n;

    while ( nleft > 0 ) {
	if ( (nwritten = write(sockd, buffer, nleft)) <= 0 ) {
	   // if ( errno == EINTR )
		nwritten = 0;
	   // else
		//Error_Quit("Error in Writeline()");
	}
	nleft  -= nwritten;
	buffer += nwritten;
    }

    return n;
}

//----------------------------------------------------------------------
/*  Removes trailing whitespace from a string  */

int Trim(char * buffer) {
    int n = strlen(buffer) - 1;

    while ( !isalnum(buffer[n]) && n >= 0 )
	buffer[n--] = '\0';

    return 0;
}

//----------------------------------------------------------------------
/*  Converts a string to upper-case  */
    
int StrUpper(char * buffer) {
    while ( *buffer ) {
	*buffer = toupper(*buffer);
	++buffer;
    }
    return 0;
}

//----------------------------------------------------------------------
/*  Cleans up url-encoded string  */
	
void CleanURL(char * buffer) {
    char asciinum[3] = {0};
    int i = 0, c;
    
    while ( buffer[i] ) {
	if ( buffer[i] == '+' )
	    buffer[i] = ' ';
	else if ( buffer[i] == '%' ) {
	    asciinum[0] = buffer[i+1];
	    asciinum[1] = buffer[i+2];
	    buffer[i] = libc_stol(asciinum);
	    c = i+1;
	    do {
		buffer[c] = buffer[c+2];
	    } while ( buffer[2+(c++)] );
	}
	++i;
    }
}
//----------------------------------------------------------------------
/*  Parses a string and updates a request
    information structure if necessary.    */

int Parse_HTTP_Header(char * buffer, struct ReqInfo * reqinfo) {

    static int first_header = 1;
    char      *temp;
    char      *endptr;
    int        len;


    if ( first_header == 1 ) {

	/*  If first_header is 0, this is the first line of
	    the HTTP request, so this should be the request line.  */


	/*  Get the request method, which is case-sensitive. This
	    version of the server only supports the GET and HEAD
	    request methods.                                        */

	if ( !strncmp(buffer, "GET ", 4) ) {
	    reqinfo->method = GET;
	    buffer += 4;
	}
	else if ( !strncmp(buffer, "HEAD ", 5) ) {
	    reqinfo->method = HEAD;
	    buffer += 5;
	}
	else {
	    reqinfo->method = UNSUPPORTED;
	    reqinfo->status = 501;
	    return -1;
	}


	/*  Skip to start of resource  */

	while ( *buffer && isspace(*buffer) )
	    buffer++;


	/*  Calculate string length of resource...  */

	endptr = strchr(buffer, ' ');
	if ( endptr == NULL )
	    len = strlen(buffer);
	else
	    len = endptr - buffer;
	if ( len == 0 ) {
	    reqinfo->status = 400;
	    return -1;
	}

	/*  ...and store it in the request information structure.  */

	reqinfo->resource = calloc(len + 1, sizeof(char));
	strncpy(reqinfo->resource, buffer, len);

	
	/*  Test to see if we have any HTTP version information.
	    If there isn't, this is a simple HTTP request, and we
	    should not try to read any more headers. For simplicity,
	    we don't bother checking the validity of the HTTP version
	    information supplied - we just assume that if it is
	    supplied, then it's a full request.                        */

	if ( strstr(buffer, "HTTP/") )
	    reqinfo->type = FULL;
	else
	    reqinfo->type = SIMPLE;

	first_header = 0;
	return 0;
    }


    /*  If we get here, we have further headers aside from the
	request line to parse, so this is a "full" HTTP request.  */

    /*  HTTP field names are case-insensitive, so make an
	upper-case copy of the field name to aid comparison.
	We need to make a copy of the header up until the colon.
	If there is no colon, we return a status code of 400
	(bad request) and terminate the connection. Note that
	HTTP/1.0 allows (but discourages) headers to span multiple
	lines if the following lines start with a space or a
	tab. For simplicity, we do not allow this here.              */

    endptr = strchr(buffer, ':');
    if ( endptr == NULL ) {
	reqinfo->status = 400;
	return -1;
    }

    temp = calloc( (endptr - buffer) + 1, sizeof(char) );
    strncpy(temp, buffer, (endptr - buffer));
    StrUpper(temp);


    /*  Increment buffer so that it now points to the value.
	If there is no value, just return.                    */

    buffer = endptr + 1;
    while ( *buffer && isspace(*buffer) )
	++buffer;
    if ( *buffer == '\0' )
     	return 0;


    /*  Now update the request information structure with the
	appropriate field value. This version only supports the
	"Referer:" and "User-Agent:" headers, ignoring all others.  */

    if ( !strcmp(temp, "USER-AGENT") ) {
	    reqinfo->useragent = malloc( strlen(buffer) + 1 );
	    strcpy(reqinfo->useragent, buffer);
    }
    else if ( !strcmp(temp, "REFERER") ) {
	    reqinfo->referer = malloc( strlen(buffer) + 1 );
	    strcpy(reqinfo->referer, buffer);
    }

    free(temp);
    return 0;
}

//----------------------------------------------------------------------
/*  Gets request headers. A CRLF terminates a HTTP header line,
    but if one is never sent we would wait forever. Therefore,
    we use select() to set a maximum length of time we will
    wait for the next complete header. If we timeout before
    this is received, we terminate the connection.               */

int Get_Request(int conn, struct ReqInfo * reqinfo) {

    char   buffer[MAX_REQ_LINE] = {0};
    int    rval;
    fd_set fds;
    struct timeval tv;


    /*  Set timeout to 5 seconds  */

    tv.tv_sec  = 5;
    tv.tv_usec = 0;


    /*  Loop through request headers. If we have a simple request,
	then we will loop only once. Otherwise, we will loop until
	we receive a blank line which signifies the end of the headers,
	or until select() times out, whichever is sooner.                */

    do {

	/*  Reset file descriptor set  */

	FD_ZERO(&fds);
	FD_SET (conn, &fds);



	rval = select(conn + 1, &fds, NULL, NULL, &tv);


	if ( rval < 0 ) {
	    Error_Quit("Error calling select() in get_request()");
	}
	else if ( rval == 0 ) {


	    return -1;

	}
	else {


	    Readline(conn, buffer, MAX_REQ_LINE - 1);
	    Trim(buffer);

	    if ( buffer[0] == '\0' )
		break;

	    if ( Parse_HTTP_Header(buffer, reqinfo) )
		break;
	}
    } while ( reqinfo->type != SIMPLE );

    return 0;
}

//----------------------------------------------------------------------

void InitReqInfo(struct ReqInfo * reqinfo) {
    reqinfo->useragent = NULL;
    reqinfo->referer   = NULL;
    reqinfo->resource  = NULL;
    reqinfo->method    = UNSUPPORTED;
    reqinfo->status    = 200;          
}

//----------------------------------------------------------------------

void FreeReqInfo(struct ReqInfo * reqinfo) {
    if ( reqinfo->useragent )
	free(reqinfo->useragent);
    if ( reqinfo->referer )
	free(reqinfo->referer);
    if ( reqinfo->resource )
	free(reqinfo->resource);
}
//----------------------------------------------------------------------
int Return_Resource(int conn, int resource, struct ReqInfo * reqinfo) {

    char c;
    int  i;

    while ( (i = read(resource, &c, 1)) ) {
	if ( i < 0 )
	    Error_Quit("Error reading from file.");
	if ( write(conn, &c, 1) < 1 )
	    Error_Quit("Error sending file.");
    }

    return 0;
}

//----------------------------------------------------------------------

int Check_Resource(struct ReqInfo * reqinfo) {

    CleanURL(reqinfo->resource);

    strcat(server_root, reqinfo->resource);
    return open(server_root, O_RDONLY,0);
}

//----------------------------------------------------------------------

int Return_Error_Msg(int conn, struct ReqInfo * reqinfo) {
    
    char buffer[100];

   // sprintf(buffer, "<HTML>\n<HEAD>\n<TITLE>Server Error %d</TITLE>\n</HEAD>\n\n", reqinfo->status);
    libc_strcpy(buffer,"<HTML>\n<HEAD>\n<TITLE>Server Error ");
    libc_strcat(buffer,libc_itos(reqinfo->status));
    libc_strcat(buffer,"</TITLE>\n</HEAD>\n\n");
    Writeline(conn, buffer, strlen(buffer));

    //sprintf(buffer, "<BODY>\n<H1>Server Error %d</H1>\n", reqinfo->status);
    libc_strcpy(buffer, "<BODY>\n<H1>Server Error ");
    libc_strcat(buffer,libc_itos(reqinfo->status));
    libc_strcat(buffer,"</H1>\n");
    Writeline(conn, buffer, strlen(buffer));

    //sprintf(buffer, "<P>The request could not be completed.</P>\n</BODY>\n</HTML>\n");
    libc_strcpy(buffer,"<P>The request could not be completed.</P>\n</BODY>\n</HTML>\n");
    Writeline(conn, buffer, strlen(buffer));

    return 0;

}
//----------------------------------------------------------------------

int Output_HTTP_Headers(int conn, struct ReqInfo * reqinfo) {

    char buffer[100];

    //sprintf(buffer, "HTTP/1.0 %d OK\r\n", reqinfo->status);
    libc_strcpy(buffer, "HTTP/1.0 ");
    libc_strcat(buffer,libc_itos(reqinfo->status));
    libc_strcat(buffer,"OK\r\n");
    
    
    Writeline(conn, buffer, strlen(buffer));

    Writeline(conn, "Server: PGWebServ v0.1\r\n", 24);
    Writeline(conn, "Content-Type: text/html\r\n", 25);
    Writeline(conn, "\r\n", 2);

    return 0;
}
//----------------------------------------------------------------------

int Service_Request(int conn) {

    struct ReqInfo  reqinfo;
    int             resource = 0;

    InitReqInfo(&reqinfo);

    

    if ( Get_Request(conn, &reqinfo) < 0 )
	return -1;

    
    if ( reqinfo.status == 200 )
	if ( (resource = Check_Resource(&reqinfo)) < 0 ) {
	  //  if ( errno == EACCES )
	//	reqinfo.status = 401;
	 //   else
		reqinfo.status = 404;
	}


    if ( reqinfo.type == FULL )
	Output_HTTP_Headers(conn, &reqinfo);


     if ( reqinfo.status == 200 ) {
	if ( Return_Resource(conn, resource, &reqinfo) )
	    Error_Quit("Something wrong returning resource.");
    }
    else
	Return_Error_Msg(conn, &reqinfo);

    if ( resource > 0 )
	if ( close(resource) < 0 )
	    Error_Quit("Error closing resource.");
    FreeReqInfo(&reqinfo);

    return 0;
}

//----------------------------------------------------------------------



int main(int argc, char *argv[]) {

    int    listener, conn;
    uni  pid;
    struct sockaddr_in servaddr;
    



    if ( (listener = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
	Error_Quit("Couldn't create listening socket.");

	printf("listener:%i\n",listener);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port        = htons(SERVER_PORT);



    if ( bind(listener, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0 )
	Error_Quit("Couldn't bind listening socket.");


 
    if ( listen(listener, LISTENQ) < 0 )
	Error_Quit("Call to listen failed.");

int i=0;

    while ( 1 ) {


	if ( (conn = accept(listener, NULL, NULL)) < 0 )
	    Error_Quit("Error calling accept()");

	printf("conn:%i\n",conn);

	if ( (pid = fork()) == 0 ) {

	    if ( close(listener) < 0 )
		Error_Quit("Error closing listening socket in child.");
	
	    
	    Service_Request(conn);

	    if ( close(conn) < 0 )
		Error_Quit("Error closing connection socket.");
	    
	}



	if ( close(conn) < 0 )
	    Error_Quit("Error closing connection socket in parent.");
	
	waitpid(-1, NULL, WNOHANG);
	printf("i:%i\n",i);
	i++;
	if(i>10){break;}
    }

    return 0;    
    }
