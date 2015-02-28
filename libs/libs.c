#include "libs.h"
#include "call.c"
#include "arg.c"
#define MARK(obj,name,arr,i)(obj.name=arr[i])


typedef struct sys_t{
void (*undefined)(void);	
int (*open)(char * filename, int flags, int mode);
int (*close)(int fd);
int (*stat)(char * filename, struct stat_f *buf);
int (*fstat)(int fd, stat_f *buf);
int (*lstat)(char * filename, struct stat_f *buf);
int (*brk)(void* brkv);
int (*exit)(int error_code);
int (*getpid)(void);
int (*fork)(void);
int (*vfork)(void);
int (*read)(int fd, char * buf, int count);
int (*lseek)(int fd, int offset, int against);
int (*kill)(int pid, int sig);
int (*dup2)(int oldfd, uni newfd);
int (*dup)(int oldfd);
int (*alarm)(int seconds);
int (*pipe)(int* filedes);
long (*time)(long tloc);
int (*unlink)(char* filename);
int (*nanosleep)(int rqtp, int rmtp);
int (*readlink)(char* path, char * buf, int bufsize);
int (*ioctl)(unsigned int fd, unsigned int cmd, void* arg);
int (*socket)(int domain, int type, int protocol);
int (*bind)(int fd, const struct sockaddr *addr, unsigned int len);
int (*accept)(int fd, struct sockaddr *addr, unsigned int *len);
int (*connect)(int fd, const struct sockaddr *addr, unsigned int len);
int (*listen)(int fd, int backlog);
int (*getsockname)(int fd, struct sockaddr *addr, unsigned int *len);
int (*setsockopt)(int fd, int level, int optname, void *optval, unsigned int optlen);
int (*getsockopt)(int fd, int level, int optname, void *optval, unsigned int *optlen);
int (*sendto)(int fd, const void *buf, size_t len, int flags, const struct sockaddr *addr, unsigned int alen);
int (*send)(int fd, const void *buf, size_t len, int flags);
int (*recvfrom)(int fd, void *buf, int len, int flags, struct sockaddr *addr, unsigned int *alen);
int (*recv)(int fd, void *buf, int len, int flags);
long (*vmsplice)(int fd, iovec *iov, unsigned long nr_segs, unsigned int flags);
long (*tee)(int fd_in, int fd_out, size_t len, unsigned int flags);
long (*splice)(int fd_in, long *off_in, int fd_out,long *off_out, size_t len, unsigned int flags);
int (*sendfile)(int out_fd, int in_fd, long *offset, size_t count);
int (*waitpid)(int pid, int *status, int options);
int (*waitid)(long type, long id, siginfo_t *info, int options);
int (*wait2)(int pid,void *status);
int (*wait)(void *status);
int (*clone)(int (*fn)(void *), void *child_stack, long flags, void *arg);
int (*select)(int n, fd_set *rfds, fd_set *wfds, fd_set *efds, timeval *tv);
int (*fcntl)(int fd, int cmd, ...);
int (*execve)(const char* filename, char * const argv[], char *const envp[]);
int (*write)(int fd, void* buf, size_t count);
int (*mprotect)(void* start, size_t len, long prot);
int (*munmap)(void *addr, size_t len);
void *(*mmap)(void *start, size_t len, int prot, int flags, int fd, long int off);
void *(*sbrk)(long inc);
void *(*mremap)(void *old_addr, size_t old_len, size_t new_len, int flags, ...);
int (*madvise)(void *addr, size_t len, int advice);
}sys_t;

