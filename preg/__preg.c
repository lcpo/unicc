
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


///------------------------------------------------------------
int pstoi(char* p){
char* bf=malloc(libc_strlen(p));
int i=0,n=0,out=0;
while(p[i]!='\0'){
	if(libc_isdigit(p[i])){bf[n]=p[i];n++;}
	i++;
	}
	out=libc_stoi(bf);
	free(bf);
return	out;
	}
///------------------------------------------------------------
int libc_in_array_int(uni* ars,uni se, uni co){
int i=0;
while(co>i){
	if(ars[i]==se){
		return i;
		          }
		i++;
		}
return -1;
										   } 
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
tb->copos[id]=z;
s=s-i;
return;	
	}
///------------------------------------------------------------
s_vect* preg(char* pt,char* str){
int strlen=libc_strlen(str),patlen=libc_strlen(pt),i=0,z=0,n=0,co=0,count_esc=0,
flag_esc=0,flag_start=0,flag_end=0,flag_step=0,flag_quest=0,
old_i=0,old_z=0,old_n,cure=0,count1=0,count2=0;
char *p=malloc(patlen),*np=malloc(patlen),*s=malloc(strlen),oc='\0',end='\n',e='\0',c,nc;
libc_strcpy(s,str); 
libc_strcpy(np,pt);
printf("str=%s\n",s);
//---------------------
s_vect* vect=malloc(1); vect->pos=malloc(strlen); vect->tp=malloc(strlen); vect->otp=malloc(strlen); vect->c=malloc(strlen);
//----------------------
s_vect* new_vect=malloc(1); new_vect->pos=malloc(strlen); new_vect->tp=malloc(strlen); new_vect->otp=malloc(strlen); new_vect->c=malloc(strlen);
//---------------------
ch_tab* tb=malloc(1); tb->table=malloc(256); tb->pos=malloc(256); tb->copos=malloc(256); tb->flag_denial=malloc(256); tb->length=0;
//---------------------
ch_stp* wb=malloc(1); wb->min=malloc(256); wb->max=malloc(256);wb->length=0;
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
	if(flag_esc==0){
		/*
		p[n]=2;n++;np++;break;
		*/
	p[n]=1;n++;
	tb->table[tb->length]=s;//bracket_string(tb,"[A-Za-z0-9\\_]");
	tb->flag_denial[tb->length]=0;
	add_poscharto_table(tb,s,tb->length,end);
	tb->length++;np++;
	break;
		}else{p[n]=*np;n++;np++;break;}
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

case '{':{if(flag_esc==0){
co=0;
	char *wsk=parce_tag(np,*np,'}');
	uni wsk_len=libc_strlen(wsk);
if(libc_chrpos(wsk,',')==-1){

if(p[n-1]!=1 && p[n-1]!=3){co=pstoi(wsk)-1;while(co>0){p[n]=p[n-1];n++;co--;}free(wsk);np=np+wsk_len;break;}
if(p[n-1]==1){co=pstoi(wsk)-1;
while(co>0){p[n]=p[n-1];n++;tb->table[tb->length]=tb->table[tb->length-1];add_poscharto_table(tb,s,tb->length,end);
tb->flag_denial[tb->length]=tb->flag_denial[tb->length-1];tb->length++;co--;}free(wsk);np=np+wsk_len;break;}

		}else{
		p[n]=3;n++;	flag_step=1;
			}
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

n=0; z=0; flag_esc=0; patlen=libc_strlen(p);
oc='\0',end='\n',e='\0',c=*p,nc=*p++; p--; i=0,co=0,count1=0;
int cpos=0,spos=0,fladd=0,flok=0,ic=0,oic=0,onz=0,ri0=0,ri1=0,ri2=0,cori0=0,cori1=0,cori2=0,nz=0,flag_rev=0;
//!-----------------------------
int* copos=malloc(patlen);
//!-----------------------------
while (*p!=0){
travel3(p,oc,c,nc);
switch(*p){
//----------------------------------------------------------------------
case 1:{
if(fladd==1){nz=copos[cpos];fladd=0;}else{nz=0;}
ic=z;

if(cpos<0){printf("err:0\n");count1++;p++;n++;break;}
if(cpos>patlen){printf("err:1\n");count1++;p++;n++;break;}

while(tb->copos[count1]>nz){
if(n==0){
if(ic==tb->pos[count1][nz]){i=preg_add(vect,s[tb->pos[count1][nz]],tb->pos[count1][nz],i,V_CHAR,V_CLASS,0);onz=nz+1;flok=1;break;}else{ic++;}	
}else{
	if(vect->tp[i-1]==V_CHAR){
if(ic==tb->pos[count1][nz] && (tb->pos[count1][nz]-vect->pos[i-1])==1){i=preg_add(vect,s[tb->pos[count1][nz]],tb->pos[count1][nz],i,V_CHAR,V_CLASS,0);onz=nz+1;flok=1;break;}else{ic++;}		
							 }else{
if(ic==tb->pos[count1][nz]){i=preg_add(vect,s[tb->pos[count1][nz]],tb->pos[count1][nz],i,V_CHAR,V_CLASS,0);onz=nz+1;flok=1;break;}else{ic++;}									 
								 }
	  }

if(ic>=strlen){ic=z;nz++;}

							}
if(n==0){
if(nz>=tb->copos[count1]){
	printf("err:2\n");//exit(0);
	count1++;
	p++;
	n++;
	break;	
						 }
		}else{
if(nz>=tb->copos[count1]){
	fladd=1;
	count1--;p--;i--;n--;cpos--;
	break;
						}			
			}							
	count1++;p++;n++;
	z=ic+1;
	if(flok==1){copos[cpos]=onz;cpos++;flok=0;}
	break;	

	}
//----------------------------------------------------------------------
case 3:{
i=preg_add(vect,3,count2,i,V_STEP,V_NULL,0);
count2++;p++;n++;
break;
}
//---------------------------------------------------------------------- 
default:{
	if(flag_start==0 && z==0){
		if(c!=s[z]){z=libc_chrpos(s,c);}
		}
	if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL,0);z++;}else{i=preg_add(vect,*p,-1,i,V_CHAR,V_NULL,0);z++;}
	p++;n++;break;
		}
//----------------------------------------------------------------------
				}
if(i<0){i=patlen;}				
vect->length=i;

		}
free(copos);		
if(flag_start==1 && flag_end==1 && flag_step!=1 && vect->length!=strlen){printf("errlen\n");return vect;}
////////////////////////////////////////////////////////////////////////////////////////
if(flag_step==0){return vect;}
print_vect(vect);
free(p);

////////////////////////////////////////////////////////////////////////////////////////
p=vect->c;
printf("===%s\n",p);
///------------------------------------------------------------
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
///------------------------------------------------------------


n=0; z=0; flag_esc=0; patlen=libc_strlen(p);
oc='\0',end='\n',e='\0',c=*p,nc=*p++; p--; i=0;
cpos=0,spos=0,fladd=0,ic=0,oic=0,ri0=0,ri1=0,ri2=0,count1=0,count2=0;
while(*p!=e){
travel3(p,oc,c,nc);
switch(*p){
case 1:{n++;p++;break;}
case 3:{
old_n=n;	
p++;n++;
printf("\n\\--------------------\\\n");
if(wb->max[count2]==-2){wb->max[count2]=strlen;}
if(wb->min[count2]==-2){wb->min[count2]=0;}
if(nc==3 && wb->min[count2+1]==0 && wb->max[count2+1]==1){printf("flag:%c\n",'?');flag_quest=1;p++;n++;}//?
z=0;
char *bf=malloc(patlen);
while(*p!=e && *p!=end){if(isbreak(*p)==0){bf[z]=*p;z++;}if(isbreak(*p)==1){break;}p++;n++;}
p=p-z; n=n-z;
printf("min=%i|max=%i|count2=%i|bf=%s|c=%c\n",wb->min[count2],wb->max[count2],count2,bf,vect->c[old_n-1]);
//----------------------------------------------------------------------
if(vect->tp[old_n-1]==V_CHAR && vect->otp[old_n-1]==V_CLASS){
	printf("char-class\n");
	z=vect->pos[old_n-1]+1;
for(ic=0;ic<wb->min[count2]-1;ic++){
if(is_tablae_symbol(tb, count1-1,s[z])){i=preg_add(new_vect,s[z],z,i,V_CHAR,V_NULL,0);z++;}else{printf("class:err1\n");return new_vect;	}
									}
if(wb->max[count2]>0){
for(ic=0;ic<wb->max[count2]-wb->min[count2];ic++){

if(flag_quest==0){
if(s[z]!=e && s[z]!=end && libc_substr_count(s+z,bf)>0 && is_tablae_symbol(tb, count1-1,s[z])){i=preg_add(new_vect,s[z],z,i,V_CHAR,V_CLASS,0);z++;}else{i--;break;}
}else{
if(s[z]!=e && s[z]!=end && libc_strncmp(s+z,bf,libc_strlen(bf))!=0 && is_tablae_symbol(tb, count1-1,s[z])){i=preg_add(new_vect,s[z],z,i,V_CHAR,V_CLASS,0);z++;}else{break;}}
					   printf("bf=%s\n",bf);		
											      }
if(wb->min[count2]!=0 && libc_strncmp(s+z,bf,libc_strlen(bf))!=0){printf("class:err3-%s\n",bf);return new_vect;}
					   }	
															}
//----------------------------------------------------------------------
if(flag_quest==1){flag_quest=0;count2++;}count2++;free(bf);
	break;
																		}
default:{
			i=preg_add(new_vect,vect->c[n],vect->pos[n],i,V_CHAR,vect->otp[n],0);			
			if(vect->otp[n]==V_CLASS){count1++;}
			n++;p++;break;
		 }	
			}
new_vect->length=i;
}

/*
while(*p!=e){
travel3(p,oc,c,nc);
switch(*p){
case 1:{
if(is_tablae_symbol(tb, count1,s[z])){i=preg_add(new_vect,s[z],z,i,V_CHAR,V_CLASS,0);count1++;}
z++;
p++;
break;}
//case 2:{i=preg_add(new_vect,s[z],z,i,V_CHAR,V_POINT,0);z++;p++;break;}
case 3:{
	p++;
if(wb->max[count2]==-2){wb->max[count2]=strlen;}
if(wb->min[count2]==-2){wb->min[count2]=0;}
if(nc==3 && wb->min[count2+1]==0 && wb->max[count2+1]==1){printf("flag:%c\n",'?');p++;flag_quest=1;}//?
n=0;
while(*p!=e && *p!=end){bf[n]=*p;p++;n++;if(isbreak(*p)==1){break;}}
p=p-n;

printf("min=%i|max=%i\n",wb->min[count2],wb->max[count2]);

///------------------------------------------------------------
if(vect->tp[i-1]==V_CHAR && vect->otp[i-1]==V_NULL){
printf("char-null\n");
for(n=0;n<wb->min[count2]-1;n++){
if(s[z]==oc){i=preg_add(new_vect,s[z],z,i,V_CHAR,V_NULL,0);z++;}else{printf("char:err1\n");return new_vect;	}
								}
if(wb->max[count2]>0){
for(n=0;n<wb->max[count2]-wb->min[count2];n++){
if(s[z]==oc){
	//printf("<<%c\n",s[z]);
i=preg_add(new_vect,s[z],z,i,V_CHAR,V_NULL,0);z++;
}		
											   }
if(libc_strncmp(s+z,bf,libc_strlen(bf))!=0){printf("char:err2\n");return new_vect;}
					   }
				}
///------------------------------------------------------------
if(vect->tp[i-1]==V_CHAR && vect->otp[i-1]==V_CLASS){
	printf("char-class\n");
for(n=0;n<wb->min[count2]-1;n++){
if(is_tablae_symbol(tb, count1,s[z])){i=preg_add(new_vect,s[z],z,i,V_CHAR,V_NULL,0);z++;}else{printf("class:err1\n");return new_vect;	}
								}
if(wb->max[count2]>0){
for(n=0;n<wb->max[count2]-wb->min[count2];n++){

if(flag_quest==0){
if(s[z]!=e && s[z]!=end && libc_substr_count(s+z,bf)>0 && is_tablae_symbol(tb, count1,s[z])){
i=preg_add(new_vect,s[z],z,i,V_CHAR,V_CLASS,0);
z++;
}else{
	z--;
	i--;
	break;
	}
				 }else{
if(s[z]!=e && s[z]!=end && libc_strncmp(s+z,bf,libc_strlen(bf))!=0 && is_tablae_symbol(tb, count1,s[z])){
i=preg_add(new_vect,s[z],z,i,V_CHAR,V_CLASS,0);
z++;
}else{break;}
					   }
					   printf("bf=%s\n",bf);		
											   }

if(wb->min[count2]!=0 && libc_strncmp(s+z,bf,libc_strlen(bf))!=0){printf("class:err3-%s\n",bf);return new_vect;}
					   }	
p++;
break;	
	}
///------------------------------------------------------------

///------------------------------------------------------------
if(flag_quest==1){flag_quest=0;count2++;}
	count2++;
	break;
	}	
default:{
	printf(">%c\n",s[z]);
	if(c!=s[z] && flag_start==0){z=libc_chrpos(s,c);}
	i=preg_add(new_vect,s[z],z,i,V_CHAR,V_NULL,0);
	z++;p++;break;}	
			}
				
new_vect->length=i;	
	}
*/	
return new_vect;
	}
