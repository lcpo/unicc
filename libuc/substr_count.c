#ifndef no_substr_count

int substr_count(char* str_s, char* sub_s){
int count_sub=0;
str_s = strstr(str_s,sub_s);
while(str_s!=0){
str_s=str_s+strlen(sub_s);
str_s = strstr(str_s,sub_s);
count_sub++;
				}
return count_sub;
}
#endif
