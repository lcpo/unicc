
#include "libpreg.h"
///---------------------------------------------------------------------
#include "libpreg.c"
///---------------------------------------------------------------------
#include "bracket.c"
///---------------------------------------------------------------------
/*
int step_symbol(int flag,s_vect* vect, char* s, char* p,char oc,char nc,char c, char end, int i){
int plen=libc_strlen(p);
char* bf=malloc(plen);

int z=vect->pos[i-1],n=0;
if(*p==s[z+1] && vect->otp[i-1]==V_CHAR){free(bf);return i;}
if(*p!=s[z+1] && vect->otp[i-1]==V_CHAR){
if(flag==0){vect->c[i]=0;vect->pos[i]=0;vect->tp[i]=0;vect->otp[i]=0;i--;}
if(flag==1){p++;travel3(p,oc,c,nc);i--;} 
free(bf); return i;
}

//------------------
if(vect->otp[i-1]==V_POINT){
	printf("1|%c\n",oc);
if(nc=='?' && c!='\\'){
p++;
n=0; int fl=0;
while(*p!=0){
	if(*p!=0){bf[n]=*p;n++;p++;}else{fl=1;break;}}

do{
vect->c[i]=s[vect->pos[i-1]+1];vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;vect->otp[i]=V_POINT;i++;z++;
}while(libc_strncmp(s+z,bf,n)!=0 && s[z]!=end && s[z]!=0);
	
}else{

n=0; int fl=0; 
printf("==%s\n",p);
while(*p!=0){if(*p!=0){bf[n]=*p;n++;p++;}else{fl=1;break;}}
do{
vect->c[i]=s[vect->pos[i-1]+1];vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;vect->otp[i]=V_POINT;i++;z++;
}while(libc_substr_count(s+(z+1),bf)>0 && s[z+n]!=end && s[z]!=0);

	}

free(bf);

return i;
							}

									
free(bf);		
return i;
																		}

//[] = 1
//.	 = 2
//{} = 3
//() = 4

*/
///---------------------------------------------------------------------
void print_vect(s_vect* vect){
int i=0;
while(i<vect->length){
printf("%i|pos=%i|code=%c:%i|type=%i|old_type=%i\n",i,vect->pos[i],vect->c[i],vect->c[i],vect->tp[i],vect->otp[i]);
i++;
					 }
printf("%s\n",vect->c);	
return;
	}
///---------------------------------------------------------------------
const char break_symbols[]={'*','+',1,2,3,4};
int isbreak(int ch){
int i;
for(i=0;i<5;i++){
if(break_symbols[i]==ch){return 1;}	
				}
return 0;		
					}
///---------------------------------------------------------------------
void gainvalknownbreak(char* bf,char* p){
int n=0; int fl=0;
while(*p!=0){
	if(*p!=0 && isbreak(*p)==0){bf[n]=*p;n++;p++;}else{break;}
	}

return;
}	
///---------------------------------------------------------------------
int class_pos(ch_tab* tb,int tbid,char* s){ //получить позицию класса относительно другого неопределенного символа.
	
	}
///---------------------------------------------------------------------


