uni __proto_len_l_nom(long long num){
uni i = 0;
if(num==0){i++;}
if(num<0){num= -num; i++;} while(num){num/=10;++i;}return i;}
////////////////////////////////////////////////////////////////////////
uni __proto_len_ul_nom(unsigned long long num){
uni i = 0;
if(num==0){i++;}
if(num<0){num= -num; i++;} while(num){num/=10;++i;}return i;}
						
////////////////////////////////////////////////////////////////////////
#ifndef no_count
inline uni count(void** v){uni i=0;while(v[i]!=NULL){++i;}return i;}
#endif

////////////////////////////////////////////////////////////////////////
#ifndef no_lens
inline uni lens(char* v){uni i=0;while(v[i]!=0){++i;}return i;}
#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_lend
uni lend(double num){
uni i = 0;
if(num<0){num= -num; i++;}
long j = 0, t;
long ol=(long)num;
while(ol>0){ol/=10; ++i;}
j=i;
num=num-j;
i++;
while(t>-1){num = num*10; t = (long)num%10; ++i;}

return i;}
#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_lenf


uni lenf(float num){
uni i = 0, j = 0, t;
if(num<0){num= -num; i++;}
int ol=(int)num;
while(ol>0){ol/=10; ++i;}
j=i;
num=num-j;
i++;
while(t>-1){num = num*10; t = (int)num%10; ++i;}

return i;}

#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_lenld
uni lenld(long double num){
uni i = 0;
if(num<0){num= -num; i++;}
long j = 0, t;
long long ol=(long long)num;
while(ol>0){ol/=10; ++i;}
j=i;
num=num-j;
i++;
while(t>-1){num = num*10; t = (long long)num%10; ++i;}

return i;}

#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_leni
#define leni(n) __proto_len_l_nom((long long)n)
#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_lenl
#define lenl(n) __proto_len_l_nom((long long)n)
#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_lenll
#define lenll(n) __proto_len_l_nom((long long)n)
#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_lenui
#define lenui(n) __proto_len_l_nom((long long)n)
#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_lenul
#define lenul(n) __proto_len_l_nom((long long)n)
#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_lenull
#define lenull(n) __proto_len_ul_nom((unsigned long long)n)
#endif
////////////////////////////////////////////////////////////////////////

