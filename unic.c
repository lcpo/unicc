
/*#include <gc/gc.h>
#define malloc(n) GC_malloc(n)
#define calloc(m,n) GC_malloc((m)+(n))
#define realloc(m,n) GC_realloc(m,n)
#define free(x) ((x)=NULL)
#define force_GC_on(x) GC_free(x)
*/

#include "unic.h"

//----------------------------------------------------------------------
#define INITIAL_ARGV_MAX 1024
char *initial_argv[INITIAL_ARGV_MAX];

int execl (char *path, char *arg, ...){
   size argv_max = 1024;

    char **argv = initial_argv;
    va_list args;
	argv[0] = arg;
 
 va_start (args, arg);
  unsigned int i = 0;
 while (argv[i++] != NULL)
  {
      if (i == argv_max)
     {
       argv_max *= 2;
        char **nptr = (char**)libc_realloc (argv == initial_argv ? NULL : argv,
                        argv_max * sizeof (char *));
      if (nptr == NULL)
         {
           if (argv != initial_argv)
         libc_free (argv);
          return -1;
        }
       if (argv == initial_argv)
         libc_memcpy (nptr, argv, i * sizeof (char *));
 
       argv = nptr;
     }
 
       argv[i] = va_arg (args, char *);
      }
   va_end (args);
    char *envp[] ={"HOME=/home/ss","PATH=/bin:/usr/bin","TZ=UTC0","USER=ss","LOGNAME=/home/ss/log.txt",0};
   int ret = execve (path, (char *const *) argv, envp);
   if (argv != initial_argv)
     libc_free (argv);
 
   return ret;
 }
//----------------------------------------------------------------------
char* getcmd(){
char* exe=libc_malloc(sizeof(char*));
char* tmp=libc_malloc(sizeof(char*));	
char* start="/proc/";
char* end="/cmdline";
char* pid=libc_itos(getpid());
libc_mcpy(tmp,start,libc_strlen(start));
libc_mcat(tmp,pid);
libc_mcat(tmp,end);
int file=open(tmp,0,0);
read(file,exe,128);
close(file);
libc_free(tmp);
return exe;
	}
//----------------------------------------------------------------------
char* getpn(){
char* exe=libc_malloc(sizeof(char*));
char* tmp=libc_malloc(sizeof(char*));	
char* start="/proc/";
char* end="/exe";
char* pid=libc_itos(getpid());
libc_mcpy(tmp,start,libc_strlen(start));
libc_mcat(tmp,pid);
libc_mcat(tmp,end);
readlink(tmp,exe,128);
libc_free(tmp);
return exe;
				}
//----------------------------------------------------------------------
int getargc(char* output){
int i=0,argc=0;
char* out=output;	
while(-1){
if(out[i]=='\0'){++argc;}
if(out[i]=='\0' && out[i+1]=='\0'){break;}
	i++;}	
return argc;	
						 }
//----------------------------------------------------------------------
char** getargv(long argc,char* output,char**argv){
int i=0,sep=0;

while(argc>i){
argv[i]=output+sep;
sep=sep+(long)libc_strlen(output+sep)+1;
	i++;
	}
return argv;
										}
//----------------------------------------------------------------------
int exec(char* command, char* out){
int $_pipe[2];
pipe($_pipe);
switch(fork()){
case -1:printf("error fork!");exit(1);
case 0: 
close($_pipe[0]); 
dup2($_pipe[1], 1); 
execl("/bin/sh", "sh", "-c", command, NULL);
close($_pipe[1]);
exit(0);			
}
close($_pipe[1]);
int ret=read($_pipe[0],out,4096);
close($_pipe[0]);
	}
//----------------------------------------------------------------------
int system(char* command){
int $_pipe[2];
pipe($_pipe);
switch(fork()){
case -1:printf("error fork!");exit(1);
case 0: 
close($_pipe[0]); 
dup2($_pipe[1], 1); 
execl("/bin/sh", "sh", "-c", command, NULL);
close($_pipe[1]);
exit(0);			
}
close($_pipe[1]);
char* buff=libc_malloc(sizeof(char*));
int ret=read($_pipe[0],buff,4096);
close($_pipe[0]);
libc_print_str(buff);
return ret;	
						  }	
//----------------------------------------------------------------------						  
void _start() {
char* _start$output=getcmd();
long _start$i=0,argc=0,_start$sep=0;
argc=getargc(_start$output);
char** argv=libc_malloc(sizeof(char**)*argc);
if(argc==1){argv[0]=(char*)_start$output;argc--;}
if(argc>=2){argv=getargv(argc,_start$output,argv);argc--;}
int result=main(argc,argv);
libc_free(argv);
exit(result);
//asm volatile("movl $60, %eax\n\t" "movq $0, %rdi\n\t" "syscall");
return;
	}
//----------------------------------------------------------------------

