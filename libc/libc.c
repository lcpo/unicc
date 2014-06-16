class libc(){
//----------------------------------------------------------------------1	
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
//----------------------------------------------------------------------2
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
//----------------------------------------------------------------------3
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
//----------------------------------------------------------------------4
void *memset(void *s, int c, size n)
{
        register unsigned char *p = (unsigned char *) s;
 
        while (n) {
                *p++ = (unsigned char) c;
                --n;
        }
 
        return s;
}
//----------------------------------------------------------------------5
char* strcat ( char* des, char* so ){
while (*des) ++des;
while ((*des++ = *so++) != '\0') ;
return des;
}
//----------------------------------------------------------------------
char * strcpy(char *to, const char *from){
	char *save = to;
	for (; (*to = *from) != 0; ++from, ++to);
	return(save);
}
//----------------------------------------------------------------------
size strlen(char *str){
	register const char *s;
	for (s = str; *s; ++s);
	return(s - str);
}
//----------------------------------------------------------------------
char* strncat(char* dst, const char * src, size n){
	if (n != 0) {
		char *d = dst;
		const char *s = src;

		while (*d != 0)
			d++;
		do {
			if ((*d = *s++) == 0)
				break;
			d++;
		} while (--n != 0);
		*d = 0;
	}
	return dst;
}
//----------------------------------------------------------------------
int strncmp(const char* s1, const char* s2, size num){
if (num == 0){return 0;}
do {
if (*s1 != *s2++){return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));}
if (*s1++ == 0){break;}
} while (--num != 0);
return 0;
 } 
//----------------------------------------------------------------------
uni strpos(char *haystack, char *needle)
{
   char *p = strstr(haystack, needle);
   if (p){return p - haystack;}else{return -1;}  
} 
//----------------------------------------------------------------------
char * strstr(char *string, char *substring){
    register char *a, *b;
    b = substring;
    if (*b == 0) {	return string;   }
    
    for ( ; *string != 0; string += 1) {
	if (*string != *b) {continue;}
	a = string;
	while (1) {if (*b == 0) {return string; }
	    if (*a++ != *b++) {break;}
	}
	b = substring;
										}
    return (char *) 0;
}
//----------------------------------------------------------------------
int print2(char* str){
printf("%s\n",str);
return 123;	
	}
//----------------------------------------------------------------------
	 
    return obj(
               set_fun(memchr,void*,libc,3),
               set_fun(memcmp,int,libc,3),
               set_fun(memcpy,void*,libc,3),
               set_fun(memset,void*,libc,3),
               set_fun(strcat,char*,libc,2),
               set_fun(strcpy,char*,libc,2),
               set_fun(strlen,size,libc,1),
               set_fun(strncat,char*,libc,3),
               set_fun(strncmp,int,libc,3),
               set_fun(strpos,uni,libc,2),
               set_fun(print2,int,libc,1),
               set_fun(strstr,char*,libc,2)
           );	
	
	}
