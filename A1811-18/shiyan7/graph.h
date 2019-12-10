#ifndef graph_h
#define graph_h

#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define max 20//权值最大为1000

typedef struct{
	char number[50];//地点名
	int num;//地点编号
}VertexType;
typedef struct{
	VertexType vex[max];//定义顶点
	int arcs[max][max];//存储矩阵
	int vexNum;
	int arcNum;//地点数和路径条数
}MGraph;


MGraph InitGraph(MGraph G);//构造校园图
void Menu();//主菜单
void Query(MGraph G);//查找函数
void floyd(MGraph G);//floyd算法
void shortestPATH_Floyd(MGraph G);//求最短路径



#endif
