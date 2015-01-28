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
   #define MAX_MEMORY_VAR   1024
   

///END MAP

#ifdef __i386__
#include "unistd_x86.h"
#else
#include "unistd_x64.h"
#endif
#ifndef _STDINT_H
#include "stdint.h"
#endif
typedef unsigned int socklen_t;
typedef unsigned short sa_family_t;
typedef unsigned short in_port_t;
typedef unsigned int in_addr_t;
//sys/socket.h
struct sockaddr
{
	sa_family_t sa_family;
	char sa_data[14];
};

struct sockaddr_storage
{
	sa_family_t ss_family;
	long long __ss_align;
	char __ss_padding[128 - sizeof(sa_family_t) - sizeof(long long)];
};

struct in_addr {
    unsigned long s_addr;  // load with inet_aton()
};

struct sockaddr_in {
    short            sin_family;   // e.g. AF_INET
    unsigned short   sin_port;     // e.g. htons(3490)
    struct in_addr   sin_addr;     // see struct in_addr, below
    long             sin_zero[8];  // zero this if you want to
};



#define HTONS(n) (((((unsigned short)(n) & 0xFF)) << 8) | (((unsigned short)(n) & 0xFF00) >> 8))
#define NTOHS(n) (((((unsigned short)(n) & 0xFF)) << 8) | (((unsigned short)(n) & 0xFF00) >> 8))

#define HTONL(n) (((((unsigned long)(n) & 0xFF)) << 24) | \
                  ((((unsigned long)(n) & 0xFF00)) << 8) | \
                  ((((unsigned long)(n) & 0xFF0000)) >> 8) | \
                  ((((unsigned long)(n) & 0xFF000000)) >> 24))

#define NTOHL(n) (((((unsigned long)(n) & 0xFF)) << 24) | \
                  ((((unsigned long)(n) & 0xFF00)) << 8) | \
                  ((((unsigned long)(n) & 0xFF0000)) >> 8) | \
                  ((((unsigned long)(n) & 0xFF000000)) >> 24))
                  
unsigned short htons(unsigned short n);
unsigned short ntohs(unsigned short n);
unsigned long htonl(unsigned long n);
unsigned long ntohl(unsigned long n);

#define htons(n) HTONS(n)
#define ntohs(n) NTOHS(n)

#define htonl(n) HTONL(n)
#define ntohl(n) NTOHL(n)


#define	SOCK_STREAM	1		/* stream socket */
#define	SOCK_DGRAM	2		/* datagram socket */
#define	SOCK_RAW	3		/* raw-protocol interface */
#define	SOCK_RDM	4		/* reliably-delivered message */
#define	SOCK_SEQPACKET	5		/* sequenced packet stream */

#define	SOL_SOCKET	0xffff		/* options for socket level */

#define	SO_DEBUG	    0x0001		/* turn on debugging info recording */
#define	SO_ACCEPTCONN	0x0002		/* socket has had listen() */
#define	SO_REUSEADDR	0x0004		/* allow local address reuse */
#define	SO_KEEPALIVE	0x0008		/* keep connections alive */
#define	SO_DONTROUTE	0x0010		/* just use interface addresses */
#define	SO_BROADCAST	0x0020		/* permit sending of broadcast msgs */
#define	SO_USELOOPBACK	0x0040		/* bypass hardware when possible */
#define	SO_LINGER	    0x0080		/* linger on close if data present */
#define	SO_OOBINLINE	0x0100		/* leave received OOB data in line */

#define SO_SNDBUF	0x1001		/* send buffer size */
#define SO_RCVBUF	0x1002		/* receive buffer size */
#define SO_SNDLOWAT	0x1003		/* send low-water mark */
#define SO_RCVLOWAT	0x1004		/* receive low-water mark */
#define SO_SNDTIMEO	0x1005		/* send timeout */
#define SO_RCVTIMEO	0x1006		/* receive timeout */
#define	SO_ERROR	0x1007		/* get error status and clear */
#define	SO_TYPE		0x1008		/* get socket type */

#define INADDR_ANY	((unsigned long int) 0x00000000)
#define INADDR_LOOPBACK	((unsigned long int) 0x7f000001)
#define INADDR_NONE	0xffffffff
#define INPORT_ANY	0

