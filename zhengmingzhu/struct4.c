//This is c program code!
/* *=+=+=+=+* *** *=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
  * 文档信息: *** :~/classCode/zhengmingzhu/struct4.c
  * 版权声明: *** :(魎魍魅魑)MIT
  * 联络信箱: *** :guochaoxxl@163.com
  * 创建时间: *** :2019年11月23日的上午10:17
  * 文档用途: *** :数据结构与算法分析-c语言描述
  * 作者信息: *** :guochaoxxl(http://cnblogs.com/guochaoxxl)
  * 修订时间: *** :2019年第46周 11月23日 星期六 上午10:17 (第327天)
  * 文件描述: *** :自行添加
 * *+=+=+=+=* *** *+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+*/
#include "struct4.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define price 0.3
#define MAXSIZE 100

LinkStackInit(LinkStackCar *s)//初始化停车场
{	int i;
	s->top = 0;
	for(i=0;i<MAXNUM;i++){
		s->stack[s->top] = NULL;}
}

int QuenueInit(QueueNode *Q)//初始化车道
{	Q->head =(QueueNode *)malloc(sizeof(QueueNode));
	if(Q->head = NULL) {
			Q->head->next = NULL;
			Q->rear =Q->head;
			reture 0;
	}else
			reture -1;
} 
			
int Arrival(LinkStackCar *In,LinkQueue *W){//有车来
	CarNode *p;
	QueueNode *t;
	p = (CarNode *)malloc(sizeof(CarNode));

	printf("\n请输入车牌号(例如赣B8888): ");
	getchar();
	gets(p->num);
	if(In->top<MAXNUM){//停车场有空位
		In->top++;
		printf("\n车辆当前在第%d个位置",In->top);
		printf("\n请输入车辆到达时间：/**:**/");
		scanf("%d:%d,(&p->reach.hour) ,(&p->reach.min") );
		In->stack[In->top] = p;
		return 0;
	} 
	else{//停车场满
		printf("\n无空位需在车道等待!");
		t = (QuenueNode *)malloc(sizeof(QuenueNode));
		t->data = p;
		t->next = NULL;
		w->rear->next = t;
		w->rear = t;
		return 0;} 
} 

void Leave(LinkStackCar *In,LinkStackCar *Temp,LinkQueueCar *W)
{
    //车辆离开
	int room;
	CarNode *p,*t;
	QueueNode *q;
	if(In->top>0) {        //  判断停车场是否为空
	 
		while(1){
		printf("\n请输入车在车场的位置/1--%d/：",In->top);
		scanf("%d",&room);

    if(room>=1&&room<=In->top) break;
    else printf("\n 输入有误,请重输: ");
		}
     
		while(In->top>room){   //  把要离开的车辆的前面的车开出来，进临时栈。
            Temp->top++;
    Temp->stack[Temp->top]=In->stack[In->top];
            In->stack[In->top]=NULL;
			In->top--;
        }
			p=In->stack[In->top]; //  把要离开的车辆节点赋给p。
			In->stack[In->top]=NULL;
            In->top--;

         while(Temp->top>=1) {    //  再把临时栈里的车开进停车场
            In->top++;
            In->stack[In->top]=Temp->stack[Temp->top];
            Temp->stack[Temp->top]=NULL;
            Temp->top--;
        }
    
		 PRINT(p,room);      //   调用计费函数计费
    if((W->head!=W->rear)&&In->top<MAX){ //如果车道上有车。    
		q=W->head->next;
        t=q->data;
		In->top++;														 printf("\n便道的%s号车进入车场第%d位置.",t->num,In->top);
	printf("\n请输入%s号车进入车场的时间:",t->num);
    scanf("%d:%d",&(t->reach.hour),&(t->reach.min));
    W->head->next=q->next;

    if(q==W->rear) W->rear=W->head;
            In->stack[In->top]=t;
                free(q);
    }
    else printf("\n便道里没有车.\n");
    }
    else printf("\n车场里没有车.");
} 


void PRINT(CarNode *p,int room){     // 车辆收费
 
	int A1,A2,B1,B2;
	printf("\n车辆离开的时间:");
	scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
	printf("\n离开车辆的车牌号为:");
	puts(p->num);
	printf("\n其到达时间为: %d:%d",p->reach.hour,p->reach.min);
	printf("\n离开时间为: %d:%d",p->leave.hour,p->leave.min);

	A1=p->reach.hour;
	A2=p->reach.min;
	B1=p->leave.hour;
	B2=p->leave.min;
	printf("\n应交费用为: %1.1f元",((B1-A1)*60+(B2-A2))*price);
     
		free(p);
}   


void menual()//停车管理系统的显示界面
	{
    LinkStackCar In,Temp;
    LinkQueueCar W;
    int ch;
		system("color 1A");
		InitStack(&In);
		InitStack(&Temp);
        InitQueue(&W);
        while(1)
{


    printf(" 欢迎使用停车场系统\n");
    printf("1. 车辆到达登记\t");
    printf("2. 车辆离开登记\t");
    printf("3. 车辆列表显示\t");
    printf("4. 退出管理系统\n");
     while(1)
{
    printf(" \n\n请选择: ");
    scanf("%d",&ch);
    if(ch>=1&&ch<=4)break;
		else printf("\n 输入有误，请重新选择： 1~4: ");
    }
    switch(ch)
    {
    case 1:Arrival(&In,&W);
		break;
    case 2:Leave(&In,&Temp,&W);
		break;
	case 3:List(In,W);
		break;
    case 4:exit(0);
	default: break;} 
 
	}
}   

