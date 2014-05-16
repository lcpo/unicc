#ifndef no_var_name


//----------------------------------------------------------------------

inline char* get_name(uni* addr) {
    uni i=0;
    uni pl=-1;
    uni* pr=addr;
    while (i<var_$l) {
        if (pr==var_$[i]) {
            pl=i;
            }
        ++i;
        }
    if (pl!=-1) {
        return var_$n[pl];
        }
    else {
        return NULL;
        }
    }


inline uni get_nom(char* name) {
    uni i=0;
    uni pl=-1;
    while (i<var_$l) {
        if (hiddenScmp(name,var_$n[i])==2) {
            pl=i;
            }
        ++i;
        }
    if (pl!=-1) {
        return (uni)*var_$[pl];
        }
    else {
        return -1;
        }
    }



char* amkey(char* str,int pos) {
    char* bf=__mem_amkey;
    char* bf2=bf;
    int ei=0;
    char* nstr=str+pos;
    while ((bf[ei] = nstr[ei])!=']') {
        ei++;
        }
    bf[ei]='\0';
    while (bf[ei]!='[') {
        ei--;
        }
    ei++;
    return bf2+ei;
    }
//----------------------------------------------------------------------

char* _a_name(char* str) { //Необходима срочная оптимизация
    int nom=0,mv=0,lp=0;
    char* name=__mem_array_name;
    while (str[nom]!=0) {
        if (str[nom]=='[') {
            mv=1;
            }
        if (mv==0) {
            name[lp]=str[nom];
            lp++;
            }
        nom++;
        }
    return name;
    }
//----------------------------------------------------------------------


char* attr(char* str) { //Необходима срочная оптимизация
    if (!hiddenSch(str,'[')) {
        return str;
        }
    char* name=_a_name(str);

    uni sn=0, pos=0, subn=1, i=hiddenStrlen(name);
    char* bf;
    char* out= __mem_attr;
    if (hiddenStrstr(str,"][")) {
        subn=hiddenSubstr_count(str,"][");
        }
    while (subn) {
        bf=amkey(str,pos);
        if (hiddenIs_num(bf)==0) {
            str=hiddenString_replace(str,bf,hiddenUtos(get_nom(bf)));
            }
        if (hiddenStrstr(str,"][")) {
            pos=pos+hiddenStrnpos(str,"][",pos)+1;
            bf=amkey(str,pos);
            if (hiddenIs_num(bf)==0) {
                str=hiddenString_replace(str,bf,hiddenUtos(get_nom(bf)));
                }
            }
        subn--;
        }
    if (hiddenStrstr(str,"]]")) {
        sn=0;
        str=str+hiddenStrnpos(str,"[",0);
        while (var_$n[sn]!=0) {
            if (hiddenSch(var_$n[sn],'[')) {
                str=hiddenString_replace(str,var_$n[sn],hiddenUtos((uni)*var_$[sn]));
                }
            sn++;
            }
        out=name;
        while ((out[i] = str[i])!='\0') {
            i++;
            }
        }
    else {
        out=str;
        }
    return out;
    }
#endif
///---------------------------------------------------------------------

//----------------------------------------------------------------------
uni get_var_id(uni* addr) {
    uni i=0;
    uni pl=-1;
    while (i<var_$l) {
        if (addr==var_$[i]) {
            pl=i;
            }
        ++i;
        }
    if (pl!=-1) {
        return pl;
        }
    else {
        return -1;
        }
    }
//----------------------------------------------------------------------
char* get_var_type(uni* addr) {
    uni i=0;
    uni pl=-1;
    while (i<var_$l) {
        if (addr==var_$[i]) {
            pl=i;
            }
        ++i;
        }
    if (pl!=-1) {
        return type_$t[var_$t[pl]];
        }
    else {
        return NULL;
        }
    }

//----------------------------------------------------------------------
uni set_var_item(uni* addr, char* type, char* name, uni _fu) {
    if(type_$l<1) {
        init_type();
        }
    uni _var=set_type_item(type);
    void** naddr=(void*)*addr;
    if (hiddenSch(type,'*')>0 && get_var_id(addr)==-1) {
        naddr=malloc(sizeof(naddr));
        if (naddr == 0) {
           // exit(1);
           return 0;
            }
        }
    if (var_$l==0) {
        var_$=malloc(sizeof(var_$));
        var_$t=malloc(sizeof(var_$t));
        var_$f=malloc(sizeof(var_$f));
        var_$n=malloc(sizeof(var_$n));
        }

    uni ind=0,fl=0,t_id=-1;

    while (var_$l>ind) {
        if (var_$[ind]==addr) {
            fl=1;
            t_id=ind;
            }
        ind++;
        }

    if (fl==0) {
        if (var_$l>0) {
            var_$n=realloc(var_$n,hiddenCount((void**)var_$n)*($_MEM_STEP));
            var_$=realloc(var_$,hiddenCount((void**)var_$)*($_MEM_STEP));
            var_$t=realloc(var_$t,hiddenCount((void**)var_$t)*($_MEM_STEP));
            var_$f=realloc(var_$f,hiddenCount((void**)var_$f)*($_MEM_STEP));
            }
        var_$[var_$l]=addr;
        var_$t[var_$l]=_var;
        var_$f[var_$l]=_fu;
        name=attr(name);
        var_$n[var_$l]=malloc(hiddenStrlen(name)*($_MEM_STEP));
        var_$n[var_$l]=name;
        var_$l++;
        }
//rti(lc,0);
    return (uni)naddr;
    }
//----------------------------------------------------------------------
void set_val(uni* addr,char* value, char* type){
if (hiddenSch(type,'*')>1){
addr=realloc(addr,hiddenCount((void**)addr)*($_MEM_STEP));
						}
return;	
	}
//----------------------------------------------------------------------


void rti(uni pl, int flag){
uni i; uni lc=var_$l;
uni min; uni* addr; 
uni id; uni nom;
uni con=0; uni t_var; uni f_var;
char * name;
for (i=0; i < lc; i++){min = i; uni j; 
for (j=i; j < lc; j++){if (var_$n[j]>var_$n[min] && var_$n[j]>0){ min = j;}}

addr = var_$[i];	 var_$[i]=var_$[min];   var_$[min]=addr;
name = var_$n[i]; 	 var_$n[i]=var_$n[min]; var_$n[min]=name;

t_var= var_$t[i]; 	 var_$t[i]=var_$t[min]; var_$t[min]=t_var;
f_var= var_$f[i]; 	 var_$f[i]=var_$f[min]; var_$f[min]=f_var;
if(var_$[i]==(uni*)-1){con++;}
						}//цикл сортировки
	if(flag==-1){var_$l=lc-con;}
	}
//----------------------------------------------------------------------


void dell_var_item(uni id){
//char* type=;
if (hiddenSch(get_var_type((uni*)var_$[id]),'*')>1){
//free(var_$[id]);
var_$n[id]="";
var_$t[id]=-1;
var_$f[id]=-1;
var_$t[id]=-1;
}else{
var_$[id]=(uni*)-1;	
var_$n[id]="";
var_$t[id]=-1;
var_$f[id]=-1;
}

if(id!=-1){rti(id,-1);}
return;
}



//----------------------------------------------------------------------
