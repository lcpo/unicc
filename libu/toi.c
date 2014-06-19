#ifndef no_toi

int _unic_toi(uni* x){
	uni id=get_var_id(x);
	int out=-1;
if(id!=-1){
char* type=get_var_type(x);
if(var_$t[id]==0){out=(char)*x;} 									//0		void
if(var_$t[id]==1){out=libc_stoi((char*)*x);} 								//1		void*
if(var_$t[id]==2){out=(char)*x;} 									//2		char 
if(var_$t[id]==3){out=libc_stoi((char*)*x);}									//3		char*
if(var_$t[id]==4){out=(int)*x;}											//4 	int 
if(var_$t[id]==5){out=libc_ltoi((long)*x);}									//5 	long
//if(var_$t[id]==6){float f=*(float*)(x);out=libc_ftoi(f);}					//6 	float
//if(var_$t[id]==7){double d=*(double*)(x);out=libc_dtoi(d);}					//7 	double
if(var_$t[id]==8){out=(int)*x;}											//8 	short
if(var_$t[id]==9){out=libc_ltoi((long)*x);}									//9 	uni
//if(var_$t[id]==10){out=libc_ultoi((long)*x);}								//10	size
if(var_$t[id]==11){out=libc_stoi((char*)*x);}								//11	wchar
if(var_$t[id]==12){out=(char)*x;}									//12	signed char
if(var_$t[id]==13){out=(unsigned char)*x;}						//13	unsigned char
if(var_$t[id]==14){out=(int)*x;}										//14	short int
if(var_$t[id]==15){out=(int)*x;}		   		   						//15	signed short
if(var_$t[id]==16){out=(int)*x;}		   		   						//16	unsigned short
if(var_$t[id]==17){out=(int)*x;}										//17	unsigned short int
if(var_$t[id]==18){out=(int)*x;}		   		   						//18	signed
if(var_$t[id]==19){out=(int)*x;}		   		   						//19	signed int
if(var_$t[id]==20){out=(int)*x;}		   		   						//20	unsigned
if(var_$t[id]==21){out=(int)*x;}										//21	unsigned int
//if(var_$t[id]==22){out=libc_ltoi((long)*x);}									//22	signed long
//if(var_$t[id]==23){out=libc_ultoi((unsigned long)*x);}						//23	unsigned long   		   
//if(var_$t[id]==24){long double ld=*(long double*)(x); out=ldtoi(ld);}   //24	long double
//if(var_$t[id]==25){out=libc_stoi((char*)*x);}								//25	signed char*
//if(var_$t[id]==26){out=libc_stoi((char*)*x);}								//26	unsigned char*
//if(var_$t[id]==27){out=libc_lltoi((long long)*x);}		   		   		   	//27	long long
//if(var_$t[id]==28){out=libc_ultoi((long)*x);}								//28	size_t
//if(var_$t[id]==29){out=libc_lltoi((long long)*x);}		   		   		   	//29	long long int
//if(var_$t[id]==30){out=libc_ultoi((long)*x);}		   		   		   		//30	unsigned long int
//if(var_$t[id]==31){out=libc_ulltoi((unsigned long long)*x);}					//31	unsigned long long int
//if(var_$t[id]==32){out=libc_lltoi((long long)*x);}		   		   		   	//32	signed long long
//if(var_$t[id]==33){out=libc_ulltoi((unsigned long long)*x);}		   		   	//33   	unsigned long long
//if(var_$t[id]==34){out=libc_ulltoi((unsigned long long)*x);}		   		   	//34  	signed long long int
if(libc_sch_count(type,'*')>1 && libc_scmp(type,"char*")!=2){libc_print_str("notice: Unable to convert type \"array\"!\n");}	   		   		   
		   }

return out;
	}
#define toi(x) (_unic_toi((uni*)&x))
#endif