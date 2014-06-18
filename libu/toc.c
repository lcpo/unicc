#ifndef no_toc
char _unic_toc(uni* x){
	uni id=get_var_id(x);
	char out='\0';
	char* buff;
if(id!=-1){
char* type=get_var_type(x);
if(sch_count(type,'*')>1 && scmp(type,"char*")!=2){buff=(void*)*x; out=buff[0];}
if(var_$t[id]==0 || var_$t[id]==1 || var_$t[id]==3 || var_$t[id]==11){buff=(void*)*x; out=buff[0];}
if(var_$t[id]==2){buff=(void*)*x; out=buff[0];}
if(var_$t[id]==4 || var_$t[id]==8){buff=itos((int)*x);out=(char)buff[0];}
if(var_$t[id]==5 || var_$t[id]==9){buff=ltos((long)*x);out=(char)buff[0];}
if(var_$t[id]==6){float f=*(float*)(x);buff=ftos(f);out=(char)buff[0];}
if(var_$t[id]==7){double d=*(double*)(x);buff=dtos(d);out=(char)buff[0];}
if(var_$t[id]==24){double ld=*(double*)(x);buff=ldtos(ld);out=(char)buff[0];}
		   }
return out;
	}
#define toc(x) (_unic_toc((uni*)&x))
#endif
