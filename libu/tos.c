#ifndef no_tos
char* _unic_tos(uni* x){
	uni id=get_var_id(x);
	char* out;
if(id!=-1){
char* type=get_var_type(x);
if(libc_sch_count(type,'*')>1 && libc_scmp(type,"char*")!=2){void** buff=*(void**)(x); return buff[0];}
if(var_$t[id]==0 || var_$t[id]==1 || var_$t[id]==3 || var_$t[id]==11){return (void*)*x;}
if(var_$t[id]==2){out=(char*)(x);}
if(var_$t[id]==4 || var_$t[id]==8){return libc_itos((int)*x);}
if(var_$t[id]==5 || var_$t[id]==9){return libc_ltos((long)*x);}
if(var_$t[id]==6){float f=*(float*)(x);return libc_ftos((float)f);}
if(var_$t[id]==7){double d=*(double*)(x); return libc_dtos((long double)d);}
if(var_$t[id]==24){long double ld=*(long double*)(x); return libc_ldtos((long double)ld);}
				}
return (char*)x;
					}
#define tos(x) (_unic_tos((uni*)&x))
#endif
