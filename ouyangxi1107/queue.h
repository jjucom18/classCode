#ifndef queue_h
#define queue_h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 10
typedef int datatype;
typedef struct{
    datatype data[axsize];
    int front;
    int rear;
    int num;
}CSeqQueue;

CSeqQueue *initQueue();
bool emptyQueue(CSeqQueue *queue);
bool fullQueue(CSeqQueue *queue);
void inQueue(CSeqQueue *queue,datatype data);
void deQueue(CSequeue *queue,datatype * data);
void frontQueue(CSeqQueue *queue,datatype *data);
void rearQueue(CSeqQueue *queue,datatype *data);

#endif
