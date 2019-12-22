#include <stdio.h>
#include <stdlib.h>
#include<string.h>
 
#define MaxSize 100     
#define VISITED 1       
#define NOTVISITED 0    
#define Infinite 1073741823  
#define MaxViewNum 50     /*景点个数最大50*/
#define MaxRoad 1000      /*定义路径为无穷大*/
#define N 16              /*目前景点个数*/
 
typedef struct
{
    char name[30];          /*景点名称*/
    char number[10];        /*景点代号*/
    char introduce[200];    /*景点介绍*/	
}Elemtype;                  /*景点信息*/
 
typedef struct
{
    int num;              /*景点编号*/
    Elemtype date;        /*景点信息*/
}View;                    /*定义景点*/
 
typedef struct
{
    View view[MaxViewNum];         /*存放顶点的一维数组，数组第零单元没有用上*/
    int length[MaxViewNum][MaxViewNum];  /*存放路径长度*/
    int m,n;
}MGraph;
 
MGraph MGr;              /*全局变量,定义MGr为MGraph类型*/
int shortest[MaxViewNum][MaxViewNum];     /*定义全局变量存贮最小路径*/
int path[MaxViewNum][MaxViewNum];         /*定义存贮路径*/
 
void init()
{
    int i,j;
    MGr.view[1].num=1;
    strcpy(MGr.view[1].date.name,"南门");
    strcpy(MGr.view[1].date.number,"001");
    strcpy(MGr.view[1].date.introduce,"坐落于前进路，市井繁华，交通便利。");
	
    MGr.view[2].num=2;
    strcpy(MGr.view[2].date.name,"教工食堂");
    strcpy(MGr.view[2].date.number,"002");
    strcpy(MGr.view[2].date.introduce,"老师吃饭的地方。");
	
    MGr.view[3].num=3;
    strcpy(MGr.view[3].date.name,"主校区图书馆");
    strcpy(MGr.view[3].date.number,"003");
    strcpy(MGr.view[3].date.introduce,"学生学习,读书的地方。");
	
    MGr.view[4].num=4;
    strcpy(MGr.view[4].date.name,"蝶湖");
    strcpy(MGr.view[4].date.number,"004");
    strcpy(MGr.view[4].date.introduce,"一个美丽的地方。");
	
    MGr.view[5].num=5;
    strcpy(MGr.view[5].date.name,"行政楼");
    strcpy(MGr.view[5].date.number,"005");
    strcpy(MGr.view[5].date.introduce,"学校领导工作的地方。");
	
    MGr.view[6].num=6;
    strcpy(MGr.view[6].date.name,"红楼");
    strcpy(MGr.view[6].date.number,"006");
    strcpy(MGr.view[6].date.introduce,"教工职员住宿的地方。");
	
    MGr.view[7].num=7;
    strcpy(MGr.view[7].date.name,"南运动场");
    strcpy(MGr.view[7].date.number,"007");
    strcpy(MGr.view[7].date.introduce,"绿茵地、活动中心。篮球场、足球场、网球场依次，丰富课余生活。");
	
    MGr.view[8].num=8;
    strcpy(MGr.view[8].date.name,"竞知楼");
    strcpy(MGr.view[8].date.number,"008");
    strcpy(MGr.view[8].date.introduce,"江西最大的教学楼");
	
    MGr.view[9].num=9;
    strcpy(MGr.view[9].date.name,"厚德楼");
    strcpy(MGr.view[9].date.number,"009");
    strcpy(MGr.view[9].date.introduce,"学生活动中心。");
	
    MGr.view[10].num=10;
    strcpy(MGr.view[10].date.name,"逸夫楼");
    strcpy(MGr.view[10].date.number,"010");
    strcpy(MGr.view[10].date.introduce,"也是图书馆。");
	
    MGr.view[11].num=11;
    strcpy(MGr.view[11].date.name,"女生宿舍");
    strcpy(MGr.view[11].date.number,"011");
    strcpy(MGr.view[11].date.introduce,"...");
	
    MGr.view[12].num=12;
    strcpy(MGr.view[12].date.name,"男生宿舍");
    strcpy(MGr.view[12].date.number,"012");
    strcpy(MGr.view[12].date.introduce,"...");
	
    MGr.view[13].num=13;
    strcpy(MGr.view[13].date.name,"西门");
    strcpy(MGr.view[13].date.number,"013");
    strcpy(MGr.view[13].date.introduce,"最大的校门。");
	
    MGr.view[14].num=14;
    strcpy(MGr.view[14].date.name,"蝶湖");
    strcpy(MGr.view[14].date.number,"014");
    strcpy(MGr.view[14].date.introduce,"一个美丽的地方。");
	
    MGr.view[15].num=15;
    strcpy(MGr.view[15].date.name,"综合学生服务中心");
    strcpy(MGr.view[15].date.number,"015");
    strcpy(MGr.view[15].date.introduce,"吃饭,取快递的地方。");
	
    MGr.view[16].num=16;
    strcpy(MGr.view[16].date.name,"北门");
    strcpy(MGr.view[16].date.number,"016");
    strcpy(MGr.view[16].date.introduce,"交通便利。");
	
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
    MGr.length[1][2]=MGr.length[2][1]=50;
    MGr.length[2][3]=MGr.length[3][2]=50;
    MGr.length[3][4]=MGr.length[4][3]=20;
    MGr.length[3][5]=MGr.length[5][3]=50;
    MGr.length[5][6]=MGr.length[6][5]=100;
    MGr.length[6][7]=MGr.length[7][6]=50;
	MGr.length[6][9]=MGr.length[9][6]=300;
    MGr.length[7][8]=MGr.length[8][7]=70;
    MGr.length[8][9]=MGr.length[9][8]=300;
	MGr.length[8][10]=MGr.length[10][8]=950;
    MGr.length[9][11]=MGr.length[11][9]=800;
    MGr.length[10][11]=MGr.length[11][10]=1060;
    MGr.length[11][12]=MGr.length[12][11]=10;
    MGr.length[12][13]=MGr.length[13][12]=450;
	MGr.length[13][14]=MGr.length[14][13]=520;
    MGr.length[11][14]=MGr.length[14][11]=300;
	MGr.length[16][14]=MGr.length[14][16]=1000;
	MGr.length[13][15]=MGr.length[15][13]=750;
	MGr.length[2][16]=MGr.length[16][2]=2550;
    MGr.length[1][1]=MGr.length[2][2]=MGr.length[3][3]=MGr.length[4][4]=0;
    MGr.length[5][5]=MGr.length[6][6]=MGr.length[7][7]=MGr.length[8][8]=0;
    MGr.length[9][9]=MGr.length[10][10]=MGr.length[11][11]=MGr.length[12][12]=0;
    MGr.length[13][13]=MGr.length[14][14]=MGr.length[15][15]=MGr.length[16][16]=0;
}
 
