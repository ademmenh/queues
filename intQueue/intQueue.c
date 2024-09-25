
#ifndef _intQUEUE_C
    #define _intQUEUE_C
#endif

#ifndef _STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef _STDIO_H
    #include <stdio.h>
#endif

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif

#ifndef _intDLIT_C
    #include "intDList.c"
#endif





typedef struct intQueue
{
    intDNode *H;
    intDNode *T;
} intQueue;



