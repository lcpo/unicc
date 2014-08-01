///TODO: optimization of special
static int is_tablae_symbol(s_vect* vect,char ch){
int ret=0,co=0;
while(co<vect->table_length){if(vect->table[co]==ch){ret++;break;}co++;}
	return ret;
	}
///---------------------------------------------------------------------
int add_tablae_symbol(s_vect* vect,char ch, int z, int i){
int fl=is_tablae_symbol(vect,ch);

if(vect->flag_denial==0){
if(fl>0){vect->code[i]=ch;vect->fn[i]=know;vect->pos[i]=z;vect->tp[i]=V_CHAR;vect->otp[i]=VS_CLASS;i++;}else{i++;}//else{vect->code[i]=0;vect->fn[i]=-1;vect->pos[i]=0;vect->tp[i]=0;vect->otp[i]=0;i++;}
	}else{
if(fl<1){vect->code[i]=ch;vect->fn[i]=know;vect->pos[i]=z;vect->tp[i]=V_CHAR;vect->otp[i]=VS_CLASS;i++;}else{i++;}//else{vect->code[i]=0;vect->fn[i]=-2;vect->pos[i]=0;vect->tp[i]=0;vect->otp[i]=0;i++;}
		}
return i;	
	}
///---------------------------------------------------------------------
static int bracket_symbol(s_vect* vect, char* s, char* p,char oc,char nc,char c, char end, int i){
int plen=libc_strlen(p);
char* bf=malloc(plen);		
char* scl=malloc(plen);
int n=0,z=0,co=0;
vect->flag_denial=0;
libc_memchr(vect->table,0,libc_strlen(vect->table)+100);	
while(*p!='\0'){
p--;oc=*p;p++;
p++;nc=*p;p--;

if(*p=='\\' && nc=='\\'){
	scl[n]=18;n++;p++;oc=18;p++;p++;nc=*p;
	}else if(oc!='\\' && *p=='^'){
		vect->flag_denial=1;p--;oc=*p;p++;p++;nc=*p;p--;
		}else if(oc!='\\' && *p==' '){p--;oc=*p;p++;p++;nc=*p;p--;}else if(oc!='\\' && *p==']'){break;}else if(p=='\0'){printf("error: no closing character ']'!!!\n");
//goto LABEL_EXIT_WHILE;
}else{scl[n]=*p;n++;}
p++;
				}
plen=libc_strlen(scl)+2;				


int a=0,fl1=0;
//printf("%s\n",scl);
co=0;n=0;z=0;
char ooscl='\0', oscl='\0', nscl='\0';

while(*scl!=0){
scl--; oscl=*scl; scl++;
scl++; nscl=*scl; scl--; 
if(oscl!='\\' && *scl==18){vect->table[a]='\\';a++;}
if(oscl=='\\' && *scl==18){vect->table[a]=18;a++;}
if(oscl=='\\' && *scl=='-' && libc_isalpha(nscl)!=0){vect->table[a]=nscl;a++;}
//if(oscl=='\\' && *scl=='-' && libc_isdigit(nscl)!=0){vect->table[a]=nscl;a++;}
if(oscl=='\\' && *scl=='-'){vect->table[a]=*scl;a++;}
if(oscl=='\\' && (is_end_step(*scl)!=-1 || is_end_step_others(*scl)!=-1)){vect->table[a]=*scl;a++;}
if(oscl!='\\' && (is_end_step(*scl)!=-1 || is_end_step_others(*scl)!=-1)){printf("error: character is not shielded '%c' !!!\n",*scl);
//goto LABEL_EXIT_WHILE;
}
	/**/
if(*scl=='-' && libc_isdigit(nscl)!=0 && libc_isdigit(oscl)!=0){
if((oscl-'0')<(nscl-'0')){
	for(z=(oscl-'0');z<=(nscl-'0');z++){vect->table[a]=z+'0';a++;}
	}else{
		for(z=(nscl-'0');z<=(oscl-'0');z++){vect->table[n]=z+'0';a++;}
		}
															   }
if(libc_isdigit(*scl)!=0 && nscl!='-' && oscl!='-'){vect->table[n]=*scl;a++;}
	/**/
	/**/														   
if(*scl=='-' && libc_isalpha(nscl)!=0 && libc_isalpha(oscl)!=0){
if(libc_islower(nscl)!=0 && libc_islower(oscl)!=0){//a
if((oscl)<(nscl)){
	for(z=(oscl);z<=(nscl);z++){vect->table[a]=z;a++;}
	}else{
		for(z=(nscl);z<=(oscl);z++){vect->table[a]=z;a++;}
		}
												 }
												 
if(libc_isupper(nscl)!=0 && libc_isupper(oscl)!=0){ //A
if((oscl)<(nscl)){
	for(z=(oscl);z<=(nscl);z++){vect->table[a]=z;a++;}
}else{
	for(z=(nscl);z<=(oscl);z++){vect->table[a]=z;a++;}}
												  }	
/**/
//////
if(libc_islower(nscl)!=0 && libc_isupper(oscl)!=0){
if(oscl<90){for(z=oscl;z<=90;z++){vect->table[a]=z;a++;}}else{for(z=65;z<=(oscl);z++){vect->table[a]=z;a++;}}
if(nscl<122){for(z=nscl;z<=122;z++){vect->table[a]=z;a++;}}else{for(z=97;z<=(nscl);z++){vect->table[a]=z;a++;}}	
//printf("err1\n oscl=%c|%i\n",oscl,oscl);	
	}
if(libc_islower(oscl)!=0 && libc_isupper(nscl)!=0){
if(oscl<122){for(z=oscl;z<=122;z++){vect->table[a]=z;a++;}}else{for(z=97;z<=(oscl);z++){vect->table[a]=z;a++;}}
if(nscl<90){for(z=nscl;z<=90;z++){vect->table[a]=z;a++;}}else{for(z=65;z<=(nscl);z++){vect->table[a]=z;a++;}}
//printf("err2\n oscl=%c|%i\n",oscl,oscl);
	}
//////												  
																}
if(libc_isalpha(*scl)!=0 && nscl!='-' && oscl!='-'){vect->table[a]=*scl;a++;}	

co++; scl++;
			}
			
z=vect->pos[i-1]+1;
c=s[z];

vect->table_length=a;
i=add_tablae_symbol(vect,c,z,i);
		
p++;

free_ptr(scl);
free(bf);
return i;
}
