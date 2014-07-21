
/*#include <gc/gc.h>
#define malloc(n) GC_malloc(n)
#define calloc(m,n) GC_malloc((m)+(n))
#define realloc(m,n) GC_realloc(m,n)
#define free(x) ((x)=NULL)
#define force_GC_on(x) GC_free(x)
*/

#include "unicc.h"

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
        char **nptr = realloc (argv == initial_argv ? NULL : argv,argv_max);
      if (nptr == NULL){
           if (argv != initial_argv)
         libc_free (argv);
          return -1;
        }
       if (argv == initial_argv){libc_memcpy (nptr, argv, i * sizeof (char *));}
 
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
 static char* proc_start="/proc/";
 static char* proc_end="/cmdline";
//----------------------------------------------------------------------
char* getcmd(){
char* exe=malloc(sizeof(exe));
char* tmp=malloc(sizeof(tmp));	
char* pid=libc_itos(getpid());
libc_strcpy(tmp,proc_start);
libc_strcat(tmp,pid);
libc_strcat(tmp,proc_end);
int file=open(tmp,0,0);
read(file,exe,128);
close(file);
free(tmp);
free(pid);
return exe;
	}
//----------------------------------------------------------------------
char* getpn(){
char* exe=malloc(sizeof(exe));
char* tmp=malloc(sizeof(tmp));
char* pid=libc_itos(getpid());
libc_strcpy(tmp,proc_start);
libc_strcat(tmp,pid);
libc_strcat(tmp,proc_end);
readlink(tmp,exe,128);
free(tmp);
free(pid);
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
int tpipe[2];
pipe(tpipe);
switch(fork()){
case -1:write($O,"error fork!",12);
exit(1);
case 0: 
close(tpipe[0]); 
dup2(tpipe[1], 1); 
execl("/bin/sh", "sh", "-c", command, NULL);
close(tpipe[1]);
exit(0);			
}
close(tpipe[1]);
int ret=read(tpipe[0],out,4096);
close(tpipe[0]);
	}
//----------------------------------------------------------------------
int system(char* command){
int tpipe[2];
pipe(tpipe);
switch(fork()){
case -1:write($O,"error fork!",12);
exit(1);
case 0: 
close(tpipe[0]); 
dup2(tpipe[1], 1); 
execl("/bin/sh", "sh", "-c", command, NULL);
close(tpipe[1]);
exit(0);			
}
close(tpipe[1]);
char* buff=libc_malloc(4096);
int ret=read(tpipe[0],buff,4096);
close(tpipe[0]);
libc_print_str(buff);
free(buff);
return ret;	
						  }
//----------------------------------------------------------------------

#ifdef __NO_START
#define main _start
#else						  	
void _start() {
char* _startout=getcmd();
long argc=0;
argc=getargc(_startout);
char** argv=malloc(argc);
if(argc==1){argv[0]=(char*)_startout;argc--;}
if(argc>=2){argv=getargv(argc,_startout,argv);argc--;}
int result=main(argc,argv);
free(_startout);
free_ptr(argv);
exit(result);
return;
 
	}
#endif	
//----------------------------------------------------------------------

