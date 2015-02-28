///------------------------------------------------------------
#ifdef __i386__
asm(
"__syscall:\n" 
"pushl %ebp\n" 
"pushl %edi\n" 
"pushl %esi\n" 
"pushl %ebx\n"
"mov  (0+5)*4(%esp),%eax\n"
"mov  (1+5)*4(%esp),%ebx\n"
"mov  (2+5)*4(%esp),%ecx\n"
"mov  (3+5)*4(%esp),%edx\n"
"mov  (4+5)*4(%esp),%esi\n"
"mov  (5+5)*4(%esp),%edi\n"
"mov  (6+5)*4(%esp),%ebp\n"
"int $0x80\n"
"popl %ebx\n"
"popl %esi\n" 
"popl %edi\n" 
"popl %ebp\n" 
"ret"
);
#endif
///------------------------------------------------------------
#ifdef __x86_64__
asm(
"__syscall:\n" 
"movq %rdi,%rax\n"
"movq %rsi,%rdi\n"
"movq %rdx,%rsi\n"
"movq %rcx,%rdx\n"
"movq %r8,%r10\n"
"movq %r9,%r8\n"
"movq 8(%rsp),%r9\n"
"syscall\n" 
"ret\n" 
);
#endif
///------------------------------------------------------------
long __syscall(long ns, long a, long b, long c, long d, long e, long f, long g);
///------------------------------------------------------------
long sysrun(long ns, ...){
	void* atr;
	long  a,b,c,d,e,f,g;
	va_start(atr, ns);
	a=(long)va_arg(atr, long);
	b=(long)va_arg(atr, long);
	c=(long)va_arg(atr, long);
	d=(long)va_arg(atr, long);
	e=(long)va_arg(atr, long);
	f=(long)va_arg(atr, long);
	g=(long)va_arg(atr, long);
	va_end(atr);
	return (long)(__syscall(ns,a,b,c,d,e,f,g));
}
///------------------------------------------------------------


