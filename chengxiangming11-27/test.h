#ifndef queue_h
#define queue_h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 10
typedef int datatype;
typedef struct{
	datatype data[Maxsize];
	int front;
	int rear;
	int num;
}SeqQueue;

CSeqQueue initQueue();
bool emptyQueue(CSeQueue *queue);
bool fullQueue(CSeqQueue *queue);
void inQueue(CSeqQueue *queue,datatype data);
void deQueue(CSeqQueue *queue,datatype *data);
void frontQueue(CSeqQueue *queue,datatype *data);
void rearQueue(CSeqQueue *queue,datatype *data);

#endif
