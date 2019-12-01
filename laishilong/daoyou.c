#include<stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#define INF 20000
#define MAX 20
typedef struct ArCell
{
	int adj; 
}
ArCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct 
{
char name[30];
int num;
char introduction[100];
}
infotype;
typedef struct
{
	infotype vexs[MAX_VERTEX_NUM]; AdjMatrix arcs;
int vexnum,arcnum;
}
MGraph; MGraph b;
MGraph InitGraph(void); 
void Browser(MGraph *G);
void ShortestPath_DIJ(MGraph * G);
void Floyd(MGraph *G);stdio.h
int LocateVex(MGraph *G,char* v);
MGraph * CreateUDN(MGraph *G);
void print(MGraph *G);
void main(void)
{
int i;
b=InitGraph();
while(i!=5)
{ 
printf("\n 九江学院导游系统 \n");
printf(" 1.浏览校园全境 \n");
printf(" 2.查看所有游览路径 \n");
printf(" 3.选择出发地点和目的地 \n");
printf(" 4.创建新的景点信息\n");
printf(" 5.退出 \n");
printf("Option-:");
scanf("%d",&i);
switch(i)
{
case 1:system("cls");Browser(&b);break;
case 2:system("cls");ShortestPath_DIJ(&b);break;
case 3:system("cls");Floyd(&b);break;
case 4:system("cls");CreateUDN(&b);break;
case 5:exit(1);break;
default:break;
    }
  }
}
MGraph InitGraph(void)
{
MGraph G;
int i,j;
G.vexnum=10;
G.arcnum=14;
for(i=0;i<G.vexnum;i++)
G.vexs[i].num=i;
strcpy(G.vexs[0].name,"南门");
strcpy(G.vexs[0].introduction,"九院南大门");
strcpy(G.vexs[1].name,"主图");
strcpy(G.vexs[1].introduction,"九院主图书馆");
strcpy(G.vexs[2].name,"红楼");
strcpy(G.vexs[2].introduction,"九江学院标志性建筑");
strcpy(G.vexs[3].name,"竞知楼");
strcpy(G.vexs[3].introduction,"九院最大的教学楼");
strcpy(G.vexs[4].name,"一食堂");
strcpy(G.vexs[4].introduction,"九院第一食堂");
strcpy(G.vexs[5].name,"11栋");
strcpy(G.vexs[5].introduction,"女生宿舍");
strcpy(G.vexs[6].name,"15栋");
strcpy(G.vexs[6].introduction,"男生宿舍");
strcpy(G.vexs[7].name,"室内田径馆");
strcpy(G.vexs[7].introduction,"九院北区体育场，新生报名处");
strcpy(G.vexs[8].name,"西门");
strcpy(G.vexs[8].introduction,"九院西大门");
strcpy(G.vexs[9].name,"北门");
strcpy(G.vexs[9].introduction,"九院北大门");
for(i=0;i<G.vexnum;i++)
for(j=0;j<G.vexnum;j++)
G.arcs[i][j].adj=INFINITY;
G.arcs[0][1].adj=200;
G.arcs[1][2].adj=300; G.arcs[2][3].adj=200;
G.arcs[2][4].adj=100; G.arcs[3][4].adj=150;
G.arcs[3][5].adj=100; G.arcs[3][6].adj=250;
G.arcs[5][7].adj=750; G.arcs[5][6].adj=150;
G.arcs[5][8].adj=950; G.arcs[6][8].adj=800;
G.arcs[6][7].adj=600; G.arcs[7][9].adj=300;
G.arcs[8][9].adj=100;
for(i=0;i<G.vexnum;i++)
for(j=0;j<G.vexnum;j++)
G.arcs[j][i].adj=G.arcs[i][j].adj;
return G;
}
void Browser(MGraph *G)
{ 
	int v;
    printf(" 编号 景点名称 简介 \n");
    for(v=0;v<G->vexnum;v++)
    printf(" %-4d %-16s %-56s \n",G->vexs[v].num,G->vexs[v].name, G->vexs[v].introduction);
}
void ShortestPath_DIJ(MGraph * G)
{
int v,w,i,min,t=0,x,flag=1,v0;
int final[20], D[20], p[20][20];
while(flag)
{
	printf("请输入一个起始景点编号:");
    scanf("%d",&v0);
if(v0<0||v0>G->vexnum)
{ 
	printf("景点编号不存在!请重新输入景点编号:"); scanf("%d",&v0); }
    if(v0>=0&&v0<G->vexnum)
    flag=0;
}
for(v=0;v<G->vexnum;v++)
{ 
	final[v]=0; D[v]=G->arcs[v0][v].adj;
    for(w=0;w<G->vexnum;w++)
    p[v][w]=0;
if(D[v]<INFINITY)
{ 
	p[v][v0]=1; p[v][v]=1;
   }
}
    D[v0]=0;final[v0]=1;
for(i=1;i<G->vexnum;i++)
{
	min=INFINITY;
    for(w=0;w<G->vexnum;w++)
    if(!final[w])
    if(D[w]<min){v=w;min=D[w];}
    final[v]=1;
    for(w=0;w<G->vexnum;w++)
    if(!final[w]&&(min+G->arcs[v][w].adj<D[w]))
{
    D[w]=min+G->arcs[v][w].adj;
    for(x=0;x<G->vexnum;x++)
    p[w][x]=p[v][x];
    p[w][w]=1;
   }
}
for(v=0;v<G->vexnum;v++)
{
	if(v0!=v) printf("%s",G->vexs[v0].name);
    for(w=0;w<G->vexnum;w++)
{
	if(p[v][w]&&w!=v0) printf("-->%s",G->vexs[w].name);
    t++;
}
if(t>G->vexnum-1&&v0!=v)printf(" 总路线长%dm\n\n",D[v]);
   }
}
void Floyd(MGraph *G)
{ 
	int v,u,i,w,k,j,flag=1,p[10][10][10],D[10][10];
    for(v=0;v<G->vexnum;v++)
    for(w=0;w<G->vexnum;w++)
{
	D[v][w]=G->arcs[v][w].adj;
    for(u=0;u<G->vexnum;u++)
    p[v][w][u]=0;
    if(D[v][w]<INFINITY)
{
	p[v][w][v]=1;p[v][w][w]=1;
   }
}
for(u=0;u<G->vexnum;u++)
for(v=0;v<G->vexnum;v++)
for(w=0;w<G->vexnum;w++)
if(D[v][u]+D[u][w]<D[v][w])
{
	D[v][w]=D[v][u]+D[u][w];
    for(i=0;i<G->vexnum;i++)
    p[v][w][i]=p[v][u][i]||p[u][w][i];
}
while(flag)
{
printf("请输入出发点和目的地的编号:");
scanf("%d%d",&k,&j);
if(k<0||k>G->vexnum||j<0||j>G->vexnum)
{
printf("景点编号不存在!请重新输入出发点和目的地的编号:");
scanf("%d%d",&k,&j);
}
if(k>=0&&k<G->vexnum&&j>=0&&j<G->vexnum)
flag=0;
}
printf("%s",G->vexs[k].name);
for(u=0;u<G->vexnum;u++)
if(p[k][j][u]&&k!=u&&j!=u)
printf("-->%s",G->vexs[u].name);
printf("-->%s",G->vexs[j].name);
printf(" 总路线长%dm\n",D[k][j]);
}
int LocateVex(MGraph *G,char* v) 
{
    int c=-1,i;
for(i=0;i<G->vexnum;i++)
if(strcmp(v,G->vexs[i].name)==0)
{
	c=i;break;}
    return c;
}
MGraph * CreateUDN(MGraph *G)
{
int i,j,k,w;
char v1[20],v2[20];
printf("请输入图的顶点数,弧数:");
scanf("%d%d",&G->vexnum,&G->arcnum);
printf("请输入景点的编号、名称、简介:\n");
for(i=0;i<G->vexnum;i++)
{
printf("景点编号:");
scanf("%d",&G->vexs->num);
printf("景点名称:");
scanf("%s",G->vexs[i].name);
printf("景点简介:");
scanf("%s",G->vexs->introduction);
}
for(i=0;i<G->vexnum;i++)
for(j=0;j<G->vexnum;j++)
G->arcs[i][j].adj=INFINITY;
printf("请输入路径信息:\n");
for(k=0;k<G->arcnum;k++)
{
printf("第%d条边:\n",k+1);
printf("景点对(x,y):"); scanf("%s",v1); scanf("%s",v2);
printf("路径长度:"); scanf("%d",&w);
i=LocateVex(G,v1);
j=LocateVex(G,v2);
if(i>=0&&j>=0)
{ 
	G->arcs[i][j].adj=w;
    G->arcs[j][i]=G->arcs[i][j]; }
   } return G;
}
void print(MGraph *G)
{
	int v,w,t=0;
for(v=0;v<G->vexnum;v++)
for(w=0;w<G->vexnum;w++)
{ 
	if(G->arcs[v][w].adj==INFINITY)
printf("? ");
else printf("%-7d",G->arcs[v][w].adj);
    t++;
if(t%G->vexnum==0)
printf("\n");
   }
}

