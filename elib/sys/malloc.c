#ifndef no_malloc
extern void*  mmap(void* addr, size len, int prot, int flags, int fd, unsigned long offset);
#undef no_mmap

void *malloc(size __size){
void *result;
result = mmap(NULL, __size+sizeof(void*) * sizeof(void*) , PROT_READ | PROT_WRITE,MMAP_FLAGS, 0, 0);//+ sizeof(size_t)
if (result == MAP_FAILED){return NULL;}
* (size *) result = __size;
return(result + sizeof(void*));
}
#endif
