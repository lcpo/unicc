#ifndef no_sch_count


uni sch_count(char* str, int ch){
uni i=0; uni count=0;
while(str[i] != '\0'){
if(str[i] == ch){count++;}
++i;}
return count;

	}
#endif
