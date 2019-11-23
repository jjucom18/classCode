#include"parking.h"

void InitQueue(SqQueue &q)
{
q=(SqQueue )malloc (sizeof(SqQueue));
q->front=q->rear=0;
}
int QueueEmpty(SqQueue q)
{
return(q->front==q->rear);
}
int QueueFull(SqQueue q)//判断队满
{
return ((q->rear+1)%M==q->front);
}
int enQueue(SqQueue &q,int e)//进队
{
if ((q->rear+1)%M==q->front) //队满
return 0;
q->rear=(q->rear+1)%M;
q->CarNo[q->rear]=e;
return 1;
}
int deQueue(SqQueue &q,int &e) //出队
{
if (q->front==q->rear) //队空的情况
return 0;
q->front=(q->front+1)%M;
e=q->CarNo[q->front];
return 1;
}
void DispQueue(SqQueue q)//输出队中元素
{
int i;
i=(q->front+1)%M;
printf("%d ",q->CarNo[i]);
while ((q->rear-i+M)%M>0)
{
i=(i+1)%M;
printf("%d ",q->CarNo[i]);
}
printf("\n");
}
