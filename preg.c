//!TODO: []
//!TODO: \S\W\B\G
//!TODO: ^$
//!TODO: (|)
//!TODO: (..)
//!TODO: (?=)
//!TODO: preg_match
//!TODO: preg_match_all
//!TODO: preg_replace
//!TODO: preg_split

typedef enum {false,true}bool;
typedef enum {unknown=-1,possible=0,know=1}finding;
typedef enum {V_CHAR,V_ESC,V_POINT,VS_CLASS,V_GROUP}vect_type;



typedef struct s_vect{
char* code;	
uni* pos;
finding* fn;
vect_type* tp;
vect_type* otp;
size_t length;	
}s_vect;

///------------------------------------------------------------
void rep_point(s_vect* vect,char* s,int i, int n){
		if(vect->code[i-n]==0 && vect->tp[i-n]==V_POINT){
			vect->code[i-n]=s[vect->pos[i]-n];
			vect->fn[i-n]=know;
			vect->pos[i-n]=vect->pos[i]-n;
			vect->tp[i-n]=V_CHAR;
			vect->otp[i-n]=V_POINT;
			}	
return;
	}
///------------------------------------------------------------

char end_step[]={'(','[','{','?','!','.','+','*'};
int is_end_step(char ch){
int i=0;
for(;i<8;i++){if(ch==end_step[i]){return ch;}}
return -1;	
	
	}

///------------------------------------------------------------

