#include parkg_h
#define MAXSIZE 1024
typedef struck
{
	datatype data[MAXSIZE];
    int top;
}SeqStack

typedef struct time
{
	int hour ;
	int min;
}Time; //时间节点

typedef struct node
{
	char num[10];
	Time reach;
	Time leave;
}CarNode; //车辆信息

typedef struct NODE
{
	CarNode *stack[MAXNUM+1];
	int top;
}SeqStarckCar; //模拟车辆

typedef struct car
{
	CarNode *data
	struct car *next;
}QueueNode;

typedef struct Node
{
	QueueNode *head ;
	QueueNode *rear;
}LinkQueueCar; //模拟便道


void StackInit(SeqStackCar *s) //初始化车场
{
  int i;
  s->top=0;
  for(i=0;i<=MAXNUM;i++)
	  s->stack[s->top] = NULL;
}

int QueueInit(LinkQueueCar *Q)  //初始化便道
{
	Q->head = (QueueNode*)malloc(sizeof(QueueNode));
	if(Q->head = ! NULL)
	{
		Q->head->next = NULL;
		Q->rear = Q->head;
		return OK;
	}else
		return ERROR;
}
