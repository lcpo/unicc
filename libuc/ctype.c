///conversion type
//todo 
//Необходима оптимизация

int __proto_l_toi(long long n){///Прототип функции конверции в инт с учетом переполнения
int sz=lenll(n)-8;
if(n<0){sz--;}
if(sz>0){	
while(sz){
n=(lenll(n)>8)?(n/10):n;		
sz--;
		}
}
return (int)n;
							}
////////////////////////////////////////////////////////////////////////

long __proto_tol(long long n){///Прототип функции конверции в лонг с учетом переполнения
int sz=lenll(n)-16;
if(n<0){sz--;}
if(sz>0){	
while(sz){
n=(lenll(n)>16)?(n/10):n;		
sz--;
		}
}
return (long)n;
							}
////////////////////////////////////////////////////////////////////////

long __proto_toul(unsigned long long n){///Прототип функции конверции в лонг с учетом переполнения
int sz=lenll(n)-19;
if(n<0){sz--;}
if(sz>0){	
while(sz){
n=(lenll(n)>19)?(n/10):n;		
sz--;
		}
}
return (long)n;
							}
////////////////////////////////////////////////////////////////////////
#ifndef no_dtos
char* __proto_dtos(double n,char* buff){///double to str
//n=n+0.000000000000001;
	*buff =+0;
char* a1 = buff;
long long i=0,j=0,k=0;
long long x=0,y=0,t=0,z=0,u=0,p=0;
if(n<0) {a1[j++] = '-'; n = -n; p=1;}
y = x = n;
if(x == 0){ a1[j++] = '0';}k = j;
while(x>0) {t = x%10; x/=10; a1[k++]=t+'0';}
i = k--;
while(k>j) {swap(a1[j],a1[k]);j++; k--;}
j = i;
n=n-y;
a1[j++] = '.';
u=(19-j)+p;
if(u<7){u=7;}
z=0;
//printf("%li\n",(long)(17-j));
while(z<u){
n=n*10;
t = (long long)n%10;
a1[j++] = t+'0';
z++;}
a1[j-1]='\0';
return a1;
}
char out_$_dtos[32];
#define dtos(x) (__proto_dtos((double)x,(char*)out_$_dtos))
#endif
////////////////////////////////////////////////////////////////////////

#ifndef no_ldtos
char* __proto_ldtos(long double n,char* buff){///long double to str
//n=n+0.0000000000000001;
	*buff =+0;
char* a2= buff;
long long i=0,j=0,k=0;
long long x=0,y=0,t=0,z=0,u=0;
if(n<0) {a2[j++] = '-'; n = -n;}
y = x = n;
if(x == 0){ a2[j++] = '0';}k = j;
while(x>0) {t = x%10; x/=10; a2[k++]=t+'0';}
i = k--;
while(k>j) {swap(a2[j],a2[k]);j++; k--;}
j = i;
n=n-y;
a2[j++] = '.';
u=(19-j);
if(u<7){u=7;}
z=0;
while(z<(u)) {
n = n*10;
t = (long long)n%10;
a2[j++] = t+'0';
				z++;}
a2[j-1]='\0';

return a2;
}
char out_$_ldtos[32];
#define ldtos(x) (__proto_ldtos((long double)x,(char*)out_$_ldtos))
#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_ftos
char* __proto_ftos(float n,char* buff){///float to str
	*buff =+0;
char* a3 = buff;

long long i=0,j=0,k=0;
long long x=0,y=0,t=0,z=0;
if(n<0) {a3[j++] = '-'; n = -n;}
//n=n+0.000001;
y = x = n;
if(x == 0){ a3[j++] = '0';}k = j;
while(x>0) {t = x%10; x/=10; a3[k++]=t+'0';}
i = k--;
while(k>j) {swap(a3[j],a3[k]);j++; k--;}
j = i;
n=n-y;
a3[j++] = '.';
z=0;
while(z<7){
n = n*10;
t = (long long)n%10;
if(t>0 && z==5){a3[j++]=(t+1)+'0';}else{a3[j++] = t+'0';}
	//a3[j++] = t+'0';

			z++;}

//if(t==0){a3[j-2]='\0';a3[j-1]='\0';}else{a3[j-1]='\0';}
a3[j-1]='\0';

return a3;
}
char out_$_ftos[32];
#define ftos(x) (__proto_ftos((float)x,(char*)out_$_ftos))
#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_itos

#define INT_MAX_LEN 12*2

