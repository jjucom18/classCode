#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define INFINITY 10000
#define M 20

typedef struct{
	char V[M][10];
	int R[M][M];
	int vexnum;
}Graph;

typedef struct tree{
	int weizhi;
	int lowcost;
};

int locatevex(Graph *g,char a[10])
{int i;
	for(i=0;i<g->vexnum;i++)
	{if(strcmp(a,g->V[i])==0)
			return i;
			}
			if(i==g->vexnum)
			return -1;
			}

int creatgraph(Graph *g){
int i=0;
int j,m,k,p;
char a[10],b[10];
printf("所以的辖区，以0为结束\n");
scanf("%s",g->V[i]);
while(strcmp("0",g->V[i])!=0){
i++;
scanf("%s",g->V[i]);
}
g->vexnum=i;
for(i=0;i<g->vexnum;i++)
for(j=0;j<g->vexnum;j++)
g->R[i][j]=INFINITY;
	printf("辖区之间的路程，以0 0 0为结束标志\n");
scanf("%s %s %d",a,b,&m);
while(strcmp("0",a)!=0||strcmp("0",b)!=0||m!=0)
{
	k=locatevex(g,a);
	p=locatevex(g,b);
	if(k==-1)
	{printf("没有%s这个辖区\n",a);
		return 0;
	}
	if(p==-1){
		printf("没有%s这个辖区\n",b);
		return 0;
	}
	g->R[k][p]=g->R[p][k]=m;
	scanf("%s%s%d",a,b,&m);
}
return 1;
}

int minimun(struct tree *a,Graph g){
	int i,k,m=0;
	for(i=0;i<g.vexnum;i++){
		if(m==0&&a[i].lowcost!=0){
			m=1;
			k=i;
		}
	}
return k;
}
void  MiniSpanTree_PRIM(Graph g,char a[10]){
	struct tree closedge[M];
	int i,j,k,money=0;
	k=locatevex(&g,a);
	for(i=0;i<g.vexnum;i++){
		if(i!=k){
			closedge[i].lowcost=g.R[k][i];
			closedge[i].weizhi=k;
		}
	}
	closedge[k].lowcost=0;
	for(i=1;i<g.vexnum;i++){
		k=minimun(closedge,g);
		money+=closedge[k].lowcost;
		printf("%d:%s %s %d\n",i,g.V[closedge[k].weizhi],g.V[k],closedge[k].lowcost);
		closedge[k].lowcost=0;
		for(j=0;j<g.vexnum;j++){
			if(g.R[k][j]<closedge[j].lowcost){
				closedge[j].weizhi=k;
				closedge[j].lowcost=g.R[k][j];
			}
		}
	}
	printf("总费用为:%d\n",money);
}

void main(){
	int i;
	Graph g;
	char a[10];
	i=creatgraph(&g);
	if(i){
		printf("从哪里开始:");
		scanf("%s",a);
		MiniSpanTree_PRIM(g,a);
	}
}

