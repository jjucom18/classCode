#include<stdio.h>
#include<malloc.h>
void StackInit(SeqStackCar *s) //初始化车场
{      int i; s->top = 0;
       for(i=0; i<=MAXNUM;i++) 
       s->stack[s->top] = NULL;
} 
       intQueueInit(LinkQueueCar *Q) //初始化便道 
{
       Q->head=(QueueNode*)malloc(sizeof(QueueNode)); 
       if(Q->head !=NULL) 
{
       Q->head->next  =NULL;
       Q->rear = Q->head; 
       return ok;
}
else
       return ERROR;
} 
void print(CarNode *p,int room)  //打印离开车辆的信息
{
       int A1,A2,B1,B2;
       printf("\n 请输入离开时间:/**:**/");
       scanf("%d:%d",&(p->leave.hour), &(p->leave.min));
       printf("\n 离开车俩的车牌号为："); puts(p->num);
       printf("\n 其到达时间为：%d:%d",p->leave.hours,p->leave.min);
       A1 =p->reach.hour;
       A2 = p->reach.min;
       B1 = p->leave.hour;
       B2 = p->leave.min;
       printf("\n 应交费用为: %2.1f元",((B1-A1))*60+(B2-A2))*price;
       free(p);
}
       int Arrival(SeqstackCar *Enter,LinkQueueCar *w) //车辆到达 
{
       	CarNode *p;
       	QueueNode *t;
       	p = (CarNode*)malloc(sizeof(CarNode));
	printf("\n 请输入车牌号（例：陕A1234）:");
       	gettchar();
       	gets(p->num);
	if(Enter->top <MAXNUM） /*车场未满，车辆车场*/
 {	
        Enter->top++;
	printf("\n 车俩在车场第%d位置.", Enter->top);
	printf("\n 请输入到达时间：/**:**/");
	scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
	Enter->stack[Enter->top] = p;
	return OK;
}
else /*车辆已满，车进便道*/
{   
        printf("\n该车须在便道等待");
	t =(QueueNode*)malloc(sizeof(QueueNode));
	t->data =p;
	t->next =NULL;
	w->rear->next = t;
	w->rear = t
	return OK;
	}

}
void Leave(SeqStackcar *Enter,SeqStackcar *Temp,LinkQueueCar *W) //车辆离开
{
	int room;
	CarNode *p, *t;
	QueueNode *q;
	if(Enter->top > 0) //有车否？
{
	while(TRUE)  /*输入离开车辆的信息*/
	{
	  printf("\n 请输入车在车场的位置/1--%d/:",Enter->top);
	  scanf("%d", &room）；
	  if(room>=1 && room<=Enter->top break;
        }
       while(Enter->top>room /*车辆离开*/
 {  
          Temp->top++;
          Temp->stack[Temp->top] =Enter->stack[Enter->top];
	  Enter->stack[Enter->top] =NULL;
	  Enter->top--;
   }
   p=Enter->stack[Enter->top];
   Enter->stack[Enter->top] =NULL;
   Enter->top--;
   while(Temp->top>= 1)
   {
     Enter->top++;
     Enter->stack[Enter->top] =Temp->stack[Temp->top];
     Temp->stack[Temp->top]= NULL;
     Temp->top--;
    }
    print(p,room);
    //判断便道上是否有车及车场是否已满
    if(W->head!=W->rear) && Enter->top<MAXNUM)
   {
	q =w->head->next;
	t =q->data;
	Enter->top++;
	printf("\n 便道的%s号车进入车场第%d位置.",t->num,Enter->top);
	printf("\n 请输入现在的时间/**：**/：");
	scanf("%d:%d", &(t->reach.hour), &(t->reach.min));
	W->head->next =q->next;
	if(q==w->rear) W->rear=W->head;
	Enter->stack[Enter->top] =t;
	free(q);
   }	
    else
	 printf("\n 便道里没有车.\n");
}
else 
         printf("\n 车场里没车.") ; /*没车*/
}
void List1(SeqStackCar *s)  //显示车场信息
{
	int i;
	if(s->top> 0) /*判断车场内是否有车*/
{
	printf("\n 车场:");
	printf("\n 位置 到达时间 车牌号\n");
	 s->stack[i]->reach.hour,s-stack[i]->reach.min;
	 puts(s->stack[i]->num);
}
}
         else
       printf("\n 车场里没车")
}
         	  
