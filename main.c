#include "unicc.c"
#include "echo.c"
//void __stack_chk_fail(void){return;}
   
//http://netlib.narod.ru/library/book0003/ch08_07.htm


int main(int argc, char** argv) {
/*
char** test1=libc_malloc(1000);


int i=0;
while(i<10){
test1[i]=libc_malloc(64);
test1[i]=libc_itos(i);
printf("%s\n",test1[i]);
	i++;
	}


printf("//---------------------------------------------------\n");
i=0;
while(i<1000){
printf("%s\n",test1[i]);	
	i++;}
*/


char* abc=var(abc,char*,main);

int i=var(i,int,main);

int test=var(test,int,main);
i=5; test=2; 
abc="tululu\n";

double* ld=var(ld,double*,main);

ld[0]=1.5;
ld[1]=2.6;

char** exp=var(exp,char**,main);
exp=libc_explode("a|z","testa|zquesta|zresta|zposta|zgeta|zrbpd");


echo (i."\n".exp[0]."\n".exp[test][0]."\n".ld[0]."\n".ld[1]."\n".exp[1]."\n");

//printf("//---------------------------------------------------\n");
while(i<10000000){
//exp=libc_explode("a|z","testa|zquesta|zresta|zposta|zgeta|zrbpd");
echo (i."\n".exp[0]."\n".exp[test][0]."\n".ld[0]."\n".ld[1]."\n".exp[1]."\n");
//libc_free(exp);

i++;
				}

print_var();


return 0;
						}





