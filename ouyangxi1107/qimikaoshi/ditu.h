#ifndef parking_h
#define parking_h
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define MAX 50
#define INFINITY 10000
#define M 20

//停车场
typedef struct time{    //  定义时间结构体

int hour;

int min;

}Time;


typedef struct node{    //  定义车辆信息结构体

char num[10];

Time reach;

Time leave;

}CarNode;


typedef struct NODE{

    CarNode *stack[MAX+1];

    int top;

    }SeqStackCar;


typedef struct car{

    CarNode *data;

    struct car *next;

    }QueueNode;

typedef struct Node{

   QueueNode *head;

    QueueNode *rear;

    }LinkQueueCar;
	

////地图


typedef struct{

	char V[M][10];

	int R[M][M];

	int vexnum;

}Graph;


typedef struct tree{

	int weizhi;

	int lowcost;

};	
	
	
int locatevex(Graph *g,char a[10]);
int creatgraph(Graph *g);
int minimun(struct tree *a,Graph g);
void  MiniSpanTree_PRIM(Graph g,char a[10]);
	
	
//	


int InitQueue(LinkQueueCar *);

int Arrival(SeqStackCar *,LinkQueueCar *);

void Leave(SeqStackCar *,SeqStackCar *,LinkQueueCar *);

void List(SeqStackCar,LinkQueueCar);

void menu();

#endif
