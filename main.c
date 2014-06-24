#include "unicc.c"

int test2(void){
printf("%s\n",__FUNCTION__);
return 0;	
	}
 
//!---------------------------------------------------------------------
size filesize(char* filename){
struct stat_f *fi=libc_malloc(sizeof(char));
stat(filename,fi);
return fi->st_gid;
							}
//!---------------------------------------------------------------------							
char* file_get_contents(char* filename){
struct stat_f *fi=libc_malloc(sizeof(char));
int res=open(filename,O_RDONLY,0);
fstat(res,fi);
char* buff=libc_malloc(fi->st_gid);
read(res,buff,fi->st_gid);
close(res);
return buff;
										}
//!---------------------------------------------------------------------
int file_put_contents(char* filename, char* src, int appendflag){
int flags=0,out=0;
if(appendflag==0){flags|= (O_CREAT|O_WRONLY|O_TRUNC);}else{flags|= (O_CREAT|O_WRONLY|O_APPEND);}
int res=open(filename,flags,0666);
out=write(res,(void*)src,libc_strlen(src));	
close(res);
return out;
												}										
										
//!---------------------------------------------------------------------

int rand(void)
{

	return 0;
}										
																
							
 
int main(int argc, char **argv) {

file_put_contents("test1.txt","test1|test2|test3|123|123|123|456|789|qwe|rtyu|fbcd|hrmp",0);
int o=0;
o=rand();
printf("\n%i\n",o);
exit(0);




return 0;
						}




//uni* addr=(uni*)libc();

//func test=(func)addr[10];

//printf("%l\n",(long)addr[10]);

//test((uni*)"test\n");

//extern print2(char* ptr);
//print2("test");


//pub("//------------------------------------\n");
//char* buf=var(buf,char*,main);
//char* buf2=var(buf2,char*,main);
//int bytes_read=var(bytes_read,int,main);

//int fd = open("/etc/passwd", 0, 0);
//bytes_read =read(fd, buf, 40);


//close(fd);

//print_fun();
//print_var();
//print_reg_type();
/*
char* t1="test";
int t2=123;
float t3=456.123;
double t4=458.1235;
printf("%f|%f|%s|%d\n",t3,t4,t1,t2);
*/

    
 /*
	//print("test\n");
	//print("test\n");
set_fun(main,int,main,2);

new(libc,obj,0);

proto(print2,prints);

int out=fun(int,print2,"test");
//printf("%i\n",out);
int out2=fun(int,prints,"test2");
//printf("%i\n",out2);

//print_fun();
	set_fun(main,int,main,2);
	char* t=var(t,char*,main);
	char** r=var(r,char**,main);
	int i=var(i,int,main);
i=0;

while(i<9999){
r[i]=var(r[i],char*,main);
i++;}

i=0;
while(i<9999){
r[i]=val(r[i],tos(i));
pub(r[i]);
pub("\n");
//delete(r[i]);

	i++;}

 //  print_var();



print_fun();
print_reg_type();
*/   

