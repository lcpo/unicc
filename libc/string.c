///---------------------------------------------------------------------
size_t libc_strlen(char *str){
	int n=0;
	if (!str){return n;}
	for (; *str; str++){n++;}
	return n;
}
///---------------------------------------------------------------------
char * libc_strcpy( char *to,char *from){
	char *save = to;
	for (; (*to = *from) != '\0'; ++from, ++to);
	return(save);
}
///---------------------------------------------------------------------
char * libc_strncpy( char *to,char *from, int nom){
	char *save = to; int i=0;
	for (; (*to = *from) != '\0' && nom>i; ++from, ++to, ++i);
	return(save);
}
///---------------------------------------------------------------------
char* libc_strcat ( char* des, char* so ){
while (*des) ++des;
while ((*des++ = *so++) != '\0') ;
return des;
}
///---------------------------------------------------------------------
char* libc_strncat(char* dst, char * src, size_t n){
	if (n != 0) {
		char *d = dst;
		char *s = src;

		while (*d != 0)
			d++;
		do {
			if ((*d = *s++) == 0)
				break;
			d++;
		} while (--n != 0);
		*d = '\0';
	}
	return dst;
}
///---------------------------------------------------------------------
int libc_strcmp(char *l, char *r){
int i=0,ll=libc_strlen(l), lr=libc_strlen(r);
if(ll!=lr){return ll - lr;}
while(l[i]!='\0'){
if(l[i]!=r[i]){return (unsigned int)l[i] - (unsigned int)r[i];}
	i++;}	
								  }
///---------------------------------------------------------------------
int libc_strncmp(char* l, char* r, size_t num){
int i=0;
if (num == 0){return 0;}
do {
if(l[i]!=r[i]){return (unsigned int)l[i]-(unsigned int)r[i];}
if (l[i] == 0){break;}
i++;
} while (--num != 0);
return 0; 
} 
///---------------------------------------------------------------------
char *libc_strchr(char *s, int c){
    char ch = c;
    for ( ; *s != ch; s++){
        if (*s == '\0'){return 0;}
        }
    return (char *)s;
}
///---------------------------------------------------------------------
char* libc_strrchr(char *cp, int ch){
    char *save; char c;
    for (save = (char *)0; (c = *cp); cp++) {
	if (c == ch)
	    save = (char *) cp;
    }
    return save;
}
///---------------------------------------------------------------------
int libc_strspn(char *p, char *s){
	int i=0, j=0;
	for (; p[i]; i++) {
		for (; s[j]; j++) {
			if (s[j] == p[i]){break;}
		}
		if (!s[j]){	break;}
	}
	return i;
}
///---------------------------------------------------------------------
int libc_strcspn (char *p,char *s){
	int i=0, j=0;

	for (; p[i]; i++) {
		for (; s[j]; j++) {
			if (s[j] == p[i]){break;}
		}
		if (s[j]){break;}
	}
	return i;
}
///---------------------------------------------------------------------
char * libc_strpbrk(char *s1, char *s2){
	for (; *s1; s1++) {
		if (libc_strchr (s2, *s1) != 0)
			return ((char *)s1);
	}
	return 0;
}
///---------------------------------------------------------------------
char * libc_strstr(char *string, char *substring){
char c, sc;
size_t len;
if ((c = *substring++) != 0) {
len = libc_strlen(substring);
	do {
		do {
		if ((sc = *string++) == 0){	return NULL;}
			} while (sc != c);
		
	} while (libc_strncmp(string, substring, len) != 0);
	string--;
	}
return ((char *) string);
}

///---------------------------------------------------------------------
//strerror(n) ???
///---------------------------------------------------------------------
char * libc_strtok(char *p, char *tok){
char *t; char *r; int n;

	if (p){t = p;}
	r = t + libc_strspn(t, tok);
	if (!(n = libc_strcspn(r, tok))){return 0;}
	t = r + n;
	if (*t){*t++ = 0;}
	return r;
}
///---------------------------------------------------------------------
void *libc_memcpy (void *dest, void *src, size_t n){
        char *r1 = dest;
        const char *r2 = src;
 
        while (n) {
                *r1++ = *r2++;
                --n;
        }
 
        return dest;
}
///---------------------------------------------------------------------
/*
void *libc_memcat (void *dest, void *src, size_t n){
        char *r1 = dest;
        const char *r2 = src;
 
        while (n) {
                *r1++ = *r2++;
                --n;
        }
 
        return dest;
}*/


///---------------------------------------------------------------------
void *libc_memmove(char *dest, char *src, size n)
{
	char *d = dest;
	const char *s = src;
	if (d==s) return d;
	if ((size_t)(d-s) < n) {
		while (n--) d[n] = s[n];
		return dest;
	}
	return libc_memcpy((char*)d, (char*)s, (size)n);
}
///---------------------------------------------------------------------
int libc_memcmp( void *s1,  void *s2, size_t n) {
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
///---------------------------------------------------------------------
void *libc_memchr( void *s, int c, size_t n){
    if (n) { unsigned char *p = s;
        do {
             if (*p++ == (unsigned char) c) {
                return (void *) (p - 1);
             }
         } while (--n);
     }
     return 0;
 }
///---------------------------------------------------------------------
void *libc_memset(void *s, int c, size n)
{
        unsigned char *p = (unsigned char *) s;
 
        while (n) {
                *p++ = (unsigned char) c;
                --n;
        }
 
        return s;
}
///---------------------------------------------------------------------
