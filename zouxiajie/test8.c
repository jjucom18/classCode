#include<stdio.h>
#include<string.h>
#define N 3  /*ͣ������С*/
#define MAX 50 /*������С*/
#define sign 10/*���ƴ�С*/
#define price 5/*ÿ���ӵļ�Ǯ*/
char part[N][sign];
char Rpart[MAX][sign];
char time[N][20];
int P,R;
partadd(char *t)
{
	strcpy(&part[P][0],t);
	printf("������ʱ�䣺����ʮ��ʮ�ָ�ʽΪ��10.10��\n");
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
		printf("�����������޷�ͣ����\n");
	}
}
newcar()
{
	char temp[sign];
	printf("�����복�ƺţ�");
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
	printf("���������ڵ�ʱ�䣺����ʮ��ʮ�ָ�ʽΪ��10.10��\n");
	scanf("%s",t);
	getchar();
	money=timed(t,&time[i][0]);
	printf("�շ�%d\n",money);
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
	printf("����Ҫ�뿪�ĳ��ƺţ�");
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
		printf("���޴˳���\n");
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
		printf("��ѡ��Ҫ�����£�\n");
		printf("1.�����³���\n");
		printf("2.�г��뿪��\n");
		printf("3.��ʾ��ͣ�����ڵĳ���\n");
		printf("4.��ʾ�ڹ����ϵĳ���\n");
		printf("5.�˳���\n");
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