#include "unicc.c"
#include "echo.c"

void* my_malloc(size_t __size){
char** out=sbrk((__size<1)?1:__size);
long i=0;
while(i<=__size){out[i]=sbrk(i);++i;}
return out;	
	}
///---------------------------------------------------------------------
void my_free(void* ptr){
ptr=NULL;	
	}
///---------------------------------------------------------------------
void *my_realloc(void *ptr, size_t __size){

        void* newptr = NULL;
        if (!ptr){return my_malloc(__size);}
        if (!__size) {my_free(ptr); return my_malloc(0);  }
		libc_memcpy(newptr, ptr, libc_count((void**)ptr)*sizeof(ptr));
		newptr=my_malloc(__size);


return newptr;
										}

int main(int argc, char** argv) {

char** test=libc_malloc(1000000);

/*
printf("%i\n",libc_strlen((char*)test));
printf("%i\n",libc_count((void**)test));*/
/*
printf("%i\n",sizeof(test)/sizeof(test[0])); //1
char* str=sbrk(100);
str="abc123";
printf("%i\n",sizeof(str)/sizeof(str[0])); //4
*/

int i=0;
while(i<1000000){
//test[i]=sbrk(sizeof(test[i]));
test=libc_realloc(test,i+1);
test[i]=libc_itos(i);
//libc_strcpy(test[i],libc_itos(i));
//printf("%s\n",test[i]);

	i++;
				}
/*				
printf("---------------------------------------------\n");
i=0;
while(i<100){
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





