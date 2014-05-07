#ifndef no_strnpos

int strnpos(char* str, char* sub, int ot){
int pFind = 0, pos = 0;
str=str+ot;
if(strstr(str,sub)){
pFind= lens(strstr(str, sub));
pos = lens(str+pFind);
}
return pos;
	}
#endif
