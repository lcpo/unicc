#include "unicc.c"


int main(int argc, char **argv) {

printf("%i\n",argc);
//printf("%i\n",argv[0]);


//REG_NEWLINE|REG_NOTBOL|REG_NOTEOL
//REG_NOSUB
//printf("%s\n",libc_md5("abc"));
/*
char*** out=libc_malloc(sizeof(char***));
libc_preg_match_all("|<[^>]+>(.*)</[^>]+>|U","<b>пример: </b>\n<div align=left>это тест</div>", out,0);
printf("%s, %s\n",out[0][0],out[0][1]);
printf("%s, %s\n",out[1][0],out[1][1]);
*/
/*
int i=0;
while(i<1000000){
//write($O,libc_md5(libc_itos(i)),32);
//write($O,"\n",1);
printf("%s\n",libc_md5(libc_itos(i)));
i++;
}*/
exit(0);
return 0;
						}





