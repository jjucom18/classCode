#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>
 
#define MaxSize 100     
#define VISITED 1       
#define NOTVISITED 0    
#define Infinite 1073741823  
#define MaxViewNum 50     /*����������50*/
#define MaxRoad 1000      /*����·��Ϊ�����*/
#define N 13             /*Ŀǰ�������*/
 
typedef struct
{
    char name[30];          /*��������*/
    char number[10];        /*�������*/
    char introduce[200];    /*�������*/	
}Elemtype;                  /*������Ϣ*/
 
typedef struct
{
    int num;              /*������*/
    Elemtype date;        /*������Ϣ*/
}View;                    /*���徰��*/
 
typedef struct
{
    View view[MaxViewNum];         /*��Ŷ����һά���飬������㵥Ԫû������*/
    int length[MaxViewNum][MaxViewNum];  /*���·������*/
    int m,n;
}MGraph;
 
MGraph MGr;              /*ȫ�ֱ���,����MGrΪMGraph����*/
int shortest[MaxViewNum][MaxViewNum];     /*����ȫ�ֱ���������С·��*/
int path[MaxViewNum][MaxViewNum];         /*�������·��*/
 
void init()
{
    int i,j;
    MGr.view[1].num=1;
    strcpy(MGr.view[1].date.name,"ѧУ����");
    strcpy(MGr.view[1].date.number,"001");
    strcpy(MGr.view[1].date.introduce,"������ʮ����ǰ����·��");
	
    MGr.view[2].num=2;
    strcpy(MGr.view[2].date.name,"��֪¥");
    strcpy(MGr.view[2].date.number,"002");
    strcpy(MGr.view[2].date.introduce,"����ѧԺ�Լ�����ѧԺ����¥");
	
    MGr.view[3].num=3;
    strcpy(MGr.view[3].date.name,"11������");
    strcpy(MGr.view[3].date.number,"003");
    strcpy(MGr.view[3].date.introduce,"����ѧԺ�󲿷�Ů�����ڵ�����");
	
    MGr.view[4].num=4;
    strcpy(MGr.view[4].date.name,"һʳ��");
    strcpy(MGr.view[4].date.number,"004");
    strcpy(MGr.view[4].date.introduce,"��Ҫ��������ĺ�");
	
    MGr.view[5].num=5;
    strcpy(MGr.view[5].date.name,"��ͼ���");
    strcpy(MGr.view[5].date.number,"005");
    strcpy(MGr.view[5].date.introduce,"��ʷ�ƾã��Ļ�������ͬѧ����ѧϰ�Ļ�������Ҫ�ղص����Ŀ��鼮");
	
    MGr.view[6].num=6;
    strcpy(MGr.view[6].date.name,"��ʳ��");
    strcpy(MGr.view[6].date.number,"006");
    strcpy(MGr.view[6].date.introduce,"��Χ��С�Խֺͳ��С���ݵ�");
	
    MGr.view[7].num=7;
    strcpy(MGr.view[7].date.name,"��ʳ��");
    strcpy(MGr.view[7].date.number,"007");
    strcpy(MGr.view[7].date.introduce,"�ǹ�ģ����ʳ�ã���Ʒ�ḻ");
	
    MGr.view[8].num=8;
    strcpy(MGr.view[8].date.name,"��ʳ��");
    strcpy(MGr.view[8].date.number,"008");
    strcpy(MGr.view[8].date.introduce,"�˼۸ߣ���ζ��������¥��������ʳ��");
	
    MGr.view[9].num=9;
    strcpy(MGr.view[9].date.name,"ѧУ����");
    strcpy(MGr.view[9].date.number,"009");
    strcpy(MGr.view[9].date.introduce,"���źܿ�����������̨");
	
    MGr.view[10].num=10;
    strcpy(MGr.view[10].date.name,"��Զ¥");
    strcpy(MGr.view[10].date.number,"010");
    
	
    MGr.view[11].num=11;
    strcpy(MGr.view[11].date.name,"����¥");
    strcpy(MGr.view[11].date.number,"011");
  
	
    MGr.view[12].num=12;
    strcpy(MGr.view[12].date.name,"24������");
    strcpy(MGr.view[12].date.number,"012");
    strcpy(MGr.view[12].date.introduce,"����");
	
    MGr.view[13].num=13;
    strcpy(MGr.view[13].date.name,"�����ﾶ��");
    strcpy(MGr.view[13].date.number,"013");
    strcpy(MGr.view[13].date.introduce,"��Ҫ���������");
	
    
	
    for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
        {
			MGr.length[i][j]=MaxRoad;
        }
    }
    for(i=1;i<=N;i++)
    {
		shortest[i][j]=0;
    }
    MGr.length[1][3]=MGr.length[3][1]=400;
    MGr.length[2][3]=MGr.length[3][2]=150;
    MGr.length[3][4]=MGr.length[4][3]=100;
    MGr.length[1][5]=MGr.length[5][1]=300;
    MGr.length[2][5]=MGr.length[5][2]=250;
    MGr.length[3][5]=MGr.length[5][3]=100;
    MGr.length[3][7]=MGr.length[7][3]=350;
    MGr.length[6][7]=MGr.length[7][6]=15;
    MGr.length[7][8]=MGr.length[8][7]=25;
    MGr.length[6][12]=MGr.length[12][6]=10;
    MGr.length[6][13]=MGr.length[13][6]=20;
    MGr.length[4][10]=MGr.length[10][4]=60;
    MGr.length[10][11]=MGr.length[11][10]=100;
    MGr.length[8][9]=MGr.length[9][8]=1000;
    MGr.length[3][12]=MGr.length[12][13]=20;
    MGr.length[11][12]=MGr.length[12][11]=340;
	
}
 
