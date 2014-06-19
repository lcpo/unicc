#ifndef no_tod
double _unic_tod(uni* x){
	uni id=get_var_id(x);
	double out=0;
	char* buff;
if(id!=-1){
char* type=get_var_type(x);
if(libc_sch_count(type,'*')>0 && libc_scmp(type,"char")==1){buff=(void*)*x; out=libc_stod((void*)buff);}else
{out=*(double*)(x);}
		   }
return out;
	}
#define tod(x) (_unic_tod((uni*)&x))
#endif