//!------------------------------------------------------------
/*
if(fladd==1){nz=copos[cpos];fladd=0;}else{nz=0;}
ic=z;
printf("nz==>%i|cpos=%i\n",nz,cpos);
printf("\n----------------------\n");

while(tb->copos[count1]>nz){

if(n==0){
if(ic==tb->pos[count1][nz]){i=preg_add(vect,s[tb->pos[count1][nz]],tb->pos[count1][nz],i,V_CHAR,V_CLASS,flag_end);onz=nz+1;flok=1;break;}else{ic++;}	
}else{
	if(vect->tp[i-1]==V_CHAR){
if(ic==tb->pos[count1][nz] && (tb->pos[count1][nz]-vect->pos[i-1])==1){i=preg_add(vect,s[tb->pos[count1][nz]],tb->pos[count1][nz],i,V_CHAR,V_CLASS,flag_end);onz=nz+1;flok=1;break;}else{ic++;}		
							 }else{
if(ic==tb->pos[count1][nz]){i=preg_add(vect,s[tb->pos[count1][nz]],tb->pos[count1][nz],i,V_CHAR,V_CLASS,flag_end);onz=nz+1;flok=1;break;}else{ic++;}									 
								 }
	  }

if(ic>=strlen){ic=z;nz++;}
							}
if(n==0){
if(nz>=tb->copos[count1]){
	printf("err:112\n");//exit(0);
	i_flag_end(flag_end,count1);
	i_flag_end(flag_end,p);
	i_flag_end(flag_end,n);
	break;	
						 }
		}else{
if(nz>=tb->copos[count1]){
	fladd=1;
	i_flag_end_rev(flag_end,count1);
	i_flag_end_rev(flag_end,p);
	i_flag_end_rev(flag_end,i);
	i_flag_end_rev(flag_end,n);
	cpos--;
	break;
						}			
			}							
	i_flag_end(flag_end,count1);
	i_flag_end(flag_end,p);
	i_flag_end(flag_end,n);
	z=ic;
	if(flok==1){copos[cpos]=onz;cpos++;flok=0;}
	break;
*/

