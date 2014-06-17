/*! ~ Системные функции, обращение на уровне ядра ~ !*/
//----------------------------------------------------------------------


uint64_t  __udivmoddi4(uint64_t num, uint64_t den, uint64_t * rem_p)
 {
  uint64_t quot = 0, qbit = 1;
 
   if ( den == 0 ) {
     return 1/((unsigned)den); 
   }
 

   while ( (int64_t)den >= 0 ) {
    den <<= 1;
     qbit <<= 1;
   }
 
  while ( qbit ) {
    if ( den <= num ) {
       num -= den;
       quot += qbit;
     }
     den >>= 1;
     qbit >>= 1;
   }

   if ( rem_p ){
     *rem_p = num;
		}

   return quot;
 }
uint64_t __udivdi3(uint64_t num, uint64_t den){
   return __udivmoddi4(num, den, NULL);
 }
//----------------------------------------------------------------------

uint64_t __umoddi3(uint64_t num, uint64_t den)
 {
   uint64_t v;
    (void) __udivmoddi4(num, den, &v);
   return v;
 } 
//----------------------------------------------------------------------
int64_t __moddi3(int64_t num, int64_t den){
   int minus = 0;
   int64_t v;

   if ( num < 0 ) {
    num = -num;
     minus = 1;
   }
  if ( den < 0 ) {
     den = -den;
     minus ^= 1;
   }
 
   (void) __udivmoddi4(num, den, (uint64_t *)&v);
   if ( minus ){ v = -v;}
 
   return v;
 } 
//----------------------------------------------------------------------
int64_t __divdi3(int64_t num, int64_t den)
 {
  int minus = 0;
   int64_t v;
 
   if ( num < 0 ) {
     num = -num;
     minus = 1;
   }
   if ( den < 0 ) {
     den = -den;
     minus ^= 1;
   }
 
   v = __udivmoddi4(num, den, NULL);
   if ( minus ){
     v = -v;
     }
 
   return v;
}
//----------------------------------------------------------------------
#ifdef __i386__
int open(const char * filename, int flags, int mode) {
       int ret;
        asm volatile(SYS_CALL
            : "=a" (ret)
            : "a" (__NR_open), "b" (filename), "c" (flags), "d" (mode)
        );
        return ret;
}
#endif
//----------------------------------------------------------------------
#ifdef __x86_64__
int open(char * filename, int flags, int mode) {
       int ret;
        asm volatile(
        "movl $2, %%eax\n\t"
        "movq %1, %%rdi\n\t"
        "movq %2, %%rsi\n\t"
        "movq %3, %%rdx\n\t"
        SYS_CALL
        : "=a"(ret)
        : "g"(filename), "g"(flags),"g"(mode)
      // : "%rdi", "%rsi", "%rdx", "%rcx", "%r11"
        );
        
        return ret;
}
#endif

//----------------------------------------------------------------------
#ifdef __i386__
void close(uni fd) {
        asm volatile(SYS_CALL
            : 
            : "a" (__NR_close), "b" (fd)
        );
}
#endif
//----------------------------------------------------------------------
#ifdef __x86_64__
void close(uni fd) {
	//__NR_close x64 =3
	int ret;
        asm volatile(
        "movl $3, %%eax\n\t"
        "movq %1, %%rdi\n\t"
        SYS_CALL
        : "=a"(ret)
        : "g"(fd)
        );
}
#endif
//----------------------------------------------------------------------
#ifdef __x86_64__
int __exit(int error_code){
	int ret;
        asm volatile(
        "movl $60, %%eax\n\t"
        "movq %1, %%rdi\n\t"
        SYS_CALL
        : "=a"(ret)
        : "g"(error_code)
        );
        return ret;
}
int __exit(int error_code) __attribute__ ((destructor));
#endif
//----------------------------------------------------------------------
#ifdef __i386__
int __exit(int error_code){
	int ret;
asm volatile(SYS_CALL
:"=a"(ret)
: "a" (__NR_exit), "b" (error_code)
);
return ret;
						 }
