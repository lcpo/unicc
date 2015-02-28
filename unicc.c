
#include "tact.h"


#ifndef __NO_START
int _start(int argc){

#ifdef __x86_64__	
char** argv=(char**)&argc+5;
#endif

#ifdef __i386__
char** argv=(char**)&argc;
#endif
int i=0;
while(argv[i]!=0){i++;}
argc=i;
char** env=(char**)&argv[i+1];

s=libs(s);

s.exit(main(argc, argv,env));
return 0;
}	
#endif
