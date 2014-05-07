#ifndef no_memcmp
int memcmp( void *s1,  void *s2, size_t n) {
     if (n) {
         unsigned char *p1 = s1, *p2 = s2;
 
        do {
            if (*p1++ != *p2++) {
                return (*--p1 - *--p2);
            }
        } while (--n);
     }
     return 0;
}
#endif
