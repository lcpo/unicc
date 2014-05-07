#ifndef no_strcpy
char * strcpy(char *to, const char *from){
	char *save = to;
	for (; (*to = *from) != 0; ++from, ++to);
	return(save);
}
#endif
