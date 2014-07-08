#include "unicc.c"
#include "echo.c"
/*
char* current_break[0];

void *sbrk(size_t incr)
{
   void* old_break = (void*)current_break;
    current_break += incr;
    return (void*) old_break;
}
*/

//732
#define PEEK_EBP(reg,t)         \
   asm(							\
       "addl %0, %%ebp\n"		\
       "movl %%ebp, %0\n"       \
       : "=r"(reg)              \
       : "r"(t)      	        \
   );

//5
#define PEEK_ESP(reg,t)         \
   asm(							\
       "add %0, %%esp\n"		\
       "mov %%esp, %0\n"        \
       : "=r"(reg)              \
       : "r"(t)      	        \
   );


//3066
#define PEEK_EDX(reg,t)         \
   asm(							\
       "add %0, %%edx\n"		\
       "mov %%edx, %0\n"        \
       : "=r"(reg)              \
       : "r"(t)      	        \
   );

#define ASM_STRCPY(reg,t)         \
   asm(							\
       "movl %0,%%ebx \n"		\
       "movl %%ebx, %0\n"        \
       : "=r"(reg)              \
       : "r"(t)      	        \
   );


int main(int argc, char **argv) {


   


char* test;//=sbrk(10000*sizeof(test));
ASM_STRCPY(test,"test12345667889");
printf("%s\n",test);
/*
int i=0;
while(i<10000){
test[i]=libc_itos(i);
printf("%s\n",test[i]);	
i++;	
	}

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


exit(0);
return 0;
						}





