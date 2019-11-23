#include<stdio.h>
#include<string.h>
#define N 3  /*停车场大小*/
#define MAX 50 /*过道大小*/
#define sign 10/*车牌大小*/
#define price 5/*每分钟的价钱*/
char part[N][sign];
char Rpart[MAX][sign];
char time[N][20];
int P,R;
partadd(char *t)
{
	strcpy(&part[P][0],t);
	printf("请输入时间：例如十点十分格式为“10.10”\n");
	scanf("%s",&time[P][0]);
	getchar();
	P++;
}
Rpartadd(char *t)
{
	if(R<MAX)
	{
		strcpy(&Rpart[R][0],t);
		R++;
	}
	else
	{
		printf("过道己满。无法停车。\n");
	}
}
newcar()
{
	char temp[sign];
	printf("请输入车牌号：");
	scanf("%s",temp);
	getchar();
	if(P<N)
	{
		partadd(temp);
	}
	else if(R<MAX)
	{
		Rpartadd(temp);
	}
}
int timed(char *t1,char *t2)
{
	int i=0,y=0,x=0,j,n=1;
	while(1)
	{
		if(t1[i]=='.')
		{
			for(j=i-1;j>=0;j--)
			{
				y=y+(t1[j]-'0')*(60*n);
				n=n*10;
			}
			while(1)
			{
				if(t1[j]==NULL)
				{
					for(n=1;j>i;j--)
					{
						y=y+(t1[j]-'0')*n;
						n=n*10;
					}
					break;
				}
				j++;
			}
			i=0;
			while(1)
			{
				if(t2[i]=='.')
				{
					for(j=i-1;j>=0;j--)
					{
						x=x+(t2[j]-'0')*(60*n);
						n=n*10;
					}
					while(1)
					{
						if(t2[j]==NULL)
						{
							for(n=1;j>i;j--)
							{
								x=x+(t2[j]-'0')*n;
								n=n*10;
							}
							break;
						}
						j++;
					}
					y=(x-y)*price;
					return y;
				}
				i++;
			}
		}
		i++;
	}
}
partcarout(int i)
{
	int j,money;
	char t[20];
	printf("请输入现在的时间：例如十点十分格式为“10.10”\n");
	scanf("%s",t);
	getchar();
	money=timed(t,&time[i][0]);
	printf("收费%d\n",money);
	for(j=i;j<P;j++)
	{
		strcpy(&part[j][0],&part[j+1][0]);
		P--;
	}
	if(R!=0)
	{
		strcpy(&part[N-1][0],&Rpart[0][0]);
		P++;
		strcpy(&time[P][0],t);
		Rpartcarout(0);
	}
}
Rpartcarout(int i)
{
	int j;
	for(j=i;j<R;j++)
	{
		strcpy(&Rpart[j][0],&Rpart[j+1][0]);
		R--;
	}
}
carout()
{
	char t[sign];
	int i,get=0;
	printf("请入要离开的车牌号：");
	scanf("%s",t);
	getchar();
	for(i=0;i<P;i++)
	{
		if(strcmp(t,&part[i][0])==0)
		{
			get=1;
			partcarout(i);
			break;
		}
	}
	for(i=0;i<R&&get==0;i++)
	{
		if(strcmp(t,&Rpart[i][0])==0)
		{
			get=1;
			Rpartcarout(i);
			break;
		}
	}
	if(get==0)
	{
		printf("查无此车。\n");
	}
}
jopart()
{
	int i;
	for(i=0;i<P;i++)
	{
		printf("%d.%s\n",i,&part[i][0]);
	}
}
joRpart()
{
	int i;
	for(i=0;i<R;i++)
	{
		printf("%d.%s\n",i,&Rpart[i][0]);
	}
}
main()
{
	int c;
	while(1)
	{
		printf("请选择要做的事：\n");
		printf("1.加入新车。\n");
		printf("2.有车离开。\n");
		printf("3.显示在停车场内的车。\n");
		printf("4.显示在过道上的车。\n");
		printf("5.退出。\n");
		c=getchar();
		getchar();
		switch (c)
		{
		case '1':newcar();
			break;
		case '2':carout();
			break;
		case '3':jopart();
			break;
		case '4':joRpart();
			break;
		case '5':exit(1);
			break;
		}
	}
}