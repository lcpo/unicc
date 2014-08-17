
#include "libpreg.h"
///---------------------------------------------------------------------
#include "libpreg.c"
///---------------------------------------------------------------------
#include "bracket.c"
///---------------------------------------------------------------------


//[] = 1
//.	 = 2
//{} = 3
//() = 4


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
const char break_symbols[]={'*','+','?',1,2,3,4};
int isbreak(int ch){
int i;
for(i=0;i<6;i++){
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
int count_char_table(ch_tab* tb,char* s,int id,char end){
	int co=0,i=0;
	while(*s!=0 && *s!=end){
		if(is_tablae_symbol(tb,id,*s)==1){co++;}
		s++;i++;}
		s=s-i;
	return co;
															}
///---------------------------------------------------------------------
void wavy_string(ch_stp* wb,char* wsk){
uni wlen=libc_strlen(wsk);
char* bf1=malloc(wlen),*np=malloc(wlen), *bf2=malloc(wlen),oc='\0',c=*wsk,nc=*wsk++; wsk--;
int n=0,fl=0,co=1,pos=libc_strpos(wsk,",");
while(*wsk){
travel3(wsk,oc,c,nc);	
if(oc=='{' && c==','){np[n]=3;n++;np[n]=c;n++;}else
if(c==',' && nc=='}'){np[n]=c;n++;np[n]=3;n++;}else
{np[n]=c;n++;}
	wsk++;
	}
n=0; oc='\0'; c=*np; nc=*np++; np--;



while(*np!='\0'){
travel3(np,oc,c,nc);
if(*np==','){fl=1;co++;np++;n=0;}

if(fl==0){
if(*np=='{'){np++;}
if(libc_isdigit(*np)!=0){bf1[n]=*np;n++;}
if(*np==3){bf1[n]='-';n++;bf1[n]='2';n++;}	
	}else{
if(*np=='}'){np++;}		
if(libc_isdigit(*np)!=0){bf2[n]=*np;n++;}
if(*np==3){bf2[n]='-';n++;bf2[n]='2';n++;}
		}
np++;
					}
if(pos==-1){bf2="-1";}
/*
printf("bf1=%s\n",bf1);
printf("bf2=%s\n",bf2);	
printf("//---------------------------\n");				
 */
wb->min[wb->length]=libc_stoi(bf1);
wb->max[wb->length]=libc_stoi(bf2);
wb->count[wb->length]=co;
 free(np);
 free(bf1);
 free(bf2);
return;
	}															
///---------------------------------------------------------------------
void add_poscharto_table(ch_tab* tb,char* s,int id,char end){
int co=count_char_table(tb,s,id,end),z=0,i=0;
tb->pos[id]=malloc(co);
while(*s!=0 && *s!=end){
if(is_tablae_symbol(tb,id,*s)==1){tb->pos[id][z]=i;z++;}
s++;i++;
}
s=s-i;
return;	
	}

s_vect* preg(char* pt,char* str){
int strlen=libc_strlen(str),patlen=libc_strlen(pt),i=0,z=0,n=0,co=0,count_esc=0,
flag_esc=0,flag_start=0,flag_end=0,flag_star=0,flag_plus=0,flag_quest=0,flag_step=0,
old_i=0,old_z=0,old_n,cure=0,count17=0;
char *p=malloc(patlen),*np=malloc(patlen),*s=malloc(strlen),*bf=malloc(patlen),oc='\0',end='\n',e='\0',c,nc;
libc_strcpy(s,str); 
libc_strcpy(np,pt);
//---------------------
s_vect* vect=malloc(1); vect->pos=malloc(strlen); vect->tp=malloc(strlen); vect->otp=malloc(strlen); vect->c=malloc(strlen);
//----------------------
s_vect* new_vect=malloc(1); new_vect->pos=malloc(strlen); new_vect->tp=malloc(strlen); new_vect->otp=malloc(strlen); new_vect->c=malloc(strlen);
//---------------------
ch_tab* tb=malloc(1);
tb->table=malloc(256);
tb->pos=malloc(256);
tb->flag_denial=malloc(256);
tb->length=0;
//---------------------
ch_stp* wb=malloc(1);
wb->min=malloc(256);
wb->max=malloc(256);
wb->count=malloc(256);
wb->length=0;

//---------------------
//tb->table_count=tag_count(np,'[',']'); 
//np=bracket_table(np,tb,'[',']');
c=*np,nc=*np++; np--;
//---------------------
printf("%s\n",np);
//!------------------------------------------------------------
//!~ preg_compile - no sapport utf8
//!------------------------------------------------------------
while (*np!=e){
travel3(np,oc,c,nc);
switch(*np){
case '\\':{if(flag_esc==0){flag_esc=1;}else{if(c==s[z]){flag_esc=0;}z++;}p[n]=*np;n++;np++;break;}
case '^':{if(flag_esc==1){if(c==s[z]){flag_esc=0;p[n]=*np;n++;}z++;}else{flag_start=1;}np++;break;}
case '*':{if(flag_esc==0){flag_star=1;}p[n]=*np;n++;np++;break;}
case '+':{if(flag_esc==0){flag_plus=1;}p[n]=*np;n++;np++;break;}
case '?':{if(flag_esc==0){flag_quest=1;}p[n]=*np;n++;np++;break;}
case '[':{if(flag_esc==0){p[n]=1;n++;
	char *bsk=parce_tag(np,*np,']');
	uni bsk_len=libc_strlen(bsk);
	tb->table[tb->length]=bracket_string(tb,bsk);
	add_poscharto_table(tb,s,tb->length,end);
	//printf("|%s|==|%s|\n",bsk,tb->table[tb->length]);
	free(bsk);
	np=np+bsk_len,tb->length++;
	break;
}else{p[n]=*np;n++;np++;break;}}
case '.':{if(flag_esc==0){p[n]=2;n++;}else{p[n]=*np;n++;np++;break;}}
case 'w':{if(flag_esc==1){n--;p[n]=1;
	tb->table[tb->length]=bracket_string(tb,"[A-Za-z0-9\\_]");
	add_poscharto_table(tb,s,tb->length,end);
	//printf("w==%s\n",tb->table[tb->length]);
		tb->length++;np++;flag_esc=0;
		break;
}else{p[n]=*np;n++;np++;break;}}
case 'W':{if(flag_esc==1){n--;p[n]=1;
	tb->table[tb->length]=bracket_string(tb,"[^A-Za-z0-9\\_]");
	add_poscharto_table(tb,s,tb->length,end);
	//printf("W==%s\n",tb->table[tb->length]);
		tb->length++;np++;flag_esc=0;
		break;
}else{p[n]=*np;n++;np++;break;}}
case 'd':{if(flag_esc==1){n--;p[n]=1;
	tb->table[tb->length]=bracket_string(tb,"[0-9]");
	add_poscharto_table(tb,s,tb->length,end);
	//printf("d==%s\n",tb->table[tb->length]);
		tb->length++;np++;flag_esc=0;
		break;
}else{p[n]=*np;n++;np++;break;}}

case 'D':{if(flag_esc==1){n--;p[n]=1;
	tb->table[tb->length]=bracket_string(tb,"[^0-9]");
	add_poscharto_table(tb,s,tb->length,end);
	//printf("D==%s\n",tb->table[tb->length]);
		tb->length++;np++;flag_esc=0;
		break;
}else{p[n]=*np;n++;np++;break;}}

case 's':{if(flag_esc==1){n--;p[n]=1;
	tb->table[tb->length]=bracket_string(tb,"[\\ \t\n\r\f\v]");
	add_poscharto_table(tb,s,tb->length,end);
	//printf("s==|%s|\n",tb->table[tb->length]);
		tb->length++;np++;flag_esc=0;
		break;
}else{p[n]=*np;n++;np++;break;}}

case 'S':{if(flag_esc==1){n--;p[n]=1;
	tb->table[tb->length]=bracket_string(tb,"[^\\ \t\n\r\f\v]");
	add_poscharto_table(tb,s,tb->length,end);
	//printf("S==|%s|\n",tb->table[tb->length]);
		tb->length++;np++;flag_esc=0;
		break;
}else{p[n]=*np;n++;np++;break;}}

case '{':{if(flag_esc==0){flag_step=1;p[n]=3;n++;
	char *wsk=parce_tag(np,*np,'}');
	uni wsk_len=libc_strlen(wsk);
	wavy_string(wb,wsk);
	free(wsk);
	np=np+wsk_len,wb->length++;
	break;
}else{p[n]=*np;n++;np++;break;}}
case '$':{if(flag_esc==1){if(c==s[z]){flag_esc=0;p[n]=*np;n++;}z++;}else{flag_end=1;}np++;break;}
default:{p[n]=*np;n++;np++;break;}	
		   }
	
			 }
//!------------------------------------------------------------
printf("%s\n",p);

n=0; z=0; flag_esc=0;
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
case '*':{
	if(flag_esc==1){
	if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
	if(c!=s[z] && v_char_exists(vect)==true){printf("Report 13: no exists - \"%c\"!!! \n",c);return vect;}
	if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
	}else{i=preg_add(vect,*p,-1,i,V_STAR,V_NULL);p++; break;}
	p++;break;
	} 
//----------------------------------------------------------------------
case '+':{
	if(flag_esc==1){
	if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
	if(c!=s[z] && v_char_exists(vect)==true){printf("Report 14: no exists - \"%c\"!!! \n",c);return vect;}
	if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
	}else{	i=preg_add(vect,*p,-1,i,V_PLUS,V_NULL);p++;break;}
	p++;break;
	}
//----------------------------------------------------------------------
case '?':{
	if(flag_esc==1){
	if(c!=s[z] && v_char_exists(vect)==true){printf("Report 15: no exists - \"%c\"!!! \n",c);return vect;}
	if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
	if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
	}else{i=preg_add(vect,*p,-1,i,V_QUEST,V_NULL);p++;break;}
	p++;break;
	} 
case 1:{
	if(flag_esc==1){
		if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
		if(c!=s[z] && v_char_exists(vect)==true){printf("Report 18: no exists - \"%c\"!!! \n",c);return vect;}
		if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
		}else{
if(cure==0){
if(vect->tp[i+1]==V_CHAR && s[z]!=end){printf("cfl1:null\n");i=add_tablae_symbol(vect,tb,count17,s[z],z,i,0);z++;count17++;p++;break;}else
if(vect->tp[i-1]==V_CHAR && s[z]!=end){printf("cfl1:null\n");i=add_tablae_symbol(vect,tb,count17,s[z],z,i,0);z++;count17++;p++;break;}else
if(c!=s[z] && v_char_exists(vect)==false){int fltbco=0,fltb=0,z0=0;z=0;while(*p==1){z0++;p++;}fltbco=count17;while(fltb!=z0){while(fltb<z0){if(is_tablae_symbol(tb,fltbco,s[z])==1){fltb++;fltbco++;}z++;if(fltb==z0){break;}}}z=z-z0;while(z0>0){i=add_tablae_symbol(vect,tb,count17,s[z],z,i,1);count17++;z++;z0--;}z--;break;
									  }else
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
	if(vect->tp[i-1]==V_CLASS){printf("cfl:reback1\n");z=0; p=p-(patlen-1);i=0; count17=0;i=add_tablae_symbol(vect,tb,count17,s[z],z,i,0);z++;p++;}
	cure++;
																	   }else
																	   
if(*p==0 && v_char_exists(vect)==false && flag_start==1 && flag_end==0){   
	if(vect->tp[i-1]==V_POINT){printf("pfl:reback2\n");p=p-(patlen-1);z=0;i=0;i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;}
	if(vect->tp[i-1]==V_CLASS){printf("cfl:reback2\n");p=p-(patlen-1);z=0;i=0;count17=0;i=add_tablae_symbol(vect,tb,count17,s[z],z,i,0);z++;p++;}
	cure++;
																	   }else
																	   
if(*p==0 && v_char_exists(vect)==false && flag_start==0 && flag_end==1 &&cure<10){
	z=strlen-1;  
	//printf("===%c|p==%c|i==%i|p==%s\n",s[z],*p,i,p);
	if(vect->tp[i-1]==V_POINT){printf("pfl:reback3\n");i--;i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);}
	if(vect->tp[i-1]==V_CLASS){printf("cfl:reback3\n");count17--;i--;i=add_tablae_symbol(vect,tb,count17,s[z],z,i,0);}
	cure++;
																       }else
																       
if(*p==0 && flag_star==1 && cure==0){
printf("flag_star\n");	
//if(vect->tp[i-1]==V_POINT){i--; z=strlen-1;i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);}
//if(vect->tp[i-1]==V_CLASS){i--; count17--; z=strlen-1;i=add_tablae_symbol(vect,tb,count17,s[z],z,i,0);}
																       }else
if(*p==0 && flag_plus==1 && cure==0){
printf("flag_plus\n");	
//if(vect->tp[i-1]==V_POINT){i--; z=strlen-1;i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);}
//if(vect->tp[i-1]==V_CLASS){i--; count17--; z=strlen-1;i=add_tablae_symbol(vect,tb,count17,s[z],z,i,0);}
																       }else 
if(*p==0 && flag_end==1){
printf("flag_end\n");	
if(vect->tp[i-1]==V_POINT){i--; z=strlen-1;i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);}
if(vect->tp[i-1]==V_CLASS){i--; count17--; z=strlen-1;i=add_tablae_symbol(vect,tb,count17,s[z],z,i,0);}																		   
																		   
																		   }																       																       
																       
//!TODO: ^...$														


}
point_reindex(vect,tb,s);
////////////////////////////////////////////////////////////////////////////////////////
if(flag_quest==0 || flag_star==0 || flag_plus==0 || flag_step==1){return vect;}
print_vect(vect);
free(p);

////////////////////////////////////////////////////////////////////////////////////////
p=vect->c;
printf("===%s\n",p);/*
n=0; z=0; i=0;
oc='\0',end='\n',e='\0',c=*p,nc=*p++; p--;
count17=0;
while (*p!=e){
travel3(p,oc,c,nc);
//point_reindex(vect,tb,s);
//if(vect->otp[n]==V_CLASS){count17++;}
switch(*p){*/
/*	
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
}while(libc_strncmp(s+z,bf,libc_strlen(bf))!=0 && s[z]!=end && s[z]!=0);
bf="";
n++;n++;break;
				}else{
do{
new_vect->c[i]=s[new_vect->pos[i-1]+1]; new_vect->pos[i]=new_vect->pos[i-1]+1; new_vect->tp[i]=V_CHAR; new_vect->otp[i]=V_POINT;i++;z++;
}while(libc_substr_count(s+(z+1),bf)>0 && s[z+1]!=end && s[z]!=0);
bf="";
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
}while(libc_strncmp(s+z,bf,libc_strlen(bf))!=0 && s[z]!=end && s[z]!=0);
bf="";
n++;n++;break;	
				}else{
do{
new_vect->c[i]=s[new_vect->pos[i-1]+1]; new_vect->pos[i]=new_vect->pos[i-1]+1; new_vect->tp[i]=V_CHAR; new_vect->otp[i]=V_NULL;i++;z++;
}while(libc_substr_count(s+(z+1),bf)>0 && s[z+1]!=end && s[z]!=0);
bf="";
n++;break;
					}
													}													
//!************************************************************													
if(vect->otp[n-1]==V_CLASS && vect->tp[n-1]==V_CHAR && vect->tp[n+1]==V_CHAR){ printf("sfl3\n");

if(flag_quest==1){
do{
i=add_tablae_symbol(new_vect,tb,count17,s[z],z,i,1);z++;
}while(libc_strncmp(s+z,bf,libc_strlen(bf))!=0 && s[z]!=end && s[z]!=0);
bf="";
	count17++;
	n++;n++;break;
				}else{
do{
i=add_tablae_symbol(new_vect,tb,count17,s[z],z,i,1);z++;
}while(libc_substr_count(s+(z+1),bf)>0 && s[z+1]!=end && s[z]!=0);
bf="";
count17++;
n++;break;
					}
													}
//!************************************************************

if(vect->otp[n-1]==V_CLASS && vect->tp[n-1]==V_CHAR && vect->tp[n+1]!=V_CHAR){printf("===================sfl4\n");
//!====buf
int z0=0,z1=0,z2=0,z3=0,bacount17=count17;				
while(*p==1 && *p!=0){z0++;p++;}		
if(flag_quest==1){n++;}
printf("==%i\n",z);
do{
if(tablae_symbol(tb,vect->pos[n+1],s[z])!=0 && vect->tp[n+1]==V_CLASS){bf[z2]=s[z];z2++;z1++;n++;}
z++;z3++;
if(s[z]==e && s[z]==end){break;}
}while(z0>z1);

printf("--%c\n",s[z]);
z=z-z3;
n=n-z0;
printf("++%c\n",s[z]);
printf("p-->%s\n",p-n);
printf("bf-->%s|\n",bf);
//!====buf
count17=bacount17;



if(flag_quest==1){
do{i=add_tablae_symbol(new_vect,tb,count17,s[z],z,i,1);z++;}while(libc_strncmp(s+z,bf,libc_strlen(bf))!=0 && s[z]!=end && s[z]!=0);
//!=====addbuf
while(z0>0){new_vect->c[i]=s[new_vect->pos[i-1]+1]; new_vect->pos[i]=new_vect->pos[i-1]+1; new_vect->tp[i]=V_CHAR; new_vect->otp[i]=V_CLASS;i++;z++;z0--;}
//!=====addbuf
bf="";count17++;n++;n++;break;
				}else{
z1=0;
do{
i=add_tablae_symbol(new_vect,tb,count17,s[z],z,i,1);z++;z1++;
}while(libc_substr_count(s+(z+1),bf)>0 && s[z+1]!=end && s[z]!=0);
//z=z-z1;
//!=====addbuf
while(z0>0){
new_vect->c[i]=s[new_vect->pos[i-1]+1];
new_vect->pos[i]=new_vect->pos[i-1]+1;
new_vect->tp[i]=V_CHAR;
new_vect->otp[i]=V_CLASS;i++;z++;z0--;
	}
bf="";	 
z=new_vect->pos[i-1];
printf("%c|p=%s\n",*p,p);
printf("%c|p=%s\n",*p,p+n);
count17++; 

break;
					}


																			 }
//!************************************************************	
	n++;p++;break;
	}

case '+':{p++;n++;break;}*/	
/*
default:{
	if(c!=s[z] && v_char_exists(new_vect)==false){z=libc_chrpos(s,c);}
	//if(c!=s[z] && v_char_exists(new_vect)==true){printf("Report 20: no exists - \"%c\"!!! \n",c);return vect;}
	if(c==s[z]){i=preg_add(new_vect,s[z],z,i,V_CHAR,V_NULL);z++;}	
	p++;n++;break;}	
	}
new_vect->length=i;
}
free(s);
free(bf);*/
return new_vect;
	}
//!------------------------------------------------------------

