char* libc_itos(int n);
//!---------------------------------------------------------------------
size libc_count(void** v) {
    size i=0;
    while (v[i]!=NULL) {
        ++i;
    }
    return i;
}
//!------------------------------------------------------------
uni libc_strpos(char *haystack, char *needle){
   char *p = libc_strstr(haystack, needle);
   if (p){return p - haystack;}else{return -1;}  
} 
//!------------------------------------------------------------
int libc_ads(int i){return (i)?0:1;}

///------------------------------------------------------------
void *libc_alloc(size_t __size){
char* buff[__size];
void* out=(void*)buff;	
out=out+ sizeof(size_t);
return (void*)out;
								}
///------------------------------------------------------------

void *libc_malloc(size_t __size){
void* out=sbrk(__size*sizeof(out));
return (void*)out;
}
///------------------------------------------------------------
void libc_free(void *ptr){
if (ptr == NULL){return;}
ptr=sbrk((libc_count((void**)ptr)*sizeof(ptr))*-1);
					}
///------------------------------------------------------------
void *libc_realloc(void *ptr, size_t __size){
        void *newptr = NULL;
 
        if (!ptr){return libc_malloc(__size);}
        if (!__size) {
                libc_free(ptr);
                return libc_malloc(sizeof(ptr));
        }
 
        newptr = libc_malloc(__size);
        if (newptr) {
                size_t old_size = *((size_t *) (ptr - sizeof(size_t)));
				 
				 libc_memcpy(newptr, ptr,libc_count((void**)ptr));
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
    char* slong=malloc(32);
    slong+=0;
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
        slong[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        slong[i++] = '-';
        l--;
    }
    slong[i] = '\0';
    i = 0;
    j=l-1;
    while (j>i) {
        swap(slong[i],slong[j]);
        i++;
        j--;
    }
    return slong;
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
case '.': pr++; break;
default :pr=-1; break;
			}
				i++;}
if(i==pr){return 1;}else{return 0;}
	}
//!---------------------------------------------------------------------
int libc_is_hex_num(char* str){
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
case 'a': pr++; break;
case 'b': pr++; break;
case 'c': pr++; break;
case 'd': pr++; break;
case 'f': pr++; break;
default :pr=-1; break;
			}
				i++;}
if(i==pr){return 1;}else{return 0;}
	}	

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
num=num-j;
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
char* buff=malloc(32);
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
char* buff=malloc(32);
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
char* buff=malloc(32);
	*buff =+0;
char* a3 = buff;

long long i=0,j=0,k=0;
long long x=0,y=0,t=0,z=0;
if(n<0) {a3[j++] = '-'; n = -n;}
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
			z++;}
a3[j-1]='\0';



return a3;
}

