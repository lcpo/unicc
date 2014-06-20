#define l_fgets(__str,__cou,__f)({int __n;if(atoi(__cou)>=2){__n=atoi(__cou);}else{__n=2;}fgets(__str,__n,__f);})

long int fsize(FILE* fp){
fseek(fp,0,SEEK_END);  
long int size =ftell(fp);  
fseek(fp,0,SEEK_SET);
return size;	
	}
//----------------------------------------------------------------------
char* file_get_contents(char* f){
FILE *fp;
int i=0;
fp = fopen(f,"r");
if(fp==0){printf("file = %s is not found \n",f);exit;}
long int size=fsize(fp);
char str[size];
char buff[STRING_MAX];
strcpy(buff,"\0");
while(fgets(str,size, fp)!=NULL){strcat(buff,str);i++;}
fseek(fp,0,SEEK_SET);
char* out;
out=buff;
fclose(fp);
return out;
	}	
//----------------------------------------------------------------------
char* fccount(char* f, char* c){
FILE* fp;long int i=0;char ch;
fp=fopen(f,"r");
 while((ch=fgetc(fp)) != EOF) {if(atoi_c(c)==ch){i++;}}
fclose(fp); 	
 return ltoa(i);
	}
