#include "unic.c"

//void init_unic () __attribute__ ((constructor,const,section("unic")));


//void init_unic() {//set_fun(init_unic,void,init_unic,0);}



//----------------------------------------------------------------------
 	

//#include <unistd.h>
//#include <stdio.h>



//http://blog.rchapman.org/post/36801038863/linux-system-call-table-for-x86-64
int main(int argc, char **argv) {
set_fun(main,int,main,2);
pub("//------------------------------------\n");
char* buf=var(buf,char*,main);
char* buf2=var(buf2,char*,main);
int bytes_read=var(bytes_read,int,main);

int fd = open("/etc/passwd", 0, 0);
bytes_read =read(fd, buf, 40);


close(fd);

print_fun();
print_var();
//print_reg_type();

return 0;

							}
    
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

