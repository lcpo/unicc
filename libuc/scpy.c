#ifndef no_scpy
inline char* scpy(char *destaddr, char *srcaddr, uni len) {
    char *d = destaddr;
    char *s = srcaddr;
    while (len-- > 0) {
        *d++ = *s++;
    }
    return destaddr;
}
#endif
