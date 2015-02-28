#ifdef __x86_64__
#define va_argsiz(t) (((sizeof(t) + sizeof(void*) - 1) / sizeof(void*)) * sizeof(void*))
#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)
#define va_arg(v,l)	__builtin_va_arg(v,l)
#define va_copy(d,s)	__builtin_va_copy(d,s)
#endif

#ifdef __i386__
#define va_argsiz(t) (((sizeof(t) + sizeof(void*) - 1) / sizeof(void*)) * sizeof(void*))
#define va_start(ap, pN) ((ap) = ((void*) (&pN) + va_argsiz(&pN)))
#define va_end(ap)	(ap=NULL)
#define va_arg(ap, t) (((ap) = (ap) + va_argsiz(t)), *((t*)(void*)((ap) - va_argsiz(t))))
#define va_copy(d, s)      ((d) = (s), (void)0)
#endif

