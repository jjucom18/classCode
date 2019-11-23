#include"parkingstack.c"
#include"parkingqueue.c"


int main()
{
int comm;
int no,e1,time,e2;
int i,j,t;
SqStack St,St1; //St是停车场，St1是在有车离开时，记录为该车移开位置的车辆
SqQueue Qu; //Qu是候车场
InitStack(St);
InitStack(St1);
InitQueue(Qu);
do
{
printf("输入指令(1:到达 2:离开 3:显示停车场 4:显示候车场 0:退出):");
scanf("%d",&comm);
switch(comm)
{
case 1: //汽车到达
printf("输入车号和时间(设车号和时间均为整数): ");
scanf("%d%d",&no,&time);
if (!StackFull(St)) //停车场不满
{
Push(St,no,time);
printf(" >>停车场位置:%d\n",St->top+1);
}
else //停车场满
{
if (!QueueFull(Qu))//候车场不满
{
enQueue(Qu,no);
printf(" >>候车场位置:%d\n",Qu->rear);
}
else
printf(" >>候车场已满,不能停车\n");
}
break;
case 2: //汽车离开
printf("输入车号和时间(设车号和时间均为整数): ");
scanf("%d%d",&no,&time);
for (i=0; i<=St->top && St->CarNo[i]!=no; i++); //在栈中找
if (i>St->top)
printf(" >>未找到该编号的汽车\n");
else
{
t = St->top - i; //需要出栈的车辆数目
for (j=0; j<t; j++) //for (j=i; j<=St->top; j++)1楼评论讲的原错误写法
{
Pop(St,e1,e2);
Push(St1,e1,e2); //倒车到临时栈St1中
}
Pop(St,e1,e2); //该汽车离开
printf(" >>%d汽车停车费用:%d\n",no,(time-e2)Price);
while (!StackEmpty(St1)) //将临时栈St1重新回到St中
{
Pop(St1,e1,e2);
Push(St,e1,e2);
}
if (!QueueEmpty(Qu)) //队不空时,将队头进栈St
{
deQueue(Qu,e1);
Push(St,e1,time); //以当前时间开始计费
}
}
break;
case 3: //显示停车场情况
if (!StackEmpty(St))
{
printf(" >>停车场中的车辆:"); //输出停车场中的车辆
DispStack(St);
}
else
printf(" >>停车场中无车辆\n");
break;
case 4: //显示候车场情况
if (!QueueEmpty(Qu))
{
printf(" >>候车场中的车辆:"); //输出候车场中的车辆
DispQueue(Qu);
}
else
printf(" >>候车场中无车辆\n");
break;
case 0: //结束
if (!StackEmpty(St))
{
printf(" >>停车场中的车辆:"); //输出停车场中的车辆
DispStack(St);
}
if (!QueueEmpty(Qu))
{
printf(" >>候车场中的车辆:"); //输出候车场中的车辆
DispQueue(Qu);
}
break;
default: //其他情况
printf(" >>输入的命令错误\n");
break;
}
}
while(comm!=0);
return 0;
}
