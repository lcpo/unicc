/*! ~ Системные функции, обращение на уровне ядра ~ !*/
///------------------------------------------------------------
//http://blog.rchapman.org/post/36801038863/linux-system-call-table-for-x86-64
//http://numactl.sourcearchive.com/documentation/0.9/syscall_8c-source.html!!!
///------------------------------------------------------------
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
///------------------------------------------------------------
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

///------------------------------------------------------------
#ifdef __i386__
asm(
"__syscall:\n" 
"pushl %ebp\n" 
"pushl %edi\n" 
"pushl %esi\n" 
"pushl %ebx\n"
"movl  (0+5)*4(%esp),%eax\n"
"movl  (1+5)*4(%esp),%ebx\n"
"movl  (2+5)*4(%esp),%ecx\n"
"movl  (3+5)*4(%esp),%edx\n"
"movl  (4+5)*4(%esp),%esi\n"
"movl  (5+5)*4(%esp),%edi\n"
"movl  (6+5)*4(%esp),%ebp\n"
"int $0x80\n"
"popl %ebx\n"
"popl %esi\n" 
"popl %edi\n" 
"popl %ebp\n" 
"ret");
#endif
///------------------------------------------------------------
#ifdef __x86_64__
asm("__syscall:\n" "movq %rdi,%rax\n" "movq %rsi,%rdi\n" "movq %rdx,%rsi\n"
"movq %rcx,%rdx\n" "movq %r8,%r10\n" "movq %r9,%r8\n" "movq 8(%rsp),%r9\n"
"syscall\n" "ret\n" );
#endif
///------------------------------------------------------------
long __syscall(long ns, long a, long b, long c, long d, long e, long f);
///------------------------------------------------------------
long __sysrun(long ns, ...){
	va_list atr;
	long  a,b,c,d,e,f;
	va_start(atr, ns);
	a=va_arg(atr, long);
	b=va_arg(atr, long);
	c=va_arg(atr, long);
	d=va_arg(atr, long);
	e=va_arg(atr, long);
	f=va_arg(atr, long);
	va_end(atr);
	return (long)(__syscall(ns,a,b,c,d,e,f));
}
///------------------------------------------------------------
#define __syscall0(n) __sysrun(n)
#define __syscall1(n,a) __sysrun(n,(long)(a))
#define __syscall2(n,a,b) __sysrun(n,(long)(a),(long)(b))
#define __syscall3(n,a,b,c) __sysrun(n,(long)(a),(long)(b),(long)(c))
#define __syscall4(n,a,b,c,d) __sysrun(n,(long)(a),(long)(b),(long)(c),(long)(d))
#define __syscall5(n,a,b,c,d,e) __sysrun(n,(long)(a),(long)(b),(long)(c),(long)(d),(long)(e))
#define __syscall6(n,a,b,c,d,e,f) __sysrun(n,(long)(a),(long)(b),(long)(c),(long)(d),(long)(e),(long)(f))
///------------------------------------------------------------
/*
struct stat {
  dev_t st_dev;
  ino_t st_ino;
  mode_t st_mode;
  nlink_t st_nlink;
  uid_t st_uid;
  gid_t st_gid;
  dev_t st_rdev;
  loff_t st_size;
  time_t st_atime;
  time_t st_mtime;
  time_t st_ctime;
};*/
struct stat_f{
  long st_dev;
  long st_ino;
  long st_mode;
  long st_nlink;
  long st_uid;
  long st_gid;
  long st_rdev;
  long st_size;
  long st_atime;
  long st_mtime;
  long st_ctime;
};
///------------------------------------------------------------
uni open(char * filename, uni flags, uni mode) {return __syscall3(__NR_open,filename,flags,mode);}
void close(uni fd) {__syscall1(__NR_close,fd);}
uni stat(char * filename, struct stat_f *buf) {return __syscall2(__NR_stat,filename,buf);}
uni fstat(int fd, struct stat_f *buf) {return __syscall2(__NR_fstat,fd,buf);}
uni lstat(char * filename, struct stat_f *buf) {return __syscall2(__NR_lstat,filename,buf);}

