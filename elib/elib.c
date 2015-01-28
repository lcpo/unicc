
/*! ~ Системные функции, обращение на уровне ядра ~ !*/
///------------------------------------------------------------
//http://blog.rchapman.org/post/36801038863/linux-system-call-table-for-x86-64
//http://numactl.sourcearchive.com/documentation/0.9/syscall_8c-source.html!!!
///------------------------------------------------------------
char ccpy(char a){
char b=0;
switch(a){
case '!':b='!';break;case '"':b='"';break;case '#':b='#';break;case '$':b='$';break;
case '%':b='%';break;case '&':b='&';break;case '\'':b='\'';break;case '(':b='(';break;
case ')':b=')';break;case '*':b='*';break;case '+':b='+';break;case ',':b=',';break;
case '-':b='-';break;case '.':b='.';break;case '/':b='/';break;case '{':b='{';break;
case '|':b='|';break;case '}':b='}';break;case '~':b='~';break;case '[':b='[';break;
case '\\':b='\\';break;case ']':b=']';break;case '^':b='^';break;case '_':b='_';break;
case '`':b='`';break;case ':':b=':';break;case ';':b=';';break;case '<':b='<';break;
case '=':b='=';break;case '>':b='>';break;case '?':b='?';break;case '@':b='@';break;

case '0':b='0';break;case '1':b='1';break;case '2':b='2';break;case '3':b='3';break;
case '4':b='4';break;case '5':b='5';break;case '6':b='6';break;case '7':b='7';break;
case '8':b='8';break;case '9':b='9';break;

case 'A':b='A';break;case 'B':b='B';break;case 'C':b='C';break;
case 'D':b='D';break;case 'E':b='E';break;case 'F':b='F';break;
case 'G':b='G';break;case 'H':b='H';break;case 'I':b='I';break;
case 'J':b='J';break;case 'K':b='K';break;case 'L':b='L';break;
case 'M':b='M';break;case 'N':b='N';break;case 'O':b='O';break;
case 'P':b='P';break;case 'Q':b='Q';break;case 'R':b='R';break;
case 'S':b='S';break;case 'T':b='T';break;case 'U':b='U';break;
case 'V':b='V';break;case 'W':b='W';break;case 'X':b='X';break;
case 'Y':b='Y';break;case 'Z':b='Z';break;

case 'a':b='a';break;case 'b':b='b';break;case 'c':b='c';break;
case 'd':b='d';break;case 'e':b='e';break;case 'f':b='f';break;
case 'g':b='g';break;case 'h':b='h';break;case 'i':b='i';break;
case 'j':b='j';break;case 'k':b='k';break;case 'l':b='l';break;
case 'm':b='m';break;case 'n':b='n';break;case 'o':b='o';break;
case 'p':b='p';break;case 'q':b='q';break;case 'r':b='r';break;
case 's':b='s';break;case 't':b='t';break;case 'u':b='u';break;
case 'v':b='v';break;case 'w':b='w';break;case 'x':b='x';break;
case 'y':b='y';break;case 'z':b='z';break;

	}
	return b;	
	}
//!-------------------------------------------------------------	
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
asm("__syscall:\n" "movq %rdi,%rax\n" "movq %rsi,%rdi\n" "movq %rdx,%rsi\n"
"movq %rcx,%rdx\n" "movq %r8,%r10\n" "movq %r9,%r8\n" "movq 8(%rsp),%r9\n"
"syscall\n" "ret\n" );
#endif
///------------------------------------------------------------
long __syscall(long ns, long a, long b, long c, long d, long e, long f, long g);
///------------------------------------------------------------
long __sysrun(long ns, ...){
	va_list atr;
	long  a,b,c,d,e,f,g;
	va_start(atr, ns);
	a=va_arg(atr, long);
	b=va_arg(atr, long);
	c=va_arg(atr, long);
	d=va_arg(atr, long);
	e=va_arg(atr, long);
	f=va_arg(atr, long);
	g=va_arg(atr, long);
	va_end(atr);
	return (long)(__syscall(ns,a,b,c,d,e,f,g));
}
///------------------------------------------------------------
#define __syscall0(n) __sysrun(n)
#define __syscall1(n,a) __sysrun(n,(long)(a))
#define __syscall2(n,a,b) __sysrun(n,(long)(a),(long)(b))
#define __syscall3(n,a,b,c) __sysrun(n,(long)(a),(long)(b),(long)(c))
#define __syscall4(n,a,b,c,d) __sysrun(n,(long)(a),(long)(b),(long)(c),(long)(d))
#define __syscall5(n,a,b,c,d,e) __sysrun(n,(long)(a),(long)(b),(long)(c),(long)(d),(long)(e))
#define __syscall6(n,a,b,c,d,e,f) __sysrun(n,(long)(a),(long)(b),(long)(c),(long)(d),(long)(e),(long)(f))
#define __syscall7(n,a,b,c,d,e,f,g) __sysrun(n,(long)(a),(long)(b),(long)(c),(long)(d),(long)(e),(long)(f),(long)(g))
///------------------------------------------------------------
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
int close(uni fd) {return __syscall1(__NR_close,fd);}
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
	#ifdef __i386__
