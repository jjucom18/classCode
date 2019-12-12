#include<stdio.h>
#include<stdio.h>
#define MaxVerNum 100
typedef char VertexType;
typedef int EdgeType;
typedef struct 
{
    VertexType vers[MaxVerNum];
    EdgeType edges[MaxVerNum][MaxVerNum];
    int vnum,enum;
}MGraph;

void CreateMGraph(MGraph *G)
{//建立无向图G的邻接矩阵储存
    inti i,j,k,w;
    printf("请输入顶点数和边数\n");
    scanf("%d,%d",&G->vnum,&G->enum);
    for(i = 0;i<G->vnum)
}