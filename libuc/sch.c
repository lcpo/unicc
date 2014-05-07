#ifndef no_sch


uni sch(char* str, int ch){
uni i=0;
while(str[i] != '\0'){
if(str[i] == ch){return 1;}
++i;}
return 0;
	}
	
#endif
