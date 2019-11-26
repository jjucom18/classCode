typedef struct time
{
	int hour;
	int min;
}Time;//时间节点
typedef struct node
{
	char num[10];
	Time reach;
	Time leave;
}CarNode;//车辆信息节点
typedef struct NODE
{
	CarNode *stack[MAXNUM+1];
	int top;
}SeqStackCar;//模拟车场
typedef struct car
{
	CarNode *date;
	struct car *next;
}QueueNode;
typedef struct Node
{
	QueueNode *head;
	QueueNode *rear;
}LinkQueueCar;//模拟便道
void StdckInit(SeqStackCar *s) //初始化车场
{
	int i;
	s->top = 0;
	for(i=0;i<=MAXNUM;i++)
		s->stack[s->top] = NULL;
}
int QueueInit(LinkQueueCar *Q) //初始化便道
{
	Q->head = (QueueNode*)malloc(sizeof(QueueNode));
	if(Q->head !=NULL)
	{
		Q->head->next = NULL;
		Q->rear = Q->head;
		return OK;
	}
	else
	return ERROR;
}
void Print(CarNde *p, int room) //打印离开车辆信息
{
	int A1,A2,B1,B2;
	printf("\n请输入离开的时间：/**：**/")；
	scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
	printf("\n离开车辆的车牌号为：");
	puts(p->num);
	printf("\n其到达时间为：%d:%d",p->reach.hour,p->reach.min);
	printf("离开时间为：%d:%d",p->leave.hour,p->leave.min);
	A1 = p->reach.hour;
	A2 = p->reach.min;
	B1 = p->leave.hour:
	B2 = p->leave.min;
	printf("\n应交费用为： %2.1f元")
}
