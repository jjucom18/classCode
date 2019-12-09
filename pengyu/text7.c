#include<stdio.h>
#include<string.h>                                                                                                   
#include<limits.h>
#include<stdlib.h>
#define MAXVESX  30
#define MAXNAME 20
typedef char VexType[MAXNAME];
typedef int AdjType;
typedef struct {
int n;                                   /* 图的顶点个数 */
VexType vexs[MAXVEX];                    /* 顶边信息 */
AdjType arcs[MAXVEX][MAXVEX];            /* 边信息 */
} GraphMatrix;

typedef struct {        /* 保存最短路径的结构体 */
AdjType len;    /* 最短路径长度 */
int pre;        /* 前一顶点 */
} Path;

int LocateVex(GraphMatrix *g, VexType u） { /*在图g中查找顶点u的编号*/
int i;
for (i=0; i<g->n; ++i)
if(strcmp(u, g->vexs[i]) == 0)
return i;
}
