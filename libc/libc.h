
#define INT_MAX_LEN 12*2
#define UINT_MAX_LEN 12*2
#define LONG_MAX_LEN 22*2
#define LONG_LONG_MAX_LEN 22*2
#define ULONG_LONG_MAX_LEN 22*2
#define ULONG_MAX_LEN 22*2
#define clear_fun($_0_x)({typeof($_0_x) $_0_o=(typeof($_0_x))fun_null;$_0_o;})
#define clear_var($_0_v)({typeof($_0_v) $_0_o=(typeof($_0_v))NULL;$_0_o;})


static char out_Hstr_rep[64];
static char _Hslong[48];
char out_$_dtos[32];
char out_$_ldtos[32];
char out_$_ftos[32];
char _$_sint[INT_MAX_LEN];
char _$_suint[UINT_MAX_LEN];
char _$_slong[LONG_MAX_LEN];
char _$_sllong[LONG_LONG_MAX_LEN];
char _$_sullong[ULONG_LONG_MAX_LEN];
char _$_sulong[ULONG_MAX_LEN];



	
extern void *libc_memchr( void *s, int c, size_t n);
extern int libc_memcmp( void *s1,  void *s2, size_t n);
extern void *libc_memcpy (void *dest, void *src, size n);
extern void *libc_memset(void *s, int c, size n);
extern char* libc_strcat ( char* des, char* so );
extern char * libc_strcpy(char *to, const char *from);
extern size libc_strlen(char *str);
extern char* libc_strncat(char* dst, const char * src, size n);
extern int libc_strncmp(const char* s1, const char* s2, size num);
extern char * libc_strstr(char *string, char *substring);
extern void libc_free(void *ptr);
extern uni libc_strpos(char *haystack, char *needle);
extern void *libc_malloc(size __size);
extern size libc_count(void** v);
extern void *libc_realloc(void *ptr, size __size);
extern uni	libc_sch(char* str, char ch);
extern int libc_scmp(char* str1, char* str2);
extern uni libc_strnpos(char* str, char* sub, int ot);
extern long libc_substr_count(char* str_s, char* sub_s);
extern char* libc_string_replace(char *string, char *delimiter, char *replacement);
extern char* libc_utos(uni n); 
extern int libc_is_dec_num(char* str);
extern void libc_fun_null(void);
extern uni libc_leni(long long num);
extern uni libc_lenul(unsigned long long num);
extern uni libc_lens(char* v);
extern uni libc_lend(double num);
extern uni libc_lenf(float num);
extern uni libc_lenld(long double num);
extern int libc_ltoi(long long n);
extern long libc_lltol(long long n);
extern long libc_ulltol(unsigned long long n);
extern char* libc_dtos(double n);
extern char* libc_ldtos(long double n);
extern char* libc_ftos(float n);
extern char* libc_itos(int n);
extern char* libc_ltos(long int n);
extern char* libc_lltos(long long int n);
extern char* libc_ulltos(unsigned long long int n);
extern char* libc_ultos(unsigned long int n);
extern double libc_stod(char* s);
extern long double libc_stold(char* s);
extern float libc_stof(char* s);
extern unsigned int libc_stoui(char* s);
extern int libc_stoi(char* s);
extern unsigned long libc_stoul(char* s);
extern long libc_stol(char* s);
extern long long libc_stoll(char* s);
extern unsigned long long libc_stoull(char* s);
extern void *libc_mcat(void *dst, void *src);
extern void *libc_mcpy(void *dst, void *src, size len);
extern void *libc_mncat(void *dst, void *src, size len);
extern void *libc_mset(void *pt, int c, size n);
extern void *libc_msetn(void *pt, int c, size n);
extern int libc_odd(uni value);
extern uni libc_sch_count(char* str, int ch);
extern char* libc_scpy(char *destaddr, char *srcaddr, uni len);
extern void *libc_set(void *ptr, int ch);
extern uni libc_print_str(char * buf);





