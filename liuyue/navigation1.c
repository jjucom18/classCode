#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stack>
#define INF 999999
#define M 20
int dist[M][M];
int path[M][M];
int Stack[M];
int top;
int counts;
int visited[M];
using namespace std;
struct vertex {
	int num;
	char name[20];
	char info[300];
};
struct maps {
	int n;
	int m;
	vertex v[M];
	int edgs[M][M];
}g;
void Creat_vertex() {
	g.v[0].num=1;
	strcpy(g.v[0].name,"红楼") ；
    g.v[1].num=2;
	strcpy(g.v[1].name,"教工食堂")；
    g.v[2].num=3;
	strcpy(g.v[2].name,"图书馆主馆")；
	g.v[3].num=4;
	strcpy(g.v[3].name,"竞知楼")；
	g.v[4].num=5;
	strcpy(g.v[4].name,"-食堂")；
	strcpy(g.v[4].info,"边上有一个中通快递快递点")；
	g.v[5].num=6;
	strcpy(g.v[5].name,"女生宿舍11栋")；
	g.v[6].num=7;
	strcpy(g.v[6].name,"男生宿舍15栋")；
	g.v[7].num=8;
	strcpy(g.v[7].name,"五食堂")；
	strcpy(g.v[7].info,"后面是莲池")；	
	g.v[8].num=9;
	strcpy(g.v[8].name,"三食堂")；
	g.v[9].num=10;
	strcpy(g.v[9].name,"四服楼")；
	g.v[10].num=11;
	strcpy(g.v[10].name,"28栋")；
	g.v[11].num=12;
	strcpy(g.v[11].name,"香远楼")；
	g.v[12].num=13	;
	strcpy(g.v[12].name,"厚德楼")；
	g.v[13].num=14	;
	strcpy(g.v[13].name,"机房")；
	g.v[14].num=15	;
	strcpy(g.v[14].name,"逸夫楼")；
	g.v[15].num=16;
	strcpy(g.v[15].name,"室内田径馆")；
	g.v[16].num=17;
	strcpy(g.v[16].name,"操场")；

			
}
void Creat_maps() {
	int i,j;
	g.n=17;
	g.m=16;
	for(i=0;i<g.n;i++)
	{
		g.edgs[i][j]=INF;
	}
}
g.edgs[0][1]=g.edgs[1][0]=
g.edgs[1][2]=g.edgs[2][1]=
g.edgs[2][3]=g.edgs[3][2]=
g.edgs[3][4]=g.edgs[4][3]=
g.edgs[4][5]=g.edgs[5][4]=
g.edgs[5][6]=g.edgs[6][5]=
g.edgs[6][7]=g.edgs[7][6]=
g.edgs[7][8]=g.edgs[8][7]=
g.edgs[8][9]=g.edgs[9][8]=
g.edgs[9][10]=g.edgs[10][9]=
g.edgs[10][11]=g.edgs[11][10]=
g.edgs[11][12]=g.edgs[12][11]=
g.edgs[12][13]=g.edgs[13][12]=
g.edgs[13][14]=g.edgs[14][13]=
g.edgs[14][15]=g.edgs[15][14]=
g.edgs[15][16]=g.edgs[16][15]=

}
void Search_info() {
	int i,n;
	printf("九江学院的景点有：\n");
for(i=0;i<13;i++)
{
	printf("%d:%s\n",g.v[i].num,g.v[i].name);
}
while(1)
{
	printf("请输入你想要查询的景点编号：\n");
	printf("按0退出\n\n");
	scanf("%d",&n);
	getcahr();
	if(n==0)
	{
		break;
	}
	else if(n<0||n>13)
	{
		printf("输入有误，请重新输入！！！\n\n");
		continue;
	}
	else
	{
		printf("%d:%s\n",g.v[n-1].num,g.v[n-1].name);
		printf("%s\n\n",g.v[n-1].info);
	}

}
return;
}
void Floyd()
{
	int i,j,k;
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
		{
			dist[i][j]=g.edgs[i][j];
			if(i!=j&&dist[i][j]<INF)
			{
				path[i][j]=i;
			}
			else
			{
				path[i][j]=-1;
			}
		}
	}
}
for(k=0;k<g.n;k++)
{
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
		{
			if(dist[i][j]>(dist[i][k]+dist[k][j]))
			{
				dist[i][j]=dist[i][k]+dist[k][j];
				path[i][j]=k;
			}
		}
	}
}
return;
} 
void Floyd_print(int s,int e)
{
	if(path[s][e]==-1||path[s][e]==e||path[s][e]==s)
	{
		return;
	}
	else
	{
		Floyd_print(s,path[s][e].name);
		Floyd_print(path[s][e],e);
	}
}
void Dfs_allpath(int s,int e)
{
	int dis=0;
	int i,j;
	Stack[top]=s;
	top++;
	visited[s]=1;
	for(i=0;i<g.n;i++)
	{
		if(g.edgs[s][i]>0&&g.edgs[s][i]!=INF&&visited[i])
		{
			if(i==e)
			{
				printf("%s->",g.v[Stack[j]].name);
				if(j<top-1)
				{

				}
			}
		}
	}
}
