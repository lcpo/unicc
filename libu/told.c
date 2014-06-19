#ifndef no_told
long double _unic_told(uni* x){
	uni id=get_var_id(x);
	long double out=0;
	char* buff;
if(id!=-1){
char* type=get_var_type(x);
if(libc_sch_count(type,'*')>0 && libc_scmp(type,"char")==1){buff=(void*)*x; out=libc_stod((void*)buff);
}else{out=*(long double*)(x);}
		   }
return out;
	}
#define told(x) (_unic_told((uni*)&x))
#endif

