
#define INT_MAX_LEN 12*2
#define UINT_MAX_LEN 12*2
#define LONG_MAX_LEN 22*2
#define LONG_LONG_MAX_LEN 22*2
#define ULONG_LONG_MAX_LEN 22*2
#define ULONG_MAX_LEN 22*2

#define clear_var($_0_v)({typeof($_0_v) $_0_o=(typeof($_0_v))NULL;$_0_o;})

typedef struct { 
   unsigned char data[64]; 
   unsigned int datalen; 
   unsigned int bitlen[2]; 
   unsigned int state[4]; 
} MD5_CTX; 

struct timespec {
  long tv_sec;
  long tv_nsec;
};

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
char char_table_base64[] = {
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R',
	'S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j',
	'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1',
	'2','3','4','5','6','7','8','9','+','/'
	};
#include "ctype.c"
///symbol
#define isalnum(c) libc_isalnum(c) //
#define isalpha(c) libc_isalpha(c)
#define iscntrl(c) libc_iscntrl(c)		//управляющий символ
#define isdigit(c) libc_isdigit(c)	 	//десятичная цифра
#define isgraph(c) libc_isgraph(c)		//печатаемый символ кроме пробела
#define islower(c) libc_islower(c) 		//буква нижнего регистра
#define isprint(c) libc_isprint(c)		//печатаемый символ, включая пробел
#define ispunct(c) libc_ispunct(c)		//печатаемый символ кроме пробела, буквы или цифры
#define isspace(c) libc_isspace(c) 		//пробел, смена страницы, новая строка, возврат каретки, табуляция, вертикальная табуляция
#define isupper(c) libc_isupper(c) 		//буква верхнего регистра
#define isxdigit(c) libc_isxdigit(c)	//шестнадцатеричная цифра
#define toupper(c) libc_toupper(c) 		//переводит букву на нижний регистр
#define tolower(c) libc_tolower(c) 		//переводит c на верхний регистр.




///memory
#define malloc libc_malloc
#define free libc_free
#define realloc libc_realloc
#include "string.c"
///string
#define strcpy(s,ct) libc_strcpy(s,ct) 			//копирует строку ct в строку s, включая '\0'; возвращает s
#define strncpy(s,ct,n) libc_strncpy(s,ct,n) 	//копирует не более n символов строки ct в s; возвращает s. Дополняет результат символами '\0', если символов в ct меньше n
#define strcat(s,ct) libc_strcat(s,ct) 			//приписывает ct к s; возвращает s
#define strncat(s,ct,n) libc_strncat(s,ct,n) 	//приписывает не более n символов ct к s, завершая s символом '\0'; возвращает s
#define strcmp(cs,st) libc_strcmp(cs,st)		//сравнивает cs и ct; возвращает <0, если cs<ct; 0, если cs==ct; и >0, если cs>ct 
#define strncmp(cs,ct,n) libc_strncmp(cs,ct,n)	//сравнивает не более n символов cs и ct; возвращает <0, если cs<ct, 0, если cs==ct, и >0, если cs>ct
#define strchr(cs,c) libc_strchr(cs,c)			//возвращает указатель на первое вхождение c в cs или, если такового не оказалось, NULL
#define strrchr(cs,c) libc_strrchr(cs,c)		//возвращает указатель на последнее вхождение c в cs или, если такового не оказалось, NULL
#define strspn(cs,ct) libc_strspn(cs,ct)		//возвращает длину начального сегмента cs, состоящего из символов, входящих в строку ct
#define strcspn(cs,ct) libc_strcspn(cs,ct)		//возвращает длину начального сегмента cs, состоящего из символов, не входящих в строку ct
#define strpbrk(cs,ct) libc_strpbrk(cs,ct)		//возвращает указатель в cs на первый символ, который совпал с одним из символов, входящих в ct, или, если такового не оказалось, NULL
#define strstr(cs, ct) libc_strstr(cs, ct)		//возвращает указатель на первое вхождение ct в cs или, если такового не оказалось, NULL
#define strlen(cs) libc_strlen(cs) 				//возвращает длину cs  
//strerror(n) //возвращает указатель на зависящую от реализации строку, соответствующую номеру ошибки n
#define strtok(s, ct) libc_strtok(s, ct) 		//strtok ищет в s лексему, ограниченную символами из ct;		
#define memcpy(s,ct, n) libc_memcpy(s,ct, n)		//копирует n символов из ct в s и возвращает s
#define memmove(s,ct,n) libc_memmove(s,ct,n)		//делает то же самое, что и memcpy, но работает и в случае "перекрывающихся" объектов.
#define memcmp(cs, ct, n) libc_memcmp(cs, ct, n) 	//сравнивает первые n символов cs и ct; выдает тот же результат, что и функция strcmp
#define memchr(cs, c, n) libc_memchr(cs, c, n) 		//возвращает указатель на первое вхождение символа c в cs или, если среди первых n символов c не встретилось, NULL
#define memset(s, c, n) libc_memset(s, c, n) 		//размещает символ c в первых n позициях строки s и возвращает s


/*необходима ревизия и проверка дублирования*/
#define libc_lens libc_strlen
//libc_strnpos
//libc_strpos
//libc_count
//substr_count
//libc_sch 
//libc_scmp
//libc_utos
//libc_is_dec_num
//libc_is_hex_num
//libc_leni
//libc_lenul
//libc_lend
//libc_lenf
//libc_lenld
//libc_ltoi
//libc_lltol
//libc_ulltol
//libc_dtos
//libc_ldtos
//libc_ftos
//libc_itos
//libc_uitos
//libc_ltos
//libc_lltos
//libc_ulltos
//libc_ultos
//libc_stod
//libc_stold
//libc_stof
//libc_stoui
//libc_stoi
//libc_stoul
//libc_stol
//libc_stoll
//libc_stoull
//libc_odd
//libc_sch_count


//libc_print_str
//libc_strpstr_nomo
//libc_explode
//libc_implode
//libc_join
//libc_strnstr
//libc_strpstr
//libc_compare
//libc_array_search
//libc_in_array
//libc_array_unique
//libc_array_unique_sort
//libc_file_exists
//libc_filesize
//libc_file_get_contents
//libc_file_put_contents
//libc_rand
//libc_string_replace
//libc_strtoupper
//libc_strtolower
//libc_strcmpi
//libc_strncmpi
//libc_stristr
//libc_string_ireplace
//libc_stripos
//libc_dirname
//libc_fopen
//libc_end
//fclose
//array
//libc_sleep
//libc_from_hex
//libc_to_hex
//libc_urlencode
//libc_urldecode
//libc_strnlen
//libc_strndup
//libc_substr
//libc_addslashes
//libc_stripslashes
//libc_array_replace
//libc_preg_print_error
//libc_preg_match
//libc_preg_match_all
//libc_base64_encode
//libc_base64_decode
//libc_md5


//libc_ltrim
//libc_rtrim
//libc_trim
/*конец*/







