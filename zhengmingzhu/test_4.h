#ifndef test_4.h
#define test_4.h
#define MAX 50

typedef struct time{    //  时间节点
	int hour;
	int min;
}Time;

typedef struct node{    //  车辆信息节点
	char num[10];
	Time reach;
	Time leave;
}CarNode;

typedef struct node{    //用链栈模拟停车场
   // CarNode *stack[MAX+1];
	datatype data;
	struct node *next
    int top;
    }LinkStackCar;

typedef struct car{		//用队列模拟车流
    CarNode *data;
    struct car *next;
    }QueueNode;

typedef struct Node{	//用队列模拟车道
    QueueNode *head;
    QueueNode *rear;
    }LinkQueueCar;

void InitStack(LinkStackCar *);
int InitQueue(LinkQueueCar *);
int Arrival(LinkStackCar *,LinkQueueCar *);
void Leave(LinkStackCar *,LinkStackCar *,LinkQueueCar *);
void List(LinkStackCar,LinkQueueCar);
void menu();

#endif