void introduce()
{
    int m;
    printf("请输入查询景点编号:\n");
    scanf("%d",&m); fflush(stdin);
    switch(m)
    {
	case 1:
		printf("景点编号:%s\t",MGr.view[1].date.number);
		printf("景点名称:%s\n",MGr.view[1].date.name);
		printf("景点简介:%s\n",MGr.view[1].date.introduce);
		break;
	case 2:
		printf("景点编号：%s\t",MGr.view[2].date.number);
		printf("景点名称：%s\n",MGr.view[2].date.name);
		printf("景点简介：%s\n",MGr.view[2].date.introduce);
		break;
	case 3:
		printf("景点编号：%s\t",MGr.view[3].date.number);
		printf("景点名称：%s\n",MGr.view[3].date.name);
		printf("景点简介：%s\n",MGr.view[3].date.introduce);
		break;
	case 4:
		printf("景点编号：%s\t",MGr.view[4].date.number);
		printf("景点名称：%s\n",MGr.view[4].date.name);
		printf("景点简介：%s\n",MGr.view[4].date.introduce);
		break;
	case 5:
		printf("景点编号：%s\t",MGr.view[5].date.number);
		printf("景点名称：%s\n",MGr.view[5].date.name);
		printf("景点简介：%s\n",MGr.view[5].date.introduce);
		break;
	case 6:
		printf("景点编号：%s\t",MGr.view[6].date.number);
		printf("景点名称：%s\n",MGr.view[6].date.name);
		printf("景点简介：%s\n",MGr.view[6].date.introduce);
		break;
	case 7:
		printf("景点编号：%s\t",MGr.view[7].date.number);
		printf("景点名称：%s\n",MGr.view[7].date.name);
		printf("景点简介：%s\n",MGr.view[7].date.introduce);
		break;
	case 8:
		printf("景点编号：%s\t",MGr.view[8].date.number);
		printf("景点名称：%s\n",MGr.view[8].date.name);
		printf("景点简介：%s\n",MGr.view[8].date.introduce);
		break;
	case 9:
		printf("景点编号：%s\t",MGr.view[9].date.number);
		printf("景点名称：%s\n",MGr.view[9].date.name);
		printf("景点简介：%s\n",MGr.view[9].date.introduce);
		break;
	case 10:
		printf("景点编号：%s\t",MGr.view[10].date.number);
		printf("景点名称：%s\n",MGr.view[10].date.name);
		printf("景点简介：%s\n",MGr.view[10].date.introduce);
		break;
	case 11:
		printf("景点编号：%s\t",MGr.view[11].date.number);
		printf("景点名称：%s\n",MGr.view[11].date.name);
		printf("景点简介：%s\n",MGr.view[11].date.introduce);
		break;
	case 12:
		printf("景点编号：%s\t",MGr.view[12].date.number);
		printf("景点名称：%s\n",MGr.view[12].date.name);
		printf("景点简介：%s\n",MGr.view[12].date.introduce);
		break;
	case 13:
		printf("景点编号：%s\t",MGr.view[13].date.number);
		printf("景点名称：%s\n",MGr.view[13].date.name);
		printf("景点简介：%s\n",MGr.view[13].date.introduce);
		break;
	case 14:
		printf("景点编号：%s\t",MGr.view[14].date.number);
		printf("景点名称：%s\n",MGr.view[14].date.name);
		printf("景点简介：%s\n",MGr.view[14].date.introduce);
		break;
	case 15:
		printf("景点编号：%s\t",MGr.view[15].date.number);
		printf("景点名称：%s\n",MGr.view[15].date.name);
		printf("景点简介：%s\n",MGr.view[15].date.introduce);
		break;
	case 16:
		printf("景点编号：%s\t",MGr.view[16].date.number);
		printf("景点名称：%s\n",MGr.view[16].date.name);
		printf("景点简介：%s\n",MGr.view[16].date.introduce);
		break;
	default:
		printf("输入序号错误。\n");
		break;
    }
    printf("\n");
}
 
