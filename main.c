/*
rtrue 2
true 1
null 0 
false -1
rfalse -2
inf (max) (infinity)
*/
#include "unicc.c"
//#include "json/json.c"
//#include "preg/preg.c"

//#include "external/pcre/pcre.h"
//#include "external/pcre/pcre.c"

//void __stack_chk_fail(void){return;}
//http://netlib.narod.ru/library/book0003/ch08_07.htm
//http://www.illusionsphotographic.com/analog/src/pcre/
//#include "preg.h"

///------------------------------------------------------------																		
int main(int argc, char** argv){
printf("argc=%i\n",argc);
char* path=malloc(1024);
strcpy(path,"/home/is/unicc/web/www/index.html");
struct stat_f *fi=malloc(sizeof(struct stat_f*));
stat(path,fi);
printf("mode=%l\n",fi->st_mode);
printf("st_size=%l\n",fi->st_size);
int total=libc_ltoct(fi->st_mode-98304);
printf("mode=%l\n",total);

//s_vect* vect=preg(".*[a-z]..","abcccc12345678def");
//print_vect(vect);
//free_vect(vect);
//*****
//s_vect* vect=preg("[0-9].*[0-9][0-9][a-z][a-z]","abc12345678tef");

//s_vect* vect=preg("colo[a-z].+?tt","colouuuuurttaaaaartt");
/*
int z=0;
while(z<255){
printf("%i|%c\n",z,z);
z++;}
*/




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
   

*/
return 0;
						}




