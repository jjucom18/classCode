#ifndef campus_h
#define campus_h

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxVerNum 19
#define INFINITY 10000
typedef struct _VertexType{
	char address[30];
}VertexType;

typedef int EdgeType;

typedef struct _MGraph{
	VertexType vexs[MaxVerNum];
	EdgeType edges[MaxVerNum][MaxVerNum];
	int vnum,enumw;
}MGraph;


void CreateMGraph(MGraph *G,VertexType *data,int edgeData[MaxVerNum][MaxVerNum]);
void initEdge(int edgeData[MaxVerNum][MaxVerNum]);
void initVnum(VertexType *data);
void ShortestPath(MGraph *G, int P[], int D[], VertexType *data,int vertex);
int SelectAddress();
void floyd(MGraph *G,int path[][MaxVerNum],int dist[][MaxVerNum],int start,int end);

#endif