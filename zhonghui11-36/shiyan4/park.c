#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"park.h"
 
void Menu()
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~欢迎使用停车管理系统~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~1、停入车辆     2、车辆离开~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~3、查询车辆信息 4、显示所有车辆~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~5、显示在场车辆 6、显示等待中的车辆~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~7、退出系统~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
 
}
 
void Init(Park **p, Park **r, Wait **w, Park **h)
{
	(*p) = (Park *)malloc(sizeof(Park));
	(*r) = (Park *)malloc(sizeof(Park));
	(*h) = (Park *)malloc(sizeof(Park));
	(*w) = (Wait *)malloc(sizeof(Wait));
 
	if(NULL == (*p) || NULL == (*r) || NULL == (*w) || NULL == (*h))
	{
		printf("malloc failure!\n");
	}
 
	(*p) -> top = NULL;
	(*r) -> top = NULL;
	(*h) -> top = NULL;
	(*p) -> length = 0;
	(*r) -> length = 0;
	(*h) -> length = 0;
 
	Car *wn = (Car *)malloc(sizeof(Car));
	if(NULL == wn)
	{
		printf("ERROR!\n");
	}
	wn -> next = NULL;
	(*w) -> rear = (*w) -> front = wn;
	(*w) -> length = 0;
}
 
int EmptyStack(Park *p)
{
	if(NULL == p)
	{
		return FALSE;
	}
	return(NULL == p -> top)? TRUE: FALSE;
}
 
