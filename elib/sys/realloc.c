#ifndef no_realloc 
extern void *memcpy (void *dest, void *src, size n);
extern void *malloc(size __size);
extern uni count(void** Arrs);
extern void free(void* ptr);
#undef no_memcpy
#undef no_malloc
#undef no_count
#undef no_free

void *realloc(void *ptr, size __size)
{
        void *newptr = NULL;
 
        if (!ptr)
                return malloc(__size);
        if (!__size) {
                free(ptr);
                return malloc(0);
        }
 
        newptr = malloc(__size);
        if (newptr) {
                size old_size = *((size *) (ptr - sizeof(size)));
				 memcpy(newptr, ptr, count(ptr)*sizeof(ptr));//(old_size < size ? old_size : size));
                free(ptr);
        }
        return newptr;
}
#endif
