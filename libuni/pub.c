#ifndef no_pub
/*
	set_type_item("void");												//0 //1
	set_type_item("void*");												//1	//8
	set_type_item("char");												//2 //1
	set_type_item("char*");												//3	//8
	set_type_item("int");												//4	//4
	set_type_item("long");												//5	//8
	set_type_item("float");												//6	//4
	set_type_item("double");											//7 //8
	set_type_item("short");												//8	//2
	set_type_item("uni");												//9		// old
	set_type_item("size");												//10 	// old
	set_type_item("wchar");												//11 	// old
*/


int _unic_pub(uni* x){
	uni id=get_var_id(x);
if(id!=-1){
char* type=get_var_type(x);
char* buff;
if(sch_count(type,'*')>1 && scmp(type,"char*")!=2){write($O,"Array",5); 			return 1;}
if(var_$t[id]==0 || var_$t[id]==1 || var_$t[id]==3 || var_$t[id]==11){write($O,(void*)*x,lens((void*)*x)); 					return 1;}
if(var_$t[id]==2){char bf[0];bf[0]=(char)*x;write($O,bf,1);				return 1;}
if(var_$t[id]==4 || var_$t[id]==8){write($O,itos((int)*x),leni((int)*x)+1);					return 1;}
if(var_$t[id]==5 || var_$t[id]==9){write($O,ltos((long)*x),lenl((long)*x)+1);				return 1;}

if(var_$t[id]==6){float f=*(float*)(x);
buff=ftos((float)f);
write($O,buff,lens((void*)buff));
		return 1;}
		
if(var_$t[id]==7){
	double d=*(double*)(x);
	buff=dtos((double)d); 
	write($O,buff,lens((void*)buff));	
	return 1;}
	
if(var_$t[id]==24){
	long double ld=*(long double*)(x);
	buff=ldtos((long double)ld);
	write($O,buff,lens((void*)buff)); 
	return 1;
	}
				}
return 0;
					}
#define pub(x) ({\
((_unic_pub((uni*)&x)==0)?(write($O,(char*)&x,lens((char*)&x))):1);\
})

#endif
