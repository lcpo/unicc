//----------------------------------------------------------------------
#ifdef __x86_64__
#include "sys/stdarg.h"
#endif

#ifdef __i386__
typedef void* va_list;
#define __va_argsiz(t) (((sizeof(t) + sizeof(uni) - 1) / sizeof(uni)) * sizeof(uni))
#define va_start(ap, pN) ((ap) = ((va_list) (&pN) + __va_argsiz(&pN)))
#define va_end(ap)	(ap=(void*)0)
#define va_arg(ap, t) (((ap) = (ap) + __va_argsiz(t)), *((t*)(void*)((ap) - __va_argsiz(t))))
#endif

extern void* malloc(size_t  size);
extern void* realloc(void* ptr,size_t size);
#define MAX_ARG 32*1024
//----------------------------------------------------------------------
uni* __arg(void* p,...){
int i=0;
uni buff[MAX_ARG]; //=malloc(0);
va_list arg;
va_start(arg,p);
while(p){buff[i++]=(uni)p; p=va_arg(arg,typeof(p));}
va_end(arg);
uni* out=(uni*)buff;
	return out;
	}

//----------------------------------------------------------------------
#define arg(x...)(__arg(x,NULL)) //Используется для ввода в функции и получении адресов в памяти и файле
//----------------------------------------------------------------------
#define are(p,t) ((t)&p[0]) //получает все адреса элементов массива в бинарном файле, в виде макроса

extern void printi(int i);
extern void prints(char* s);


///example
//uni_u ars=arg(arg0,arg1,arg2,arg3); //получает положительные адреса (бинарник) (для ввода и вывода)
//uni_u ars=arg(&arg0,&arg1,&arg2,&arg3); //получает отрицательные адреса (память) каждый адрес граничит зарегистрированым адресом переменной
/* /для вывода
int i=0;
while(ars[i]!=0){
itos(to,ars[i]);
print(to,lens(to));
//print("\n",1);
//print((char*)ars[i],lens((char*)ars[i]));
print("\n",1);
	i++;}
*/
