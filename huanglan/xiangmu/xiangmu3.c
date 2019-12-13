#include<stdio.h>
#include<malloc.h>
typedef struct Qnode
{
	int data;
	struct Qnode *next;
}Qnode,*Queueptr;
typedef struct
{
	Queueptr front;
	Queueptr rear;
}Linkqueue;
void Initqueue(Linkqueue *Q) //建立空队列

{
Q->front=Q->rear=(Queueptr)malloc(sizeof(Qnode));
if(Q->front)
Q->front->next=NULL;
}
void Enqueue(Linkqueue *Q,int m)//入队
{
Queueptr p;
p=(Queueptr)malloc(sizeof(Qnode));
if(p)
{
	p->data=m;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
}
}
int Dequeue(Linkqueue *Q)//出队
{int m;
Queueptr p;
if(Q->rear!=Q->front)
{
	p=Q->front->next;
	m=p->data;
	Q->front->next=p->next;
}

if(Q->front==p)
Q->rear=Q->front;
free(p);
return m;
}
void Dance(Linkqueue *M,Linkqueue *W)//学生舞蹈搭配
{   
	int i,m,n,k,a,b,c,d,num=0,r=0;
	printf("请输入男生的数量：");
	scanf("%d",&n);
	printf("请输入女生的数量：");
	scanf("%d",&m);
	printf("请输入曲子的数量：");
	scanf("%d",&k);
	printf("请输入你要查找的男生编号：");
	scanf("%d",&a);
	printf("请输入你要查找的女生编号：");
	scanf("%d",&b);
    for(i=1;i<=m;i++)
		Enqueue(W,i);
	for(i=1;i<=n;i++)
		Enqueue(M,i);
	for(i=1;i<=k;i++)
	{
		printf("\n\n现在正在播放第%d首曲子！\n",i);
		c=Dequeue(M);
		d=Dequeue(W);
		printf("现在正在跳舞的是第%d号男生和第%d号女生！\n",c,d);
		if (c==a&&b==d)
		{
			r=1;
			num++;
			printf("第%d号男生和%d号女生在s第%d号曲子一起跳舞！\n",a,b,i);
		}
		Enqueue(M,c);
		Enqueue(W,d);
	}
	if(r==0)
		printf("\n你要查找的%d号男生和%d号女生没有在一起搭配跳舞！\n",a,b);
	if (r==1)
		printf("\n你要查找的%d号男生和%d号女生在一起跳舞的次数为：%d次\n",a,b,num);
}
int main()
{
	Linkqueue M,W;
	Initqueue(&M);
	Initqueue(&W);
	Dance(&M,&W);
	return 0;
}
