#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#define MAX 50
typedef struct time 
{   
int hour;
int min;
}Time;                  //定义时间结构体
typedef struct node
{    
char num[10];
Time reach;
Time leave;
}CarNode;               //  定义车辆信息结构体
typedef struct NODE
{
    CarNode *stack[MAX+1];
    int top;
    }SeqStackCar;       //模拟车场
typedef struct car
{
    CarNode *data;
    struct car *next;
    }QueueNode;
typedef struct Node
{
    QueueNode *head;
    QueueNode *rear;
    }LinkQueueCar;       //模拟便道
void InitStack(SeqStackCar *s);
 int InitQueue(LinkQueueCar *Q);
void Print(CarNode *p,int room);
 int Arrival(SeqStackCar *Enter,LinkQueueCar *W);
void Leave(SeqStackCar *Enter,SeqStackCar *Temp,LinkQueueCar *W);
 void List1(SeqStackCar *S);
 void List2(LinkQueueCar *W);

#endif
