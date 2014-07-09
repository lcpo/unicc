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
#define cpyquad(variable,value)asm("mov %0,%%ebx \n" "mov %%ebx, %0\n" : "=r"(variable): "r"(value));
#define cpylong cpyquad
#define ADDR(address ,variable) asm("mov  %%eax,%0 \n"	"mov  %0, %%eax \n" : "=r"(address) : "r"(variable));
#define IN_EDX(reg,t)asm("add %0, %%edx\n" "mov %%edx, %0\n" : "=r"(reg) : "r"(t));
#endif


#ifdef __x86_64__
#define cpylong(variable,value) asm("mov %%eax,%0\n" "mov %0,%%eax\n"	: "=r"(variable): "r"(value));
#define cpyquad(variable,value) asm("mov %%rax,%0\n" "mov %0,%%rax\n"	: "=r"(variable): "r"(value));
#define ADDR(address ,variable) asm("mov  %%rax,%0 \n"	"mov  %0, %%rax \n" : "=r"(address) : "r"(variable));
#define IN_EDX(reg,t)asm("addq %0, %%rdx\n" "movq %%rdx, %0\n" : "=r"(reg) : "r"(t));
#endif

#define cpy(variable,value)({\
if(sizeof(variable)<4){variable=value;}\
if(sizeof(variable)==4){cpylong(variable,value);}\
if(sizeof(variable)==8){cpyquad(variable,value);}\
	})



/*

void* alloc(long long __size){
char buff[__size];
void* out;
ADDR(out,buff);
return out;
	}

*/

int main() {




char** test=malloc(0);



int i=0;
while(i<1000000){
	test=realloc(test,i+1*sizeof(char**));
test[i]=libc_itos(i);
printf("%s\n",test[i]);	
i++;	
	}

/*
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
*/

//char** test;
//PEEK_EDX(test,10);
//cpy(test[0],"abc");
//printf("%s\n",test[0]);





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
//asm volatile("movl $60, %rax\n\t" "movq $0, %rdi\n\t" "syscall");
//asm volatile("movl $0, %ebx\n\t" "movl $1, %eax\n\t" "int $0x80\n");
return 0;
						}





