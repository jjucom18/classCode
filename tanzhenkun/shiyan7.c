#include "string.h"
#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#define Max 20000//最大值为20000
#define NUM 16//顶点最大数为10


typedef struct ArcCell//弧信息
{
int adj; //权值，顶点距离
}ArcCell;

typedef struct VertexType//顶点类型
{
int number; 
char *sight; //景点名称
char *description;//景点介绍
}VertexType;  

typedef struct 
{
VertexType vex[NUM];//顶点向量
ArcCell arcs[NUM][NUM];//数组表示，邻接矩阵
int vexnum,arcnum;//图的当前顶点数和弧数
}MGraph;  

MGraph G;  
int P[NUM][NUM]; //定义景点指针
long int D[NUM]; //最短距离
int   x[16]={0};
void CreateUDN(int v,int a);
void narrate();  
void ShortestPath(int num);
void output(int sight1,int sight2);
char Menu();  
void search();  
char SearchMenu(); 
void   HaMiTonian(int);  
void   NextValue(int);   
void   display();


void main()
{
 
int v0,v1;
char ck;
CreateUDN(NUM,16);//构造图
do
{ 
ck=Menu();
switch(ck)
{
case '1':
system("cls");
narrate();
printf("\n\n\t\t\t请选择起点景点（0～15）：");
scanf("%d",&v0);
printf("\t\t\t请选择终点景点（0～15）：");
scanf("%d",&v1);
ShortestPath(v0); 
output(v0,v1);    
printf("\n\n\t\t\t\t请按ENTER继续...\n");
getchar();
getchar();
break;
case '2':search();
break;
case '3':
system("cls");
//narrate();
x[0]=1;  
HaMiTonian(1);
printf("\n\n\t\t\t\t请按任意键继续...\n");
getchar();
getchar();
break;
};
}while(ck!='e'); 
}


char Menu() 
{
char c;
int flag;
do
{
flag=1;
system("cls");
narrate();
printf("\n\t\t\t┏----------------------------\n");
printf("\t\t\t┃                              ┃\n");
printf("\t\t\t┃      1、查询景点路径         ┃\n");
printf("\t\t\t┃      2、查询景点信息         ┃\n");
printf("\t\t\t┃      3、推荐参观路线         ┃\n");
printf("\t\t\t┃      b、退出                 ┃\n");
printf("\t\t\t┃                              ┃\n");
printf("\t\t\t┗------------------------------\n");
printf("\t\t\t\t请输入您的选择：");
scanf("%c",&c);
if(c=='1'||c=='2'||c=='3'||c=='b')
flag=0;
}while(flag);
     return c;
}

char SearchMenu() //查询景点路径
{
char c;
int flag;
do
{
flag=1;
system("cls");
narrate();
printf("\n\t\t\t-----------------------------\n");
printf("\t\t\t┃                              ┃\n");
printf("\t\t\t┃      1、按照景点编号查询     ┃\n");
printf("\t\t\t┃      2、按照景点名称查询     ┃\n");
printf("\t\t\t┃      b、返回                 ┃\n");
printf("\t\t\t┃                              ┃\n");
printf("\t\t\t┗------------------------------\n");
printf("\t\t\t\t请输入您的选择：");
scanf("%c",&c);
if(c=='1'||c=='2'||c=='b')
flag=0;
}while(flag);
 return c;
}


