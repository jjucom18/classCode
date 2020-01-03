#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <ctype.h>


#define MAX_SIZE_PARK 5  //停车场的最大容量
#define MAX_SIZE_SERVICE_ROAD 15 //便道的容量
#define OK  1
#define ERROR 0 


typedef char Elementtype;
typedef char Status;

//车辆信息据结构定义
typedef struct car
{
 Elementtype car_licence[20];   //车辆的牌照号码
int timearv_hours;    //车辆进入停车场的时间,小时
int timearv_mins;     //车辆进入出停车场的时间,分钟
int timelev_hours;
int timelev_mins;
 }Car_informa;

//栈的定义 
typedef struct stack
{
Car_informa data[MAX_SIZE_PARK];
Car_informa data_temp[MAX_SIZE_PARK];//定义一个临时空间用来存储因让车从停车场退出去的车
int top;
}S_node;

//队列的定义，链表的结构
typedef struct queue
{ 
Car_informa data[MAX_SIZE_SERVICE_ROAD];
struct queue *next;   

}Q_node;


//对栈的操作 
 Status init(S_node *head);
 Status stack_is_empty(S_node head);
 Status stack_is_full(S_node head);
 Status stack_push(S_node *head,Car_informa car_msg);
 Status stack_pop(S_node *head,S_node *temp_head,Car_informa car_msg,Q_node* q_head,int count);


//对队列的操作
 Status init_queue(Q_node **q_head);
 Status queue_push(Q_node* q_head,Car_informa car_msg);


void printf_stack(S_node *head,Car_informa car_msg);//打印停车场的信息
void printf_queue(Q_node *q_head ,Car_informa car_msg);


int  length(Q_node *q_head);

 Q_node *q_head;//(全局变量)定义一个队列的头指针
