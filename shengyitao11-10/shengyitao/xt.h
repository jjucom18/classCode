#ifndef xt_h
#define xt_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//停车地图导航系统
#define Max 1000
#define INF 5000
typedef struct place {
    char name[30];//名字 
    int index;//下标 
    char intro[30];//简介 
}PLA;//定义位置
typedef struct {
    PLA place[Max];
    float edge[Max][Max];
    int vertexnum;//点的数目 
    int edgenum;//边数目 
}Graph;//定义一个图 
void Init_Graph(Graph *G);//初始化一个图
void show_menu(Graph * G);//输出菜单 
void shortestdistance(Graph *G);//求最短距离 
void display(Graph *G,int start,int end);//展示路径 
int path[Max][Max]={0};

#define F 0
#define T 1
#define MAX 800

typedef struct Node   //数据
{
    int number;
    int time;
}Node;

typedef struct QueueNode   //队列结点
{
    struct Node infom;
    struct QueueNode * next;
}*QueueNode;

typedef struct LinkQueue    //链队列
{
    struct QueueNode * front;
    struct QueueNode * rear;
}LinkQueue;

typedef struct stack         //栈结点
{
    struct Node data;
    struct stack *next;
}*StackNode;

typedef struct LinkStack     //链栈
{
    StackNode top;
    int count;
}LinkStack;

//函数实现
void menu(LinkQueue *wait,LinkQueue *park,LinkStack *giveway,int num,int t);//菜单
int init(LinkQueue *wait,LinkQueue *park,LinkStack *giveway);//初始化
int linklength(LinkQueue q);//查看长度
int enqueue(LinkQueue *q,int num,int t);//入队列
int dequeue(LinkQueue *q,int *num,int *t);//出队列
void park1(LinkQueue *wait,LinkQueue *park);//停车函数
int push(LinkStack *s,int num,int t);//入栈
int pop(LinkStack *s,int *num,int *t);//出栈
void leave2(LinkQueue *wait,LinkQueue *park,LinkStack *giveway,int num,int t);//离开函数
void view3(LinkQueue wait,LinkQueue park);//查看停车场状态
#endif
