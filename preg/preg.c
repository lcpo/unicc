
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
//*
//+
//?

///------------------------------------------------------------
void print_vect(s_vect* vect){
int i=0;
while(i<vect->length){
printf("%i|pos=%i|code=%c:%i|type=%i|old_type=%i\n",i,vect->pos[i],vect->c[i],vect->c[i],vect->tp[i],vect->otp[i]);
i++;
					 }
printf("%s\n",vect->c);	
return;
	}
///------------------------------------------------------------

int isbreak(int ch){
int i;
for(i=0;i<3;i++){
if(break_symbols[i]==ch){return 1;}	
				}
return 0;		
					}
///------------------------------------------------------------
/*void gainvalknownbreak(char* bf,char* p){
int n=0; int fl=0;
while(*p!=0){
	if(*p!=0 && isbreak(*p)==0){bf[n]=*p;n++;p++;}else{break;}
	}

return;
}*/	
///------------------------------------------------------------
int count_char_table(ch_tab* tb,char* s,int id,char end){
	int co=0,i=0;
	while(*s!=0 && *s!=end){
		if(is_tablae_symbol(tb,id,*s)==1){co++;}
		s++;i++;}
		s=s-i;
	return co;
															}
///------------------------------------------------------------
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
free(np); free(bf1); free(bf2);
return;
	}															
///------------------------------------------------------------
void add_poscharto_table(ch_tab* tb,char* s,int id,char end){
int co=count_char_table(tb,s,id,end),z=0,i=0;
tb->pos[id]=malloc(co);
while(*s!=0 && *s!=end){
if(is_tablae_symbol(tb,id,*s)==1){tb->pos[id][z]=i;z++;}//else{tb->pos[id][z]=-1;z++;}
s++;i++;
}
s=s-i;
return;	
	}