s_vect* preg(char* pt,char* str){
int strlen=libc_strlen(str),
patlen=libc_strlen(pt);
//----------------------
s_vect* vect=malloc(1);
vect->pos=malloc(strlen);
vect->tp=malloc(strlen);
vect->otp=malloc(strlen);
vect->c=malloc(strlen);
//----------------------
s_vect* new_vect=malloc(1);	
new_vect->pos=malloc(strlen);
new_vect->tp=malloc(strlen);
new_vect->otp=malloc(strlen);
new_vect->c=malloc(strlen);
//----------------------
ch_tab* tb=malloc(1);
tb->table=malloc(1024);
tb->table_src=malloc(1024);
tb->flag_denial=malloc(1024);
tb->rep=1;
tb->length=0;
tb->tag_start='[';
tb->tag_end=']';
//----------------------

int i=0,z=0,n=0,co=0,flag_esc=0,count_esc=0,flag_start=0,flag_end=0,flag_star=0,flag_plus=0,
old_i=0,old_z=0,cure=0,count17=0;
char *p=malloc(patlen),*np=malloc(patlen),*s=malloc(strlen),*bf=malloc(patlen);
libc_strcpy(s,str); 
libc_strcpy(np,pt);

tb->table_count=tag_count(np,'[',']'); 
np=bracket_table(np,tb);
char oc='\0',end='\n',e='\0',c=*np,nc=*np++; np--;

while (*np!=e){
travel3(np,oc,c,nc);
switch(*np){
	
case '\\':{
if(flag_esc==0){flag_esc=1;}else{if(c==s[z]){flag_esc=0;}z++;}
p[n]=*np;n++;
np++;break;
}
case '^':{
if(flag_esc==1){if(c==s[z]){flag_esc=0;p[n]=*np;n++;}z++;}else{flag_start=1;}
np++;break;
}
case '$':{
if(flag_esc==1){if(c==s[z]){flag_esc=0;p[n]=*np;n++;}z++;}else{flag_end=1;}
np++;break;
}
default:{p[n]=*np;n++;np++;break;}	
	}
	
			 }
//!-----------------------------
n=0; z=0;
oc='\0',end='\n',e='\0',c=*p,nc=*p++; p--;
//!-----------------------------
while (*p!=e){
travel3(p,oc,c,nc);
point_reindex(vect,tb,s);
switch(*p){
//----------------------------------------------------------------------
case '\\':{if(flag_esc==0){flag_esc=1;}else{
if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
if(c!=s[z] && v_char_exists(vect)==true){printf("Report 1: no exists - \"%c\"!!! \n",c);return vect;}
if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
}p++;break;}
//----------------------------------------------------------------------
case '.':{
	if(flag_esc==1){
		if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
		printf("%c,%c",s[z],c);
		if(c!=s[z] && v_char_exists(vect)==true){printf("Report 2: no exists - \"%c\"!!! \n",c);return vect;}
		if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
		}else{
if(cure==0){
if(vect->tp[i+1]==V_CHAR && s[z]!=end){printf("pfl:next\n");i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;break;}else
if(vect->tp[i-1]==V_CHAR && s[z]!=end){printf("pfl:prev\n");i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;break;}else
{printf("pfl:null\n");i=preg_add(vect,2,-1,i,V_POINT,V_NULL);z++;p++;break;}
			}
			 }
	
	p++;break;
	}
//----------------------------------------------------------------------
case '^':{
	if(flag_esc==1){
		if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
		if(c!=s[z] && v_char_exists(vect)==true){printf("Report 3: no exists - \"%c\"!!! \n",c);return vect;}
		if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
		}
		p++;break;}
//----------------------------------------------------------------------
case '$':{if(flag_esc==1){
	if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
	if(c!=s[z] && v_char_exists(vect)==true){printf("Report 4: no exists - \"%c\"!!! \n",c);return vect;}
	if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
	}
	p++;break;}
//----------------------------------------------------------------------
case 'b':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 5: no exists - \"%c\"!!! \n",c);return vect;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}	
//----------------------------------------------------------------------
case 'B':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 6: no exists - \"%c\"!!! \n",c);return vect;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}
//----------------------------------------------------------------------
case 'd':{if(flag_esc==0){
	if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
	if(c!=s[z] && v_char_exists(vect)==true){printf("Report 7: no exists - \"%c\" \"%c\"!!! \n",c,s[z]);return vect;}
	if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}
	}
	p++;break;
	}