uni brk(void* brkv) {return __syscall1(__NR_brk,brkv);}
uni __exit(uni error_code){return __syscall1(__NR_exit,error_code); }
uni __exit(uni error_code) __attribute__ ((destructor));
#define exit __exit
uni getpid(void){return __syscall0(__NR_getpid);}
int fork(void){return __syscall0(__NR_fork);}
int vfork(void){return __syscall0(__NR_vfork);}
uni read(uni fd, char * buf, uni count) {return __syscall3(__NR_read,fd,buf,count);}
uni kill(uni pid, int sig){return __syscall2(__NR_kill,pid,sig);}
uni dup2(uni oldfd, uni newfd){return __syscall2(__NR_dup2,oldfd,newfd);}
uni alarm(int seconds){return __syscall1(__NR_alarm,seconds);}
uni pipe(int* filedes){return __syscall1(__NR_pipe,filedes);}
long time(long tloc){return __syscall1(__NR_time,tloc);}
int unlink(char* filename){return __syscall1(__NR_unlink,filename);}
uni nanosleep(uni rqtp, uni rmtp){return __syscall2(__NR_nanosleep,rqtp,rmtp);}
int readlink(char* path, char * buf, int bufsize){return __syscall3(__NR_readlink,path,buf,bufsize);}
int ioctl(unsigned int fd, unsigned int cmd, unsigned int arg){return __syscall3(__NR_ioctl,fd,cmd,arg);}
int execve(const char* filename, char * const argv[], char *const envp[]){return __syscall3(__NR_execve,filename,argv,envp);}
size write(int fd, void* buf, size count) {return __syscall3(__NR_write,fd,buf,count);}
int mprotect(void* start, size_t len, long prot) {return __syscall3(__NR_mprotect,start,len,prot);}
uni munmap(void *addr, uni len) {return __syscall2(__NR_munmap,addr,len);}
//void* mmap(void* addr, size len, int prot, int flags, int fd, unsigned long offset){return (void*)__syscall6(__NR_mmap,(long)&addr,len,prot,flags,fd,offset);}
void *mmap(void *start, size_t len, int prot, int flags, int fd, unsigned off)
{
	if (sizeof(unsigned) > sizeof(long))
		if (((long)off & 0xfff) | ((long)((unsigned long long)off>>(12 + 8*(sizeof(unsigned)-sizeof(long))))))
			start = (void *)-1;
#ifdef __NR_mmap2
	return (void *)__syscall6(__NR_mmap2, start, len, prot, flags, fd, off>>12);
#else
	return (void *)__syscall6(__NR_mmap, start, len, prot, flags, fd, off);
#endif
}

void *sbrk(long inc){return (void *)__syscall1(__NR_brk, __syscall1(__NR_brk, 0)+inc);}
///------------------------------------------------------------
uint64_t  __udivmoddi4(uint64_t num, uint64_t den, uint64_t * rem_p){
  uint64_t quot = 0, qbit = 1;
    if ( den == 0 ) {return 1/((unsigned)den);}
  while ( (int64_t)den >= 0 ) {den <<= 1; qbit <<= 1; }
 
  while ( qbit ) {
    if ( den <= num ) { num -= den; quot += qbit;}
     den >>= 1; qbit >>= 1;
				  }
   if ( rem_p ){*rem_p = num;}
   return quot;
																		}
///------------------------------------------------------------
uint64_t __udivdi3(uint64_t num, uint64_t den){return __udivmoddi4(num, den, NULL);}
///------------------------------------------------------------
uint64_t __umoddi3(uint64_t num, uint64_t den){ uint64_t v;(void) __udivmoddi4(num, den, &v);return v;} 
///------------------------------------------------------------
int64_t __moddi3(int64_t num, int64_t den){
  int minus = 0; int64_t v; 
  if ( num < 0 ) { num = -num; minus = 1; }
  if ( den < 0 ) { den = -den; minus ^= 1;}
  (void) __udivmoddi4(num, den, (uint64_t *)&v);
   if ( minus ){ v = -v;}
   return v;
 } 
///------------------------------------------------------------
int64_t __divdi3(int64_t num, int64_t den){
  int minus = 0; int64_t v;
  if ( num < 0 ) {num = -num; minus = 1; }
   if ( den < 0 ) { den = -den; minus ^= 1;}
    v = __udivmoddi4(num, den, NULL);
   if ( minus ){ v = -v;}
    return v;
}
///------------------------------------------------------------
void free(void *ptr){
if (ptr == NULL){return;}
ptr -= sizeof(ptr);
if(munmap(ptr, sizeof(ptr)) == -1){write($O,"munmap failed!\n",15);}
}
//!---------------------------------------------------------------------
void *malloc(size_t __size){
void *result=mmap(0, __size , PROT_READ|PROT_WRITE,MMAP_FLAGS, 0, 0);//+ sizeof(size_t)
if (result == MAP_FAILED){return NULL;}
* (size_t *) result = __size;
return(result + sizeof(__size));
}	
//!---------------------------------------------------------------------
void *libc_memcpy (void *dest, void *src, size_t n);
size_t libc_count(void** v);
//!---------------------------------------------------------------------
void *realloc(void *ptr, size_t __size)
{
        void *newptr = NULL;
 
        if (!ptr){return malloc(__size);}
        if (!__size) {
                free(ptr);
                return malloc(0);
        }
 
        newptr = malloc(__size);
        if (newptr) {
			#ifdef __x86_64__
                size_t old_size = *((size_t *) (ptr - sizeof(size_t)));
				 libc_memcpy(newptr, ptr, (old_size < __size ? old_size : __size));
           #endif
           #ifdef __i386__
           libc_memcpy(newptr, ptr, libc_count((void**)ptr)*sizeof(ptr));
           #endif
                free(ptr);
        }
        return newptr;
}

