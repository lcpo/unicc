#include "../unic.c"
#include "../debug.c"
//----------------------------------------------------------------------
int main(int argc, char **argv) {
	set_fun(main,int,main,2);
	char* t=var(t,char*,main);
	char** r=var(r,char**,main);
	int i=var(i,int,main);
i=0;

while(i<9999){
r[i]=var(r[i],char*,main);
i++;}

i=0;
while(i<9999){
r[i]=val(r[i],tos(i));
pub(r[i]);
pub("\n");
//delete(r[i]);

	i++;}

   print_var();
 return 0;
   }
