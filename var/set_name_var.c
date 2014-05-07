#ifndef no_var_name

char __mem_amkey[MAX_ARG]; //Темповая переменная
char __mem_array_name[MAX_ARG]; //Темповая переменная
char __mem_attr[MAX_ARG]; //Темповая переменная
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