///------------------------------------------------------------
s_vect* preg(char* pt,char* str){
int strlen=libc_strlen(str),patlen=libc_strlen(pt),i=0,z=0,n=0,co=0,count_esc=0,
flag_esc=0,flag_start=0,flag_end=0,flag_step=0,
old_i=0,old_z=0,old_n,cure=0,count1=0,count2=0;
char *p=malloc(patlen),*np=malloc(patlen),*s=malloc(strlen),*bf=malloc(patlen),oc='\0',end='\n',e='\0',c,nc;
libc_strcpy(s,str); 
libc_strcpy(np,pt);
//---------------------
s_vect* vect=malloc(1); vect->pos=malloc(strlen); vect->tp=malloc(strlen); vect->otp=malloc(strlen); vect->c=malloc(strlen);
//----------------------
s_vect* new_vect=malloc(1); new_vect->pos=malloc(strlen); new_vect->tp=malloc(strlen); new_vect->otp=malloc(strlen); new_vect->c=malloc(strlen);
//---------------------
ch_tab* tb=malloc(1); tb->table=malloc(256); tb->pos=malloc(256); tb->flag_denial=malloc(256); tb->length=0;
//---------------------
ch_stp* wb=malloc(1); wb->min=malloc(256); wb->max=malloc(256); wb->count=malloc(256); wb->length=0;
//---------------------
c=*np,nc=*np++; np--;
//---------------------
printf("%s\n",np);
//!------------------------------------------------------------
//!~ preg_compile - no sapport utf8
//!------------------------------------------------------------
while (*np!=e){
travel3(np,oc,c,nc);
switch(*np){
case '\\':{
	if(flag_esc==0 && nc=='\\'){flag_esc=0;np++;p[n]=*np;n++;np++;break;}
	if(flag_esc==0 && nc!='\\'){flag_esc=1;np++;break;}
	np++;break;}
case '^':{if(flag_esc==1){flag_esc=0;p[n]=*np;n++;z++;}else{flag_start=1;}np++;break;}
case '*':{
if(flag_esc==0){flag_step=1;p[n]=3;n++;
	wavy_string(wb,"{0,}");
	np++,wb->length++;
	break;
}else{p[n]=*np;n++;np++;break;}
	}
case '+':{
if(flag_esc==0){flag_step=1;p[n]=3;n++;
	wavy_string(wb,"{1,}");
	np++,wb->length++;
	break;
}else{p[n]=*np;n++;np++;break;}
	}
	
case '?':{
if(flag_esc==0){flag_step=1;p[n]=3;n++;
	wavy_string(wb,"{0,1}");
	np++,wb->length++;
	break;
}else{p[n]=*np;n++;np++;break;}
		}
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
case '.':{
	if(flag_esc==0){p[n]=2;n++;np++;break;}else{p[n]=*np;n++;np++;break;}
	}

case 'w':{if(flag_esc==1){p[n]=1;n++;
	tb->table[tb->length]=bracket_string(tb,"[A-Za-z0-9\\_]");
	add_poscharto_table(tb,s,tb->length,end);
	//printf("w==%s\n",tb->table[tb->length]);
		tb->length++;np++;flag_esc=0;
		break;
}else{p[n]=*np;n++;np++;break;}}

case 'W':{if(flag_esc==1){p[n]=1;n++;
	tb->table[tb->length]=bracket_string(tb,"[^A-Za-z0-9\\_]");
	add_poscharto_table(tb,s,tb->length,end);
	//printf("W==%s\n",tb->table[tb->length]);
		tb->length++;np++;flag_esc=0;
		break;
}else{p[n]=*np;n++;np++;break;}}

case 'd':{
	if(flag_esc==1){
		p[n]=1;n++;
	tb->table[tb->length]=bracket_string(tb,"[0-9]");
	add_poscharto_table(tb,s,tb->length,end);
	//printf("d==%s\n",tb->table[tb->length]);
		tb->length++;np++;flag_esc=0;
		break;
}else{p[n]=*np;n++;np++;break;}}

case 'D':{if(flag_esc==1){p[n]=1;n++;
	tb->table[tb->length]=bracket_string(tb,"[^0-9]");
	add_poscharto_table(tb,s,tb->length,end);
	//printf("D==%s\n",tb->table[tb->length]);
		tb->length++;np++;flag_esc=0;
		break;
}else{p[n]=*np;n++;np++;break;}}

case 's':{if(flag_esc==1){p[n]=1;n++;
	tb->table[tb->length]=bracket_string(tb,"[\\ \t\n\r\f\v]");
	add_poscharto_table(tb,s,tb->length,end);
	//printf("s==|%s|\n",tb->table[tb->length]);
		tb->length++;np++;flag_esc=0;
		break;
}else{p[n]=*np;n++;np++;break;}}

case 'S':{if(flag_esc==1){p[n]=1;n++;
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
case '$':{if(flag_esc==1){flag_esc=0;p[n]=*np;n++;z++;}else{flag_end=1;}np++;break;}
default:{p[n]=*np;n++;np++;break;}	
		   }
	
			 }
//!------------------------------------------------------------
///~ end preg_compile
//!------------------------------------------------------------
/*
 * 
i=0;
while(p[i]){
printf("%c\n",p[i]);
i++;
}
printf("%s\n",p);
exit(0);
*/
printf("%s\n",p);

n=0; z=0; flag_esc=0; patlen=libc_strlen(p);
oc='\0',end='\n',e='\0',c=*p,nc=*p++; p--; i=0;
int cpos=0,spos=0,fladd=0,ic=0,oic=0,ri=0,ri2=0;
//!-----------------------------
if(flag_end==1){n=patlen;p=p+patlen; count1=tb->length-1; count2=wb->length-1; z=strlen-1; i=patlen-1;}
while (is_i_flag(flag_end,n,patlen)!=false){
travel3(p,oc,c,nc);
if(c=='\0'){i_flag_end(flag_end,p);continue;}
point_reindex(vect,tb,s);

switch(*p){
//----------------------------------------------------------------------
case 1:{
	
	if(v_char_exists_vect(vect)==false && flag_end==0 && flag_start==0 && tb->pos[count1+1]!=NULL && nc==1){
		printf("cl1|%c\n",nc);
	while(tb->pos[count1][ri]!=NULL || tb->pos[count1+1][ri2]!=NULL){
	printf("%c|%c|%i|%i|%i\n",s[tb->pos[count1][ri]],s[tb->pos[count1+1][ri2]],tb->pos[count1][ri],tb->pos[count1+1][ri2],(tb->pos[count1][ri]-tb->pos[count1+1][ri2]));
	if(tb->pos[count1][ri]>tb->pos[count1+1][ri2]){
		ri2++;
												}
	if((tb->pos[count1][ri]-tb->pos[count1+1][ri2])==-1){z=tb->pos[count1][ri];break;}else{ri++;}
	if(tb->pos[count1][ri]==NULL && tb->pos[count1+1][ri2]!=NULL){ri=0;}
	if(tb->pos[count1][ri]!=NULL && tb->pos[count1+1][ri2]==NULL){ri2=0;}
	if(tb->pos[count1][ri]==NULL && tb->pos[count1+1][ri2]==NULL){z=0;printf("-err\n");break;}
	}
																		}
	if(v_char_exists_vect(vect)==false && flag_end==0 && flag_start==0 && tb->pos[count1+1]==NULL && isbreak(nc)==0){
	printf("cl2|%c\n",nc);
	while(tb->pos[count1][ri]!=NULL){
	if(s[tb->pos[count1][ri]+1]==nc){z=tb->pos[count1][ri];break;}	
	printf("%c|%c|%i|%i\n",s[tb->pos[count1][ri]],s[tb->pos[count1][ri]+1],tb->pos[count1][ri]);
	ri++;
									}
								
		}

	if(is_tablae_symbol(tb, count1,s[z]) && isbreak(vect->c[i+1])!=1){
	i=preg_add(vect,s[z],z,i,V_CHAR,V_CLASS,flag_end);
	i_flag_end(flag_end,z);
	i_flag_end(flag_end,count1);
	}else{
	i=preg_add(vect,1,count1,i,V_CLASS,V_NULL,flag_end);
	i_flag_end(flag_end,z);
	i_flag_end(flag_end,count1);	
		}
	i_flag_end(flag_end,p);
	break;
	}
//----------------------------------------------------------------------
case 2:{
	//i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);
if(vect->tp[i+1]==V_CHAR && s[z]!=e && s[z]!=end){printf("pfl:next\n");i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT,flag_end);}else
if(vect->tp[i-1]==V_CHAR && s[z]!=e && s[z]!=end){printf("pfl:prev\n");i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT,flag_end);}
else{printf("pfl:null\n");i=preg_add(vect,2,-1,i,V_POINT,V_NULL,flag_end);}
	i_flag_end(flag_end,z);
	i_flag_end(flag_end,p);
	break;
	}
//----------------------------------------------------------------------
case 3:{
//	printf("-------------------------\n");
//	printf("min=%i|max=%i|count=%i\n",wb->min[count2],wb->max[count2],wb->count[count2]);
//	printf("-------------------------\n");
	i=preg_add(vect,3,count2,i,V_STEP,V_NULL,flag_end);
	i_flag_end(flag_end,count2);
	i_flag_end(flag_end,p);
	break;
	}
//---------------------------------------------------------------------- 
default:{
	if(*p!=0){
	if(flag_start==0 && z==0){
		if(c!=s[z]){z=libc_chrpos(s,c);}
		}
	if(c==s[z]){
	i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL,flag_end);
	i_flag_end(flag_end,z);
				}else{
	i=preg_add(vect,*p,-1,i,V_CHAR,V_NULL,flag_end);
	i_flag_end(flag_end,z);

					}
				
			}
	i_flag_end(flag_end,p);
	
	break;
		}
//----------------------------------------------------------------------
				}
if(i<0){i=patlen;}				
vect->length=i;
i_flag_end(flag_end,n);
		}
		
