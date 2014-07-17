
//----------------------------------------------------------------------
typedef enum json_type {JSON_NULL, JSON_OBJECT, JSON_ARRAY,JSON_STRING, JSON_INTEGER, JSON_DOUBLE, JSON_BOOL,JSON_AGENT} json_type;
typedef struct json {
	json_type type;
	char* src; 
	char* key;  
	char* value;  
	char* this;
	int flag;
	int length;
	int flags;	  
	struct json* child; 
	struct json* next; 
	struct json* last_child;
	} json;

const json* json_parse(char* text);
void json_free(const json* js);
const json* json_get(const json* sjson, char* key); // get object's property by key
const json* json_item(const json* sjson, int idx); // get array element by index


#ifndef JSON_CALLOC
#define JSON_CALLOC() malloc(sizeof(json))
#define JSON_FREE(sjson) free((void*)(sjson))
#endif


#ifndef JSON_REPORT_ERROR
#define JSON_REPORT_ERROR(mes,p) printf("JSON PARSE ERROR (%d): %s in %c \n", __LINE__,mes,p)
#endif

#define IS_WHITESPACE(c) ((unsigned char)(c)<=(unsigned char)' ')

static const json dummy={ JSON_NULL };

static json* create_json(json_type type, char* key, json* parent) {
  json* js=JSON_CALLOC();
  js->type=type;
  js->key=key;
  if (!parent->last_child) { parent->child=parent->last_child=js;  
  }else{
    parent->last_child->next=js;
    parent->last_child=js;
  }
  parent->length++;
  return js;
}
///------------------------------------------------------------
void json_free(const json* js) {
  json* p=js->child;
  json* p1;
  while (p) {
    p1=p->next;
    json_free(p);
    p=p1;
  }
  JSON_FREE(js);
}
///------------------------------------------------------------
static char* unescape_string(char* s, char** end) {
  char* p=s;
  char* d=s;
  char c;
  while ((c=*p++)) {
    if (c=='"') {
      *d='\0';
      *end=p;
      return s;
    }
    else if (c=='\\') {
      switch (*p) {
        case '\\':
        case '/':
        case '"':
          *d++=*p++;
          break;
        case 'b':
          *d++='\b'; p++;
          break;
        case 'f':
          *d++='\f'; p++;
          break;
        case 'n':
          *d++='\n'; p++;
          break;
        case 'r':
          *d++='\r'; p++;
          break;
        case 't':
          *d++='\t'; p++;
          break;
        default:
          *d++=c;
          break;
      }
    }
    else {
      *d++=c;
    }
  }
  JSON_REPORT_ERROR("no closing quote for string",p);
  return 0;
}
///------------------------------------------------------------
static char* skip_block_comment(char* p) {
  
  char* ps=p-2;
  if (!*p) {
    JSON_REPORT_ERROR("endless comment",p);
    return 0;
  }
  REPEAT:
  p=libc_strchr(p+1, '/');
  if (!p) {
    JSON_REPORT_ERROR("endless comment",p);
    return 0;
  }
  if (p[-1]!='*') goto REPEAT;
  return p+1;
}
///------------------------------------------------------------
static char* parse_key(char** key, char* p) {

  char c;
  while ((c=*p++)) {
    if (c=='"') {
      *key=unescape_string(p, &p);
      if (!*key) return 0; // propagate error
      while (*p && IS_WHITESPACE(*p)) p++;
      if (*p==':') return p+1;
      JSON_REPORT_ERROR("unexpected chars",p);
      return 0;
    }
    else if (IS_WHITESPACE(c) || c==',') {
      // continue
    }
    else if (c=='}') {
      return p-1;
    }
    else if (c=='/') {
      if (*p=='/') { // line comment
        char* ps=p-1;
        p=libc_strchr(p+1, '\n');
        if (!p) {
          JSON_REPORT_ERROR("endless comment",p);
          return 0; // error
        }
        p++;
      }
      else if (*p=='*') { // block comment
        p=skip_block_comment(p+1);
        if (!p) return 0;
      }
      else {
        JSON_REPORT_ERROR("unexpected chars",p);
        return 0; // error
      }
    }
    else {
      JSON_REPORT_ERROR("unexpected chars",p);
      return 0; // error
    }
  }
  JSON_REPORT_ERROR("unexpected chars",p);
  return 0; // error
}
///------------------------------------------------------------
 char* parse_value(json* parent, char* key, char* p) {
int len=0,i=0,n=0,z=0;
  json* js;
  while (1) {
    switch (*p) {
      case '\0':
        JSON_REPORT_ERROR("unexpected end of text",p);
        return 0; // error
      case ' ': 
      case '\t': 
      case '\n': 
      case '\r':
      case ',':
        // skip
        p++;
        break;
      case '{':
        js=create_json(JSON_OBJECT, key, parent);
        p++;
        while (1) {
          char* new_key;
          p=parse_key(&new_key, p);
          if (!p) return 0; // error
          if (*p=='}') return p+1; // end of object
          p=parse_value(js, new_key, p);
          if (!p) return 0; // error
        }
      case '[':
      js=create_json(JSON_ARRAY, key, parent);
 if(p[0]=='['){      

len=libc_strlen(p);
 i=0;n=1;z=0;
     char* bf=libc_alloc(len*sizeof(bf));

     	     
     while(len>i){
	if(p[i]==']' && p[i+n]==' ' || p[i]==']' && p[i+n]=='\t' || p[i]==']' && p[i+n]=='\r' ||p[i]==']' && p[i+n]=='\n'){n++;}
	if(p[i]==']' && p[i+n]==']' || p[i]==']' && p[i+n]==',' || p[i]==']' && p[i+n]=='}'){bf[z]=p[i];n=1;i++;z++;break;}else{bf[z]=p[i];i++;z++;}	 
	if(!p[i]){break;}
		 }
bf[i]='\0';
		js->value=bf;
					}
      p++;i=0;
       while (1) {
          //printf("|%s|%i|\n",p,i);
          p=parse_value(js, NULL, p);
          if (!p){ return 0; }
          if (*p==']') { break;}
       i++;}
      // printf("|%s|\n",p+1);
		return p+1;
      case ']':
        return p;
      case '"':
        p++;
        js=create_json(JSON_STRING, key, parent);
        js->value=unescape_string(p, &p);
        if (!js->value) return 0; // propagate error
        return p;
      case '-': case '0': case '1': case '2': case '3': 
      case '4': case '5': case '6': case '7': case '8': 
      case '9':
        {
		char* pe;
		
		if(libc_strchr(p,']')){pe=libc_strpstr(p,"]");}
		if(libc_strchr(pe,',')){pe=libc_strpstr(pe,",");}
		if(libc_strchr(pe,'}')){pe=libc_strpstr(pe,"}");}
		
	   if (libc_strchr(pe,'.') || libc_strchr(pe,'e') || libc_strchr(pe,'E')){
		   js=create_json(JSON_DOUBLE, key, parent);
		   js->value=pe;
		   }else{
		js=create_json(JSON_INTEGER, key, parent);
		js->value=pe;	   
			   }

return p+libc_strlen(pe);
	   
        }
      case 't':
        if (!libc_strncmp(p, "true", 4)){
          js=create_json(JSON_BOOL, key, parent);
          js->value=(void*)1;
          return p+4;
        }
        JSON_REPORT_ERROR("unexpected chars",p);
        return 0; // error
      case 'f':
        if (!libc_strncmp(p, "false", 5)) {
          js=create_json(JSON_BOOL, key, parent);
          js->value=(void*)0;
          return p+5;
        }
        JSON_REPORT_ERROR("unexpected chars",p);
        return 0; // error
      case 'n':
        if (!libc_strncmp(p, "null", 4)) {
          create_json(JSON_NULL, key, parent);
          return p+4;
        }
        JSON_REPORT_ERROR("unexpected chars",p);
        return 0; // error
      case '/': // comment
        if (p[1]=='/') { // line comment
          char* ps=p;
          p=libc_strchr(p+2, '\n');
          if (!p) {
            JSON_REPORT_ERROR("endless comment",p);
            return 0; // error
          }
          p++;
        }
        else if (p[1]=='*') { // block comment
          p=skip_block_comment(p+2);
          if (!p) return 0;
        }
        else {
          JSON_REPORT_ERROR("unexpected chars",p);
          return 0; // error
        }
        break;
      default:
      p++;
     
        JSON_REPORT_ERROR("unexpected chars",p);
        //break;
        //return 0; // error
    }
  }
}
///------------------------------------------------------------
const json* json_parse(char* text) {
  json js={0};
  if (!parse_value(&js, 0, text)) {
    if (js.child) json_free(js.child);
    return 0;
  }
  return js.child;
}
///------------------------------------------------------------
const json* json_get(const json* sjson, char* key) {
  if (!sjson || !key) return &dummy; // never return null
  json* js;
  for (js=sjson->child; js; js=js->next) {
    if (js->key && !libc_strcmp(js->key, key)) return js;
  }
  return &dummy; 
}
///------------------------------------------------------------
const json* json_item(const json* sjson, int idx) {
  if (!sjson) return &dummy; // never return null
  json* js;
  for (js=sjson->child; js; js=js->next) {
    if (!idx--) return js;
  }
  return &dummy; 
}
///------------------------------------------------------------
json* __json_set(json* js, int type,...){
va_list atr;
va_start(atr, type);
int lenkey=0,lenvalue=0,z=0,lensrc=0,lenthis=0;	
char* value=NULL,*key=NULL;json* child;

if((type==JSON_OBJECT || type==JSON_ARRAY || type==JSON_AGENT) && js==(json*)0){
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
if((type==JSON_OBJECT || type==JSON_ARRAY || type==JSON_AGENT) && js!=(json*)0){

if(js->type!=JSON_ARRAY){
	key=va_arg(atr, char*);
	lenkey=(key!=NULL)?libc_strlen(key):0;
	child=va_arg(atr, json*);
	lenvalue=(child->src!=NULL)?libc_strlen(child->src):0;
	js->this=NULL;
	js->this=malloc((lenkey+lenvalue+9)*sizeof(js->this));
js->this[z]='"'; z++;
libc_strcat(js->this,key); z=z+lenkey;
js->this[z]='"'; z++;
js->this[z]=':'; z++;
libc_strcat(js->this,child->src); z=z+lenvalue;

}else{
	child=va_arg(atr, json*);
	lenkey=(child->src!=NULL)?libc_strlen(child->src):0;
	js->this=NULL;
	js->this=malloc((lenkey+lenvalue+9)*sizeof(js->this));
	libc_strcat(js->this,child->src); z=z+lenkey;
	}
	}else{															
key=va_arg(atr, char*); 
if(key!=NULL){value=va_arg(atr, char*);}
lenkey=(key!=NULL)?libc_strlen(key):0;
lenvalue=(value!=NULL)?libc_strlen(value):0;
}														

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
if(value!=NULL){
js->this[z]='"'; z++;
libc_strcat(js->this,key); z=z+lenkey;
js->this[z]='"'; z++;
js->this[z]=':'; z++;
libc_strcat(js->this,value); z=z+lenvalue;
}else{libc_strcat(js->this,key); z=z+lenkey;}
break;
				}
case JSON_DOUBLE:{
if(value!=NULL){
js->this[z]='"'; z++;
libc_strcat(js->this,key); z=z+lenkey;
js->this[z]='"'; z++;
js->this[z]=':'; z++;
libc_strcat(js->this,value); z=z+lenvalue;
}else{libc_strcat(js->this,key); z=z+lenkey;}
break;
				}
case JSON_NULL:{
if(value!=NULL){
js->this[z]='"'; z++;
libc_strcat(js->this,key); z=z+lenkey;
js->this[z]='"'; z++;
js->this[z]=':'; z++;
}
libc_strcat(js->this,"null"); z=z+4;

break;
				}

case JSON_BOOL:{
if(js->type==JSON_ARRAY && key==NULL){libc_strcat(js->this,"false"); z=z+5;break;}
	
if(js->type==JSON_ARRAY && value==NULL){
if(!libc_strncmpi(key,"false",5)){libc_strcat(js->this,"false"); z=z+5;}else
if(!libc_strncmpi(key,"true",4)){libc_strcat(js->this,"true"); z=z+4;}else
{libc_strcat(js->this,"true"); z=z+4;}	
break;
		}else{
		
js->this[z]='"'; z++;
libc_strcat(js->this,key); z=z+lenkey;
js->this[z]='"';z++;
js->this[z]=':';z++;
if(value==NULL){
	libc_strcat(js->this,"false"); z=z+5;
}else{
if(!libc_strncmpi(value,"false",5)){libc_strcat(js->this,"false"); z=z+5;}else
if(!libc_strncmpi(value,"true",4)){libc_strcat(js->this,"true"); z=z+4;}else
{libc_strcat(js->this,"true"); z=z+4;}	
	}
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
	js->src=realloc(js->src,(z+lensrc)*sizeof(json));
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
char* buff=libc_malloc(len*sizeof(buff)*10);
while(i<len){
if(src[i]==','|| src[i]=='{' || src[i]=='[' || src[i]=='(' || src[i]=='}' || src[i]==']' || src[i]==')'){buff[z]=src[i];z++;buff[z]='\n';z++;}else
if(src[i]=='"' && (src[i-1]==',' || src[i-1]=='{')){buff[z]='\t';z++;buff[z]=src[i];z++;}else
{buff[z]=src[i];z++;}	
	
	i++;}
	
write(fd,buff,libc_strlen(buff));
libc_free(buff);	
								}
///---------------------------------------------------------------------
/*

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






json_out* js=json_set(NULL,JSON_AGENT);
js=json_set(js,JSON_STRING,"f","lib_strlen");
js=json_set(js,JSON_STRING,"t",NULL);
js=json_set(js,JSON_STRING,"r","len");
js=json_set(js,JSON_STRING,"a","$test");
//printf("%s\n",js->src); 

json_out* obj=json_start(JSON_OBJECT);
obj=json_set(obj,JSON_INTEGER,"strlen",js->src);
obj=json_set(obj,JSON_STRING,"test","varable");
printf("%s\n",obj->src); 

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