//----------------------------------------------------------------------
case 'D':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 8: no exists - \"%c\"!!! \n",c);return vect;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}
//----------------------------------------------------------------------
case 's':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 9: no exists - \"%c\"!!! \n",c);return vect;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}
//----------------------------------------------------------------------
case 'S':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 10: no exists - \"%c\"!!! \n",c);return vect;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}
//----------------------------------------------------------------------
case 'w':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 11: no exists - \"%c\"!!! \n",c);return vect;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}
//----------------------------------------------------------------------
case 'W':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 12: no exists - \"%c\"!!! \n",c);return vect;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}	
//----------------------------------------------------------------------
case '*':{
	if(flag_esc==1){
	if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
	if(c!=s[z] && v_char_exists(vect)==true){printf("Report 13: no exists - \"%c\"!!! \n",c);return vect;}
	if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
	}else{
		if(oc=='.'){flag_star=1;}else if(oc==1){flag_star=1;}else{flag_star=0;}
		i=preg_add(vect,*p,-1,i,V_STAR,V_NULL);p++; break;}p++;break;} 
//----------------------------------------------------------------------
case '+':{
if(flag_esc==1){
if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
if(c!=s[z] && v_char_exists(vect)==true){printf("Report 14: no exists - \"%c\"!!! \n",c);return vect;}
if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
}else{
	if(oc=='.'){flag_plus=1;}else if(oc==1){flag_plus=1;}else{flag_plus=0;}
	i=preg_add(vect,*p,-1,i,V_PLUS,V_NULL);p++;break;}p++;break;}
//----------------------------------------------------------------------
case '?':{
	if(flag_esc==1){
		if(c!=s[z] && v_char_exists(vect)==true){printf("Report 15: no exists - \"%c\"!!! \n",c);return vect;}
		if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
		if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
		}else{i=preg_add(vect,*p,-1,i,V_QUEST,V_NULL);p++;break;}
	p++;break;
	} 
//----------------------------------------------------------------------
case '{':{if(flag_esc==1){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 16: no exists - \"%c\"!!! \n",c);return vect;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}}p++;break;}
//----------------------------------------------------------------------
case '[':{if(flag_esc==1){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 17: no exists - \"%c\"!!! \n",c);return vect;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}}p++;break;}
//----------------------------------------------------------------------

///!!!!!!!!!!!!!!!!!!!!!!!!!!

case 1:{
	if(flag_esc==1){
		if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
		if(c!=s[z] && v_char_exists(vect)==true){printf("Report 18: no exists - \"%c\"!!! \n",c);return vect;}
		if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
		}else{
		//----------------	
		if(v_char_exists(vect)==false){
		int fltbco=0,fltb=0,z0=0,z1=0;
		z=0;
while(*p==1){z0++;p++;}
p=p-z0;fltbco=count17;

while(fltb<z0){
if(tablae_symbol(tb,fltbco,s[z])==1){fltb++;fltbco++;}

if(fltb==z0 && fltbco==1){i=add_tablae_symbol(vect,tb,fltbco-1,s[z],z,i);break;}
if(fltb==z0 && fltbco>1){i=add_tablae_symbol(vect,tb,fltbco-1,s[z],z,i);break;}
printf("fltbco=%i|fltb=%i|z=%i|s=%c\n",fltbco,fltb,z,s[z]);
z++;z1++;
}

p++;break;
									  }	
		//----------------
if(cure==0){
if(vect->tp[i+1]==V_CHAR && s[z]!=end){i=add_tablae_symbol(vect,tb,count17,s[z],z,i);z++;count17++;p++;break;}else
if(vect->tp[i-1]==V_CHAR && s[z]!=end){i=add_tablae_symbol(vect,tb,count17,s[z],z,i);z++;count17++;p++;break;}else
{printf("cfl1:null\n");
	i=preg_add(vect,1,count17,i,V_CLASS,V_NULL);z++;count17++;p++;break;}
			} 
			 }
count17++;p++;
break;
		}	
//----------------------------------------------------------------------
case '(':{if(flag_esc==1){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 18: no exists - \"%c\"!!! \n",c);return vect;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}}p++;break;}
//----------------------------------------------------------------------
default:{
	if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
	if((flag_star!=0 || flag_plus!=0) && c!=s[z]){z=libc_chrpos(s,c);}	
	if(c!=s[z] && v_char_exists(vect)==true && (flag_star==0 && flag_plus==0)){printf("Report 19: no exists - \"%c\"!!! \n",c);return vect;}
	if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}
	p++;break;
	}
