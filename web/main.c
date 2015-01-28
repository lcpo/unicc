#include "../unicc.c"
#include "construct.c"
///------------------------------------------------------------	

//char response[] = "<doctype !html><html><head><title>test index</title>"
//"</head>"
//"<body><a href='?abc=999'>999</a>|<a href='?abc=888'>888</a></html>\r\n";

//1. получить запрос и разобрать его
//2. Подгрузить файл если присутствует или отдать 404
//3. Если мы подгружали уже файл то сообщить чтобы брать из кеша
//4. написать контроллер обработчиков файлов к приме

																	
int main(int argc, char** argv){

  int one = 1, client_fd, read_size=0,sock,port;
  struct sockaddr_in svr_addr, cli_addr;
  socklen_t sin_len = sizeof(cli_addr);





   port = 8080;
 sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0){ printf("can't open socket\n"); exit(0);}
  
  setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(int));
 

  svr_addr.sin_family = AF_INET;
  svr_addr.sin_addr.s_addr = INADDR_ANY;
  svr_addr.sin_port = htons(port);
 
  if (bind(sock, (struct sockaddr *) &svr_addr, sizeof(svr_addr)) == -1) {
  close(sock);
  printf("Can't bind\n");
  exit(0);
  }
 
  listen(sock, 5);
  int i=0;
  while (1) {
    client_fd = accept(sock, (struct sockaddr *) &cli_addr, &sin_len);
 
    if (client_fd == -1) {printf("Can't accept\n");continue;}
    
//php-cgi -q /home/is/unicc/web/www/in.php
char* client_message=malloc(1024);
char* buff=malloc(1024);
char* server_root=malloc(1024);	
char* path=malloc(1024);
strcpy(server_root,"/home/is/unicc/web/www/");

   while( (read_size = recv(client_fd , client_message , 4096 , 0)) > 0 ){

 struct HTTP* client=malloc(1024);
 struct parsed_url* purl = malloc(1024);
		parse_http_header(client_message,client);
		purl=parse_url(client->HTTP_URL,purl);


if(strlen(purl->path)==0){
	purl->path="index.html";
	}else{
    if(purl->path[strlen(purl->path)-1]=='/'){strcat(purl->path,"index.html");}		
		}
		
	//echo ("scheme:",purl->scheme,"\n");
    //echo ("host:",purl->host,"\n");
    //echo ("port:",purl->port,"\n");
    //echo ("path:",purl->path,"\n");
    //echo ("query:",purl->query,"\n");
    //echo ("fragment:",purl->fragment,"\n");
    //echo ("username:",purl->username,"\n");
    //echo ("password:",purl->password,"\n");
    strcpy(path,server_root);
    strcat(path,purl->path);

struct stat_f *fi=malloc(sizeof(struct stat_f*));
stat(path,fi);
if(fi->st_atime==0 && fi->st_mtime==0 && fi->st_ctime==0){
	clear_stat(fi);client->HTTP_STATUS=404;
	}else{client->HTTP_STATUS=200;}


libc_print_str(path);
libc_print_str("\n");
int fres=0;
if((fres=open(path,O_RDONLY,0))<0){
	if(fres<0){client->HTTP_STATUS=404;}
	if(fres==-14){client->HTTP_STATUS=403;}
}else{client->HTTP_STATUS=200;}

if(client->HTTP_STATUS==200){
	
int copoint=libc_subchr_count(purl->path,'.');
int n=0;
while(libc_chrpos(purl->path++,'.')!=0){n++;}
char* mtype=malloc(32); char* charset=malloc(32); char* connection=malloc(10);

if(!libc_strncmpi(purl->path, "jpg", 4)){
	mtype="image/jpg";charset="";connection="keep-alive";}else
if(!libc_strncmpi(purl->path, "html", 5)){
	mtype="text/html";charset="UTF-8";connection="close";}else
if(!libc_strncmpi(purl->path, "php", 3)){
	mtype="text/html";charset="UTF-8";connection="keep-alive";}else
{mtype="text/plain";charset="UTF-8";connection="close";}
//printf("rash=.%s\n",purl->path);
purl->path-=n;
	
buff=socket_start_header($O,buff,client->HTTP_STATUS,"OK",mtype,charset);
buff=socket_end_header($O,buff,connection, fi->st_gid);
write(client_fd, buff, libc_strlen(buff));
loadfile(client_fd, fres);

close(fres);
clear_stat(fi);
free_ptr((void*)fi);
free(mtype);
free(charset);
free(connection);
}        

if(client->HTTP_STATUS==404){
buff=socket_start_header($O,buff,client->HTTP_STATUS,"Not Found","text/html","UTF-8");
buff=socket_end_header($O,buff,"close", 0);
write(client_fd, buff, libc_strlen(buff));
	}
    
        
  	
close(client_fd);
parsed_url_free(purl);
free_ptr((void*)purl); 
parse_http_header_free(client);
free_ptr((void*)client);
    }
    
free(client_message);
free(buff);
free(server_root);	
free(path);


    if(i>25){close(sock);break;}
    i++;
  }
  
  
	
return 0;
						}
