#define travel3(str,oc,c,nc)({c=*str;str--;oc=*str;str++;str++;nc=*str;str--;}) 
#define travel5(str,ooc,oc,c,nc,nnc)({c=*str;str--;str--;ooc=*str;str++;str++;str--;oc=*str;str++;str++;nc=*str;str--;str++;str++;nc=*str;str--;str--;})

typedef enum {false,true}bool;
typedef enum {V_NULL,V_CHAR,V_POINT,VS_CLASS,V_GROUP}vect_type;


typedef struct s_vect{
char* c;	
uni* pos;
vect_type* tp;
vect_type* otp;
size_t length;
						}s_vect;

///---------------------------------------------------------------------
typedef struct ch_tab{
int rep;
char** table_src;
char** table;
int* flag_denial;
size_t table_count;
size_t length;
char tag_start;
char tag_end;
	}ch_tab;
