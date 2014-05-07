///void *set(void *ptr, int ch);
#ifndef no_set

void *set(void *ptr, int ch){
//if ((uintptr_t)ptr % sizeof(long) == 0) {
//long *p = ptr;
//mset(p,ch,count(&ptr)+1);
//}else{
mset(ptr,ch,lens(ptr));
 //        }
return ptr;
 }
#endif
