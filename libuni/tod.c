#ifndef no_tod
double _unic_tod(uni* x){
	uni id=get_var_id(x);
	double out=0;
	char* buff;
if(id!=-1){
char* type=get_var_type(x);
if(sch_count(type,'*')>0 && scmp(type,"char")==1){buff=(void*)*x; out=stod((void*)buff);}else
{out=*(double*)(x);}
		   }
return out;
	}
#define tod(x) (_unic_tod((uni*)&x))
#endif

