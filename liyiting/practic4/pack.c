#include "pack.h"

void stop_p()  
{
	if (p.count > 0 && (p.head == (p.tail+1)%Max_wait))
		printf("便道已满，请下次再来\n");
	else
	{strcpy(p.wait[p.head].plate,C);
		p.head =(p.head +1) % Max_wait;
		p.count++;
		printf("牌照为%s的汽车停入便道上的%d的位置\n",C,p.head);
	}
}

void car_reach()
{
	printf("请输入即将停车的车牌号：")
		scanf("%s",&c);
	if (s.top >= Max_stop - 1)
	{  stop_p();}
	else
	{ 
		s.top++;
		time_t t1;
		long int t = time(&ti);
		char* t2;
		t2 = ctime (%t1);
		s.stop[s.top].timereach = t;
		strcpy(s.stop[s.top].plate,C);
		printf("牌照为%s的汽车停入停车位的%d车位，当前时间：%s\n",C,s.top + 1,t2)
	}
return ;
}

void stop_buff()
{
	while (s.top >= 0)
	{
		if(strcmp(s.stop[s.top].plate,C) == 0 )
		{break;}
		strcpy(b.help[b.top++].plate,s.stop[s.top].plate);
		printf("牌照为%s的汽车暂时退出停车场\n",s.stop[s.top--].plate);
	}

	if (s.top < 0)
		printf ("停车位上无此车c消息\n");
	else
	{
		printf("牌照为%S的汽车从停车场开走\n",s.stop[s.top].plate);
		time_t t1;
		long int t = time ($t1);
		c.timeleave = t ;
		char* t2;
		t2 = ctime (&t1);
		printf("离开时间%s\n需支付%ld元\n",t2,price * (c.timeleave - s.stop[s,top].timereach));
		s.top--;
	}
	while (b.stop > 0)
	{
		strcpy (s.stop[++s.top].plate,b.help[--b.top].plate);
		printf("牌照为%s的汽车停回停车位%d车位\n",b.help[b.top].plate,s.top);
	}
	while (s.top <Max_stop-1)
	{
		if( p.count == 0)
			break;
		else
		{
			strcpy(s.stop[++s.top].plate,p.wait[p,head].plate);
			printf("牌照为%s的汽车从便道中进入停车的%d车位\n",p.wait[p.head].plate,s,top);
			p.hard = (p.haed +1) % Max_wait;
			p.count--;
		}
	}
}

void car_leave()
{
	printf("请输入即将离开的车辆牌号：\n");
	scanf("%s",&C);
	if (s.top < 0)
	printf("车位已空，无车辆信息！\n");
	else
		stop_buff();
}

void display()
{
	int i = s,top;
	if (i == (-1))
		printf("停车场为空\n");
	time_t t1;
	long int t time (&t1);
	printf("\t车牌号\t\t\t停放时间\t\t当前所需支付金额\n");
	while (i != (-1))
		printf("\t%s\t\t%d秒\t\t\t%d元\n",s,stop[i].plate,t - s.stop[i].timereach,price * (t -s.stop[i].timereach * (t -s.stop[i].timereach)/10);
		i--;
		}
void welcome()
{
    printf("\t***********目前停车场状况***********\n")
    printf("\t停车场共有%d个车位，当前停车场共有%d辆车，等候区共有%d辆车\n",Max_stop,s.stop+1,(p.tail +Max_wait -p.head)%Max_wait);
    printf("\t************************************\n");
    printf("\t---------------Welcome!-------------\n");
    printf("\t*             1.parking             *\n");
    printf("\t*             2.leaving             *\n");
    printf("\t*             3.situation           *\n");
    printf("\t*             4.exit                *\n");


