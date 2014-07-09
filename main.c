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
#ifdef __i386__
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

#define CPY(reg,t) 		        \
   asm(							\
       "movq %0,%%ebx \n"		\
       "movq %%ebx, %0\n"       \
       : "=r"(reg)              \
       : "r"(t)      	        \
   );
#endif


#ifdef __x86_64__

#define cpylong(variable,value) asm("mov %%eax,%0\n" "mov %0,%%eax\n"	: "=r"(variable): "r"(value));
#define cpyquad(variable,value) asm("mov %%rax,%0\n" "mov %0,%%rax\n"	: "=r"(variable): "r"(value));

#define cpy(variable,value)({\
if(sizeof(variable)<4){variable=value;}\
if(sizeof(variable)==4){cpylong(variable,value);}\
if(sizeof(variable)==8){cpyquad(variable,value);}\
	})

#define ADDR(address ,variable) asm("mov  %%rax,%0 \n"	"mov  %0, %%rax \n" : "=r"(address) : "r"(variable));

#define PEEK_EDX(reg,t)         \
   asm(							\
       "addq %0, %%rdx\n"		\
       "movq %%rdx, %0\n"        \
       : "=r"(reg)              \
       : "r"(t)      	        \
   );



#endif

//#define main _start
//
//int argc, char **argv

int main() {

char ps;	
cpy(ps,'a');
printf("%c\n",ps);

int rs;	
cpy(rs,123);
printf("%i\n",rs);

long ts;	
cpy(ts,123);
printf("%l\n",ts);

char* nom;
cpy(nom,"ttts");
printf("%s\n",nom);


char** test;
//PEEK_EDX(test,10);
cpy(test[0],"abc");
printf("%s\n",test[0]);

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
//asm volatile("movl $60, %eax\n\t" "movq $0, %rdi\n\t" "syscall");
return 0;
						}





