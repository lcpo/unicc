///---------------------------------------------------------------------
bool v_char_exists(s_vect* vect){ 
int i=0;
while(i<vect->length){if(vect->tp[i]==V_CHAR){return true;} i++;}
return false;		
	}
///---------------------------------------------------------------------
bool v_point_exists(s_vect* vect){
int i=0;
while(i<vect->length){if(vect->tp[i]==V_POINT){return true;} i++;}
return false;		
	}
///---------------------------------------------------------------------
bool vs_classes_exists(s_vect* vect){
int i=0;
while(i<vect->length){if(vect->tp[i]==VS_CLASS){return true;} i++;}
return false;		
	}
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
	scl[n]=1;n++;p++;oc=1;p++;p++;nc=*p;
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

while(*p!=0){
	if(oc!='\\' && *p==tag_start){ns++;}
	if(oc!='\\' && *p==tag_end){ne++;}
	p++;
	p--;oc=*p;p++; 
	p++;nc=*p;p--;
	if(*p==0){break;}
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
tb->rep=1;
tb->length=0;
tb->tag_start=tag_start;
tb->tag_end=tag_end;
return;
																	}

///---------------------------------------------------------------------
int preg_add(s_vect* vect,char ch,int pos, int i, vect_type type,vect_type old_type){
//if(ch!=0){
vect->c[i]=ch;
vect->pos[i]=pos;
vect->tp[i]=type;
vect->otp[i]=old_type;
i++;
//}	
	return i;
	}
///---------------------------------------------------------------------
void point_reindex(s_vect* vect,ch_tab* tb,char* s){
int i=0,fl=0;

while(i<vect->length){
if(vect->tp[i]==V_CHAR && vect->tp[i+1]==V_POINT){printf("pfl:reindex-next\n");vect->c[i+1]=s[vect->pos[i]+1];vect->pos[i+1]=vect->pos[i]+1;	vect->tp[i+1]=V_CHAR;vect->otp[i+1]=V_POINT;}	

if(vect->tp[i]==V_CHAR && vect->tp[i+1]==VS_CLASS){

fl=is_tablae_symbol(tb,vect->c[i+1],s[vect->pos[i]+1]);
if(tb->flag_denial[vect->c[i+1]]==0){
if(fl>0){vect->c[i+1]=s[vect->pos[i]+1]; vect->pos[i+1]=vect->pos[i]+1;vect->tp[i+1]=V_CHAR;vect->otp[i+1]=VS_CLASS;}else{vect->c[i+1]='#';vect->pos[i+1]=0;vect->tp[i+1]=0;vect->otp[i+1]=0;}
	}else{
if(fl<1){vect->c[i+1]=s[vect->pos[i]+1]; vect->pos[i+1]=vect->pos[i]+1;vect->tp[i+1]=V_CHAR;vect->otp[i+1]=VS_CLASS;}else{vect->c[i+1]='@';vect->pos[i+1]=0;vect->tp[i+1]=0;vect->otp[i+1]=0;}
		}

		}
	i++;
	}
	
fl=0;
while(i>0){
	if(vect->tp[i]==V_CHAR && vect->tp[i-1]==V_POINT){printf("pfl:reindex-prev\n");
		vect->c[i-1]=s[vect->pos[i]-1];
		vect->pos[i-1]=vect->pos[i]-1;
		vect->tp[i-1]=V_CHAR;
		vect->otp[i-1]=V_POINT;
		}

//printf("%i|%i\n",vect->tp[i],vect->tp[i-1]);	
if(vect->tp[i]==V_CHAR && vect->tp[i-1]==VS_CLASS){
fl=is_tablae_symbol(tb,vect->c[i-1],s[vect->pos[i]-1]);
//printf("fl=%i\n",fl);
if(tb->flag_denial[vect->c[i-1]]==0){
if(fl>0){
	vect->c[i-1]=s[vect->pos[i]-1]; 
	vect->pos[i-1]=vect->pos[i]-1;
	vect->tp[i-1]=V_CHAR;
	vect->otp[i-1]=VS_CLASS;
	}else{vect->c[i-1]='#';vect->pos[i-1]=0;vect->tp[i-1]=0;vect->otp[i-1]=0;}
	}else{
if(fl<1){
	vect->c[i-1]=s[vect->pos[i]-1];
	vect->pos[i-1]=vect->pos[i]-1;
	vect->tp[i-1]=V_CHAR;
	vect->otp[i-1]=VS_CLASS;
	}else{vect->c[i-1]='@';vect->pos[i-1]=0;vect->tp[i-1]=0;vect->otp[i-1]=0;}
		}
		}		

	i--;
	}
	
return;	
	}
///---------------------------------------------------------------------
void free_vect(s_vect* vect){
free_ptr(vect->pos);
free_ptr(vect->tp);
free_ptr(vect->otp);
free_ptr(vect->c);
free_ptr(vect);
return;	
	}
