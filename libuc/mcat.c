#ifndef no_mcat

inline void *mcat(void *dst, void *src){
//size_t i;
//if ((uintptr_t)dst % sizeof(long) == 0 && (uintptr_t)src % sizeof(long) == 0) {
//long *d=dst;
//long *s = src;
//mncat(d,s,count(&dst)+count(&src)+2);
//}else{
mncat(dst,src,lens(dst)+lens(src));
 //    }
return dst;
	}
#endif
