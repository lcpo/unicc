#ifndef no_free
#undef no_munmap
extern uni munmap(void *__addr, uni __len);
void free(void *ptr){

if (ptr == NULL){return;}
ptr -= sizeof(size);
munmap(ptr, * (size *) ptr + sizeof(size));
}
#endif
