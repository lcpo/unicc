
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
i=0,z=0,n=0,co=0,flag_esc=0,count_esc=0,back=0,old_z=0;
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
if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}
if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
}p++;break;}
//----------------------------------------------------------------------
case '.':{
	if(flag_esc==1){
		if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
		if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}
		if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
		}else{
if(vect->tp[i+1]==V_CHAR && s[z]!=end){i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;break;}else
if(vect->tp[i-1]==V_CHAR && s[z]!=end){i=preg_add(vect,s[z],z,i,V_CHAR,V_POINT);z++;p++;break;}else
{i=preg_add(vect,0,0,i,V_POINT,V_NULL);z++;p++;break;}
		
			}
	
	p++;break;
	}
//----------------------------------------------------------------------
case '^':{if(flag_esc==1){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}}p++;break;}
//----------------------------------------------------------------------
case '$':{if(flag_esc==1){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}}p++;break;}
//----------------------------------------------------------------------
case 'b':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}	
//----------------------------------------------------------------------
case 'B':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}
//----------------------------------------------------------------------
case 'd':{if(flag_esc==0){
	
	if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
	if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\" \"%c\"!!! \n",c,s[z]);return;}
	if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}
	}
	p++;break;
	}
//----------------------------------------------------------------------
case 'D':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}
//----------------------------------------------------------------------
case 's':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}
//----------------------------------------------------------------------
case 'S':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}
//----------------------------------------------------------------------
case 'w':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}
//----------------------------------------------------------------------
case 'W':{if(flag_esc==0){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}}p++;break;}	
//----------------------------------------------------------------------
case '*':{if(flag_esc==1){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}}p++;break;} 
//----------------------------------------------------------------------
case '+':{if(flag_esc==1){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}}p++;break;}
//----------------------------------------------------------------------
case '?':{
	if(flag_esc==1){
		if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}
		if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
		if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}
		}else{
			//?
		if(nc==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}else{p++;break;}
		//?	
			}
	p++;break;
	} 
//----------------------------------------------------------------------
case '{':{if(flag_esc==1){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}}p++;break;}
//----------------------------------------------------------------------
case '[':{if(flag_esc==1){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}}p++;break;}
//----------------------------------------------------------------------
case '(':{if(flag_esc==1){if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;flag_esc=0;}}p++;break;}
//----------------------------------------------------------------------
default:{
	if(c!=s[z] && v_char_exists(vect)==false){z=libc_chrpos(s,c);}
	if(c!=s[z] && v_char_exists(vect)==true){printf("Report: no exists - \"%c\"!!! \n",c);return;}
	if(c==s[z]){i=preg_add(vect,s[z],z,i,V_CHAR,V_NULL);z++;}
	p++;break;
	}
//----------------------------------------------------------------------
				}
vect->length=i;

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
/*
char char_point_table[]={
0,1,2,3,4,5,6,7,8,9,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,
29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,
53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,
77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,
101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,
119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,
137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,
155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,
173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,
191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,
209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,
227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,
245,246,247,248,249,250,251,252,253,254,255};
//----------------------------------------------------------------------
char ispoint(char ch){
int i=0;
for(;i<255;i++){if(ch==char_point_table[i]){return ch;}}
return -1;	
	}
*/
//----------------------------------------------------------------------
//	-1  unknown
//	 0  possible
//	 1  know
//U
/*
if(flag==LAZY){	
if(nc==s[z]){
		n=0;
		while(*p!=0){if(is_end_step(*p)==-1 || *p!=0){bf[n]=*p;n++;p++;}else{break;}}p=p-n;
		char* sbf=libc_strpart(s+z,0,n);
		if(libc_strcmp(bf,sbf)==0){
			//printf("yes|bf=%s|sbf=%s\n",bf,sbf);
			while(*sbf!=0){
				if(*sbf==s[z]){
					vect->code[i]=s[z];
					vect->fn[i]=know;
					vect->pos[i]=z;
					vect->tp[i]=V_CHAR;
					vect->otp[i]=V_POINT;
					i++;
					}else{break;}sbf++;z++;
					}
			break;
			}else{
				//printf("no|bf=%s|sbf=%s\n",bf,sbf);
				z++;
				}
		
free(sbf);
			
	}
}
*/
