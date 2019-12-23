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
	AdjType arcs[MAXVEX][MAXVEX];
}GraphMatrix;

typedef struct {
	AdjType len;
	int pre;
}Path;

int LocateVex(GraphMatrix *g, VexType u){
	int i;
	for (i=0; i<g->n; ++i)
		if(strcmp(u, g->vexs[i]) == 0)
			return i;
}
