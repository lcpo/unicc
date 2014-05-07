#ifndef no_mset


///void *mset(void *ptr, int ch, size_t len);
void *mset(void *pt, int c, size n){
uni i;
char *pb = (char *) pt;
for(i=0;i<(n+1);i++){pb[i]=c;}
return pb;
 }
 #endif
