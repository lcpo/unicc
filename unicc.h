#ifndef $
#define $ unicc_
#endif

#ifdef _WIN32
#define $O 1
#define $memd 4
#else
#define $O 0
#define $memd 8
#endif
//#include "external/gc/gc.h"
//#include "external/pcre.h"
//#include "external/curl/curl.h"
//#include "external/mysql/mysql.h"


#ifndef _UNICC_C_GLOBAL_TYPE
#define _UNICC_C_GLOBAL_TYPE


	#ifndef NULL
#define NULL ((void*)0)
	#endif
//----------------------------------------------------------------------
	#ifndef EOF
#define EOF ((void*)-1)
	#endif
//----------------------------------------------------------------------

#ifndef uni_t
#undef uni_t

	#ifdef __i386__
#define  uni_t int
	#endif

	#ifdef __x86_64__
#define uni_t long
	#endif

#endif

///----------------------------------------------------------------------

	#ifdef __i386__
typedef unsigned int size; 
	#endif

	#ifdef __x86_64__
typedef unsigned long size; 
	#endif

#ifndef wchar
typedef void* wchar;
#endif

///----------------------------------------------------------------------
#define size_t size
///----------------------------------------------------------------------
typedef uni_t uni;
///----------------------------------------------------------------------

#define MAX_ARG 1024*32
#define swap(x, y) do { typeof(x) __temp = x; x = y; y = __temp; } while (0)
#endif

#ifdef __i386__
#define $_MEM_STEP 64
#endif

#ifdef __x86_64__
#define $_MEM_STEP 64
#endif


#include "elib/elib.h"
#include "elib/elib.c"

#define arg(x...)(__arg(x,NULL)) 									///Используется для ввода в функции и получении адресов в памяти и файле
typedef uni * (*func)(uni *p,...);
#define obj($_p...)({(func*)arg((void*)$_p);})         			///создание массива аргуметов для объекта
#define are(p,t) ((t)&p[0]) 										///получает все адреса элементов массива в бинарном файле, в виде макроса

#include "external/pcre.h"

#include "libc/libc.h"
#include "libc/libc.c"

#include "type/type.h"
#include "type/type.c"

#include "var/var.h"
#include "var/var.c"


#include "debug/debug.h"
#include "debug/debug.c"

#include "libu/libu.h"
#include "libu/libu.c"

#include "libo/libo.h"
#include "libo/libo.c"

