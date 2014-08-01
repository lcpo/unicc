#include "unicc.c"
#include "json.c"
#include "preg.c"

//#include "external/pcre/pcre.h"
//#include "external/pcre/pcre.c"

//void __stack_chk_fail(void){return;}
//http://netlib.narod.ru/library/book0003/ch08_07.htm
//http://www.illusionsphotographic.com/analog/src/pcre/

// ~ подлежит обязательному экранированию для получения этого символа иначе он будет использован в качестве \

typedef long* o_wchar;
int main(int argc, char** argv) {

s_vect* vect;
vect=malloc(1*sizeof(vect));
vect->pos=malloc(20);
vect->fn=malloc(20);
vect->tp=malloc(20);
vect->otp=malloc(20);
vect->code=malloc(20);
//preg(vect,"..\\.e{1}","abcde.ftessssst5str|12345sp56");
//preg(vect,"colo.*r1","colouuuuuuuur123r15\n6r1789");

char* char_table=malloc(20);

preg(vect,"colo[0-9]*r","colo331210r");

int i=0;
while(i<vect->length){
printf("fn=%i|pos=%i|code=%c|type=%i|old_type=%i\n",vect->fn[i],vect->pos[i],vect->code[i],vect->tp[i],vect->otp[i]);
i++;
					}


printf("%s\n",vect->code);
free_vect(vect);



o_wchar tst="я";
i=0;
//write(0,(void*)tst,2);
printf("%s\n",*tst);






printf("\n");
//printf("%s\n",strpartlr("abcdef123456789",2,4,6));
//printf("%s\n",strpart("abcdef123456789",6,5));






/*
echo ("create array:\n");	
int i=0,nom=0,id=0;
char*** test=malloc(10);
echo ("end:\n");
while(i<10){
	test[i]=malloc(5);
	nom=0;
while(nom<5){test[i][nom]=malloc(2);nom++;}	
	i++;}
free(test);
echo ("test\n");
*/
/*
echo ("create array:\n");
int i=0,nom=0,id=0;
char* test="123|456|789|abc|def";
char* test2="afdf|dfdf|avaa|yyy";
char** ex=libc_explode("|",test);
char** ex2=libc_explode("|",test2);*/
/*
while(ex[i]!=NULL){
printf("%s\n",ex[i]);
i++;}

i=0;
while(ex2[i]!=NULL){
printf("%s\n",ex2[i]);
i++;}
*/
/*
char** ex3=libc_malloc(libc_count((void**)ex)+libc_count((void**)ex2));
array_merge(ex3,ex,ex2);


i=0;
while(ex3[i]!=NULL){
printf("%s\n",ex3[i]);
i++;}
free(ex);
free(ex2);
free(ex3);
i=0;
while(i<libc_count((void*)hope.a)){
printf("%i|%i|%s\n",i,hope.a[i],hope.a[i]);	
	i++;}

 


*/

/*
id=getptrid(buff);

nom=hope.i+1;
printf("size:%i\n",sizeof(hope));

    


char* bf;
i=0;
while(i<1000000){
buff=realloc(buff,i+1);	
buff[i]=libc_itos(i);
printf("%s\n",buff[i]);
free(buff[i]);


	i++;
	}	
*/

return 0;
						}










