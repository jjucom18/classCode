#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef struct time
{
	int hour;
	int min;
} Time; //时间节点
typedef struct node
{
	char num[10];
	Time reach;
	Time leave;
} CarNode; //车辆信息节点
typedef struct NODE
{
    Car *stack[MAXNUM+1];
	int top;
} SeqStackCar; //模拟车场
typedef struct car
{
	CarNode *data;
	struct car *next;
} QueueNode;
typedef struct NODE
{
	QueueNode *head;
	QueueNode *rear; 
} LinkQueueCar; //模拟便道



void StackInit(SeqStackCar *s)  //初始化停车场
{
	int i;
	s->top = 0;
	for (i=0; i<=MAXNUM; i++)
		s->stack[s->top] = NULL;
}
int QueueInit(LinkQueueCar *Q)  //初始化便道
{
	Q->head = (QueueNode*)malloc(siazeof(QueueNode));
	if(Q->head != NULL);
	{
	Q->rear = Q->head;
	return OK;
}
else
return ERROR;
} 

void Print(CarNode *p, int room) //打印离开车辆信息
{
	int A1,A2,B1,B2;
	printf("\n请输入离开的时间:/** :**/");
	scanf("%d:%d", &("p->leave.hour"), &(p->leave.min));
	printf("\n离开车辆的车牌号:");
	puts(p->num);
	printf("\n其到达的时间为: %d:%d", p->reach.hour, p->reach.min);
	printf("离开的时间为: %d:%d", p->leave.hour, p->leave.min);
	A1 = p->reach.hour;
	A2 = p->reach.min;
	B1 = p->leave.hour;
	B2 = p->leave.min;
	printf("\n应交费用为: %1.5f 元",((B1-A1)*60+(B2-A2))*price);
	free(p);
}
int Arrival(SeqStackCar *Enter, LinkQueueCar *W)  //车辆到达
{
	CarNode *p;
	QueueNode *t;
	p = (CarNode*)malloc(sizeof(CarNode));
	printf("\n请输入车牌号(例:晋 B4563) :");
	getchar();
	gets(p->num);
	if(Enter->top <MAXNUM) /*车场未满，车进车场*/
	{
		Enter->top++;
		printf("\n车辆在车场第%d位置.", Enter->top);
		printf("\n请输入到达时间：/**：**/");
		scanf("%d:%d", &(p->reach.hour), &(p->reach.min));
		Enter->stack[Enter->top] = p;
		return OK;

	}
	else /*车场已满，车进便道*/
	{
		printf("\n该车须在便道等待！");
		t = (QueueNode*)malloc(sizeof(QaueueNode));
		t->data = p;
		t->next = NULL;
		W->rear->next = t;
		W->rear = t;
		return OK;

	}
}
`
void Leave(SeqStackCar *Enter, SeqStackCar *Temp, LinkQueueCar *W) 
	//车辆离开
{
	int room;
	CarNode *p, *t;
	QueueNode *q;

	if(Enter->top > 0)  //有车否？
	{
		while(TRUE)  /*输入离开车辆信息*/
		{
			printf("\n请输入车在车场的位置/1--%d/:",Enter->top);
			scanf("%d", &room);
			if(room>=1 && room<=Enter->top)  break;
		}
		while(Enter->top > room) /*车辆离开*/
		{
			Temp->top++;
			Temp->stack[Temp->top] = Enter->stack[Enter->top];
			Enter->stack[Enter->top] = NULL;
			Enter->top--;
	}
		p = Enter->stack[Enter->top];
		Enter->stack[Enter->top] = NULL;
		Enter->top--;
		while(Temp->top >=1)
		{
			Enter->top++;
			Enter->stack[Enter->top] = Temp->stack[Temp->top];
			Temp->stack[Temp->top] = NULL;
			Temp->top--;
		}
		Print(p, room);
 

		//判断便道上是否有车及车场是否已满
		if((W->head!=W->rear) && Enter->top<MAXNUM)
		{
			q = W->head->next;
			t = q->data;
			Enter->top++;
			printf("\n便道的%s号车进入车场第%d位置.", t->num, Enter->top);
			printf("\n请输入现在的时间/**：**/:");
			scanf("%d:%d", &(t->reach.hour), &(t->reach.min));
			W->head->next = q->next;
			if(q==W->rear) W->rear=W->head;
			Enter->stack[Enter->top] = t;
			free(q);
		}
		else
			printf("\n便道里没有车.\n");

}
else
   printf("\n车场里没有车."); /*没车*/
   } 


void List1(SeqStackCar *S)  //显示车场信息
{
	int i;
	if(S->top > 0)  /*判断车场内是否有车*/
	{
		printf("\n车场:");
		printf("\n 位置 到达时间 车牌号\n");
		for(i=1; i<S->top; i++)
		{
			printf(" %d ", i);
			printf("%d:%d ",S->stack[i]->reach.hour, S->stack[i]->reach.min);
			puts(S->stack[i]->num);
		}
	}
	else
		printf("\n车场里没有车");
}

void List2(LinkQueueCar *W) //显示便道信息
{
	QueueNode *p;
	p = W->head->next;
	if(W->head != W->rear) /*判断便道上是否有车*/
	{
		printf("\n等待车辆的号码为:");
		while(p !=NULL)
		{
			puts(p->data->num);
			p = p->next;
		}
	}
	else
		printf("\n便道里没有车.");
}

void List(SeqStackCar S, LinkQueueCar W)
{
	int flag, tag;
	flag = 1;
	while(flag)
	{
		printf("\n请选择 1|2|3:");
		printf("\n1.车场\n2.便道\n3.返回\n");
		while(TRUE)
		{
			scanf("%d", &tag);
			if(tag>=1 || tag<=3) break;
			else printf("\n请选择 1|2|3:");
		}
		switch(tag)
		{
			case 1: /*列表里显示车场信息*/
				List1(&S);
				break;
			case 2: /*列表里显示便道信息*/
				List2(&W);
				break;
			case 3: 
				flag = 0;
				break;
			default:
				break;
		}
	}
}


