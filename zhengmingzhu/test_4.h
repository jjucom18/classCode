#ifndef test_4_h
#define test_4_h
#define MAXSIZE 100

typedef struct time{    //  时间节点
	int hour;
	int min;
}Time;

typedef struct node{    //  车辆信息节点
	char num[10];
	Time reach;
	Time leave;
}CarNode;

//typedef int dataType;
//typedef struct NODE{    //用链栈模拟停车场
//	CarNode linkstack(MAXSIE + 1);
//	datatype data;
///	struct node *next
   // datatype *top;
    //}SeqStackCar;

typedef struct NODE{	//用栈模拟停车场
    CarNode *linkstack[MAX+1];
    int top;
    }SeqStackCar;

typedef struct car{		//用队列模拟车流
    CarNode *data;
    struct car *next;
    }QueueNode;

typedef struct Node{	//用队列模拟车道
    QueueNode *head;
    QueueNode *rear;
    }LinkQueueCar;

void StackInit(SeqStackCar *s);
int QueueInit(LinkQueueCar *Q);
int Arrival(SeqStackCar *In,LinkQueueCar *W);
void Leave(SeqStackCar *In,SeqStackCar *Team,LinkQueueCar *W);
void List(SeqStackCar,LinkQueueCar);
void menual();

#endif
