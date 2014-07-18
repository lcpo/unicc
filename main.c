#include "unicc.c"
#include "json.c"
//void __stack_chk_fail(void){return;}
//http://netlib.narod.ru/library/book0003/ch08_07.htm






int main(int argc, char** argv) {
	

json* js0=json_set(NULL,JSON_ARRAY);
js0=json_set(js0,JSON_STRING,"lll");
js0=json_set(js0,JSON_INTEGER,"123");
js0=json_set(js0,JSON_DOUBLE,"125.568");
js0=json_set(js0,JSON_NULL);
js0=json_set(js0,JSON_BOOL,"true");
js0=json_set(js0,JSON_BOOL,NULL);
js0=json_set(js0,JSON_BOOL,"false");
//json_print(js0,0);

json* js=json_set(NULL,JSON_OBJECT);
js=json_set(js,JSON_ARRAY,"some-arr",js0);
js=json_set(js,JSON_STRING,"test-string","abc\"'124");
js=json_set(js,JSON_STRING,"test-string-ru","проба");
js=json_set(js,JSON_INTEGER,"test-int","123");
js=json_set(js,JSON_DOUBLE,"test-dou","125.568");
js=json_set(js,JSON_NULL,"test-null","abc123");
js=json_set(js,JSON_BOOL,"test-bool1","abc123");
js=json_set(js,JSON_BOOL,"test-bool2","true");
js=json_set(js,JSON_BOOL,"test-bool3","false");
js=json_set(js,JSON_BOOL,"test-bool2",NULL);
//json_print(js,0);

json* gjs=json_set(NULL,JSON_OBJECT);
gjs=json_set(gjs,JSON_OBJECT,"some-obj",js);
printf("%s\n",gjs->src);
json_print(gjs,0);


/*
char **te1=libc_malloc(3*sizeof(char**));
te1[0]="test1",te1[1]="test2",te1[2]="test3",te1[3]="4";
char **te2=libc_malloc(3*sizeof(char**));
te2[0]="abc1",te2[1]="abc2",te2[2]="abc3",te2[3]="5";
char **te3=libc_malloc(3*sizeof(char**));
te3[0]="123",te3[1]="345",te3[2]="678",te3[3]="910";

char** buff=libc_malloc(10*sizeof(char**));

array_merge(buff,te1,te2,te3);

int co=libc_count((void**)buff);
printf("co=%i\n",co);
int i=0;
while(co>i){
printf("%s\n",buff[i]);	
	i++;}

*/


return 0;
						}





