#include "unicc.c"
#include "echo.c"
//void __stack_chk_fail(void){return;}



int main(int argc, char** argv) {
	/*
char** test=malloc(10*sizeof(test));
int i=0;
while(i<10){
test=realloc(test,i+1);
test[i]=libc_itos(i);
libc_strcpy(test[i],libc_itos(i));
printf("%s\n",test[i]);

	i++;
				}
				
printf("---------------------------------------------\n");
i=0;
while(i<10){
printf("%s\n",test[i]);
i++;}				
	*/			

/*
char** test=libc_malloc(0);
int i=0;
while(i<10){
test=libc_realloc(test,i+1);
test[i]=libc_itos(i);
//libc_strcpy(test[i],libc_itos(i));
printf("%s\n",test[i]);

	i++;
				}
*/				

/*				
printf("---------------------------------------------\n");
i=0;
while(i<10){
printf("%s\n",test[i]);
i++;}
*/
/*
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

//printf("//---------------------------------------------------\n");
while(i<1000000){
//exp=libc_explode("a|z","testa|zquesta|zresta|zposta|zgeta|zrbpd");
echo (i."\n".exp[0]."\n".exp[test][0]."\n".ld[0]."\n".ld[1]."\n".exp[1]."\n");
//libc_free(exp);

i++;
				}

//print_var();
*/

return 0;
						}





