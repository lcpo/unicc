#ifdef __i386__
#define cpyquad(variable,value)asm("mov %0,%%ebx \n" "mov %%ebx, %0\n" : "=r"(variable): "r"(value));
#define cpylong cpyquad
#define ADDR(address ,variable) asm("mov  %%eax,%0 \n"	"mov  %0, %%eax \n" : "=r"(address) : "r"(variable));
#define IN_EDX(reg,t)asm("add %0, %%edx\n" "mov %%edx, %0\n" : "=r"(reg) : "r"(t));
#endif


#ifdef __x86_64__
#define cpylong(variable,value) asm("mov %%eax,%0\n" "mov %0,%%eax\n"	: "=r"(variable): "r"(value));
#define cpyquad(variable,value) asm("mov %%rax,%0\n" "mov %0,%%rax\n"	: "=r"(variable): "r"(value));
#define ADDR(address ,variable) asm("mov  %%rax,%0 \n"	"mov  %0, %%rax \n" : "=r"(address) : "r"(variable));
#define IN_EDX(reg,t)asm("addq %0, %%rdx\n" "movq %%rdx, %0\n" : "=r"(reg) : "r"(t));
#endif

#define cpy(variable,value)({\
if(sizeof(variable)<4){variable=value;}\
if(sizeof(variable)==4){cpylong(variable,value);}\
if(sizeof(variable)==8){cpyquad(variable,value);}\
	})

//----------------------------------------------------------------------
	#ifdef __i386__
#define SYS_CALL "int $0x80" 
	#endif
//----------------------------------------------------------------------
	#ifdef __x86_64__
#define SYS_CALL "syscall"
	#endif
//----------------------------------------------------------------------
///MAP
#define MAP_FAILED ((void*)-1)
#define O_RDONLY       0x0000 //открыть только на чтение
#define O_WRONLY       0x0001 //открыть только на запись
#define O_RDWR         0x0002 //открыть и на чтение и на запись
#define O_ACCMODE      0x0003

#define O_CREAT		0x0040


#define O_NOCTTY	0x0100
#define O_EXCL		0x0080
#define O_APPEND	0x0400 //Добавить в конец
#define O_TRUNC		0x0200 //Перезапись

#define O_NONBLOCK	0x0800
#define O_SYNC		0x1000
#define O_LARGEFILE	0

#define S_IRUSR 	   0400
#define S_IWUSR 	   0200
#define S_IXUSR 	   0100


   #define PROT_READ       0x1
   #define PROT_WRITE      0x2
   #define PROT_EXEC       0x4
   #define PROT_NONE       0x0
   
   #define MAP_SHARED      0x01
   #define MAP_PRIVATE     0x02
   #define MAP_FIXED       0x10
   #define MAP_ANONYMOUS   0x20            
   #define MAP_GROWSDOWN  0x100

   
   #define MAP_EXECUTABLE   0x1000          /* стек, как сегмент */
   #define MAP_DENYWRITE    0x2000
   #define MAP_NORESERVE    0x4000
   #define MAP_LOCKED       0x2000          /* заблокировать отображение */
   #define MAP_POPULATE 	0x8000
   #define MAP_NONBLOCK		0x10000
   #define MAP_STACK		0x20000
   #define MAX_MEMORY_VAR 1024
   

///END MAP

#ifdef __i386__
#include "unistd_x86.h"
#else
#include "unistd_x64.h"
#endif
#ifndef _STDINT_H
#include "stdint.h"
#endif