//!---------------------------------------------------------------------
char* libc_itos(int n){///int to str
     int i=0, sign=0,j=0;
     uni l=libc_leni(n);
     char* sint=malloc(l+1);
	 sint+=0;
     if ((sign = n) < 0){n = -n; l++;}
	 i = 0;
     do {
     sint[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);
     if (sign < 0){sint[i++] = '-'; l--;}
     sint[i] = '\0';
i = 0;
j=l-1;
while(j>i) {swap(sint[i],sint[j]);i++; j--;}
return sint;
					}
//!---------------------------------------------------------------------
#define libc_uitos libc_itos

//!---------------------------------------------------------------------
 char* libc_ltos(long int n){///long to str

     int i=0, sign=0,j=0;
     uni l=libc_leni(n);
	 char* slong=malloc(l+1);
	 slong+=0;

      if ((sign = n) < 0){n = -n; l++;}
i = 0;
     do {
         slong[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);
     if (sign < 0){slong[i++] = '-'; l--;}
     slong[i] = '\0';
i = 0;
j=l-1;
while(j>i) {swap(slong[i],slong[j]);i++; j--;}
return slong;
 }

//!---------------------------------------------------------------------

 char* libc_lltos(long long int n){///long long to str
	
     int i=0, sign=0,j=0;
     uni l=libc_leni(n);
	 char* sllong=malloc(l+1);
	 sllong+=0;

      if ((sign = n) < 0){n = -n; l++;}
i = 0;
     do {
         sllong[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);
     if (sign < 0){sllong[i++] = '-'; l--;}
     sllong[i] = '\0';
i = 0;
j=l-1;
while(j>i) {swap(sllong[i],sllong[j]);i++; j--;}
return sllong;
 }

//!---------------------------------------------------------------------

 char* libc_ulltos(unsigned long long int n){///unsigned long long to str

     int i=0, sign=0,j=0;
     uni l=libc_leni(n);
	char *sullong=malloc(l+1);
	sullong+=0;
      if ((sign = n) < 0){n = -n; l++;}
i = 0;
     do {
         sullong[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);
     if (sign < 0){sullong[i++] = '-'; l--;}
     sullong[i] = '\0';
i = 0;
j=l-1;
while(j>i) {swap(sullong[i],sullong[j]);i++; j--;}
return sullong;
 }

//!---------------------------------------------------------------------


 char* libc_ultos(unsigned long int n){///unsigned long to str

     int i=0, sign=0,j=0;
     uni l=libc_leni(n);
     char *sulong=malloc(l+1);
     sulong+=0;

      if ((sign = n) < 0){n = -n; l++;}
i = 0;
     do {
         sulong[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);
     if (sign < 0){sulong[i++] = '-'; l--;}
     sulong[i] = '\0';
i = 0;
j=l-1;
while(j>i) {swap(sulong[i],sulong[j]);i++; j--;}
return sulong;
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
inline int libc_odd(uni value){return (value & 1);} //определяет четное или нечетное
//!---------------------------------------------------------------------
uni libc_sch_count(char* str, int ch){ //считает количество вхождений символа в строку
uni i=0; uni count=0;
while(str[i] != '\0'){
if(str[i] == ch){count++;}
++i;}
return count;

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
char* buff_strn=malloc(strlen(str));
libc_strcpy(buff_strn,"\0");
char* estr=libc_strstr(str,ser)+len_ser;
int iestr=libc_strlen(estr);
len_nstr=len_str-iestr-len_ser;
libc_strncat(buff_strn,str,len_nstr);
return buff_strn;
}else{return str;}
	}
//!---------------------------------------------------------------------
//Требуется оптимизация
char** libc_explode(char* se,char* str){ //Разбивает строку на массив по разделителю
int i=0,l=0,n=0,len=libc_strlen(str),cou=libc_substr_count(str,se);
char** ret=malloc(cou+1);
while(l!=-1){
l=libc_strpos(str,se);
ret[i]=libc_strpstr_nomo(str,se);
str=str+l+libc_strlen(se);
	i++;
			}			
//ret[i]='\0';
return ret;      
										}
///---------------------------------------------------------------------
char* libc_implode(char* r,char** arri){
int i=0,n=libc_count((void **)arri),n_arr=0,n_r=libc_strlen(r);

while(i<n){n_arr=n_arr+libc_strlen(arri[i])+n_r;i++;}
char* out=malloc(i);

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
char* buff_strn=libc_malloc(libc_strlen(str));
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
return buff_strn;
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
char** item=libc_malloc(libc_count((void**)ars));
int i=0;
while(ars[i]!=NULL){
int id=libc_array_search(ars[i],ars);
if(id!=-1 && id==i){item[id]=ars[i];}else{item[i]="";}
i++;}
return item;	
	}
///---------------------------------------------------------------------
char** libc_array_unique_sort(char **ars){
char** item=libc_malloc(libc_count((void**)ars));
int i=0,n=0;
while(ars[i]!=NULL){
int id=libc_array_search(ars[i],ars);
if(id!=-1 && id==i){item[n++]=ars[i];}
i++;}
return item;	
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
struct stat_f *fi=libc_malloc(0);
stat(filename,fi);
if(fi->st_atime==0 && fi->st_mtime==0 && fi->st_ctime==0){
	free((void*)fi);
	return 0;
	}else{
		return 1;}
	} 
//!------------------------------------------------------------
size libc_filesize(char* filename){
struct stat_f *fi=libc_malloc(0);
stat(filename,fi);
int out=fi->st_gid;
free(fi);
return out;
							}
//!------------------------------------------------------------
char* libc_file_get_contents(char* filename){
struct stat_f *fi=libc_malloc(0);
int res=open(filename,O_RDONLY,0);
fstat(res,fi);
char* buff=libc_malloc(fi->st_gid);
read(res,buff,fi->st_gid);
close(res);
free((void*)fi);
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
    int bret = 0, ldel=libc_strlen(delimiter), lrep=libc_strlen(replacement),lstr=libc_strlen(string), i=0,j=0;
    char* ret = libc_malloc(ldel+lrep+lstr);
    while (string[i] != '\0') {
        if (!libc_strncmp(&string[i], delimiter, ldel)) {
            i += ldel;
            j += lrep;
            bret = 1;
        } else {i++;j++;}
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
char* libc_strtoupper(char* str){
int i=0,n=libc_strlen(str);
while(n<i){
str[i]=libc_toupper(str[i]);
	i++;}
return str;		
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
    int bret = 0, ldel=libc_strlen(delimiter),lstr=libc_strlen(string), lrep=libc_strlen(replacement), i=0,j=0;
    char* ret = libc_malloc(ldel+lrep+lstr);
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

char *libc_dirname(char *s){
if (!s || !*s || !libc_strchr(s, '/')){ return ".";}
size_t n=libc_strlen(s);
int co=libc_sch_count(s,'/'),coti=0,i=0;
char* out=libc_malloc(n);
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
#define array($_value...)({\
void* $_ar[]={$_value,'\0'};\
(void**)$_ar;})

///------------------------------------------------------------
int libc_sleep(unsigned int seconds){

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
char *libc_strndup(char *str, size_t count){
	size_t len = libc_strnlen(str, count);
	char *dup = libc_malloc(len+count);
	if (!dup){ return NULL;}
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
char* buff=libc_malloc(col);
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
char* buff=libc_malloc(col);
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
char* buffrsa=libc_malloc(libc_strlen(str));
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
libc_preg_print_error(char* pattern,int errchar, char* errstr){
libc_print_str("Ошибка: ");
libc_print_str((char*)errstr);
libc_print_str("\nСимвол N ");
libc_print_str(libc_itos(errchar));
libc_print_str("\nШаблон:");
libc_print_str(pattern);
libc_print_str("\n");	
	}
///------------------------------------------------------------
/*
int libc_preg_match ( char* pattern, char* subject, char** matches , int flags , int offset){
char *errstr;
unsigned char *tables="";//=pcre_maketables();
int pairs=0,i=0,j=0,vecsize=libc_strlen(subject),vector[vecsize],errchar;
//if(flags==0){flags=(PCRE_UTF8|PCRE_CASELESS|PCRE_MULTILINE);}else{flags|=PCRE_UTF8|PCRE_CASELESS|PCRE_MULTILINE;}
if(matches==NULL){j=PCRE_ANCHORED;}else{j=PCRE_NOTEMPTY;}
pcre *f=pcre_compile(pattern,flags,&errstr,&errchar,NULL);
//if((f)==NULL){libc_preg_print_error(pattern,errchar,errstr);return -1;}
//pcre_extra *f_ext=pcre_study(f,0,&errstr);
//pairs=pcre_exec(f,f_ext,subject,libc_strlen(subject),offset,j,vector,vecsize);

pairs=pcre_exec(f,NULL,subject,libc_strlen(subject),offset,j,vector,vecsize);
//while(pairs>i){
//matches[i]=libc_malloc(sizeof(matches[i]));	
//pcre_get_substring(subject,vector,pairs, i, &matches[i]);
//pcre_copy_substring(subject, vector, pairs,   i, matches[i], sizeof(char*)*vecsize);

//i++;
//}
return 1;
																	}
*/
///------------------------------------------------------------
/*
int libc_preg_match_all ( char* pattern, char* subject, char*** matches , int flags){
char *errstr;
unsigned char *tables="";//pcre_maketables();
char* buff2=libc_malloc(sizeof(buff2));
int pairs=0,n=0,i=0,j=0,p=0,vecsize=libc_strlen(subject)+1,vector[vecsize],errchar;
//if(flags==0){flags=(PCRE_UTF8|PCRE_CASELESS|PCRE_MULTILINE);}else{flags|=PCRE_UTF8|PCRE_CASELESS|PCRE_MULTILINE;}
if(matches==NULL){j=PCRE_ANCHORED;}else{j=PCRE_NOTEMPTY;}
pcre *f=pcre_compile(pattern,flags,&errstr,&errchar,NULL);
if((f)==NULL){libc_preg_print_error(pattern,errchar,errstr);return -1;}
//pcre_extra *f_ext=pcre_study(f,0,&errstr);

while((pairs=pcre_exec(f,f_ext,subject,libc_strlen(subject),p,j,vector,vecsize))>0){
matches[i]=malloc(sizeof(matches[i]));
n=0;
if((pairs)<0){return -1;}
while(pairs>n){
matches[i][n]=malloc(sizeof(matches[i][n]));
pcre_copy_substring(subject,vector,pairs,n,matches[i][n],libc_strlen(subject));
n++;
			  }
p=vector[1];
	i++;
   }

return 1;
																									}
*/
///---------------------------------------------------------------------
char** simgen(char* sim, int cou){
int i=0;
char** outs=malloc(cou);
char* numb=malloc(3);
while(cou>i){
numb=sim;
libc_strcat(numb,libc_itos(i));
outs[i]=numb;	
i++;}
return outs;	
}																								
///---------------------------------------------------------------------
/*
char *string_preg_replace(char* pattern, char* replacement, char* subject , int limit){
int i=0;
char* buffr=subject;
char*** pat_ar=malloc(sizeof(pat_ar));	
if(libc_preg_match_all(pattern,subject,pat_ar,0)){
char* nbuffr=replacement;
char** sim=simgen("$",100);
char** newarr=malloc(sizeof(newarr));
while(pat_ar[i]!=NULL){newarr[i]=pat_ar[i][0];i++;}
char** aruq=libc_array_unique_sort(newarr);
char** nsim=malloc(sizeof(nsim));
i=0;
while(sim[i]!=NULL){
if(libc_strpos(nbuffr,sim[i])!=-1 && aruq[i]!=NULL){nsim[i]=sim[i];}else{nsim[i]="";}
i++;
}
nbuffr=libc_array_replace(nbuffr,sim,nsim);
i=0;
char* tmp=malloc(sizeof(tmp));
char** sep=malloc(sizeof(sep));
while(aruq[i]!=NULL){
if(nsim[i]!=""){
tmp=libc_strstr(nbuffr,nsim[i]);
tmp=libc_strpstr_nomo(tmp+1,"$");
sep[i]="$";
libc_strcat(sep[i],tmp);
sep[i]=libc_string_replace(sep[i],nsim[i],aruq[i]);
}else{sep[i]="";}
i++;}
buffr=libc_array_replace(buffr,aruq,sep);
free(pat_ar);
free(sim);
free(newarr);
free(aruq);
free(nsim);
free(nbuffr);
free(tmp);
free(sep);
}

return buffr;	
																					}
*/ 
#endif
///------------------------------------------------------------
char* libc_base64_encode(char *data) {
int i = 0;
int j = 0;
int mod_table[] = {0, 2, 1};
	size_t input_length=libc_strlen(data);
    size_t output_length = 4 * ((input_length + 2) / 3);
    char *encoded_data = libc_malloc(output_length);
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
	char* decoding_table = libc_malloc(sizeof(decoding_table));
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

void md5_transform(MD5_CTX *ctx, unsigned char data[]){  
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

void md5_proc(MD5_CTX *ctx, unsigned char data[], unsigned char hash[]){  
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
    char buf[33];
   MD5_CTX ctx; 
   md5_proc(&ctx,str,ha); 

   
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
void __echo(char* p,...){
va_list arg;
va_start(arg,p);
while(p){libc_print_str(p); p=va_arg(arg,char*);}
va_end(arg);
return;
					}
#define echo(x...) (__echo(x,NULL))
///------------------------------------------------------------
typedef struct {
char *scheme, *host, *port, *path, *query, *fragment, *username, *password;
}parsed_url;
///------------------------------------------------------------
int _is_scheme_char(int c){
    return (!isalpha(c) && '+' != c && '-' != c && '.' != c) ? 0 : 1;
}
///---------------------------------------------------------------------
void parsed_url_free(parsed_url* purl){
    if ( NULL != purl ) {
        if ( NULL != purl->scheme ) {
            free((void *)purl->scheme);
        }
        if ( NULL != purl->host ) {
            free((void *)purl->host);
        }
        if ( NULL != purl->port ) {
            free((void *)purl->port);
        }
        if ( NULL != purl->path ) {
            free((void *)purl->path);
        }
        if ( NULL != purl->query ) {
            free((void *)purl->query);
        }
        if ( NULL != purl->fragment ) {
            free((void *)purl->fragment);
        }
        if ( NULL != purl->username ) {
            free((void *)purl->username);
        }
        if ( NULL != purl->password ) {
            free((void *)purl->password);
        }
        free((void *)purl);
    }
}
///---------------------------------------------------------------------
parsed_url *parse_url(char *url){
    parsed_url *purl;
    char *tmpstr;
    char *curstr;
    int len;
    int i;
    int userpass_flag;
    int bracket_flag;


    purl = malloc(sizeof(parsed_url));
    if ( NULL == purl ) {
        return NULL;
    }
    purl->scheme = NULL;
    purl->host = NULL;
    purl->port = NULL;
    purl->path = NULL;
    purl->query = NULL;
    purl->fragment = NULL;
    purl->username = NULL;
    purl->password = NULL;

    curstr = url;


    tmpstr = libc_strchr(curstr, ':');
    if ( NULL == tmpstr ) {
        parsed_url_free(purl);
        return NULL;
    }

    len = tmpstr - curstr;
    for ( i = 0; i < len; i++ ) {
        if ( !_is_scheme_char(curstr[i]) ) {
            parsed_url_free(purl);
            return NULL;
        }
    }

    purl->scheme = malloc(len+1);
    if ( NULL == purl->scheme ) {
        parsed_url_free(purl);
        return NULL;
    }
    libc_strncpy(purl->scheme, curstr, len);
    purl->scheme[len] = '\0';

    for ( i = 0; i < len; i++ ) {
        purl->scheme[i] = tolower(purl->scheme[i]);
    }

    tmpstr++;
    curstr = tmpstr;

    for ( i = 0; i < 2; i++ ) {
        if ( '/' != *curstr ) {
            parsed_url_free(purl);
            return NULL;
        }
        curstr++;
    }


    userpass_flag = 0;
    tmpstr = curstr;
    while ( '\0' != *tmpstr ) {
        if ( '@' == *tmpstr ) {
            userpass_flag = 1;
            break;
        } else if ( '/' == *tmpstr ) {
            userpass_flag = 0;
            break;
        }
        tmpstr++;
    }


    tmpstr = curstr;
    if ( userpass_flag ) {

        while ( '\0' != *tmpstr && ':' != *tmpstr && '@' != *tmpstr ) {
            tmpstr++;
        }
        len = tmpstr - curstr;
        purl->username = malloc(len + 1);
        if ( NULL == purl->username ) {
            parsed_url_free(purl);
            return NULL;
        }
        (void)libc_strncpy(purl->username, curstr, len);
        purl->username[len] = '\0';

        curstr = tmpstr;
        if ( ':' == *curstr ) {
            curstr++;

            tmpstr = curstr;
            while ( '\0' != *tmpstr && '@' != *tmpstr ) {
                tmpstr++;
            }
            len = tmpstr - curstr;
            purl->password = malloc(len + 1);
            if ( NULL == purl->password ) {
                parsed_url_free(purl);
                return NULL;
            }
            (void)strncpy(purl->password, curstr, len);
            purl->password[len] = '\0';
            curstr = tmpstr;
        }

        if ( '@' != *curstr ) {
           parsed_url_free(purl);
            return NULL;
        }
        curstr++;
    }

    if ( '[' == *curstr ) {
        bracket_flag = 1;
    } else {
        bracket_flag = 0;
    }

    tmpstr = curstr;
    while ( '\0' != *tmpstr ) {
        if ( bracket_flag && ']' == *tmpstr ) {

            tmpstr++;
            break;
        } else if ( !bracket_flag && (':' == *tmpstr || '/' == *tmpstr) ) {

            break;
        }
        tmpstr++;
    }
    len = tmpstr - curstr;
    purl->host = malloc(len + 1);
    if ( NULL == purl->host || len <= 0 ) {
       parsed_url_free(purl);
        return NULL;
    }
    libc_strncpy(purl->host, curstr, len);
    purl->host[len] = '\0';
    curstr = tmpstr;


    if ( ':' == *curstr ) {
        curstr++;

        tmpstr = curstr;
        while ( '\0' != *tmpstr && '/' != *tmpstr ) {
            tmpstr++;
        }
        len = tmpstr - curstr;
        purl->port = malloc(len + 1);
        if ( NULL == purl->port ) {
            parsed_url_free(purl);
            return NULL;
        }
        libc_strncpy(purl->port, curstr, len);
        purl->port[len] = '\0';
        curstr = tmpstr;
    }


    if ( '\0' == *curstr ) {
        return purl;
    }


    if ( '/' != *curstr ) {
        parsed_url_free(purl);
        return NULL;
    }
    curstr++;


    tmpstr = curstr;
    while ( '\0' != *tmpstr && '#' != *tmpstr  && '?' != *tmpstr ) {
        tmpstr++;
    }
    len = tmpstr - curstr;
    purl->path = malloc(len + 1);
    if ( NULL == purl->path ) {
        parsed_url_free(purl);
        return NULL;
    }
    libc_strncpy(purl->path, curstr, len);
    purl->path[len] = '\0';
    curstr = tmpstr;


    if ( '?' == *curstr ) {

        curstr++;

        tmpstr = curstr;
        while ( '\0' != *tmpstr && '#' != *tmpstr ) {
            tmpstr++;
        }
        len = tmpstr - curstr;
        purl->query = malloc(len + 1);
        if ( NULL == purl->query ) {
           parsed_url_free(purl);
            return NULL;
        }
        libc_strncpy(purl->query, curstr, len);
        purl->query[len] = '\0';
        curstr = tmpstr;
    }

    
    if ( '#' == *curstr ) {

        curstr++;

        tmpstr = curstr;
        while ( '\0' != *tmpstr ) {
            tmpstr++;
        }
        len = tmpstr - curstr;
        purl->fragment = malloc(len + 1);
        if ( NULL == purl->fragment ) {
            parsed_url_free(purl);
            return NULL;
        }
        libc_strncpy(purl->fragment, curstr, len);
        purl->fragment[len] = '\0';
        curstr = tmpstr;
    }

    return purl;
}

///---------------------------------------------------------------------
void** libc_memcat(void **arg1, void **arg2, size_t co){
	int a=libc_count(arg1),b=0;
	while(co>b){arg1[a]=arg2[b];b++;a++;}
return arg1;	
	}



void** __array_merge(void* buff,void* p,...){
va_list arg;
va_start(arg,p);
while(p!=NULL){
libc_memcat(buff, p, libc_count((void**)p));
p=va_arg(arg,void*);
}
va_end(arg);	
return (void**)buff;	
											}


#define array_merge(x,y...) (__array_merge((void*)x,(void*)y,NULL))
///---------------------------------------------------------------------
