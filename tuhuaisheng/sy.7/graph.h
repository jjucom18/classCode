#ifndef graph_h
#define graph_h
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#define MAXVEX 30
#define MAXNAME 20
typedef char VexType[MAXNAME];
typedef int AdjType;
typedef struct {
	int n;
	VexType vexs[MAXVEX];
	AdjType arcs[MAXVEX][MAXVEX];

}GraphMatrix;
typedef struct{/*保存最短路径的结构体*/
	AdjType len;/*最短路径长度*/
	int pre;/*前一丁点*/

}Path;
#endif
