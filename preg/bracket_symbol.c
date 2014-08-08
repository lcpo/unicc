///TODO: optimization of special
/*!
 * выделить токен из строки паттерна
 * модифицировать строку паттерна
 */ 
char end_step[]={'(','[','{','?','!','.','+','*'};
///---------------------------------------------------------------------
char end_step_others[]={')','}',']',' ','|',','};
///---------------------------------------------------------------------
static int is_end_step(char ch){int i=0;for(;i<8;i++){if(ch==end_step[i]){return ch;}}return -1;}
///---------------------------------------------------------------------
static int is_end_step_others(char ch){int i=0;for(;i<6;i++){if(ch==end_step_others[i]){return ch;}}return -1;}
///---------------------------------------------------------------------
int is_tablae_symbol(ch_tab* tb,int n,char ch){
int ret=0,co=0,tblen=libc_strlen(tb->table[n]); 
while(co<tblen){if(tb->table[n][co]==ch){ret++;break;}co++;}
	return ret;
														}
///---------------------------------------------------------------------
int add_tablae_symbol(s_vect* vect,ch_tab* tb, int tbn,char ch, int z, int i){

int fl=is_tablae_symbol(tb,tbn,ch);
if(tb->flag_denial[tbn]==0){
if(fl>0){vect->c[i]=ch;vect->pos[i]=z;vect->tp[i]=V_CHAR;vect->otp[i]=VS_CLASS;i++;}else{vect->c[i]=-1;vect->pos[i]=0;vect->tp[i]=0;vect->otp[i]=0;i++;}
	}else{
if(fl<1){vect->c[i]=ch;vect->pos[i]=z;vect->tp[i]=V_CHAR;vect->otp[i]=VS_CLASS;i++;}else{vect->c[i]=-2;vect->pos[i]=0;vect->tp[i]=0;vect->otp[i]=0;i++;}
		}
return i;	
	}

///------------------------------------------------------------

char* parce_tag(char* p,char tag_start, char tag_end){
int plen=libc_strlen(p);
char* scl=malloc(plen);
int n=0,fl=1;
char oc='\0',c=*p,nc=*p++; p--;

if(*p!=tag_start){ 
while(fl!=0){
	p++;
	p--;oc=*p;p++; 
	p++;nc=*p;p--;
	if(oc!='\\' && *p==tag_start){fl=0;break;}
	if(*p=='\0'){fl=0;break;}

	}
}

while(*p!='\0'){
	//printf("->%c\n",*p);
p--;oc=*p;p++;
p++;nc=*p;p--;
if(*p=='\\' && nc=='\\'){
	scl[n]=18;n++;p++;oc=18;p++;p++;nc=*p;
	}else if(oc!='\\' && *p==tag_start){
		scl[n]=*p;n++;
		p--;oc=*p;p++;p++;nc=*p;p--;
		}//else if(oc!='\\' && *p==' '){p--;oc=*p;p++;p++;nc=*p;p--;}
		else if(oc!='\\' && *p==tag_end){scl[n]=*p;break;}else if(p=='\0'){
printf("error: no closing character '%c'!!!\n",tag_end); return scl;
}else{scl[n]=*p;n++;}
p++;
				}
				p++;
return scl;	
													}
///------------------------------------------------------------
int tag_count(char *p, char tag_start, char tag_end){
int ns=0,ne=0;
char oc='\0',c=*p,nc=*p++; p--;

while(nc!=0){
	if(oc!='\\' && *p==tag_start){ns++;}
	if(oc!='\\' && *p==tag_end){ne++;}
	p++;
	p--;oc=*p;p++; 
	p++;nc=*p;p--;
	if(nc==0){break;}


	}
	if(ns!=ne){printf("warning :no end tag or no start tag!!!\n");}
	//printf("<==%i\n",ne);
//	p=p-ne;
	return ne;	
	}
///------------------------------------------------------------
void table_init(char* p, ch_tab* tb, char tag_start, char tag_end){ 
tb->table_count=tag_count(p,tag_start,tag_end);
tb->table=malloc(tb->table_count);
tb->table_src=malloc(tb->table_count);
tb->flag_denial=malloc(tb->table_count);
tb->rep=17;
tb->length=0;
tb->tag_start=tag_start;
tb->tag_end=tag_end;
return;
									}


