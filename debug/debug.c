///---------------------------------------------------------------------
///Отладка
///---------------------------------------------------------------------
void print_fun(void) {
    int i=0;
    printf("regs fun:\n");
    while(i<fun_$l) {
        printf("%i\t| $=%l\t|$n= %s | \t$o=%s |\t $p=%l|\t $a=%l|\t $i:",i,(long)fun_$[i],fun_$n[i],type_$t[fun_$o[i]],(long)fun_$p[i],(long)fun_$a[i]);
    int n=0;
    while(fun_$i[i][n]!=0){printf("%l(%s), ",(long)n,(char*)fun_$i[i][n]);n++;}    
        i++;
        printf("\n");
        }
        
    }
//----------------------------------------------------------------------
 void print_var() {
    int i=0;

    printf("regs var:\n");

    while (var_$l>i) {
        printf("i=%d \t| $ =%l \t\t| $t =%s\t| $f =%l \t |",i,(long)var_$[i],type_$t[var_$t[i]],(long)var_$f[i]);
        printf("$n =%s\t| ",var_$n[i]);
        printf("\n");
        i++;
        }
    return;
    }
//----------------------------------------------------------------------
int print_reg_type(void) {
    int i=0;
    printf("regs type:\n");
    while (type_$l>i) {
        printf("i = %d | t=%s | z=%l\n",i,type_$t[i],(long)type_$z);
        i++;
        }
    return 1;
    }
//----------------------------------------------------------------------
