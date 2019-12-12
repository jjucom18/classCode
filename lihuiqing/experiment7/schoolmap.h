#ifndef schoolmap_h
#define schoolmap_h
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#define MAXVEX 30
#define MAXNAME 20
typedef char VexType[MAXNAME];
typedef int AdjType;

typedef struct {
	int n;
	VexType vexs[MAXVEX];
	VexType arcs[MAXVEX][MAXVEX];
}GraphMatrix;

typedef struct {AdjType len;
	int pre;
}Path;

int LocateVex(GraphMatrix *s,VexType p)
	int i;
	for (i=0;i<s->n;++i)
	if(strcmp(p,s->vexs[i])==0)
	return i;
	return -1;
	}

void Init(GraphMatrix *s)
	int i,j,k,w;
	int edgeNums; 
VexType va,vb;
FILE *graphlist;
graphlist = fopen("schoolmap.txt","r");
fscanf(graphlist,"%d",&g->n);
fscanf(graphlist,"%d",&edgeNums);
for (i=0;i<g->n;++i)
fscanf(graphlist,"%s",g->vexs[i]);
for (i=0;i<g->n;++j)
g->arcs[i][j]=INT_MAX;
for (k=0;k<edgeNums;++k)
{fscanf(graphlist,"%s%s%d",va,vb,&w);
	i=LocateVex(g,va);
	j=LocateVex(g,vb);
	if (i!=-1&&j!=-1)
		g->arcs[i][j]=w;}
		else
{printf("%s<->%s读取错误，请仔细检查!!!",va,vb);
	exit(0);}}
	for (i=0;i<g->n;i++)
	g->arcs[i][j]=0;
	fclose(graphlist);}

	void Dijkstra(GraphMatrix *pgraph,Path dist[],int start)
{int i,j,min;
	AdjType minw;
	dist[start].len = 0;
	dist[start].pre = 0;
	pgraph->arcs[start][start] = 1;
	for (i=0;i<pgraph->n;i++)
		dist[i].len = pgraph->arcs[start][i];
	if (dist[i].len != INT_MAX)
		dist[i].pre = start;
	else
		dist[i].pre = -1;}
		dist[start].pre = -1;
		for (i=0;i<pgraph->n;i++)
{minw = INT_MAX;
	min = start;
	for (j=0;j<pgraph->n,j++)
		if((pgraph->arcs[j][j]==0)&&(dist[j].len<minw))
			minw = dist[j].len;
	min = j;}
	if (min == 0)
	break;
	pgraph->arcs[min][min] = 1;
	for (j=0;j<pgraph->n;j++)
	if (pgraph->arcs[j][j] == 1
			continue;
			if (dist[j].len>dist[min].len+pgraph->arcs[min][j]&&dist[min].len+pgraph->arcs[min][j]>0
				{dist[j].len = dist[min].len + pgraph->arcs[min][j];
				dist[j].pre = min;
				}
			}
		}
	}
