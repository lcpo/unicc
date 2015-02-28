#ifndef NULL
#define NULL ((void*)0)
#endif

#ifndef EOF
#define EOF ((void*)-1)
#endif

	#ifdef __i386__
typedef  int uni;
typedef  unsigned int uni_t;
typedef  unsigned int size_t;

	#endif

	#ifdef __x86_64__
typedef  long uni;
typedef unsigned long uni_t;
typedef unsigned long size_t; 
	#endif


typedef struct stat_f{
  long st_dev;
  uni st_ino;
  unsigned short st_mode;
  unsigned short st_nlink;
  unsigned short st_uid;
  unsigned short st_gid;  
  long st_rdev;
  uni st_size;
  unsigned long st_blksize;
  unsigned long st_blocks;
  long st_atime;
  int st_mtime;
  long st_ctime;
  unsigned short st_omode;
}stat_f;

struct sockaddr
{
	unsigned short sa_family;
	char sa_data[14];
};
typedef union sigval {
	int sival_int;
	void *sival_ptr;
}sigval;

typedef struct siginfo_t{
	int si_signo;
	int si_code;
	sigval si_value;
	int si_errno;
	uni si_pid;
	uni si_uid;
	void *si_addr;
	int si_status;
	int si_band;
} siginfo_t;

typedef struct fd_set{
	unsigned long fds_bits[1024 / 8 / sizeof(long)];
} fd_set;

typedef struct timeval {
long tv_sec;     /* seconds */
long tv_usec;    /* microseconds */
           }timeval;

typedef struct iovec {
    void  *iov_base;            /* Starting address */
    size_t iov_len;             /* Number of bytes */
}iovec;           