//----------------------------------------------------------------------
				}
vect->length=i;
if(*p==0 && v_char_exists(vect)==false && flag_start==0 && flag_end==0){
	if(vect->tp[i-1]==V_POINT){printf("pfl:reback1\n");z=0; p=p-(patlen-1);i=0; i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;}
	if(vect->tp[i-1]==V_CLASS){printf("cfl:reback1\n");z=0; p=p-(patlen-1);i=0; count17=0;i=add_tablae_symbol(vect,tb,count17,s[z],z,i);z++;p++;}
	cure++;
																	   }else
																	   
if(*p==0 && v_char_exists(vect)==false && flag_start==1 && flag_end==0){   
	if(vect->tp[i-1]==V_POINT){printf("pfl:reback2\n");p=p-(patlen-1);z=0;i=0;i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;}
	if(vect->tp[i-1]==V_CLASS){printf("cfl:reback2\n");p=p-(patlen-1);z=0;i=0;count17=0;i=add_tablae_symbol(vect,tb,count17,s[z],z,i);z++;p++;}
	cure++;
																	   }else
																	   
if(*p==0 && v_char_exists(vect)==false && flag_start==0 && flag_end==1 &&cure<10){
	z=strlen-1;  
	//printf("===%c|p==%c|i==%i|p==%s\n",s[z],*p,i,p);
	if(vect->tp[i-1]==V_POINT){printf("pfl:reback3\n");i--;i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);}
	if(vect->tp[i-1]==V_CLASS){printf("cfl:reback3\n");count17--;i--;i=add_tablae_symbol(vect,tb,count17,s[z],z,i);}
	cure++;
																       }else
																       
if(*p==0 && flag_star==1 && cure==0){
printf("flag_star\n");	
if(vect->tp[i-1]==V_POINT){i--; z=strlen-1;i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);}
if(vect->tp[i-1]==V_CLASS){i--; count17--; z=strlen-1;i=add_tablae_symbol(vect,tb,count17,s[z],z,i);}
																       }else
if(*p==0 && flag_plus==1 && cure==0){
printf("flag_plus\n");	
if(vect->tp[i-1]==V_POINT){i--; z=strlen-1;i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);}
if(vect->tp[i-1]==V_CLASS){i--; count17--; z=strlen-1;i=add_tablae_symbol(vect,tb,count17,s[z],z,i);}
																       }else 
if(*p==0 && flag_end==1){
printf("flag_end\n");	
if(vect->tp[i-1]==V_POINT){i--; z=strlen-1;i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);}
if(vect->tp[i-1]==V_CLASS){i--; count17--; z=strlen-1;i=add_tablae_symbol(vect,tb,count17,s[z],z,i);}																		   
																		   
																		   }																       																       
																       