void floyd()                 
{
    int i,j,k;
    for(i=1;i<=N;i++)
    {
		for(j=1;j<=N;j++)
		{
			shortest[i][j]=MGr.length[i][j];
			path[i][j]=0;
		}
    }   /*初始化数组*/
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
					path[j][i]=k;   /*记录经过的路径*/
				}//end_if
			}			
		}//end_for
    }
}
 
void display(int i,int j)
{         /*打印两个景点的路径及最短路径*/
    int a,b;
    a=i;
    b=j;
    printf("您要查询的两景点间最短路径是： \n\n");
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
		printf("%d->%d的最短路径是： %d 米。\n\n",a,b,shortest[a][b]);
	}
	else
	{
		printf("%d",a);
		while(path[i][j]!=0)
		{      /*把i到j的路径上所有经过的景点按顺序打印出来*/
			printf("-->%d",path[i][j]);
			if(i<j)
				j=path[i][j];
			else
				i=path[j][i];
		}
		printf("->%d\n\n",b);
		printf("%d->%d的最短路径是： %d 米。\n\n",a,b,shortest[a][b]);
	}
}/*display*/
 
int shortdistance()
{    /*要查找的两景点的最短路径*/
    int i,j;
    printf("请输入要查询的两个景点的数字编号(1->16)中间用空格间隔开。\n");
    scanf("%d %d",&i,&j);
    if(i>N||i<0||j>N||j<0)
    {
		printf("输入信息错误！\n\n");
		printf("请输入要查询的两个景点的数字编号（1->16）中间用空格间隔开。\n");
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
 
int A[MaxSize+1][MaxSize+1];   
int D[MaxSize+1];
int S[MaxSize+1],P[MaxSize+1];
int source,sink;
int step = 1;
int top = -1;                    
int Stack[MaxSize+1];   
         
void input()                  
{
	int i;
	printf("\n请输入起始节点:");
	scanf("%d",&source);
	printf("\n请输入结束节点:");
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
		printf("没有路径存在!\n\n");
		exit(1);
	}
	else
		Stack[++top] = value;
}
int Pop()
{
	if ( top < 0 )
	{
		printf("没有路径存在!\n\n");
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
		printf("\n节点%d与节点%d之间没有路径存在！\n\n",source,sink);
		return;
	}
	printf("\n");
	
	while ( node != source )
	{
		Push(node);
		node  = P[node];
	} 
	printf("V%d到V%d的最短路径为:\n",source,sink);
	printf("  V%d",source);
	while( node != sink)
	{
		node = Pop();
		printf(" --%ld-->",MGr.length[ P[node] ][node]);
		printf("V%d",node);
	}
	printf("\n");
	printf("\n %d->%d的最短路径是： %ld\n",source,sink,D[sink]);
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
 
 
void map()
{ 
	printf("===========================================================\n");
        printf("-------------------------------------------++++------------\n");
	printf("------------------------------------------ |16| -----------\n");
	printf("------------------------------------------ |16| -----------\n");
	printf("-------------------------------------------++++------------\n");
	printf("----------++++++++++---------------------------------------\n");
	printf("--------- |   14   | --------------------------------------\n");
	printf("--------- |   14   | --------------------------------------\n");
	printf("----------++++++++++++++++++++++---------------------------\n");
	printf("----------------- |     15     | --------------------------\n");
	printf("----------------- |     15     | --------------------------\n");
	printf("--++++-----------+++++++++++++++---------------------------\n");
	printf("- |13| --------- | 12 |--------------------------++++++----\n");
	printf("- |13| --------- | 12 |--------------------------| 10 |----\n");
	printf("--++++-----------+++++++++++---------------------| 10 |----\n");
	printf("--------------------- | 11 | --------------------++++++----\n");
	printf("--------------------- | 11 | ------------------------------\n");
	printf("----------------------++++++---------+++++++---------------\n");
	printf("------------------------------------ |  8  | --------------\n");
	printf("--------------+++++++----+++++------ |  8  | --------------\n");
	printf("------------- |  3  |--- | 4 |-------+++++++---------------\n");
	printf("------------- |  3  |--- | 4 |-----------------------------\n");
	printf("--------------+++++++----+++++-------+++++++---------------\n");
	printf("------------------------+++++------- |  7  | -------+++++--\n");
	printf("----------------------- | 5 | -------+++++++--------| 9 |--\n");
	printf("------------+++++-------+++++--------+++++----------+++++--\n");
	printf("----------- | 2 | ------------------ | 6 | ----------------\n");
	printf("----------- | 2 | ------------------ | 6 | ----------------\n");
	printf("---+++++----+++++--------------------+++++-----------------\n");
	printf("-- | 1 | --------------------------------------------------\n");
	printf("---+++++---------------------------------------------------\n");
	printf("===========================================================\n");
    printf("\n");
    fflush(stdin);
}/*map*/
 
int main()
{
    char k;
    init();
	printf("**********************************************************************\n");
	printf("*                                                                    *\n");
	printf("*                   欢 迎 来 到 九 江 学 院 !                        *\n");
	printf("*                                                                    *\n");
	printf("**********************************************************************\n");
    printf("\n");
    while(1)
    {   
		printf("1.景点信息查询请按“1”键;\n");
		printf("2.景点最短路径查询   请按“2”键;\n");
		printf("3.景点最短路径查询   请按“3”键;\n");
		printf("4.校内景点地图查询请按“4”键;\n");	    
		printf("5.退出系统请按“5”键;\n");
		printf("请选择: \n");
		scanf("%c",&k);
		
		switch(k)
		{
		case '1':printf("景点介绍查询（请输入1-16）。\n");
			introduce();break;
		case '2':printf("景点最短路径查询。");
			shortdistance();break;
		case '3':printf("景点最短路径查询。");
			distance();break;
		case '4':printf("景点地图。\n");
			map();break;
		case '5':printf("谢谢使用!\n");exit(0);
		}
    }
    system("pause");
	return 0;
}
