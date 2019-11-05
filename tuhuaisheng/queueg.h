#ifndef queue_h
#define queue_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10
typedef int DataType;
typedef struct{

		DataType data[MAXSIZE] ;
			int front, rear;
				int num;
} SeqQueue;

SeqQueue *initQueue() ;
int emptyQueue(SeqQueue *queue) ;
int fullQueue(SeqQueue *queue) ;
int inQueue(SeqQueue *queue, DataType data) ;
int outQueue(SeqQueue *queue, DataType *data) ;

#endif
