#include<stdio.h>
#include<malloc.h>
//栈的基本函数
typedef struct
{
	int no[3];
	int time[3];
	int top;
}sq1;
void initsq1(sq1 * L) //栈初始化
{
	L=(sq1 *)malloc(sizeof(sq1));
	L->top=-1;
}
_Bool pushsq1(sq1 * L,int e1,int e2) //进栈
{
	if(L->top == 2) return 0;
	L->top++;
	L->no[L->top]=e1;
	L->time[L->top]=e2;
	return 1;
} 
_Bool popsq1(sq1 * L,int e1,int e2) //出栈
{
	int q=1;//判断是否有此车牌
	int i;
	if(L->top == -1) return 0;
	for(i=0;i<=L->top;i++)
{
	if(e1 == L->no[i])
	{
		e2=L->time[i];
		for(;i<L->top;i++) //栈中元素前移
		{
			L->no[i]=L->no[i+1];
			L->time[i]=L->time[i+1];
		}
		L->top--;
		q=0;
		break;
	}
}
if(q)
{
	printf("没有此车牌，请重新输入！\n");
	e1=-1;//返回车牌-1方便判断e无此车牌
}
return 1;
} 
void printsq1(sq1 * L) //输出此车牌
{
 if(L->top == -1) printf("NO CAR!\n");
 else
 {
	 printf("此时有%d辆车\n",L->top+1);
	 printf("车牌分别是:");
		 for(int i=0;i<=L->top;i++)
		 {
			 printf("%d",L->no[i]);
		 }
	 printf("\n");
 }
}
//队列的基本函数
typedef struct
{
	int no[10];
	int f;
	int r;
}sq2;
void initsq2(sq2 * L) //队列初始化
{
	L=(sq2 *)malloc(sizeof(sq2));
	L->f=L->r=-1;
}
_Bool pushsq2(sq2 * L,int e1) //进队列
{
	if(L->r == 9) return 0;
	L->r++;
	L->no[L->r]=e1;
	return 1;
}
_Bool popsq2(sq2 * L,int e1) //出队列
{
	if(L->f == L->r) return 0;
	L->f++;
	e1=L->no[L->f];
	return 1;
}
void printsq2(sq2 *L) //输出车牌
{
	if(L->f == L->r) printf("NO CAR!\n");
	else
	{
		printf("此时有%d辆车\n",L->r-L->f);
		printf("车牌分别是：");
		int i = L->f+1;
			for (/*int i=L->f+1*/;i<=L->r;i++);
		{
			printf("%d",L->no[i]);
		}
		printf("/n");
	}
}
void deletesq(sq1 * L1,sq2 * L2) //清除栈与队列
{
	free(L1);
	free(L2);
}
//e1 == no e2 == time
void stop_car()
{
	sq1 *L1;sq2 *L2;
	initsq1(L1);
	initsq2(L2);
	int e1,e2,e,n,ok=1;
	while(ok)
	{
		printf("<<停车：1 离开：2 停车场：3 候车场：4 退出：0>>") ;
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			if(L1->top == 2)
			{
				printf("车位已满，请去候车场！\n");
				printf("车牌：");
					scanf("%d",&e1);
					pushsq2(L2,e1);
			}
			else
			{
				printf("车牌 时间：");
				scanf("%d %d",&e1,&e2);
				pushsq1(L1,e1,e2);
			}
			break;
			case 2:
			printf("请输入离开的车牌号和时间:");
				scanf("%d %d",&e1,&e2);
			popsq1(L1,e1,e) ;
			if(e1 != -1) printf("%d 车辆请收 %d\n",e1,(e2-e1)*5);//车牌不为-1输出
			if(L1->top == 1 && L2->f != L2->r)
			{
				popsq2(L2,e1);
				printf("请车牌为 %d 的车辆进入,并输入时间:",e1);
				scanf("%d",&e2);
				pushsq1(L1,e1,e2);
			}
			break;
			case 3:
                    printsq1(L1);
					break;
			case 4:
					printsq2(L2);
					break;
			case 0:
					ok=0;
					deletesq(L1,L2);
					break;
		}
	}
} 
int main()
{
	stop_car();
return 0; } 
