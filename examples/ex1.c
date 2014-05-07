#include "../unic.c"
#include "../debug.c"

obj newClass() {


    uni pp(uni a) { a++;    return a; }



    uni mm(uni a) {
        
        a--;
        
        return a;
        }

        

    uni sl(uni x, uni y) {
        return (x+y);
        
        }
        
    uni vi(uni x, uni y) {
        return (x-y);
        
        }

    uni test(uni i,char* str) {

        printf("i=%li\n",(long)i);
        printf("str=%s\n",str);
        return 0;
        
        }

    void my_print(uni* args) {
        int i=0;
        while(args[i]!=0) {
            printf("%s\n",(char*)args[i]);
            i++;
            }
        }

    return obj(
               set_fun(pp,uni,newClass,1),
               set_fun(mm,uni,newClass,1),
               set_fun(sl,uni,newClass,2),
               set_fun(vi,uni,newClass,2),
               set_fun(test,uni,newClass,2),
               set_fun(my_print,void,newClass,-1)
           );

    }
int main(int argc, char **argv) {    
	set_fun(main,int,main,2);
new(newClass,obj,0);
proto(my_print,old_print);
proto(old_print,my_print);
unset_fun("newClass");
  fun(uni,test,i,"test\n");    
    
    proc(void*,my_print,"prosto","test","teest",t);
    proc(void*,old_print,"abc","def","gik");
return 0;
}    
