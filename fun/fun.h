#ifndef _UNIC_C_STRUCTURE_FUNCTION
#define _UNIC_C_STRUCTURE_FUNCTION
typedef uni * (*func)(uni *p,...);
typedef uni * object,Object,class,Class,new,obj,Obj,function;

static func * 	fun_$;  		//! адрес функции
static char ** 	fun_$n; 		//! название функции
static uni  * 	fun_$o;			//! то что возвращает функция
static uni  * 	fun_$p;			//! функция прородитель, в случае первичной является родителем себя самой:)
static uni  * 	fun_$a;			//! Количество аргументов|-1 бесконечное
static uni 		fun_$l; 		//! количество записей
static char *** fun_$i;			//! Синонимы функции
#endif
#include "arg/arg.c" //Требуется в переборке и оптимизации
/*!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Релиз функций/макросов для работы с функциями, редакция 13.01.13
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!*/
#define obj($_p...)({(obj)arg((void*)$_p);})                			///создание массива аргуметов для объекта
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
///---------------------------------------------------------------------add fun alias
#define proto($_name,$_add_name)(set_fun_proto(#$_name,#$_add_name)) ///производит аналогию между основным именем и добавляет дополнительное	
