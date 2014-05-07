#ifndef no_scmp

int scmp(char* str1, char* str2){
uni si1=lens(str1); uni si2=lens(str2);
if(si1>si2){return 1;}
if(si1<si2){return -1;}
if(si1==si2){
uni i;
for(i=0;i<si1;i++){
if(str1[i]!=str2[i]){return 0;}
}
			}
return 2;
	}
#endif
