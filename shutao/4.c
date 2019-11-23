#include<stdlib.h>

#define MAX 3 //停车场最大容量为3辆,便于观察 ^define price 0.05

#define pricee 0.02

typedef struct time{ //定义吋间结构体

int hour; int min;

}Time;

typedef struct node{ //定义车辆信息结构体 char num[10];

Time reach;

Time leave;

}CarNode;

typedef struct NODE{

CarNode *stack[MAX+1]; int

top;

}SeqStackCar;

typedef struct car

{ CarNode 氺data;

struct car 氺next;

}QueueNode;

typedef struct

Node{ QueueNode 氺

head; QueueNode 氺

rear;

}LinkQueueCar;

void lnitStack(ScqStackCar 氺);

int InitQueue(LinkQueueCar *); int Arrival(SeqStackCar LinkQueueCar 氺);

void Leave(SeqStackCar *, SeqStackCar LinkQueueCar *); void

List(SeqStackCar, LinkQueueCar); void main ()

{

SeqStackCar Enter,Temp;

LinkQueueCar Wait; int ch;

system(〃color 4A〃);

TnitStack(&Rnter);

InitStack(&Temp);
TnitQueue(&Wait); whi

le (1)

{

printf (〃\n ?※?※?※?※?※?欢迎使用停车场系统.?※?※?※?

zz※ ? ※ ? \t\n\n);

车辆到达登记.; 1. pr i n t f("\n\t ################

z,pri n t f (\n \ t ################ 2. 车辆离开登记.林醐醐觀灘漏\t\n") •’

pr i n t f("\n\t ################ 3. 车辆列表显示.醐醐醐林醐醐\t\n");

printf C\n\側醐林醐林醐醐 wh i1e(1) 4. 退出系统. 醐醐林醐誦醐\t\n\n");

{

printf ("请选择:〃); scanf

(〃%d",&ch);

if(ch>=l&&ch<=4)break; else

printf(〃\n 输入冇误,

请重新选择:广4: 〃); }

swi tch(ch)

{

case 1:Arrival(&Enter, &Wait);

break;



case 2:Leave(&Enter, &Temp, &Wait);break; case

3:List(Enter, Wait);break; case 4:exit(0);

default: break;

// Pl定义函数

void InitStack(SeqStackCar *s) { // 栈的初始化

int i;

s->top=0;

for(i二0;i<=MAX;i++)

—s〉stack[s->top]=NULL;

int InitQueue(LinkQueueCar *Q) { // 队列的初姑化

Q->hcad=(QucueNode *)ma1loc(sizeof(QueueNode));

if(Q->head!=NULL)

{

Q->head->next=NULL;
Q-〉rear=Q-〉head;

return (1);

}

else return(-1);

}

float PRINTE(CarNode *p, int room) { // 车辆收费

int Al, A2,B1,B2;

printf ("\n车辆离开便道的时fuj;

vz,scanf (%d:%d, & (p->leave. hour), & (p->leave. min)); printf ("\n离开车辆的车牌号为; puts(p-〉num);

printf (〃\n 其到达便道时间为:%d:%d",p->reach. hour, p->reach. min); printf

("\n 离开便道时间为:%d:%d〃,p-〉leave, hour, p->leave, min); Al=p->reach.hour;

A2二p-〉reach, min;

Bl=p->leave.hour;

B2=p->leave. min;

printf (〃\n 应交费川为:,2. If 元〃,((Bl-Al)*60+(B2-A2))*pricee); return(((Bl-Al)*60+(B2-A2))*pricee); free(p);

}

void PRINT(CarNode *p, int room) { // 车辆收费

int Al, A2,B1,B2;

printf C\n车辆离开的时间<);

scanf("%d:%cT,&(p->leave. hour), &(p->leave. min)); printf C\n离开车辆的车

牌号为<); puts(p^>num);

printf (〃\n 其到达停车位时间为:%d:%d〃,p->reach. hour, p->reach. min); printf ("\n 离开停车位时间为:%d:%d", p->leave, hour, p->leave, min); Al=p->reach. hour;

A2=p->reach. min;

Bl=p->1eave.hour;

B2=p->leave. min;

printf (〃\n 应交费用为:,2. If 元' ((Bl-Al) *60+ (B2-A2))*price+PRINTE(p, room)); free

(p);

//车辆的到达?记

int Arrival(SeqStackCar 氺Enter,LinkQueueCar 氺W){
CarNode *p;

QueueNode *t;

p=(CarNode 本)malloc(sizeof(CarNode)); flushall ();

z,printf (\n清输入车牌号(例:豫BI 234):〃);

gets(p-〉num);

if(Enter->top<MAX)

{

Enter一〉top+十;

printf (〃\n 车辆在车场觉,d 位置.〃,Enter->top);

printf C\n车辆到达时间:"k

scanf(〃%d:%d〃, &(p-〉reach. hour), &(p->reach. min));

Enter-〉stack[Enter-〉top]二p; return (1); }

else

{

printf ("\n该车须在便道等特!有车位时进入车场"); t

二(QueueNode *)malloc(sizeof(QueueNode)); t->data=p;

t->next=NULL;

W->rcar->ncxt=t;

W->rear=t;

printf ("请输入进入便道的时间");

scanf("%d:%cT, &(p->reach. hour), &(p-〉reach. min));

return (1):

void Leave(SeqStackCar *Enter, SeqStackCar *Temp, LinkQueueCar *W) { //车辆的离不 int room;

CarNode 氺p,本t;

QueueNode 氺q;

if (Enter->top〉0) //判断车场是否为空

{

while (1)

printf :〃\n 请输入车‘在车场的位置/l~%d/:〃,Enter-〉top:;

scanf (〃,d〃,&room);

z:if(room>=l&&room<Rnter->top) break; else printf(〃\n输入

有误,请重输:");

while(Enter->top>room) //把要删除的车辆的前面的车开出来,进临吋栈。 {
Temp->top++;

Temp-〉stack[Temp-〉top]=Enter->stack[Enter-〉top];

Enter->stack[Enter->top]=NULL;

Enter-〉top--;

}

p=Enter-〉stack[Enter-〉top]; //把要删除的车辆节点赋给p。

Enter->stack[Enter-〉top]二NULL;

Enter->top--;

while (Temp->top>=l) //再把临时栈里徳车辆进停车场 {

Enter-〉top++;

Enter-〉stack[Enter->top]二Temp-〉stack[Temp->top];

-Temp->stack[Temp〉top]=NULL;

Temp-〉top--;

}

PRINT(p, room) ; // 调用计费函数计费。。

if ((W->head! =W->rear)&&Enter->top<MAX) //如果便道上4•车,则再开进停车场。

{

q=W->head->ncxt: t二q-〉data;

Enter—〉top++;

printf (〃\n 便道的,s 号牢进入车•场访,d 位置.〃,t->num, Enter->top);

printf C\n请输入%s号车进入车场的时间:",t->num);

scanf (〃,d:%d〃, &(卜〉reach, hour), &(卜〉reach, min));

// t-〉leave - hour =t-〉reach, hour;

//t->leave • min =t-〉reach. min;

W->head->next=q->next; if(q==W->rear)

W->rear=W-〉head;

Enter-〉stack[Enter-〉top]=t;

PRINTE(t, room); free(q);

}

else printf ("\n 便道里没有车.\n");

}

else printf ("\n车场里没有车.;

void Listl (SeqStackCar *S) //AA示:午:场里的午:辆情况

{

int i;

if(S->top〉0)

{

printf (〃\n 车场:〃);

printf("\n位昔到达吋间 车牌号\n"); for(i=l;i

〈=S_>top;i++)

{

printf (〃 ,d 〃,i);
printf(〃 %d:%d

〃,S->stack[i]->reach. hour, S-〉stack[i]-〉reach. min);

puts (S->stack[i]->num);

}

>

else printf (〃\n车场里没有车〃);

}

void List2(LinkQueueCar *W) //显示便道上的车辆惜况

{

QueueNode 氺p; int i;

p=W->head->next; if(W->head!=W-〉rear)

{

printf ("\n等待车辆的号码为:"); for(i=l;

(p!=NULL); i++)

{

printf (〃\n 第 ,d 牢辆.〃,

i); puts (p->data->num);

p=p->next ;

}

}

else printf ("\n便道里没有车;

printf(〃\n");

} void List (SeqStackCar S, LinkQucucCar W) //ffi不•,遍历 int flag, tag; flag=l; while(flag)

printfC 查看车辆列表显示:");

printf(〃\n 1.车场列表\n 2.便道列表\n 3.返回主菜单\n");

printf(〃\ri 请选择 while (1)

{

scanf(〃,d〃,&tag);

if(tag>=l && tag<=3) break;

else printfC\n输入有误,请重新选择1〜3:〃);

}

switch(tag)

{

case 1:List 1(&S);break;

case 2:List2(&W);break;

case 3:f1ag=O; system(〃cls〃); break;

default: break;

