#include "unic.h"
/*
//--------------------------------------------------------------------//
char* strpstr_nomo(char* str,char* ser){
if(strstr(str,ser)){
int len_ser=strlen(ser),len_str=strlen(str),len_nstr;
char* buff_strn=GC_malloc(0);
strcpy(buff_strn,"\0");
char* estr=strstr(str,ser)+len_ser;
int iestr=strlen(estr);
len_nstr=len_str-iestr-len_ser;
strncat(buff_strn,str,len_nstr);
char* out=buff_strn;
return out;
}else{return str;}
	}
//--------------------------------------------------------------------//
char** explode(char* se,char* str){
int i=0,l=0;char* new_s="";
int cou=substr_count(str,se)+1;
char* ret[cou];
while(l!=-1){
l=strpos(str,se);
new_s =strpstr_nomo(str,se);
ret[i]=new_s;
str=str+l+strlen(se);
	i++;
}
ret[i]='\0';
char** out=GC_realloc(0,sizeof(ret));
memcpy(out, ret, sizeof(ret));
return out;
	}

//--------------------------------------------------------------------//analog implode
#define concat_t(buff,a,b)({strcat(buff,a);strcat(buff,b);buff;})

char* implode(char* r,char** arri){
int i=0,n=5,n_arr=0,n_r=strlen(r);
char buff[1024];
memset(buff,'\0',sizeof(char));
while(arri[i]!=NULL){n_arr=n_arr+strlen(arri[i])+n_r;concat_t(buff,arri[i],r);i++;}
n_arr=n_arr-n_r;
strncat(buff,buff,n_arr);
char* out=buff+(n_arr+n_r);
strcpy(buff,"");
return out;
}
#define join implode
//--------------------------------------------------------------------//

*/





int main(int argc, char **argv){
init_type();
///----------------------------------------------------------------------
char* vtr=var(vtr,char*);
char** ot=var(ot,char**);


vtr="test1|test2|test3|";
pub(vtr);
/*
ot=explode("|",vtr);
int i=0;
while(ot[i]!=0){
	char** ex=explode("test",ot[i]);
	int n=0;
	while(ex[n]!=0){print(ex[n]);n++;}print("\n");

	i++;}
*/
pub("\n");

//print(implode("",ot));
//print("\n");
///----------------------------------------------------------------------

print_var();
print_reg_type();
//system("read -s -n 1");
exit(0);
return;
	}
