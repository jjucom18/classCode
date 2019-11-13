#include "queueg.h"


typedef struct{
	DataType data[MaxSize];
	int front;
	int rear;
	int num;
}CSeQueue;





CSQueue* Init_SeQueue()
{
	CSeQueue *q;
	q=(CSeQueue*)malloc(sizeof(CSeQueue));
	q->front=MAXSIZE -1;
	q->rear=MAXSIZE-1;
	q->front=q->rear;
	q->num=0;
	return q;
}



int In_SeQueue(CSeQueue *q,int x)
{
	if(q->num==MAXSIZE) {
		printf("队满")；
			return -1;
	}

else
   {
	   q>rear=(q->rear+1)%MAXSIZE;
	   q->data[q->rear]=x;
	   q->num++;
	   return 1;
   }
} 





int Out_SeQueue(CSeQueue *q,int *x){
	 if(q->num==0)
	 {
		 printf("队空");
		 return -1 ;
	 }

}


int Empty_SeQueue(CSeQueue *q)
{
	if(q->num==0) return  1;
	  else return 0;


}





















