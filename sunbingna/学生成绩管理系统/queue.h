#ifndef _QUEUE_H
#define _QUEUE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdbool.h>

typedef struct QNode
{ 
    char account[5];
    char password[5];
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{ 
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

void InitQueue(LinkQueue *Q);
int QueueEmpty(LinkQueue Q);
void EnQueue(LinkQueue *Q);
bool QueueTraverse(LinkQueue Q);
void QueueChoice();
void queuechoice();

#endif