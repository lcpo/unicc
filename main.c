#include "unicc.c"
#include "json.c"

#include "external/pcre/pcre.h"
#include "external/pcre/pcre.c"

//void __stack_chk_fail(void){return;}
//http://netlib.narod.ru/library/book0003/ch08_07.htm
//http://www.illusionsphotographic.com/analog/src/pcre/

///---------------------------------------------------------------------
/*
char char_point_table[]={
0,1,2,3,4,5,6,7,8,9,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,
29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,
53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,
77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,
101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,
119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,
137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,
155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,
173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,
191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,
209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,
227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,
245,246,247,248,249,250,251,252,253,254,255};

char ispoint(char ch){
int i=0;
for(;i<255;i++){if(ch==char_point_table[i]){return ch;}}
return -1;	
	}

*/

void libc_preg_print_error(char* pattern,int errchar, char* errstr){
libc_print_str("Ошибка: ");
libc_print_str((char*)errstr);
libc_print_str("\nСимвол N ");
libc_print_str(libc_itos(errchar));
libc_print_str("\nШаблон:");
libc_print_str(pattern);
libc_print_str("\n");	
return;	
	}

/*

int libc_preg_match ( char* pattern, char* subject, char** matches , int flags , int offset){
char *errstr=malloc(8);
unsigned char *tables="";
int pairs=0,i=0,j=0,vecsize=libc_strlen(subject),vector[vecsize],errchar;
pcre *f=pcre_compile(pattern, PCRE_CASELESS | PCRE_DOTALL,&errstr,&errchar,NULL);
if((f)==NULL){libc_preg_print_error(pattern,errchar,errstr);return -1;}
pairs=pcre_exec(f,NULL,subject,libc_strlen(subject),offset,j,vector,vecsize);

//printf("%i",pairs);

//pcre_extra *f_ext=pcre_study(f,0,&errstr);
//pairs=pcre_exec(f,f_ext,subject,libc_strlen(subject),offset,j,vector,vecsize);
//while(pairs>i){
//matches[i]=libc_malloc(sizeof(matches[i]));	
//pcre_get_substring(subject,vector,pairs, i, &matches[i]);
//pcre_copy_substring(subject, vector, pairs,   i, matches[i], sizeof(char*)*vecsize);

//i++;
//}

return 1;
																	}

*/

///------------------------------------------------------------
int main(int argc, char** argv) {
//char** out=malloc(16);
//libc_preg_match("|..\\..|U","abcde.|test5str|1234556",out,0,0);

char *errstr=malloc(8);
int errchar;
real_pcre *re;

real_pcre *f=pcre_compile(re,"/..\\../U", PCRE_CASELESS | PCRE_DOTALL,&errstr,&errchar,NULL);

//ap->pattern = pcre_compile(ap->from + 7, PCRE_CASELESS | PCRE_DOTALL,(char **)(&errstr), &erroffset, NULL);
//pcre_exec((pcre *)p, NULL, s, (int)strlen(s), 0, 0, pmatch,(pmatch == NULL)?0:PMATCH_SIZE) >= 0)

//printf("%i\n",ispoint('\0'));



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










