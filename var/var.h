
///----------------------------------------------------------------------var
#ifndef _UNIC_C_STRUCTURE_VARIABLE
#define _UNIC_C_STRUCTURE_VARIABLE
static uni  ** 		var_$;		//!Адрес переменной в памяти
static uni  *  		var_$t; 	//!номер зарегистрированного типа
static char ** 		var_$n; 	//!Имя переменной
static uni  *  		var_$f; 	//!Адрес функции где появилась переменная
static uni 			var_$l; 	//!Количество записей структуры
#endif
///----------------------------------------------------------------------var
char __mem_amkey[MAX_ARG]; //Темповая переменная
char __mem_array_name[MAX_ARG]; //Темповая переменная
char __mem_attr[MAX_ARG]; //Темповая переменная

#define var($_addr,$_type,$_fu)({\
($_type) set_var_item((uni*)&$_addr,#$_type,#$_addr,(uni)&$_fu);\
}) //!регистрирует новую переменную

#define val($_addr,$_val)({\
set_val((uni*)&$_addr,#$_val,(char*)get_var_type((uni*)&$_addr));\
$_addr=(typeof($_addr))$_val;\
$_addr;}) //!Добавлет значение в переменную и выделяет под нее память 

#define push //!TODO:Добавляет значение в массив и выделяет под него память

#define delete($_addr)({uni $_$_pl=get_var_id((uni*)&$_addr);dell_var_item($_$_pl);}) //! Удаляет переменную