#define	AF_UNSPEC	0		/* unspecified */
#define	AF_UNIX		1		/* local to host (pipes, portals) */
#define	AF_INET		2		/* internetwork: UDP, TCP, etc. */
#define	AF_IMPLINK	3		/* arpanet imp addresses */
#define	AF_PUP		4		/* pup protocols: e.g. BSP */
#define	AF_CHAOS	5		/* mit CHAOS protocols */
#define	AF_NS		6		/* XEROX NS protocols */
#define	AF_ISO		7		/* ISO protocols */
#define	AF_OSI		AF_ISO
#define	AF_ECMA		8		/* european computer manufacturers */
#define	AF_DATAKIT	9		/* datakit protocols */
#define	AF_CCITT	10		/* CCITT protocols, X.25 etc */
#define	AF_SNA		11		/* IBM SNA */
#define AF_DECnet	12		/* DECnet */
#define AF_DLI		13		/* DEC Direct data link interface */
#define AF_LAT		14		/* LAT */
#define	AF_HYLINK	15		/* NSC Hyperchannel */
#define	AF_APPLETALK	16		/* Apple Talk */
#define	AF_ROUTE	17		/* Internal Routing Protocol */
#define	AF_LINK		18		/* Link layer interface */
#define	pseudo_AF_XTP	19		/* eXpress Transfer Protocol (no AF) */
//from waitpid
#define WNOHANG		1	/* dont hang in wait */
#define WUNTRACED	2	/* tell about stopped, untraced children */
#define	WAIT_ANY	(-1)	/* any process */
#define	WAIT_MYPGRP	0	/* any process in my process group */
union sigval {
	int sival_int;
	void *sival_ptr;
};

typedef struct {
	int si_signo;
	int si_code;
	union sigval si_value;
	int si_errno;
	uni si_pid;
	uni si_uid;
	void *si_addr;
	int si_status;
	int si_band;
} siginfo_t;

struct timeval {
long      tv_sec;     /* seconds */
long tv_usec;    /* microseconds */
           };

#define FD_SETSIZE 1024

typedef struct
{
	unsigned long fds_bits[FD_SETSIZE / 8 / sizeof(long)];
} fd_set;

#define FD_ZERO(s) do { int __i; unsigned long *__b=(s)->fds_bits; for(__i=sizeof (fd_set)/sizeof (long); __i; __i--) *__b++=0; } while(0)
#define FD_SET(d, s)   ((s)->fds_bits[(d)/(8*sizeof(long))] |= (1<<((d)%(8*sizeof(long)))))
#define FD_CLR(d, s)   ((s)->fds_bits[(d)/(8*sizeof(long))] &= ~(1<<((d)%(8*sizeof(long)))))
#define FD_ISSET(d, s) ((s)->fds_bits[(d)/(8*sizeof(long))] & (1<<((d)%(8*sizeof(long)))))

//errorno.h
#define EPERM            1      /* Operation not permitted */
#define ENOENT           2      /* No such file or directory */
#define ESRCH            3      /* No such process */
#define EINTR            4      /* Interrupted system call */
#define EIO              5      /* I/O error */
#define ENXIO            6      /* No such device or address */
#define E2BIG            7      /* Arg list too long */
#define ENOEXEC          8      /* Exec format error */
#define EBADF            9      /* Bad file number */
#define ECHILD          10      /* No child processes */
#define EAGAIN          11      /* Try again */
#define ENOMEM          12      /* Out of memory */
#define EACCES          13      /* Permission denied */
#define EFAULT          14      /* Bad address */
#define ENOTBLK         15      /* Block device required */
#define EBUSY           16      /* Device or resource busy */
#define EEXIST          17      /* File exists */
#define EXDEV           18      /* Cross-device link */
#define ENODEV          19      /* No such device */
#define ENOTDIR         20      /* Not a directory */
#define EISDIR          21      /* Is a directory */
#define EINVAL          22      /* Invalid argument */
#define ENFILE          23      /* File table overflow */
#define EMFILE          24      /* Too many open files */
#define ENOTTY          25      /* Not a typewriter */
#define ETXTBSY         26      /* Text file busy */
#define EFBIG           27      /* File too large */
#define ENOSPC          28      /* No space left on device */
#define ESPIPE          29      /* Illegal seek */
#define EROFS           30      /* Read-only file system */
#define EMLINK          31      /* Too many links */
#define EPIPE           32      /* Broken pipe */
#define EDOM            33      /* Math argument out of domain of func */
#define ERANGE          34      /* Math result not representable */
#define EDEADLK         35      /* Resource deadlock would occur */
#define ENAMETOOLONG    36      /* File name too long */
#define ENOLCK          37      /* No record locks available */
#define ENOSYS          38      /* Function not implemented */
#define ENOTEMPTY       39      /* Directory not empty */
#define ELOOP           40      /* Too many symbolic links encountered */
#define EWOULDBLOCK     EAGAIN  /* Operation would block */
#define ENOMSG          42      /* No message of desired type */
#define EIDRM           43      /* Identifier removed */
#define ECHRNG          44      /* Channel number out of range */
#define EL2NSYNC        45      /* Level 2 not synchronized */
#define EL3HLT          46      /* Level 3 halted */
#define EL3RST          47      /* Level 3 reset */
#define ELNRNG          48      /* Link number out of range */
#define EUNATCH         49      /* Protocol driver not attached */
#define ENOCSI          50      /* No CSI structure available */
#define EL2HLT          51      /* Level 2 halted */
#define EBADE           52      /* Invalid exchange */
#define EBADR           53      /* Invalid request descriptor */
#define EXFULL          54      /* Exchange full */
#define ENOANO          55      /* No anode */
#define EBADRQC         56      /* Invalid request code */
#define EBADSLT         57      /* Invalid slot */

