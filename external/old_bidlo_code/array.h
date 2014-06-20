//----------------------------------------------------------------------
var  v(void* val){
mc("v()==non|file:lcpo.c");	
var out;
if(((char*)val)=="" || ((char*)val)==NULL){
	out.$=calloc(STRING_MAX,sizeof(char*));
	}else{
		out.$=malloc(strlen((char*)val));
		memcpy(out.$,(char*)val,strlen((char*)val));
		}
out.$t="var";
return out;

					}
//----------------------------------------------------------------------					
#define  array(v...)({\
	char* ar[]={v};\
	arr out;\
	out.$=c_malloc(sizeof(ar));\
	out.$=ar;\
	out.$t="arr";\
	out;})
//----------------------------------------------------------------------	
#define  array(v...)({char* ar[]={v};array out;out.$=calloc(ARRAY_MAX,sizeof(char**)); out.$=ar;out.$t="array";out;})	
char* add(char* val){
mc("add()|file:lcpo.c");
char* out=malloc(strlen(val)+1);
memcpy(out,val,strlen(val)+1);
return out;
					}
//----------------------------------------------------------------------					
#define is_array(arr)({\
int ret=0;\
if(sizeof(arr)/sizeof(&arr)>1){ret=1;}\
ret;}) //!!! -доработать
//----------------------------------------------------------------------
int array_search(char* str,char** ars){
int i=0;
while(ars[i]!=NULL){
if(compare(ars[i],str,"!=")){return i;}
i++;}
return -1;
	}
//----------------------------------------------------------------------
char** array_unique(char **ars){
char** item=Arr();
int i=0;
while(ars[i]!=NULL){
int id=array_search(ars[i],ars);
if(id!=-1 && id==i){item[id]=add(ars[i]);}else{item[i]='\0';}
i++;}
return item;	
	}	
