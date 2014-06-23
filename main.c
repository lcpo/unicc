#include "unicc.c"

int test2(void){
printf("%s\n",__FUNCTION__);
return 0;	
	}
 
int main(int argc, char **argv) {
	/*
set_fun(main,int,main,2);
//print_fun();
//print_var();
float test=var(test,float,main);
test=123.4567;
pub(test);
pub("\n");
int o=len(test);
var(o,int,main);

printf("%i\n",o);

test2();
print_var();
print_fun();*/


char* test1="test1|test2|test3|123|123|123|456|789|qwe|rtyu|fbcd|hrmp";
char* test2="|";
char* test3=libc_strpstr_nomo(test1,test2);

char** test4=libc_explode(test2,test1);
test4=libc_array_unique(test4);
int nom=libc_count((void**)test4);
int i=0;
while(nom>i){
printf("%s\n",test4[i]);
++i;}

//char* test5=libc_implode("|++|",test4);
//printf("%s\n",test5);



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

