#include"List.h"

int initQueue(LinkQueue *Q)
{
        printf("Init a queue ......\n");
        if(!(Q->front = Q->tail = (Queue *)malloc(QUEUE_LEN)))
        {
                printf("ERROR:Malloc Error !\n");
                return ERROR;
        }
        Q->front->next = NULL;
        return OK;
}

int enterQueue(LinkQueue *Q,int enterValue)
{
        Queue *tmpNode = NULL;
        if(!(tmpNode = (Queue*)malloc(QUEUE_LEN)))
        {
                printf("ERROR:Malloc Error !\n");
                return ERROR;
        }

        tmpNode->value = enterValue;
        tmpNode->next = NULL;
        Q->tail->next = tmpNode;
        Q->tail = tmpNode;

}

int isEmptyQueue(LinkQueue *Q)
{
        return  (Q->front->next == NULL);
}



int printQueue(LinkQueue *Q)
{
        Queue *tmpNode = NULL;
        tmpNode = Q->front->next;
        if(NULL == tmpNode)
        {
                printf("ERROR:Queue is NULL\n");
                return ERROR;

        }

        while(tmpNode != Q->tail)
        {
                printf("%d  ",tmpNode->value);
                tmpNode = tmpNode->next;
        }
        printf("%d\n",Q->tail->value);

}

int deQueue(LinkQueue *Q)
{
        if(isEmptyQueue(Q))
        {
                printf("ERROR:The Queue is empty !\n");
                return ERROR;
        }
        int value;
        value = Q->front->next->value;
        Q->front->next = Q->front->next->next;
        return value;
}


int Query(LinkQueue *Q,int myNum)
{
        int numOfMan = 0;
        if(isEmptyQueue(Q))
        {
                printf("The Queue is empty \n");
                return ERROR;
        }
        if( myNum>Q->tail->value || myNum < Q->front->next->value)
        {
                printf("SORRY you have put into a wrong waiting number\n");
                return ERROR;
        }

        numOfMan = myNum-Q->front->next->value;
        return  numOfMan;
}
