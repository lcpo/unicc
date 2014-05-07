#include "set_name_var.c"


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





