#include "parking.h"
#include<stdio.h>
 #include<stdlib.h>
 #include<unistd.h>
 #include<string.h>
 #define MAX 50       //  停车场最大容量为5辆，便于观察
 #define price 0.1    //  定义停车费
 
 void InitStack(SeqStackCar *s){   // 栈的初始化
int i;
s->top=0;
for(i=0;i<=MAX;i++)
s->stack[s->top]=NULL; }
int InitQueue(LinkQueueCar *Q){     // 队列的初始化
Q->head=(QueueNode *)malloc(sizeof(QueueNode));
    if(Q->head!=NULL)
    {
        Q->head->next=NULL;
        Q->rear=Q->head;
        return(1);
    }
    else return(-1);
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
 printf("\n应交费用为: %2.1f元",((B1-A1)*60+(B2-A2))*price);
      free(p); }       // 车辆的到达登记

 int Arrival(SeqStackCar *Enter,LinkQueueCar *W){
        CarNode *p;
        QueueNode *t;
        p=(CarNode *)malloc(sizeof(CarNode));
       // flushall();
        printf("\n请输入车牌号(例:豫B1234):\n");
         scanf("%s",p->num);
 
          if(Enter->top<MAX)
            {
            Enter->top++;
          printf("\n车辆在车场第%d位置.",Enter->top);
          printf("\n车辆到达时间:");
          scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
          Enter->stack[Enter->top]=p;
            return(1);
             }
              else
        {
             printf("\n该车须在便道等待!有车位时进入车场");
                 t=(QueueNode *)malloc(sizeof(QueueNode));
                   t->data=p;
                     t->next=NULL;
                       W->rear->next=t;
                         W->rear=t;
                         return(1);
                         }
                          }

void Leave(SeqStackCar *Enter,SeqStackCar *Temp,LinkQueueCar *W)
{
    //车辆的离开
int room;
 CarNode *p,*t;
  QueueNode *q;
   if(Enter->top>0)         //  判断车场是否为空
   {
        while(1)
        {
        printf("\n请输入车在车场的位置/1--%d/：",Enter->top);
    scanf("%d",&room);
    if(room>=1&&room<=Enter->top) break;
    else printf("\n 输入有误,请重输: ");
     }
     while(Enter->top>room)   //  把要删除的车辆的前面的车开出来，进临时栈。
        {
            Temp->top++;
     Temp->stack[Temp->top]=Enter->stack[Enter->top];
             Enter->stack[Enter->top]=NULL;
                  Enter->top--;
        }
         p=Enter->stack[Enter->top]; //  把要删除的车辆节点赋给p。
           Enter->stack[Enter->top]=NULL;
            Enter->top--;
             while(Temp->top>=1)     //  再把临时栈里德车辆进停车场
            {
            Enter->top++;
            Enter->stack[Enter->top]=Temp->stack[Temp->top];
            Temp->stack[Temp->top]=NULL;
            Temp->top--;
             }
             PRINT(p,room);      //   调用计费函数计费。。
              if((W->head!=W->rear)&&Enter->top<MAX) //如果便道上有车，则再开进停车场。
            {
                q=W->head->next;
                t=q->data;
                Enter->top++;
                printf("\n便道的%s号车进入车场第%d位置.",t->num,Enter->top);
                printf("\n请输入%s号车进入车场的时间:",t->num);
                scanf("%d:%d",&(t->reach.hour),&(t->reach.min));
                W->head->next=q->next;
                if(q==W->rear) W->rear=W->head;
                  Enter->stack[Enter->top]=t;
                    free(q);
            }
               else printf("\n便道里没有车.\n");
        }
            else printf("\n车场里没有车.");
        }
        void List1(SeqStackCar *S)   //显示车场里的车辆情况
        {
             int i;
            if(S->top>0)
        {
            printf("\n车场:");
            printf("\n 位置  到达时间    车牌号\n");
            for(i=1;i<=S->top;i++)
        {
        printf("  %d   ",i);
        printf("  %d:%d     ",S->stack[i]->reach.hour,S->stack[i]->reach.min);
        puts(S->stack[i]->num);
        }
        }
        else printf("\n车场里没有车");
        }
        void List2(LinkQueueCar *W)     //显示便道上的车辆情况
        {
             QueueNode *p;
              int i;
            p=W->head->next;
        if(W->head!=W->rear)
        {
        printf("\n等待车辆的号码为:");
        for(i=1; (p!=NULL); i++)
        {
        printf("\n第 %d 车辆.",i);
        puts(p->data->num);
        p=p->next;
        }
         }
         else printf("\n便道里没有车.");
        printf("\n");
         }
         void List(SeqStackCar S,LinkQueueCar W)  //显示,遍历
        {
        int flag,tag;
        flag=1;
         while(flag)
        {
            printf("   查看车辆列表显示:  ");
            printf("\n 1.车场列表\n 2.便道列表\n 3.返回主菜单\n");
            printf("\n请选择 1~5:");   while(1)
        {
            scanf("%d",&tag);
            if(tag>=1 && tag<=5) break;
            else printf("\n 输入有误,请重新选择 1~5:");
            }
            switch(tag)
            {
                 case 1:List1(&S);break;
                   case 2:List2(&W);break;
                    case 3:flag=0;  system("cls");  break;
                     default: break;
                      }
                }
            }

void menu()
	{
     SeqStackCar Enter,Temp;
     LinkQueueCar Wait;
      int ch;
      system("color 1A");
      InitStack(&Enter);
       InitStack(&Temp);
        InitQueue(&Wait);
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
    case 1:Arrival(&Enter,&Wait);
     break;
     case 2:Leave(&Enter,&Temp,&Wait);
     break;
     case 3:List(Enter,Wait);break;
     case 4:exit(0);
default: break;
 }
 }
}   

