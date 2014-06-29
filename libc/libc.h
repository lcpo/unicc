
#define INT_MAX_LEN 12*2
#define UINT_MAX_LEN 12*2
#define LONG_MAX_LEN 22*2
#define LONG_LONG_MAX_LEN 22*2
#define ULONG_LONG_MAX_LEN 22*2
#define ULONG_MAX_LEN 22*2
#define clear_fun($_0_x)({typeof($_0_x) $_0_o=(typeof($_0_x))fun_null;$_0_o;})
#define clear_var($_0_v)({typeof($_0_v) $_0_o=(typeof($_0_v))NULL;$_0_o;})



char _Hslong[48];
char out_$_dtos[32];
char out_$_ldtos[32];
char out_$_ftos[32];
char _$_sint[INT_MAX_LEN];
char _$_suint[UINT_MAX_LEN];
char _$_slong[LONG_MAX_LEN];
char _$_sllong[LONG_LONG_MAX_LEN];
char _$_sullong[ULONG_LONG_MAX_LEN];
char _$_sulong[ULONG_MAX_LEN];


	
 void *libc_memchr( void *s, int c, size_t n);
 int libc_memcmp( void *s1,  void *s2, size_t n);
 void *libc_memcpy (void *dest, void *src, size n);
 void *libc_memset(void *s, int c, size n);
 char* libc_strcat ( char* des, const char* so );
 char * libc_strcpy(char *to, const char *from);
 size_t libc_strlen(char *str);
 char* libc_strncat(char* dst, const char * src, size_t n);
 int libc_strncmp(char* s1, char* s2, size_t num);
 char * libc_strstr(char *string, char *substring);
 void libc_free(void *ptr);
 uni libc_strpos(char *haystack, char *needle);
 void *libc_malloc(size __size);
 size_t libc_count(void** v);
 void *libc_realloc(void *ptr, size __size);
 uni	libc_sch(char* str, char ch);
 int libc_scmp(char* str1, char* str2);
 uni libc_strnpos(char* str, char* sub, int ot);
 long libc_substr_count(char* str_s, char* sub_s);
 char* libc_string_replace(char *string, char *delimiter, char *replacement);
 char* libc_utos(uni n); 
 int libc_is_dec_num(char* str);
 void libc_fun_null(void);
 uni libc_leni(long long num);
 uni libc_lenul(unsigned long long num);
 uni libc_lens(char* v);
 uni libc_lend(double num);
 uni libc_lenf(float num);
 uni libc_lenld(long double num);
 int libc_ltoi(long long n);
 long libc_lltol(long long n);
 long libc_ulltol(unsigned long long n);
 char* libc_dtos(double n);
 char* libc_ldtos(long double n);
 char* libc_ftos(float n);
 char* libc_itos(int n);
 char* libc_ltos(long int n);
 char* libc_lltos(long long int n);
 char* libc_ulltos(unsigned long long int n);
 char* libc_ultos(unsigned long int n);
 double libc_stod(char* s);
 long double libc_stold(char* s);
 float libc_stof(char* s);
 unsigned int libc_stoui(char* s);
 int libc_stoi(char* s);
 unsigned long libc_stoul(char* s);
 long libc_stol(char* s);
 long long libc_stoll(char* s);
 unsigned long long libc_stoull(char* s);
 void *libc_mcat(void *dst, void *src);
 void *libc_mcpy(void *dst, void *src, size len);
 void *libc_mncat(void *dst, void *src, size len);
 void *libc_mset(void *pt, int c, size n);
 void *libc_msetn(void *pt, int c, size n);
 int libc_odd(uni value);
 uni libc_sch_count(char* str, int ch);
 char* libc_scpy(char *destaddr, char *srcaddr, uni len);
 void *libc_set(void *ptr, int ch);
 uni libc_print_str(char * buf);




