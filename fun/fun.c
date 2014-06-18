
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
        fun_$=libc_malloc(sizeof(fun_$));
        fun_$n=libc_malloc(sizeof(fun_$n));
        fun_$o=libc_malloc(sizeof(fun_$o));
        fun_$p=libc_malloc(sizeof(fun_$p));
        fun_$a=libc_malloc(sizeof(fun_$a));
        fun_$i=libc_malloc(sizeof(fun_$i));
        
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
            fun_$=libc_realloc(fun_$,libc_count((void**)fun_$)*($_MEM_STEP));
            fun_$n=libc_realloc(fun_$n,libc_count((void**)fun_$n)*($_MEM_STEP));
            fun_$o=libc_realloc(fun_$o,libc_count((void**)fun_$o)*($_MEM_STEP));
            fun_$p=libc_realloc(fun_$p,libc_count((void**)fun_$p)*($_MEM_STEP));
            fun_$a=libc_realloc(fun_$a,libc_count((void**)fun_$a)*($_MEM_STEP));
            fun_$i=libc_realloc(fun_$i,libc_count((void**)fun_$i)*($_MEM_STEP));
            }
        fun_$[fun_$l]=addr;
        fun_$n[fun_$l]=libc_malloc(libc_strlen(name)*($_MEM_STEP));
        fun_$n[fun_$l]=name;
        fun_$o[fun_$l]=out_var;
        fun_$p[fun_$l]=par;
        fun_$a[fun_$l]=narg;
        fun_$i[fun_$l]=libc_malloc(libc_strlen(name)*($_MEM_STEP));
        fun_$i[fun_$l][0]=name;
        fun_$i[fun_$l][1]=0;
        t_id=fun_$l;
        fun_$l++;
        }
    return (uni)addr;
    }
    
///----------------------------------------------------------------------
uni set_fun_proto(char* name,char* addName){
uni i=0,n=0,id=-1,coAl=0;

    while(fun_$n[i]) {
        if(libc_scmp(fun_$n[i],name)==2) {id=i;}
        n=0;
        while(fun_$i[i][n]!=0){
		if(libc_scmp(fun_$i[i][n],name)==2){id=i;}
		if(libc_scmp(fun_$i[i][n],addName)==2){id=-1;}
		n++;
							  }
		if(libc_scmp(fun_$n[i],addName)==2){id=-1;}  
        i++;
        }
if(id!=-1){
coAl=libc_count((void**)fun_$i[id]);
	fun_$i[id]=libc_realloc(fun_$i[id],coAl*($_MEM_STEP));
	fun_$i[id][coAl++]=addName;
	fun_$i[id][coAl++]=0;
	return 1;
	}else{
	return 0;
	}        

											}
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
        if(libc_scmp(fun_$n[i],name)==2) {id=i;}
        n=0;
        while(fun_$i[i][n]!=0){
		if(libc_scmp(fun_$i[i][n],name)==2){id=i;}
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
        if(libc_scmp(fun_$n[i],name)==2) {id=i;}
        i++;
					}
return id;
	} 
//----------------------------------------------------------------------

/*!
 * На будущее: упразнить работу с именами функций через предобработчик-парсер
 */
 
//get_fun_id // получает ид по элементу
//get_parant_id // получает массив ид по родителю (ид)
//get_children_id //полчает массив ид по детям (ид)

//get_fun_name // получает ид по имени
//get_parant_name // получает массив ид по родителю (имени)
//get_children_name //полчает массив ид по детям (имени)

//get_fun //получает элемент по имени
//get_parant //получает массив элементов по родителю
//get_children //получает массив элементов по детям

//set_in //уровни доступа метода и поведение

//rename_fun //переименовывает элемент
//back_fun //возвращает предыдущее состояние элемента

//extends // массовое наследование методов
//extend //заменяет метод модифицированным аналогом

//general //Добавить метод из одного класса в другой
//genes // добавить в класс методы () от других классов

//unset_fun //удаляет элемент и дочерние по имени
//unset_fun_id //удаляет элемент и дочерние элементы по ид
//unset_parant_name //удаляет родителей и все родительские элементы возвращает исходное состояние по имени
//unset_parant_id //удаляет родителей и все родительские элементы возвращает исходное состояние по ид
//unset_children_name //удаляет всех детей у элемента по имени
//unset_children_id //удаляет всех детей у элемента по имени
//unset_children //удаляет всех детей у элемента по адресу
//unset_parant //удаляет родителей и все родительские элементы возвращает исходное состояние по адресу

