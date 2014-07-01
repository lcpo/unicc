//!---------------------------------------------------------------------

size_t libc_strlen(char* v){size_t i=0;while(v[i]!=0){++i;}return i;}
#define libc_lens libc_strlen 

//!---------------------------------------------------------------------	
void *libc_memchr( void *s, int c, size_t n){
    if (n) { unsigned char *p = s;
        do {
             if (*p++ == (unsigned char) c) {
                return (void *) (p - 1);
             }
         } while (--n);
     }
     return 0;
 }
//!---------------------------------------------------------------------
int libc_memcmp( void *s1,  void *s2, size_t n) {
     if (n) {
         unsigned char *p1 = s1, *p2 = s2;
 
        do {
            if (*p1++ != *p2++) {
                return (*--p1 - *--p2);
            }
        } while (--n);
     }
     return 0;
}

//!---------------------------------------------------------------------
void *libc_memcpy (void *dest, void *src, size_t n)
{
        char *r1 = dest;
        const char *r2 = src;
 
        while (n) {
                *r1++ = *r2++;
                --n;
        }
 
        return dest;
}
//!---------------------------------------------------------------------
void *libc_memset(void *s, int c, size n)
{
        unsigned char *p = (unsigned char *) s;
 
        while (n) {
                *p++ = (unsigned char) c;
                --n;
        }
 
        return s;
}
//!---------------------------------------------------------------------
void *libc_memmove(char *dest, char *src, size n)
{
	char *d = dest;
	const char *s = src;
	if (d==s) return d;
	if ((size_t)(d-s) < n) {
		while (n--) d[n] = s[n];
		return dest;
	}
	return libc_memcpy((char*)d, (char*)s, (size)n);
}
//!---------------------------------------------------------------------

char* libc_strcat ( char* des, const char* so ){
while (*des) ++des;
while ((*des++ = *so++) != '\0') ;
return des;
}
//!---------------------------------------------------------------------
char * libc_strcpy( char *to,const char *from){
	char *save = to;
	for (; (*to = *from) != '\0'; ++from, ++to);
	return(save);
}

//!---------------------------------------------------------------------
char* libc_strncat(char* dst, const char * src, size_t n){
	if (n != 0) {
		char *d = dst;
		const char *s = src;

		while (*d != 0)
			d++;
		do {
			if ((*d = *s++) == 0)
				break;
			d++;
		} while (--n != 0);
		*d = '\0';
	}
	return dst;
}
//!---------------------------------------------------------------------
int libc_strncmp(char* l, char* r, size_t num){
int i=0;
if (num == 0){return 0;}
do {
if(l[i]!=r[i]){return (unsigned int)l[i]-(unsigned int)r[i];}
if (l[i] == 0){break;}
i++;
} while (--num != 0);
return 0; 
 } 
//!---------------------------------------------------------------------

char * libc_strstr(char *string, char *substring){
char c, sc;
size_t len;
if ((c = *substring++) != 0) {
len = libc_strlen(substring);
	do {
		do {
		if ((sc = *string++) == 0){	return NULL;}
			} while (sc != c);
		
	} while (libc_strncmp(string, substring, len) != 0);
	string--;
	}
return ((char *) string);
}
//!---------------------------------------------------------------------
void libc_free(void *ptr){

if (ptr == NULL){return;}
ptr -= sizeof(size);
//munmap(ptr, * (size *) ptr + sizeof(size));
munmap(ptr,  * (size *) ptr + sizeof(size)*sizeof(void*));
}
//!---------------------------------------------------------------------
uni libc_strpos(char *haystack, char *needle){
   char *p = libc_strstr(haystack, needle);
   if (p){return p - haystack;}else{return -1;}  
} 
//!---------------------------------------------------------------------

void *libc_malloc(size __size){
void *result;
result = mmap(NULL, __size , PROT_READ | PROT_WRITE,MMAP_FLAGS, 0, 0);//+ sizeof(size_t)
if (result == MAP_FAILED){return NULL;}
* (size *) result = __size;
return(result + sizeof(void*));
}
//!---------------------------------------------------------------------
size libc_count(void** v) {
    size i=0;
    while (v[i]!=NULL) {
        ++i;
    }
    return i;
}
//!---------------------------------------------------------------------
void *libc_realloc(void *ptr, size __size)
{
        void *newptr = NULL;
 
        if (!ptr)
                return libc_malloc(__size);
        if (!__size) {
                libc_free(ptr);
                return libc_malloc(0);
        }
 
        newptr = libc_malloc(__size);
        if (newptr) {
                size old_size = *((size *) (ptr - sizeof(size)));
				 libc_memcpy(newptr, ptr, libc_count((void**)ptr)*sizeof(ptr));//(old_size < size ? old_size : size));
                libc_free(ptr);
        }
        return newptr;
}

//!---------------------------------------------------------------------
uni	libc_sch(char* str, char ch) {
    uni i=0;
    while (str[i] != '\0') {
        if (str[i] == ch) {
            return 1;
        }
        ++i;
    }
    return 0;
}
//!---------------------------------------------------------------------

int libc_scmp(char* str1, char* str2){
uni si1=libc_strlen(str1); uni si2=libc_strlen(str2);
if(si1>si2){return 1;}
if(si1<si2){return -1;}
if(si1==si2){
uni i;
for(i=0;i<si1;i++){
if(str1[i]!=str2[i]){return 0;}
}
			}
return 2;
	}


//!---------------------------------------------------------------------
uni libc_strnpos(char* str, char* sub, int ot) {
    int pFind = 0, pos = 0;
    str=str+ot;
    if (libc_strstr(str,sub)) {
        pFind= libc_strlen(libc_strstr(str, sub));
        pos = libc_strlen(str+pFind);
    }
    return pos;
}
//!---------------------------------------------------------------------
long libc_substr_count(char* str_s, char* sub_s) {
    long count_sub=0;
    str_s = libc_strstr(str_s,sub_s);
    while (str_s!=0) {
        str_s=str_s+libc_strlen(sub_s);
        str_s = libc_strstr(str_s,sub_s);
        count_sub++;
    }
    return count_sub;
}

//!---------------------------------------------------------------------

