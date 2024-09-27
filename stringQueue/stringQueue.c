
#ifndef _stringQUEUE_C
    #define _stringQUEUE_C
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

#ifndef _stringDLIST_C
    #include "stringDList.c"
#endif





typedef struct stringQueue
{
    stringDNode *H;
    stringDNode *T;
} stringQueue;





