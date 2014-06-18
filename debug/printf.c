
/*
void __stack_chk_fail(){return;}
extern char* itos(int n);
extern char* ltos(long n);
extern char* dtos(double n);
extern char* ftos(float n);
char __print_buf[32];

int __print(void* p,...){
int i=0,n=0;
uni buff[MAX_ARG];
va_list arg;
va_start(arg,p);
while(p){buff[i++]=(uni)p; p=va_arg(arg,typeof(p));}
va_end(arg);
uni* out=(uni*)buff;
n=i; i=1;


char* format=(char*)out[0];
char buffer[1];
char *tmp_chard=__print_buf;
int itmp=0,ri=0,len_format=strlen((void *)format);
double dtmp;
float ftmp;

while(len_format>ri){
if(format[ri]=='%' && format[ri+1]=='c'){buffer[0]==(char)out[i]; buffer[1]=(char)'0'; write($O,buffer,1); ++ri; ++ri; ++i;}else
if(format[ri]=='%' && format[ri+1]=='s'){tmp_chard=(char*)out[i]; write($O,(void*)tmp_chard,strlen((void*)tmp_chard)); ++ri; ++ri;++i;}else
if(format[ri]=='%' && format[ri+1]=='i'){tmp_chard=itos((int)out[i]); write($O,tmp_chard,strlen(tmp_chard)+1); ++ri; ++ri;++i;}else
if(format[ri]=='%' && format[ri+1]=='l'){tmp_chard=ltos((long)out[i]); write($O,tmp_chard,strlen(tmp_chard)); ++ri; ++ri;++i;}else
{buffer[0]=(char)format[ri];buffer[1]='0';write($O,buffer,1);++ri;}

	}
	return 1;
}*/


#define printf(x...)(__print(x,NULL))


/*
int printf(char *format, ...)
{
        //va_list args;
        
        //va_start( args, format );
        return __print( format, args );
}

int sprintf(char *out, char *format, ...)
{
        va_list args;
        
        va_start( args, format );
        return __print( &out, format, args );
}
*/









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
