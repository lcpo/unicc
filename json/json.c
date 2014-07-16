
//----------------------------------------------------------------------
typedef enum json_type {
  JSON_NULL,    // this is null value
  JSON_OBJECT,  // this is an object; properties can be found in child nodes
  JSON_ARRAY,   // this is an array; items can be found in child nodes
  JSON_STRING,  // this is a string; value can be found in text_value field
  JSON_INTEGER, // this is an integer; value can be found in int_value field
  JSON_DOUBLE,  // this is a double; value can be found in dbl_value field
  JSON_BOOL     // this is a boolean; value can be found in int_value field
} json_type;

typedef struct json {
  json_type type;       // type of json node, see above
  char* key;         // key of the property; for object's children only
  char* text_value;  // text value of STRING node
  long int_value;          // the value of INTEGER or BOOL node
  double dbl_value;        // the value of DOUBLE node
  int length;              // number of children of OBJECT or ARRAY
  struct json* child;   // points to first child
  struct json* next;    // points to next child
  struct json* last_child;
} json;

typedef int (*json_unicode_encoder)(unsigned int codepoint, char* p, char** endp);

extern json_unicode_encoder json_unicode_to_utf8;

const json* json_parse(char* text, json_unicode_encoder encoder);
const json* json_parse_utf8(char* text);
void json_free(const json* js);
const json* json_get(const json* sjson, char* key); // get object's property by key
const json* json_item(const json* sjson, int idx); // get array element by index



#ifndef JSON_CALLOC
#define JSON_CALLOC() malloc(sizeof(json))
#define JSON_FREE(sjson) libc_free((void*)(sjson))
#endif


#ifndef JSON_REPORT_ERROR
#define JSON_REPORT_ERROR(p) printf("NXJSON PARSE ERROR (%d): %s\n", __LINE__, p)
#endif

#define IS_WHITESPACE(c) ((unsigned char)(c)<=(unsigned char)' ')

static const json dummy={ JSON_NULL };

static json* create_json(json_type type, char* key, json* parent) {
  json* js=JSON_CALLOC();
  assert(js);
  js->type=type;
  js->key=key;
  if (!parent->last_child) {
    parent->child=parent->last_child=js;
  }
  else {
    parent->last_child->next=js;
    parent->last_child=js;
  }
  parent->length++;
  return js;
}

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

static int unicode_to_utf8(unsigned int codepoint, char* p, char** endp) {
  if (codepoint<0x80) *p++=codepoint;
  else if (codepoint<0x800) *p++=192+codepoint/64, *p++=128+codepoint%64;
  else if (codepoint-0xd800u<0x800) return 0; 
  else if (codepoint<0x10000) *p++=224+codepoint/4096, *p++=128+codepoint/64%64, *p++=128+codepoint%64;
  else if (codepoint<0x110000) *p++=240+codepoint/262144, *p++=128+codepoint/4096%64, *p++=128+codepoint/64%64, *p++=128+codepoint%64;
  else return 0; // error
  *endp=p;
  return 1;
}

json_unicode_encoder json_unicode_to_utf8=unicode_to_utf8;

static inline int hex_val(char c) {
  if (c>='0' && c<='9') return c-'0';
  if (c>='a' && c<='f') return c-'a'+10;
  if (c>='A' && c<='F') return c-'A'+10;
  return -1;
}

static char* unescape_string(char* s, char** end, json_unicode_encoder encoder) {
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
        case 'u': // unicode
          if (!encoder) {
            // leave untouched
            *d++=c;
            break;
          }
          char* ps=p-1;
          int h1, h2, h3, h4;
          if ((h1=hex_val(p[1]))<0 || (h2=hex_val(p[2]))<0 || (h3=hex_val(p[3]))<0 || (h4=hex_val(p[4]))<0) {
            JSON_REPORT_ERROR("invalid unicode escape");
            return 0;
          }
          unsigned int codepoint=h1<<12|h2<<8|h3<<4|h4;
          if ((codepoint & 0xfc00)==0xd800) { // high surrogate; need one more unicode to succeed
            p+=6;
            if (p[-1]!='\\' || *p!='u' || (h1=hex_val(p[1]))<0 || (h2=hex_val(p[2]))<0 || (h3=hex_val(p[3]))<0 || (h4=hex_val(p[4]))<0) {
              JSON_REPORT_ERROR("invalid unicode surrogate");
              return 0;
            }
            unsigned int codepoint2=h1<<12|h2<<8|h3<<4|h4;
            if ((codepoint2 & 0xfc00)!=0xdc00) {
              JSON_REPORT_ERROR("invalid unicode surrogate");
              return 0;
            }
            codepoint=0x10000+((codepoint-0xd800)<<10)+(codepoint2-0xdc00);
          }
          if (!encoder(codepoint, d, &d)) {
            JSON_REPORT_ERROR("invalid codepoint");
            return 0;
          }
          p+=5;
          break;
        default:
          // leave untouched
          *d++=c;
          break;
      }
    }
    else {
      *d++=c;
    }
  }
  JSON_REPORT_ERROR("no closing quote for string");
  return 0;
}

