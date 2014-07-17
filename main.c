#include "unicc.c"
#include "json.c"
//void __stack_chk_fail(void){return;}
   
//http://netlib.narod.ru/library/book0003/ch08_07.htm





json* __json_set(json* js, int type,...){
va_list atr;
va_start(atr, type);
int lenkey=0,lenvalue=0,z=0,lensrc=0,lenthis=0;	
char* value=NULL,*key=NULL;

if(type==JSON_OBJECT || type==JSON_ARRAY || type==JSON_AGENT){
json* sjs=malloc(sizeof(json));
sjs->type=type;
switch(type){
case JSON_OBJECT:sjs->src="{}";break;
case JSON_ARRAY:sjs->src="[]";break;
case JSON_AGENT:sjs->src="[]";break;
			}
sjs->this="";
sjs->flag=1;
js=sjs;
return js;	
															}

key=va_arg(atr, char*); 
if(key!=NULL){value=va_arg(atr, char*);}
lenkey=(key!=NULL)?libc_strlen(key):0;
lenvalue=(value!=NULL)?libc_strlen(value):0;
															

if(type!=JSON_OBJECT && type!=JSON_ARRAY && type!=JSON_AGENT){
js->this=NULL;
js->this=malloc((lenkey+lenvalue+9)*sizeof(js->this));
}
	
switch(type){
case JSON_STRING:{
js->this[z]='"'; z++;
libc_strcat(js->this,key); z=z+lenkey;
js->this[z]='"'; z++;
if(value!=NULL){
js->this[z]=':'; z++;
js->this[z]='"'; z++;
value=libc_addslashes(value);
libc_strcat(js->this,value); z=z+libc_strlen(value);
js->this[z]='"'; z++;
}
break;
				}
case JSON_INTEGER:{
js->this[z]='"'; z++;
libc_strcat(js->this,key); z=z+lenkey;
js->this[z]='"'; z++;
if(value!=NULL){
js->this[z]=':'; z++;
libc_strcat(js->this,value); z=z+lenvalue;
}
break;
				}
case JSON_DOUBLE:{
js->this[z]='"'; z++;
libc_strcat(js->this,key); z=z+lenkey;
js->this[z]='"'; z++;
if(value!=NULL){
js->this[z]=':'; z++;
libc_strcat(js->this,value); z=z+lenvalue;
}
break;
				}
case JSON_NULL:{
js->this[z]='"'; z++;
libc_strcat(js->this,key); z=z+lenkey;
js->this[z]='"'; z++;
if(value!=NULL){
js->this[z]=':'; z++;
libc_strcat(js->this,"null"); z=z+4;
}
break;
				}

case JSON_BOOL:{
js->this[z]='"'; z++;
libc_strcat(js->this,key); z=z+lenkey;
js->this[z]='"'; z++;

if(value==NULL){
	libc_strcat(js->this,"false"); z=z+5;
}else{
js->this[z]=':'; z++;	
if(!libc_strncmpi(value,"false",5)){libc_strcat(js->this,"false"); z=z+5;}else
if(!libc_strncmpi(value,"true",4)){libc_strcat(js->this,"true"); z=z+4;}else
{libc_strcat(js->this,"true"); z=z+4;}	
	}
break;	
				}
								
								
		}	
js->this[z++]='\0';

if(js->flag==1){js->src=malloc(z*sizeof(js->src));
if(js->type==JSON_OBJECT){libc_strcpy(js->src,"{");}
if(js->type==JSON_ARRAY){libc_strcpy(js->src,"[");}
if(js->type==JSON_AGENT){libc_strcpy(js->src,"(");}
js->flag++;
}else{
	lensrc=libc_strlen(js->src);
	js->src=realloc(js->src,(z+lensrc)*sizeof(js->src));
	js->src[lensrc-1]=',';
	}
libc_strcat(js->src,js->this);
lensrc=libc_strlen(js->src);
if(js->type==JSON_OBJECT){js->src[lensrc]='}';}
if(js->type==JSON_ARRAY){js->src[lensrc]=']';}
if(js->type==JSON_AGENT){js->src[lensrc]=')';}
lensrc++;
js->src[lensrc]='\0';
	va_end(atr);
return js;	
	}
///---------------------------------------------------------------------
#define json_set(x,y...)(__json_set((json*)x,y,NULL))
///---------------------------------------------------------------------
void json_print(json* js,int fd){
int len=libc_strlen(js->src),i=0,z=0;
char* src=js->src;
char* buff=libc_malloc(len*sizeof(buff));
while(i<len){
if(src[i]==','|| src[i]=='{' || src[i]=='[' || src[i]=='(' || src[i]=='}' || src[i]==']' || src[i]==')'){buff[z]=src[i];z++;buff[z]='\n';z++;}else
if(src[i]=='"' && (src[i-1]==',' || src[i-1]=='{')){buff[z]='\t';z++;buff[z]=src[i];z++;}else
{buff[z]=src[i];z++;}	
	
	i++;}
	
write(fd,buff,libc_strlen(buff));
libc_free(buff);	
								}
///---------------------------------------------------------------------

int main(int argc, char** argv) {
	
//char* src=libc_file_get_contents("test.json");

json* js0=json_set(NULL,JSON_ARRAY);
js0=json_set(js0,JSON_STRING,"abc\"'124");
js0=json_set(js0,JSON_STRING,"проба");
js0=json_set(js0,JSON_INTEGER,"123");
js0=json_set(js0,JSON_DOUBLE,"125.568");
js0=json_set(js0,JSON_NULL,"abc123");
js0=json_set(js0,JSON_BOOL,"abc123");
js0=json_set(js0,JSON_BOOL,"true");
js0=json_set(js0,JSON_BOOL,"false");
js0=json_set(js0,JSON_BOOL,NULL);

json* js=json_set(NULL,JSON_OBJECT);
js=json_set(js,JSON_INTEGER,"some-arr",js0->src);
js=json_set(js,JSON_STRING,"test-string","abc\"'124");
js=json_set(js,JSON_STRING,"test-string-ru","проба");
js=json_set(js,JSON_INTEGER,"test-int","123");
js=json_set(js,JSON_DOUBLE,"test-dou","125.568");
js=json_set(js,JSON_NULL,"test-null","abc123");
js=json_set(js,JSON_BOOL,"test-bool1","abc123");
js=json_set(js,JSON_BOOL,"test-bool2","true");
js=json_set(js,JSON_BOOL,"test-bool3","false");
js=json_set(js,JSON_BOOL,"test-bool2",NULL);
//printf("%s\n",js->src);     

json* gjs=json_set(NULL,JSON_OBJECT);
gjs=json_set(gjs,JSON_INTEGER,"some-obj",js->src);
json_print(gjs,0);






/*
json_out* js=json_start(JSON_AGENT);
js=json_set(js,JSON_STRING,"f","lib_strlen");
js=json_set(js,JSON_STRING,"t",NULL);
js=json_set(js,JSON_STRING,"r","len");
js=json_set(js,JSON_STRING,"a","$test");
//printf("%s\n",js->src); 

json_out* obj=json_start(JSON_OBJECT);
obj=json_set(obj,JSON_INTEGER,"strlen",js->src);
obj=json_set(obj,JSON_STRING,"test","varable");
printf("%s\n",obj->src); 
*/

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





