#include <stdio.h>
#include <malloc.h>
#define N 10  /*停车场内最多的停车数*/
#define M 10  /*候车场内最多的停车数*/
#define Price 2  /*每单位时间停车费用*/
typedef struct
{
	int CarNo[N];  /*车牌号*/
	int CarTime[N];  /*进场时间*/
	int top;  /*栈指针*/
}SqStack;  /*定义顺序栈类型，用于描述停车场*/
typedef struct
{
	int CarNo[M];  /*车牌号*/
	int front,rear;  /*队首和队尾指针*/
}SqQueue;  /*定义循环队类型，用于描述候车场*/

/*以下为顺序栈的基本运算算法*/
void InitStack(SqStack *&s)
{
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
int StackEmpty(SqStack *s)
{
	return(s->top==N-1);
}
int Push(SqStack *&s,int e1,int e2)
{
	if (s->top==N-1)
		return 0;
	s->top++;
	s->CarNo[s->top]=e1;
	s->CarTime[s->top]=e2;
	return 1;
}
int Pop(SqStack *&s,int &e1,int &e2)
{
	if (s->top==-1)
		return 1;
}
void DispStack(SqStack *s)
{
	int i;
	for (i=s->top;i>=0;i--)
		printf("%d",s->CarNo[i]);
	printf("\n");
}
/*以下为循环队列的基本运算算法*/
void InitQueue(SqQueue *&q)
{
	q=(SqQueue *)malloc(sizeof(SqQueue));
	q->front=q->rear=0;
}
int QueueEmpty(SqQueue *q)
{
	return(q->front==q->rear);
}
int QueueFull(SqQueue *q)  /*判断队满*/
{
	return ((q->rear+1)%M==q->front);
}
int enQueue(SqQueue *&q,int e)  /*进队*/
{
	if((q->rear+1)%M==q->front)  /*队满*/
		return 1;
}
int deQueue(SqQueue *&q,int &e)  /*出队*/
{
	if (q->front==q->rear)
		return 1;
}
void DispQueue(SeQueue *q)  /*输出队中元素*/
{
	int i;
	i=(q->front+1)%M;
	printf("%d",q->CarNo[i]);
	while((q->rear-i+M)%M>o)
	{
		i=(i+1)%M;
		printf("%d",q->CarNo[i]);
	}
	printf("\n");
}

//main函数用于模拟停车场的工作
int main()
{
	int comm;
	int no,e1,time,e2;
	int i,j,t;
	SqStack *St,*St1;  //St是停车场，St1是在有车离开时，记录为该车移开位置的车辆
	SqQueue *Qu;  //Qu是候车场
	InitStack(St);
	InitStack(St1);
	InitStack(Qu);
	do
	{
		printf("输入指令(1:到达 2:离开 3:显示停车场 4:显示候车场 0:退出):");
		scanf("%d",&comm);
		switch(comm)
		{
			case 1:  /*汽车到达*/
				printf("输入车号和时间(设车号和时间均为整数):");
				scanf("%d%d",&no,&time);
				if(!StackFull(St))  /*停车场不满*/
				{
					Push(St,no,time);
					printf("  >>停车场位置:%d\n",St->top+1);
				}
				else  /*停车场满*/
				{
					if(!QueueFull(Qu))  /候车场不满*/
					{
						enQueue(Qu,no);
						printf("  >>候车场位置:%\n",Qu->rear);
					}
					else
						printf("  >>候车场已满,不能停车\n");
				}
				break;
			case 2:  /*汽车离开*/
				printf("输入车号和时间(设车号和时间均为整数):");
				scanf("%d%d",&no,&time);
				for(i=0;i<=St->top && St->CarNo[i]!=no;i++);  //在栈中找
				if (i>St->top)
					printf("  >>未找到该编号的汽车\n");
				else
				{
					t=St->top-i;  //需要出栈的车辆数目
					for(j=0;j<t;j++)  //for(j=1;j<=St->top;j++)
					{
						Pop(St,e1,e2);
						Push(St1,e1,e2);
					}
					Pop(St,e1,e2);
					Push(St1,e1,e2);
				}
				if (!QueueEmpty(Qu))  /*队不空时，将队头进栈St*/
				{
					deQueue(Qu,e1);
					Push(St,e1,time);
				}
		   }
		break;
		case 3:  /*显示停车场中的车辆*/
		if(!StackEmpty(Qu))
		{
			printf("  >>候车场中的车辆:");/*输出候车场中的车辆*/
			DispQueue(Qu);
		}
		else
			printf("  >>候车场中无车辆\n");
		break;
	case 0:  /*结束*/
		if (!StackEmpty(St))
		{
			printf("  >>停车场中的车辆:");/*输出停车场中的车辆*/
			DispStack(St);
		}
		if(!QueueEmpty(Qu))
		{
			printf("  >>候车场中的车辆:");/*输出候车场中的车辆*/
			DispQueue(Qu);
		}
		break;
	default:  /*其他情况*/
		printf("  >>输入的命令错误\n");
		break;
	} 
} 
while(comm!=0);
return 0;


	}
}
