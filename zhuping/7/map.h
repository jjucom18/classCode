#ifndef map_h
#define map_h

#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

#define MaxSize 100             
#define MaxViewNum 50     /*景点个数最大50*/
#define MaxRoad 1000      /*定义路径为无穷大*/
#define N 22              /*目前景点个数*/
 
typedef struct
{
    char name[30];          /*景点名称*/
    char number[10];        /*景点代号*/
    char introduce[200];    /*景点介绍*/	
}Elemtype;                  /*景点信息*/
 
typedef struct
{
    int num;              /*景点编号*/
    Elemtype date;        /*景点信息*/
}View;                    /*定义景点*/
 
typedef struct
{
    View view[MaxViewNum];         /*存放顶点的一维数组，数组第零单元没有用上*/
    int length[MaxViewNum][MaxViewNum];  /*存放路径长度*/
    int m,n;
}MGraph;
 
MGraph MGr;              /*全局变量,定义MGr为MGraph类型*/

int shortest[MaxViewNum][MaxViewNum];     /*定义全局变量存贮最小路径*/
int path[MaxViewNum][MaxViewNum];         /*定义存贮路径*/

void init() ;/*各个节点*/
void introduce();/*查询*/ 
void floyd();/*佛洛伊德算法*/
void display(int i,int j);/*输出两个景点的路径和最短路径*/ 
int shortdistance();/*最短路径计算*/ 
void map();/*地图*/

#endif