uni* __libs_constructor(){
void undefined(){return;}	
//!------------------------------------------------------------
#ifndef __NO_LIBS_OPEN
int open(char * filename, int flags, int mode) {return syscall(__NR_open,filename,flags,mode);}
#else
#define open undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_CLOSE
int close(int fd) {return syscall(__NR_close,fd);}
#else
#define close undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_STAT
int stat(char * filename, struct stat_f *buf) {return syscall(__NR_stat,filename,buf);}
#else
#define stat undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_FSTAT
int fstat(int fd, stat_f *buf) {return syscall(__NR_fstat,fd,buf);}
#else
#define fstat undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_LSTAT
int lstat(char * filename, struct stat_f *buf) {return syscall(__NR_lstat,filename,buf);}
#else
#define lstat undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_BRK
int brk(void* brkv) {return syscall(__NR_brk,brkv);}
#else
#define brk undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_EXIT
int exit(int error_code){return syscall(__NR_exit,error_code); }
#else
#define exit undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_GETPID
int getpid(void){return syscall(__NR_getpid);}
#else
#define getpid undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_FORK
int fork(void){return syscall(__NR_fork);}
#else
#define fork undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_VFORK
int vfork(void){return syscall(__NR_vfork);}
#else
#define vfork undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_READ
int read(int fd, char * buf, int count) {return syscall(__NR_read,fd,buf,count);}
#else
#define read undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_LSEEK
int lseek (int fd, int offset, int against){return syscall(__NR_lseek,fd,offset,against);}
#else
#define lseek undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_KILL
int kill(int pid, int sig){return syscall(__NR_kill,pid,sig);}
#else
#define kill undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_DUP2
int dup2(int oldfd, uni newfd){return syscall(__NR_dup2,oldfd,newfd);}
#else
#define dup2 undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_DUP
int dup(int oldfd){return syscall(__NR_dup,oldfd);}
#else
#define dup undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_ALARM
int alarm(int seconds){return syscall(__NR_alarm,seconds);}
#else
#define alarm undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_PIPE
int pipe(int* filedes){return syscall(__NR_pipe,filedes);}
#else
#define pipe undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_TIME
long time(long tloc){return syscall(__NR_time,tloc);}
#else
#define time undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_UNLINK
int unlink(char* filename){return syscall(__NR_unlink,filename);}
#else
#define unlink undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_NANOSLEEP
int nanosleep(int rqtp, int rmtp){return syscall(__NR_nanosleep,rqtp,rmtp);}
#else
#define nanosleep undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_READLINK
int readlink(char* path, char * buf, int bufsize){return syscall(__NR_readlink,path,buf,bufsize);}
#else
#define readlink undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_IOCTL
int ioctl(unsigned int fd, unsigned int cmd, void* arg){return syscall(__NR_ioctl,fd,cmd,arg);}
#else
#define ioctl undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_SOCKET
int socket(int domain, int type, int protocol){return socketcall(socket,domain, type, protocol, 0, 0, 0);}
#else
#define socket undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_BIND
int bind(int fd, const struct sockaddr *addr, unsigned int len){return socketcall(bind, fd, addr, len, 0, 0, 0);}
#else
#define bind undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_ACCEPT
int accept(int fd, struct sockaddr *addr, unsigned int *len){int ret=-1;ret = socketcall(accept, fd, addr, len, 0, 0, 0);return ret;}
#else
#define accept undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_CONNECT
int connect(int fd, const struct sockaddr *addr, unsigned int len){int ret=-1;ret = socketcall(connect, fd, addr, len, 0, 0, 0);	return ret;}
#else
#define connect undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_LISTEN
int listen(int fd, int backlog){return socketcall(listen, fd, backlog, 0, 0, 0, 0);}
#else
#define listen undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_GETSOCKNAME
int getsockname(int fd, struct sockaddr *addr, unsigned int *len){	return socketcall(getsockname, fd, addr, len, 0, 0, 0);}
#else
#define getsockname undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_SETSOCKOPT
int setsockopt(int fd, int level, int optname, void *optval, unsigned int optlen){return socketcall(setsockopt, fd, level, optname, optval, optlen, 0);}
#else
#define setsockopt undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_GETSOCKOPT
int getsockopt(int fd, int level, int optname, void *optval, unsigned int *optlen){return socketcall(getsockopt, fd, level, optname, optval, optlen, 0);}
#else
#define getsockopt undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_SENDTO
int sendto(int fd, const void *buf, size_t len, int flags, const struct sockaddr *addr, unsigned int alen){return socketcall(sendto, fd, buf, len, flags, addr, alen);}
#else
#define sendto undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_SEND
int send(int fd, const void *buf, size_t len, int flags){return sendto(fd, buf, len, flags, 0, 0);}
#else
#define send undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_RECVFROM
int recvfrom(int fd, void *buf, int len, int flags, struct sockaddr *addr, unsigned int *alen){return socketcall(recvfrom, fd, buf, len, flags, addr, alen);}
#else
#define recvfrom undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_RECV
int recv(int fd, void *buf, int len, int flags){return recvfrom(fd, buf, len, flags, 0, 0);}
#else
#define recv undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_VMSPLICE
long vmsplice(int fd, iovec *iov, unsigned long nr_segs, unsigned int flags){
	//vmsplice - splice user pages into a pipe
	long r=-1;
	r = syscall(__NR_vmsplice, fd, iov, nr_segs, flags);
	return r;
	}
#else
#define vmsplice undefined
#endif
//!------------------------------------------------------------	
#ifndef __NO_LIBS_TEE
long tee(int fd_in, int fd_out, size_t len, unsigned int flags){	
//tee - duplicating pipe content
int r=-1;
	r = syscall(__NR_tee,fd_in,fd_out,len,flags);
	return r;
}
#else
#define tee undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_SPLICE
long splice(int fd_in, long *off_in, int fd_out,long *off_out, size_t len, unsigned int flags){ 
	//splice data to/from a pipe
	return syscall(__NR_splice, fd_in, off_in, fd_out, off_out, len, flags);	
	}
#else
#define splice undefined
#endif	
//!------------------------------------------------------------
#ifndef __NO_LIBS_SENDFILE
int sendfile(int out_fd, int in_fd, long *offset, size_t count){ //file to socket
//sendfile - производит обмен данными между описателями файлов  
int r=-1;
	r = syscall(__NR_sendfile,out_fd,in_fd,offset,count);
	return r;
}
#else
#define sendfile undefined
#endif	
//!------------------------------------------------------------
#ifndef __NO_LIBS_WAITPID
int waitpid(int pid, int *status, int options){
	int r=-1;
	r = syscall(__NR_wait4, pid, status, options, 0);
	return r;
}
#else
#define waitpid undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_WAITID
int waitid(long type, long id, siginfo_t *info, int options){int r = syscall(__NR_waitid, type, id, info, options, 0);return r;}
#else
#define waitid undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_WAIT2
int wait2(int pid,void *status){return waitpid(pid, status, 0);}
#else
#define wait2 undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_WAIT
int wait(void *status){return waitpid((int)-1, status, 0);}
#else
#define wait undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_CLONE
int clone(int (*fn)(void *), void *child_stack, long flags, void *arg){
	int r=-1;
	r = syscall(__NR_clone,flags,child_stack);
	fn(arg);
	return r;
	}
#else
#define clone undefined
#endif	
//!------------------------------------------------------------	
#ifndef __NO_LIBS_SELECT
int select(int n, fd_set *rfds, fd_set *wfds, fd_set *efds, timeval *tv){
	int r=-1;
	#ifdef __NR__newselect
	r = syscall(__NR__newselect, n, rfds, wfds, efds, tv);
	#else
	r = syscall(__NR_select, n, rfds, wfds, efds, tv);
	#endif
	return r;
}
#else
#define select undefined
#endif
//!------------------------------------------------------------
#ifndef __NO_LIBS_FCNTL
int fcntl(int fd, int cmd, ...){int r;	long arg;void* ap;va_start(ap, cmd);arg = va_arg(ap, long);va_end(ap);	r = syscall(__NR_fcntl, fd, cmd, arg);return r;}
#else
#define fcntl undefined
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_EXECVE
int execve(const char* filename, char * const argv[], char *const envp[]){return syscall(__NR_execve,filename,argv,envp);}
#else
#define execve undefined
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_WRITE
int write(int fd, void* buf, size_t count) {return syscall(__NR_write,fd,buf,count);}
#else
#define write undefined
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_MPROTECT
int mprotect(void* start, size_t len, long prot) {return syscall(__NR_mprotect,start,len,prot);}
#else
#define mprotect undefined
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_MUNMAP
int munmap(void *addr, size_t len) {return syscall(__NR_munmap,addr,len);}
#else
#define munmap undefined
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_MMAP
void *mmap(void *start, size_t len, int prot, int flags, int fd, long int off){

#ifdef __NR_mmap2
	return syscall(__NR_mmap2, start, len, prot, flags, fd, off>>16);
#else
	return syscall(__NR_mmap, start, len, prot, flags, fd, off);
#endif
}
#else
#define mmap undefined
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_SBRK
void *sbrk(long inc){return syscall(__NR_brk, syscall(__NR_brk, 0)+inc);}
#else
#define sbrk undefined
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_MREMAP
void *mremap(void *old_addr, size_t old_len, size_t new_len, int flags, ...){
	void* ap;
	void *new_addr;
	va_start(ap, flags);
	new_addr = va_arg(ap, void *);
	va_end(ap);

	return syscall(__NR_mremap, old_addr, old_len, new_len, flags, new_addr);
}
#else
#define mremap undefined
#endif
///------------------------------------------------------------
#ifndef __NO_LIBS_MADVISE
int madvise(void *addr, size_t len, int advice){return syscall(__NR_madvise, addr, len, advice);}
#else
#define madvise undefined
#endif
///------------------------------------------------------------
return arg(
open,close,stat,fstat,lstat,brk,exit,getpid,fork,vfork,read,lseek,kill,
dup2,dup,alarm,pipe,time,unlink,nanosleep,readlink,ioctl,socket,bind,
accept,connect,listen,getsockname,setsockopt,getsockopt,sendto,send,
recvfrom,recv,vmsplice,tee,splice,sendfile,waitpid,waitid,wait2,wait,
clone,select,fcntl,execve,write,mprotect,munmap,mmap,sbrk,mremap,madvise
			);
}


