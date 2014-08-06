
#define travel3(str,oc,c,nc)({c=*str;str--;oc=*str;str++;str++;nc=*str;str--;}) 
#define travel5(str,ooc,oc,c,nc,nnc)({c=*str;str--;str--;ooc=*str;str++;str++;str--;oc=*str;str++;str++;nc=*str;str--;str++;str++;nc=*str;str--;str--;})

typedef enum {false,true}bool;
typedef enum {V_NULL,V_CHAR,V_POINT,VS_CLASS,V_GROUP}vect_type;


typedef struct s_vect{
char* c;	
uni* pos;
vect_type* tp;
vect_type* otp;
size_t length;
char* table;
int table_length;
int flag_denial;
						}s_vect;

///---------------------------------------------------------------------
typedef struct ch_tab{
int rep;
char** table_src;
char** table;
size_t table_count;
size_t length;
char tag_start;
char tag_end;
	}ch_tab;

///---------------------------------------------------------------------
#include "bracket_symbol.c"
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
//char end_step[]={'(','[','{','?','!','.','+','*'};
//char end_step_others[]={')','}',']',' ','|',','};
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
void point_reindex(s_vect* vect,char* s){
int i=0,co=0;
while(i<vect->length){
	if(vect->tp[i]==V_CHAR && vect->tp[i+1]==V_POINT){vect->c[i+1]=s[vect->pos[i]+1];vect->pos[i+1]=vect->pos[i]+1;	vect->tp[i+1]=V_CHAR;vect->otp[i+1]=V_POINT;}	
	i++;
	}
	
i=0;co=0;
while(i<vect->length){
	if(vect->tp[i]==V_CHAR && vect->tp[i-1]==V_POINT){vect->c[i-1]=s[vect->pos[i]-1];vect->pos[i-1]=vect->pos[i]-1;	vect->tp[i-1]=V_CHAR;vect->otp[i-1]=V_POINT;}	
	i++;
	}
	
return;	
	}
	
///---------------------------------------------------------------------
void preg(s_vect* vect,char* pt,char* str){
int strlen=libc_strlen(str),
 patlen=libc_strlen(pt),
i=0,z=0,n=0,co=0,flag_esc=0,count_esc=0,flag_start=0,flag_end=0,back=0,old_i=0,old_z=0,count17=0;
char *p=malloc(patlen),*s=malloc(strlen),*bf=malloc(patlen);
libc_strcpy(s,str); libc_strcpy(p,pt);


char oc='\0',end='\n',e='\0',c=*p,nc=*p++; p--;
while (*p!=e){
travel3(p,oc,c,nc);
point_reindex(vect,s);
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
		if(c!=s[z] && v_char_exists(vect)==true){printf("Report 2: no exists - \"%c\"!!! \n",c);return;}
		if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
		}else{
if(vect->tp[i+1]==V_CHAR && s[z]!=end){i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;break;}else
if(vect->tp[i-1]==V_CHAR && s[z]!=end){i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;break;}else
{i=preg_add(vect,0,0,i,V_POINT,V_NULL);z++;p++;break;}
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
	printf("%c,%c\n",c,s[z]);
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
case '*':{if(flag_esc==1){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 13: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}}p++;break;} 
//----------------------------------------------------------------------
case '+':{if(flag_esc==1){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report 14: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}}p++;break;}
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
		if(nc==s[z]){
			i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;p++;p++;break;
		}else{i--;i--;i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);p++;z++;break;}
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
/*
	else{
		i=bracket_symbol(vect,s,p,oc,nc,c,end,i);
		p++;break;
		}
*/
	p++;break;
	}
//----------------------------------------------------------------------
case 17:{
i=add_tablae_symbol(vect,c,z,i);
count17++;
p++;
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
	z=0; p=p-i; i=0;
	if(*p=='.'){i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;}
																	   }
if(*p==0 && v_char_exists(vect)==false && flag_start==1 && flag_end==0){
	z=0; p=p-i; i=0;
	if(*p=='.'){i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;}
																	   }
if(*p==0 && v_char_exists(vect)==false && flag_start==0 && flag_end==1){
	z=strlen-1; 
	p=p-(i+flag_end); i--; //printf("===%c\n",s[z]);
	if(*p=='.'){i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;p++;}
	
																   }
//!TODO: ^...$																   																	   																	   
}

point_reindex(vect,s);

free(s);
free(p);
free(bf);
	}
///------------------------------------------------------------
void free_vect(s_vect* vect){
free_ptr(vect->pos);
free_ptr(vect->tp);
free_ptr(vect->otp);
free_ptr(vect->c);
free_ptr(vect);
return;	
	}

///---------------------------------------------------------------------

