///------------------------------------------------------------
#define travel3(str,oc,c,nc)({c=*str;str--;oc=*str;str++;str++;nc=*str;str--;}) 
#define travel5(str,ooc,oc,c,nc,nnc)({c=*str;str--;str--;ooc=*str;str++;str++;str--;oc=*str;str++;str++;nc=*str;str--;str++;str++;nc=*str;str--;str--;})
///------------------------------------------------------------
typedef enum {false,true}bool;
typedef enum {V_NULL,V_CHAR,V_POINT,V_CLASS,V_STEP,V_GROUP}vect_type;
///------------------------------------------------------------
const char break_symbols[]={1,2,3};
///------------------------------------------------------------
typedef struct s_vect{
char* c;	
uni* pos;
vect_type* tp;
vect_type* otp;
size_t length;
						}s_vect;

///------------------------------------------------------------
typedef struct ch_tab{
char** table; 	          		//char table
char** pos; 	  				//pos to src str
uni* copos;
unsigned char* flag_denial;   //denial 
uni length;
						}ch_tab;
///------------------------------------------------------------
typedef struct ch_stp{
uni* min;
uni* max;
uni length;
						}ch_stp;
///------------------------------------------------------------
#define  i_flag_end(flag,x)(flag==0)?x++:x--;
#define  i_flag_end_rev(flag,x)(flag==0)?x--:x++;
///------------------------------------------------------------
bool is_i_flag(int flag,int i,int max){
max--;
if(flag==1){
	if(i>0){return true;}else{return false;}
	}else{
	if(i>max){return false;}else{return true;}	
		}	
	}