if(flag_start==1 && flag_end==1 && flag_step!=1 && vect->length!=strlen){printf("errlen\n");return vect;}
////////////////////////////////////////////////////////////////////////////////////////
if(flag_step==0){return vect;}
print_vect(vect);
free(p);

////////////////////////////////////////////////////////////////////////////////////////
p=vect->c;
printf("===%s\n",p);
///------------------------------------------------------------
n=0; z=0; flag_esc=0; patlen=libc_strlen(p);
oc='\0',end='\n',e='\0',c=*p,nc=*p++; p--; i=0;
cpos=0,spos=0,fladd=0,ic=0,oic=0,ri=0,ri2=0,count1=0,count2=0;

while(*p!=e){
travel3(p,oc,c,nc);
switch(*p){
case 1:{
if(is_tablae_symbol(tb, count1,s[z])){i=preg_add(new_vect,s[z],z,i,V_CHAR,V_CLASS,0);count1++;}
z++;
p++;
break;}
case 2:{i=preg_add(new_vect,s[z],z,i,V_CHAR,V_POINT,0);z++;p++;break;}
case 3:{
printf("min=%i|max=%i|count=%i\n",wb->min[count2],wb->max[count2],wb->count[count2]);

for(n=0;n<wb->min[count2]-1;n++){
if(isbreak(oc)==0 && s[z]==oc){
	i=preg_add(new_vect,s[z],z,i,V_CHAR,V_NULL,0);z++;
	}else{
		printf("err1\n");return new_vect;
		}
								}
if(wb->count[count2]==1 && s[z]==oc){printf("err2\n");return new_vect;}

if(wb->max[count2]!=-1){
for(n=0;n<wb->max[count2]-1;n++){
	if(isbreak(oc)==0){
	if(s[z]==oc){i=preg_add(new_vect,s[z],z,i,V_CHAR,V_NULL,0);z++;}else{printf("err3\n");return new_vect;}		
		}
	}
										  
					   }
					   	
	p++;count2++;break;
	}	
default:{
	printf(">%c\n",s[z]);
	i=preg_add(new_vect,s[z],z,i,V_CHAR,V_NULL,0);
	z++;p++;break;}	
			}	
new_vect->length=i;	
	}
	
