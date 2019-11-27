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
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define price 0.3
#define MAXSIZE 100

StackInit(SeqStackCar *s)//初始化停车场
{//	int i;int top;
//	s->top = 0;
//	for(i=0;i<MAXSIZE;i++){
	SeqStackCar *s =(SeqStackCar *) malloc (sizeof(SeqStackCar));
	t ->next = NULL;
	if(t->next = NULL)
		return t;
	else
		return -1;
//	return s;
}

int QueueInit(QueueNode *Q)//初始化车道
{
	Q->head =(QueueNode *)malloc(sizeof(QueueNode));
	if(Q->head = NULL) {
			Q->head->next = NULL;
			Q->rear =Q->head;
			return 0;
	}else
			return -1;
} 
			
int Arrival(SeqStackCar *In,LinkQueueCar *W){//有车来
	
	CarNode *p;
	QueueNode *t;
	int top;
	p = (CarNode *)malloc(sizeof(CarNode));

	printf("\n请输入车牌号(例如赣B8888): ");
	getchar();
	gets(p->num);

	if(In->top<MAXSIZE){//停车场有空位
		In->top++;
		printf("\n车辆当前在第%d个位置",In->top);
		printf("\n请输入车辆到达时间：/**:**/");
		scanf("%d:%d,(&p->reach.hour) ,(&p->reach.min") );
		In->linkstack[In->top] = p;
		return 0;
	} else{//停车场满
		printf("\n无空位需在车道等待!");
		t = (QueueNode *)malloc(sizeof(QueueNode));
		t->data = p;
		t->next = NULL;
		w->rear->next = t;
		w->rear = t;
		return 0;} 
} 

void Leave(SeqStackCar *In,SeqStackCar *Temp,LinkQueueCar *W)
{
    //车辆离开
	int room;int top;
	CarNode *p,*t;
	QueueNode *q;
	if(In->top>0) {        //  判断停车场是否为空
	 
		while(1){
		printf("\n请输入车在车场的位置/1--%d/：",In->top);
		scanf("%d",&room);

    if(room>=1&&room<=In->top)	break;
		else printf("\n 输入有误,请重输: ");
	}
     
		while(In->top>room){   //  把要离开的车辆的前面的车开出来，进临时栈。
            Temp->top++;
			Temp->linkstack[Temp->top]=In->linkstack[In->top];
            In->linkstack[In->top]=NULL;
			In->top--;
        }
			p=In->linkstack[In->top]; //  把要离开的车辆节点赋给p。
			In->linkstack[In->top]=NULL;
            In->top--;

		while(Temp->top>=1) {    //  再把临时栈里的车开进停车场
            In->top++;
            In->linkstack[In->top]=Temp->linkstack[Temp->top];
            Temp->linkstack[Temp->top]=NULL;
            Temp->top--;
        }
    
		PRINT(p,room);      //   调用计费函数计费

    if((W->head!=W->rear)&&In->top<MAXSIZE){ //如果车道上有车。    
		q=W->head->next;
        t=q->data;
		In->top++;

	printf("\n便道的%s号车进入车场第%d位置.",t->num,In->top);
	printf("\n请输入%s号车进入车场的时间:",t->num);
    scanf("%d:%d",&(t->reach.hour),&(t->reach.min));
	W->head->next=q->next; 

    if(q==W->rear){
		W->rear=W->head;
        In->linkstack[In->top]=t;
                
		free(q);
    }
    else printf("\n便道里没有车.\n");
    }
    else printf("\n车场里没有车.");
	}  


void PRINT(CarNode *p,int room){     // 车辆收费
 
	int A1,A2,B1,B2;
	printf("\n输入车辆离开的时间:");
	scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
	printf("\n车辆到达时间为: %d:%d",p->reach.hour,p->reach.min);
	printf("\n车辆离开时间为: %d:%d",p->leave.hour,p->leave.min);
	printf("\n离开车辆的车牌号为:");
	puts(p->num);

	A1=p->reach.hour;
	A2=p->reach.min;
	B1=p->leave.hour;
	B2=p->leave.min;
	printf("\n应交费用为: %2.1f元",((B1-A1)*60+(B2-A2))*price);
    
		free(p);
}   


