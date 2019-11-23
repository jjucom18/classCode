#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

#include"car.h"

void welcome(){
	printf("\n\n");
	printf("\t**欢迎使用本系统**\n");
	printf("\t有车到来时请按【C】。\n");
	printf("\t然后根据屏幕提示进行操作，有车走时请按【A】\n");
	printf("\t然后根据屏幕提示进行操作，要退出系统请按【B】\n");
	printf("\t请选择你要做的操作.\n");
	return ;
}

void StackInit(SeqStackCar *s)  //初始化车场
{
	int i;
	s->top=0;
	for(i=0;i<=MAXNUM;i++)
		s->stack[s->top]=NULL;
}

int QueueInit(LinkQueueCar *Q)  //初始化便道
{
	Q->head=(QueueNode *)malloc(sizeof(QueueNode));
	if(Q->head!=NULL){
		Q->head->next=NULL;
		Q->rear=Q->head;
		return(1);
	}
	else 
		return(-1);
}

void Print(CarNode *p,int room)  //打印车辆离开的信息
{
	int A1,A2,B1,B2;
	int price=2;
	printf("请输入离开的时间：/**:**/");
	scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
	printf("离开车辆的车牌号");
      puts(p->num);
	printf("\n其到达时间：%d:%d",p->reach.hour,p->reach.min);
	printf("\n离开时间：%d:%d",p->leave.hour,p->leave.min);
	A1=p->reach.hour;
	A2=p->reach.min;
	B1=p->leave.hour;
	B2=p->leave.min;
	printf("\n应交费用：%2.1d元",((B1-A1)*60+(B2-A2))*price);
	free(p);
}


int Arrival(SeqStackCar *Enter,LinkQueueCar *W)  //车辆到达
{
	CarNode *p;
	QueueNode *t;
	char num[10];
	p=(CarNode *)malloc(sizeof(CarNode));
	printf("\n请输入车牌号(例：DS888)：\n");
    getchar();
	scanf("%s",num);
	if(Enter->top<MAXNUM)    //未满
	{
		Enter->top++;
		printf("\n车辆停在第%d位置",Enter->top);
		printf("到达时间：/**:**/");
		scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
		Enter->stack[Enter->top]=p;
		return(1);
	}
	else //车满
	{
		printf("\n请在便道等候!");
        t=(QueueNode *)malloc(sizeof(QueueNode));
		t->data=p;
		t->next=NULL;
		W->rear->next=t;
		W->rear=t;
		return(1);
	}
}

void Leave(SeqStackCar *Enter,SeqStackCar *Temp,LinkQueueCar *W)  //车辆离开
{
	int room;CarNode *p,*t;
	QueueNode *q;
	int TURE;
	if(Enter->top>0)  //有车？
	{
		while(TURE){
			printf("\n请输入车停的位置: %d",Enter->top);
			scanf("%d",&room);
			if(room>=1&&room<=Enter->top) break;
		}
		while(Enter->top>room) //车辆离开
		{
			Temp->top++;
			Temp->stack[Temp->top]=Enter->stack[Enter->top];
			Enter->stack[Enter->top]=NULL;
			Enter->top--;
		}
		p=Enter->stack[Enter->top];
		Enter->stack[Enter->top]=NULL;
		Enter->top--;
		while(Temp->top>=1){
			Enter->top++;
			Enter->stack[Enter->top]=Temp->stack[Temp->top];
			Temp->stack[Temp->top]=NULL;
			Temp->top--;
		}
		Print(p,room);

if((W->head!=W->rear)&&Enter->top<MAXNUM){
	q=W->head->next;
	t=q->data;
	Enter->top++;
	printf("\n便道的%s号车进入车场第%d位置",t->num,Enter->top);
	printf("\n请输入现在的时间/**:**/");
	scanf("%d:%d",&(t->reach.hour),&(t->reach.min));
	W->head->next=q->next;
	if(q==W->rear) W->rear=W->head;
	Enter->stack[Enter->top]=t;
	free(q);
}
else
printf("\n便道里没有车");
	}
else
printf("\n车场里没有车"); //没车
}


void List1(SeqStackCar *S)  //显示车场信息
{
	int i;
	if(S->top>0) /*判断车场内是否有车*/
	{
		printf("\n车场：");
		printf("\n位置 到达时间 车牌号\n");
		for(i=1;i<=S->top;i++){
			printf("%d",i);
			printf("%d:%d",S->stack[i]->reach.hour,S->stack[i]->reach.min);
			puts(S->stack[i]->num);
		}
	}
	else
		printf("\n车场里没有车");
}


void List2(LinkQueueCar *W)  //显示便道信息
{
	QueueNode *p;
	p=W->head->next;
	if(W->head!=W->rear) /*判断便道是否有车*/
	{
		printf("\n等待车辆的号码：");
		while(p!=NULL){
			puts(p->data->num);
			p=p->next;
		}
	}
	else
		printf("\n便道里没有车");
}

void List(SeqStackCar S,LinkQueueCar W){
	int flag,tag;
	int TURE;
	flag=1;
	while(flag){
		printf("\n请选择1|2|3:");
		printf("\n1.车场\n2.便道\n3.返回\n");
		while(TURE){
			scanf("%d",&tag);
			if(tag>=1||tag<=3) break;
			else printf("\n请选择1|2|3:");
		}
switch(tag){
	case 1: /*列表显示车场信息*/
		List1(&S);
	case 2:/*列表显示便道信息*/
		List2(&W);
		break;
	case 3:flag-0;
		   break;
	default :break;
}
	}
}
