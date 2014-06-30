#include "unicc.c"
#include "md5.c"

char binhex[16] = {'0', '1', '2', '3','4', '5', '6', '7','8', '9', 'a', 'b','c', 'd', 'e', 'f'};


int main(int argc, char **argv) {

char hash[16],in2[]={"abc"};
   unsigned int len,i=0; 
   MD5_CTX ctx; 
   md5_init(&ctx); 
   md5_update(&ctx,in2,libc_strlen(in2)); 
   md5_final(&ctx,hash);
	printf("\n");
    for (i=0;i<16;i++){ 
    printf ("%c%c", binhex[hash[i] >> 4],binhex[hash[i] & 0x0f]);

				}
							

printf("\n");

/*
char* start="abc";	
unsigned *d=md5(start,3);
int j,k;
WBunion u;
    printf("= 0x");
    for (j=0;j<4; j++){
        u.w = d[j];
        for (k=0;k<4;k++) printf("%c%c", binhex[u.b[k] >> 4], binhex[u.b[k] & 0x0f]); //printf("%02x",u.b[k]);
    }
    printf("\n");

	
//printf("%s", hash); 
//printf("\n");
*/ 
/*
*printf("%c%c", binhex[c >> 4], binhex[c & 0x0f]); 
*/

exit(0);
return 0;
						}





