#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#define MAXVEX 30
#define MAXNAME 20
typedef char VexType[MAXNAME];
typedef int AdjType;

typedef struct{
	int n;
	VexType vexs[MAXVEX];
	AdjType arcs[MAXVEX] [MAXVEX];
}GraphMatrix;

typedef struct{
	AdjType len;
	int pre;
}Path;

int LocateVex(GraphMatrix *g,VexType u){
	int i;
	for(i=0;i<g->n;++i)
		if(strcmp(u,g->vexs[i])==0)
			return i;
	return -1;
}

void Init(GraphMatrix *g){
	int i,j,k,w;
	int edgeNums;
	VexType va,vb;
	FILE *graphlist;
	graphlist=fopen("campusnav.txt","r");
	fscanf(graphlist,"%d",&g->n);
	fscanf(graphlist,"%d",&edgeNums);
	for(i=0;i<g->n;++i)
		fscanf(graphlist,"%s",g->vexs[i]);
	for (i=0;i<g->n;++i)
		for(j=0;j<g->n;++j)
			g->arcs[i][j]=INT_MAX;
	for(k=0;k<edgeNums;++k){
		fscanf(graphlist,"%s%s%d",va,vb,&w);
		i=LocateVex(g,va);
		j=LocateVex(g,vb);
		if(i!=-1&&j!=-1){
			g->arcs[i][j]=w;
		}else{
			printf("%s<-<%s读取错误，请您仔细检查!!",va,vb);
			exit(0);
		}
	}
	for(i=0;i<g->n;i++)
		g->arcs[i][i]=0;
	fclose(graphlist);
}

void Dijkstra(GraphMatrix *pgraph,Path dist[],int start){
	int i,j,min;
	AdjType minw;
	dist[start].len=0;
	dist[start].pre=0;
	pgraph->arcs[start][start]=1;
	for(i=0;i<pgraph->n;i++){
		dist[i].len=pgraph->arcs[start][i];
		if(dist[i].len!=INT_MAX)
			dist[i].pre=start;
		else
			dist[i].pre=-1;
	}
	dist[start].pre=-1;
	for(i=0;i<pgraph->n;i++){
		minw=INT_MAX;
		min=start;
		for(j=0;j<pgraph->n;j++)
			if((pgraph->arcs[j][i]==0) &&(dist[j].len<minw)){
				minw=dist[j].len;
				min=j;
			}
		if(min==0)
			break;
		pgraph->arcs[min][min]=1;
		for(j=0;j<pgraph->n;j++){
			if(pgraph->arcs[j][j]==1)
				continue;
			if(dist[j].len>dist[min].len+pgraph->arcs[min][j]&&dist[min].len+pgraph->arcs[min][j]>0)
			{
				dist[j].len=dist[min].len+pgraph->arcs[min][j];
				dist[j].pre=min;
			}
		}
	}
}

int main(int argc,char *argv[]){
	GraphMatrix graph;
	Path path[MAXVEX];
	int tmp,cnt=0,pre=-1;
	int temppath[MAXVEX];
	int m,n;
	VexType va,vb;
	long totallen=0;
	long curlen=0;
	Init(&graph);
	printf("\n请输入您要查询的起点和终点\n");
	scanf("%s%s",va,vb);
	m=LocateVex(&graph,va);
	n=LocateVex(&graph,vb);
	if(m!=-1&&n!=-1){
		Dijkstra(&graph,path,m);
		for (tmp=0;tmp<MAXVEX;tmp++)
			temppath[tmp]=-1;
			pre=n;
			while(path[pre].pre!=-1) {
				temppath[cnt]=pre;
				cnt++;
			}
			temppath[cnt]=m;
			if(cnt<=0){
				if(m!=n)
					printf("%s->%s无路可走\n",graph.vexs[m],graph.vexs[n]);
				else
					printf("您输入的顶点重合!\n");
	}else
	{
		tmp=cnt;
		printf("%s->",graph.vexs[temppath[tmp]]);
		for(;tmp>0;tmp--){
			printf("%s(%d)->",graph.vexs[temppath[tmp-1]],
			graph.arcs[temppath[tmp]][temppath[tmp-1]] ) ;
			totallen+=graph.arcs[temppath[tmp]][temppath[tmp-1]];
		}
		printf("共:%md\n",totallen);
	}
		}else{
			printf("(%s<->%s)中有不存在的城市，请您仔细检查!!",va,vb);
		}
	}

