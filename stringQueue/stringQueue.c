
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

void funcstringQueueEnqueue (stringQueue *pQueue, string value)
{
    
    stringDNode *vpNew, *vpTemp;

    if ( pQueue->H==NULL )
    {
        vpNew = funcstringDNodeCreate (value);
        pQueue->H = vpNew;
        pQueue->T = vpNew;
    }
    else
    {
        vpTemp = pQueue->T;
        pQueue->T = funcstringDNodeCreate (value);

        pQueue->T->Previous = vpTemp;
        vpTemp->Next = pQueue->T;

    }
}

void funcstringQueueDequeue (stringQueue *pQueue, string *pholder)
{
    stringDNode *vpTemp;

    if ( pQueue->H==pQueue->T )
    {
        funcstringDNodeFree (pQueue->H);
        pQueue->H = NULL;
        pQueue->T = NULL;
    }
    else
    {
        vpTemp = pQueue->H;
        pQueue->H = pQueue->H->Next;

        (*pholder) = vpTemp->Value;
        funcstringDNodeFree (vpTemp);
    }
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