//sort_fun //сортировка функций после удаления 


//----------------------------------------------------------------------
uni* get_children_id(func item){//полчает массив ид по детям (ид)
	
	} 
//----------------------------------------------------------------------
uni* get_parant_name(char* name){// получает массив ид по родителю (имени)
	
	} 
//----------------------------------------------------------------------
uni* get_children_name(char* name){	 //полчает массив ид по детям (имени)
	
	}
//----------------------------------------------------------------------
/*
uni get_fun(char* name) {//Получает элемент по имени
    uni i=0,id=-1,n=0;
    while(fun_$n[i]) {
        if(libc_scmp(fun_$n[i],name)==2) {id=i;}
        n=0;
        while(fun_$i[i][n]!=0){
		if(libc_scmp(fun_$i[i][n],name)==2){id=i;}
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
*/											
//----------------------------------------------------------------------
uni* get_parant(char* name){} //получает массив элементов по родителю
//----------------------------------------------------------------------
uni* get_children(char* name){} //получает массив элементов по детям
//----------------------------------------------------------------------
uni set_in(char* name){} //уровни доступа метода и поведение добавляет
uni get_in(char* name){} //уровни доступа метода и поведение получает
//----------------------------------------------------------------------
uni rename_fun(char* name, char* newName){ //переименовывает элемент
//Необходимо изменить основное имя на новое, если нового нет в алиасах то добавить. 	
	}
//----------------------------------------------------------------------
uni back_fun(uni id){ //возвращает предыдущее состояние элемента
	
	}
//----------------------------------------------------------------------
uni extends(char* met){ // массовое наследование методов

}
//----------------------------------------------------------------------
//uni extend(char* met, char* newMet){} //заменяет метод модифицированным аналогом
//uni general(char* class1,char* class2){} //Добавить метод из одного класса в другой
//uni genes(char* class1,uni* classes){} // добавить в класс методы () от других классов

//unset_fun //удаляет элемент по адресу
//unset_fun_name //удаляет элемент и дочерние по имени
//unset_fun_id //удаляет элемент и дочерние элементы по ид




//unset_parant_name //удаляет родителей и все родительские элементы возвращает исходное состояние по имени
//unset_parant_id //удаляет родителей и все родительские элементы возвращает исходное состояние по ид

//unset_children_name //удаляет всех детей у элемента по имени
//unset_children_id //удаляет всех детей у элемента по имени
//unset_children //удаляет всех детей у элемента по адресу

//unset_parant //удаляет родителей и все родительские элементы возвращает исходное состояние по адресу

//sort_fun //сортировка функций после удаления 

	
												
											
											
											
//----------------------------------------------------------------------
uni unset_fun_struct(uni id){
uni i=0;
fun_$[id]=(func)-1;
fun_$n[id]=(char*)"\0";
fun_$o[id]=(uni)1;
fun_$p[id]=(uni)-1;
fun_$a[id]=(uni)-1;


while(fun_$i[id][i]!=NULL){
if(fun_$p[i]==(uni)fun_$[id] && fun_$p[i]!=(uni)fun_$[i]){unset_fun_struct(i);}
fun_$i[id][i]=(char*)"\0";
i++;}

return 1;	
	}
//----------------------------------------------------------------------
uni unset_fun(char* name){//Удаляет элемент и все дочерние элементы

    uni i=0,id=-1,n=0;
    while(fun_$n[i]) {
        if(libc_scmp(fun_$n[i],name)==2) {id=i;}
        n=0;
        while(fun_$i[i][n]!=0){
		if(libc_scmp(fun_$i[i][n],name)==2){id=i;}
		n++;
								}
        i++;
        }
    if(id!=-1) {
n=0;
i=0;
while(fun_$l>n){
if(fun_$p[n]==(uni)fun_$[id] && fun_$p[n]!=(uni)fun_$[n]){unset_fun_struct(n);}
	n++;
	}
unset_fun_struct(id);        


        return 1;
        }else {
        return 0;
        }
	
	}
											


