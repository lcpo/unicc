#include "unicc.c"


/*
func* te(){
void test1(void){printf("1\n");}
void test2(void){printf("2\n");}
void test3(void){printf("3\n");}
return obj(test1,test2,test3);
	} 
func* re;
re=te();
func test1=re[0];
func test2=re[1];
func test3=re[2];
test1(0);
test2(0);
test3(0);
*/


int main(int argc, char **argv) {

/*
int i=17;
while(i<43){
printf("%i=%c\n",i,'0'+i);//+32
i++;
}
*/
/*
int i=1;
while(i<255){
printf("%i=%c\n",i,'0'+i);//+32
i++;
}
*/


//char* x=libc_malloc(sizeof(char*));
//x=libc_stristr("test123","tEst");
//printf("\nx=%s\n",x);

int o;
char* ro;
char* str="0987654321test123";
char* sub="Test";
printf("\nstr=%s\n",str);

o=libc_stripos("0987654321test123","test");
printf("\nx=%i\n",o);

ro=libc_stristr("0987654321test123","Test");
printf("\nro=%s\n",ro);

int bo=libc_strncmpi(str+10, "Test", libc_strlen("Test"));
printf("\nbo=%i\n",bo);
exit(0);




return 0;
						}





