#include "unicc.c"




int main(int argc, char **argv) {

//REG_NEWLINE|REG_NOTBOL|REG_NOTEOL
//REG_NOSUB
//printf("%s\n",libc_md5("abc"));
char*** out=libc_malloc(sizeof(char***));
libc_preg_match_all("|<[^>]+>(.*)</[^>]+>|U","<b>пример: </b>\n<div align=left>это тест</div>", out,0);
printf("%s, %s\n",out[0][0],out[0][1]);
printf("%s, %s\n",out[1][0],out[1][1]);


exit(0);
return 0;
						}





