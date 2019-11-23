#include "tests.h"
#include<stdio.h>

void main()
	{int command;
	       int num,i,time,j;
       int m,n;
SeqStack *s1,*s2;SeqQueue *q;InitStack(s1);InitStack(s2);InitQueue(q);
while(1)
{printf("please input command(1:arrive   2:leave   3:exit):\n");
	while (1) scanf("%d",&command);
	if(command>=1&&command<=3) break;
	else
	switch(command)
	{case 1:printf("arrive time:  ");  scanf("%d",&num,&time);
		if(!StackFull(s1))
				{push(s1,num,time);printf("park location:%d\n",s1->top+1);}
				else {if(!QueueFull(q))
				{InQueue(q,num);printf("location of waiting area:%d\n",q->rear);}
				else printf("Location of waiting area is full\n");}
	break;
	case 2:printf ("leave time:   ");scanf("%d%d",&num,&time);
	for (m=0;m<=s1->top&&s1->CarNum[m]!=num;m++);
	       if(m>=s1->top)
		       printf("The car was not found\n");
	       else {for (n=m;n<=s1->top;n++)
	{pop(s1,i,j);push(s2,i,j);}
	pop(s1,i,j);printf("%d price of packing:%d\n",num,(time-j)*price);
	while (!StackEmpty(s2))
	{pop(s2,i,j);push(s2,i,j);}
	if(!QueueEmpty(q))
	{OutQueue(q,i);push(s1,i,time);}}
			break;
	case 3:if(!StackEmpty(s1)) 
	       {printf("停车场的车辆：");
		       DispStack(s1);}
		       if(!QueueEmpty(q)) 
		       {printf("候车场的车辆：");
			       DispQueue(q);}break;
	default:
	       break;}
	}}
	