void search() //查询景点信息
{
int num;
int i;
char c;
char name[20];
 
do
{
system("cls");
c=SearchMenu();
switch (c)
{
case '1': 
system("cls");
narrate();
printf("\n\n\t\t请输入您要查找的景点编号：");
scanf("%d",&num);
for(i=0;i<NUM;i++)
{
if(num==G.vex[i].number)
{
printf("\n\n\t\t\t您要查找景点信息如下:");
printf("\n\n\t\t\t%-25s\n\n",G.vex[i].description);
printf("\n\t\t\t按ENTER返回...");
getchar();
getchar();
break;
}
}
if(i==NUM)
{
printf("\n\n\t\t\t没有找到！");
printf("\n\n\t\t\t按ENTER返回...");
getchar();
getchar();
}  
break;
case '2':
narrate();
system("cls");
printf("\n\n\t\t请输入您要查找的景点名称：");
scanf("%s",name);
for(i=0;i<NUM;i++)
{
if(!strcmp(name,G.vex[i].sight))//?
{
printf("\n\n\t\t\t您要查找景点信息如下:");
printf("\n\n\t\t\t%-25s\n\n",G.vex[i].description);
printf("\n\t\t\t按ENTER返回...");
getchar();
getchar();
break;
}
}
if(i==NUM)
{
printf("\n\n\t\t\t没有找到！");
printf("\n\n\t\t\t按ENTER返回...");
getchar();
getchar();
}
break;
}
}while(c!='e');
}


void CreateUDN(int v,int a)//采用数组表示法，构造无向图G
{
int i,j;
G.vexnum=v; //初始化图的顶点数和边数
G.arcnum=a;
for(i=0;i<G.vexnum;++i) G.vex[i].number=i;//初始化每一个顶点的编号
 
 
 
G.vex[0].sight="九江学院南门";
G.vex[0].description="学生出入最多的大门。";
G.vex[1].sight="南门大礼堂";
G.vex[1].description="讲座、庆典活动、社团演出的场所";
G.vex[2].sight="主图书馆";
G.vex[2].description="九江学院最大的图书馆";
G.vex[3].sight="竞知楼";
G.vex[3].description="九江学院最大教学楼";
G.vex[4].sight="一食堂";
G.vex[4].description="用餐的地方";
G.vex[5].sight="女生宿舍";
G.vex[5].description="女生寝室聚集地";
G.vex[6].sight="男生宿舍";
G.vex[6].description="男生寝室聚集地";
G.vex[7].sight="学生四服楼";
G.vex[7].description="各种商品售卖处及各种快递领取处";
G.vex[8].sight="三食堂";
G.vex[8].description="人流量最多的食堂";
G.vex[9].sight="厚德楼";
G.vex[9].description="校领导办公及部分学生上课的地方";
G.vex[10].sight="香远楼";
G.vex[10].description="英语、马克思学院主要上课的地方";
G.vex[11].sight="文友楼";
G.vex[11].description="会计学院主要上课的地方";
G.vex[12].sight="公共机房";
G.vex[12].description="学生上机处";
G.vex[13].sight="逸夫图书馆";
G.vex[13].description="主校区第二图书馆";
G.vex[14].sight="北区田径馆";
G.vex[14].description="体育活动场所";
G.vex[15].sight="九江学院北门";
G.vex[15].description="学校出入大门";
 
 
for(i=0;i<G.vexnum;++i)
for(j=0;j<G.vexnum;++j)//初始化邻接矩阵
G.arcs[i][j].adj=Max;
G.arcs[0][1].adj=G.arcs[1][0].adj=2;
G.arcs[1][2].adj=G.arcs[2][1].adj=12;
G.arcs[2][3].adj=G.arcs[3][2].adj=7;
G.arcs[2][4].adj=G.arcs[4][2].adj=16;
G.arcs[3][5].adj=G.arcs[5][3].adj=10;
G.arcs[3][7].adj=G.arcs[7][3].adj=23;
G.arcs[4][6].adj=G.arcs[6][4].adj=8;
G.arcs[4][8].adj=G.arcs[8][4].adj=14;
G.arcs[5][9].adj=G.arcs[9][5].adj=18;
G.arcs[5][10].adj=G.arcs[10][5].adj=29;
G.arcs[6][11].adj=G.arcs[11][6].adj=14;
G.arcs[6][12].adj=G.arcs[12][6].adj=36;
G.arcs[7][13].adj=G.arcs[13][7].adj=22;
G.arcs[7][14].adj=G.arcs[14][7].adj=17;
G.arcs[2][6].adj=G.arcs[6][2].adj=23;
G.arcs[3][11].adj=G.arcs[11][3].adj=28;
G.arcs[3][14].adj=G.arcs[14][3].adj=42;
G.arcs[9][13].adj=G.arcs[13][9].adj=25;
G.arcs[9][14].adj=G.arcs[14][9].adj=29;
G.arcs[15][8].adj=G.arcs[8][15].adj=56;
G.arcs[0][8].adj=G.arcs[8][0].adj=32;
G.arcs[0][6].adj=G.arcs[6][0].adj=27;
}


