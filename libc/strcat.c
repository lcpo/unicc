#ifndef no_strcat
inline char* strcat ( char* des, char* so ){
while (*des) ++des;
while ((*des++ = *so++) != '\0') ;
return des;
}
#endif
