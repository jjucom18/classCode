#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<console.h>
#define MaxSize 100     
#define VISITED 1       
#define NOTVISITED 0    
#define Infinite 100000000 
#define MaxViewNum 30     /*景点个数最大30*/
#define MaxRoad 1000      /*定义路径为无穷大*/
#define N 21              /*目前景点个数*/
 
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
	    View view[MaxViewNum];         /*存放顶点的一维数组*/
	    int length[MaxViewNum][MaxViewNum];  /*存放路径长度*/
            int m,n;
}MGraph;
 
MGraph MGr;              /*全局变量,定义MGr为MGraph类型*/
int shortest[MaxViewNum][MaxViewNum];     /*定义全局变量存贮最小路径*/
int path[MaxViewNum][MaxViewNum];         /*定义存贮路径*/
void init()
{       int i,j;
MGr.view[1].num=1;
    strcpy(MGr.view[1].date.name,"北门");
    strcpy(MGr.view[1].date.number,"001");
    strcpy(MGr.view[1].date.introduce,"九江学院最北门");
			    	
MGr.view[2].num=2;
    strcpy(MGr.view[2].date.name,"艺术学院");
    strcpy(MGr.view[2].date.number,"002");
    strcpy(MGr.view[2].date.introduce,"艺术系学生学习的地方，是主校区最新式的建筑");
	    	 
MGr.view[3].num=3;
    strcpy(MGr.view[3].date.name,"西门");
    strcpy(MGr.view[3].date.number,"003");
    strcpy(MGr.view[3].date.introduce,"九江学院最西门，各学院升旗的地方，最先看到太阳升起"）；
		    
MGr.view[4].num=4;
    strcpy(MGr.view[4].date.name,"北区田径馆");
    strcpy(MGr.view[4].date.number,"004");
    strcpy(MGr.view[4].date.introduce,"北区的高级运动会所满足学生全方位的运动需求");

MGr.view[5].num=5;
    strcpy(MGr.view[5].date.name,"绿色果园");
    strcpy(MGr.view[5].date.number,"005");
    strcpy(MGr.view[5].date.introduce,"九江学院自己研发开发种植的养殖基地");

MGr.view[6].num=6;
    strcpy(MGr.view[6].date.name,"五食堂");
    strcpy(MGr.view[6].date.number,"006");
    strcpy(MGr.view[6].date.introduce,"九江学院第五食堂，菜种丰富好吃实惠，但冬冷夏热");

MGr.view[7].num=7;
    strcpy(MGr.view[7].date.name,"户外田径场");
    strcpy(MGr.view[7].date.number,"007");
    strcpy(MGr.view[7].date.introduce,"夜晚学生们运动交友的圣地");

MGr.view[8].num=8;
    strcpy(MGr.view[8].date.name,"户外篮球场");
    strcpy(MGr.view[8].date.number,"008");
    strcpy(MGr.view[8].date.introduce,"北区篮球场是各大学院训练比赛的地方，夜晚也可带小姐姐来这练球哦~");

MGr.view[9].num=9;
    strcpy(MGr.view[9].date.name,"逸夫图书馆");
        strcpy(MGr.view[9].date.number,"009");
	    strcpy(MGr.view[9].date.introduce,"逸夫为名，是九江学院新式图书馆藏书丰富可供大学生在知识的海洋畅游");

MGr.view[10].num=10;
    strcpy(MGr.view[10].date.name,"学生15栋宿舍");
        strcpy(MGr.view[10].date.number,"010");
	    strcpy(MGr.view[10].date.introduce,"该栋宿舍是电子工程学院学生聚居的地方，是大学生活的根据地");

MGr.view[11].num=11;
    strcpy(MGr.view[11].date.name,"四食堂");
        strcpy(MGr.view[11].date.number,"011");
	    strcpy(MGr.view[11].date.introduce,"走廊式食堂，学生可在这里购买冰激凌，奶茶等饮品以及水果");

MGr.view[12].num=12;
    strcpy(MGr.view[12].date.name,"三食堂");
        strcpy(MGr.view[12].date.number,"012");i
	    strcpy(MGr.view[12].date.introduce,"九江学院最大的规模性食堂，共有三层，绝对能满足学生各种的美食欲望");

MGr.view[13].num=13;
    strcpy(MGr.view[13].date.name,"一食堂");
        strcpy(MGr.view[13].date.number,"013");
	    strcpy(MGr.view[13].date.introduce,"九江学院最早的食堂，早餐较为丰富，有两层楼c，菜种也多");

MGr.view[14].num=14;
    strcpy(MGr.view[14].date.name,"文理实验楼");
        strcpy(MGr.view[14].date.number,"014");
	    strcpy(MGr.view[14].date.introduce,"文学理学实验的大楼，是电子学院学生做大物实验的地方，是工科学生的恶魔深渊");

MGr.view[15].num=15;
    strcpy(MGr.view[15].date.name,"实训楼");
        strcpy(MGr.view[15].date.number,"015");
	    strcpy(MGr.view[15].date.introduce,"是工科学生实训的地方，二楼是学校公共机房，使用计算机课程的上课地");

MGr.view[16].num=16;
    strcpy(MGr.view[16].date.name,"二食堂");
        strcpy(MGr.view[16].date.number,"016");
	    strcpy(MGr.view[16].date.introduce,"风评最不好的食堂，饭菜一般，价格偏上，不建议在这里吃");

MGr.view[17].num=17;
    strcpy(MGr.view[17]date.name,"学生宿舍十一栋");
        strcpy(MGr.view[17].date.number,"017");
	    strcpy(MGr.view[17].date.introduce,"电子学院女生住的宿舍，有独立卫生间，电子女生很幸福")
		    
MGr.view[17].num=17;
	        strcpy(MGr.view[18]date.name,"竞知楼");
		        strcpy(MGr.view[18].date.number,"018");
			            strcpy(MGr.view[18].date.introduce,"九江学院最大也是江西最大的教学楼，是电子学院及其他大院的教学楼");

MGr.view[19].num=19;
    strcpy(MGr.view[19].date.name,"南区田径场");
            strcpy(MGr.view[19].date.number,"019");
	                strcpy(MGr.view[19].date.introduce,"南区的大型露天塑胶跑道，和真草批足球场");
		
MGr.view[20].num=20;
    strcpy(MGr.view[20].date.name,"行政楼，校医院");
            strcpy(MGr.view[20].date.number,"020");
	                strcpy(MGr.view[20].date.introduce,"学校的行政部以及校医院所在地，新生体检地");

MGr.view[21].num=21;
    strcpy(MGr.view[21].date.name,"九江学院南门");
            strcpy(MGr.view[21].date.number,"021");
	                strcpy(MGr.view[21].date.introduce,"九江学院最炫，人流量最大的校门，门口正对面是小吃街");




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
MGr.length[2][3]=MGr.length[3][2]=300;
MGr.length[1][3]=MGr.length[3][1]=250;
MGr.length[1][4]=MGr.length[4][1]=30;
MGr.length[1][5]=MGr.length[5][1]=100;
MGr.length[4][7]=MGr.length[7][4]=20;
MGr.length[4][8]=MGr.length[8][4]=20;
MGr.length[5][9]=MGr.length[9][5]=100;
MGr.length[3][6]=MGr.length[6][3]=100;
MGr.length[7][6]=MGr.length[6][7]=50;
MGr.length[7][11]=MGr.length[11][7]=50;
MGr.length[8][14]=MGr.length[14][8]=100;
MGr.length[8][15]=MGr.length[15][8]=50;
MGr.length[14][15]=MGr.length[15][14]=100;
MGr.length[9][15]=MGr.length[15][9]=50;
MGr.length[6][10]=MGr.length[10][6]=50;
MGr.length[11][12]=MGr.length[12][11]=30;
MGr.length[12][6]=MGr.length[6][12]=50;
MGr.length[11][13]=MGr.length[13][11]=100;
MGr.length[13][16]=MGr.length[16][13]=50;
MGr.length[16][19]=MGr.length[19][16]=200;
MGr.length[14][19]=MGr.length[19][14]=300;
MGr.length[15][20]=MGr.length[20][15]=800;
MGr.length[10][17]=MGr.length[17][10]=150; 
MGr.length[17][18]=MGr.length[18][17]=100;
MGr.length[12][18]=MGr.length[18][12]=200;
MGr.length[18][19]=MGr.length[19][18]=100; 
MGr.length[19][20]=MGr.length[20][19]=100;
MGr.length[20][21]=MGr.length[21][20]=50; 

MGr.length[1][1]=MGr.length[2][2]=MGr.length[3][3]=MGr.length[4][4]=0;
MGr.length[5][5]=MGr.length[6][6]=MGr.length[7][7]=MGr.length[8][8]=0;
MGr.length[9][9]=MGr.length[10][10]=MGr.length[11][11]=MGr.length[12][12]=0;
MGr.length[13][13]=MGr.length[14][14]=MGr.length[15][15]=MGr.length[16][16]=0;
MGr.length[17][17]=MGr.length[18][18]=MGr.length[19][19]=MGr.length[20][20]=MGr.length[21][21]=0;

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
	printf("景点编号:%s\t",MGr.view[2].date.number);
	printf("景点名称:%s\n",MGr.view[2].date.name);
	printf("景点简介:%s\n",MGr.view[2].date.introduce);
	break;
 case 3:
        printf("景点编号:%s\t",MGr.view[3].date.number);                                                                        printf("景点名称:%s\n",MGr.view[3].date.name);                                                                          printf("景点简介:%s\n",MGr.view[3].date.introduce);                                                                     break;
 case 4:
        printf("景点编号:%s\t",MGr.view[4].date.number);                                                                        printf("景点名称:%s\n",MGr.view[4].date.name);                                                                          printf("景点简介:%s\n",MGr.view[4].date.introduce);                                                                     break;
 case 5:
        printf("景点编号:%s\t",MGr.view[5].date.number);                                                                        printf("景点名称:%s\n",MGr.view[5].date.name);                                                                          printf("景点简介:%s\n",MGr.view[5].date.introduce);                                                                     break;
 case 6:                                                                                                                        printf("景点编号:%s\t",MGr.view[6].date.number);                                                                        printf("景点名称:%s\n",MGr.view[6].date.name);                                                                          printf("景点简介:%s\n",MGr.view[6].date.introduce);                                                                     break;
 case 7:                                                                                                                        printf("景点编号:%s\t",MGr.view[7].date.number);                                                                        printf("景点名称:%s\n",MGr.view[7].date.name);                                                                          printf("景点简介:%s\n",MGr.view[7].date.introduce);                                                                     break;		
 case 8:                                                                                                                        printf("景点编号:%s\t",MGr.view[8].date.number);                                                                        printf("景点名称:%s\n",MGr.view[8].date.name);                                                                          printf("景点简介:%s\n",MGr.view[8].date.introduce);                                                                     break;	    	
 case 9:                                                                                                                        printf("景点编号:%s\t",MGr.view[9].date.number);                                                                        printf("景点名称:%s\n",MGr.view[9].date.name);                                                                          printf("景点简介:%s\n",MGr.view[9].date.introduce);                                                                     break;	    	
 case 10:                                                                                                                        printf("景点编号:%s\t",MGr.view[10].date.number);                                                                        printf("景点名称:%s\n",MGr.view[10].date.name);                                                                          printf("景点简介:%s\n",MGr.view[10].date.introduce);                                                                     break;	    	
 case 11:                                                                                                                       printf("景点编号:%s\t",MGr.view[11].date.number);                                                                        printf("景点名称:%s\n",MGr.view[11].date.name);                                                                          printf("景点简介:%s\n",MGr.view[11].date.introduce);                                                                     break;	    	
 case 12:                                                                                                                        printf("景点编号:%s\t",MGr.view[12].date.number);                                                                        printf("景点名称:%s\n",MGr.view[12].date.name);                                                                          printf("景点简介:%s\n",MGr.view[12].date.introduce);                                                                     break;	    	
 case 13:                                                                                                                        printf("景点编号:%s\t",MGr.view[13].date.number);                                                                        printf("景点名称:%s\n",MGr.view[13].date.name);                                                                          printf("景点简介:%s\n",MGr.view[13].date.introduce);                                                                     break;	    	
 case 14:                                                                                                                        printf("景点编号:%s\t",MGr.view[14].date.number);                                                                        printf("景点名称:%s\n",MGr.view[14].date.name);                                                                          printf("景点简介:%s\n",MGr.view[14].date.introduce);                                                                     break;	    	
 case 15:                                                                                                                        printf("景点编号:%s\t",MGr.view[15].date.number);                                                                        printf("景点名称:%s\n",MGr.view[15].date.name);                                                                          printf("景点简介:%s\n",MGr.view[15].date.introduce);                                                                     break;
 case 16:                                                                                                                        printf("景点编号:%s\t",MGr.view[16].date.number);                                                                        printf("景点名称:%s\n",MGr.view[16].date.name);                                                                          printf("景点简介:%s\n",MGr.view[16].date.introduce);                                                                     break;
 case 17:                                                                                                                        printf("景点编号:%s\t",MGr.view[17].date.number);                                                                        printf("景点名称:%s\n",MGr.view[17].date.name);                                                                          printf("景点简介:%s\n",MGr.view[17].date.introduce);                                                                     break;
 case 18:                                                                                                                        printf("景点编号:%s\t",MGr.view[18].date.number);                                                                        printf("景点名称:%s\n",MGr.view[18].date.name);                                                                          printf("景点简介:%s\n",MGr.view[18].date.introduce);                                                                     break;
 case 19:                                                                                                                        printf("景点编号:%s\t",MGr.view[19].date.number);                                                                        printf("景点名称:%s\n",MGr.view[19].date.name);                                                                          printf("景点简介:%s\n",MGr.view[19].date.introduce);                                                                     break;
 case 20:                                                                                                                        printf("景点编号:%s\t",MGr.view[20].date.number);                                                                        printf("景点名称:%s\n",MGr.view[20].date.name);                                                                          printf("景点简介:%s\n",MGr.view[20].date.introduce);                                                                     break;
 case 21:                                                                                                                        printf("景点编号:%s\t",MGr.view[21].date.number);                                                                        printf("景点名称:%s\n",MGr.view[21].date.name);                                                                          printf("景点简介:%s\n",MGr.view[21].date.introduce);                                                                     break;
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
	    {for(j=1;j<=N;j++)
   	{
	shortest[i][j]=MGr.length[i][j];
		path[i][j]=0;
			}
	    }   /*初始化数组*/
	    for(k=1;k<=N;k++)
	       {for(i=1;i<=N;i++)
		{for(j=1;j<=N;j++)
		{if(shortest[i][j]>(shortest[i][k]+shortest[k][j]))
		{shortest[i][j]=shortest[i][k]+shortest[k][j];
		path[i][j]=k;
									path[j][i]=k;   /*记录经过的路径*/
	}//end_if
	}			
	}//end_for
	    }
}

void display(int i,int j)
{   /*打印两个景点的路径及最短路径*/
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


nt A[MaxSize+1][MaxSize+1];  
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
	{S[i] = NOTVISITED;                     
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



int main()
{
   char k;
	 init();
	printf("**********************************************************************\n");
	printf("*                                                                    *\n");
	printf("*                                                                    *\n");
	printf("*           欢迎使用九江学院主校区导游系统 !                         *\n");
	printf("*                                                                    *\n");
	printf("*                                                                    *\n");
	printf("**********************************************************************\n");
	  printf("\n");
	       while(1)
						{   
	printf("1.景点信息查询请按“1”键;\n");
																printf("2.景点最短路径查询 请按“2”键;\n");
																printf("3.景点最短路径查询 请按“3”键;\n");
																printf("4.校内景点地图查询请按“4”键;\n");	    
																printf("5.退出系统请按“5”键;\n");
																printf("请选择: \n");
																scanf("%c",&k);
																switch(k)
																		{
																case '1':printf("景点介绍查询（请输入1-21）。\n");
																	introduce();break;						
																														case '2':printf("景点最短路径查询。");
															shortdistance();break;
																												 		case '3':printf("景点最短路径 查询。");
																													 			distance();break;
																													 		case '4':printf("景点地图。\n");
																																												 			map();break;	
																	case '5':printf("谢谢使用!\n");exit(0);
				 		}																    }
	 system("pause");
  	return 0;
}
