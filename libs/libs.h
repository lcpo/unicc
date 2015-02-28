#include "constructor.h"
#ifdef __i386__
#include "unistd_x86.h"
#endif

#ifdef __x86_64__
#include "unistd_x64.h"
#endif
#include "type.h"
#include "arg.h"
#include "call.h"
