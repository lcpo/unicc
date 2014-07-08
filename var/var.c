#ifndef no_var_name


//----------------------------------------------------------------------

char* get_name(uni* addr) {
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


uni get_nom(char* name) {
    uni i=0;
    uni pl=-1;
    while (i<var_$l) {
        if (libc_scmp(name,var_$n[i])==2) {
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
    if (!libc_sch(str,'[')) {
        return str;
        }
    char* name=_a_name(str);

    uni sn=0, pos=0, subn=1, i=libc_strlen(name);
    char* bf;
    char* out= __mem_attr;
    if (libc_strstr(str,"][")) {
        subn=libc_substr_count(str,"][");
        }
    while (subn) {
        bf=amkey(str,pos);
        if (libc_is_dec_num(bf)==0) { 
            str=libc_string_replace(str,bf,libc_utos(get_nom(bf)));
            }
        if (libc_strstr(str,"][")) {
            pos=pos+libc_strnpos(str,"][",pos)+1;
            bf=amkey(str,pos);
            if (libc_is_dec_num(bf)==0) {
                str=libc_string_replace(str,bf,libc_utos(get_nom(bf)));
                }
            }
        subn--;
        }
    if (libc_strstr(str,"]]")) {
        sn=0;
        str=str+libc_strnpos(str,"[",0);
        while (var_$n[sn]!=0) {
            if (libc_sch(var_$n[sn],'[')) {
                str=libc_string_replace(str,var_$n[sn],libc_utos((uni)var_$[sn]));
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
char* get_var_type_by_name(char* name){
    uni i=0;
    uni pl=-1;
    while (i<var_$l) {
        if (libc_scmp(name,var_$n[i])==2) {
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
uni get_var_id_by_name(char* name){
    uni i=0;
    uni pl=-1;
    while (i<var_$l) {
        if (libc_scmp(name,var_$n[i])==2) {
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
char* get_var_type_by_id(int pl){
    if (pl!=-1) {
        return type_$t[var_$t[pl]];
        }else{
        return NULL;
        }	
	}
//----------------------------------------------------------------------
uni* get_var_adr_by_id(uni pl){
    if (pl!=-1) {
        return var_$[pl];
        }else{
        return (uni*)-1;
        }	
	}	
//----------------------------------------------------------------------
uni set_var_item(uni* addr, char* type, char* name, uni _fu) {
    if(type_$l<1) {
        init_type();
        }
    uni _var=set_type_item(type);
    void** naddr=(void*)*addr;
    if (libc_sch(type,'*')>0 && get_var_id(addr)==-1) {
        naddr=malloc(sizeof(naddr)*($_MEM_STEP));
        if (naddr == 0) {
           // exit(1);
           return 0;
            }
        }
    if (var_$l==0) {
        var_$=malloc(sizeof(var_$)*($_MEM_STEP));
        var_$t=malloc(sizeof(var_$t)*($_MEM_STEP));
        var_$f=malloc(sizeof(var_$f)*($_MEM_STEP));
        var_$n=malloc(sizeof(var_$n)*libc_strlen(name)*($_MEM_STEP));
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
            var_$n=realloc(var_$n,libc_count((void**)var_$n)*sizeof(var_$n)*($_MEM_STEP));
            var_$=realloc(var_$,libc_count((void**)var_$)*sizeof(var_$)*($_MEM_STEP));
            var_$t=realloc(var_$t,libc_count((void**)var_$t)*sizeof(var_$t)*($_MEM_STEP));
            var_$f=realloc(var_$f,libc_count((void**)var_$f)*sizeof(var_$f)*($_MEM_STEP));
            }
        var_$[var_$l]=addr;
        var_$t[var_$l]=_var;
        var_$f[var_$l]=_fu;
        name=attr(name);
        var_$n[var_$l]=malloc(libc_strlen(name)*sizeof(var_$n[var_$l])*($_MEM_STEP));
        var_$n[var_$l]=name;
        var_$l++;
        }
//rti(lc,0);
    return (uni)naddr;
    }
//----------------------------------------------------------------------
void set_val(uni* addr,char* value, char* type){
if (libc_sch(type,'*')>1){
addr=realloc(addr,libc_count((void**)addr)*($_MEM_STEP));
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
if (libc_sch(get_var_type((uni*)var_$[id]),'*')>1){
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
