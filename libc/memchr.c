#ifndef no_memchr
void *memchr( void *s, int c, size_t n){
    if (n) { unsigned char *p = s;
        do {
             if (*p++ == (unsigned char) c) {
                return (void *) (p - 1);
             }
         } while (--n);
     }
     return 0;
 }
#endif
