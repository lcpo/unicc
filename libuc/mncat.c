#ifndef no_mncat


inline void *mncat(void *dst, void *src, size len){
char *d=dst;
char *s = src;
mcpy(d+lens(dst),s,len);

return dst;
	}
#endif
