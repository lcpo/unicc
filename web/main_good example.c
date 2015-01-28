#include "/home/is/unicc/unicc.c"
///------------------------------------------------------------	
char response[] = "HTTP/1.1 200 OK\r\n"
"Content-Type: text/html; charset=UTF-8\r\n\r\n"
"<doctype !html><html><head><title>Bye-bye baby bye-bye</title>"
"<style>body { background-color: #111 }"
"h1 { font-size:4cm; text-align: center; color: black;"
" text-shadow: 0 0 2mm red}</style></head>"
"<body><h1>Goodbye, world!</h1></body></html>\r\n";
																	
int main(int argc, char** argv){
  int one = 1, client_fd;
  struct sockaddr_in svr_addr,cli_addr;
  socklen_t sin_len = sizeof(cli_addr);
 
 int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0){
   // err(1, "can't open socket");
   printf("can't open socket\n");
  close(sock);
  exit(0);
				}
  setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(int));
 
  int port = 8080;
  svr_addr.sin_family = AF_INET;
  svr_addr.sin_addr.s_addr = INADDR_ANY;
  svr_addr.sin_port = htons(port);
 
  if (bind(sock, (struct sockaddr *) &svr_addr, sizeof(svr_addr)) == -1) {
    close(sock);
    //err(1, "Can't bind");
  printf("Can't bind\n");
  }
 
  listen(sock, 5);
  int i=0;
  while (1) {
    client_fd = accept(sock, (struct sockaddr *) &cli_addr, &sin_len);
    printf("got connection\n");
 
    if (client_fd == -1) {
      printf("Can't accept\n");
      continue;
    }
 
    write(client_fd, response, sizeof(response) - 1); 
    close(client_fd);
    if(i>20){break;}
    i++;
  }
	
return 0;
						}
