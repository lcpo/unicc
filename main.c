#include "unicc.c"
#include "json.c"
//void __stack_chk_fail(void){return;}
   
//http://netlib.narod.ru/library/book0003/ch08_07.htm






int main(int argc, char** argv) {
char* src=libc_file_get_contents("test.json");
const json* sjson=json_parse(src, 0);
if (sjson) {
  printf("some-int=%l\n", json_get(sjson, "some-int")->int_value);
  printf("some-dbl=%f\n", json_get(sjson, "some-dbl")->dbl_value);
  printf("some-bool=%s\n", json_get(sjson, "some-bool")->int_value? "true":"false");
  printf("some-null=%s\n", json_get(sjson, "some-null")->text_value);
  printf("hello=%s\n", json_get(sjson, "hello")->text_value);
  printf("other=%s\n", json_get(sjson, "other")->text_value);
  printf("KEY=%s\n", json_get(json_get(sjson, "obj"), "KEY")->text_value);
  

  const json* arr=json_get(sjson, "array");
  int i;
  for (i=0; i<arr->length; i++) {
    const json* item=json_item(arr, i);
    printf("arr[%i]=(%l)|%l|%f|%s\n", i, item->type, item->int_value, item->dbl_value, item->text_value);
  }
  json_free(sjson);
}



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





