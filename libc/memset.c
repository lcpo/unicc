#ifndef no_memset
void *memset(void *s, int c, size n)
{
        register unsigned char *p = (unsigned char *) s;
 
        while (n) {
                *p++ = (unsigned char) c;
                --n;
        }
 
        return s;
}
#endif