void preg(s_vect* vect,char* pt,char* str){
int slen=libc_strlen(str)-1,plen=libc_strlen(pt),fl=0,i=0,z=0,n=0,co=0;
char* p=malloc(plen);
char* s=malloc(slen+1);
char* bf=malloc(plen);
char vbf[1];
libc_strcpy(s,str);
libc_strcpy(p,pt);

char oc='\0';	//старый
char c=*p; 		//Текущий
char nc=*p++;	//Новый
p--;
char end='\n';

while (*p!=0){
c=*p;
p--;oc=*p;p++;
p++;nc=*p;p--;

switch(*p){
//----------------------------------------------------------------------
case '\\':{
	p++; i--;
break;	
		  }	
//----------------------------------------------------------------------
LABEL_CHARS:
case 'q':case 'w':case 'e':case 'r':case 't':case 'y':case 'u':
case 'i':case 'o':case 'p':case 'a':case 's':case 'd':case 'f':
case 'g':case 'h':case 'j':case 'k':case 'l':case 'z':case 'x':
case 'c':case 'v':case 'b':case 'n':case 'm':case '&':
case '1':case '2':case '3':case '4':case '5':case '6':case '7':
case '8':case '9':case '0':{
for(z=0;z<slen+1;z++){
if(c==s[z] && vect->pos[i-1]==0){vect->code[i]=c;vect->fn[i]=know;vect->pos[i]=z; vect->tp[i]=V_CHAR;i++;break;}
if(c==s[z] && (z-vect->pos[i-1])==1){vect->code[i]=c;vect->fn[i]=know;vect->pos[i]=z;vect->tp[i]=V_CHAR;i++;break;}	
					 }
//printf("%c|\n",vect->code[i-1]);					 
p++;i--;
break;
	}
//----------------------------------------------------------------------
case '.':{
	
if(oc=='\\'){
for(z=0;z<slen+1;z++){
if(c==s[z] && vect->pos[i-1]==0){vect->code[i]=s[z];vect->fn[i]=know;vect->pos[i]=z;vect->tp[i]=V_CHAR;break;}
if(c==s[z] && (z-vect->pos[i-1])==1){vect->code[i]=s[z];vect->fn[i]=know;vect->pos[i]=z;vect->tp[i]=V_CHAR;break;}
		
					 }		
	
	}else{
		
	if(vect->code[i-1]!=0){
	vect->code[i]=s[vect->pos[i-1]+1];vect->fn[i]=know;vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR; vect->otp[i]=V_POINT;
		}else{
			vect->pos[i]=0;vect->fn[i]=0; vect->code[i]=0;vect->tp[i]=V_POINT;
			}
}


p++;	
break;	
		}
//----------------------------------------------------------------------
case '*':{
p++;
z=vect->pos[i-1];
if(oc!=s[z] && vect->otp[i-1]!=V_POINT){
vect->code[i]=0;vect->fn[i]=0;vect->pos[i]=0;vect->tp[i]=0; vect->otp[i]=0; i--;
}else{
if(nc=='?' && c!='\\'){p++;
libc_memchr(bf,0,plen);	
n=0; 
while(*p!=0){if(is_end_step(*p)==-1 || *p!=0){bf[n]=*p;n++;p++;}else{break;}}
p=p-n;
do{
vect->code[i]=s[vect->pos[i-1]+1];vect->fn[i]=know;vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;i++;z++;
}while(libc_strncmp(s+z,bf,n)!=0 && s[z]!=end && s[z]!=0);
	i--;
}else{
libc_memchr(bf,0,plen);	
n=0; 
while(*p!=0){if(is_end_step(*p)==-1 || *p!=0){bf[n]=*p;n++;p++;}else{break;}}
do{
vect->code[i]=s[vect->pos[i-1]+1];vect->fn[i]=know;vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;i++;z++;
}while(libc_substr_count(s+(z+1),bf)>0 && s[z+n]!=end && s[z]!=0);
	i--;
	}
	
	}

	break;
	} 
//----------------------------------------------------------------------
	
case '?':{p++;
z=vect->pos[i-1];
if(oc!=s[z]){vect->code[i]=0;vect->fn[i]=0;vect->pos[i]=0;vect->tp[i]=0; vect->otp[i]=0; i--;
}else{
vect->code[i]=s[vect->pos[i-1]+1];vect->fn[i]=know;vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;
p++;	
	}
break;
		 } 
//----------------------------------------------------------------------
case '+':{
p++;
z=vect->pos[i-1];
if(oc!=s[z] && vect->otp[i-1]!=V_POINT){
//vect->code[i]=0;vect->fn[i]=0;vect->pos[i]=0;vect->tp[i]=0; vect->otp[i]=0; i--;
p++;i--;
}else{
if(nc=='?' && c!='\\'){p++;
libc_memchr(bf,0,plen);	
n=0; 
while(*p!=0){if(is_end_step(*p)==-1 || *p!=0){bf[n]=*p;n++;p++;}else{break;}}
p=p-n;
do{
vect->code[i]=s[vect->pos[i-1]+1];vect->fn[i]=know;vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;i++;z++;
}while(libc_strncmp(s+z,bf,n)!=0 && s[z]!=end && s[z]!=0);
	i--;
}else{
libc_memchr(bf,0,plen);	
n=0; 
while(*p!=0){if(is_end_step(*p)==-1 || *p!=0){bf[n]=*p;n++;p++;}else{break;}}
do{
vect->code[i]=s[vect->pos[i-1]+1];vect->fn[i]=know;vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;i++;z++;
}while(libc_substr_count(s+(z+1),bf)>0 && s[z+n]!=end && s[z]!=0);
	i--;
	}
	}	

	break;
	} 
//----------------------------------------------------------------------	 
case '{':{
char* quant=malloc(plen);
n=0;p++;
while(*p!='}' && *p!='\0'){
quant[n]=*p;
p++;n++;
if(*p=='\0'){printf("error: no closing character '}'!!!\n");goto LABEL_EXIT_WHILE;}
}
int pos=libc_strpos(quant,",");
if(pos==-1){

co=libc_stoi(quant)-1;

if(co>=0){
//----	
p++;
z=vect->pos[i-1]+1;
if(vect->otp[i-1]==V_POINT){
	//printf("==%c\n",*p);
libc_memchr(bf,0,plen);	
n=0; 
while(*p!=0){if(is_end_step(*p)==-1 || *p!=0){bf[n]=*p;n++;p++;}else{break;}}
p=p-n;
do{
vect->code[i]=s[vect->pos[i-1]+1];vect->fn[i]=know;vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;i++;z++;co--;
}while(libc_strncmp(s+z,bf,n)!=0 && s[z]!=end && s[z]!=0 && co>0);
	//i--;	
	
	}
///-----------------------------
if(vect->otp[i-1]==V_CHAR){
while(co>0 && s[z]!=end){
	if(s[z]==oc){
		vect->code[i]=s[z];
		vect->fn[i]=know;
		vect->pos[i]=vect->pos[i-1]+1;	
		vect->tp[i]=V_CHAR;	
		i++;co--;z++;
	}else{
		vect->code[i-1]=0;
		vect->fn[i-1]=0;
		vect->pos[i-1]=0;
		vect->tp[i-1]=0; 
		vect->otp[i-1]=0;
		i--;break;}
		}
						}
///-----------------------------
}else{vect->code[i-1]=0;vect->fn[i-1]=0;vect->pos[i-1]=0;vect->tp[i-1]=0; vect->otp[i-1]=0; i--;  }


}else{
char* bf1=malloc(plen);
char* bf2=malloc(plen);
n=0;fl=0;
while(*quant!='\0'){
if(*quant==','){fl=1;quant++;n=0;}
if(fl==0){bf1[n]=*quant;}else{bf2[n]=*quant;}
quant++;n++;	
					}

int min=libc_stoi(bf1);
int max=libc_stoi(bf2)+1;
/*
printf("min==%i\n",min);
printf("max==%i\n",max);
printf("--%c\n",*p);
*/
//--------

if(min<max && min>0 && max>0){
	p++;
z=vect->pos[i-1];
///-----------------------------
n=0;fl=0; co=z+min;
if(vect->otp[i-1]==V_CHAR){
	
while(z<co){
	if(s[z]==oc){vect->code[i]=s[z];vect->fn[i]=know;vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;i++;z++;fl++;}else{vect->code[i]=0;vect->fn[i]=0;vect->pos[i]=0;vect->tp[i]=0;vect->otp[i]=0;fl=0;i--;break;}
n++;	
	}	
while(n<max){
	if(s[z]==oc && fl==min){vect->code[i]=s[z];vect->fn[i]=know;vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;i++;z++;}else{vect->code[i-1]=0;vect->fn[i-1]=0;vect->pos[i-1]=0;vect->tp[i-1]=0;vect->otp[i-1]=0;i--;i--;	break;}
		n++;
	}
						}
///-----------------------------11111
z++; 
if(vect->otp[i-1]==V_POINT){
	//printf("==%c\n",*p);
libc_memchr(bf,0,plen);	
n=0; 
while(*p!=0){if(is_end_step(*p)==-1 || *p!=0){bf[n]=*p;n++;p++;}else{break;}}
p=p-n;
co=0;
do{
z++;max--;co++;
}while(libc_strncmp(s+z,bf,n)!=0 && s[z]!=end && s[z]!=0 && max>min);
z=z-co;
max=max+co;

do{
vect->code[i]=s[vect->pos[i-1]+1];
vect->fn[i]=know;
vect->pos[i]=vect->pos[i-1]+1;
vect->tp[i]=V_CHAR;
vect->otp[i]=V_POINT;
i++;z++;max--;
if(vect->code[i-1]==0){i--;break;}
}while(libc_strncmp(s+z,bf,n)!=0 && s[z]!=end && s[z]!=0 && max>min);
	i--;	
//printf("sum=%i|co=%i|min=%i|max=%i\n",(min-max),co,min,max+co);
if((min-max)==-1 && co>min){
	//printf("err\n");
	vect->code[i-1]=0;vect->fn[i-1]=0;vect->pos[i-1]=0;vect->tp[i-1]=0; vect->otp[i-1]=0; i--; 
	}
	}
///-----------------------------2222
	}else{
if(min>0){ ///TODO:: colo.{1,}r //color
printf("fl0\n");
	p++;
z=vect->pos[i-1];
///-----------------------------
n=0;fl=0; co=z+min;
if(vect->otp[i-1]==V_CHAR){
	
while(z<co){
	if(s[z]==oc){vect->code[i]=s[z];vect->fn[i]=know;vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;i++;z++;fl++;}else{vect->code[i]=0;vect->fn[i]=0;vect->pos[i]=0;vect->tp[i]=0;vect->otp[i]=0;fl=0;i--;break;}
n++;	
	}	
while(s[z]!=end){
	if(s[z]==oc && fl==min){vect->code[i]=s[z];vect->fn[i]=know;vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;i++;z++;}else{vect->code[i-1]=0;vect->fn[i-1]=0;vect->pos[i-1]=0;vect->tp[i-1]=0;vect->otp[i-1]=0;i--;i--;	break;}
		n++;
	}
						}
///-----------------------------
z++; 
if(vect->otp[i-1]==V_POINT){
	//printf("==%c\n",*p);
	max=slen;
libc_memchr(bf,0,plen);	
n=0; 
while(*p!=0){if(is_end_step(*p)==-1 || *p!=0){bf[n]=*p;n++;p++;}else{break;}}
p=p-n;
co=0;
do{
z++;max--;co++;
}while(libc_strncmp(s+z,bf,n)!=0 && s[z]!=end && s[z]!=0 && max>min);
z=z-co;
max=max+co;

do{
vect->code[i]=s[vect->pos[i-1]+1];
vect->fn[i]=know;
vect->pos[i]=vect->pos[i-1]+1;
vect->tp[i]=V_CHAR;
vect->otp[i]=V_POINT;
i++;z++;max--;
if(vect->code[i-1]==0){i--;break;}
}while(libc_strncmp(s+z,bf,n)!=0 && s[z]!=end && s[z]!=0 && max>min);
	i--;	
//printf("sum=%i|co=%i|min=%i|max=%i\n",(min-max),co,min,max+co);
if((min-max)==-1 && co>min){
	//printf("err\n");
	vect->code[i-1]=0;vect->fn[i-1]=0;vect->pos[i-1]=0;vect->tp[i-1]=0; vect->otp[i-1]=0; i--; 
	}
						}
///-----------------------------
						
///-----------------------------								
	}else if(max>0){
	printf("fl2\n");
	p++;
z=vect->pos[i-1];
///-----------------------------
n=0;fl=0;
if(vect->otp[i-1]==V_CHAR && max>1){
	
while(n<max){
	if(s[z]==oc){vect->code[i]=s[z];vect->fn[i]=know;vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;i++;z++;
	}else{

		if(n>0){
		vect->code[i-1]=0;vect->fn[i-1]=0;vect->pos[i-1]=0;vect->tp[i-1]=0;vect->otp[i-1]=0;i--;i--;
		}else{i--;}
		break;}
		n++;
			}
			}else{
//----
			
if(oc!=s[z] && vect->otp[i-1]!=V_POINT){ //+
//vect->code[i]=0;vect->fn[i]=0;vect->pos[i]=0;vect->tp[i]=0; vect->otp[i]=0; i--;
p++;i--;
}else{

if(*p=='?' && c!='\\'){p++;
libc_memchr(bf,0,plen);	
n=0; 
while(*p!=0){if(is_end_step(*p)==-1 || *p!=0){bf[n]=*p;n++;p++;}else{break;}}
p=p-n;
do{
vect->code[i]=s[vect->pos[i-1]+1];vect->fn[i]=know;vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;i++;z++;
}while(libc_strncmp(s+z,bf,n)!=0 && s[z]!=end && s[z]!=0);
	i--;
}else{
libc_memchr(bf,0,plen);	
n=0; 
while(*p!=0){if(is_end_step(*p)==-1 || *p!=0){bf[n]=*p;n++;p++;}else{break;}}
do{
vect->code[i]=s[vect->pos[i-1]+1];vect->fn[i]=know;vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;i++;z++;
}while(libc_substr_count(s+(z+1),bf)>0 && s[z+n]!=end && s[z]!=0);
	i--;
	}
	
	}	
		/**/
	free(quant);
	free(bf1);
	free(bf2);
	p--;
	break;	
				
				}
	//-----				
if(vect->otp[i-1]==V_POINT && max==1){

if(oc!=s[z] && vect->otp[i-1]!=V_POINT){ //*
vect->code[i]=0;vect->fn[i]=0;vect->pos[i]=0;vect->tp[i]=0; vect->otp[i]=0; i--;
}else{
if(*p=='?' && c!='\\'){p++;
libc_memchr(bf,0,plen);	
n=0; 
while(*p!=0){if(is_end_step(*p)==-1 || *p!=0){bf[n]=*p;n++;p++;}else{break;}}
p=p-n;
do{
vect->code[i]=s[vect->pos[i-1]+1];vect->fn[i]=know;vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;i++;z++;
}while(libc_strncmp(s+z,bf,n)!=0 && s[z]!=end && s[z]!=0);
	i--;
}else{
libc_memchr(bf,0,plen);	
n=0; 
while(*p!=0){if(is_end_step(*p)==-1 || *p!=0){bf[n]=*p;n++;p++;}else{break;}}
do{
vect->code[i]=s[vect->pos[i-1]+1];vect->fn[i]=know;vect->pos[i]=vect->pos[i-1]+1;vect->tp[i]=V_CHAR;i++;z++;
}while(libc_substr_count(s+(z+1),bf)>0 && s[z+n]!=end && s[z]!=0);
	i--;
	}
	/*
	free(quant);
	free(bf1);
	free(bf2);
	p--;
	break;	*/
	}
	
//-----
	}		
			

///-----------------------------
			
	}else{
			printf("fl3\n");
vect->code[i-1]=0;vect->fn[i-1]=0;vect->pos[i-1]=0;vect->tp[i-1]=0; vect->otp[i-1]=0; i--; 
}
		}
//--------
free(bf1);
free(bf2);	
	}

free(quant);	
	break;
	}
//----------------------------------------------------------------------
case '[':{p++;break;}
//----------------------------------------------------------------------
default:{p++;i--;break;}	
	}
i++;
}

LABEL_EXIT_WHILE:
vect->length=i;
while(i>0){rep_point(vect,s,i,1);i--;}

free(s);
free(p);
free(bf);

	}
///------------------------------------------------------------
void free_vect(s_vect* vect){
free(vect->pos);
free(vect->fn);
free(vect->tp);
free(vect->otp);
free(vect->code);
free_ptr(vect);
return;	
	}

///------------------------------------------------------------
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
