#include "fun/arg.c" //Требуется в переборке и оптимизации
/*!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Релиз функций/макросов для работы с функциями, редакция 13.01.13
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!*/
#define obj($_p...)({(obj)arg((void*)$_p);})                			///создание массива аргуметов для объекта
///---------------------------------------------------------------------
uni set_fun_item(func addr,char* name, char* out, uni par, uni narg) {
    uni ind=0;
    uni fl=0;
    int t_id=-1;
    if(type_$l<1) {
        init_type();
        }
    uni out_var=set_type_item(out);
    if(fun_$l==0) {
        fun_$=malloc(sizeof(fun_$));
        fun_$n=malloc(sizeof(fun_$n));
        fun_$o=malloc(sizeof(fun_$o));
        fun_$p=malloc(sizeof(fun_$p));
        fun_$a=malloc(sizeof(fun_$a));
        fun_$i=malloc(sizeof(fun_$i));
        
        }

    while(fun_$l>ind) {
        if(fun_$[ind]==addr) {
            fl=1;
            t_id=(int)ind;
            }
        ind++;
        }

    if(fl==0) {
        if(fun_$l>0) {
            fun_$=realloc(fun_$,hiddenCount((void**)fun_$)*($_MEM_STEP));
            fun_$n=realloc(fun_$n,hiddenCount((void**)fun_$n)*($_MEM_STEP));
            fun_$o=realloc(fun_$o,hiddenCount((void**)fun_$o)*($_MEM_STEP));
            fun_$p=realloc(fun_$p,hiddenCount((void**)fun_$p)*($_MEM_STEP));
            fun_$a=realloc(fun_$a,hiddenCount((void**)fun_$a)*($_MEM_STEP));
            fun_$i=realloc(fun_$i,hiddenCount((void**)fun_$i)*($_MEM_STEP));
            }
        fun_$[fun_$l]=addr;
        fun_$n[fun_$l]=malloc(hiddenStrlen(name)*($_MEM_STEP));
        fun_$n[fun_$l]=name;
        fun_$o[fun_$l]=out_var;
        fun_$p[fun_$l]=par;
        fun_$a[fun_$l]=narg;
        fun_$i[fun_$l]=malloc(hiddenStrlen(name)*($_MEM_STEP));
        fun_$i[fun_$l][0]=name;
        fun_$i[fun_$l][1]=0;
        t_id=fun_$l;
        fun_$l++;
        }
    return (uni)addr;
    }
    
///---------------------------------------------------------------------
#define set_fun($_addr,$_type,$_parent,$_narg)({                               \
set_fun_item((func)&$_addr,#$_addr,#$_type,(uni)$_parent,($_narg)?$_narg:-1);  \
})                                                        ///регистрация адреса функции
//----------------------------------------------------------------------
#define new($_addr,$_type,$_p...)({                                     \
set_fun_item((func)&$_addr,#$_addr,#$_type,(uni)$_addr,-1);              \
($_type)(*$_addr)($_p);})                                  ///Регистрация и вызов объекта
///---------------------------------------------------------------------
#define proc($_type,$_f,$_p...)({										\
set_type_item(#$_type);													\
uni $_addr=get_fun_name(#$_f);												\
func $_call=(func)$_addr;												\
($_type)$_call(arg($_p));												\
}) 															//!не документирована
//----------------------------------------------------------------------
#define fun($_type,$_f,$_p...)({										\
uni $_addr=get_fun_name(#$_f);											\
func $_call=(func)$_addr;												\
($_type)$_call((uni*)$_p);												\
})														  //!не документирована
//----------------------------------------------------------------------
uni set_fun_proto(char* name,char* addName){
uni i=0,n=0,id=-1,coAl=0;

    while(fun_$n[i]) {
        if(hiddenScmp(fun_$n[i],name)==2) {id=i;}
        n=0;
        while(fun_$i[i][n]!=0){
		if(hiddenScmp(fun_$i[i][n],name)==2){id=i;}
		if(hiddenScmp(fun_$i[i][n],addName)==2){id=-1;}
		n++;
							  }
		if(hiddenScmp(fun_$n[i],addName)==2){id=-1;}  
        i++;
        }
if(id!=-1){
coAl=hiddenCount((void**)fun_$i[id]);
	fun_$i[id]=realloc(fun_$i[id],coAl*($_MEM_STEP));
	fun_$i[id][coAl++]=addName;
	fun_$i[id][coAl++]=0;
	return 1;
	}else{
	return 0;
	}        

											}
///---------------------------------------------------------------------add fun alias
#define proto($_name,$_add_name)(set_fun_proto(#$_name,#$_add_name)) ///производит аналогию между основным именем и добавляет дополнительное	
//----------------------------------------------------------------------
uni get_id_fun(func item){//! получает ид по элементу
    uni i=0,id=-1;
    while(fun_$[i]) {
        if(fun_$[i]==item) {id=i;}
        i++;
        }
return id;	
	} 
//----------------------------------------------------------------------	
uni get_id_parant(func item){//! получает ид родителя (ид)
    uni i=0,id=-1,nid=-1;
    while(fun_$[i]) {
        if(fun_$[i]==item) {id=i;}
        i++;
        }
        i=0;
   while(fun_$[i]){
	  if(fun_$p==(uni*)fun_$[id]){nid=i;}
	   i++;}     
return nid;
	}
//----------------------------------------------------------------------
uni get_fun_name(char* name){//! получает адрес функции по имени
    uni i=0,id=-1,n=0;
    while(fun_$n[i]) {
        if(hiddenScmp(fun_$n[i],name)==2) {id=i;}
        n=0;
        while(fun_$i[i][n]!=0){
		if(hiddenScmp(fun_$i[i][n],name)==2){id=i;}
		n++;
								}
        i++;
        }
    if(id!=-1) {
        return (uni)fun_$[id];
        }
    else {
        return 0;
        }	
	}	 	
//----------------------------------------------------------------------
uni get_id_name(char* name){//! получает ид в структуре по имени
   uni i=0,id=-1;
    while(fun_$n[i]) {
        if(hiddenScmp(fun_$n[i],name)==2) {id=i;}
        i++;
					}
return id;
	} 
//----------------------------------------------------------------------
