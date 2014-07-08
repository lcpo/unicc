#include "unicc.c"
#include "echo.c"

int main(int argc, char **argv) {

/*
char** te=malloc(0);
int i=0;
while(i<100000000){
te=realloc(te,i+1*sizeof(te));
te[i]=libc_itos(i);
printf("%s\n",te[i]);
free(te[i]);	
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

echo (i,"\n",exp[0],"\n",exp[test][0],"\n",ld[0],"\n",ld[1],"\n",exp[1],"\n");

printf("//---------------------------------------------------\n");
while(i<1000000){
exp=libc_explode("a|z","testa|zquesta|zresta|zposta|zgeta|zrbpd");
echo (i."\n".exp[0]."\n".exp[test][0]."\n".ld[0]."\n".ld[1]."\n".exp[1]."\n");
//libc_free(exp);

i++;
				}

print_var();



exit(0);
return 0;
						}





