#ifndef no_strlen
size strlen(char *str){
	register const char *s;
	for (s = str; *s; ++s);
	return(s - str);
}

#endif	
