#include <stdio.h>     
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
typedef int ElemType;
#define MaxSize 100
#define QNODE struct QNode
typedef struct Node        //车辆信息
{

	char AL;
	int NO;
	int time;
} Node;
typedef struct Stack        //栈定义
{

	struct Node    data[MaxSize] ;
	int top;
	int num;
} SqStack;
QNODE              //队列节点
{

	struct Node data;
	QNODE *next;
} ;
typedef struct LinkQueue      //队列结构体定义
{

	QNODE *front,*rear;
	int num;
} LinkQueue;
SqStack *Init_SeqStack()         //栈初始化
{

	SqStack *s;
	s=(SqStack*) malloc(sizeof(SqStack) ) ;
	s->top=-1;
	s->num=0;
	return s;
} 
LinkQueue *Init_LQueue()         //队列初始化
{

	LinkQueue *q;
	QNODE *p;
	q=(LinkQueue*) malloc(sizeof(LinkQueue) ) ;
	p=(QNODE*) malloc(sizeof(QNODE) ) ;
	p->next=NULL;
	q->front=q->rear=p;
	q->num=0;
	return q;
} 
int Empty_SeqStack(SqStack *s)         //判断栈是否为空，栈为空返回1
{

	if(s->top ==-1) 
		return 1;
	else
		return 0;
} 
int  Full_SeqStack(SqStack *s,int n)     //判断栈是否已满，若栈满返回1
{

	if(s->top==n-1) 
		return 1;
	else
		return 0;
} 
int Empty_LQueue(LinkQueue *q)         //判断队列是否为空，队列为空返回1
{

	if(q->front==q->rear) 
		return 1;
	else
		return 0;
} 
void In_Lqueue(    LinkQueue *q,struct Node s)   //入队
{

	QNODE *p;
	p=(QNODE*) malloc(sizeof(QNODE) ) ;
	p->data=s;
	q->num++;
	p->next=NULL;
	q->rear->next =p;
	q->rear =p;
} 
void Push_SeqStack(SqStack *p,struct Node s)   //入栈
{

	p->top ++;
	p->data[p->top] =s;
	p->num++;
} 
int Pop_SeqStack(SqStack *s,struct Node car) //出栈
{

	SqStack *p;
	int t;
	p=Init_SeqStack() ;
	while(s->data[s->top] .NO !=car.NO) //找到车牌号为P.NO的车，
	{

		Push_SeqStack(p,s->data[s->top] ) ;
		s->top--;
		s->num--;
	} 
	t=car.time-s->data[s->top] .time;
	s->top--;
	s->num--;
	while(Empty_SeqStack(p) ==0) 
	{

		Push_SeqStack(s,p->data[p->top] ) ;
		p->top--;
		p->num--;
	} 
	return t;
} 
struct Node Out_LQueue(LinkQueue *q)   //出队
{

	QNODE *p;
	p=q->front->next;
	q->front->next=p->next;
	q->num --;
	if(    q->front->next==NULL) 
		q->rear=q->front;
	return p->data;
	free(p) ;
} 
int main() 
{

	SqStack *parkstack;            //parkstack为表示停车场的栈
	LinkQueue *parkqueue;      //parkqueue为表示便道的队列
	struct Node car;
	int n,a=0,t;                      //n为停车场栈的最大容量
	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime) ;
	timeinfo = localtime (&rawtime) ;
	parkstack=Init_SeqStack() ;
	parkqueue=Init_LQueue() ; //初始界面
	printf(" 实验名称： 停车场管理系统\n") ;
	printf("=============================================\n") ;
	printf("程序运行开始，") ;
	printf("Current local time and date:%s",asctime(timeinfo) ) ;
	printf("请输入停车场最大容量n=\n") ;
	scanf("%d",&n) ;
	printf("请输入车辆信息\n") ;
	scanf("%c,%d,%d",&car.AL,&car.NO,&car.time) ;
	while(car.AL!='E') 
	{

		if(car.AL=='A' ) 
		{
			                                // 汽车到达的情况
     if(Full_SeqStack(parkstack,n) ==1)         //栈满的情况
			 {

     In_Lqueue(parkqueue,car) ;                //进入队列等待
	 printf("这辆车在门外便道上第%d个位置\n",parkqueue->num) ;
     printf("\n") ;
	 printf("请输入车辆信息\n") ;
           } 
 else {

	 Push_SeqStack(parkstack,car) ;        //入栈
	 printf("这辆车在停车场内第%d个位置\n",parkstack->num) ;
	 printf("\n") ;
	 printf("请输入车辆信息\n") ;
} 
} 
	 if(car.AL=='D' )                     //汽车离开的情况
{
    t=Pop_SeqStack(parkstack,car) ;//出栈
    printf("这辆车停留时间为%d\n",t) ;
	printf("\n") ;
	 printf("请输入车辆信息\n") ;
	 if(Empty_LQueue(parkqueue) ==0)   //队列不为空需要进栈
	 Push_SeqStack(parkstack,Out_LQueue(parkqueue)  ) ;     
} 
 if(car.AL=='P'&&car.NO==0&&car.time==0 ) //显示停车场的车数
 {

	printf("停车场的车数为%d\n",parkstack->num) ;
    printf("\n") ;
    printf("请输入车辆信息\n") ;
} 
 if(car.AL=='W'&&car.NO==0&&car.time==0 ) //显示候车场的车数
{

	 printf("候车场的车数为%d\n",parkqueue->num) ;
	 printf("\n") ;
	 printf("请输入车辆信息\n") ;
} 
 scanf("%c,%d,%d",&car.AL,&car.NO,&car.time) ;       
} 
 printf("输入结束\n") ;
 printf("Current local time and date:%s",asctime(timeinfo) ) ;
 return 1;
} 
