#define php_strstr(h,n)({\
char* __o=strstr(tos(h),tos(n));\
if(__o==NULL){__o="(null)";}\
__o;})
