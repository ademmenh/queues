
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






void funcstringQueueInit (stringQueue *pQueue)
{
    pQueue->H = NULL;
    pQueue->T = NULL;
}

bool funcstringQueueEmpty (stringQueue Queue)
{
    if ( Queue.H==NULL )       // Queue.H==NULL && Queue.T==NULL
    {
        return true;
    }
    else
    {
        return false;
    }
}
