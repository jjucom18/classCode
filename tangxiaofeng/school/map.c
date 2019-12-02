#include"map.h"
/*校园地图*/
void Browser()
{
system ("color 00");
printf(" 九江学院校园平面图");
printf("\n");
printf(" 南门 ");
printf("\n");
printf(" // || \\ \\ ");
printf("\n");
printf(" // || \\ \\ ");
printf("\n");
printf(" // 逸夫图书馆===实训楼======北区田径馆");
printf("\n");
printf(" // || ");
printf("\n");
printf("// || ");
printf("\n");
printf("三食堂 || ");
printf("\n");
printf(" \\ || ");
printf("\n");
printf(" 莲湖 ");
printf("\n");
printf(" || ");
printf("\n");
printf(" || ");
printf("\n");
printf(" 主图书馆=====竟知楼=====南区田径场 ");
printf("\n");
printf(" \\ \\ // ");
printf("\n");
printf(" \\ \\ // ");
printf("\n");
printf(" \\ \\ // ");
printf("\n");
printf("文理实验楼 ");
printf("\n");
printf(" // ");
printf("\n");
printf(" // ");
printf("\n");
printf(" 望庐楼 ");
}
/*已存景点阅览*/
void PlaceList()
{
system ("color 00");
printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
printf("\t\t┃已存文件景点一览表 ┃\n");
printf("\t\t┣━━━━━━━━━━━━┳━━━━━━━━━━━━┫\n");
printf("\t\t┃1.逸夫图书馆 ┃2.实训楼 ┃\n");
printf("\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n");
printf("\t\t┃3.三食堂 ┃4.北区体育馆 ┃\n");
printf("\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n");
printf("\t\t┃5.莲湖 ┃6.竟知楼 ┃\n");
printf("\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n");
printf("\t\t┃7.主图书馆 ┃8.文理实验楼 ┃\n");
printf("\t\t┣━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n");
printf("\t\t┃9.南区田径场 ┃10.望庐楼 ┃\n");
printf("\t\t┗━━━━━━━━━━┻━━━━━━━━━━━━┛\n");
}
/*访问标志数组初始化*/
void creatvisited(adjmatrix *g)
{
int i;
for(i=0; i<g->vexnum; i++)
visited[i]=0;
}
/*遍历*/
void search(adjmatrix *g)
{
int i,n;
creatvisited(g);
for(i=0; i<g->vexnum; i++)
printf("%d\t%s\n",g->vertex[i].top,g->vertex[i].info);
printf("请输入遍历的起点序号:(1-%d)\n",g->vexnum);
scanf("%d",&n);
DFS(g,n-1);
}
/*深度遍历*/
void DFS(adjmatrix *g,int v)
{
int k;
visited[v]=1;//置已访问标记
printf("景点序号:%d 名称:%s\n",g->vertex[v].top,g->vertex[v].info);
for(k=0; k<g->vexnum; k++)
if(!visited[k]&&g->arcs[v][k].adj!=INF)
DFS(g,k);
}
/*已存景点信息文本*/
void vernumfile(adjmatrix *g)
{
FILE *fp;
int i;
fp=fopen("vernum.txt","wt");
for(i=0; i<g->vexnum; i++)
fprintf(fp,"%d %s %s\n",g->vertex[i].top,g->vertex[i].info,g->vertex[i].introduce);
fclose(fp);
}
/*已存景点间路径文本*/
void arcnumfile(adjmatrix *g)
{
FILE *fp;
int i,j;
fp=fopen("arcnum.txt","wt");
for(i=0; i<g->arcnum; i++)
for(j=0; j<g->arcnum; j++)
if(g->arcs[i][j].adj!=INF)
{
fprintf(fp,"%d %d %d\n",g->vertex[i].top,g->vertex[j].top,g->arcs[i][j].adj);
}
fclose(fp);
}
/*读取景点信息*/
void readvernum(adjmatrix *g)
{
FILE *fp;
int i=0;
fp=fopen("vernum.txt","rt");
while(fscanf(fp,"%d %s %s",&g->vertex[i].top,g->vertex[i].info,g->vertex[i].introduce)!=EOF)
{
printf("景点序号:%d 名称:%s\n",g->vertex[i].top,g->vertex[i].info);
printf("景点信息:%s\n",g->vertex[i].introduce);
printf("\n");
i++;
}
g->vexnum=i;
fclose(fp);
}
/*读取路径信息*/
void readarcnum(adjmatrix *g)
{
FILE *fp;
int i=0,j=0,k=0;
for(i = 0; i<g->vexnum; i++)
for(j = 0; j<g->vexnum; j++)
g->arcs[i][j].adj =INF;
fp=fopen("arcnum.txt","rt");
while(fscanf(fp,"%d %d %d",&i,&j,&k)!=EOF)
{
g->arcs[i-1][j-1].adj=k;
}
fclose(fp);
}
/* 读取景点信息*/
void findvernum(adjmatrix *g)
{
int i,n;
char choice;
for(i=0; i<g->vexnum; i++)
printf("%d\t%s\n",g->vertex[i].top,g->vertex[i].info);
do
{
printf("请输入要查询的景点序号(1-%d):\n",g->vexnum);
scanf("%d",&n);
printf("景点名称:%s\n",g->vertex[n-1].info);
printf("景点信息:%s\n",g->vertex[n-1].introduce);
printf("\n");
printf("是否继续查询:(y/n):\n");
_flushall();
scanf("%c",&choice);
}
while(choice=='Y'||choice=='y');
}
/*弗洛伊德算法*/
void floyd(adjmatrix *g)
{
int i,j,k;
for(i=0; i<g->vexnum; i++)
for(j=0; j<g->vexnum; j++)
shortest[i][j]=0;
for(i=0; i<g->vexnum; i++)
for(j=0; j<g->vexnum; j++)
{
shortest[i][j]=g->arcs[i][j].adj;
path[i][j]=0;
}
for(i=0; i<g->vexnum; i++)
for(j=0; j<g->vexnum; j++)
for(k=0; k<g->vexnum; k++)
if(shortest[i][j]>(shortest[i][k]+shortest[k][j]))
{
shortest[i][j]=shortest[i][k]+shortest[k][j];
path[i][j]=k;
path[j][i]=k;
}
}
/*最短路径*/
void shortload(adjmatrix *g)
{
int i,j,a,b;
PlaceList();
floyd(g);
printf("请输入起始景点和终止景点(1-%d):\n",g->vexnum);
scanf("%d%d",&i,&j);
a=i;
b=j;
i=i-1;
j=j-1;
if(i<j)
{
printf("%d",b);
while(path[i][j]!=0)
{
printf("<-%d",path[i][j]+1);
if(i<j)
j=path[i][j];
else
i=path[j][i];
}
printf("<-%d",a);
printf("\n\n");
printf("%d->%d 距离是:%d米\n\n",a,b,shortest[a-1][b-1]);
}
else
{
printf("%d",a);
while(path[i][j]!=0)
{
printf("<-%d",path[i][j]+1);
if(i<j)
j=path[i][j];
else
i=path[j][i];
}
printf("<-%d",b);
printf("\n\n");
printf("%d->%d 最短距离是:%d米\n\n",a,b,shortest[a-1][b-1]);
}
}
/*菜单栏*/
int meun()
{
char choice;
adjmatrix *g;
g=(adjmatrix *)malloc(sizeof(adjmatrix));//创建头结点
system ("color 00");
while(1)
{
printf("\n");
printf("\t\t************************************************\n");
printf("\t\t***************校园景点导航系统*****************\n");
printf("\t\t*****************欢迎您的使用*******************\n");
printf("\t\t************************************************\n");
printf("\t\t**\t 1: 读取文件信息**\n");
printf("\t\t**\t 2: 遍历景点信息**\n");
printf("\t\t**\t 3: 查询景点信息**\n");
printf("\t\t**\t 4: 查询最短路径**\n");
printf("\t\t**\t 5: 查看景点地图**\n");
printf("\t\t**\t 0: 退出查询系统**\n");
printf("\t\t************************************************\n");
printf("\t\t************************************************\n");
printf("\n");
printf("请选择需要使用的功能序号:");
choice=getchar();
switch(choice)
{
case '1':
{
readvernum(g);
readarcnum(g);
break;
}
case '2':
{
search(g);
break;
}
case '3':
{
findvernum(g);
break;
}
case '4':
{
shortload(g);
break;
}
case '5':
{
Browser(g);
break;
}
case '0':
{
printf("谢谢使用,再见!\n");
exit(0);
}
}
printf("请按任意键继续.....");
getch();
_flushall();//清除所有缓冲区
system("cls");
}
}

