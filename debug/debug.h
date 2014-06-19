
#ifdef __NO_DEBUG
#define assert(__ex)
#else
#define assert(__ex) (void)((__ex) || (__assert ((char*)#__ex, (int)__LINE__,(char*)__FILE__),0))
#endif
