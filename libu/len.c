#ifndef no_len //Допилить работу с многобайтовыми символами

uni _unic_len(uni* x){
	uni id=get_var_id(x);
	uni out=-1;
if(id!=-1){
char* type=get_var_type(x);
if(sch_count(type,'*')>1 && scmp(type,"char*")!=2){out=count((void*)*x);}
if(var_$t[id]==0 || var_$t[id]==1 || var_$t[id]==3 || var_$t[id]==11){out=lens((void*)*x);}
if(var_$t[id]==2){return 1;}
if(var_$t[id]==4 || var_$t[id]==8){out=leni((int)*x);}
if(var_$t[id]==5 || var_$t[id]==9){out=lenl((long)*x);}
if(var_$t[id]==6){float f=*(float*)(x); out=lenf(f);}
if(var_$t[id]==7){double d=*(double*)(x); out=lend(d);}
if(var_$t[id]==24){double ld=*(double*)(x); out=lenld(ld);}
		   }
return out;
					}

#define len(x) (_unic_len((uni*)&x))
#endif
