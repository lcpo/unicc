#ifndef no_tol

int _unic_tol(uni* x){
	uni id=get_var_id(x);
	int out=-1;
if(id!=-1){
char* type=get_var_type(x);
if(var_$t[id]==0){out=ctol((char)*x);} 									//0		void
if(var_$t[id]==1){out=stol((char*)*x);} 								//1		void*
if(var_$t[id]==2){out=ctol((char)*x);} 									//2		char 
if(var_$t[id]==3){out=stol((char*)*x);}									//3		char*
if(var_$t[id]==4){out=(long)*x;}										//4 	int 
if(var_$t[id]==5){out=(long)*x;}										//5 	long
if(var_$t[id]==6){float f=*(float*)(x);out=ftol(f);}					//6 	float
if(var_$t[id]==7){double d=*(double*)(x);out=dtol(d);}					//7 	double
if(var_$t[id]==8){out=(long)*x;}										//8 	short
if(var_$t[id]==9){out=(long)*x;}										//9 	uni
if(var_$t[id]==10){out=ulltol((unsigned long long)*x);}					//10	size
if(var_$t[id]==11){out=stol((char*)*x);}								//11	wchar
if(var_$t[id]==12){out=ctol((char)*x);}									//12	signed char
if(var_$t[id]==13){out=ctol((unsigned char)*x);}						//13	unsigned char
if(var_$t[id]==14){out=(long)*x;}										//14	short int
if(var_$t[id]==15){out=(long)*x;}		   		   						//15	signed short
if(var_$t[id]==16){out=(long)*x;}		   		   						//16	unsigned short
if(var_$t[id]==17){out=(long)*x;}										//17	unsigned short int
if(var_$t[id]==18){out=(long)*x;}		   		   						//18	signed
if(var_$t[id]==19){out=(long)*x;}		   		   						//19	signed int
if(var_$t[id]==20){out=(long)*x;}		   		   						//20	unsigned
if(var_$t[id]==21){out=(long)*x;}										//21	unsigned int
if(var_$t[id]==22){out=(long)*x;}										//22	signed long
if(var_$t[id]==23){out=ulltoi((unsigned long long)*x);}					//23	unsigned long   		   
if(var_$t[id]==24){long double ld=*(long double*)(x); out=ldtol(ld);}   //24	long double
if(var_$t[id]==25){out=stol((char*)*x);}								//25	signed char*
if(var_$t[id]==26){out=stol((char*)*x);}								//26	unsigned char*
if(var_$t[id]==27){out=lltol((long long)*x);}		   		   		   	//27	long long
if(var_$t[id]==28){out=ulltol((unsigned long long)*x);}					//28	size_t
if(var_$t[id]==29){out=lltol((long long)*x);}		   		   		   	//29	long long int
if(var_$t[id]==30){out=ulltol((unsigned long long)*x);}   		   		//30	unsigned long int
if(var_$t[id]==31){out=ulltol((unsigned long long)*x);}					//31	unsigned long long int
if(var_$t[id]==32){out=lltoi((long long)*x);}		   		   		   	//32	signed long long
if(var_$t[id]==33){out=ulltoi((unsigned long long)*x);}		   		   	//33   	unsigned long long
if(var_$t[id]==34){out=lltoi((long long)*x);}				   		   	//34  	signed long long int
if(sch_count(type,'*')>1 && scmp(type,"char*")!=2){print("notice: Unable to convert type \"array\"!\n");}	   		   		   
		   }

return out;
	}
#define tol(x) (_unic_tol((uni*)&x))
#endif