char * 	libc_utos(uni n) {
    *_Hslong+=0;
    uni i, sign,j;
    uni num=n;
    uni l = 0;
    if (num==0) {
        l++;
    }
    if (num<0) {
        num= -num;
        l++;
    }
    while (num) {
        num/=10;
        ++l;
    }
    if ((sign = n) < 0) {
        n = -n;
        l++;
    }
    i = 0;
    do {
        _Hslong[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        _Hslong[i++] = '-';
        l--;
    }
    _Hslong[i] = '\0';
    i = 0;
    j=l-1;
    while (j>i) {
        swap(_Hslong[i],_Hslong[j]);
        i++;
        j--;
    }
    return _Hslong;
}
//!---------------------------------------------------------------------
int libc_is_dec_num(char* str){
int i=0, pr=0;
while(str[i]!=0){
switch(str[i]){
case '-': pr++; break;
case '0': pr++; break;
case '1': pr++; break;
case '2': pr++; break;
case '3': pr++; break;
case '4': pr++; break;
case '5': pr++; break;
case '6': pr++; break;
case '7': pr++; break;
case '8': pr++; break;
case '9': pr++; break;
default :pr=-1; break;
			}
				i++;}
if(i==pr){return 1;}else{return 0;}
	}
//!---------------------------------------------------------------------
void libc_fun_null(void){return;}
//!---------------------------------------------------------------------
///Len type
uni libc_leni(long long num){
uni i = 0;
if(num==0){i++;}
if(num<0){num= -num; i++;} while(num){num/=10;++i;}return i;
}
//!---------------------------------------------------------------------
uni libc_lenul(unsigned long long num){
uni i = 0;
if(num==0){i++;}
if(num<0){num= -num; i++;} while(num){num/=10;++i;}return i;
}

//!---------------------------------------------------------------------

uni libc_lend(double num){
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

//!---------------------------------------------------------------------

uni libc_lenf(float num){
uni i = 0, j = 0, t;
if(num<0){num= -num; i++;}
int ol=(int)num;
while(ol>0){ol/=10; ++i;}
j=i;
num=num-j;///---------------------------------------------------------------------
///Отладка
i++;
while(t>-1){num = num*10; t = (int)num%10; ++i;}

return i;}


//!---------------------------------------------------------------------

uni libc_lenld(long double num){
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

//!---------------------------------------------------------------------

///conversion type
//todo 
//Необходима оптимизация

int libc_ltoi(long long n){///Прототип функции конверции в инт с учетом переполнения
int sz=libc_leni(n)-8;
if(n<0){sz--;}
if(sz>0){	
while(sz){
n=(libc_leni(n)>8)?(n/10):n;		
sz--;
		}
}
return (int)n;
							}
//!---------------------------------------------------------------------

long libc_lltol(long long n){///Прототип функции конверции в лонг с учетом переполнения
int sz=libc_leni(n)-16;
if(n<0){sz--;}
if(sz>0){	
while(sz){
n=(libc_leni(n)>16)?(n/10):n;		
sz--;
		}
}
return (long)n;
							}
//!---------------------------------------------------------------------

long libc_ulltol(unsigned long long n){///Прототип функции конверции в лонг с учетом переполнения
int sz=libc_leni(n)-19;
if(n<0){sz--;}
if(sz>0){	
while(sz){
n=(libc_leni(n)>19)?(n/10):n;		
sz--;
		}
}
return (long)n;
							}
//!---------------------------------------------------------------------

char* libc_dtos(double n){///double to str
char* buff=out_$_dtos;
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


//!---------------------------------------------------------------------

char* libc_ldtos(long double n){///long double to str
char* buff=out_$_ldtos;
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

//!---------------------------------------------------------------------
char* libc_ftos(float n){///float to str
char* buff=out_$_ftos;
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

//!---------------------------------------------------------------------
char* libc_itos(int n){///int to str
	*_$_sint+=0;
     int i=0, sign=0,j=0;
     uni l=libc_leni(n);
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

//!---------------------------------------------------------------------

char* libc_uitos(unsigned int n){///unsigned int to str
	*_$_suint+=0;
     int i=0, sign=0,j=0;
     uni l=libc_leni(n);
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

//!---------------------------------------------------------------------
 char* libc_ltos(long int n){///long to str
	*_$_slong+=0;
     int i=0, sign=0,j=0;
     uni l=libc_leni(n);
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

//!---------------------------------------------------------------------

 char* libc_lltos(long long int n){///long long to str
	*_$_sllong+=0;
     int i=0, sign=0,j=0;
     uni l=libc_leni(n);
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

//!---------------------------------------------------------------------

 char* libc_ulltos(unsigned long long int n){///unsigned long long to str
	*_$_sullong+=0;
     int i=0, sign=0,j=0;
     uni l=libc_leni(n);

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

//!---------------------------------------------------------------------


 char* libc_ultos(unsigned long int n){///unsigned long to str
	*_$_sulong+=0;
     int i=0, sign=0,j=0;
     uni l=libc_leni(n);
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

//!---------------------------------------------------------------------

double libc_stod(char* s){///str to double
int i=0; 
double sign=0,is=0,si=0;
char* sdt=s;
sign = (s[0] == '-') ? -1.0 : 1.0;
int len=libc_strlen(s);
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

//!---------------------------------------------------------------------

long double libc_stold(char* s){///str to long double
int i=0; 
long double sign=0,is=0,si=0;
char* sdt=s;
sign = (s[0] == '-') ? -1.0 : 1.0;
int len=libc_strlen(s);
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

//!---------------------------------------------------------------------

float libc_stof(char* s){///str to float
int i=0; 
float sign=0,is=0,si=0;
char* sdt=s;
sign = (s[0] == '-') ? -1.0 : 1.0;
int len=libc_strlen(s);
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

//!--------------------------------------------------------------------- 1

unsigned int libc_stoui(char* s){///str to unsigned int
int i=0, n=0;
for (n = 0, i=0; libc_strlen(s)>i; i++){
if (s[i] == '-'){i++;}
n = 10 * n + (s[i] - '0');
}
return n;
}

//!--------------------------------------------------------------------- 1

int libc_stoi(char* s){///str to int
int i=0, n=0, sign=0;
sign = (s[0] == '-') ? -1 : 1;
for (n = 0, i=0; libc_strlen(s)>i; i++){
if (s[i] == '-'){i++;}
n = 10 * n + (s[i] - '0');
}
return sign * n;
}

//!--------------------------------------------------------------------- 1

unsigned long libc_stoul(char* s){///str to unsigned long
long i=0, n=0;

for (n = 0, i=0; libc_strlen(s)>i; i++){
if (s[i] == '-'){i++;}
n = 10 * n + (s[i] - '0');
}
return n;
}

//!--------------------------------------------------------------------- 1

long libc_stol(char* s){///str to long
long i=0, n=0, sign=0;
sign = (s[0] == '-') ? -1 : 1;
for (n = 0, i=0; libc_strlen(s)>i; i++){
if (s[i] == '-'){i++;}
n = 10 * n + (s[i] - '0');
}
return sign * n;
}

//!--------------------------------------------------------------------- 1

long long libc_stoll(char* s){/// str to long long
long long i=0, n=0, sign=0;
sign = (s[0] == '-') ? -1 : 1;
for (n = 0, i=0; libc_strlen(s)>i; i++){
if (s[i] == '-'){i++;}
n = 10 * n + (s[i] - '0');
}
return sign * n;
}

//!--------------------------------------------------------------------- 1

unsigned long long libc_stoull(char* s){/// str to unsigned long long
unsigned long long i=0, n=0;
for (n = 0, i=0; libc_strlen(s)>i; i++){
if (s[i] == '-'){i++;}
n = 10 * n + (s[i] - '0');
}
return n;
}
//!--------------------------------------------------------------------- 
void *libc_mcat(void *dst, void *src){
//size_t i;
//if ((uintptr_t)dst % sizeof(long) == 0 && (uintptr_t)src % sizeof(long) == 0) {
//long *d=dst;
//long *s = src;
//mncat(d,s,count(&dst)+count(&src)+2);
//}else{
libc_mncat(dst,src,libc_strlen(dst)+libc_strlen(src));
 //    }
return dst;
	}
//!---------------------------------------------------------------------
void *libc_mcpy(void *dst, void *src, size len){
uni i;
char *d = dst;
char *s = src;
for (i=0; i<len; i++) {d[i] = s[i];}
return dst;
	}
//!---------------------------------------------------------------------
void *libc_mncat(void *dst, void *src, size len){
char *d=dst;
char *s = src;
libc_mcpy(d+libc_strlen(dst),s,len);
return dst;
	}
//!---------------------------------------------------------------------
void *libc_mset(void *pt, int c, size n){
uni i;
char *pb = (char *) pt;
for(i=0;i<(n+1);i++){pb[i]=c;}
return pb;
 }
//!---------------------------------------------------------------------
void *libc_msetn(void *pt, int c, size n){
uni i;
long *pb = (long *) pt;
for(i=0;i<(n);i++){pb[i]=c;}
return pb;
	}
//!---------------------------------------------------------------------
int libc_odd(uni value){return (value & 1);} //определяет четное или нечетное
//!---------------------------------------------------------------------
uni libc_sch_count(char* str, int ch){ //считает количество вхождений символа в строку
uni i=0; uni count=0;
while(str[i] != '\0'){
if(str[i] == ch){count++;}
++i;}
return count;

	}
//!---------------------------------------------------------------------
char* libc_scpy(char *destaddr, char *srcaddr, uni len) { //заполняет строку другой строкой
    char *d = destaddr;
    char *s = srcaddr;
    while (len-- > 0) {
        *d++ = *s++;
    }
    return destaddr;
}
//!---------------------------------------------------------------------
void *libc_set(void *ptr, int ch){ //заполняет строку символом
//if ((uintptr_t)ptr % sizeof(long) == 0) {
//long *p = ptr;
//mset(p,ch,count(&ptr)+1);
//}else{
libc_mset(ptr,ch,libc_strlen(ptr));
 //        }
return ptr;
 }
//!---------------------------------------------------------------------
uni libc_print_str(char * buf){ //Печатает строку
return write($O, (void*)buf, libc_strlen(buf));
}
//!---------------------------------------------------------------------
//Требуется оптимизация
char* libc_strpstr_nomo(char* str,char* ser){ //Получает позицию первого вхождения подстроки не модифицируя строку
if(libc_strstr(str,ser)){	
int len_ser=libc_strlen(ser),len_str=libc_strlen(str),len_nstr;
char* buff_strn=libc_malloc(len_str);
libc_strcpy(buff_strn,"\0");
char* estr=libc_strstr(str,ser)+len_ser;
int iestr=libc_strlen(estr);
len_nstr=len_str-iestr-len_ser;
libc_strncat(buff_strn,str,len_nstr);
char* out=buff_strn;
return out;
}else{return str;}
	}
//!---------------------------------------------------------------------
//Требуется оптимизация
char** libc_explode(char* se,char* str){ //Разбивает строку на массив по разделителю
int i=0,l=0;char* new_s="";
int cou=libc_substr_count(str,se)+2;
char** ret=libc_malloc(cou);
while(l!=-1){
l=libc_strpos(str,se);
new_s =libc_strpstr_nomo(str,se);
ret[i]=new_s;
str=str+l+libc_strlen(se);
	i++;
}
ret[i]='\0';
return ret;        
								}
///---------------------------------------------------------------------
char* libc_implode(char* r,char** arri){
int i=0,n=libc_count((void **)arri),n_arr=0,n_r=libc_strlen(r);

while(i<n){n_arr=n_arr+libc_strlen(arri[i])+n_r;i++;}
char* out=libc_malloc((n_arr+n_r));

i=0;
while(i<n){
	libc_strcat(out,arri[i]);
	if((n-1)!=i){libc_strcat(out,r);}
	i++;
}
return out;
										}
///---------------------------------------------------------------------
#define libc_join libc_implode
///---------------------------------------------------------------------
char* libc_strnstr(char* str, char* ser){
if(libc_strstr(str,ser)){
int len_ser=libc_strlen(ser),len_str=libc_strlen(str),len_nstr;
char* buff_strn=libc_malloc(len_str);
libc_strcpy(buff_strn,"\0");
char* estr=libc_strstr(str,ser)+len_ser;
int iestr=libc_strlen(estr);
len_nstr=len_str-iestr;
libc_strncat(buff_strn,str,len_nstr);
char* out=buff_strn;
return out;
}else{return "";}
	}
///---------------------------------------------------------------------		
char* libc_strpstr(char* str,char* ser){
if(libc_strstr(str,ser)){	
int len_ser=libc_strlen(ser),len_str=libc_strlen(str),len_nstr;
char* buff_strn=libc_malloc(len_str);
libc_strcpy(buff_strn,"\0");
char* estr=libc_strstr(str,ser)+len_ser;
int iestr=libc_strlen(estr);
len_nstr=len_str-iestr-len_ser;
libc_strncat(buff_strn,str,len_nstr);
char* out=buff_strn;
return out;
}else{return "";}
	}
///---------------------------------------------------------------------
long libc_compare(char* tmp_a, char* tmp_b, char* par){ //сравнение строк
long i=0,r=0,n_a=libc_strlen(tmp_a),n_b=libc_strlen(tmp_b);
if(par=="!="){if(n_a!=n_b){return 0;}}
if(par=="=="){
while(n_a>i){
if(tmp_a[i]==tmp_b[i]){r++;}else{r--;}i++;}
if(n_a==r){return 1;}else{return 0;}
			 }
	}
///---------------------------------------------------------------------
int libc_array_search(char* str,char** ars){//Поиск в массиве значения возврат индекса
int i=0;
while(ars[i]!=NULL){
if(libc_compare(ars[i],str,"==")){return i;}
i++;}
return -1;
	}
///---------------------------------------------------------------------
int libc_in_array(char* str,char** ars){//Поиск в массиве значения возврат индекса
int i=0;
while(ars[i]!=NULL){
if(libc_compare(ars[i],str,"==")){return i;}
i++;}
return -1;
	}	
///---------------------------------------------------------------------
char** libc_array_unique(char **ars){
char** item=libc_malloc(sizeof(ars));
int i=0;
while(ars[i]!=NULL){
int id=libc_array_search(ars[i],ars);
if(id!=-1 && id==i){item[id]=ars[i];}else{item[i]="";}
i++;}
return item;	
	}
///---------------------------------------------------------------------
char** libc_array_unique_sort(char **ars){
char** item=libc_malloc(sizeof(ars));
int i=0,n=0;
while(ars[i]!=NULL){
int id=libc_array_search(ars[i],ars);
if(id!=-1 && id==i){item[n++]=ars[i];}
i++;}
return item;	
	}			
///---------------------------------------------------------------------
int libc_isspace(int ch){
	return ch == ' ' || (unsigned)ch-'\t' < 5;
}
///---------------------------------------------------------------------
char* libc_ltrim(char *str) {
  int len = libc_strlen(str);
  char *cur = str;
  while (*cur && libc_isspace(*cur)) {
    ++cur;
    --len;
  }
  if (str != cur) libc_memmove(str, (char*)cur, len + 1);

  return str;
}
///---------------------------------------------------------------------
char* libc_rtrim(char *str) {
  int len = libc_strlen(str);
  char *cur = str + len - 1;
  while (cur != str && libc_isspace(*cur)) --cur;
  cur[libc_isspace(*cur) ? 0 : 1] = '\0';
  return str;
}
///---------------------------------------------------------------------
char * libc_trim(char *str) {
  libc_rtrim(str);
  libc_ltrim(str);
  return str;
}
///---------------------------------------------------------------------
int libc_file_exists(char* filename){
struct stat_f *fi=libc_malloc(sizeof(char));
stat(filename,fi);
if(fi->st_atime==0 && fi->st_mtime==0 && fi->st_ctime==0){return 0;}else{return 1;}
	} 
//!------------------------------------------------------------
size libc_filesize(char* filename){
struct stat_f *fi=libc_malloc(sizeof(char));
stat(filename,fi);
return fi->st_gid;
							}
//!------------------------------------------------------------
char* libc_file_get_contents(char* filename){
struct stat_f *fi=libc_malloc(sizeof(char));
int res=open(filename,O_RDONLY,0);
fstat(res,fi);
char* buff=libc_malloc(fi->st_gid);
read(res,buff,fi->st_gid);
close(res);
return buff;
										}
//!------------------------------------------------------------
int libc_file_put_contents(char* filename, char* src, int appendflag){
int flags=0,out=0;
if(appendflag==0){flags|= (O_CREAT|O_WRONLY|O_TRUNC);}else{flags|= (O_CREAT|O_WRONLY|O_APPEND);}
int res=open(filename,flags,0666);
out=write(res,(void*)src,libc_strlen(src));	
close(res);
return out;
												}										
										
//!------------------------------------------------------------

long libc_rand(long min, long max){
long t,out;
t=time(0);
out = out*0x343fd+0x269EC3;
out=((out >> 0x10) & 0x7FFF)+t;
if(max==0 && max==0){
return out;	
}else{
	max++;
return out % (max-min)+min;
}
								}										
//!------------------------------------------------------------
char * 	libc_string_replace(char *string, char *delimiter, char *replacement) {
    if (!libc_strstr(string,delimiter)) {
        return string;
    }
    int bret = 0, ldel=libc_strlen(delimiter), lrep=libc_strlen(replacement), i=0,j=0;
    char* ret = libc_malloc(libc_strlen(string)+libc_strlen(replacement));
    while (string[i] != '\0') {
        if (!libc_strncmp(&string[i], delimiter, ldel)) {
            i += ldel;
            j += lrep;
            bret = 1;
        } else {
            i++;
            j++;
        }
    }
    i = 0;
    j = 0;
    while (string[i] != '\0') {
        if (!libc_strncmp(&string[i], delimiter, ldel)) {
            libc_memcpy(&ret[j], replacement, lrep);
            i += ldel;
            j += lrep;
        } else {
            ret[j] = string[i];
            i++;
            j++;
        }
    }
    ret[j] = '\0';
    return ret;
}
//!------------------------------------------------------------
int libc_islower(int ch){
	return (unsigned)ch-'a' < 26;
}
//!------------------------------------------------------------
int libc_isupper(int ch){
	return (unsigned)ch-'A' < 26;
}
//!------------------------------------------------------------
int libc_toupper(int ch){
	if (libc_islower(ch)){ return (ch & 95);}
	return ch;
}
//!------------------------------------------------------------
char* libc_strtoupper(char* str){
int i=0,n=libc_strlen(str);
while(n<i){
str[i]=libc_toupper(str[i]);
	i++;}
return str;		
	}
//!------------------------------------------------------------
int libc_tolower(int ch){
	if (libc_isupper(ch)){ return (ch | 32);}
	return ch;
}
//!------------------------------------------------------------
char* libc_strtolower(char* str){
int i=0,n=libc_strlen(str);
while(n<i){
str[i]=libc_tolower(str[i]);
	i++;}
return str;		
	}
//!------------------------------------------------------------
int libc_strcmp(char *l, char *r){
int i=0,ll=libc_strlen(l), lr=libc_strlen(r);
if(ll!=lr){return ll - lr;}
while(l[i]!='\0'){
if(l[i]!=r[i]){return (unsigned int)l[i] - (unsigned int)r[i];}
	i++;}	
								  }
//!------------------------------------------------------------
int libc_strcmpi(char *l, char *r){
int i=0,ll=libc_strlen(l), lr=libc_strlen(r);
if(ll!=lr){return ll - lr;}
char bfl,bfr;
while(l[i]!='\0'){
bfl=libc_toupper(l[i]); bfr=libc_toupper(r[i]);
if(bfl!=bfr){return (unsigned int)bfl - (unsigned int)bfr;}
	i++;}	
								  }
//!------------------------------------------------------------
int libc_strncmpi(char* l, char* r, size_t num){
char bfl,bfr;	
int i=0;
if (num == 0){return 0;}
do {
bfl=libc_toupper(l[i]); bfr=libc_toupper(r[i]);	
if(bfl!=bfr){return ((unsigned int)bfl - (unsigned int)bfr);}
if (bfl == 0){break;}
i++;
} while (--num != 0);
return 0; 

 } 
//!------------------------------------------------------------
char * libc_stristr(char *string, char *substring){
char c, sc;
size_t len;
if ((c = *substring++) != 0) {
len = libc_strlen(substring);
	do {
		do {
		if ((sc = *string++) == 0){	return NULL;}
			} while (libc_tolower(sc) != libc_tolower(c));
	string--;			
		
		} while (libc_strncmpi(string, substring, len) == 0);

	}
return ((char *) string);
}
//!------------------------------------------------------------
char * 	libc_string_ireplace(char *string, char *delimiter, char *replacement) {
    if (!libc_stristr(string,delimiter)) {
        return string;
    }
    int bret = 0, ldel=libc_strlen(delimiter), lrep=libc_strlen(replacement), i=0,j=0;
    char* ret = libc_malloc(sizeof(char*));
    while (string[i] != '\0') {
        if (!libc_strncmpi(&string[i], delimiter, ldel)) {
            i += ldel;
            j += lrep;
            bret = 1;
        } else {
            i++;
            j++;
        }
    }
    i = 0;
    j = 0;
    while (string[i] != '\0') {
        if (!libc_strncmpi(&string[i], delimiter, ldel)) {
            libc_memcpy(&ret[j], replacement, lrep);
            i += ldel;
            j += lrep;
        } else {
            ret[j] = string[i];
            i++;
            j++;
        }
    }
    ret[j] = '\0';
    return ret;
}
//!------------------------------------------------------------
int libc_stripos(char *haystack, char *needle){
   char *p = libc_stristr(haystack, needle);
  if (p){return p - haystack;}else{return -1;}  
} 
///------------------------------------------------------------
char *libc_strchr(const char *s, int c){
    char ch = c;
    for ( ; *s != ch; s++){
        if (*s == '\0'){return 0;}
        }
    return (char *)s;
}
///------------------------------------------------------------
char *libc_dirname(char *s){
if (!s || !*s || !libc_strchr(s, '/')){ return ".";}
size_t n=libc_strlen(s);
int co=libc_sch_count(s,'/'),coti=0,i=0;
char* out=libc_malloc(sizeof(char*));
	do{
	out[i]=s[i];
	if(s[i]=='/'){coti++;}
		i++; 
		}while(i<n && coti!=co);
out[i++]='\0';
	return out;
}
///------------------------------------------------------------
int libc_fopen(char* filename, char* mods){
	int fd,flags;
	if (!libc_strchr("rwa", *mods)) {return 0;}	
	if (libc_strchr(mods, '+')){flags = O_RDWR;}
	else if (*mods == 'r'){flags = O_RDONLY;}else {flags = O_WRONLY;}
	if (*mods != 'r'){flags |= O_CREAT;}
	if (*mods == 'w'){flags |= O_TRUNC;}
	if (*mods == 'a'){flags |= O_APPEND;}
	fd = open(filename, flags, 0666);
	if (fd < 0){ return 0;}else{return fd;}
}
///------------------------------------------------------------
void* libc_end(void** arr){
long pos=libc_count(arr);
return arr[pos];	
					 }
///------------------------------------------------------------					 
#define fclose close
///------------------------------------------------------------
int libc_isalpha(int ch){
	return ((unsigned)ch|32)-'a' < 26;
}
///------------------------------------------------------------
int libc_isdigit(int ch){
	return (unsigned)ch-'0' < 10;
}
///------------------------------------------------------------
#define array($_value...)({\
void* $_ar[]={$_value,'\0'};\
(void**)$_ar;})

///------------------------------------------------------------
int libc_sleep(unsigned int seconds){
struct timespec {
  long tv_sec;
  long tv_nsec;
};
	struct timespec tv = { .tv_sec = seconds, .tv_nsec = 0 };
	if (nanosleep((long)&tv, (long)&tv)){return tv.tv_sec;}
	return 0;
}
///------------------------------------------------------------
char libc_from_hex(char ch) {
  return libc_isdigit(ch) ? ch - '0' : libc_tolower(ch) - 'a' + 10;
}
///------------------------------------------------------------
char libc_to_hex(char code) {
  const char hex[] = "0123456789abcdef";
  return hex[code & 15];
}
///------------------------------------------------------------
int libc_isalnum(int ch){
	return libc_isalpha(ch) || libc_isdigit(ch);
}
///------------------------------------------------------------

char *libc_urlencode(char *str) {
  char *pstr = str, *buf = libc_malloc(libc_strlen(str)), *pbuf = buf;
  while (*pstr) {
    if (libc_isalnum(*pstr) || *pstr == '-' || *pstr == '_' || *pstr == '.' || *pstr == '~') 
      *pbuf++ = *pstr;
    else if (*pstr == ' ') 
      *pbuf++ = '+';
    else 
      *pbuf++ = '%', *pbuf++ = libc_to_hex(*pstr >> 4), *pbuf++ = libc_to_hex(*pstr & 15);
    pstr++;
  }
  *pbuf = '\0';
  return buf;
}
///------------------------------------------------------------
char *libc_urldecode(char *str) {
  char *pstr = str, *buf = libc_malloc(libc_strlen(str)), *pbuf = buf;
  while (*pstr) {
    if (*pstr == '%') {
      if (pstr[1] && pstr[2]) {
        *pbuf++ = libc_from_hex(pstr[1]) << 4 | libc_from_hex(pstr[2]);
        pstr += 2;
      }
    } else if (*pstr == '+') { 
      *pbuf++ = ' ';
    } else {
      *pbuf++ = *pstr;
    }
    pstr++;
  }
  *pbuf = '\0';
  return buf;
}
///------------------------------------------------------------
size_t libc_strnlen(char *str, size_t count){
	char *ps = libc_memchr(str, 0, count);
	return ps ? ps-str : count;
}
///------------------------------------------------------------
char *libc_strndup(char *str, size_t count)
{
	size_t len = libc_strnlen(str, count);
	char *dup = libc_malloc(len+1);
	if (!dup) return NULL;
	libc_memcpy(dup, str, len);
	dup[len] = '\0';
	return dup;
}


///------------------------------------------------------------
 /*
printf("%s\n",libc_substr("abcdef", 1,  -1));     // bcdef
printf("%s\n",libc_substr("abcdef", 1,   3));     // bcd
printf("%s\n",libc_substr("abcdef", 0,   4));     // abcd
printf("%s\n",libc_substr("abcdef", 0,  8));      // abcdef
printf("%s\n",libc_substr("abcdef", -1,   1));    // f
*/
char* libc_substr(char* str, int begin, int len){
if(begin<=-1){begin=libc_strlen(str)+begin;}
  return libc_strndup(str + begin, len); 
} 
///------------------------------------------------------------
char* libc_addslashes(char* str){
int i=0,col=libc_strlen(str),n=0;
char* buff=libc_malloc(sizeof(char*));
while(i<col){	
if(str[i]=='\'' && str[i-1]!='\\'){buff[n++]='\\'; buff[n++]=str[i];}else
if(str[i]=='`' && str[i-1]!='\\'){buff[n++]='\\'; buff[n++]=str[i];}else
if(str[i]=='\\' && str[i-1]!='\\'){buff[n++]='\\'; buff[n++]=str[i];}else
if(str[i]=='"' && str[i-1]!='\\'){buff[n++]='\\'; buff[n++]=str[i];}else
{buff[n++]=str[i];}	
	i++;
			}
return buff;
}
///------------------------------------------------------------
char* libc_stripslashes (char* str ){
int i=0,col=libc_strlen(str),n=0;
char* buff=libc_malloc(sizeof(char*));
while(i<col){
if(str[i]!='\\'){buff[n++]=str[i];i++;}else
if(str[i]=='\\' && str[i+1]=='\\'){buff[n++]=str[i];i++;}else
{i++;}
			}
return buff;	
	}
///------------------------------------------------------------
char* libc_array_replace(char* str, char** delimiters, char **replacement){
int i=0;
char* buffrsa=libc_malloc(sizeof(char**));
buffrsa=str;
while(delimiters[i]!=NULL){
if(replacement[i]!=NULL && replacement[i]!='\0' && libc_strpos(buffrsa,delimiters[i])!=-1){
	buffrsa=libc_string_replace(buffrsa,delimiters[i],replacement[i]);
	}
	i++;}
return buffrsa;		
	}
///------------------------------------------------------------
#ifdef _PCRE_H

///------------------------------------------------------------
libc_preg_print_error(char* pattern,int errchar,const char* errstr){
libc_print_str("Ошибка: ");
libc_print_str((char*)errstr);
libc_print_str("\nСимвол N ");
libc_print_str(libc_itos(errchar));
libc_print_str("\nШаблон:");
libc_print_str(pattern);
libc_print_str("\n");	
	}
///------------------------------------------------------------

int libc_preg_match ( char* pattern, char* subject, char** matches , int flags , int offset){
char *errstr;
unsigned char *tables=pcre_maketables();
int pairs=0,i=0,j=0,vecsize=libc_strlen(subject),vector[vecsize],errchar;
//if(flags==0){flags=(PCRE_UTF8|PCRE_CASELESS|PCRE_MULTILINE);}else{flags|=PCRE_UTF8|PCRE_CASELESS|PCRE_MULTILINE;}
if(matches==NULL){j=PCRE_ANCHORED;}else{j=PCRE_NOTEMPTY;}
pcre *f=pcre_compile(pattern,flags,&errstr,&errchar,tables);
if((f)==NULL){libc_preg_print_error(pattern,errchar,errstr);return -1;}
pcre_extra *f_ext=pcre_study(f,0,&errstr);
pairs=pcre_exec(f,f_ext,subject,libc_strlen(subject),offset,j,vector,vecsize);

while(pairs>i){
matches[i]=libc_malloc(sizeof(char*));	
//pcre_get_substring(subject,vector,pairs, i, &matches[i]);
pcre_copy_substring(subject, vector, pairs,   i, matches[i], sizeof(char*)*vecsize);

i++;
}
return 1;
																	}
 
///------------------------------------------------------------
int libc_preg_match_all ( char* pattern, char* subject, char*** matches , int flags){
char *errstr;
unsigned char *tables=pcre_maketables();
char* buff2=libc_malloc(sizeof(char*));
int pairs=0,n=0,i=0,j=0,p=0,vecsize=libc_strlen(subject)+1,vector[vecsize],errchar;
//if(flags==0){flags=(PCRE_UTF8|PCRE_CASELESS|PCRE_MULTILINE);}else{flags|=PCRE_UTF8|PCRE_CASELESS|PCRE_MULTILINE;}
if(matches==NULL){j=PCRE_ANCHORED;}else{j=PCRE_NOTEMPTY;}
pcre *f=pcre_compile(pattern,flags,&errstr,&errchar,NULL);
if((f)==NULL){libc_preg_print_error(pattern,errchar,errstr);return -1;}
pcre_extra *f_ext=pcre_study(f,0,&errstr);

while((pairs=pcre_exec(f,f_ext,subject,libc_strlen(subject),p,j,vector,vecsize))>0){
matches[i]=libc_malloc(sizeof(char**));
n=0;
if((pairs)<0){return -1;}
while(pairs>n){
matches[i][n]=libc_malloc(sizeof(char*));
pcre_copy_substring(subject,vector,pairs,n,matches[i][n],libc_strlen(subject));
n++;
			  }
p=vector[1];
	i++;
   }

return 1;
																									}

#endif
///------------------------------------------------------------
char* libc_base64_encode(char *data) {
int i = 0;
int j = 0;
int mod_table[] = {0, 2, 1};
	size_t input_length=libc_strlen(data);
    size_t output_length = 4 * ((input_length + 2) / 3);
    char *encoded_data = libc_malloc(input_length+1);
    for (;i< input_length;) {
		unsigned int octet_a = i < input_length ? (unsigned char)data[i++] : 0;
		unsigned int octet_b = i < input_length ? (unsigned char)data[i++] : 0;
		unsigned int octet_c = i < input_length ? (unsigned char)data[i++] : 0;
		unsigned int triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;
        encoded_data[j++] = char_table_base64[(triple >> 3 * 6) & 0x3F];
        encoded_data[j++] = char_table_base64[(triple >> 2 * 6) & 0x3F];
        encoded_data[j++] = char_table_base64[(triple >> 1 * 6) & 0x3F];
        encoded_data[j++] = char_table_base64[(triple >> 0 * 6) & 0x3F];
							  }
	i=0;
    for (;i<mod_table[input_length % 3]; i++){encoded_data[output_length - 1 - i] = '=';}
    return encoded_data;
										}
///------------------------------------------------------------

char* libc_base64_decode(char *data) {
	int i = 0; int j = 0;
	char* decoding_table = libc_malloc(256);
	for (;i<64;i++){decoding_table[(unsigned char) char_table_base64[i]] = i;}
	size_t input_length=libc_strlen(data);
    size_t output_length = libc_strlen(data) / 4 * 4;
    if (data[input_length - 1] == '='){ output_length--;}
    if (data[input_length - 2] == '='){ output_length--;}
    unsigned char *decoded_data = libc_malloc(output_length);
	i=0;   
    for (; i < input_length;) {
        unsigned int sextet_a = data[i] == '=' ? 0 & i++ : decoding_table[data[i++]];
        unsigned int sextet_b = data[i] == '=' ? 0 & i++ : decoding_table[data[i++]];
        unsigned int sextet_c = data[i] == '=' ? 0 & i++ : decoding_table[data[i++]];
        unsigned int sextet_d = data[i] == '=' ? 0 & i++ : decoding_table[data[i++]];
        unsigned int triple = (sextet_a << 3 * 6) + (sextet_b << 2 * 6) + (sextet_c << 1 * 6) + (sextet_d << 0 * 6);
        if (j < output_length) decoded_data[j++] = (triple >> 2 * 8) & 0xFF;
        if (j < output_length) decoded_data[j++] = (triple >> 1 * 8) & 0xFF;
        if (j < output_length) decoded_data[j++] = (triple >> 0 * 8) & 0xFF;
    }
    return decoded_data;
}
///------------------------------------------------------------
char* libc_md5(char* str){
	

#define MD5_SUM1(a,b,c,d,m,s,t) ({ a += ((b & c) | (~b & d)) + m + t; a = b + ((a << s) | (a >> (32-s))); })
#define MD5_SUM2(a,b,c,d,m,s,t) ({ a += ((b & d) | (c & ~d)) + m + t; a = b + ((a << s) | (a >> (32-s))); })
#define MD5_SUM3(a,b,c,d,m,s,t) ({ a += (b ^ c ^ d) + m + t; a = b + ((a << s) | (a >> (32-s))); }) 
#define MD5_SUM4(a,b,c,d,m,s,t) ({ a += (c ^ (b | ~d)) + m + t; a = b + ((a << s) | (a >> (32-s))); }) 

void md5_transform(MD5_CTX *ctx, unsigned char data[]) 
{  
   unsigned int a,b,c,d,m[16],i,j; 
   
   for (i=0,j=0; i < 16; ++i, j += 4){ 
      m[i] = (data[j]) + (data[j+1] << 8) + (data[j+2] << 16) + (data[j+3] << 24); 
   }
   a = ctx->state[0]; b = ctx->state[1];   c = ctx->state[2]; d = ctx->state[3]; 
   
   MD5_SUM1(a,b,c,d,m[0],  7,0xd76aa478); 
   MD5_SUM1(d,a,b,c,m[1], 12,0xe8c7b756); 
   MD5_SUM1(c,d,a,b,m[2], 17,0x242070db); 
   MD5_SUM1(b,c,d,a,m[3], 22,0xc1bdceee); 
   MD5_SUM1(a,b,c,d,m[4],  7,0xf57c0faf); 
   MD5_SUM1(d,a,b,c,m[5], 12,0x4787c62a); 
   MD5_SUM1(c,d,a,b,m[6], 17,0xa8304613); 
   MD5_SUM1(b,c,d,a,m[7], 22,0xfd469501); 
   MD5_SUM1(a,b,c,d,m[8],  7,0x698098d8); 
   MD5_SUM1(d,a,b,c,m[9], 12,0x8b44f7af); 
   MD5_SUM1(c,d,a,b,m[10],17,0xffff5bb1); 
   MD5_SUM1(b,c,d,a,m[11],22,0x895cd7be); 
   MD5_SUM1(a,b,c,d,m[12], 7,0x6b901122);
   MD5_SUM1(d,a,b,c,m[13],12,0xfd987193); 
   MD5_SUM1(c,d,a,b,m[14],17,0xa679438e); 
   MD5_SUM1(b,c,d,a,m[15],22,0x49b40821); 
   
   MD5_SUM2(a,b,c,d,m[1],  5,0xf61e2562); 
   MD5_SUM2(d,a,b,c,m[6],  9,0xc040b340); 
   MD5_SUM2(c,d,a,b,m[11],14,0x265e5a51); 
   MD5_SUM2(b,c,d,a,m[0], 20,0xe9b6c7aa);
   MD5_SUM2(a,b,c,d,m[5],  5,0xd62f105d); 
   MD5_SUM2(d,a,b,c,m[10], 9,0x02441453); 
   MD5_SUM2(c,d,a,b,m[15],14,0xd8a1e681); 
   MD5_SUM2(b,c,d,a,m[4], 20,0xe7d3fbc8);
   MD5_SUM2(a,b,c,d,m[9],  5,0x21e1cde6); 
   MD5_SUM2(d,a,b,c,m[14], 9,0xc33707d6); 
   MD5_SUM2(c,d,a,b,m[3], 14,0xf4d50d87); 
   MD5_SUM2(b,c,d,a,m[8], 20,0x455a14ed);
   MD5_SUM2(a,b,c,d,m[13], 5,0xa9e3e905); 
   MD5_SUM2(d,a,b,c,m[2],  9,0xfcefa3f8); 
   MD5_SUM2(c,d,a,b,m[7], 14,0x676f02d9); 
   MD5_SUM2(b,c,d,a,m[12],20,0x8d2a4c8a);
   
   MD5_SUM3(a,b,c,d,m[5],  4,0xfffa3942); 
   MD5_SUM3(d,a,b,c,m[8], 11,0x8771f681); 
   MD5_SUM3(c,d,a,b,m[11],16,0x6d9d6122); 
   MD5_SUM3(b,c,d,a,m[14],23,0xfde5380c); 
   MD5_SUM3(a,b,c,d,m[1],  4,0xa4beea44); 
   MD5_SUM3(d,a,b,c,m[4], 11,0x4bdecfa9); 
   MD5_SUM3(c,d,a,b,m[7], 16,0xf6bb4b60); 
   MD5_SUM3(b,c,d,a,m[10],23,0xbebfbc70); 
   MD5_SUM3(a,b,c,d,m[13], 4,0x289b7ec6); 
   MD5_SUM3(d,a,b,c,m[0], 11,0xeaa127fa); 
   MD5_SUM3(c,d,a,b,m[3], 16,0xd4ef3085); 
   MD5_SUM3(b,c,d,a,m[6], 23,0x04881d05); 
   MD5_SUM3(a,b,c,d,m[9],  4,0xd9d4d039); 
   MD5_SUM3(d,a,b,c,m[12],11,0xe6db99e5); 
   MD5_SUM3(c,d,a,b,m[15],16,0x1fa27cf8); 
   MD5_SUM3(b,c,d,a,m[2], 23,0xc4ac5665); 
      
   MD5_SUM4(a,b,c,d,m[0],  6,0xf4292244); 
   MD5_SUM4(d,a,b,c,m[7], 10,0x432aff97); 
   MD5_SUM4(c,d,a,b,m[14],15,0xab9423a7); 
   MD5_SUM4(b,c,d,a,m[5], 21,0xfc93a039); 
   MD5_SUM4(a,b,c,d,m[12], 6,0x655b59c3); 
   MD5_SUM4(d,a,b,c,m[3], 10,0x8f0ccc92); 
   MD5_SUM4(c,d,a,b,m[10],15,0xffeff47d); 
   MD5_SUM4(b,c,d,a,m[1], 21,0x85845dd1); 
   MD5_SUM4(a,b,c,d,m[8],  6,0x6fa87e4f); 
   MD5_SUM4(d,a,b,c,m[15],10,0xfe2ce6e0); 
   MD5_SUM4(c,d,a,b,m[6], 15,0xa3014314); 
   MD5_SUM4(b,c,d,a,m[13],21,0x4e0811a1); 
   MD5_SUM4(a,b,c,d,m[4],  6,0xf7537e82); 
   MD5_SUM4(d,a,b,c,m[11],10,0xbd3af235); 
   MD5_SUM4(c,d,a,b,m[2], 15,0x2ad7d2bb); 
   MD5_SUM4(b,c,d,a,m[9], 21,0xeb86d391); 

   ctx->state[0] += a; ctx->state[1] += b; ctx->state[2] += c; ctx->state[3] += d; 
}  

void md5_update(MD5_CTX *ctx, unsigned char data[], unsigned char hash[]){  
//init	
   ctx->datalen = 	0; 
   ctx->bitlen[0] = 0; 
   ctx->bitlen[1] = 0; 
   ctx->state[0] = 0x67452301; 
   ctx->state[1] = 0xEFCDAB89; 
   ctx->state[2] = 0x98BADCFE; 
   ctx->state[3] = 0x10325476;	
//end init
//update	
   unsigned int t,i,len=libc_strlen((char*)data);
   
   for (i=0; i < len; ++i) { 
      ctx->data[ctx->datalen] = data[i]; 
      ctx->datalen++; 
      if (ctx->datalen == 64) { 
         md5_transform(ctx,ctx->data); 
if (ctx->bitlen[0] > 0xffffffff - 512){ ++ctx->bitlen[1]; ctx->bitlen[0] += 512;}         
         
          
         ctx->datalen = 0; 
      }  
   }
//end update
//final   
   i = ctx->datalen; 

   if (ctx->datalen < 56) { 
      ctx->data[i++] = 0x80; 
      while (i < 56) 
         ctx->data[i++] = 0x00; 
   }  
   else if (ctx->datalen >= 56) { 
      ctx->data[i++] = 0x80; 
      while (i < 64) 
         ctx->data[i++] = 0x00; 
      md5_transform(ctx,ctx->data); 
      libc_memset(ctx->data,0,56); 
   }  
   


if (ctx->bitlen[0] > 0xffffffff - 8 * ctx->datalen){++ctx->bitlen[1];} 
   ctx->bitlen[0] += 8 * ctx->datalen;     
   ctx->data[56] = ctx->bitlen[0]; 
   ctx->data[57] = ctx->bitlen[0] >> 8; 
   ctx->data[58] = ctx->bitlen[0] >> 16; 
   ctx->data[59] = ctx->bitlen[0] >> 24; 
   ctx->data[60] = ctx->bitlen[1]; 
   ctx->data[61] = ctx->bitlen[1] >> 8; 
   ctx->data[62] = ctx->bitlen[1] >> 16;  
   ctx->data[63] = ctx->bitlen[1] >> 24; 
   md5_transform(ctx,ctx->data); 
   
   for (i=0; i < 4; ++i) { 
      hash[i]    = (ctx->state[0] >> (i*8)) & 0x000000ff; 
      hash[i+4]  = (ctx->state[1] >> (i*8)) & 0x000000ff; 
      hash[i+8]  = (ctx->state[2] >> (i*8)) & 0x000000ff; 
      hash[i+12] = (ctx->state[3] >> (i*8)) & 0x000000ff; 
   }
 //end final       
}  

    char ha[16];
    char buf[33];//=libc_malloc(sizeof(char*)); 
   MD5_CTX ctx; 
   md5_update(&ctx,str,ha); 

   
    unsigned char * pin = ha;
    const char * hex = "0123456789abcdef";
    char * pout = buf;
    int i = 0;
    for(; i < 16; ++i){
        *pout++ = hex[(*pin>>4)&0xF];
        *pout++ = hex[(*pin++)&0xF];
					}	
	    *pout = 0;
	char* outs=buf;    
return outs;
	}
  
///------------------------------------------------------------