//!TODO: ^...$														


}
point_reindex(vect,tb,s);
////////////////////////////////////////////////////////////////////////////////////////
print_vect(vect);
free(p);
////////////////////////////////////////////////////////////////////////////////////////
p=vect->c;
printf("===%s\n",p);
n=0; z=0; i=0;
oc='\0',end='\n',e='\0',c=*p,nc=*p++; p--;
int flag_quest=0;
count17=0;
while (*p!=e){
travel3(p,oc,c,nc);
//point_reindex(vect,tb,s);
//if(vect->otp[n]==V_CLASS){count17++;}
switch(*p){
case '?':{p++;n++;break;}

case '*':{
	//printf("%c|otpold:%i|tpold:%i|otpnew:%i|tpnew:%i|\n",*p,vect->otp[n-1],vect->tp[n-1],vect->otp[n+1],vect->tp[n+1]);
p++;
if(nc=='?' && c!='\\'){p++;flag_quest=1;}
gainvalknownbreak(bf,p); 
printf("bf=%s\n",bf);

//!************************************************************
if(vect->otp[n-1]==V_POINT && vect->tp[n-1]==V_CHAR && vect->tp[n+1]==V_CHAR){ printf("sfl1\n");

if(flag_quest==1){
do{
new_vect->c[i]=s[new_vect->pos[i-1]+1]; new_vect->pos[i]=new_vect->pos[i-1]+1; new_vect->tp[i]=V_CHAR; new_vect->otp[i]=V_POINT;i++;z++;
}while(libc_strncmp(s+z,bf,n)!=0 && s[z]!=end && s[z]!=0);
n++;n++;break;
				}else{
do{
new_vect->c[i]=s[new_vect->pos[i-1]+1]; new_vect->pos[i]=new_vect->pos[i-1]+1; new_vect->tp[i]=V_CHAR; new_vect->otp[i]=V_POINT;i++;z++;
}while(libc_substr_count(s+(z+1),bf)>0 && s[z+n]!=end && s[z]!=0);
n++;break;
					}
													}
//!************************************************************													
if(vect->otp[n-1]==V_NULL && vect->tp[n-1]==V_CHAR && vect->tp[n+1]==V_CHAR){ printf("sfl2\n");

if(flag_quest==1){
do{
if(s[new_vect->pos[i-1]+1]==*p){	
new_vect->c[i]=s[new_vect->pos[i-1]+1]; new_vect->pos[i]=new_vect->pos[i-1]+1; new_vect->tp[i]=V_CHAR; new_vect->otp[i]=V_NULL;i++;z++;
}else{
new_vect->c[i]=-1; new_vect->pos[i]=-1; new_vect->tp[i]=V_CHAR; new_vect->otp[i]=V_NULL;i++;z++;	
	}
}while(libc_strncmp(s+z,bf,n)!=0 && s[z]!=end && s[z]!=0);
n++;n++;break;	
				}else{
do{
new_vect->c[i]=s[new_vect->pos[i-1]+1]; new_vect->pos[i]=new_vect->pos[i-1]+1; new_vect->tp[i]=V_CHAR; new_vect->otp[i]=V_NULL;i++;z++;
}while(libc_substr_count(s+(z+1),bf)>0 && s[z+n]!=end && s[z]!=0);
n++;break;
					}
													}													
//!************************************************************													
if(vect->otp[n-1]==V_CLASS && vect->tp[n-1]==V_CHAR && vect->tp[n+1]==V_CHAR){ printf("sfl3\n");

if(flag_quest==1){
do{
i=add_tablae_symbol(new_vect,tb,count17,s[z],z,i);z++;
}while(libc_strncmp(s+z,bf,n)!=0 && s[z]!=end && s[z]!=0);
	count17++;
	n++;n++;break;
				}else{
do{
i=add_tablae_symbol(new_vect,tb,count17,s[z],z,i);z++;
}while(libc_substr_count(s+(z+1),bf)>0 && s[z+n]!=end && s[z]!=0);
count17++;
n++;break;
					}
													}
//!************************************************************

if(vect->otp[n-1]==V_CLASS && vect->tp[n-1]==V_CHAR && vect->tp[n+1]!=V_CHAR){
int r=0;

printf("ex|table=%s|flag_denial=%i|%c|\n",tb->table[vect->pos[n+1]],tb->flag_denial[vect->pos[n+1]],s[z]);
printf("%i",tablae_symbol(tb, vect->pos[n+1],s[z]));
//создать динамический подставляемый буфер неопределенной длинны
//и вести сравнение с ним.

																			 }
//!************************************************************	
	n++;p++;break;
	}
case '+':{p++;n++;break;}	
default:{
	if(c!=s[z] && v_char_exists(new_vect)==false){z=libc_chrpos(s,c);}
	if(c!=s[z] && v_char_exists(new_vect)==true){printf("Report 20: no exists - \"%c\"!!! \n",c);return vect;}
	if(c==s[z]){i=preg_add(new_vect,s[z],z,i,V_CHAR,V_NULL);z++;}	
	p++;n++;break;}	
	}
new_vect->length=i;
}
free(s);
free(bf);
return new_vect;
	}
//!------------------------------------------------------------

