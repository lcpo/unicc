///TODO: optimization of special
/*!
 * выделить токен из строки паттерна
 * модифицировать строку паттерна
 */ 

char* bracket_string(ch_tab *tb,char* scl){
int plen=libc_strlen(scl)+2;				
int a=0,fl1=0,co=0,n=0,z=0;
char ooscl='\0',oscl='\0',nscl='\0';
char* table=malloc(1024);
tb->flag_denial[tb->length]=0;
scl++;
while(*scl!='\0'){
scl--; oscl=*scl; scl++;
scl++; nscl=*scl; scl--;
if(oscl!='\\' && *scl==' '){scl++;continue;}
if(oscl!='\\' && *scl=='^'){tb->flag_denial[tb->length]=1;scl++;continue;}
if(oscl!='\\' && *scl==1){table[a]='\\';a++;}
if(oscl=='\\' && *scl==1){table[a]=1;	a++;}
//if(oscl=='\\' && *scl=='-' && libc_isalpha(nscl)!=0){table[a]=nscl;a++;}
//if(oscl=='\\' && *scl=='-'){table[a]=*scl;a++;}
if(libc_isspace(*scl)!=0){table[a]=*scl;a++;}
if(oscl=='\\' && (*scl=='[' && *scl==']')){table[a]=*scl;a++;}
if(oscl!='\\' && (*scl=='[' && *scl==']')){printf("error: character is not shielded '%c' !!!\n",*scl);return scl;}
if(oscl=='\\' && libc_ispunct(*scl)!=0){table[a]=*scl;a++;}
	/**/
if(*scl=='-' && libc_isdigit(nscl)!=0 && libc_isdigit(oscl)!=0){
if((oscl)<(nscl)){
for(z=(oscl);z<=(nscl);z++){table[a]=z;a++;}
}else{
for(z=(nscl);z<=(oscl);z++){table[n]=z;a++;}
	 }
															   }
if(libc_isdigit(*scl)!=0 && nscl!='-' && oscl!='-'){table[n]=*scl;a++;}
	/**/
	/**/
if(*scl=='-' && libc_isalpha(nscl)!=0 && libc_isalpha(oscl)!=0){
if(libc_islower(nscl)!=0 && libc_islower(oscl)!=0){//a
if((oscl)<(nscl)){
	for(z=(oscl);z<=(nscl);z++){table[a]=z;a++;}
	}else{
		for(z=(nscl);z<=(oscl);z++){table[a]=z;a++;}
		}
												 }
												 
if(libc_isupper(nscl)!=0 && libc_isupper(oscl)!=0){ //A
if((oscl)<(nscl)){
	for(z=(oscl);z<=(nscl);z++){table[a]=z;a++;}
}else{
	for(z=(nscl);z<=(oscl);z++){table[a]=z;a++;}}
												  }	
/**/
//////
if(libc_islower(nscl)!=0 && libc_isupper(oscl)!=0){
if(oscl<90){for(z=oscl;z<=90;z++){table[a]=z;a++;}}else{for(z=65;z<=(oscl);z++){table[a]=z;a++;}}
if(nscl<122){for(z=nscl;z<=122;z++){table[a]=z;a++;}}else{for(z=97;z<=(nscl);z++){table[a]=z;a++;}}	
//printf("err1\n oscl=%c|%i\n",oscl,oscl);	
	}
if(libc_islower(oscl)!=0 && libc_isupper(nscl)!=0){
if(oscl<122){for(z=oscl;z<=122;z++){table[a]=z;a++;}}else{for(z=97;z<=(oscl);z++){table[a]=z;a++;}}
if(nscl<90){for(z=nscl;z<=90;z++){table[a]=z;a++;}}else{for(z=65;z<=(nscl);z++){table[a]=z;a++;}}
//printf("err2\n oscl=%c|%i\n",oscl,oscl);
	}
//////												  
																}
if(libc_isalpha(*scl)!=0 && nscl!='-' && oscl!='-'){table[a]=*scl;a++;}	

co++; scl++;
			}
			//p=p-plen;
	return table;
	}																		
	
///------------------------------------------------------------	

