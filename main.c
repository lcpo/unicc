#include "unicc.c"
#include "json/json.c"
#include "preg/preg.c"

//#include "external/pcre/pcre.h"
//#include "external/pcre/pcre.c"

//void __stack_chk_fail(void){return;}
//http://netlib.narod.ru/library/book0003/ch08_07.htm
//http://www.illusionsphotographic.com/analog/src/pcre/

// ~ подлежит обязательному экранированию для получения этого символа иначе он будет использован в качестве \

///------------------------------------------------------------																		
int main(int argc, char** argv) {
int z=0; int co=0;

s_vect* vect=malloc(1);
vect->pos=malloc(200);
vect->tp=malloc(200);
vect->otp=malloc(200);
vect->c=malloc(200);
ch_tab* tb=malloc(1);
tb->table=malloc(100);
tb->table_src=malloc(100);
tb->flag_denial=malloc(100);
tb->rep=17;
tb->length=0;
tb->tag_start='[';
tb->tag_end=']';

preg(vect,tb,"[a-z][a-z][a-z][a-z]$","abcdef");


int i=0;
while(i<vect->length){
printf("%i|pos=%i|code=%c:%i|type=%i|old_type=%i\n",i,vect->pos[i],vect->c[i],vect->c[i],vect->tp[i],vect->otp[i]);
i++;
					 }
printf("%s\n",vect->c);
//free_vect(vect);


//preg(vect,"..\\.e{1}","abcde.ftessssst5str|12345sp56");
//preg(vect,"colo.*r1","colouuuuuuuur123r15\n6r1789");
//colo[0-9]*a[0-9]*ro


					 



/*
wchar tst[]=L"я";
printf("%c\n",tst[0]);
printf("%c\n",tst[2]);
printf("\n");*/
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



/*
int i=0;
char* test="1234567890";
while(i<10){
printf("%s\n",test);
test++;
	
	i++;}
*/
/*
int i=0;
char* test="1234567890";
while(i<10){
char* new=libc_strpart(test,0, libc_strlen(test)-i);
printf("%s\n",new);
free(new);
i++;}
*/