void introduce()
{
    int m;
    printf("�������ѯ������:\n");
    scanf("%d",&m); fflush(stdin);
    switch(m)
    {
	case 1:
		printf("������:%s\t",MGr.view[1].date.number);
		printf("��������:%s\n",MGr.view[1].date.name);
		printf("������:%s\n",MGr.view[1].date.introduce);
		break;
	case 2:
		printf("�����ţ�%s\t",MGr.view[2].date.number);
		printf("�������ƣ�%s\n",MGr.view[2].date.name);
		printf("�����飺%s\n",MGr.view[2].date.introduce);
		break;
	case 3:
		printf("�����ţ�%s\t",MGr.view[3].date.number);
		printf("�������ƣ�%s\n",MGr.view[3].date.name);
		printf("�����飺%s\n",MGr.view[3].date.introduce);
		break;
	case 4:
		printf("�����ţ�%s\t",MGr.view[4].date.number);
		printf("�������ƣ�%s\n",MGr.view[4].date.name);
		printf("�����飺%s\n",MGr.view[4].date.introduce);
		break;
	case 5:
		printf("�����ţ�%s\t",MGr.view[5].date.number);
		printf("�������ƣ�%s\n",MGr.view[5].date.name);
		printf("�����飺%s\n",MGr.view[5].date.introduce);
		break;
	case 6:
		printf("�����ţ�%s\t",MGr.view[6].date.number);
		printf("�������ƣ�%s\n",MGr.view[6].date.name);
		printf("�����飺%s\n",MGr.view[6].date.introduce);
		break;
	case 7:
		printf("�����ţ�%s\t",MGr.view[7].date.number);
		printf("�������ƣ�%s\n",MGr.view[7].date.name);
		printf("�����飺%s\n",MGr.view[7].date.introduce);
		break;
	case 8:
		printf("�����ţ�%s\t",MGr.view[8].date.number);
		printf("�������ƣ�%s\n",MGr.view[8].date.name);
		printf("�����飺%s\n",MGr.view[8].date.introduce);
		break;
	case 9:
		printf("�����ţ�%s\t",MGr.view[9].date.number);
		printf("�������ƣ�%s\n",MGr.view[9].date.name);
		printf("�����飺%s\n",MGr.view[9].date.introduce);
		break;
	case 10:
		printf("�����ţ�%s\t",MGr.view[10].date.number);
		printf("�������ƣ�%s\n",MGr.view[10].date.name);
		printf("�����飺%s\n",MGr.view[10].date.introduce);
		break;
	case 11:
		printf("�����ţ�%s\t",MGr.view[11].date.number);
		printf("�������ƣ�%s\n",MGr.view[11].date.name);
		printf("�����飺%s\n",MGr.view[11].date.introduce);
		break;
	case 12:
		printf("�����ţ�%s\t",MGr.view[12].date.number);
		printf("�������ƣ�%s\n",MGr.view[12].date.name);
		printf("�����飺%s\n",MGr.view[12].date.introduce);
		break;
	case 13:
		printf("�����ţ�%s\t",MGr.view[13].date.number);
		printf("�������ƣ�%s\n",MGr.view[13].date.name);
		printf("�����飺%s\n",MGr.view[13].date.introduce);
		break;
	
	default:
		printf("������Ŵ���\n");
		break;
    }
    printf("\n");
}
 
void floyd()                 /*���������㷨*/
{
    int i,j,k;
    for(i=1;i<=N;i++)
    {
		for(j=1;j<=N;j++)
		{
			shortest[i][j]=MGr.length[i][j];
			path[i][j]=0;
		}
    }   /*��ʼ������*/
    for(k=1;k<=N;k++)
    {
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=N;j++)
			{
				if(shortest[i][j]>(shortest[i][k]+shortest[k][j]))
				{
					shortest[i][j]=shortest[i][k]+shortest[k][j];
					path[i][j]=k;
					path[j][i]=k;   /*��¼������·��*/
				}//end_if
			}			
		}//end_for
    }
}
 