///------------------------------------------------------------
char* bracket_string(ch_tab *tb,char* scl){
int plen=libc_strlen(scl)+2;				
int a=0,fl1=0,co=0,n=0,z=0;
char ooscl='\0',oscl='\0',nscl='\0';
char* table=malloc(1024);
tb->flag_denial[tb->length]=0;
scl++;
while(*scl!=']'){
scl--; oscl=*scl; scl++;
scl++; nscl=*scl; scl--;
if(oscl!='\\' && *scl==' '){scl++;continue;}
if(oscl!='\\' && *scl=='^'){tb->flag_denial[tb->length]=1;scl++;continue;}
if(oscl!='\\' && *scl==18){table[a]='\\';a++;}
if(oscl=='\\' && *scl==18){table[a]=18;	a++;}
if(oscl=='\\' && *scl=='-' && libc_isalpha(nscl)!=0){table[a]=nscl;a++;}
//if(oscl=='\\' && *scl=='-' && libc_isdigit(nscl)!=0){table[a]=nscl;a++;}
if(oscl=='\\' && *scl=='-'){table[a]=*scl;a++;}
if(oscl=='\\' && (*scl=='[' || *scl==']')){table[a]=*scl;a++;}
if(oscl!='\\' && (*scl=='[' || *scl==']')){printf("error: character is not shielded '%c' !!!\n",*scl);return scl;}

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

char* bracket_table(char* p,ch_tab *tb){
int i=0,plen=libc_strlen(p),psmes=0,psum=0; 
char* scl,bf[1];

tb->table_count=tag_count(p,tb->tag_start,tb->tag_end);
	printf("=>%i\n",tb->table_count);

while(i<tb->table_count){
scl=parce_tag(p,tb->tag_start,tb->tag_end);
tb->table[tb->length]=bracket_string(tb,scl);
tb->table_src[tb->length]=scl;
psmes=libc_strpos(p,scl)+libc_strlen(scl);
p=p+psmes;
psum=psum+psmes;
tb->length++;
i++;
						}
printf("1===%s|\n",p);
p=p-psum;
printf("2===%s|\n",p);

bf[0]=tb->rep;
bf[1]='\0';
char* out;
	printf("=>%s\n",p);
i=0;
while(i<tb->table_count){
	printf("s->%s\n",tb->table_src[i]);
	printf("r->%s\n",bf);
p=libc_string_replace(p,tb->table_src[i],bf);
//free(p);
//p=out;
free(tb->table_src[i]);
	i++;
						}

return p;	
										}
///------------------------------------------------------------	

/*
static int bracket_symbol(s_vect* vect, char* s, char* p,char oc,char nc,char c, char end, int i){
	p++;
int plen=libc_strlen(p);
char* scl=malloc(plen);
int n=0,z=0,co=0;
vect->flag_denial=0;
//printf("==%s\n",p);
while(*p!='\0'){
p--;oc=*p;p++;
p++;nc=*p;p--;

if(*p=='\\' && nc=='\\'){
	scl[n]=18;n++;p++;oc=18;p++;p++;nc=*p;
	}else if(oc!='\\' && *p=='^'){
		vect->flag_denial=1;p--;oc=*p;p++;p++;nc=*p;p--;
		}else if(oc!='\\' && *p==' '){p--;oc=*p;p++;p++;nc=*p;p--;}else if(oc!='\\' && *p==']'){break;}else 
		if(p=='\0'){printf("error: no closing character ']'!!!\n"); return i;
//goto LABEL_EXIT_WHILE;
}else{scl[n]=*p;n++;}
p++;
				}
printf("==%s\n",p);				
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
	
if(*scl=='-' && libc_isdigit(nscl)!=0 && libc_isdigit(oscl)!=0){
if((oscl-'0')<(nscl-'0')){
	for(z=(oscl-'0');z<=(nscl-'0');z++){vect->table[a]=z+'0';a++;}
	}else{
		for(z=(nscl-'0');z<=(oscl-'0');z++){vect->table[n]=z+'0';a++;}
		}
															   }
if(libc_isdigit(*scl)!=0 && nscl!='-' && oscl!='-'){vect->table[n]=*scl;a++;}
														   
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
vect->table[a]='\0';
vect->table_length=a;
i=add_tablae_symbol(vect,c,z,i);
//printf("%s\n",vect->table);		
p++;p++;
printf("==%s\n",p);
free_ptr(scl);
return i;
}
*/
