//!con --------------------------------------------------------
//!cpy --------------------------------------------------------
//!err --------------------------------------------------------
//!ex  --------------------------------------------------------
//!get --------------------------------------------------------
//!is  --------------------------------------------------------
//!len --------------------------------------------------------
//Допилить работу с многобайтовыми символами
uni _unic_len(uni* x){
	uni id=get_var_id(x);
	uni out=-1;
if(id!=-1){
char* type=get_var_type(x);
if(libc_sch_count(type,'*')>1 && libc_scmp(type,"char*")!=2){out=libc_count((void*)*x);}
if(var_$t[id]==0 || var_$t[id]==1 || var_$t[id]==3 || var_$t[id]==11){out=libc_lens((void*)*x);}
if(var_$t[id]==2){return 1;}
if(var_$t[id]==4 || var_$t[id]==8){out=libc_leni((int)*x);}
if(var_$t[id]==5 || var_$t[id]==9){out=libc_leni((long)*x);}
if(var_$t[id]==6){float f=*(float*)(x); out=libc_lenf(f);}
if(var_$t[id]==7){double d=*(double*)(x); out=libc_lend(d);}
if(var_$t[id]==24){double ld=*(double*)(x); out=libc_lenld(ld);}
		   }
return out;
					}

#define len(x) (_unic_len((uni*)&x))

//!mem --------------------------------------------------------
//!pub --------------------------------------------------------
int _unic_pub(uni* x){
	uni id=get_var_id(x);
if(id!=-1){
char* type=get_var_type(x);
char* buff;
if(libc_sch_count(type,'*')>1 && libc_scmp(type,"char*")!=2){write($O,"Array",5); 			return 1;}
if(var_$t[id]==0 || var_$t[id]==1 || var_$t[id]==3 || var_$t[id]==11){write($O,(void*)*x,libc_lens((void*)*x)); 					return 1;}
if(var_$t[id]==2){char bf[0];bf[0]=(char)*x;write($O,bf,1);				return 1;}
if(var_$t[id]==4 || var_$t[id]==8){write($O,libc_itos((int)*x),libc_leni((int)*x)+1);					return 1;}
if(var_$t[id]==5 || var_$t[id]==9){write($O,libc_ltos((long)*x),libc_leni((long)*x)+1);				return 1;}

if(var_$t[id]==6){float f=*(float*)(x);
buff=libc_ftos((float)f);
write($O,buff,libc_lens((void*)buff));
		return 1;}
		
if(var_$t[id]==7){
	double d=*(double*)(x);
	buff=libc_dtos((double)d); 
	write($O,buff,libc_lens((void*)buff));	
	return 1;}
	
if(var_$t[id]==24){
	long double ld=*(long double*)(x);
	buff=libc_ldtos((long double)ld);
	write($O,buff,libc_lens((void*)buff)); 
	return 1;
	}
				}
return 0;
					}
#define pub(x) ({\
((_unic_pub((uni*)&x)==0)?(write($O,(char*)&x,libc_lens((char*)&x))):1);\
})
//!rex --------------------------------------------------------
//!set --------------------------------------------------------
//!so  --------------------------------------------------------
//!toc --------------------------------------------------------
char _unic_toc(uni* x){
	uni id=get_var_id(x);
	char out='\0';
	char* buff;
if(id!=-1){
char* type=get_var_type(x);
if(libc_sch_count(type,'*')>1 && libc_scmp(type,"char*")!=2){buff=(void*)*x; out=buff[0];}
if(var_$t[id]==0 || var_$t[id]==1 || var_$t[id]==3 || var_$t[id]==11){buff=(void*)*x; out=buff[0];}
if(var_$t[id]==2){buff=(void*)*x; out=buff[0];}
if(var_$t[id]==4 || var_$t[id]==8){buff=libc_itos((int)*x);out=(char)buff[0];}
if(var_$t[id]==5 || var_$t[id]==9){buff=libc_ltos((long)*x);out=(char)buff[0];}
if(var_$t[id]==6){float f=*(float*)(x);buff=libc_ftos(f);out=(char)buff[0];}
if(var_$t[id]==7){double d=*(double*)(x);buff=libc_dtos(d);out=(char)buff[0];}
if(var_$t[id]==24){double ld=*(double*)(x);buff=libc_ldtos(ld);out=(char)buff[0];}
		   }
return out;
	}
