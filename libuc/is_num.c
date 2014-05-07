#ifndef no_is_num

int is_num(char* str){
int i=0, pr=0;
while(str[i]!=0){
switch(str[i]){
case '-': pr++; break;
case '0': pr++; break;
case '1': pr++; break;
case '2': pr++; break;
case '3': pr++; break;
case '4': pr++; break;
case '5': pr++; break;
case '6': pr++; break;
case '7': pr++; break;
case '8': pr++; break;
case '9': pr++; break;
default :pr=-1; break;
			}
				i++;}
if(i==pr){return 1;}else{return 0;}
	}
#endif
