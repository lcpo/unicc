
#include <gc/gc.h>
#define malloc(n) GC_malloc(n)
#define calloc(m,n) GC_malloc((m)+(n))
#define realloc(m,n) GC_realloc(m,n)
#define free(x) ((x)=NULL)
#define force_GC_on(x) GC_free(x)

#include "unic.h"
