#ifndef _TYPE_UNIC_C
#define _TYPE_UNIC_C

	#ifndef $
#define $ unic_
	#endif

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

//----------------------------------------------------------------------



	#ifdef __i386__
typedef unsigned int size; 
	#endif

	#ifdef __x86_64__
typedef unsigned long size; 
	#endif

#ifndef wchar
typedef void* wchar;
#endif

//----------------------------------------------------------------------
typedef uni_t uni;
//----------------------------------------------------------------------
#define MAX_ARG 1024*32
#define swap(x, y) do { typeof(x) __temp = x; x = y; y = __temp; } while (0)
#endif

#ifdef __i386__
#define $_MEM_STEP 64
#endif

#ifdef __x86_64__
#define $_MEM_STEP 128
#endif








