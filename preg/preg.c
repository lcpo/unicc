
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
free(bf);
return i;
										}

//------------------
if(vect->otp[i-1]==V_POINT){
	printf("1|%c\n",oc);
if(nc=='?' && c!='\\'){
p++;
n=0; int fl=0;
while(*p!=0){if(*p!=0){bf[n]=*p;n++;p++;}else{fl=1;break;}}

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
*/
//[] = 1
//{} = 2
//() = 3

///---------------------------------------------------------------------
/*
int preg_count(char* p){
int ret=0;
ret=ret+tag_count(p,'[',']');
ret=ret+tag_count(p,'{','}');
ret=ret+tag_count(p,'(',')');
return ret;
	}
*/
	
///---------------------------------------------------------------------
void preg(s_vect* vect,ch_tab* tb,char* pt,char* str){
int strlen=libc_strlen(str),
 patlen=libc_strlen(pt),
i=0,z=0,n=0,co=0,flag_esc=0,count_esc=0,flag_start=0,flag_end=0,
old_i=0,old_z=0,cure=0,count17=0;
char *p=malloc(patlen),*np=malloc(patlen),*s=malloc(strlen),*bf=malloc(patlen);
libc_strcpy(s,str); libc_strcpy(np,pt);

tb->table_count=tag_count(np,'[',']');
p=bracket_table(np,tb);
//printf("rex==%s\n",p);


char oc='\0',end='\n',e='\0',c=*p,nc=*p++; p--;
while (*p!=e){
travel3(p,oc,c,nc);
point_reindex(vect,tb,s);
switch(*p){
//----------------------------------------------------------------------
case '\\':{if(flag_esc==0){flag_esc=1;}else{
if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
if(c!=s[z] && v_char_exists(vect)==true){printf("Report 1: no exists - \"%c\"!!! \n",c);return;}
if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
}p++;break;}
//----------------------------------------------------------------------
case '.':{
	if(flag_esc==1){
		if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
		printf("%c,%c",s[z],c);
		if(c!=s[z] && v_char_exists(vect)==true){printf("Report 2: no exists - \"%c\"!!! \n",c);return;}
		if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
		}else{
if(cure==0){
	//printf("%c",s[z]);
/*
if(v_char_exists(vect)==false && flag_start==0 && flag_end==0){
printf("pfl1\n");	
i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;break;	
	}
*/					
if(vect->tp[i+1]==V_CHAR && s[z]!=end){printf("pfl:next\n");i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;break;}else
if(vect->tp[i-1]==V_CHAR && s[z]!=end){printf("pfl:prev\n");i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;break;}else
{printf("pfl:null\n");i=preg_add(vect,0,0,i,V_POINT,V_NULL);z++;p++;break;}
			}
			 }
	
	p++;break;
	}
//----------------------------------------------------------------------
case '^':{
	if(flag_esc==1){
		if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
		if(c!=s[z] && v_char_exists(vect)==true){printf("Report 3: no exists - \"%c\"!!! \n",c);return;}
		if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
		}else{flag_start=1;}
		p++;break;}
//----------------------------------------------------------------------
case '$':{if(flag_esc==1){
	if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
	if(c!=s[z] && v_char_exists(vect)==true){printf("Report 4: no exists - \"%c\"!!! \n",c);return;}
	if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
	}else{flag_end=1;}
	p++;break;}
//----------------------------------------------------------------------
case 'b':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 5: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}	
//----------------------------------------------------------------------
case 'B':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 6: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}
//----------------------------------------------------------------------
case 'd':{if(flag_esc==0){
	//printf("%c,%c\n",c,s[z]);
	if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
	if(c!=s[z] && v_char_exists(vect)==true){printf("Report 7: no exists - \"%c\" \"%c\"!!! \n",c,s[z]);return;}
	if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}
	}
	p++;break;
	}
//----------------------------------------------------------------------
case 'D':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 8: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}
//----------------------------------------------------------------------
case 's':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 9: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}
//----------------------------------------------------------------------
case 'S':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 10: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}
//----------------------------------------------------------------------
case 'w':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 11: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}
//----------------------------------------------------------------------
case 'W':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 12: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}	
//----------------------------------------------------------------------
case '*':{
	if(flag_esc==1){
	if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
	if(c!=s[z] && v_char_exists(vect)==true){printf("Report 13: no exists - \"%c\"!!! \n",c);return;}
	if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
	}else{
	//i=step_symbol(0,vect,s,p,oc,nc,c,end,i);z++;	
		}
p++;break;} 
//----------------------------------------------------------------------
case '+':{
if(flag_esc==1){
if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
if(c!=s[z] && v_char_exists(vect)==true){printf("Report 14: no exists - \"%c\"!!! \n",c);return;}
if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
}else{
	//i=step_symbol(0,vect,s,p,oc,nc,c,end,i);z++;
	}
p++;break;}
//----------------------------------------------------------------------
case '?':{
	if(flag_esc==1){
		if(c!=s[z] && v_char_exists(vect)==true){printf("Report 15: no exists - \"%c\"!!! \n",c);return;}
		if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
		if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
		}else{
			//?
		if(nc!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,nc);}	
			printf("?==%c,%c\n",nc,s[z]);
		if(nc==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;p++;p++;break;}
		else if(nc=='.'){if(s[z]!=e && s[z]!=end){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;p++;p++;break;}}
		else if(nc==17){i=add_tablae_symbol(vect,tb,count17,s[z],z,i);z++;count17++;p++;p++;break;}	
		else{i--;i--;i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);p++;z++;break;}
		//?	
			}
	p++;break;
	} 