static char* skip_block_comment(char* p) {
  
  char* ps=p-2;
  if (!*p) {
    JSON_REPORT_ERROR("endless comment");
    return 0;
  }
  REPEAT:
  p=libc_strchr(p+1, '/');
  if (!p) {
    JSON_REPORT_ERROR("endless comment");
    return 0;
  }
  if (p[-1]!='*') goto REPEAT;
  return p+1;
}

static char* parse_key(char** key, char* p, json_unicode_encoder encoder) {

  char c;
  while ((c=*p++)) {
    if (c=='"') {
      *key=unescape_string(p, &p, encoder);
      if (!*key) return 0; // propagate error
      while (*p && IS_WHITESPACE(*p)) p++;
      if (*p==':') return p+1;
      JSON_REPORT_ERROR("unexpected chars");
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
          JSON_REPORT_ERROR("endless comment");
          return 0; // error
        }
        p++;
      }
      else if (*p=='*') { // block comment
        p=skip_block_comment(p+1);
        if (!p) return 0;
      }
      else {
        JSON_REPORT_ERROR("unexpected chars1");
        return 0; // error
      }
    }
    else {
      JSON_REPORT_ERROR("unexpected chars2");
      //return 0; // error
    }
  }
  JSON_REPORT_ERROR("unexpected chars3");
  return 0; // error
}

static char* parse_value(json* parent, char* key, char* p, json_unicode_encoder encoder) {

  json* js;
  while (1) {
    switch (*p) {
      case '\0':
        JSON_REPORT_ERROR("unexpected end of text");
        return 0; // error
      case ' ': case '\t': case '\n': case '\r':case ',':
        // skip
        p++;
        break;
      case '{':
        js=create_json(JSON_OBJECT, key, parent);
        p++;
        while (1) {
          char* new_key;
          p=parse_key(&new_key, p, encoder);
          if (!p) return 0; // error
          if (*p=='}') return p+1; // end of object
          p=parse_value(js, new_key, p, encoder);
          if (!p) return 0; // error
        }
      case '[':
      
        js=create_json(JSON_ARRAY, key, parent);
        p++;
        while (1) {
          p=parse_value(js, 0, p, encoder);
          if (!p) return 0; // error
          if (*p==']') return p+1; // end of array
        }
        
        return p;
      case ']':
        return p;
      case '"':
        p++;
        js=create_json(JSON_STRING, key, parent);
        js->text_value=unescape_string(p, &p, encoder);
        if (!js->text_value) return 0; // propagate error
        return p;
      case '-': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        {
char* pe;
		pe=libc_strpstr(p,",");
		if(libc_strchr(pe,']')){pe=libc_strpstr(pe,"]");}
		if(libc_strchr(pe,'}')){pe=libc_strpstr(pe,"}");}

	   if (libc_strchr(pe,'.') || libc_strchr(pe,'e') || libc_strchr(pe,'E')){
		   js=create_json(JSON_DOUBLE, key, parent);
		   js->dbl_value=libc_stof(pe);
		   }else{
		js=create_json(JSON_INTEGER, key, parent);
		js->int_value=libc_stol(pe);	   
			   }

	   return p+libc_strlen(pe);
        }
      case 't':
        if (!libc_strncmp(p, "true", 4)) {
          js=create_json(JSON_BOOL, key, parent);
          js->int_value=1;
          return p+4;
        }
        JSON_REPORT_ERROR("unexpected chars01");
        return 0; // error
      case 'f':
        if (!libc_strncmp(p, "false", 5)) {
          js=create_json(JSON_BOOL, key, parent);
          js->int_value=0;
          return p+5;
        }
        JSON_REPORT_ERROR("unexpected chars02");
        return 0; // error
      case 'n':
        if (!libc_strncmp(p, "null", 4)) {
          create_json(JSON_NULL, key, parent);
          return p+4;
        }
        JSON_REPORT_ERROR("unexpected chars03");
        return 0; // error
      case '/': // comment
        if (p[1]=='/') { // line comment
          char* ps=p;
          p=libc_strchr(p+2, '\n');
          if (!p) {
            JSON_REPORT_ERROR("endless comment");
            return 0; // error
          }
          p++;
        }
        else if (p[1]=='*') { // block comment
          p=skip_block_comment(p+2);
          if (!p) return 0;
        }
        else {
          JSON_REPORT_ERROR("unexpected chars-1");
          return 0; // error
        }
        break;
      default:
      p++;
     // break;
        JSON_REPORT_ERROR("unexpected chars-2");
        //return 0; // error
    }
  }
}

const json* json_parse_utf8(char* text) {
  return json_parse(text, unicode_to_utf8);
}

const json* json_parse(char* text, json_unicode_encoder encoder) {
  json js={0};
  if (!parse_value(&js, 0, text, encoder)) {
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
  return &dummy; // never return null
}

const json* json_item(const json* sjson, int idx) {
  if (!sjson) return &dummy; // never return null
  json* js;
  for (js=sjson->child; js; js=js->next) {
    if (!idx--) return js;
  }
  return &dummy; // never return null
}

