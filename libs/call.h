#define syscall sysrun
///------------------------------------------------------------
#define __syscall0(n) syscall(n)
#define __syscall1(n,a) syscall(n,(long)(a))
#define __syscall2(n,a,b) syscall(n,(long)(a),(long)(b))
#define __syscall3(n,a,b,c) syscall(n,(long)(a),(long)(b),(long)(c))
#define __syscall4(n,a,b,c,d) syscall(n,(long)(a),(long)(b),(long)(c),(long)(d))
#define __syscall5(n,a,b,c,d,e) syscall(n,(long)(a),(long)(b),(long)(c),(long)(d),(long)(e))
#define __syscall6(n,a,b,c,d,e,f) syscall(n,(long)(a),(long)(b),(long)(c),(long)(d),(long)(e),(long)(f))
#define __syscall7(n,a,b,c,d,e,f,g) syscall(n,(long)(a),(long)(b),(long)(c),(long)(d),(long)(e),(long)(f),(long)(g))
///------------------------------------------------------------
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
#define socketcall(nr, a, b, c, d, e, f) syscall(__NR_socketcall, __NR_UN_##nr, ((long [6]){ (long)a, (long)b, (long)c, (long)d, (long)e, (long)f }))
#endif

#ifdef __x86_64__
#define socketcall(nr,a,b,c,d,e,f) syscall(__NR_##nr,a,b,c,d,e,f)
#endif
