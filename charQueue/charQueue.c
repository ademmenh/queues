
#ifndef _charQUEUE_C
    #define _charQUEUE_C
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

#ifndef _charDLIST_C
    #include "charDList.c"
#endif





typedef struct charQueue
{
    charDNode *H;
    charDNode *T;
} charQueue;




void funccharQueueInit (charQueue *pQueue)
{
    pQueue->H = NULL;
    pQueue->T = NULL;
}


bool funccharQueueEmpty (charQueue Queue)
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
