

char* socket_start_header(int fd,char* buff, int status_code, 
char* status_text,char* type_content,char* charset){
	char* stats=libc_itos(status_code);
libc_strcpy(buff,"");
libc_strcat(buff,"HTTP/1.1 ");
libc_strcat(buff,stats);
libc_strcat(buff," ");
libc_strcat(buff,status_text);
libc_strcat(buff,"\r\n");
libc_strcat(buff,"Content-Type: ");
libc_strcat(buff,type_content);
libc_strcat(buff,"; ");
//img:Accept-Ranges:bytes
if(libc_strlen(charset)>1){
libc_strcat(buff,"charset=");
libc_strcat(buff,charset);
}
libc_strcat(buff,"\r\n");
libc_strcat(buff,"Server:Unicc-framework\r\n");
free_ptr(stats);
return buff;	
																												}
//----------------------------------------------------------------------
char* socket_end_header(int fd,char* buff,char* connection, long body_size){
	char*bsize= libc_itos(body_size);
libc_strcat(buff,"Content-Length: ");
libc_strcat(buff,bsize);
libc_strcat(buff,"\r\n");
libc_strcat(buff,"Connection: ");
libc_strcat(buff,connection);
libc_strcat(buff,"\r\n");
libc_strcat(buff,"\r\n");
free_ptr(bsize);
return buff;	
	}																												
//----------------------------------------------------------------------

struct HTTP{
char* HTTP_METHOD;
char* HTTP_HOST;
char* HTTP_URL;
char* HTTP_REFERER;
char* HTTP_USER_AGENT;
char* HTTP_COOKIE;
char* HTTP_RESOURCE;
char* HTTP_CONNECTION;
char* HTTP_REQUEST;
char* HTTP_PROTOCOL;
int   HTTP_STATUS;	
	};
void parse_http_header_free(struct HTTP* client){
	free(client->HTTP_METHOD);
	free(client->HTTP_HOST);
	free(client->HTTP_PROTOCOL);
	free(client->HTTP_REQUEST);
	free(client->HTTP_URL);
return;	
	}	
int parse_http_header(char* buffer, struct HTTP* client){
	client->HTTP_METHOD=malloc(0);
	client->HTTP_HOST=malloc(0);
	client->HTTP_PROTOCOL=malloc(0);
	client->HTTP_REQUEST=malloc(0);
	client->HTTP_URL=malloc(0);
	
	int i,fl_met=0,fl_prot=0,fl_host=0,index=0;
	
if ( !libc_strncmpi(buffer, "GET ", 4) ) {
	    client->HTTP_METHOD = "GET";
	    buffer +=4;
	    fl_met=1;
	}
	else if ( !libc_strncmpi(buffer, "POST ", 5) ) {
	    client->HTTP_METHOD = "POST";
	    buffer +=5;
	    fl_met=1;
	}
	else {
	    client->HTTP_METHOD = "UNSUPPORTED";
	    client->HTTP_STATUS = 501;
	    fl_met=0;
	    return -1;
	}
	

	
	
	i=0;
	while(*buffer!=' '){client->HTTP_REQUEST[i]=ccpy(*buffer);buffer++;i++;}
	client->HTTP_REQUEST[i]='\0';
	buffer++;

	
	if(!libc_strncmpi(buffer, "HTTP/", 5)){
	i=0,index=0;
	fl_prot=1;
	while(*buffer!='\n'){client->HTTP_PROTOCOL[i]=ccpy(*buffer);buffer++;i++;}
	client->HTTP_PROTOCOL[i]='\0';
	buffer++;	
									}
	if(!libc_strncmpi(buffer, "Host: ", 6)){
	buffer += 6;
	fl_host=1;	
	i=0,index=0;
	while(*buffer!='\n'){client->HTTP_HOST[i]=ccpy(*buffer);buffer++;i++;}
	client->HTTP_HOST[i]='\0';
	buffer++;
			           }
		           
if(fl_prot==1 && fl_met==1 && fl_host==1){
	libc_strcpy(client->HTTP_URL,"http://");
	libc_strcat(client->HTTP_URL,client->HTTP_HOST);
	libc_strcat(client->HTTP_URL,client->HTTP_REQUEST);
	}else{
		return 0;
		}			           								

	
return 1;	
}
//----------------------------------------------------------------------
int loadfile(int client, int file){

    char c;
    int  i,n=0;

    while ( (i = read(file, &c, 1)) ) {
	if ( i < 0 ){libc_print_str("Error reading from file.");}
	if ( write(client, &c, 1) < 1 ){libc_print_str("Error sending file.");}
    n++;
    }

    return n;
}