#define __NR_UN_socket      1
#define __NR_UN_bind        2
#define __NR_UN_connect     3
#define __NR_UN_listen      4
#define __NR_UN_accept      5
#define __NR_UN_getsockname 6
#define __NR_UN_getpeername 7
#define __NR_UN_socketpair  8
#define __NR_UN_send        9
#define __NR_UN_recv        10
#define __NR_UN_sendto      11
#define __NR_UN_recvfrom    12
#define __NR_UN_shutdown    13
#define __NR_UN_setsockopt  14
#define __NR_UN_getsockopt  15
#define __NR_UN_sendmsg     16
#define __NR_UN_recvmsg     17
#define socketcall(nr, a, b, c, d, e, f) __syscall2(__NR_socketcall, __NR_UN_##nr, ((long [6]){ (long)a, (long)b, (long)c, (long)d, (long)e, (long)f }))
#endif

	#ifdef __x86_64__
#define socketcall(nr,a,b,c,d,e,f) __syscall6(__NR_##nr,a,b,c,d,e,f)
	#endif

int socket(int domain, int type, int protocol){return socketcall(socket,domain, type, protocol, 0, 0, 0);}
int bind(int fd, const struct sockaddr *addr, socklen_t len){return socketcall(bind, fd, addr, len, 0, 0, 0);}
int accept(int fd, struct sockaddr *addr, socklen_t *len){int ret=-1;ret = socketcall(accept, fd, addr, len, 0, 0, 0);return ret;}
int connect(int fd, const struct sockaddr *addr, socklen_t len){int ret=-1;ret = socketcall(connect, fd, addr, len, 0, 0, 0);	return ret;}
int listen(int fd, int backlog){return socketcall(listen, fd, backlog, 0, 0, 0, 0);}
int getsockname(int fd, struct sockaddr *addr, socklen_t *len){	return socketcall(getsockname, fd, addr, len, 0, 0, 0);}
int setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen){return socketcall(setsockopt, fd, level, optname, optval, optlen, 0);}
int getsockopt(int fd, int level, int optname, void *optval, socklen_t *optlen){	return socketcall(getsockopt, fd, level, optname, optval, optlen, 0);}
int sendto(int fd, const void *buf, size_t len, int flags, const struct sockaddr *addr, socklen_t alen){int r=-1;r = socketcall(sendto, fd, buf, len, flags, addr, alen);return r;}
int send(int fd, const void *buf, size_t len, int flags){return sendto(fd, buf, len, flags, 0, 0);}

int recvfrom(int fd, void *buf, int len, int flags, struct sockaddr *addr, socklen_t *alen){
	int r=-1;
	r = socketcall(recvfrom, fd, buf, len, flags, addr, alen);
	return r;
}
int recv(int fd, void *buf, int len, int flags)
{
	return recvfrom(fd, buf, len, flags, 0, 0);
}

//select
//idtype_t

uni waitid(long type, long id, siginfo_t *info, int options)
{
	int r=-1;
	r = __syscall5(__NR_waitid, type, id, info, options, 0);
	return r;
}

uni waitpid(uni pid, int *status, int options)
{
	int r=-1;
	r = __syscall4(__NR_wait4, pid, status, options, 0);
	return r;
}