#define EDEADLOCK       EDEADLK

#define EBFONT          59      /* Bad font file format */
#define ENOSTR          60      /* Device not a stream */
#define ENODATA         61      /* No data available */
#define ETIME           62      /* Timer expired */
#define ENOSR           63      /* Out of streams resources */
#define ENONET          64      /* Machine is not on the network */
#define ENOPKG          65      /* Package not installed */
#define EREMOTE         66      /* Object is remote */
#define ENOLINK         67      /* Link has been severed */
#define EADV            68      /* Advertise error */
#define ESRMNT          69      /* Srmount error */
#define ECOMM           70      /* Communication error on send */
#define EPROTO          71      /* Protocol error */
#define EMULTIHOP       72      /* Multihop attempted */
#define EDOTDOT         73      /* RFS specific error */
#define EBADMSG         74      /* Not a data message */
#define EOVERFLOW       75      /* Value too large for defined data type */
#define ENOTUNIQ        76      /* Name not unique on network */
#define EBADFD          77      /* File descriptor in bad state */
#define EREMCHG         78      /* Remote address changed */
#define ELIBACC         79      /* Can not access a needed shared library */
#define ELIBBAD         80      /* Accessing a corrupted shared library */
#define ELIBSCN         81      /* .lib section in a.out corrupted */
#define ELIBMAX         82      /* Attempting to link in too many shared libraries */
#define ELIBEXEC        83      /* Cannot exec a shared library directly */
#define EILSEQ          84      /* Illegal byte sequence */
#define ERESTART        85      /* Interrupted system call should be restarted */
#define ESTRPIPE        86      /* Streams pipe error */
#define EUSERS          87      /* Too many users */
#define ENOTSOCK        88      /* Socket operation on non-socket */
#define EDESTADDRREQ    89      /* Destination address required */
#define EMSGSIZE        90      /* Message too long */
#define EPROTOTYPE      91      /* Protocol wrong type for socket */
#define ENOPROTOOPT     92      /* Protocol not available */
#define EPROTONOSUPPORT 93      /* Protocol not supported */
#define ESOCKTNOSUPPORT 94      /* Socket type not supported */
#define EOPNOTSUPP      95      /* Operation not supported on transport endpoint */
#define EPFNOSUPPORT    96      /* Protocol family not supported */
#define EAFNOSUPPORT    97      /* Address family not supported by protocol */
#define EADDRINUSE      98      /* Address already in use */
#define EADDRNOTAVAIL   99      /* Cannot assign requested address */
#define ENETDOWN        100     /* Network is down */
#define ENETUNREACH     101     /* Network is unreachable */
#define ENETRESET       102     /* Network dropped connection because of reset */
#define ECONNABORTED    103     /* Software caused connection abort */
#define ECONNRESET      104     /* Connection reset by peer */
#define ENOBUFS         105     /* No buffer space available */
#define EISCONN         106     /* Transport endpoint is already connected */
#define ENOTCONN        107     /* Transport endpoint is not connected */
#define ESHUTDOWN       108     /* Cannot send after transport endpoint shutdown */
#define ETOOMANYREFS    109     /* Too many references: cannot splice */
#define ETIMEDOUT       110     /* Connection timed out */
#define ECONNREFUSED    111     /* Connection refused */
#define EHOSTDOWN       112     /* Host is down */
#define EHOSTUNREACH    113     /* No route to host */
#define EALREADY        114     /* Operation already in progress */
#define EINPROGRESS     115     /* Operation now in progress */
#define ESTALE          116     /* Stale NFS file handle */
#define EUCLEAN         117     /* Structure needs cleaning */
#define ENOTNAM         118     /* Not a XENIX named type file */
#define ENAVAIL         119     /* No XENIX semaphores available */
#define EISNAM          120     /* Is a named type file */
#define EREMOTEIO       121     /* Remote I/O error */
#define EDQUOT          122     /* Quota exceeded */

#define ENOMEDIUM       123     /* No medium found */
#define EMEDIUMTYPE     124     /* Wrong medium type */
