#include "unicc.c"
#include "json.c"
//void __stack_chk_fail(void){return;}
   
//http://netlib.narod.ru/library/book0003/ch08_07.htm




json* json_set(char* key, char* value, int type){
	json* sjson=JSON_CALLOC();
	sjson->type=type;
	sjson->key=key;
	sjson->value=value;
	switch(type){
	case JSON_NULL:
	case JSON_BOOL:
	case JSON_ARRAY:
	case JSON_INTEGER:
	case JSON_DOUBLE:
	case JSON_STRING:
	default:break;	
		}
	return sjson;
	}

int main(int argc, char** argv) {
	
//char* src=libc_file_get_contents("test.json");

json* sjson=json_set("test","123",JSON_OBJECT);

printf("%s\n",sjson->value);

/*
int i;
//first lvl json
const json* sjson=json_parse(src);

printf("size=%i\n", sizeof(json));

if(sjson){
printf("some-int=%s\n", json_get(sjson, "some-int")->value);
printf("some-dbl=%s\n", json_get(sjson, "some-dbl")->value);
printf("some-bool=%s\n", json_get(sjson, "some-bool")->value? "true":"false");
printf("some-null=%s\n", json_get(sjson, "some-null")->value);
printf("hello=%s\n", json_get(sjson, "hello")->value);
printf("other=%s\n", json_get(sjson, "other")->value);
printf("KEY=%s\n", json_get(sjson, "obj")->value);
printf("array=%s\n", json_get(sjson, "array")->value);

//2 lvl json

const json* arr=json_get(sjson, "array");

  for (i=0; i<arr->length; i++){
    const json* item=json_item(arr, i);
    printf("arr[%i]=(%l)|%s\n", i, item->type, item->value);
								}


//only array 2 lvl json
const json* ts=json_parse(arr->value);
printf("%s\n",json_item(ts,1)->value);



printf("SKARR1=%s\n", json_get(json_get(json_get(sjson, "obj"), "obj2"),"SKARR1")->value);

//4 lvl json
const json* arr2=json_get(json_get(json_get(sjson, "obj"), "obj2"),"SKARR1");
  for (i=0; i<arr2->length; i++){
    const json* item2=json_item(arr2, i);
    printf("arr2[%i]=(%l)|%s\n", i, item2->type, item2->value);
								}


  json_free(sjson);

}*/



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





