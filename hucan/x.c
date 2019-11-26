#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2//车库容量
#define price 0.05//每车每分钟费用

typedef struct time//时间结点
{ 
int hour;
	    int min;
}Time;
typedef struct node
{
    char num[10];
    Time reach;
    Time leave;
}CarNode;
typedef struct NODE//模拟车站
{ 
 CarNode *stack[MAX+1];
     int top;
}SeqStackCar;
typedef struct car
{
	    CarNode *data;
	        struct car *next;
}QueueNode;
typedef struct Node//模拟通道
{
QueueNode *head;
    QueueNode *rear;
}LinkQueueCar;

void InitStack(SeqStackCar *);
int InitQueue(LinkQueueCar *);
int arrival(SeqStackCar *,LinkQueueCar *);
void leave(SeqStackCar *,SeqStackCar *,LinkQueueCar *);
void list(SeqStackCar,LinkQueueCar);
int main(void)
{
    SeqStackCar Enter,Temp;
    LinkQueueCar Wait;
    int ch;
    InitStack(&Enter);
    InitStack(&Temp);
    InitQueue(&Wait);
    while(1)
    {
        printf("|-----------------------------------------------|\n");
        printf("|        1.The car arrive        |\n");
	printf("|        2.The car leave            |\n");
        printf("|        3.The schedule            |\n");
	printf("|        4.Exit                |\n");
	printf("|-----------------------------------------------|\n");
	while(1)
	{
	    scanf("%d",&ch);
	    if(ch >= 1 &&ch <= 4)
		break;
	    else
	        printf("\nPlease choose: 1|2|3|4.");
	}
        switch(ch)
	{
        case 1:
	    arrival(&Enter,&Wait);
	    break;
	case 2:
	    leave(&Enter,&Temp,&Wait);
	    break;
	case 3:
	    list(Enter,Wait);
            break;
        case 4:
	    exit(0);
	default:
	    break;
	}
    }
}

void InitStack(SeqStackCar *s)
{
   int i;
   s->top = 0;
   for(i = 0; i <= MAX; ++i)
   {
  s->stack[s->top] = NULL;
      }
}
int InitQueue(LinkQueueCar *Q)
{
    Q->head = (QueueNode *)malloc(sizeof(QueueNode));
    if(Q->head != NULL)
    {
       Q->head->next = NULL;
       Q->rear = Q->head;
       return 1;
}
    else
{
    return -1;
}
}
void print(CarNode *p,int room)
{
    int A1,A2,B1,B2;
    printf("\nPlease input the depart time:/**:**/");
    scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
    printf("\nThe number of the car:");
    puts(p->num);
    printf("\nThe time The car arrive:%d:%d",p->reach.hour,p->reach.min);
    printf("\nThe depart time:%d:%d",p->leave.hour,p->leave.min);
    A1 = p->reach.hour;
    A2 = p->reach.min;
    B1 = p->leave.hour;
    B2 = p->leave.min;
    printf("\nThe fee: %2.1f元",((B1-A1)*60+(B2-A2)*price));
    free(p);
}
int arrival(SeqStackCar *Enter,LinkQueueCar *W)
{
    CarNode *p;
    QueueNode *t;
    p = (CarNode *)malloc(sizeof(CarNode));
    flushall();
     printf("\nInput the number of the car(例：陜A1234)：");
     gets(p->num);
      if(Enter->top < MAX)
      {
	 Enter->top ++;
	 printf("\nThe place of the car.",Enter->top);
	 printf("\nThe time the car arrive:/**:**/");
	 scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
	 Enter->stack[Enter->top] = p;
	 return 1;
      }
      else
      {
        printf("\n该车须在便道等待！");
	t = (QueueNode *)malloc(sizeof(QueueNode));
        t->data = p;
	t->next = NULL;
	W->rear->next = t;
	W->rear = t;
	return 1;
      }
}
void leave(SeqStackCar *Enter,SeqStackCar *Temp,LinkQueueCar *W)
{
    int i,room;
    CarNode *p,*t;
    QueueNode *q;
    if(Enter->top > 0)
    {
        while(1)
        {
	    printf("\n请输入车在车场的位置/1--%d/",Enter->top);
	    scanf("%d",&room);
	    if(room >= 1 && room <= Enter->top)
		break;
	}
	while(Enter->top > room)
	{
	      Temp->top ++;
	      Temp->stack[Temp->top] = Enter->stack[Enter->top];
	      Enter->stack[Enter->top] = NULL;
	      Enter->top --;
	}
        p = Enter->stack[Enter->top];
	Enter->stack[Enter->top] = NULL;
	Enter->top --;
	while(Temp->top >= 1)
	{
	    Enter->top ++;
	    Enter->stack[Enter->top] = Temp->stack[Temp->top];
	    Temp->stack[Temp->top] = NULL;
	    Temp->top --;
	{
	print(p,room);
	if((W->head != W->rear) && Enter->top < MAX)
        {
            q = W->head->next;
	    t = q->next;
	    Enter->top ++;
	    printf("\n便道的%s号车进入车场的第%d位置。",t->num,Enter->top);
	    printf("\n请输入现在的时间/**:**/:");
	    scanf("%d:%d",&(t->reach.hour),&(t->reach.min));
	    W->head->next = q->next;
	    if(q == W->rear)
		W->rear = W->head;
	    Enter->stack[Enter->top] = t;
	    free(q);
	}
	else
	{
	    printf("\n便道没有车");
        }
    }
    else
    {
	 printf("\n车场里没有车。");
    }
}
void list1(SeqStackCar *S)
{
    int i;
    if(S->top > 0
    {
        printf("\n车场：");
	printf("\n位置 到达时间 车牌号\n");
	for(i = 1; i <= S->top; ++i)
	{
	    printf(" %d ",i);
	    printf("%d:%d ",S->stack[i]->reach.hour,S->stack[i]->reach.min);
	    puts(S->stack[i]->num);
	}
   }
   else
   {
       printf("\n车场里没有车。")
   }
}
void list2(LinkQueueCar *W)
{
    QueueNode *p;
    p = W->head->next;
    if(W->head != W->rear)
    {
	printf("\n等待车辆号码为：");
	while(p != NULL)
	{
	    puts(p->data->num);
	    p = p->next;
	}
    }
    else
    {
	printf("\n便道里没有车。");
    }
}
void list(SeqStackCar S,LinkQueueCar W)
{
    int flag,tag;
    flag = 1;
    while(flag)
    {
	printf("\n请选择 1|2|3:");
	printf("\n1.车场\n2.便道\n3.返回\n");
	while(1)
	{
	    scanf("%d",&tag);
	    if(tag >= 1 || tag <= 3)
	    {
		break;
            }
	    else
	    {
		printf("\n请选择 1|2|3:");
	    }
      }
      switch(tag)
      {
      case 1:
	  list1(&S);
	  break;
      case 2:
	  list2(&W);
	  break;
      case 3;
          flag = 0;
	  break;
      default:
	  break;
      }
   }
}
