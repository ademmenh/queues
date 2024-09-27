

#ifndef _floatQUEUE_C
    #define _floatQUEUE_C
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

#ifndef _floatDLIST_C
    #include "floatDList.c"
#endif





typedef struct floatQueue
{
    floatDNode *H;
    floatDNode *T;
} floatQueue;

