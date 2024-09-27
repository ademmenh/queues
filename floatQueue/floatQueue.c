

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






void funcfloatQueueInit (floatQueue *pQueue)
{
    pQueue->H = NULL;
    pQueue->T = NULL;
}

void funcfloatQueueEnqueue (floatQueue *pQueue, float value)
{
    
    floatDNode *vpNew, *vpTemp;

    if ( pQueue->H==NULL )
    {
        vpNew = funcfloatDNodeCreate (value);
        pQueue->H = vpNew;
        pQueue->T = vpNew;
    }
    else
    {
        vpTemp = pQueue->T;
        pQueue->T = funcfloatDNodeCreate (value);

        pQueue->T->Previous = vpTemp;
        vpTemp->Next = pQueue->T;

    }
}

void funcfloatQueueDequeue (floatQueue *pQueue, float *pholder)
{
    floatDNode *vpTemp;

    if ( pQueue->H==pQueue->T )
    {
        funcfloatDNodeFree (pQueue->H);
        pQueue->H = NULL;
        pQueue->T = NULL;
    }
    else
    {
        vpTemp = pQueue->H;
        pQueue->H = pQueue->H->Next;

        (*pholder) = vpTemp->Value;
        funcfloatDNodeFree (vpTemp);
    }
}

void funcfloatQueueFront (floatQueue Queue, float *pholder)
{

    if ( Queue.H==NULL )
    {
        printf ("the queue is empty !");
        exit (1);
    }

    (*pholder) = (Queue.H)->Value;
}

void funcfloatQueueBack (floatQueue Queue, float *pholder)
{

    if ( Queue.H==NULL )
    {
        printf ("the queue is empty !");
        exit (1);
    }

    (*pholder) = (Queue.T)->Value;
}

bool funcfloatQueueEmpty (floatQueue Queue)
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




void funcfloatQueueCreate (floatQueue *pQueue, int stackSize)
{

    int vfInput;
    int viCn;
    for ( viCn=0; viCn<stackSize; viCn++ )
    {
        vfInput = funcfloatInput();
        funcfloatQueueEnqueue (pQueue, vfInput);
    }
}

void funcfloatQueueDisplay (floatQueue Queue)
{
    floatDNode *vpCn;
    int viCn;


    if ( funcfloatQueueEmpty(Queue) )
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
