///------------------------------------------------------------
void print_reg_var(uni id){
if(id!=-1){
uni* x=get_var_adr_by_id(id);
char* type=get_var_type(x);	
char* buff;
if(libc_sch_count(type,'*')>1 && libc_scmp(type,"char*")!=2){write($O,"Array",5); return;}
if(var_$t[id]==0 || var_$t[id]==1 || var_$t[id]==3 || var_$t[id]==11){write($O,(void*)*x,libc_lens((void*)*x));return;}
if(var_$t[id]==2){char bf[0];bf[0]=(char)*x;write($O,bf,1);return;}
if(var_$t[id]==4 || var_$t[id]==8){write($O,libc_itos((int)*x),libc_leni((int)*x)+1);return;}
if(var_$t[id]==5 || var_$t[id]==9){write($O,libc_ltos((long)*x),libc_leni((long)*x)+1);return;}
if(var_$t[id]==6){float f=*(float*)(x);buff=libc_ftos((float)f);write($O,buff,libc_lens((void*)buff));return;}
if(var_$t[id]==7){double d=*(double*)(x);buff=libc_dtos((double)d);write($O,buff,libc_lens((void*)buff));return;}
if(var_$t[id]==24){long double ld=*(long double*)(x);buff=libc_ldtos((long double)ld);write($O,buff,libc_lens((void*)buff));return;}
		}	
	
	}

///------------------------------------------------------------
void print_item_array(char* name){
uni len=0,id=-1,i=0,sid=0;
int arr_co=0;
uni* x;
uni* sx;
char* name_arr; char* type; char* arg_arr;
	len=libc_strlen(name)-1;
	name_arr=libc_strpstr(name,"["); 
	arg_arr=libc_strstr(name,"[");
	id=get_var_id_by_name(name_arr);
	type=get_var_type_by_name(name_arr);
	x=get_var_adr_by_id(id);
	len=libc_strlen(arg_arr);
	arr_co=libc_sch_count(arg_arr,'[');
int flag=0,p=0,cur=0,z=0,n=0;

long lvect[arr_co],rvect[arr_co];
rvect[n]=0;n++;
char buf[len+1];	

while(len>i){
if(arg_arr[i]!='[' && arg_arr[i]!=']'){z++;buf[p]=arg_arr[i]; p++;lvect[n-1]=z;rvect[n]=p;}
if(arg_arr[i-1]==']' && arg_arr[i]=='['){z=0;n++;}
i++;			
			}
buf[p]='\0';

long vect[100];
i=0;
//printf("=%s\n",buf);

char* nbuff=libc_alloc(sizeof(nbuff)*len*arr_co);
while(arr_co>i){
nbuff=libc_substr(buf,rvect[i],lvect[i]);
if(libc_is_dec_num(nbuff)){vect[i]=libc_stol(nbuff);
}else{sid=get_var_id_by_name(nbuff);sx=get_var_adr_by_id(sid);vect[i]=(long)*sx;}

	i++;
				}
			
if(libc_scmp(type,"char*")==2 && arr_co==1){char* out1=(char*)*x;char bf1[0]; bf1[0]=out1[(int)vect[0]];write($O,bf1,1);}
if(libc_scmp(type,"char**")==2 && arr_co==1){char** out2=(char**)*x;char* bf2=out2[(int)vect[0]];write($O,bf2,libc_strlen(bf2));}
if(libc_scmp(type,"char**")==2 && arr_co==2){char** out3=(char**)*x;char bf3[0];bf3[0]=out3[(int)vect[0]][(int)vect[1]];write($O,bf3,1);}
if(libc_scmp(type,"char***")==2 && arr_co==2){char*** out4=(char***)*x;char* bf4=out4[(int)vect[0]][(int)vect[1]];write($O,bf4,libc_strlen(bf4));}				

if(libc_scmp(type,"int*")==2 && arr_co==1){int* out5=(int*)*x;int bf5; bf5=out5[(int)vect[0]];write($O,libc_itos(bf5),libc_strlen(libc_itos(bf5)));}
if(libc_scmp(type,"int**")==2 && arr_co==2){int** out7=(int**)*x;int bf7;bf7=out7[(int)vect[0]][(int)vect[1]];write($O,libc_itos(bf7),libc_strlen(libc_itos(bf7)));}

if(libc_scmp(type,"long*")==2 && arr_co==1){long* out5=(long*)*x;long bf5; bf5=out5[(int)vect[0]];write($O,libc_ltos(bf5),libc_strlen(libc_ltos(bf5)));}
if(libc_scmp(type,"long**")==2 && arr_co==2){long** out7=(long**)*x;long bf7;bf7=out7[(int)vect[0]][(int)vect[1]];write($O,libc_ltos(bf7),libc_strlen(libc_ltos(bf7)));}

if(libc_scmp(type,"float*")==2 && arr_co==1){float* out5=(float*)*x;float bf5; bf5=out5[(int)vect[0]];write($O,libc_dtos(bf5),libc_strlen(libc_dtos(bf5)));}
if(libc_scmp(type,"float**")==2 && arr_co==2){float** out7=(float**)*x;float bf7;bf7=out7[(int)vect[0]][(int)vect[1]];write($O,libc_dtos(bf7),libc_strlen(libc_dtos(bf7)));}

if(libc_scmp(type,"double*")==2 && arr_co==1){double* out5=(double*)*x;double bf5; bf5=out5[(int)vect[0]];write($O,libc_dtos(bf5),libc_strlen(libc_dtos(bf5)));}
if(libc_scmp(type,"double**")==2 && arr_co==2){double** out7=(double**)*x;double bf7;bf7=out7[(int)vect[0]][(int)vect[1]];write($O,libc_dtos(bf7),libc_strlen(libc_dtos(bf7)));}

return;
libc_free(name_arr);
	}
///------------------------------------------------------------

void __printtype(char* args){

int len=libc_strlen(args)-1;
uni id=-1;
if(args[0]=='"' && args[len]=='"'){libc_print_str(libc_substr(args,1,len-1));}else
if(args[0]=='\'' && args[len]=='\''){libc_print_str(libc_substr(args,1,len-1));}else	
if(libc_is_dec_num(args)==1){libc_print_str(args);}else
if(libc_sch(args,'[')==1 && libc_sch(args,']')==1){
	print_item_array(args);
	}else{
	id=get_var_id_by_name(args);
	print_reg_var(id);
		}	

						}		
///------------------------------------------------------------

void __echo(char* str_arg){
str_arg=libc_string_replace(str_arg,"\\n","\n");
str_arg=libc_string_replace(str_arg,"\\r","\r");
str_arg=libc_string_replace(str_arg,"\\t","\t");

int len=libc_strlen(str_arg),i=0,p=0,n=0,z=0,nom=0;
char* buff=libc_malloc(len*sizeof(buff)*libc_strlen(str_arg));
long lvect[len],rvect[len];
rvect[n]=0;n++;
while(len>i){if((str_arg[i]==',' || str_arg[i]=='.') && str_arg[i-1]!='\\'){z=0;i++;n++;}else{z++;lvect[n-1]=z;buff[p]=str_arg[i];p++;i++;rvect[n]=p;}}
i=0;
while(n>i){	
	__printtype(libc_substr(buff,rvect[i],lvect[i]));
	i++;}

	}
///------------------------------------------------------------	
#define echo(p...)({__echo(#p);})
///------------------------------------------------------------	
