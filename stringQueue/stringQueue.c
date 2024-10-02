
#define _stringQUEUE_C

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

void funcstringQueueFront (stringQueue Queue, string *pholder)
{

    if ( Queue.H==NULL )
    {
        printf ("the queue is empty !");
        exit (1);
    }

    (*pholder) = (Queue.H)->Value;
}

void funcstringQueueBack (stringQueue Queue, string *pholder)
{

    if ( Queue.H==NULL )
    {
        printf ("the queue is empty !");
        exit (1);
    }

    (*pholder) = (Queue.T)->Value;
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




void funcstringQueueCreate (stringQueue *pQueue, int stackSize)
{

    string vsInput;
    int viCn;
    for ( viCn=0; viCn<stackSize; viCn++ )
    {
        funcstringInput(&vsInput);
        funcstringQueueEnqueue (pQueue, vsInput);
    }
}

void funcstringQueueDisplay (stringQueue Queue)
{
    stringDNode *vpCn;
    int viCn;


    if ( funcstringQueueEmpty(Queue) )
    {
        printf ("The List is Empty!");
        return;
    }


    vpCn = Queue.H;
    viCn = 0;
    while ( vpCn!=NULL )
    {
        printf ("The value n %d is: ");
        funcstringDisplay (vpCn->Value);
        printf ("\n");
        viCn++;
        vpCn = vpCn->Next;
    }
}
