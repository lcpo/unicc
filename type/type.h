///----------------------------------------------------------------------type
#ifndef _UNIC_C_STRUCTURE_TYPE
#define _UNIC_C_STRUCTURE_TYPE
static char ** 	type_$t;
static uni		type_$l;
static uni		type_$z;
static char *** type_$i;						//! Синонимы типа
#define set_type($_arg) set_type_item(#$_arg) 	//! Регистрация типа
#endif

///----------------------------------------------------------------------var
#ifndef _UNIC_C_STRUCTURE_VARIABLE
#define _UNIC_C_STRUCTURE_VARIABLE
static uni  ** 		var_$;		//!Адрес переменной в памяти
static uni  *  		var_$t; 	//!номер зарегистрированного типа
static char ** 		var_$n; 	//!Имя переменной
static uni  *  		var_$f; 	//!Адрес функции где появилась переменная
static uni 			var_$l; 	//!Количество записей структуры
#endif
///----------------------------------------------------------------------func
#ifndef _UNIC_C_STRUCTURE_FUNCTION
#define _UNIC_C_STRUCTURE_FUNCTION
/*
typedef uni * (*func)(uni *p,...);
typedef uni * object,Object,class,Class,new,obj,Obj,function;

static func * 	fun_$;  		//! адрес функции
static char ** 	fun_$n; 		//! название функции
static uni  * 	fun_$o;			//! то что возвращает функция
static uni  * 	fun_$p;			//! функция прородитель, в случае первичной является родителем себя самой:)
static uni  * 	fun_$a;			//! Количество аргументов|-1 бесконечное
static uni 		fun_$l; 		//! количество записей
static char *** fun_$i;			//! Синонимы функции
*/
#endif




