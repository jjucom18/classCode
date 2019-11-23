#ifndef ABC_H_INCLUDED
#define ABC_H_INCLUDED
#define MAX 50
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
void InitStack(SeqStackCar *);
 int InitQueue(LinkQueueCar *);
 int Arrival(SeqStackCar *,LinkQueueCar *);
void Leave(SeqStackCar *,SeqStackCar *,LinkQueueCar *);
 void List(SeqStackCar,LinkQueueCar);
 
#endif // ABC_H_INCLUDED
