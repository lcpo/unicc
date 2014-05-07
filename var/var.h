#ifndef $
#define $ unic_
#endif
#include "hidden.c"

void fun_null(void){return;}
#define clear_fun($_0_x)({typeof($_0_x) $_0_o=(typeof($_0_x))fun_null;$_0_o;})
#define clear_var($_0_v)({typeof($_0_v) $_0_o=(typeof($_0_v))NULL;$_0_o;})


///----------------------------------------------------------------------type
static char ** 	type_$t;
static uni		type_$l;
static uni		type_$z;
static char *** type_$i;	//! Синонимы типа
///----------------------------------------------------------------------var

static uni  ** 		var_$;	//!Адрес переменной в памяти
static uni  *  		var_$t; //!номер зарегистрированного типа
static char ** 		var_$n; //!Имя переменной
static uni  *  		var_$f; //!Адрес функции где появилась переменная
static uni 			var_$l; //!Количество записей структуры
///----------------------------------------------------------------------func
typedef uni * (*func)(uni *p,...);
typedef uni * object,Object,class,Class,new,obj,Obj,function;

static func * 	fun_$;  //! адрес функции
static char ** 	fun_$n; //! название функции
static uni  * 	fun_$o;	//! то что возвращает функция
static uni  * 	fun_$p;	//! функция прородитель, в случае первичной является родителем себя самой:)
static uni  * 	fun_$a;	//! Количество аргументов|-1 бесконечное
static uni 		fun_$l; //! количество записей
static char *** fun_$i;	//! Синонимы функции
///----------------------------------------------------------------------type
#define set_type($_arg) set_type_item(#$_arg)
#include "set_type.c"


///----------------------------------------------------------------------func
#include "set_fun.c"


///----------------------------------------------------------------------var
#include "set_var.c"
#define var($_addr,$_type,$_fu)({\
($_type) set_var_item((uni*)&$_addr,#$_type,#$_addr,(uni)&$_fu);\
}) //!регистрирует новую переменную


#define val($_addr,$_val)({\
set_val((uni*)&$_addr,#$_val,(char*)get_var_type((uni*)&$_addr));\
$_addr=(typeof($_addr))$_val;\
$_addr;}) //!Добавлет значение в переменную и выделяет под нее память 

#define push //!Добавляет значение в массив и выделяет под него память

#include "dell_var.c"
#define delete($_addr)({uni $_$_pl=get_var_id((uni*)&$_addr);dell_var_item($_$_pl);})

