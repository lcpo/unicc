
//----------------------------------------------------------------------
/*
uni set_type_item(char* name) {
    uni ind=0, fl=0, t_id=-1;
    if (type_$l==0) {
        type_$t=libc_malloc(sizeof(type_$t)*libc_strlen(name)*($_MEM_STEP));
        type_$z=sizeof(char*);
        }
    while (type_$l>ind) {
        if (libc_scmp(type_$t[ind],name)==2) {
            fl=1;
            t_id=ind;
            }
            
        ind++;
        }

    if (fl==0) {
        if (type_$l>0) {
            type_$t=libc_realloc(type_$t,((libc_count((void**)type_$t))*($_MEM_STEP)));
            type_$z=((libc_count((void**)type_$t))*($_MEM_STEP));
            }
        type_$t[type_$l]=libc_malloc(((libc_strlen(name))*($_MEM_STEP)));
        type_$t[type_$l]=name;
        t_id=type_$l;
        type_$l++;

        }
    return t_id;
    }
*/
uni set_type_item(char* name) {
    uni ind=0, fl=0, t_id=-1;
    if (type_$l==0) {
        type_$t=malloc(sizeof(type_$t)*libc_strlen(name)*($_MEM_STEP));
        type_$z=sizeof(char*);
        }
    while (type_$l>ind) {
        if (libc_scmp(type_$t[ind],name)==2) {
            fl=1;
            t_id=ind;
            }
            
        ind++;
        }

    if (fl==0) {
        if (type_$l>0) {
            type_$t=realloc(type_$t,((libc_count((void**)type_$t))*($_MEM_STEP)));
            type_$z=((libc_count((void**)type_$t))*($_MEM_STEP));
            }
        type_$t[type_$l]=malloc(((libc_strlen(name))*($_MEM_STEP)));
        type_$t[type_$l]=name;
        t_id=type_$l;
        type_$l++;

        }
    return t_id;
    }
//----------------------------------------------------------------------
//assoc_type //Ассоциатор типов
//get_type //получает id по имени
//in_type проверяет на подобность передаваемый тип с существующими

//----------------------------------------------------------------------
void init_type(void) {
    set_type(void);                 //0
    set_type(void*);                //1
    set_type(char);                 //2
    set_type(char*);                //3
    set_type(int);                  //4
    set_type(long);                 //5
    set_type(float);                //6
    set_type(double);               //7
    set_type(short);                //8
    set_type(uni);                  //9
    set_type(size);                 //10
    set_type(wchar);                //11
   //-------------------------------------------
 
    set_type(signed char);          //12
    set_type(unsigned char);        //13
    set_type(short int);            //14
    set_type(signed short);         //15
    set_type(unsigned short);       //14
    set_type(unsigned short int);   //16
    set_type(signed);               //17
    set_type(signed int);           //18
    set_type(unsigned);             //19
    set_type(unsigned int);         //20
    set_type(signed long);          //21
    set_type(unsigned long);        //22
    set_type(long double);          //23
    set_type(signed char*);         //24
    set_type(unsigned char*);       //25
    set_type(long long);            //26
    set_type(size_t);               //27
    set_type(long long int);        //28

    set_type(unsigned long int);     //29
    set_type(unsigned long long int);//30
    set_type(signed long);           //31
    set_type(unsigned long);         //32

    set_type(signed long long);      //33
    set_type(unsigned long long);    //34
    set_type(signed long long int);  //35
    set_type(unsigned long long int);//36

    return;
    }
///Необходимо создании ассоциативной структуры для вмещения большего количества типов