/*
if(fladd==1){nz=copos[cpos];fladd=0;}else{nz=((flag_end==1)?(tb->copos[count1]-1):0);}
if(flag_end==1){ic=strlen;}else{ic=z;}

printf("nz==>%i|cpos=%i\n",nz,cpos);
printf("\n----------------------\n");
//if(cpos<0){printf("err:0\n");i_flag_end(flag_end,count1);i_flag_end(flag_end,p);i_flag_end(flag_end,n);break;}
//if(cpos>patlen){printf("err:1\n");i_flag_end(flag_end,count1);i_flag_end(flag_end,p);i_flag_end(flag_end,n);break;}

				
while(((flag_end==1)?(0<nz):(tb->copos[count1]>nz))){
//printf("n=%i|ic=%i|pos=%i\n",n,ic,tb->pos[count1][nz]);
if(((flag_end==1)?(n==patlen-1):(n==0))){
if(ic==tb->pos[count1][nz]){
	i=preg_add(vect,s[tb->pos[count1][nz]],tb->pos[count1][nz],i,V_CHAR,V_CLASS,flag_end);onz=((flag_end==1)?(nz-1):(nz+1));flok=1;break;}else{i_flag_end(flag_end,ic);}	
}else{
	if(vect->tp[((flag_end==1)?(i+1):(i-1))]==V_CHAR){
if(ic==tb->pos[count1][nz] && (tb->pos[count1][nz]-vect->pos[((flag_end==1)?(i+1):(i-1))])==-1){i=preg_add(vect,s[tb->pos[count1][nz]],tb->pos[count1][nz],i,V_CHAR,V_CLASS,flag_end);onz=((flag_end==1)?(nz-1):(nz+1));flok=1;break;}else{i_flag_end(flag_end,ic);}		
							 }else{
if(ic==tb->pos[count1][nz]){i=preg_add(vect,s[tb->pos[count1][nz]],tb->pos[count1][nz],i,V_CHAR,V_CLASS,flag_end);onz=((flag_end==1)?(nz-1):(nz+1));flok=1;break;}else{i_flag_end(flag_end,ic);}									 
								 }
	  }

if(((flag_end==1)?(ic<=0):(ic>=strlen))){ic=z;i_flag_end(flag_end,nz);}

							}
if(((flag_end==1)?(n==patlen-1):(n==0))){
if(((flag_end==1)?(nz<=0):(nz>=tb->copos[count1]))){
	printf("err:2\n");//exit(0);
	i_flag_end(flag_end,count1);
	i_flag_end(flag_end,p);
	i_flag_end(flag_end,n);
	break;	
						 }
		}else{
if(((flag_end==1)?(nz<=0):(nz>=tb->copos[count1]))){
	fladd=1;
	i_flag_end_rev(flag_end,count1);
	i_flag_end_rev(flag_end,p);
	i_flag_end_rev(flag_end,i);
	i_flag_end_rev(flag_end,n);
	cpos--;
	break;
						}			
			}							
	i_flag_end(flag_end,count1);
	i_flag_end(flag_end,p);
	i_flag_end(flag_end,n);
	z=ic;
	if(flok==1){copos[cpos]=onz;cpos++;flok=0;}
	break;
*/
