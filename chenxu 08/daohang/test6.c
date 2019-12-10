#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max 10000
#define NUM 11
typedef struct ArcCell{
int adj;
char *info;
}ArcCell;
typedef struct VertexType{
int number;
char *sight;
}VertexType;
typedef struct{
VertexType vex[NUM];
ArcCell arcs[NUM][NUM];
int vexnum,arcnum;
}MGraph;
MGraph G;
int P[NUM][NUM];
long int D[NUM];
int x[13]={0};
void CreateUDN(int v,int a);
void pingmu();
void ShortestPath(int num);
void output(int sight1,int sight2);
char Menu();
void NextValue(int);
int main() // 主函数
{ int v0,v1;
char ck;
CreateUDN(NUM,11);
do
{
ck=Menu();
switch(ck)
{
case '1':
pingmu();
printf("\n\n\t\t\t请选择出发地序号（1～10）：");
scanf("%d",&v0);
printf("\t\t\t请选择目的地序号（1～10）：");
scanf("%d",&v1);
ShortestPath(v0);
output(v0,v1);
printf("\n\n\t\t\t\t请按回车键继续...\n");
getchar();
getchar();
break;
case'2':
 printf("\n");
 printf("\n");
 getchar();
getchar();
 break;
};
}while(ck!='e');
return 0;
}
char Menu() // 主菜单
{
char c;
int flag;
do{
flag=1;
pingmu();
printf("\n\t\t****************************************\n");
printf("\t\t九江学院学生导航系统\n");
printf("\t\t 1.查询景点路径 \n");
printf("\t\t 2.系统简介\n");
printf("\t\t e.退出 \n");
printf("\t\t****************************************\n");
printf("\t\t\t请输入您的选择：");
scanf("%c",&c);
if(c=='1'||c=='2'||c=='e')
flag=0;
}while(flag);
return c;
}
void CreateUDN(int v,int a) // 创建图的函数
{
int i,j;
G.vexnum=v;
G.arcnum=a;
for(i=1;i<G.vexnum;++i) G.vex[i].number=i;
G.vex[0].sight="各个景点名字";
G.vex[1].sight="竞知楼";
G.vex[2].sight="北门";
G.vex[3].sight="女生宿舍";
G.vex[4].sight="南门";
G.vex[5].sight="男生宿舍";
G.vex[6].sight="主图书馆";
G.vex[7].sight="食堂";
G.vex[8].sight="望庐楼";
G.vex[9].sight="体育馆";
G.vex[10].sight="西门";
for(i=1;i<G.vexnum;++i)
{
for(j=1;j<G.vexnum;++j)
{
G.arcs[i][j].adj=Max;
G.arcs[i][j].info=NULL;
}
}
 
 
G.arcs[1][4].adj=G.arcs[4][1].adj=600;
G.arcs[1][3].adj=G.arcs[3][1].adj=400;
G.arcs[3][5].adj=G.arcs[5][3].adj=1000;
G.arcs[3][10].adj=G.arcs[10][3].adj=800;
G.arcs[4][6].adj=G.arcs[6][4].adj=400;
G.arcs[2][5].adj=G.arcs[5][2].adj=900;
G.arcs[2][4].adj=G.arcs[4][2].adj=2000;
G.arcs[5][7].adj=G.arcs[7][5].adj=300;
G.arcs[4][6].adj=G.arcs[6][4].adj=400;
G.arcs[4][7].adj=G.arcs[7][4].adj=1200;
G.arcs[6][8].adj=G.arcs[8][6].adj=150;
G.arcs[7][8].adj=G.arcs[8][7].adj=700;
G.arcs[6][9].adj=G.arcs[9][6].adj=1300;
G.arcs[3][10].adj=G.arcs[10][3].adj=800;
}
void pingmu() // 输出函数
{
int i;
printf("                          九江学院景点\n");
for(i=1;i<NUM;i++)
{
printf("\t\t\t\t(%2d)%-20s\t\t\t",i,G.vex[i].sight);
}
}
void ShortestPath(int num) // 迪杰斯特拉算法最短路径
{
int v,w,i,t;
int final[NUM];
int min;
for(v=1;v<NUM;v++)
{
final[v]=0;
D[v]=G.arcs[num][v].adj;
for(w=1;w<NUM;w++)
P[v][w]=0;
if(D[v]<32767)
{
P[v][num]=1;
P[v][v]=1;
}
}
D[num]=0;
final[num]=1;
for(i=1;i<NUM;++i)
{
min=Max;
for(w=1;w<NUM;++w)
if(!final[w])
if(D[w]<min)
{
v=w;
min=D[w];
}
final[v]=1;
for(w=1;w<NUM;++w)
if(!final[w]&&((min+G.arcs[v][w].adj)<D[w]))
{
D[w]=min+G.arcs[v][w].adj;
for(t=0;t<NUM;t++)
P[w][t]=P[v][t];
P[w][w]=1;
}
}
}
void output(int sight1,int sight2) // 输出函数
{
int a,b,c,d,q=0;
a=sight2;
if(a!=sight1)
{
printf("\n\t从%s到%s的最短路径是",G.vex[sight1].sight,G.vex[sight2].sight);
printf("\t(最短距离为 %dm.)\n\n\t",D[a]);
printf("\t%s",G.vex[sight1].sight);
d=sight1;
for(c=0;c<NUM;++c)
{
gate:;
P[a][sight1]=0;
for(b=0;b<NUM;b++)
{
if(G.arcs[d][b].adj<32767&&P[a][b])
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