//----------------------------------------------------------------------
case '{':{if(flag_esc==1){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 16: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}}p++;break;}
//----------------------------------------------------------------------
case '[':{
	if(flag_esc==1){
	if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
	if(c!=s[z] && v_char_exists(vect)==true){printf("Report 17: no exists - \"%c\"!!! \n",c);return;}
	if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
	}
	p++;break;
	}
//----------------------------------------------------------------------
case 17:{
	if(flag_esc==1){
		if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
		if(c!=s[z] && v_char_exists(vect)==true){printf("Report 18: no exists - \"%c\"!!! \n",c);return;}
		if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
		}else{
//printf("cure:%i\n",cure);
if(cure==0){			
if(vect->tp[i+1]==V_CHAR && s[z]!=end){i=add_tablae_symbol(vect,tb,count17,s[z],z,i);z++;count17++;p++;break;}else
if(vect->tp[i-1]==V_CHAR && s[z]!=end){i=add_tablae_symbol(vect,tb,count17,s[z],z,i);z++;count17++;p++;break;}else
{i=preg_add(vect,count17,z,i,VS_CLASS,V_NULL);z++;count17++;p++;break;}
		} 
			 }
count17++;p++;
break;
		}	
//----------------------------------------------------------------------
case '(':{if(flag_esc==1){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 18: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}}p++;break;}
//----------------------------------------------------------------------
default:{
	if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
	if(c!=s[z] && v_char_exists(vect)==true){printf("Report 19: no exists - \"%c\"!!! \n",c);return;}
	if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}
	p++;break;
	}
//----------------------------------------------------------------------
				}
vect->length=i;
if(*p==0 && v_char_exists(vect)==false && flag_start==0 && flag_end==0){
	
	z=0; p=p-i; i=0; count17=0;
	//printf("%c\n",*p);
	if(*p=='.'){printf("pfl:reback\n");i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;}
	if(*p==17){i=add_tablae_symbol(vect,tb,count17,s[z],z,i);z++;p++;}
	cure++;
	//printf("%i,%i\n",z,i);
																	   }
																	   
if(*p==0 && v_char_exists(vect)==false && flag_start==1 && flag_end==0){
	z=0; p=p-i; i=0; count17=0;
	if(*p=='.'){printf("pfl:reback\n");i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;}
	if(*p==17){i=add_tablae_symbol(vect,tb,count17,s[z],z,i);z++;p++;}
	cure++;
																	   }
																	   
if(*p==0 && v_char_exists(vect)==false && flag_start==0 && flag_end==1){
	z=strlen-1; count17--;
	p=p-(i+flag_end); i--; //printf("===%c\n",s[z]);
	if(*p=='.'){printf("pfl:reback\n");i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;p++;}
	if(*p==17){i=add_tablae_symbol(vect,tb,count17,s[z],z,i);z++;p++;p++;}
	cure++;
																       }
//!TODO: ^...$														


}

point_reindex(vect,tb,s);

free(s);
free(p);
free(bf);
return;
	}


///---------------------------------------------------------------------