int FullStack(Park *p)
{
	if(NULL == p)
	{
		return FALSE;
	}
	if(p -> length == P_MAX)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
 
int EnterStack(Park *p, Car *c)
{
	if(NULL == p)
	{
		return FALSE;
	}
	Car *t = (Car *)malloc(sizeof(Car));
	if (NULL == t)
	{
		return FALSE;
	}
	t = c;
	t -> next = p -> top;
	p -> top = t;
	p -> length++;
}
 
Car *PopStack(Park *p)
{
	if(NULL == p)
	{
		printf("ERROR\n");
	}
	Car *tmp = p -> top;
	p -> top = tmp -> next;
	p -> length--;
	return tmp;
}
 
int TraverStackP(Park *p)
{
	if(NULL == p)
	{
		return FALSE;
	}
	Car *c = p -> top;
	while(c)
	{
		printf("车牌号%s 入场时间为%s 正在计时\n", c -> carnum, c -> timein);
		c = c -> next;
	}
	printf("\n");
}
 
int TraverStackH(Park *p)
{
	if(NULL == p)
	{
		return FALSE;
	}
	Car *c = p -> top;
	while(c)
	{
		printf("车牌号%s 入场时间为%s 离开时间为%s 费用为%d\n", c -> carnum, c -> timein, c -> timeout, c -> total);
		c = c -> next;
	}
	printf("\n");
}
int EmptyQueue(Wait *w)
{
	if(NULL == w)
	{
		return FALSE;
	}
	return(w -> length == 0)? TRUE: FALSE;
	
}
int FullQueue(Wait *w)
{
	if(NULL == w)
	{
		return FALSE;
	}
	if(w -> length == W_MAX)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
 
Car *PopQueue(Wait *w)
{
	if(NULL == w || w -> front == w -> rear)
	{
		printf("ERROR\n");
	}
 
	Car *tmp = w -> front -> next;
	w -> front -> next = tmp -> next;
	if (tmp == w -> rear)
	{
		w -> rear = w -> front;
	}
	return tmp;
}
 
int TraverQueue(Wait *w)
{
	if(NULL == w)
	{
		return FALSE;
	}
	Car *c = w -> front ->next;
	while(c)
	{
		printf("车牌%s正在等待入栈\n", c -> carnum);
		c = c -> next;
	}
	printf("\n");
}
 
char *now_time()
{
	time_t timep;
	time(&timep);
	return ctime(&timep);
}
 
int Seconds()
{
	time_t timep;
	return time(&timep);
}
 
int InsertCar(Park *p, Wait *w)
{
	if(NULL == p || NULL == w)
	{
		printf("error!\n");
	}
	if(FullStack(p) == TRUE)
	{
		if(FullQueue(w) == TRUE)
		{
			printf("等候区已满！\n");
		}
		else
		{
			Car *c = (Car *)malloc(sizeof(Car));
			c -> carnum = (char *)malloc(sizeof(char) * 8) ;
			if(NULL == c)
			{
				return FALSE;
			}
			printf("请输入车牌之后进入等待队列：\n");
			scanf("%s", c -> carnum);
			c -> next = NULL;
			w -> rear -> next = c;
			w -> rear = c;
			w -> length++;
			printf("已进入等待队列！\n");
		}
		printf("车库已满！\n");
	}
	else
	{
		Car *c = (Car *)malloc(sizeof(Car));
		c -> carnum = (char *)malloc(sizeof(char) * 8) ;
		c -> timein = (char *)malloc(sizeof(char) * 30) ;
		c -> timeout = (char *)malloc(sizeof(char) * 30) ;
		if(NULL == c)
		{
			return FALSE;
		}
 
		printf("请输入车牌号：\n");
		scanf("%s", c -> carnum);
		
		strcpy(c -> timein, now_time());
		c -> InsertSeconds = Seconds();
		c -> total = 0;
		c -> next = p -> top;
		p -> top = c;
		p -> length++;
		printf("%s已经成功进入停车栈\n",c -> carnum);
	}
}
 
int PopCar(Park *p, Park *r, Wait *w, Park *h)
{
	if(NULL == p || NULL == r || NULL == w || NULL == h)
	{
		return FALSE;
	}
	char *goalnum = (char *)malloc(sizeof(char) * 20);
	printf("请输入需要离开的车牌号：\n");
	scanf("%s", goalnum);
	Car *n = p -> top;
	int count = 0;
	while(n != NULL && strcmp(goalnum, n -> carnum) != 0)
	{
		count++;
		n = n -> next;
	}
	n = p -> top;
 
	if(count == p -> length)
	{
		printf("该车辆不在停车场内！\n");
	}
	else
	{
		while(n)
		{
			if(strcmp(goalnum, n -> carnum) == 0)
			{
				strcpy(n -> timeout, now_time());
				n -> total = (Seconds() - n -> InsertSeconds) * PRICE;
				EnterStack(h, PopStack(p));
				printf("%s已经退出停车栈，费用为%d元\n", n -> carnum, n -> total);
				break;
			}
			EnterStack(r, PopStack(p));
			printf("%s已经退出停车栈，暂时进入让路栈\n",n -> carnum);
			n =  p-> top;//关键问题！！！！！！！
		}
		while(FullStack(p) == FALSE && EmptyStack(r) == FALSE) 
		{
			EnterStack(p, PopStack(r));
			printf("%s已经回到停车栈\n", p -> top -> carnum);
			if(EmptyStack(r) == TRUE)
			{
				printf("让路栈已空！\n");
				break;
			}
		}
	}
	while( EmptyQueue(w) == FALSE && FullStack(p) == FALSE)
	{
		EnterStack(p, PopQueue(w));
		printf("%s已经从候车队列进入停车栈！\n", p -> top -> carnum);
		p -> top -> timein = now_time();
	}
}
 
int QueryCar(Park *p, Wait *w, Park *h)
{
	int flag = 0;
	char *goal = (char *)malloc(sizeof(char));
	if(NULL == p || NULL == h || NULL == w)
	{
		return FALSE;
	}
	printf("请输入想要查找的车牌号：\n");
	scanf("%s",goal);
	Car *p1 = p -> top;
	Car *w1 = w -> front -> next;
	Car *h1 = h -> top;
	while(p1)
	{
		if(strcmp(goal, p1 -> carnum) == 0)
		{
			printf("车牌为%s的车辆正在计时停车，入场时间为%s\n",p1 -> carnum, p1 -> timein);
			flag = 1;
			break;
		}
		p1 = p1 -> next;
	}
	while(w1)
	{
		if(strcmp(goal, w1 -> carnum) == 0)
		{
			printf("车牌为%s的车辆正在等候队列\n",w1 -> carnum);
			flag = 1;
			break;
		}
	}
	while(h1)
	{
		if(strcmp(goal, h1 -> carnum) == 0)
		{
			printf("车辆%s已离开,入场时间%s,离开时间%s,计费%d元\n",h1 -> carnum, h1 -> timein, h1 -> timeout, h1 -> total);
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		printf("没有找到这辆车！\n");
	}
 
}
 
int ListAll(Park *p, Wait *w, Park *h)
{
	if(NULL == p || NULL == w || NULL == h)
	{
		return FALSE;
	}
	TraverStackP(p);
	TraverStackH(h);
	TraverQueue(w);
}

