#ifndef no_memcpy
void *memcpy (void *dest, void *src, size n)
{
        register char *r1 = dest;
        register const char *r2 = src;
 
        while (n) {
                *r1++ = *r2++;
                --n;
        }
 
        return dest;
}
#endif
