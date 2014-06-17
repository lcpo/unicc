//extern void * malloc(size_t __size);
//extern void * realloc(void * __ptr, size_t __size);
//extern void free(void * __ptr);
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
#define O_RDONLY       00
#define O_WRONLY       01
#define O_RDWR         02

#define S_IRUSR 	   0400
#define S_IWUSR 	   0200
#define S_IXUSR 	   0100
#define PROT_READ       0x1 
#define PROT_WRITE      0x2 
#define PROT_EXEC       0x4 
#define PROT_NONE       0x0 
#define MAP_SHARED      0x01 
#define MAP_PRIVATE     0x02 
#define MAP_FILE        0
#define MAP_ANONYMOUS   0x20 
#define MAP_ANON        MAP_ANONYMOUS
#define MMAP_FLAGS MAP_PRIVATE | MAP_ANONYMOUS 
///END MAP

#ifdef __i386__
#include "unistd_x86.h"
#else
#include "unistd_x64.h"
#endif
#ifndef _STDINT_H
#include "stdint.h"
#endif




