uni* __arg(void* p,...){
int i=0;
uni buff[4096];
void* arg;
va_start(arg,p);
while(p){buff[i++]=(uni)p; p=va_arg(arg,typeof(p));}
va_end(arg);
uni* out=(uni*)buff;
	return out;
						}
#define arg(x...)(__arg(x,NULL))
