#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define n 3
int vip1=0;
int y,z;
float sum1=0,sum2=0,sum3=0,sum4=0,sum5=0;
float i1=0,i2=0,i3=0,i4=0,i5=0;
float ave1=0,ave2=0,ave3=0,ave4=0,ave5=0;
static int N;
struct List{
	int A[n+1];
	int len;
}L;
struct Lnode{
	int data;
	Lnode *next;
};
struct Linkqueue{
	Lnode *front;
	Lnode *rear;
}Q;

void Initshuzu()
{
	for(int i=1;i<n;i++)
		L.A[i]=0;
	L.len=0;
}

void Initqueue()
{
	Q.front=Q.rear=(Lnode *)malloc(sizeof(Lnode));
	Q.front->next=NULL;
}

void Enqueue(Linkqueue *Q,int elem)
{
	Lnode *s;
	s=(Lnode *)malloc(sizeof(Lnode));
	s->data=elem;
	s->next=NULL;
	Q->rear->next=s;
	Q->rear=s;
}

int Dlqueue(Linkqueue *Q)
{
	Lnode *t;
	int x;
	if(Q->front==Q->rear)
	{
		printf("队列为空!\n");
		exit(1);
	}
	else
	{
		t=Q->front->next;
		Q->front->next=t->next;
		x=t->data;
		free(t);
		return x;
	}
}

void print1()
{
	int i;
	printf("正在办理业务的顾客编号为: \n");
	for(i=1;i<=L.len;i++)
	{
		printf("%d ",L.A[i]);
	}
	printf("\n");
}

void print2()
{
	int i=0;
	printf("正在办理业务的顾客编号为: ");
	Lnode *s=Q.front->next;
	while(s!=NULL)
	{
		printf("%d",s->data);
		s=s->next;
		i++;
	}
	printf("\n您的前面一共有%d人在排队，请您稍后!",i);
	printf("\n");
}

void daoda(int x)
{
	int i=L.len+1;
	if(L.len<n)
	{
		L.A[i]=x;
		i++;
		L.len++;
	}
	else
		Enqueue(&Q,x);
}

void likai(int x)
{
	int i=0;
	do
	{
		if(x>L.len)
		{
			printf("输入有误!\n请重新输入: ");
			scanf("%d",&x);
		}
		else
			for(i=0;i<=L.len;i++)
			{
				if(i==x)
				{
					printf("尊敬的%d号顾客您好!\n",x);
					L.A[i]=0;
					L.len--;
					if(Q.front!=Q.rear)
					{
						int y=Dlqueue(&Q);
						L.A[i]=y;
						L.len++;
					}
				}
			}
	}while(i==0);
}

int guitai()
{
	int y=0;
	printf("请输入你所办理的业务的柜台号（1-3）:\n");
	scanf("%d",&y);
	if(y<1||y>5)
	{
		printf("你输入的柜台号有误，请重新输入!\n");
		printf("请输入你所办理的业务的柜台号（1-3）:\n");
		scanf("%d",&y);
	}
	else
		printf("你所办理的业务的柜台为%d.\n",y);
	return y;
}

int pingfeng()
{
	int y=0;
	printf("请输入你的评分（1-5）:\n   1分…………非常不满意;\n   2分…………比较不满意；\n   3分…………一般满意；\n    4分…………比较满意；\n    5分…………非常满意。\n");
	printf("请输入: ");
	scanf("%d",&y);
	if(y<1||y>5)
	{
		printf("你输入评分有误，请重新输入! \n");
		printf("请输入你的评分（1-5）: \n");
		scanf("%d",&y);
	}
	else
		printf("你的评分为%d.\n",y);
	return y;
}

void mygrade()
{
	printf("为了改善服务质量，请你对我们的服务进行评价。谢谢! \n");
	z=guitai();
	y=pingfeng();
	switch(z)
	{
	case 1:
		{
			sum1+=y;
			i1++;
			ave1=sum1/i1;
			printf("%d号柜台的平均满意度为%0.2f。感谢你的评分，谢谢!!! \n",z,ave1);
			break;
		}
	case 2:
		{
			sum2+=y;
			i2++;
			ave2=sum2/i2;
			printf("%d号柜台的平均满意度为%0.2f。感谢你的评分，谢谢!!! \n",z,ave2);
			break;
		}
	case 3:
		{
			sum3+=y;
			i3++;
			ave3=sum3/i3;
			printf("%d号柜台的平均满意度为%0.2f。感谢你的评分，谢谢!!! \n",z,ave3);
			break;
		}
	case 4:
		{
			sum4+=y;
			i4++;
			ave4=sum4/i4;
			printf("%d号柜台的平均满意度为%0.2f。感谢你的评分，谢谢!!! \n",z,ave4);
			break;
		}
	case 5:
		{
			sum5+=y;
			i5++;
			ave5=sum5/i5;
			printf("%d号柜台的平均满意度为%0.2f。感谢你的评分，谢谢!!! \n",z,ave5);
			break;
		}
	default : printf("你的输入有误，请重新输入! \n");
	}
	getch();
}

