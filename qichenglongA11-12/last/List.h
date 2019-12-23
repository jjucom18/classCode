#ifndef  LIST_H
#define LIST_H
#include<stdio.h>
#include<stdlib.h>

#define OK      0
#define ERROR   -1
#define QUEUE_LEN  sizeof(Queue)

static bankNumber = 0;
static totalNumber = 0;
int stopBank();
int startBank();
int flag = 1;
//define the structure node
typedef struct queue
{
        int value;
        struct queue *next;
}Queue;

// front point to head node
typedef struct linkqueue
{
        Queue *front;
        Queue *tail;
}LinkQueue;



#endif