void display(int i,int j)
{         /*��ӡ���������·�������·��*/
    int a,b;
    a=i;
    b=j;
    printf("��Ҫ��ѯ������������·���ǣ� \n\n");
    fflush(stdin);
	if(i<j)
	{
		printf("%d",b);
		while(path[i][j]!=0)
		{
			printf("<--%d",path[i][j]);
			if(i<j)
				j=path[i][j];
			else
				i=path[j][i];
		}
		printf("<-%d\n\n",a);
		printf("%d->%d�����·���ǣ� %d �ס�\n\n",a,b,shortest[a][b]);
	}
	else
	{
		printf("%d",a);
		while(path[i][j]!=0)
		{      /*��i��j��·�������о����ľ��㰴˳���ӡ����*/
			printf("-->%d",path[i][j]);
			if(i<j)
				j=path[i][j];
			else
				i=path[j][i];
		}
		printf("->%d\n\n",b);
		printf("%d->%d�����·���ǣ� %d �ס�\n\n",a,b,shortest[a][b]);
	}
}/*display*/
 
int shortdistance()
{    /*Ҫ���ҵ�����������·��*/
    int i,j;
    printf("������Ҫ��ѯ��������������ֱ��(1->16)�м��ÿո�������\n");
    scanf("%d %d",&i,&j);
    if(i>N||i<0||j>N||j<0)
    {
		printf("������Ϣ����\n\n");
		printf("������Ҫ��ѯ��������������ֱ�ţ�1->16���м��ÿո�������\n");
		scanf("%d %d",&i,&j);
    }
    else
    {
		floyd();
		display(i,j);
    }
    return 1;
    fflush(stdin);
}/*shortestdistance*/
 
int A[MaxSize+1][MaxSize+1];   /*�Ͻ�˹�����㷨*/
int D[MaxSize+1];
int S[MaxSize+1],P[MaxSize+1];
int source,sink;
int step = 1;
int top = -1;                    
int Stack[MaxSize+1];   
         
void input()                  
{
	int i;
	printf("\n��������ʼ�ڵ�:");
	scanf("%d",&source);
	printf("\n����������ڵ�:");
	scanf("%d",&sink);
	
	for ( i = 1; i <= N; i++ )
	{
		S[i] = NOTVISITED;                     
		D[i] = MGr.length[source][i];      
		P[i] = source;      
	}
	S[source] = VISITED;          
	D[source] = 0;
}
void Push(int value)
{
	if ( top >= MaxSize )
	{
		printf("û��·������!\n\n");
		exit(1);
	}
	else
		Stack[++top] = value;
}
int Pop()
{
	if ( top < 0 )
	{
		printf("û��·������!\n\n");
		exit(1);
	}
	return Stack[top--];
}
int minD()
{
	int i,t=0;
	long int minimum = Infinite;
	for ( i=1;i<=N;i++ )
		if ( (S[i] == NOTVISITED) && D[i] < minimum )
		{
			minimum = D[i];
			t = i;
		}
		return t;
}
 
void output_path()
{
	int node = sink;
	
	if ( (sink == source) || (D[sink] == Infinite) )
	{
		printf("\n�ڵ�%d��ڵ�%d֮��û��·�����ڣ�\n\n",source,sink);
		return;
	}
	printf("\n");
	
	while ( node != source )
	{
		Push(node);
		node  = P[node];
	} 
	printf("V%d��V%d�����·��Ϊ:\n",source,sink);
	printf("  V%d",source);
	while( node != sink)
	{
		node = Pop();
		printf(" --%ld-->",MGr.length[ P[node] ][node]);
		printf("V%d",node);
	}
	printf("\n");
	printf("\n %d->%d�����·���ǣ� %ld\n",source,sink,D[sink]);
	printf("\n");
}
 
void distance()
{
	int t,I;
	input();
	for ( step =2;step <=N; step++ )
	{
		
		t = minD();
		S[t] = VISITED;
		
		for ( I=1; I <= N; I++ )
			if ( (S[I] == NOTVISITED) && (D[t]+MGr.length[t][I] <= D[I]) )
			{
				D[I] = D[t] + MGr.length[t][I];
				P[I] = t;
			}
	}
	output_path();
}

 
int main()
{
    char k;
    init();
	printf("**********************************************************************\n");
	printf("*                                                                    *\n");
	printf("*                                                                    *\n");
	printf("*           ��ӭʹ�þŽ�ѧԺ��У������ϵͳ !                     *\n");
	printf("*                                                                    *\n");
	printf("*                                                                    *\n");
	printf("**********************************************************************\n");
    printf("\n");
    while(1)
    {   
		printf("1.������Ϣ��ѯ�밴��1����;\n");
		printf("2.�������·����ѯ�����������㷨���밴��2����;\n");
		printf("3.�������·����ѯ���Ͻ�˹�����㷨���밴��3����;\n");
		printf("4.У�ھ����ͼ��ѯ�밴��4����;\n");	    
		printf("5.�˳�ϵͳ�밴��5����;\n");
		printf("��ѡ��: \n");
		scanf("%c",&k);
		
		switch(k)
		{
		case '1':printf("������ܲ�ѯ��������1-16����\n");
			introduce();break;
		case '2':printf("�������·����ѯ�����������㷨����");
			shortdistance();break;
		case '3':printf("�������·��(�Ͻ�˹�����㷨����ѯ��");
			distance();break;
		case '4':printf("�����ͼ��\n");
			map();break;
		case '5':printf("ллʹ��!\n");exit(0);
		}
    }
    system("pause");
	return 0;
}
