

void __stack_chk_fail(){return;}
extern char* itos(int n);
extern char* ltos(long n);

char out_$_dtos[32];
extern char* __proto_dtos(double x,char* out);

#define dtos(x) (__proto_dtos((double)x,(char*)out_$_dtos))

extern char* __proto_ftos(float x,char* out);
char out_$_ftos[32];

#define ftos(x) (__proto_ftos((float)x,(char*)out_$_ftos))



int __print(char **out, char *format, va_list args ){
	
int len_format=strlen((void *)format);
int i=0,itmp=0;
long ltmp=0;
char buff[1];
char *tmp_chard;
while(len_format>i){
if(format[i]=='%' && format[i+1]=='c'){buff[0]==(char)va_arg( args, char ); buff[1]=(char)'0'; write($O,buff,1); ++i; ++i;}else
if(format[i]=='%' && format[i+1]=='s'){tmp_chard=va_arg( args, char* ); write($O,(void*)tmp_chard,strlen((void*)tmp_chard)); ++i; ++i;}else
if(format[i]=='%' && format[i+1]=='d'){tmp_chard=dtos(va_arg( args, double )); write($O,tmp_chard,strlen(tmp_chard)); ++i; ++i;}else
if(format[i]=='%' && format[i+1]=='i'){itmp=va_arg( args, int ); tmp_chard=itos(itmp); write($O,tmp_chard,strlen(tmp_chard)); ++i; ++i;}else
if(format[i]=='%' && format[i+1]=='l'){ltmp=va_arg( args, long ); tmp_chard=ltos(ltmp); write($O,tmp_chard,strlen(tmp_chard)); ++i; ++i;}else
if(format[i]=='%' && format[i+1]=='f'){tmp_chard=ftos(va_arg( args, float )); write($O,tmp_chard,strlen(tmp_chard)); ++i; ++i;}else
{
buff[0]=(char)format[i]; 
buff[1]='0';
write($O,buff,1);
++i;	
	}

	}
	va_end( args );
	return 1;
}

int printf(char *format, ...)
{
        va_list args;
        
        va_start( args, format );
        return __print( 0, format, args );
}

int sprintf(char *out, char *format, ...)
{
        va_list args;
        
        va_start( args, format );
        return __print( &out, format, args );
}








/*
#ifdef TEST_PRINTF
int main(void)
{
	char *ptr = "Hello world!";
	char *np = 0;
	int i = 5;
	unsigned int bs = sizeof(int)*8;
	int mi;
	char buf[80];

	mi = (1 << (bs-1)) + 1;
	printf("%s\n", ptr);
	printf("printf test\n");
	printf("%s is null pointer\n", np);
	printf("%d = 5\n", i);
	printf("%d = - max int\n", mi);
	printf("char %c = 'a'\n", 'a');
	printf("hex %x = ff\n", 0xff);
	printf("hex %02x = 00\n", 0);
	printf("signed %d = unsigned %u = hex %x\n", -3, -3, -3);
	printf("%d %s(s)%", 0, "message");
	printf("\n");
	printf("%d %s(s) with %%\n", 0, "message");
	sprintf(buf, "justif: \"%-10s\"\n", "left"); printf("%s", buf);
	sprintf(buf, "justif: \"%10s\"\n", "right"); printf("%s", buf);
	sprintf(buf, " 3: %04d zero padded\n", 3); printf("%s", buf);
	sprintf(buf, " 3: %-4d left justif.\n", 3); printf("%s", buf);
	sprintf(buf, " 3: %4d right justif.\n", 3); printf("%s", buf);
	sprintf(buf, "-3: %04d zero padded\n", -3); printf("%s", buf);
	sprintf(buf, "-3: %-4d left justif.\n", -3); printf("%s", buf);
	sprintf(buf, "-3: %4d right justif.\n", -3); printf("%s", buf);

	return 0;
}
*/
/*
 * if you compile this file with
 *   gcc -Wall $(YOUR_C_OPTIONS) -DTEST_PRINTF -c printf.c
 * you will get a normal warning:
 *   printf.c:214: warning: spurious trailing `%' in format
 * this line is testing an invalid % at the end of the format string.
 *
 * this should display (on 32bit int machine) :
 *
 * Hello world!
 * printf test
 * (null) is null pointer
 * 5 = 5
 * -2147483647 = - max int
 * char a = 'a'
 * hex ff = ff
 * hex 00 = 00
 * signed -3 = unsigned 4294967293 = hex fffffffd
 * 0 message(s)
 * 0 message(s) with %
 * justif: "left      "
 * justif: "     right"
 *  3: 0003 zero padded
 *  3: 3    left justif.
 *  3:    3 right justif.
 * -3: -003 zero padded
 * -3: -3   left justif.
 * -3:   -3 right justif.
 */
/*
#endif*/
