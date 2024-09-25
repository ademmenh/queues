
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




void funcintQueueInit (intQueue *pQueue)
{
    pQueue->H = NULL;
    pQueue->T = NULL;
}

void funcintQueueEnqueue (intQueue *pQueue, int value)
{
    
    intDNode *vpNew, *vpTemp;

    if ( pQueue->H==NULL )
    {
        vpNew = funcintDNodeCreate (value);
        pQueue->H = vpNew;
        pQueue->T = vpNew;
    }
    else
    {
        vpTemp = pQueue->T;
        pQueue->T = funcintDNodeCreate (value);

        pQueue->T->Previous = vpTemp;
        vpTemp->Next = pQueue->T;

    }
}

void funcintQueueDequeue (intQueue *pQueue, int *pholder)
{
    intDNode *vpTemp;

    if ( pQueue->H==pQueue->T )
    {
        funcintDNodeFree (pQueue->H);
        pQueue->H = NULL;
        pQueue->T = NULL;
    }
    else
    {
        vpTemp = pQueue->H;
        pQueue->H = pQueue->H->Next;

        (*pholder) = vpTemp->Value;
        funcintDNodeFree (vpTemp);
    }
}

void funcintQueueFront (intQueue Queue, int *pholder)
{

    if ( Queue.H==NULL )
    {
        printf ("the queue is empty !");
        exit (1);
    }

    (*pholder) = (Queue.H)->Value;
}

void funcintQueueBack (intQueue Queue, int *pholder)
{

    if ( Queue.H==NULL )
    {
        printf ("the queue is empty !");
        exit (1);
    }

    (*pholder) = (Queue.T)->Value;
}

bool funcintQueueEmpty (intQueue Queue)
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