char _$_sint[INT_MAX_LEN];
char* itos(int n){///int to str
	*_$_sint+=0;
     int i=0, sign=0,j=0;
     uni l=leni(n);
    // char c;

     if ((sign = n) < 0){n = -n; l++;}
i = 0;
     do {
         _$_sint[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);
     if (sign < 0){_$_sint[i++] = '-'; l--;}
     _$_sint[i] = '\0';
i = 0;
j=l-1;
while(j>i) {swap(_$_sint[i],_$_sint[j]);i++; j--;}

return _$_sint;
 }
#endif

#ifndef no_uitos

#define UINT_MAX_LEN 12*2

char _$_suint[UINT_MAX_LEN];
char* uitos(unsigned int n){///unsigned int to str
	*_$_suint+=0;
     int i=0, sign=0,j=0;
     uni l=leni(n);
    // char c;

     if ((sign = n) < 0){n = -n; l++;}
i = 0;
     do {
         _$_sint[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);
     if (sign < 0){_$_sint[i++] = '-'; l--;}
     _$_sint[i] = '\0';
i = 0;
j=l-1;
while(j>i) {swap(_$_suint[i],_$_suint[j]);i++; j--;}

return _$_suint;
 }
#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_ltos

#define LONG_MAX_LEN 22*2

char _$_slong[LONG_MAX_LEN];
 char* ltos(long int n){///long to str
	*_$_slong+=0;
     int i=0, sign=0,j=0;
     uni l=lenl(n);
	 //char c;

      if ((sign = n) < 0){n = -n; l++;}
i = 0;
     do {
         _$_slong[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);
     if (sign < 0){_$_slong[i++] = '-'; l--;}
     _$_slong[i] = '\0';
i = 0;
j=l-1;
while(j>i) {swap(_$_slong[i],_$_slong[j]);i++; j--;}
return _$_slong;
 }
#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_lltos

#define LONG_LONG_MAX_LEN 22*2

char _$_sllong[LONG_LONG_MAX_LEN];
 char* lltos(long long int n){///long long to str
	*_$_sllong+=0;
     int i=0, sign=0,j=0;
     uni l=lenl(n);
	 //char c;

      if ((sign = n) < 0){n = -n; l++;}
i = 0;
     do {
         _$_sllong[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);
     if (sign < 0){_$_sllong[i++] = '-'; l--;}
     _$_sllong[i] = '\0';
i = 0;
j=l-1;
while(j>i) {swap(_$_sllong[i],_$_sllong[j]);i++; j--;}
return _$_sllong;
 }
#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_ulltos

#define ULONG_LONG_MAX_LEN 22*2

char _$_sullong[ULONG_LONG_MAX_LEN];
 char* ulltos(unsigned long long int n){///unsigned long long to str
	*_$_sullong+=0;
     int i=0, sign=0,j=0;
     uni l=lenl(n);
	 //char c;

      if ((sign = n) < 0){n = -n; l++;}
i = 0;
     do {
         _$_sullong[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);
     if (sign < 0){_$_sullong[i++] = '-'; l--;}
     _$_sullong[i] = '\0';
i = 0;
j=l-1;
while(j>i) {swap(_$_sullong[i],_$_sullong[j]);i++; j--;}
return _$_sllong;
 }
#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_ultos

#define ULONG_MAX_LEN 22*2

char _$_sulong[ULONG_MAX_LEN];
 char* ultos(unsigned long int n){///unsigned long to str
	*_$_sulong+=0;
     int i=0, sign=0,j=0;
     uni l=lenl(n);
	 //char c;

      if ((sign = n) < 0){n = -n; l++;}
i = 0;
     do {
         _$_sulong[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);
     if (sign < 0){_$_sulong[i++] = '-'; l--;}
     _$_sulong[i] = '\0';
i = 0;
j=l-1;
while(j>i) {swap(_$_sulong[i],_$_sulong[j]);i++; j--;}
return _$_sulong;
 }
#endif
////////////////////////////////////////////////////////////////////////
#define lltol(n) __proto_tol((long long)n)
#define ulltol(n) __proto_toul((unsigned long long)n)
#define ftol(n) __proto_tol((long long)n)
#define dtol(n) __proto_tol((long long)n)
#define ldtol(n) __proto_tol((unsigned long long)n)
#define ctol(n) ((long)n)
////////////////////////////////////////////////////////////////////////	
#define ltoi(n) __proto_l_toi((long long)n)
#define ultoi(n) __proto_l_toi((long long)n)
#define lltoi(n) __proto_l_toi((long long)n)
#define ulltoi(n) __proto_l_toi((long long)n)
#define ftoi(n) __proto_l_toi((long long)n)
#define dtoi(n) __proto_l_toi((long long)n)
#define ldtoi(n) __proto_l_toi((long long)n)
#define ctoi(n) ((int)n)
///---------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////
#ifndef no_stod 
double stod(char* s){///str to double
int i=0; 
double sign=0,is=0,si=0;
char* sdt=s;
sign = (s[0] == '-') ? -1.0 : 1.0;
int len=strlen(s);
int k=len;


while (s[i]!='.'){
if (sdt[i] == '-'){i++;}
is = is *10. + (sdt[i] - '0');
i++;
				}
k--;
while (s[k]!='.'){
if(s[0]=='-'){si = si * .1 - (sdt[k] - '0');}else{si = si * .1 + (sdt[k] - '0');}
k--;
					}
si =si* .1;

return sign*is+si;
}
#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_stold 
long double stold(char* s){///str to long double
int i=0; 
long double sign=0,is=0,si=0;
char* sdt=s;
sign = (s[0] == '-') ? -1.0 : 1.0;
int len=strlen(s);
int k=len;


while (s[i]!='.'){
if (sdt[i] == '-'){i++;}
is = is *10. + (sdt[i] - '0');
i++;
				}
k--;
while (s[k]!='.'){
if(s[0]=='-'){si = si * .1 - (sdt[k] - '0');}else{si = si * .1 + (sdt[k] - '0');}
k--;
					}
si =si* .1;

return sign*is+si;
}
#endif
////////////////////////////////////////////////////////////////////////
#ifndef no_stof
float stof(char* s){///str to float
int i=0; 
float sign=0,is=0,si=0;
char* sdt=s;
sign = (s[0] == '-') ? -1.0 : 1.0;
int len=strlen(s);
int k=len;


while (s[i]!='.'){
if (sdt[i] == '-'){i++;}
is = is *10. + (sdt[i] - '0');
i++;
				}
k--;
while (s[k]!='.'){
if(s[0]=='-'){si = si * .1 - (sdt[k] - '0');}else{si = si * .1 + (sdt[k] - '0');}
k--;
					}
si =si* .1;

return sign*is+si;
}
#endif
//////////////////////////////////////////////////////////////////////// 1
#ifndef no_stoui 
unsigned int stoui(char* s){///str to unsigned int
int i=0, n=0;
for (n = 0, i=0; strlen(s)>i; i++){
if (s[i] == '-'){i++;}
n = 10 * n + (s[i] - '0');
}
return n;
}
#endif
//////////////////////////////////////////////////////////////////////// 1
#ifndef no_stoi 
int stoi(char* s){///str to int
int i=0, n=0, sign=0;
sign = (s[0] == '-') ? -1 : 1;
for (n = 0, i=0; strlen(s)>i; i++){
if (s[i] == '-'){i++;}
n = 10 * n + (s[i] - '0');
}
return sign * n;
}
#endif
//////////////////////////////////////////////////////////////////////// 1
#ifndef no_stoul 
unsigned long stoul(char* s){///str to unsigned long
long i=0, n=0;

for (n = 0, i=0; strlen(s)>i; i++){
if (s[i] == '-'){i++;}
n = 10 * n + (s[i] - '0');
}
return n;
}
#endif
//////////////////////////////////////////////////////////////////////// 1
#ifndef no_stol 
long stol(char* s){///str to long
long i=0, n=0, sign=0;
sign = (s[0] == '-') ? -1 : 1;
for (n = 0, i=0; strlen(s)>i; i++){
if (s[i] == '-'){i++;}
n = 10 * n + (s[i] - '0');
}
return sign * n;
}
#endif
//////////////////////////////////////////////////////////////////////// 1
#ifndef no_stoll 
long long stoll(char* s){/// str to long long
long long i=0, n=0, sign=0;
sign = (s[0] == '-') ? -1 : 1;
for (n = 0, i=0; strlen(s)>i; i++){
if (s[i] == '-'){i++;}
n = 10 * n + (s[i] - '0');
}
return sign * n;
}
#endif
//////////////////////////////////////////////////////////////////////// 1
#ifndef no_stoull 
unsigned long long stoull(char* s){/// str to unsigned long long
unsigned long long i=0, n=0;
for (n = 0, i=0; strlen(s)>i; i++){
if (s[i] == '-'){i++;}
n = 10 * n + (s[i] - '0');
}
return n;
}
#endif

