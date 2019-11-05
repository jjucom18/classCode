#include "queueg.h"


SeqQueue *initQueue() {

		SeqQueue *q = (SeqQueue *) malloc(sizeof(SeqQueue) ) ;
			q->front =q->rear =MAXSIZE -1;
				q->num=0;
				
					return q;
} 

int  emptyQueue(SeqQueue *q) {

		if(q->num == 0)			return 1;
			else   return 0;} 
			 
			
			int inQueue(SeqQueue *q, DataType x) {

			if (q->num == MAXSIZE) {

			return -1;
	} else {

			q->rear =(q->rear+1) %MAXSIZE;
			q->data[q->rear] =x;
			q->num++;
			return 1;
					} 
			} 
int  outQueue(SeqQueue *q,DataType *x )  
{

			if(q->num==0) {

						return -1;
								} 
					else{

                        	q->front=(q->front+1) %MAXSIZE;
					    	*x=q->data[q->front] ;
							q->num--;
							return 1;
									} 
}   