int __exit(int error_code) __attribute__ ((destructor));
#endif
#define exit __exit
//---------------------------------------------------------------------- 
#ifdef __i386__
int read(int fd, char * buf, uni count){
        int ret;
        // __NR_read x64=0
        asm volatile(SYS_CALL
            : "=a" (ret)
            : "a" (__NR_read), "b" (fd), "c" (buf), "d" (count)
        );
        return ret;
}
#endif
//----------------------------------------------------------------------
#ifdef __x86_64__
int read(int fd, char* buf, size count) {
        int ret;
        // __NR_read x64=0
        asm volatile(
        "movl $0, %%eax\n\t"
        "movq %1, %%rdi\n\t"
        "movq %2, %%rsi\n\t"
        "movq %3, %%rdx\n\t"
        SYS_CALL
        : "=a"(ret)
        : "g"(fd), "g"(buf),"g"(count)
        );
        return ret;
}
#endif
//----------------------------------------------------------------------
#ifdef __i386__
size write(int fd, void* buf, size count) {
       size ret; 
        asm volatile(SYS_CALL
            : "=a" (ret)
            : "a" (__NR_write), "b" (fd), "c" (buf), "d" (count)
        );
        return ret;
}
#endif
//----------------------------------------------------------------------
#ifdef __x86_64__
size write(int fd, void* buf, size count) {
       size ret; 
		asm volatile(
        "movl $1, %%eax\n\t"
        "movq %1, %%rdi\n\t"
        "movq %2, %%rsi\n\t"
        "movq %3, %%rdx\n\t"
        SYS_CALL
        : "=a"(ret)
        : "g"(fd),"g"(buf), "g"(count)
        //   : "%rdi", "%rsi", "%rdx", "%rcx", "%r11"
        );
        return ret;
}
#endif

//----------------------------------------------------------------------

extern size strlen(char* str);
uni print(char * buf){
return write(0, (void*)buf, strlen(buf));
}


 

//----------------------------------------------------------------------
#ifdef __i386__
uni munmap(void *__addr, uni __len) {
        int ret;
        asm volatile(SYS_CALL:"=a"(ret):"a" (__NR_munmap), "b" (__addr), "c" (__len));
        return ret;
}
#endif
#ifdef __x86_64__
uni munmap(void *__addr, uni __len) {
        int ret;
        asm volatile(SYS_CALL
        "movl $11, %%eax\n\t"
        "movq %1, %%rdi\n\t"
        "movq %2, %%rsi\n\t"
        :"=a"(ret)
        : "g" (__addr), "g" (__len));
        return ret;
}
#endif
//----------------------------------------------------------------------

///http://numactl.sourcearchive.com/documentation/0.9/syscall_8c-source.html!!!

#ifdef __x86_64__
long __syscall6(long call, long a, long b, long c, long d, long e, long f){
long res;
asm("movq %0, %%r9; "  : : "g" (f) 		: "%r9");
asm("movq %0, %%r8; "  : : "g" (e) 		: "%r8");
asm("movq %0, %%r10; " : : "g" (d) 		: "%r10");
asm("movq %0, %%rdx; " : : "g" (c) 		: "%rdx");
asm("movq %0, %%rsi; " : : "g" (b) 		: "%rsi");
asm("movq %0, %%rdi; " : : "g" (a) 		: "%rdi");
asm("movq %0, %%rax; " : : "g" (call) 	: "%rax");
asm("syscall;" : : : "%rax", "%r11", "%rcx");
asm volatile("movq %%rax, %0; " : "=g" (res) );
return res;
																		}
#endif 
#ifdef __i386__
asm(
"__syscall6:\n"
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
"ret"
);

extern long __syscall6(long n, long a, long b, long c, long d, long e, long f);
#endif


void*  mmap(void* addr, size len, int prot, int flags, int fd, unsigned long offset){return (void*)__syscall6(__NR_mmap,(long)&addr,len,prot,flags,fd,offset);}


//----------------------------------------------------------------------
void *malloc(size __size){
void *result;
result = mmap(NULL, __size+sizeof(void*) * sizeof(void*) , PROT_READ | PROT_WRITE,MMAP_FLAGS, 0, 0);//+ sizeof(size_t)
if (result == MAP_FAILED){return NULL;}
* (size *) result = __size;
return(result + sizeof(void*));
}
//----------------------------------------------------------------------
extern void *memcpy (void *dest, void *src, size n);
extern void *malloc(size __size);
extern uni count(void** Arrs);
extern void free(void* ptr);

void *realloc(void *ptr, size __size)
{
        void *newptr = NULL;
 
        if (!ptr)
                return malloc(__size);
        if (!__size) {
                free(ptr);
                return malloc(0);
        }
 
        newptr = malloc(__size);
        if (newptr) {
                size old_size = *((size *) (ptr - sizeof(size)));
				 memcpy(newptr, ptr, count(ptr)*sizeof(ptr));//(old_size < size ? old_size : size));
                free(ptr);
        }
        return newptr;
}
//----------------------------------------------------------------------
void free(void *ptr){

if (ptr == NULL){return;}
ptr -= sizeof(size);
munmap(ptr, * (size *) ptr + sizeof(size));
}
