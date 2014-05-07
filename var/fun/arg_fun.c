/*
#ifndef _TYPE_UNIC_C
#include "../../utype.c"
#endif

	#ifndef $
#define $ unic_
	#endif

static char** arr_$n;
static char** arr_$i;
static int arr_$l;

//----------------------------------------------------------------------

int mass_elem_args(char* s){
int nom,v,mv,pl,lp;
nom=0;
v=0;
mv=0;
pl=0;
lp=0;
char* nm=malloc(0);
char* mn=malloc(0);
while(s[nom]!=0){
if(s[nom]=='['){mv=1;}
if(mv==0){mn[lp]=s[nom];lp++;} //копируем имя массива
if(s[nom-1]!='['){v++;}
if(s[nom]!=']'){v--;} //копируем аргумент индекса
if(v!=0){nm[pl++]=s[nom++];}else{nom++;}
				}
if(arr_$l<1){
arr_$n=malloc(0);
arr_$i=malloc(0);
}else{
arr_$n=realloc(arr_$n,count((void**)arr_$n)+1);
arr_$i=realloc(arr_$i,count((void**)arr_$i)+1);
			}
arr_$n[arr_$l]=mn;
arr_$i[arr_$l]=nm;
arr_$l=arr_$l+1;
if(sch(nm,'[')==1){mass_elem_args(nm);}{return -1;}
							}

//----------------------------------------------------------------------
uni get_item_mass_elem_args(uni ind_arr){
uni index;
int nom,pl;
if(ind_arr!=-1){index=ind_arr;}else{

if(is_num(arr_$i[arr_$l-1])==0){
nom=0; pl=-1;
while(var_$n[nom]!=NULL){if(scmp(arr_$i[arr_$l-1],var_$n[nom])==2){pl=nom;}nom++;}
if(pl!=-1){index=(uni)*var_$[pl];}else{index=-1;} //error
								}else{index=atoi(arr_$i[arr_$l-1]);}
									}

nom=0; pl=-1; void** el;
while(var_$n[nom]!=NULL){if(scmp(arr_$n[arr_$l-1],var_$n[nom])==2){pl=nom;}nom++;}

if(pl!=-1){el=(void*)*var_$[pl];}else{el=NULL;} //error
arr_$n[arr_$l]=0; arr_$i[arr_$l]=0; arr_$l=arr_$l-1;
if(arr_$l!=0){get_item_mass_elem_args((uni)el[index]);}else{return (uni)el[index];}
										}
//----------------------------------------------------------------------
uni get_item(char* x){
if(sch(x,'[')==1){
return get_item_mass_elem_args(mass_elem_args(x));
}else{
return (uni)x;
}
					}
//----------------------------------------------------------------------
inline char ** get_arg(char* str_arg, void** addr_arg){
uni mem=lens(str_arg)+1;
char** buff=malloc(mem);
char** out=malloc(mem);
int* vect=malloc(mem);
int veci=0;
int ign=0;
int kv=0;
int i=0;

while(str_arg[i]!=0){
switch(str_arg[i]){
case '"':ign=i;kv++; break;
case '\'':ign=i;kv++; break;
case '\\':ign=0;kv--; break;
				  }
if(str_arg[i]==',' || str_arg[i]=='.'){
if(odd(kv)==0){vect[veci++]=i;}
if(ign==i && odd(kv)==0){vect[veci++]=i;}
									  }i++;
				}
i=0;
buff[i]=str_arg;
while(veci>i){buff[i+1]=str_arg+(vect[i]+1);i++;}
i=0;
ign = 0; kv=0;

while(veci>i){
out[i]=malloc((vect[i]+1));
int n=0;

while(buff[i][n]!=0 && buff[i][n]!='"' && buff[i][n+1]!='"' && buff[i][n]!='\'' && buff[i][n+1]!='\'' ){
if(buff[i][n]!=',' && buff[i][n]!='.'){
	out[i][n]=buff[i][n];
	}n++;}
n=0;

ign =0; kv =0;
//----
// && buff[i][0]=='\''

while(buff[i][n]!=0 && buff[i][0]=='"'){
switch(buff[i][n]){
case '\'' :out[i][n]='\''; kv++;  break;
case '"' :out[i][n]='"'; kv++;  break;
case '\\':out[i][n]='\\'; kv--; break;
case ',':if(odd(kv)!=0){out[i][n]=',';} break;
case '.':if(odd(kv)!=0){out[i][n]='.';} break;
default :out[i][n]=buff[i][n]; break;
				  }
n++;									}
//-------------------------------------------------
ign =0; kv =0;
while(buff[i][n]!=0 && buff[i][0]=='\''){
switch(buff[i][n]){
case '\'' :out[i][n]='\''; kv++;  break;
case '"' :out[i][n]='"'; kv++;  break;
case '\\':out[i][n]='\\'; kv--; break;
case ',':if(odd(kv)!=0){out[i][n]=',';} break;
case '.':if(odd(kv)!=0){out[i][n]='.';} break;
default :out[i][n]=buff[i][n]; break;
				  }
n++;									}




i++;
			}
if(buff[i]!=0){
out[i]=malloc(vect[i]+1);
out[i]=buff[i];
				}

return out;
	}

#define name_arg(p...)({\
char** args=get_arg(#p,NULL);int i=0;\
while(args[i]!=NULL){\
print((char*)get_item(args[i]),lens((char*)get_item(args[i])));\
print("\n",1);i++;}\
})
*/
