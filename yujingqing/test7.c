X      20  //图中顶点数的最大值

#define    MAXedg  30  //图中边数的最大值 

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <conio.h>

typedef int AdjMatrix[MAX][MAX];

typedef struct

{

	int vexs[MAX];

	AdjMatrix arcs;

}Matrix_Graph;//图的矩阵表示法。

typedef struct edgenode

{

	int  adjvex;    //临接点序号

		int  length;    //道路长度

		char info[10];  //景点名称

		char info2[100];    //景点详细信息

		struct edgenode *next;

}edgenode, *Node ; 

typedef struct

{

	char  name[10];    //存储景点的名称.

		char  information[100];    //具体的介绍此景点

		struct edgenode *link;      //指向下一个景点

}vexnode;                    //景点及其信息.

typedef  struct Edge

{

	int lengh;  //边的权值，表示路径长度.

		int ivex, jvex;  //边的两端顶点号

		struct Edge *next;  //指向下一条边

} EdgeType; 

//边及其信息.
//
//typedef struct
//
//{
//
//int  num;  //顶点编号。
//
//char name[10];  //顶点名称
//
//} vertex;
//
//typedef struct
//
//{
//
//vertex vexs[MAX];          //顶点集合
//
//int    edges[MAX][MAX];  //临街矩阵
//
//}adjmax;  //adj
//
//FILE *fp;  //文件的读取
//
//void clrscr() //清屏
//
//{
//
//system("cls");
//
//}
//
//void creatgraph(vexnode g[],int *n, EdgeType e[],adjmax *adj) //创建校园图
//
//{
//
//int b,i,s,d,len;
//
//struct edgenode *p,*q;    //定义图的结构体
//
//if((fp = fopen("file.txt","r")) == NULL)  //打开文件
//
//{
//
//printf("文件打开错误！\n");
//
//getchar();
//
//exit(0);
//
//}
//
//fscanf(fp,"%d %d\n",n,&b);  //读入景点个数和边数
//
//for(i = 1; i <= *n; i++)    //读入景点名称和详细介绍信息
//
//{
//
//fscanf(fp,"%s %s\n",&g[i].name,&g[i].information);
//
//strcpy(adj->vexs[i].name,g[i].name);
//
//g[i].link = NULL;  //初始化
//
//}
//
//for(i = 1; i <= b; i++) 
//
//{ 
//
//fscanf(fp,"%d %d %d\n",&e[i].lengh,&e[i].ivex,&e[i].jvex);  //读入道路长度和起始点
//
//s = e[i].ivex;    //s是起点，d是终点。
//
//d = e[i].jvex;
//
//len = e[i].lengh;
//
//adj->edges[s][d] = e[i].lengh;  //为邻接矩阵中相应的边赋值
//
//adj->edges[d][s] = e[i].lengh;
//
//p = (Node)malloc(sizeof(edgenode));  //申请一个弧节点。
//
//p->next = NULL;
//
//q = (Node)malloc(sizeof(edgenode));
//
//q->next = NULL;
//
//p->adjvex = d;    // 弧p指向的定点
//
//p->length = len;
//
//strcpy(p->info,g[d].name); //为景点赋名称
//
//strcpy(p->info2,g[d].information); //为景点赋介绍信息
//
//q->adjvex = s;      // 弧q指向的定点
//
//q->length = len;
//
//strcpy(q->info,g[s].name);  //为景点赋名称
//
//strcpy(q->info2,g[s].information);  //为景点赋介绍信息
//
//p->next = g[s].link;  //头插法建立邻接表
//
//g[s].link = p;
//
//q->next = g[d].link;
//
//g[d].link = q;
//
//}
//
//printf("校园旅游图已经建立！\n");
//
//getchar();
//
//}
//
//void Name(int i)
//
//{
//
//switch(i)
//
//{
//
//case 1:
//
//printf("1:学校正门\n\n");break;
//
//case 2:
//
//printf("2:主楼广场 \n\n");break;
//
//case 3:
//
//printf("3:图书馆\n\n");break;
//
//case 4:
//
//printf("4:国际交流中心\n\n");break;
//
//case 5:
//
//printf("5:宿舍区\n\n");break;
//
//case 6:
//
//printf("6:二食堂\n\n");break;
//
//case 7:
//
//printf("7:体育馆\n\n");break;
//
//case 8:
//
//printf("8:大操场\n\n");break;
//
//case 9:
//
//printf("9:校医院\n\n");break;
//
//case 10:
//
//printf("10: 大学活动中心\n\n");break;
//
//default:
//
//printf("景点编号输入错误！请输入1->10的数字编号！\n\n"); break;
//
//}
//
//} /*Name*/
//
//void Information(int i)
//
//{/*景点介绍*/
//
//switch(i)
//
//{
//
//case 1:
//
//printf("学校正门:正门旁边是一条宽敞的马路，交通方便；进门后直对面就是两栋高大的主楼，气势宏伟。\n\n");break;
//
//case 2:
//
//printf("主楼广场: 广场大致圆形，两边是两栋主楼。 \n\n");break;
//
//case 3:
//
//printf("图书馆: 学校信息资源中心，外表呈‘品’字形，两面藏有大量各种书刊，设有电子查阅室和自习室，是学生学习的好地方。\n\n");break;
//
//case 4:
//
//printf("国际交流中心: 一楼餐厅（吃饭不贵而且很卫生），楼上是一些留学生和外教的住所。还有一些国际研讨会经常在这里开展。\n\n");break;
//
//case 5:
//
//printf("宿舍区: 有一、二、三、四、六、七、九、七个公寓，是大部分学生的住所。\n\n");break;
//
//case 6:
//
//printf("二食堂: 坐落在宿舍区，里面有各个地方的小吃，味道不错，是学生就餐的主要餐厅。\n\n");break;
//
//case 7:
//
//printf("体育馆: 里面有篮球场，羽毛球场，乒乓球桌，是学校举行各项体育活动的主要场所。\n\n");break;
//
//case 8:
//
//printf("大操场:在体育馆旁边，是学生和老师体育锻炼的主要地方。\n\n");break;
//
//case 9:
//
//printf("校医院: 设备不太齐全，只能治疗一些常见的小病，但是价格很便宜。\n\n\n");break;
//
//case 10:
//
//printf("大学活动中心:  里面有书店、打印和复印的地方、各种学生组织的办公室。里面还可以举行各项文艺活动。\n\n");break;
//
//default:
//
//printf("景点编号输入错误！请输入1->10的数字编号！\n\n"); break;
//
//}
//
//}/*Information*/
//
//void travgraph(vexnode g[],int n,adjmax adj)  //查找指定景点信息
//
//{
//
//int i = 1,flag = 1,len;  //len存储要查询的景点的序号
//
//char ch;
//
//printf("请输入您要查询的景点序号:\n");
//
//scanf("%d",&len);
//
//getchar();
//
//printf("此景点的名称是:");
//
//Name(len);
//
//printf("此景点的介绍是:");
//
//Information(len);
//
//do{
//
//printf("是否继续? Y/N");
//
//scanf("%c",&ch);
//
//getchar();   
//
//if(ch == 'Y' || ch == 'y')  //继续
//
//{
//
//flag = 1;
//
//i = 1;
//
//printf("请输入您要查询的景点序号:\n");
//
//scanf("%d",&len);
//
//getchar();
//
//printf("此景点的名称是:");
//
//Name(len);
//
//printf("此景点的介绍是:");
//
//Information(len);
//
//continue ;
//
//}
//
//else
//
//flag = 0;  //不继续
//
//break;
//
//}while(1);
//
//}
//
//void creat(Matrix_Graph *G)
//
//{
//
//int i,j;
//
//for(i=1;i<=N;i++) G->vexs[i]=i;//初始化，0号位不用。
//
//for(i=1;i<=N;i++)
//
//for(j=1;j<=N;j++) G->arcs[i][j]=0;//初始值为0。
//
//G->arcs[1][2]=2;G->arcs[1][9]=5;//表示景点一到景点二的距离是2。
//
//G->arcs[2][1]=2;G->arcs[2][3]=5;G->arcs[2][4]=4;G->arcs[2][9]=6;
//
//G->arcs[3][2]=5;G->arcs[3][4]=7;G->arcs[3][7]=5;G->arcs[3][9]=6;G->arcs[3][10]=6;
//
=1;i<=N;i++)

