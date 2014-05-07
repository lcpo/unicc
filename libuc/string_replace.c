#ifndef no_string_replace
char out_str_rep[MAX_ARG];
char* string_replace(char *string, char *delimiter, char *replacement){
if(!strstr(string,delimiter)){return string;}

int bret = 0, ldel=lens(delimiter), lrep=lens(replacement), i=0,j=0;
char* ret = out_str_rep;
while (string[i] != '\0') {
if (!strncmp(&string[i], delimiter, ldel)) {i += ldel; j += lrep; bret = 1;}else{i++;j++;}
						}
i = 0; j = 0;


while (string[i] != '\0') {
if (!strncmp(&string[i], delimiter, ldel)) {memcpy(&ret[j], replacement, lrep);i += ldel;j += lrep;}else{ret[j] = string[i];i++;j++;}
						  }
ret[j] = '\0';
return ret;
}
#endif
