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
    strcpy(MGr.view[1].date.name,"学校北门");
    strcpy(MGr.view[1].date.number,"1");
    strcpy(MGr.view[1].date.introduce,"坐落于艺术学院附近，靠近公路旁，比较偏僻，交通不便。");
	
    MGr.view[2].num=2;
    strcpy(MGr.view[2].date.name,"学校南门");
    strcpy(MGr.view[2].date.number,"2");
    strcpy(MGr.view[2].date.introduce,"坐落于学校最繁华的地段。");
	
    MGr.view[3].num=3;
    strcpy(MGr.view[3].date.name,"学校西门");
    strcpy(MGr.view[3].date.number,"3");
    strcpy(MGr.view[3].date.introduce,"学校最气派的大门，校升旗仪式也在西门举行，交通也比较便利。");
	
    MGr.view[4].num=4;
    strcpy(MGr.view[4].date.name,"莲池");
    strcpy(MGr.view[4].date.number,"4");
    strcpy(MGr.view[4].date.introduce,"九江学院两坐湖之一，九江学院著名的风景点之一。");
	
    MGr.view[5].num=5;
    strcpy(MGr.view[5].date.name,"主图书馆");
    strcpy(MGr.view[5].date.number,"5");
    strcpy(MGr.view[5].date.introduce,"历史悠久，文化积淀，书目种类繁多，主要以文科类的书籍为主，提供同学安静学习的环境。");
	
    MGr.view[6].num=6;
    strcpy(MGr.view[6].date.name,"竞知楼");
    strcpy(MGr.view[6].date.number,"6");
    strcpy(MGr.view[6].date.introduce,"九江学院规模最大的教学楼，九江学院的标志性建筑。");
	
    MGr.view[7].num=7;
    strcpy(MGr.view[7].date.name,"南区操场");
    strcpy(MGr.view[7].date.number,"7");
    strcpy(MGr.view[7].date.introduce,"绿茵地、活动中心。篮球场、足球场、，丰富课余生活。");
	
    MGr.view[8].num=8;
    strcpy(MGr.view[8].date.name,"一食堂");
    strcpy(MGr.view[8].date.number,"8");
    strcpy(MGr.view[8].date.introduce,"山上楼栋学生吃饭的主要地方。");
	
    MGr.view[9].num=9;
    strcpy(MGr.view[9].date.name,"校医院");
    strcpy(MGr.view[9].date.number,"9");
    strcpy(MGr.view[9].date.introduce,"校医院，同学们看病拿药的地方，提供便利。");
	
    MGr.view[10].num=10;
    strcpy(MGr.view[10].date.name,"三食堂");
    strcpy(MGr.view[10].date.number,"10");
    strcpy(MGr.view[10].date.introduce,"九江学院规模最大的食堂，食品种类齐全美味可口，价格实惠。");
	
    MGr.view[11].num=11;
    strcpy(MGr.view[11].date.name,"四服二楼快递点");
    strcpy(MGr.view[11].date.number,"11");
    strcpy(MGr.view[11].date.introduce,"九江学院快递的主要集中点，京东，天天，圆通，邮政。");
	
    MGr.view[12].num=12;
    strcpy(MGr.view[12].date.name,"学生宿舍");
    strcpy(MGr.view[12].date.number,"12");
    strcpy(MGr.view[12].date.introduce,"学生宿舍区，留学生宿舍，学生宿舍31-34栋。");
	
    MGr.view[13].num=13;
    strcpy(MGr.view[13].date.name,"田径馆");
    strcpy(MGr.view[13].date.number,"13");
    strcpy(MGr.view[13].date.introduce,"学生训练的地方，比赛专用用地。");
	
    MGr.view[14].num=14;
    strcpy(MGr.view[14].date.name,"教学区");
    strcpy(MGr.view[14].date.number,"14");
    strcpy(MGr.view[14].date.introduce,"立信楼，文友楼，义丰楼，香园楼，厚德楼。");
	
    MGr.view[15].num=15;
    strcpy(MGr.view[15].date.name,"实训楼");
    strcpy(MGr.view[15].date.number,"15");
    strcpy(MGr.view[15].date.introduce,"学校的公共机房，学生实习，上课用地。");
	
    MGr.view[16].num=16;
    strcpy(MGr.view[16].date.name,"逸夫图书馆");
    strcpy(MGr.view[16].date.number,"16");
    strcpy(MGr.view[16].date.introduce,"学校理工类图书馆");
	
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
    MGr.length[3][4]=MGr.length[4][3]=60;
    MGr.length[3][5]=MGr.length[5][3]=100;
    MGr.length[5][6]=MGr.length[6][5]=100;
    MGr.length[6][7]=MGr.length[7][6]=220;
	MGr.length[6][9]=MGr.length[9][6]=80;
    MGr.length[7][8]=MGr.length[8][7]=250;
    MGr.length[8][9]=MGr.length[9][8]=100;
	MGr.length[8][10]=MGr.length[10][8]=150;
    MGr.length[9][11]=MGr.length[11][9]=50;
    MGr.length[10][11]=MGr.length[11][10]=60;
    MGr.length[11][12]=MGr.length[12][11]=40;
    MGr.length[12][13]=MGr.length[13][12]=50;
	MGr.length[13][14]=MGr.length[14][13]=20;
    MGr.length[11][14]=MGr.length[14][11]=80;
	MGr.length[16][14]=MGr.length[14][16]=500;
	MGr.length[13][15]=MGr.length[15][13]=450;
	MGr.length[2][16]=MGr.length[16][2]=150;
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
 
void floyd()                 /*佛洛依德算法*/
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
 

int main()
{
    char k;
    init();
	printf("************************ 欢迎使用九江学院导游系统 !**********************\n");                     
   	 printf("\n");
    while(1)
    {   
		printf("1.景点信息查询请按“1”键;\n");
		printf("2.景点最短路径查询 请按“2”键;\n");
		printf("3.退出系统请按“3”键;\n");
		printf("请选择: \n");
		scanf("%c",&k);
		
		switch(k)
		{
		case '1':printf("景点介绍查询（请输入1-16）。\n");
			introduce();break;
		case '2':printf("景点最短路径查询.");
			shortdistance();break;		
		case '3':printf("谢谢使用!\n");exit(0);
		}
    }
    system("pause");
	return 0;
}