return new_vect;
	}
//!------------------------------------------------------------





/*
if(flag_step==0){
//-----------	
if(flag_end==0 && s[z]!=e && s[z]!=end && v_char_exists_pattern(p-n)==true && v_char_exists_vect(vect)==false){
    printf("poin0-0\n");
	cpos=v_char_pos_pattern(p-n),spos=libc_chrpos(s,p[cpos]),fladd=0;
    cpos--; spos--;
	ic=0,oic=cpos;
while(cpos>=ic){if(p[ic]==2){i=preg_add(vect,s[spos-oic],spos-oic,i,V_CHAR,V_POINT);z++;p++;break;}ic++;oic--;}
	z=vect->pos[i-1]+1;
	break;
			}
//-----------
if(flag_end==0 && s[z]!=e && s[z]!=end && v_char_exists_pattern(p-n)==true && v_char_exists_vect(vect)==true){
	printf("poin0-1\n");
i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;break;
	}
//-----------
if(flag_end==0 && s[z]!=e && s[z]!=end && v_char_exists_pattern(p-n)==false && v_char_exists_vect(vect)==true){
	printf("poin0-2\n");
i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;break;
	}	
//-----------
if(flag_end==0 && s[z]!=e && s[z]!=end && v_char_exists_pattern(p-n)==false && v_char_exists_vect(vect)==false){
	printf("poin0-3\n");
	i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);
	z++;p++;break;
	}
//-----------	
if(flag_end==1 && s[z]!=e && s[z]!=end && v_char_exists_pattern(p-n)==false && v_char_exists_vect(vect)==false){
printf("poin1-0\n");
//printf("%i\n",n);
z=z+strlen-patlen;
cpos=patlen;
while(cpos>0){
if(*p==2){	
i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);
z++;p++;
		  }
cpos--;
}

break;
																	    }
//-----------																	    
if(flag_end==1 && s[z]!=e && s[z]!=end && v_char_exists_pattern(p-n)==false && v_char_exists_vect(vect)==true){
printf("poin1-1\n");
	i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);
	z++;p++;break;	
	}
	
//-----------																	 
if(flag_end==1 && s[z]!=e && s[z]!=end && v_char_exists_pattern(p-n)==true && v_char_exists_vect(vect)==false){
printf("poin1-2\n");
//i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT); z++; p++; break;
	cpos=v_char_pos_pattern(p-n),spos=libc_chrpos(s,p[cpos]),fladd=0;
    cpos--; spos--;
	ic=0,oic=cpos;
	//printf("cpos=%i|spos=%i\n",cpos,spos);
while(cpos>=ic){
	//printf("pic==%c",p[ic]);
	if(p[ic]==2){
	i=preg_add(vect,s[spos-oic],spos-oic,i,V_CHAR,V_POINT);z++;p++;break;
	//printf("ddp\n");
	}
	ic++;oic--;
	
	}
	z=vect->pos[i-1]+1;
	break;																	      }
//-----------																	 
if(flag_end==1 && s[z]!=e && s[z]!=end && v_char_exists_pattern(p-n)==true && v_char_exists_vect(vect)==true){
printf("poin1-3\n");	
i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT); z++; p++; break;
				}
}
*/
