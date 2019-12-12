#ifndef map_h
#define map_h
#include<stdio.h>
#include<stdlib.h>//调用system函数
#include<conio.h>
#include<string.h>
#define maxsize 600
#define INF 32767//两景点不可到距离长度
int visited[maxsize];//全局变量
int path[maxsize][maxsize];//经过景点
int shortest[maxsize][maxsize];//最短路径
typedef struct//定义对各个景点信息存储的结构体类型
{
int top;//景点序号
char info[maxsize];//景点名称
char introduce[maxsize];//景点介绍
} data;//定义顶点类型
typedef struct node
{
int adj;//相邻接的景点间的距离
} node;//定义边的类型
typedef struct
{
data vertex[maxsize];//景点、顶点
node arcs[maxsize][maxsize];//景点间距离
int vexnum,arcnum;//景点数、边数
} adjmatrix;//定义图的类型
void Browser();/*校园地图*/
void PlaceList();/*已存景点阅览*/
void creatvisited(adjmatrix *g);/*访问标志数组初始化*/
void DFS(adjmatrix *g,int v);/*深度遍历*/
void search(adjmatrix *g);/*遍历*/
void vernumfile(adjmatrix *g);/*已存景点信息文本*/
void arcnumfile(adjmatrix *g);/*已存景点间路径文本*/
void readvernum(adjmatrix *g);/*读取景点信息*/
void readarcnum(adjmatrix *g);/*读取路径信息*/
void findvernum(adjmatrix *g);/*查询景点信息*/
void floyd(adjmatrix *g);/*弗洛伊德算法*/
void shortload(adjmatrix *g);/*最短路径*/
int meun();/*菜单栏*/