#define toc(x) (_unic_toc((uni*)&x))
//!tod --------------------------------------------------------
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
//!tof --------------------------------------------------------
float _unic_tof(uni* x){
	uni id=get_var_id(x);
	float out=0;
	char* buff;
if(id!=-1){
char* type=get_var_type(x);
if(libc_sch_count(type,'*')>0 && libc_scmp(type,"char")==1){
	buff=(void*)*x; out=libc_stof((void*)buff);
}else{out=*(double*)(x);}
		   }
return out;
	}
#define tof(x) (_unic_tof((uni*)&x))
//!toi --------------------------------------------------------

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
//!tol --------------------------------------------------------

int _unic_tol(uni* x){
	uni id=get_var_id(x);
	int out=-1;
if(id!=-1){
char* type=get_var_type(x);
if(var_$t[id]==0){out=(char)*x;} 									//0		void
if(var_$t[id]==1){out=libc_stol((char*)*x);} 								//1		void*
if(var_$t[id]==2){out=(char)*x;} 									//2		char 
if(var_$t[id]==3){out=libc_stol((char*)*x);}									//3		char*
if(var_$t[id]==4){out=(long)*x;}										//4 	int 
if(var_$t[id]==5){out=(long)*x;}										//5 	long
//if(var_$t[id]==6){float f=*(float*)(x);out=libc_ftol(f);}					//6 	float
//if(var_$t[id]==7){double d=*(double*)(x);out=libc_dtol(d);}					//7 	double
if(var_$t[id]==8){out=(long)*x;}										//8 	short
if(var_$t[id]==9){out=(long)*x;}										//9 	uni
//if(var_$t[id]==10){out=libc_ulltol((unsigned long long)*x);}					//10	size
if(var_$t[id]==11){out=libc_stol((char*)*x);}								//11	wchar
if(var_$t[id]==12){out=(char)*x;}									//12	signed char
if(var_$t[id]==13){out=(unsigned char)*x;}						//13	unsigned char
if(var_$t[id]==14){out=(long)*x;}										//14	short int
if(var_$t[id]==15){out=(long)*x;}		   		   						//15	signed short
if(var_$t[id]==16){out=(long)*x;}		   		   						//16	unsigned short
if(var_$t[id]==17){out=(long)*x;}										//17	unsigned short int
if(var_$t[id]==18){out=(long)*x;}		   		   						//18	signed
if(var_$t[id]==19){out=(long)*x;}		   		   						//19	signed int
if(var_$t[id]==20){out=(long)*x;}		   		   						//20	unsigned
if(var_$t[id]==21){out=(long)*x;}										//21	unsigned int
if(var_$t[id]==22){out=(long)*x;}										//22	signed long
//if(var_$t[id]==23){out=libc_ulltoi((unsigned long long)*x);}					//23	unsigned long   		   
//if(var_$t[id]==24){long double ld=*(long double*)(x); out=libc_ldtol(ld);}   //24	long double
//if(var_$t[id]==25){out=libc_stol((char*)*x);}								//25	signed char*
//if(var_$t[id]==26){out=libc_stol((char*)*x);}								//26	unsigned char*
//if(var_$t[id]==27){out=libc_lltol((long long)*x);}		   		   		   	//27	long long
//if(var_$t[id]==28){out=libc_ulltol((unsigned long long)*x);}					//28	size_t
//if(var_$t[id]==29){out=libc_lltol((long long)*x);}		   		   		   	//29	long long int
//if(var_$t[id]==30){out=libc_ulltol((unsigned long long)*x);}   		   		//30	unsigned long int
//if(var_$t[id]==31){out=libc_ulltol((unsigned long long)*x);}					//31	unsigned long long int
//if(var_$t[id]==32){out=libc_lltoi((long long)*x);}		   		   		   	//32	signed long long
//if(var_$t[id]==33){out=libc_ulltoi((unsigned long long)*x);}		   		   	//33   	unsigned long long
//if(var_$t[id]==34){out=libc_lltoi((long long)*x);}				   		   	//34  	signed long long int
if(libc_sch_count(type,'*')>1 && libc_scmp(type,"char*")!=2){libc_print_str("notice: Unable to convert type \"array\"!\n");}	   		   		   
		   }

return out;
	}
#define tol(x) (_unic_tol((uni*)&x))
//!told -------------------------------------------------------
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
//!tos --------------------------------------------------------
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
//!tou --------------------------------------------------------
 
