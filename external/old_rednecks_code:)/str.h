char* add(char* val);

//----------------------------------------------------------------------
char* strmin(char* str,long int n){
if(str!=NULL){	
long int len=strlen(str);
if(n>strlen(str) && n>0){n=len;}	
char* buffsm=add("");
strncpy(buffsm,str,len-n);
return buffsm;
}else{
return '\0';	
}}
//----------------------------------------------------------------------
char** simgen(char* sim, int cou){
int i=0;
char** outs=Arr();
char* numb=add("");
while(cou>i){
numb=add(sim);
strcat(numb,itoa(i));
outs[i]=add(numb);	
i++;}
return outs;	
}	
//----------------------------------------------------------------------
int compare(char* tmp_a, char* tmp_b, char* par){
long int i=0,r=0;
if(par=="!="){if(strlen(tmp_a)!=strlen(tmp_b)){return 0;}}
if(par=="=="){
while(strlen(tmp_a)>i){if(tmp_a[i]==tmp_b[i]){r++;}else{r--;}i++;}
if(strlen(tmp_a)==r){return 1;}else{return 0;}
}
	}
//----------------------------------------------------------------------	

#define concat_t(buff,a,b)({strcat(buff,a);strcat(buff,b);buff;})
//--------------------------------------------------------------------//analog substr_count
//#define substr_count(___str,___s)({int ___i=0;___str = strstr(___str, ___s);while(___str!=NULL){___str=___str+strlen(___s);___str = strstr(___str, ___s);___i++;}___i;})

int substr_count(char* str_s, char* sub_s){
int count_sub=0;
str_s = strstr(str_s,sub_s);
while(str_s!=NULL){
str_s=str_s+strlen(sub_s);
str_s = strstr(str_s,sub_s);
count_sub++;
				}
return count_sub;
}

//--------------------------------------------------------------------//analog implode

//--------------------------------------------------------------------//core function
int lenAllArg(char* p,...){
va_list ar;
va_start(ar,p);
int n=0;
int lenb=0;
while(p!=false){
lenb=(lenb+strlen(p));
p=va_arg(ar,typeof(p));
n++;}
va_end(ar);
return lenb;
}
//--------------------------------------------------------------------//core print
int proto_print(char* p,...){
char buff[STRING_MAX];
memset(buff,'\0',sizeof(char));
va_list arg;
va_start(arg,p);
int i=0;
while(p!=false){
strncat(buff,p,strlen(p));
p=va_arg(arg,typeof(p));
i++;}
va_end(arg);
printf("%s",buff);
strcpy(buff,"");
return true;
		}
//--------------------------------------------------------------------//analog print
#define print(p...)({proto_print(p,false);})
//--------------------------------------------------------------------//core echo
void proto_echo(char* p,...){
char buff[STRING_MAX];
memset(buff,'\0',sizeof(buff));
va_list arg;
va_start(arg,p);
int i=0;
while(p!=false){
strncat(buff,p,strlen(p));
p=va_arg(arg,typeof(p));
i++;
}
printf("%s",buff);
va_end(arg);
strcpy(buff,"");
	}
//--------------------------------------------------------------------//analog echo	
#define echo(p...)({proto_echo(p,false);})
//--------------------------------------------------------------------//
char* proto_con(char* s,...){
char buff[STRING_MAX];
va_list arg;
va_start(arg,s);
while(s!=false){
strcat(buff,s);
s=va_arg(arg,typeof(s));
}
va_end(arg);
char* out=buff;
return out;
strcpy(buff,"");
	}
//--------------------------------------------------------------------//	
#define con(p...)({proto_con(p,false);})
//--------------------------------------------------------------------//

int proc_string_replace(char *string, const char *delimiter, const char *replacement){
int	 bret = 0;char *ret;int length_del, length_rep, i, j;
if (string == NULL || delimiter == NULL || replacement == NULL){return 0;}
length_del = strlen(delimiter);
length_rep = strlen(replacement);
i = 0;j = 0; 
while (string[i] != '\0') {
if (!strncmp(&string[i], delimiter, length_del)) {i += length_del;j += length_rep;bret = 1;}else{i++;j++;}
					  }
if (!bret){return bret;}
ret = malloc(j+1);
if (!ret){return 0;}
i = 0;j = 0; 
while (string[i] != '\0') {
if (!strncmp(&string[i], delimiter, length_del)) {strncpy(&ret[j], replacement, length_rep);i += length_del;j += length_rep;}else{ret[j] = string[i];i++;j++;}
						  }
ret[j] = '\0';
strcpy(string, ret);
free(ret);
return bret;
}

//--------------------------------------------------------------------//
char* strnstr(char* str, char* ser){
if(strstr(str,ser)){
int len_ser=strlen(ser),len_str=strlen(str),len_nstr;
char* buff_strn=Str();
strcpy(buff_strn,"\0");
char* estr=strstr(str,ser)+len_ser;
int iestr=strlen(estr);
len_nstr=len_str-iestr;
strncat(buff_strn,str,len_nstr);
char* out=buff_strn;
return out;
}else{return "";}
	}
//--------------------------------------------------------------------//		
char* strpstr(char* str,char* ser){
if(strstr(str,ser)){	
int len_ser=strlen(ser),len_str=strlen(str),len_nstr;
char* buff_strn=Str();
strcpy(buff_strn,"\0");
char* estr=strstr(str,ser)+len_ser;
int iestr=strlen(estr);
len_nstr=len_str-iestr-len_ser;
strncat(buff_strn,str,len_nstr);
char* out=buff_strn;
return out;
}else{return "";}
	}


//**********************************************************************/
int strpos(char *haystack, char *needle)
{
   char *p = strstr(haystack, needle);
   if (p){return p - haystack;}else{return -1;}  
}
//**********************************************************************/
int strpos_r(char *haystack, char *needle ,int pos){
char* str;
int len_needle=strlen(needle);
if(pos>0){str=haystack+pos;}else{str=haystack;}
print_var(pos,d\n);	
   char *p = strstr(str, needle);
   if (p){return p - str+len_needle;}else{return -1;} 
}
//--------------------------------------------------------------------//analog explode

//----------------------------------------------------------------------
char* string_replace(char *str, char *delimiter, char *replacement){
char *ret=Str();
int length_del=strlen(delimiter), length_rep=strlen(replacement), i=0, j=0;
while (str[i] != '\0') {if (!strncmp(&str[i], delimiter, length_del)) {i += length_del;j += length_rep;}else{i++;j++;}}
i = 0;j = 0; 
while (str[i] != '\0') {if (!strncmp(&str[i], delimiter, length_del)) {strncpy(&ret[j], replacement, length_rep);i += length_del;j += length_rep;}else{ret[j] = str[i];i++;j++;}}
ret[j] = '\0';
char* out=add(ret);
return out;
}
//----------------------------------------------------------------------
char* array_replace(char* str, char** delimiters, char **replacement){
int i=0;
char* buffrsa=add(str);
while(delimiters[i]!=NULL){
if(replacement[i]!=NULL && replacement[i]!='\0' && strpos(buffrsa,delimiters[i])!=-1){buffrsa=string_replace(buffrsa,delimiters[i],replacement[i]);}
	i++;}
return buffrsa;		
	}

