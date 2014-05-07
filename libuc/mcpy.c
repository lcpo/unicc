#ifndef no_mcpy


inline void *mcpy(void *dst, void *src, uni len){
uni i;
char *d = dst;
char *s = src;
for (i=0; i<len; i++) {d[i] = s[i];}
return dst;
	}
#endif