sys_t libs(sys_t sys){
	uni* __libs_addr_list=__libs_constructor();
MARK(sys,open,__libs_addr_list,0);
MARK(sys,close,__libs_addr_list,1);
MARK(sys,stat,__libs_addr_list,2);
MARK(sys,fstat,__libs_addr_list,3);
MARK(sys,lstat,__libs_addr_list,4);
MARK(sys,brk,__libs_addr_list,5);
MARK(sys,exit,__libs_addr_list,6);
MARK(sys,getpid,__libs_addr_list,7);
MARK(sys,fork,__libs_addr_list,8);
MARK(sys,vfork,__libs_addr_list,9);
MARK(sys,read,__libs_addr_list,10);
MARK(sys,lseek,__libs_addr_list,11);
MARK(sys,kill,__libs_addr_list,12);
MARK(sys,dup2,__libs_addr_list,13);
MARK(sys,dup,__libs_addr_list,14);
MARK(sys,alarm,__libs_addr_list,15);
MARK(sys,pipe,__libs_addr_list,16);
MARK(sys,time,__libs_addr_list,17);
MARK(sys,unlink,__libs_addr_list,18);
MARK(sys,nanosleep,__libs_addr_list,19);
MARK(sys,readlink,__libs_addr_list,20);
MARK(sys,ioctl,__libs_addr_list,21);
MARK(sys,socket,__libs_addr_list,22);
MARK(sys,bind,__libs_addr_list,23);
MARK(sys,accept,__libs_addr_list,24);
MARK(sys,connect,__libs_addr_list,25);
MARK(sys,listen,__libs_addr_list,26);
MARK(sys,getsockname,__libs_addr_list,27);
MARK(sys,setsockopt,__libs_addr_list,28);
MARK(sys,getsockopt,__libs_addr_list,29);
MARK(sys,sendto,__libs_addr_list,30);
MARK(sys,send,__libs_addr_list,31);
MARK(sys,recvfrom,__libs_addr_list,32);
MARK(sys,recv,__libs_addr_list,33);
MARK(sys,vmsplice,__libs_addr_list,34);
MARK(sys,tee,__libs_addr_list,35);
MARK(sys,splice,__libs_addr_list,36);
MARK(sys,sendfile,__libs_addr_list,37);
MARK(sys,waitpid,__libs_addr_list,38);
MARK(sys,waitid,__libs_addr_list,39);
MARK(sys,wait2,__libs_addr_list,40);
MARK(sys,wait,__libs_addr_list,41);
MARK(sys,clone,__libs_addr_list,42);
MARK(sys,select,__libs_addr_list,43);
MARK(sys,fcntl,__libs_addr_list,44);
MARK(sys,execve,__libs_addr_list,45);
MARK(sys,write,__libs_addr_list,46);
MARK(sys,mprotect,__libs_addr_list,47);
MARK(sys,munmap,__libs_addr_list,48);
MARK(sys,mmap,__libs_addr_list,49);
MARK(sys,sbrk,__libs_addr_list,50);
MARK(sys,mremap,__libs_addr_list,51);
MARK(sys,madvise,__libs_addr_list,52);
	
return sys;	
													}


uni* __libs_constructor()__attribute__((visibility ("hidden")));
static sys_t s;

