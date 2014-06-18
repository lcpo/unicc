void __stack_chk_fail(){return;}
extern char* itos(int n);
extern char* ltos(long n);
extern char* dtos(double n);
extern char* ftos(float n);

int proto_printf(char* format,...){
char* tmp_text;
char buffer[1];
int i=0,n=0,len_format=strlen((void *)format);
double dtmp=0;
long ltmp=0;
int itmp=0;

va_list arg;
va_start(arg,format);
while(len_format>i){
if(format[i]=='%' && format[i+1]=='i'){ itmp=va_arg(arg,int); print(itos(itmp));  ++i; ++i; ++n;}else
if(format[i]=='%' && format[i+1]=='d'){itmp=va_arg(arg,int); print(itos(itmp));  ++i; ++i; ++n;}else
if(format[i]=='%' && format[i+1]=='c'){buffer[0]=va_arg(arg,char); buffer[1]=(char)'0'; print(buffer); ++i; ++i; ++n;}else
if(format[i]=='%' && format[i+1]=='s'){tmp_text=va_arg(arg,char*); print(tmp_text);++i; ++i; ++n;}else
if(format[i]=='%' && format[i+1]=='l'){ltmp=va_arg(arg,long); print(ltos(ltmp)); ++i; ++i; ++n;}else
if(format[i]=='%' && format[i+1]=='f'){dtmp=va_arg(arg,double); print(dtos(dtmp));++i; ++i; ++n;}else
{buffer[0]=(char)format[i];buffer[1]='\0';print(buffer);++i;}	
				   }
va_end(arg);

	return 1;
}

#define printf(x...)(proto_printf(x,NULL))
