
//!---------------------------------------------------------------------1	
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
//!---------------------------------------------------------------------2
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
//!---------------------------------------------------------------------3
void *libc_memcpy (void *dest, void *src, size n)
{
        register char *r1 = dest;
        register const char *r2 = src;
 
        while (n) {
                *r1++ = *r2++;
                --n;
        }
 
        return dest;
}
//!---------------------------------------------------------------------4
void *libc_memset(void *s, int c, size n)
{
        register unsigned char *p = (unsigned char *) s;
 
        while (n) {
                *p++ = (unsigned char) c;
                --n;
        }
 
        return s;
}
//!---------------------------------------------------------------------5
char* libc_strcat ( char* des, char* so ){
while (*des) ++des;
while ((*des++ = *so++) != '\0') ;
return des;
}
//!---------------------------------------------------------------------
char * libc_strcpy(char *to, const char *from){
	char *save = to;
	for (; (*to = *from) != 0; ++from, ++to);
	return(save);
}
//!---------------------------------------------------------------------
size libc_strlen(char *str){
	register const char *s;
	for (s = str; *s; ++s);
	return(s - str);
}
//!---------------------------------------------------------------------
char* libc_strncat(char* dst, const char * src, size n){
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
		*d = 0;
	}
	return dst;
}
//!---------------------------------------------------------------------
int libc_strncmp(const char* s1, const char* s2, size num){
if (num == 0){return 0;}
do {
if (*s1 != *s2++){return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));}
if (*s1++ == 0){break;}
} while (--num != 0);
return 0;
 } 
//!---------------------------------------------------------------------

char * libc_strstr(char *string, char *substring){
    register char *a, *b;
    b = substring;
    if (*b == 0) {	return string;   }
    
    for ( ; *string != 0; string += 1) {
	if (*string != *b) {continue;}
	a = string;
	while (1) {if (*b == 0) {return string; }
	    if (*a++ != *b++) {break;}
	}
	b = substring;
										}
    return (char *) 0;
}
//!---------------------------------------------------------------------
void libc_free(void *ptr){

if (ptr == NULL){return;}
ptr -= sizeof(size);
munmap(ptr, * (size *) ptr + sizeof(size));
}
//!---------------------------------------------------------------------
uni libc_strpos(char *haystack, char *needle)
{
   char *p = libc_strstr(haystack, needle);
   if (p){return p - haystack;}else{return -1;}  
} 
//!---------------------------------------------------------------------

void *libc_malloc(size __size){
void *result;
result = mmap(NULL, __size+sizeof(void*) * sizeof(void*) , PROT_READ | PROT_WRITE,MMAP_FLAGS, 0, 0);//+ sizeof(size_t)
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

char * 	libc_string_replace(char *string, char *delimiter, char *replacement) {
    if (!libc_strstr(string,delimiter)) {
        return string;
    }
    int bret = 0, ldel=libc_strlen(delimiter), lrep=libc_strlen(replacement), i=0,j=0;
    char* ret = out_Hstr_rep;
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

uni libc_lens(char* v){uni i=0;while(v[i]!=0){++i;}return i;}

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
/*
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
*/
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
uni libc_sch_count(char* str, int ch){
uni i=0; uni count=0;
while(str[i] != '\0'){
if(str[i] == ch){count++;}
++i;}
return count;

	}
//!---------------------------------------------------------------------
char* libc_scpy(char *destaddr, char *srcaddr, uni len) {
    char *d = destaddr;
    char *s = srcaddr;
    while (len-- > 0) {
        *d++ = *s++;
    }
    return destaddr;
}
//!---------------------------------------------------------------------
void *libc_set(void *ptr, int ch){
//if ((uintptr_t)ptr % sizeof(long) == 0) {
//long *p = ptr;
//mset(p,ch,count(&ptr)+1);
//}else{
libc_mset(ptr,ch,libc_strlen(ptr));
 //        }
return ptr;
 }
//!---------------------------------------------------------------------
uni libc_print_str(char * buf){
return write($O, (void*)buf, libc_strlen(buf));
}
//!---------------------------------------------------------------------



