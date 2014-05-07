#ifndef no_strncmp	 
int strncmp(const char* s1, const char* s2, size num){
if (num == 0){return 0;}
do {
if (*s1 != *s2++){return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));}
if (*s1++ == 0){break;}
} while (--num != 0);
return 0;
 }
 #endif	
