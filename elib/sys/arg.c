#ifndef no_arg
//----------------------------------------------------------------------
#ifdef __x86_64__
#include "stdarg.h"
#endif

#ifdef __i386__
typedef void* va_list;
#define __va_argsiz(t) (((sizeof(t) + sizeof(uni) - 1) / sizeof(uni)) * sizeof(uni))
#define va_start(ap, pN) ((ap) = ((va_list) (&pN) + __va_argsiz(&pN)))
#define va_end(ap)	(ap=(void*)0)
#define va_arg(ap, t) (((ap) = (ap) + __va_argsiz(t)), *((t*)(void*)((ap) - __va_argsiz(t))))
#endif

extern void* malloc(size  __size);
extern void* realloc(void* ptr,size __size);
//----------------------------------------------------------------------
uni* __arg(void* p,...){
int i=0;
uni buff[MAX_ARG];
va_list arg;
va_start(arg,p);
while(p){buff[i++]=(uni)p; p=va_arg(arg,typeof(p));}
va_end(arg);
uni* out=(uni*)buff;
	return out;
	}

//----------------------------------------------------------------------
#define arg(x...)(__arg(x,NULL)) //Используется для ввода в функции и получении адресов в памяти и файле

#else
#define arg(x...)(#x)
#endif
//----------------------------------------------------------------------
#define are(p,t) ((t)&p[0]) //получает все адреса элементов массива в бинарном файле, в виде макроса