void vip(int x)
{
	int i,a;
	a=x;
	char ch[3];
	int k=0;
	switch(a)
	{
	case 1:
		{
			printf("请输入你的卡号：");
			scanf("%d",&i);
			printf("请输入五位密码：");
			while(ch[k-1]!=' ')
			{
				ch[k]=getch();
				k++;
				printf("*");
			}
			if(i==100&&ch[0]=='1'&&ch[1]=='1'&&ch[2]=='1'&&ch[3]=='1')
			{
				printf("\n尊敬的VIP用户您好，请直接到VIP区办理业务!\n");
				vip1++;
			}
			else if(i==200&&ch[0]=='2'&&ch[1]=='2'&&ch[2]=='2'&&ch[3]=='2')
			{
				printf("\n尊敬的VIP用户您好，请直接到VIP区办理业务! \n");
				vip1++;
			}
			else if(i==300&&ch[0]=='3'&&ch[1]=='3'&&ch[2]=='3'&&ch[3]=='3')
			{
				printf("\n尊敬的VIP用户您好，请直接到VIP区办理业务! \n");
				vip1++;
			}
			else if(i==400&&ch[0]=='4'&&ch[1]=='4'&&ch[2]=='4'&&ch[3]=='4')
			{
				printf("\n尊敬的VIP用户您好，请直接到VIP区办理业务! \n");
				vip1++;
			}
			else if(i==500&&ch[0]=='5'&&ch[1]=='5'&&ch[2]=='5'&&ch[3]=='5')
			{
				printf("\n尊敬的VIP用户您好，请直接到VIP区办理业务! \n");
				vip1++;
			}
			else
				printf("\n你的输入有误! \n");
			break;
		}
	default :
		break;
	}
}

void time()
{
	time_t timep;
	time(&timep);
	printf("                      现在时刻: %s",ctime(&timep));
}

void main()
{
	time_t  a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,start,end;
	float b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0,b8=0,b9=0,b10=0,allsum=0,average=0,xi=0;
	float A[10]={0,0,0,0,0,0,0,0,0,0};
	int c,x,v,w=0;
	Initshuzu();
	Initqueue();
	double sum=0;
	while(1)
	{
		printf("\n******************************欢迎光临中国银行*******************************\n");
		printf("\n                              1      顾客到达\n");
		printf("                              2      顾客离开\n");
		printf("                              3      查看业务办理\n");
		printf("                              4      查看排队情况\n");
		printf("                              5      退出\n\n");
		time();
		printf("*******************************欢迎光临中国银行******************************\n");
		printf("请输入: ");
		scanf("%d",&c);
		switch(c)
		{
		case 1:
			{
				system("cls");
				printf("\n*****************顾客到达界面******************************\n\n");
				int k=0;
				int a;
				printf("请选择你的用户类型: VIP用户请按 1; \n                    普通卡用户请按2.\n");
				printf("请输入: ");
				scanf("%d",&a);
				if(a==1)
				{

					vip(a);
					getch();
				}
				else
				{
					v++;
					printf("尊敬的普通卡用户，你的业务号为%d.\n",v);
					daoda(v);
				}
				system("cls");
				break;
			}
		case 2:
			{
				system("cls");
				printf("\n******************顾客离开界面******************************\n\n");
				printf("请输入离开顾客的编号: \n");
				scanf("%d",&x);
				likai(x);
				mygrade();
				w++;
				allsum+=A[0];
				getch();
				system("cls");
				break;
			}
		case 3:
			{
				system("cls");
				printf("\n**********************业务查询界面******************************\n\n");
				print1();
				getch();
				system("cls");
				break;
			}
		case 4:
			{
				system("cls");
				printf("******************排队查询界面***********************\n\n");
				print2();
				getch();
				system("cls");
				break;
			}
		case 5:
				return;
				getch();
				system("cls");
		case 6:
			{
				system("cls");
				printf("\n******************系统查询界面***********************\n\n");
				char cool[3];
				int i=0,k=0;
				printf("请输入你的卡号: ");
				scanf("%d",&i);
				printf("请输入五位密码: ");
				while(cool[k-1]!='\n')
				{
					cool[k]=getch();
					k++;
					printf("*");
				}
				if(i==000&&cool[0]=='1'&&cool[1]=='1'&&cool[2]=='1'&&cool[3]=='1')
				{
					average=allsum/w;
					printf("\n至今已有 %d 位普通用户，%d 位VIP用户成功办理业务!",w,vip1);
					printf("\n普通用户业务办理总共用时 %0.2f,平均用时 %0.2f\n",allsum,average);
				}
				getch();
				system("cls");
				break;
			}
		default:printf("输入有误!请重新输入: \n");
			getch();
			system("cls");
		}
	}
}
