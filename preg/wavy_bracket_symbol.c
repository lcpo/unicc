///TODO: optimization of special
static int wavy_bracket_symbol(s_vect* vect, char* s, char* p,char oc,char nc,char c, char end, int i){
int plen=libc_strlen(p),slen=libc_strlen(s);
char* bf=malloc(plen);
char* quant=malloc(plen);
int n=0,z=0,co=0,fl=0;

while(*p!='}' && *p!='\0'){
quant[n]=*p;
p++;n++;
if(*p=='\0'){printf("error: no closing character '}'!!!\n");
//goto LABEL_EXIT_WHILE;
}
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
if(min>0){ ///TODO: colo.{1,}r //color
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
	return i;	
				
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
free(bf);
	return i;
	}
///---------------------------------------------------------------------
