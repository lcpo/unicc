
//----------------------------------------------------------------------
typedef enum json_type {JSON_NULL, JSON_OBJECT, JSON_ARRAY,JSON_STRING, JSON_INTEGER, JSON_DOUBLE, JSON_BOOL} json_type;
typedef struct json {
	json_type type; 
	char* key;  
	char* value;  
	int length;  
	struct json* child; 
	struct json* next; 
	struct json* last_child;
	} json;

typedef struct json_out{
int type;
char* obj;
char* arr;
char* str;
long lon;
double dou;	
	}json_out;

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
///---------------------------------------------------------------------
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
///---------------------------------------------------------------------
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
///---------------------------------------------------------------------
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
///---------------------------------------------------------------------
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
///---------------------------------------------------------------------
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
///---------------------------------------------------------------------
const json* json_parse(char* text) {
  json js={0};
  if (!parse_value(&js, 0, text)) {
    if (js.child) json_free(js.child);
    return 0;
  }
  return js.child;
}

const json* json_get(const json* sjson, char* key) {
  if (!sjson || !key) return &dummy; // never return null
  json* js;
  for (js=sjson->child; js; js=js->next) {
    if (js->key && !libc_strcmp(js->key, key)) return js;
  }
  return &dummy; 
}

const json* json_item(const json* sjson, int idx) {
  if (!sjson) return &dummy; // never return null
  json* js;
  for (js=sjson->child; js; js=js->next) {
    if (!idx--) return js;
  }
  return &dummy; 
}

