#include<test.h>
int mian(int argc,char **argv){

	CSeqQueue *queue = initqueue();
	queue = (CSeqQueue*)malloc(sizeof(CSeqQueue));
    queue->front=queue->rear=Maxsize-1;
	queue->num=0;
	return queue;
} 
int In_SeQueue(CSeQueue *queue,datatype x)
{   if(queue->num==Maxsize)
	{
     printf("队满！");
	 return-1;
	}
    else{
		queue>rear=(queue->rear+1)%Maxsize;
		queue->data[queue->rear]=x;
		queue->num++;
		return 1;
	}
}
int Out_SeQueue(CSeQueue *queue,datatype *x)
{
	if(queue->num==0)
	{
		printf("队空！");
		return -1；
	}
	else{
		queue->front=(queue->front+1)%Maxsize;
		*x=queue->data[queue->front];
		queue->num--;
		return 1;
	}
}int Empty_SeQueue(CSeQueue *queue)
{
	if(queue->num==0)
		return 1;
	else 
		return 0;
}