int select(int n, fd_set *rfds, fd_set *wfds, fd_set *efds, struct timeval *tv)
{
	int r=-1;
	r = __syscall5(__NR_select, n, rfds, wfds, efds, tv);
	return r;
}
int execve(const char* filename, char * const argv[], char *const envp[]){return __syscall3(__NR_execve,filename,argv,envp);}
size write(int fd, void* buf, size count) {return __syscall3(__NR_write,fd,buf,count);}
int mprotect(void* start, size_t len, long prot) {return __syscall3(__NR_mprotect,start,len,prot);}
uni munmap(void *addr, uni len) {return __syscall2(__NR_munmap,addr,len);}
void *mmap(void *start, size_t len, int prot, int flags, int fd, long int off){
#ifdef __NR_mmap2
	return (void *)__syscall6(__NR_mmap2, start, len, prot, flags, fd, off>>16);
#else
	return (void *)__syscall6(__NR_mmap, start, len, prot, flags, fd, off);
#endif
}
///------------------------------------------------------------
void *sbrk(long inc){return (void *)__syscall1(__NR_brk, __syscall1(__NR_brk, 0)+inc);}
///------------------------------------------------------------
void *mremap(void *old_addr, size_t old_len, size_t new_len, int flags, ...){
	va_list ap;
	void *new_addr;
	
	va_start(ap, flags);
	new_addr = va_arg(ap, void *);
	va_end(ap);

	return (void *)__syscall5(__NR_mremap, old_addr, old_len, new_len, flags, new_addr);
}
///------------------------------------------------------------
int madvise(void *addr, size_t len, int advice){return __syscall3(__NR_madvise, addr, len, advice);}
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
typedef struct mhope{
uni a[MAX_MEMORY_VAR];
uni z[MAX_MEMORY_VAR];
uni i;
	}mhope;

static mhope hope;
///------------------------------------------------------------
inline void init_malloc(void){hope.i=0;return;}
void init_malloc(void)	__attribute__ ((constructor));
///------------------------------------------------------------
void hope_sort(){
uni i=0,j=0,z=0,min=0,max=0,nom=hope.i+1;
uni a=0;	
    for(i = 0 ; i < nom ; i++) { 
       for(j = 0 ; j < nom - i - 1 ; j++) {  
           if(hope.a[j] < hope.a[j+1]) {           
              a = hope.a[j]; 
              hope.a[j] = hope.a[j+1] ; 
              hope.a[j+1] = a; 
              
              z = hope.z[j]; 
              hope.z[j] = hope.z[j+1] ; 
              hope.z[j+1] = z;
           }
        }
    }
if(hope.i>0){hope.i--;}    	
	}
///------------------------------------------------------------
uni getptrid(void *ptr){
uni i=0,z=0,n=-1;
while(i<hope.i){
if(((uni)ptr)==hope.a[i]){z=hope.z[i];n=i;break;}	
	i++;
	}
return n;		
	}
///------------------------------------------------------------
void dropptr(void* ptr){
uni id=getptrid(ptr);
hope.a[id]=-1; 
hope.z[id]=-1;
hope_sort();
	}
///------------------------------------------------------------	
size_t libc_strlen(char* str);
size_t libc_count(void** v);


void free_ptr(void* ptr){
if (ptr == NULL){return;}
uni id=getptrid(ptr);
if(id==-1){return;}
if(hope.z[id]>0){
if(munmap(ptr, hope.z[id]) == -1){write($O,"munmap failed!\n",15);}	
dropptr(ptr);
}
return;		 
	}

void free(void* ptr){
if (ptr == NULL){return;}
int id=getptrid(ptr),pco=libc_strlen((char*)ptr),sco=libc_count((void**)ptr);
if(id==-1){return;}
if(sco>0 && pco==0){
	void** bf=ptr;
	while(sco>0){sco--;if(libc_count((void**)bf[sco])>0){free(bf[sco]);}else{free_ptr(bf[sco]);}}
					}
free_ptr(ptr);

return;	
	}




	
	
	






//!---------------------------------------------------------------------
	
void *malloc(size_t __size){
if(__size<=0){__size=1;}
void *result=mmap(0, __size*sizeof(result) , PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);//+ sizeof(size_t)
if (result == MAP_FAILED){write($O,"mmap failed!\n",13);return NULL;}
hope.a[hope.i]=(uni)result;
hope.z[hope.i]=__size*sizeof(result);
hope.i++;

return result;
}	
//!---------------------------------------------------------------------
void *libc_memcpy (void *dest, void *src, size_t n);

//!---------------------------------------------------------------------
void *realloc(void *ptr, size_t __size){
uni i=0,z=0,id=getptrid(ptr);
        if (!ptr){return malloc(__size);}
        if (!__size) {free(ptr);return malloc(1);}
          void *newptr = malloc(__size);
        if (newptr) {
				 libc_memcpy(newptr, ptr, hope.z[id]);
                free(ptr);
        }else{write($O,"mmap failed!\n",13);return NULL;}
        return newptr;
}

#define calloc(m,n) malloc((m)+(n))
