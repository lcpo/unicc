#ifndef no_strpos
uni strpos(char *haystack, char *needle)
{
   char *p = strstr(haystack, needle);
   if (p){return p - haystack;}else{return -1;}  
}
#endif
