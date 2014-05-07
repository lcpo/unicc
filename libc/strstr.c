#ifndef no_strstr
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
#endif	
