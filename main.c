#include "unicc.c"


/*
func* te(){
void test1(void){printf("1\n");}
void test2(void){printf("2\n");}
void test3(void){printf("3\n");}
return obj(test1,test2,test3);
	} 
func* re;
re=te();
func test1=re[0];
func test2=re[1];
func test3=re[2];
test1(0);
test2(0);
test3(0);
*/

//$_tp=(typeof($_tp))libc_malloc(sizeof(typeof($_tp)));\








	
int main(int argc, char **argv) {

printf("%s\n",libc_substr("abcdef", 1,   -1));    // bcdef
printf("%s\n",libc_substr("abcdef", 1,   3));     // bcd
printf("%s\n",libc_substr("abcdef", 0,   4));     // abcd
printf("%s\n",libc_substr("abcdef", 0,  -1));     // abcdef
printf("%s\n",libc_substr("abcdef", 5,   1));     // f
/*
echo substr('abcdef', 1);     // bcdef
echo substr('abcdef', 1, 3);  // bcd
echo substr('abcdef', 0, 4);  // abcd
echo substr('abcdef', 0, 8);  // abcdef
echo substr('abcdef', -1, 1); // f
*/

exit(0);




return 0;
						}