for(j=1;j<=N;j++)

if(G->arcs[i][j]==0) G->arcs[i][j]=MAX;//没有被重新赋值的，表示两景点之间

//没有路，用MAX表示无穷大。
//
//}
//
//void path(Matrix_Graph *G,int s,int e)
//
//{
//
//int i,j,u,c=1,t,v;
//
//int r[N+1][N+1];//用来存放路径上的景点。
//
//int T[N],flag[N],d[N];
//
//for(i=0;i<=N;i++)
//
//for(j=0;j<=N;j++) r[i][j]=0;//初始值为0。
//
//for(i=1;i<=N;i++)
//
//{
//
//T[i]=-1;//初始值为-1。
//
//flag[i]=1;//初始值为1。
//
//d[i]=MAX;//路径长度初始值为无穷大，用MAX表示。
//
//}
//
//flag[s]=0;//修改标识。
//
//while(c<=N)
//
//{
//
//t=MAX;
//
//for(i=1;i<=N;i++)
//
//if(flag[i]&&G->arcs[s][i]<t)
//
//{
//
//t=G->arcs[s][i];v=i;r[v][1]=v;}
//
//for(i=1;i<=c;i++)
//
//for(j=1;j<=N;j++)
//
//if(flag[j]&&d[i]+G->arcs[T[i]][j]<t)
//
//{
//
//t=d[i]+G->arcs[T[i]][j];v=j;
//
//if(r[v][0]!=-1)
//
//{
//
//u=1;
//
//while(r[T[i]][u]!=0)
//
//{
//
//r[v][u]=r[T[i]][u];u++;}
//
//}
//
//r[v][u]=v;
//
//}
//
//r[v][0]=-1;
//
//T[c]=v;
//
//flag[v]=0;
//
//d[c]=t;
//
//c++;
//
//}
//
//printf("\nThe path is:\n(%d)",s);
//
//j=1;
//
//while(r[e][j]!=0)
//
//{
//
//printf("-->(%d)",r[e][j]);j++;}//显示路径。
//
//printf("\n\n");
//
//}
//
//void main()//主函数
//
//{
//
//int i,j;
//
//Matrix_Graph G;
//
//creat(&G);
//
//int n = 0; //景点数目             
//
//vexnode  g[MAX];  //保存顶点及其信息
//
//EdgeType e[MAXedg];  //保存边及其信息
//
//adjmax adj; //保存边和定点
//
//char choice = 'x';
//
//while(1)
//
//{
//
//clrscr();
//
//printf("\n\n\t\t\t***校园导游系统***");
//
//printf("\n\t\t*************************************\n\n");
//
//printf("\t\t\t1. 文件读入并创建校园图:\n\n");
//
//printf("\t\t\t2. 查询景点详细信息:\n\n");
//
//printf("\t\t\t3. 查找两景点间最短路径:\n\n");
//
//printf("\t\t\t0. 退出\n\n");
//
//printf("\t\t\tWrite By Edvis@2009/07/06");
//
//printf("\n\t\t************************************\n\n");
//
//printf("Please enter your choice(0-3):\n ");
//
//choice = getchar();
//
//switch(choice)
//
//{
//
//case '1':
//
//clrscr();
//
//creatgraph(g,&n,e,&adj);  //创建图(景点，景点数，边，边和景点)
//
//printf("\n打开文件错误\n");
//
//getchar();
//
//break;
//
//case '2':
//
//clrscr();
//
//travgraph(g,n,adj);//查询景点信息
//
//getchar();
//
//break;
//
//case '3':
//
//clrscr();
//
//printf("\2你目前的位置是：\n");
//
//scanf("%d",&i);
//
//getchar();
//
//printf("\2你的目的地是：\n");
//
//scanf("%d",&j);
//
//getchar();
//
//path(&G,i,j);//查找最短路径
//
//getchar();
//
//creat(&G);
//
//do{
//
//printf("是否继续? Y/N");
//
//char ch;
//
//int flag=1;
//
//scanf("%c",&ch);
//
//getchar();   
//
//if(ch == 'Y' || ch == 'y')  //继续
//
//{
//
//flag = 1;
//
//i = 1;
//
//printf("\2你目前的位置是：\n");
//
//scanf("%d",&i);
//
//getchar();
//
//printf("\2你的目的地是：\n");
//
//scanf("%d",&j);
//
//getchar();
//
//path(&G,i,j);//查找最短路径
//
//getchar();
//
//creat(&G);
//
//continue ;
//
//}
//
//else
//
//flag = 0;  //不继续
//
//break;
//
//}while(1);
//
//break;
//
//case '0':
//
//clrscr();
//
//printf("\n*******按任意键退出********\n");
//
//getchar();
//
//exit(0);
//
//break;
//
//default:
//
//printf("\n输入错误,请重新输入0-3之间的数字:\n");
//
//getchar();
//
//break;
//
//}
//
//}
//
//getchar();
//
//}
//
//
//
