#ifndef no_msetn


void *msetn(void *pt, int c, size n){
uni i;
long *pb = (long *) pt;
for(i=0;i<(n);i++){pb[i]=c;}
return pb;
	}
#endif