void narrate()//界面美化
{
int i,k=0;
printf("\n\t\t*****************欢迎使用校园导游程序***************\n");
printf("\n\t\t*************亲，很高兴为您服务江西省最美大学*****************\n");
printf("\n\t\t********************江西省九江学院*******************\n");
printf("\n\t\t****************************************");
printf("\n\t\t**********************景点名称***********************\n");
printf("\t\t\t****************************************\n");
for(i=0;i<NUM;i++)
{
printf("\t\t\t\t\t(%2d)%-10s\t\t\t\n",i,G.vex[i].sight);
k=k+1;
}
printf("\t_________________________________________________________________\n");
}


void ShortestPath(int num)//最短路径
{
int v,w,i,t; 
int final[NUM];  //辅助数组
int min;
for(v=0;v<NUM;v++)
{
final[v]=0; 
D[v]=G.arcs[num][v].adj;
for(w=0;w<NUM;w++)
 P[v][w]=0;
if(D[v]<20000) 
{
P[v][num]=1;
P[v][v]=1;
}
}
 
D[num]=0;
final[num]=1;     
       
for(i=0;i<NUM;++i)    
{
min=Max;    
for(w=0;w<NUM;++w)
if(!final[w])   
if(D[w]<min)  
{
v=w;
min=D[w];
}
final[v]=1;  
for(w=0;w<NUM;++w) 
if(!final[w]&&((min+G.arcs[v][w].adj)<D[w]))
{
D[w]=min+G.arcs[v][w].adj;
for(t=0;t<NUM;t++)
P[w][t]=P[v][t];
P[w][w]=1;
}
}
}


void output(int sight1,int sight2)   //输出界面
{
int a,b,c,d,q=0;
a=sight2;   
if(a!=sight1)   
 {
printf("\n\t从%s到%s的最短路径是",G.vex[sight1].sight,G.vex[sight2].sight);
printf("\t(最短距离%ld)\n\n\t",D[a]); 
printf("\t%s",G.vex[sight1].sight);  
d=sight1;     
for(c=0;c<NUM;++c)
{
gate:;       //?
P[a][sight1]=0;
for(b=0;b<NUM;b++)
{
if(G.arcs[d][b].adj<20000&&P[a][b]) 
{
printf("-->%s",G.vex[b].sight); 
q=q+1;    
P[a][b]=0;
d=b;    
if(q%8==0) printf("\n");
goto gate;
}
}
}
}
}


void HaMiTonian(int m) //哈密尔顿图遍历,用来求推荐路线
{
if(m>11)   return;  
L: NextValue(m);  
if(x[m]==0)  
return;  
if(m==9&G.arcs[0][x[15]-1].adj!=20000)  
display();  
else  
HaMiTonian(m+1);  
goto   L;  
}


void NextValue(int k)  //哈密顿函数中用到此函数
{  
int j;  
l:x[k]=(x[k]+1)%16;  
if(x[k]==0)  
return;  
if(G.arcs[x[k-1]-1][x[k]-1].adj!=20000)  
{  
for(j=0;j<k;j++)  
if(x[j]==x[k])  
goto l;  
return;      
}  
else  
goto l;      
} 

 
void display()  
{  
int i=0;
printf("\n\n\t");
for(i=0;i<15;i++)  
printf("%s->",G.vex[x[i]-1].sight);  
printf("出口");
printf("\n");
}  
