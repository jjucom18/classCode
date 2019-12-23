#include"parking.h"

void InitStack(SeqStackCar *s){
	int i;
	s->top=0;
	for(i=0;i<=MAX;i++)
		s->stack[s->top]=NULL;
}

int InitQueue(LinkQueueCar *Q){
	Q->head=(QueueNode *)malloc(sizeof(QueueNode));
	if(Q->head!=NULL)
	{
		Q->head->next=NULL;
		Q->rear=Q->head;
		return(1);
	}
	else return(-1);
}

float PRINTE(CarNode *p,int room){
	int A1,A2,B1,B2;
	printf("\n车辆离开便道的时间:");
	scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
	printf("\n离开车辆的车牌号:");
	puts(p->num);
	printf("\n其到达便道的时间为：%d:%d",p->reach.hour,p->reach.min);
	printf("\n离开便道时间为：%d:%d",p->leave.hour,p->leave.min);
	A1=p->reach.hour;
	A2=p->reach.min;
	B1=p->leave.hour;
	B2=p->leave.min;
	printf("\n应交费用为：%2.1f元",((B1-A1)*60+(B2-A2))*pricee);
	return(((B1-A1)*+(B2-A2))*pricee);
	free(p);
}
	
void PRINT(CarNode *p,int room){
	int A1,A2,B1,B2;
	printf("\n车辆离开的时间:");
	scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
	printf("\n离开车辆的车牌号为:");
	puts(p->num);
	printf("\n其到达停车位的时间");
	printf("\n离开停车位的时间为:");
	A1=p->reach.hour;
	A2=p->reach.min;
	B1=p->leave.hour;
	B2=p->leave.min;
	printf("\n应交费用为:%2.1f元",((B1-A1)*60+(B2-A2))*price+PRINTE(p,room));
	free(p);
}

int Arrival(SeqStackCar *Enter,LinkQueueCar *W){
	CarNode *p;
	QueueNode *t;
	p=(CarNode *)malloc(sizeof(CarNode));
	flushall();
	printf("\n请输入车牌号(例B2342):");
	gets(p->num);
	if(Enter->top<MAX)
	{
		Enter->top++;
		printf("\n车辆在车场第%d位置",Enter->top);
		printf("\n车辆到达时间:");
		scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
		Enter->stack[top]=p;
		return(1);
	}
}
	else{
		printf("\n该车须在便道等待！有车位时进入车场");
		t=(QueueNode *)malloc(sizeof(QueueNode));
		printf("请输入进入便道的时间");
		scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
		return(1);
	} 
	
void Leave(SeqStackCar *Enter,SeqStackCar *Temp,LinkQueueCar *W)
{
	int room;CarNode *p,*t;
	QueueNode &q;
	if(Enter->top>0)
	{
		while(1){
			printf("\n请输入车在车场位置/1--%d/:",Enter-top);
			scanf("%d",&room);
			if(room>=1&&room<=Enter->top)break;
			else printf("\n输入有误，请重输:");
		}
		while(Enter->top>room)
		{
			temp->top++;
			temp->stack[Temp->top]=Enter->stack[Enter->top];
			Enter->stack[Enter->top]=NULL;
			Enter->top--;
		}
		p=Enter->stack[Enter->top];
		Enter->stack[Enter->top]=NULL;
		Enter->top--;
		while(Temp->top>=1)
		{
			Enter->top++;
			Enter->stack[Enter->top]=Temp->stack[Temp->top];
			Temp->stack[Temp->top]=NULL;
			Temp->top--;
		}
		PRINT(p,room);
		if((w->head!=W->rear)&&Enter->top<MAX)
		{
			p=W->head->next;
			t=p->data;
			Enter->top++;
			scanf("%d:%d",&(t->reach.hour),&(t->reach.min));
			t->leave.hour=t->reach.hour;
			t->leave.min=t->reach.min;
			W->head->next=q->next;
			if(p==W->rear)W->rear=w->head;

			Enter->stack[Enter->top]=t;
			PRINIE(t,room);
			free(p);
		}
		else printf("\n便道里没有车\n");
	}
	else printf("\n车场里没有车");
}
void List1(SeqStackCar *S)
{
	int i;
	if(S->top>0)
	{
		printf("\n车场:");
		printf("\n位置 到达时间  车牌号\n");
		for(i=1;i<=S->top;i++)
		{
			printf(" %d  ",i);
			printf("%d:%d",S->stack[i]->reach.hour,S->stack[i]->reach.min);
			puts(S->stack[i]->num);
		}
	}
	else printf("\n车场里没有车");
}
void List2(LinkQueueCar *W)
{
	QueueNode *p;
	int i;
	p=W->head->next;
	if(W->head!=W->rear)
	{
		printf("\n等待车辆的号码为：");
		for(i=1;(p!=NULL);i++)
		{
			printf("\n第%d车辆.",i);
			puts(p->data->num);
			p=p->next;
		}
	}
	else printf("\n便道里没有车.");
	printf("\n");
}
void List(SeqStackCar S,LinkQueueCar W)
{
	int flag,tag;
	flag=1;
	while(flag)
	{
		printf("查看车辆列表显示:");
		printf("\n 1.车辆列表\n2.便道列表\n3.返回主菜单\n");
		printf("\n请选择 1~3:");
		while(1)
		{
			scanf("%d",&tag);
			if(tag>=1&&tag<=3)break;
			else printf("\n输入有误，请重新选择 1~3:");
		}
		switch(tag)
		{
			case 1:List1(&S);break;
			case 2:List2(&W);break;
		    case 3:flag=0;system("cls");break;
			default:break;
		}
	}
}
