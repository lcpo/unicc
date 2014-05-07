

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
if (hiddenSch(get_var_type((uni*)var_$[id]),'*')>1){
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
