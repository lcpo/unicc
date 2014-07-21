#include "unicc.c"
#include "json.c"
//void __stack_chk_fail(void){return;}
//http://netlib.narod.ru/library/book0003/ch08_07.htm


//1 =1024 =>4096 : 1024
//2 =4097 =>8192 : 2048
//3 =8193 =>12288: 3072
//4 =12289 =>16384 : 4095

/*

*/



///------------------------------------------------------------
int main(int argc, char** argv) {
int i=0,nom=0,id=0;
char** buff=malloc(0);
id=getptrid(buff);

nom=hope.i+1;
printf("size:%i\n",sizeof(hope));
printf("a==%i\n",hope.a[id]);
printf("z==%i\n",hope.z[id]);
//printf("max==%i\n",hope.max[id]);
//printf("min==%i\n",hope.min[id]);
printf("id==%i\n",id);
    i=0;
  /*  
while(nom>i){
printf("%i|a:%i|z:%i|min:%i|max:%i\n",i,hope.a[i],hope.z[i],hope.min[i],hope.max[i]);
i++;
	}
*/

i=0;
while(i<10000){
buff=realloc(buff,i+1);	
buff[i]=libc_itos(i);
//printf("%s\n",buff[i]);
dropptr(buff[i]);
	i++;
	}	


i=0;
while(i<10000){
	printf("%s\n",buff[i]);
	//free(buff[i]);
	i++;
	}

return 0;
						}




/*
static char mem_block_0[0];
static char mem_block_1[2];
static char mem_block_2[4];
static char mem_block_3[8];
static char mem_block_4[16];
static char mem_block_5[32];
static char mem_block_6[64];
static char mem_block_7[128];
static char mem_block_8[256];
static char mem_block_9[512];
static char mem_block_10[1024];
static char mem_block_11[2048];
static char mem_block_12[4096];
static char mem_block_13[8190];
static char mem_block_14[16380];
static char mem_block_15[32760];
static char mem_block_16[65520];
static char mem_block_17[131040];
static char mem_block_18[262080];
static char mem_block_19[524160];
static char mem_block_20[1048320];
static char mem_block_21[2096640];
static char mem_block_22[4193280];
static char mem_block_23[8386560];
static char mem_block_24[16773120];
static char mem_block_25[33546240];
static char mem_block_26[67092480];
static char mem_block_27[134184960];
static char mem_block_28[268369920];
static char mem_block_29[536739840];
static char mem_block_30[1073479680];

void * salloc(size_t __size){
void* out=(void*)mem_block_10;
if(out==NULL){printf("error!\n");return NULL;}
	return out;
	}




///------------------------------------------------------------

int main(int argc, char** argv) {
int i=0;
char** buff=salloc(10);
printf("%i\n",libc_count((void**)buff));
while(i<10){
buff[i]=libc_itos(i);
	//printf("%s\n",buff[i]);
	
	i++;}	
i=0;
while(i<10){
	printf("%s\n",buff[i]);
	
	i++;}	


return 0;
						}

*/






