
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

void funccharQueueEnqueue (charQueue *pQueue, int value)
{
    
    charDNode *vpNew, *vpTemp;

    if ( pQueue->H==NULL )
    {
        vpNew = funccharDNodeCreate (value);
        pQueue->H = vpNew;
        pQueue->T = vpNew;
    }
    else
    {
        vpTemp = pQueue->T;
        pQueue->T = funccharDNodeCreate (value);

        pQueue->T->Previous = vpTemp;
        vpTemp->Next = pQueue->T;

    }
}

void funccharQueueDequeue (charQueue *pQueue, int *pholder)
{
    charDNode *vpTemp;

    if ( pQueue->H==pQueue->T )
    {
        funccharDNodeFree (pQueue->H);
        pQueue->H = NULL;
        pQueue->T = NULL;
    }
    else
    {
        vpTemp = pQueue->H;
        pQueue->H = pQueue->H->Next;

        (*pholder) = vpTemp->Value;
        funccharDNodeFree (vpTemp);
    }
}

void funccharQueueFront (charQueue Queue, int *pholder)
{

    if ( Queue.H==NULL )
    {
        printf ("the queue is empty !");
        exit (1);
    }

    (*pholder) = (Queue.H)->Value;
}

void funccharQueueBack (charQueue Queue, int *pholder)
{

    if ( Queue.H==NULL )
    {
        printf ("the queue is empty !");
        exit (1);
    }

    (*pholder) = (Queue.T)->Value;
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


void funccharQueueCreate (charQueue *pQueue, int stackSize)
{

    int vcInput;
    int viCn;
    for ( viCn=0; viCn<stackSize; viCn++ )
    {
        vcInput = funccharInput();
        funccharQueueEnqueue (pQueue, vcInput);
    }
}

void funccharQueueDisplay (charQueue Queue)
{
    charDNode *vpCn;
    int viCn;


    if ( funccharQueueEmpty(Queue) )
    {
        printf ("The Queue is Empty!");
        return;
    }


    vpCn = Queue.H;
    viCn = 0;
    while ( vpCn!=NULL )
    {
        printf ("The value n %d is: %c.\n", viCn, vpCn->Value);
        viCn++;
        vpCn = vpCn->Next;
    }

}
