#ifndef DAOHANG_H

#define DAOHANG_H

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define max 20000

#define n 17

typedef struct{			//图中顶点的结构类型，存放景点的编号、名称、简介等信息，

	int num;

		char name[20];

			char inform[100];

}vextype;



typedef struct ArCell	//图中边的结构类型，存放路径的长度

{

		int a;				//路径长度

}Arcell,Adj[n][n];



typedef struct			//图的结构类型，包含顶点与边，以及顶点与边的数目

{

		vextype vex[n];

			Adj adj;

				int vexnum,adjnum;

}Graph;

Graph g;

int shortest[n][n];        //两点最短距离

int path[n][n];            //经过的景点

void view();//地图

void jingdianjieshao();          //景点介绍

void zuiduanlujing();    //查找最短路径

void floyed();             //用Floyd算法求两个景点的最短路径

void juli(int i,int j); //打印两景点的路径及最短距离

void huanyingjiemian();	   //欢迎界面

void jingdianliebiao();	   //景点列表	

void tuijianlujing();

void Init();					//初始化赋值

void jiesujiemian();

#endif
