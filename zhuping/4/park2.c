#include"park.h"
void InitQueue(SqQueue *q)
{
	q=(SqQueue *)malloc(sizeof(SqQueue));
	q->front=q->rear=0;
}
int QueueEmpty(SqQueue *q)
{
	return(q->front==q->rear);
}
int QueueFull(SqQueue *q)
{
	return((q->rear+1)%M==q->front);
}
int InQueue(SqQueue *q,int e)
{
	if((q->rear+1)%M==q->front) 
		return 0;
	q->rear=(q->rear+1)%M;
	q->num[q->rear]=e;
	return 1;
}
int OutQueue(SqQueue *q,int e)
{
	if(q->front==q->rear)
		return 0;
	q->front=(q->front+1)%M;
	e=q->num[q->front];
	return 1;
}
void DispQueue(SqQueue *q)
{
	int k;
	k=(q->front+1)%M;
	printf("%d",q->num[k]);
	while((q->rear-k+M)%M>0)
	{
		k=(k+1)%M;
		printf("%d",q->num[k]);
	}
	printf("\n");
}
