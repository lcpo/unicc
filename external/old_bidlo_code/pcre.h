char* add(char* val);
//***********************************************************************************************
int preg_match ( char* pattern, char* subject, char** matches , int flags , int offset){
pcre *f;
pcre_extra *f_ext;
const char *errstr;
int errchar;
int vecsize=strlen(subject);
int vector[vecsize];
const unsigned char *tables;
int pairs,i,j=0;
tables=pcre_maketables();
f=pcre_compile(pattern,PCRE_UTF8|flags,&errstr,&errchar,tables);
if((f)==NULL){printf("Ошибка: %s\nСимвол N%i\nШаблон:%s\n",errstr,errchar,pattern);return -1;}
f_ext=pcre_study(f,0,&errstr);
if((pairs=pcre_exec(f,f_ext,subject,strlen(subject),offset,PCRE_NOTEMPTY,vector,vecsize))<0){return 0;}
for(i=0;i<pairs;i++){
char* buff1=add(subject);
pcre_copy_substring(subject,vector,pairs,i,buff1,strlen(subject));
matches[i]=add(buff1);
pcre_free_substring(buff1);
	    }

return 1;
}
//***********************************************************************************************
int preg_match_all ( char* pattern, char* subject, char*** matches , int flags , int offset){
pcre *f;
pcre_extra *f_ext;
const char *errstr;
int vecsize=strlen(subject);
int vector[vecsize];
const unsigned char *tables;
int errchar,pairs,n,i=0,j=0;
tables=pcre_maketables();
f=pcre_compile(pattern,PCRE_UTF8|flags,&errstr,&errchar,NULL);
if((f)==NULL){printf("Ошибка: %s\nСимвол N%i\nШаблон:%s\n",errstr,errchar,pattern);return -1;}
f_ext=pcre_study(f,0,&errstr);
while((pairs=pcre_exec(f,f_ext,subject,strlen(subject),j+offset,PCRE_NOTEMPTY,vector,vecsize))>0){
matches[i]=Arr();
n=0;
if((pairs)<0){return -1;}
while(pairs>n){
char* buff2=add("");
pcre_copy_substring(subject,vector,pairs,n,buff2,strlen(subject));
matches[i][n]=add(buff2);
pcre_free_substring(buff2);
n++;
			  }
j=vector[1];
	i++;
   }

return 1;
}
//***********************************************************************************************
char *string_preg_replace(char* pattern, char* replacement, char* subject , int limit){
int i=0;
char* buffr=add(subject);
char*** pat_ar=Arr();	
if(preg_match_all(pattern,subject,pat_ar,0,0)){
char* nbuffr=add(replacement);
char** sim=Arr();
sim=simgen("$",100);
char** newarr=Arr();
while(pat_ar[i]!=NULL){newarr[i]=add(pat_ar[i][0]);i++;}
char** aruq=array_unique(newarr);
char** nsim=Arr();
i=0;
while(sim[i]!=NULL){
if(strpos(nbuffr,sim[i])!=-1 && aruq[i]!=NULL){nsim[i]=add(sim[i]);}else{nsim[i]="";}
i++;
}
nbuffr=array_replace(nbuffr,sim,nsim);
i=0;
char* tmp=Str();
char** sep=Arr();
while(aruq[i]!=NULL){
if(nsim[i]!=""){
tmp=strstr(nbuffr,nsim[i]);
tmp=strpstr_nomo(tmp+1,"$");
sep[i]=add("$");
strcat(sep[i],tmp);
sep[i]=string_replace(sep[i],nsim[i],aruq[i]);
}else{sep[i]=add("");}
i++;}
buffr=array_replace(buffr,aruq,sep);
}

return buffr;	
																					}

//----------------------------------------------------------------------
char* array_preg_replace(char* str, char** delimiters, char **replacement){
int i=0;
char* buffrsa=add(str);
while(delimiters[i]!=NULL){
if(replacement[i]!=NULL && replacement[i]!='\0' && strpos(buffrsa,delimiters[i])!=-1){buffrsa=string_preg_replace(buffrsa,delimiters[i],replacement[i],0);}
	i++;}
return buffrsa;		
	}
//----------------------------------------------------------------------

