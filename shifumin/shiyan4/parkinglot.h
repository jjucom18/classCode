#ifndef parkinglot_h
#define parkinglot_h

#define Price 0.05          //定义停车价格和停车场容量
#define MAX_STOP 10
#define MAX_PAVE 10

#include <stdlib.h>
#include <stdio.h>
#include <time.h>                   
#include <string.h>


typedef struct
{

    int timeIn;              // 进入停车场时间
    int timeOut;             // 离开停车场时间
    char plate[10];
    // 汽车牌照号码，定义一个字符指针类型
}Car;

// 停放栈（用于停放车辆）
typedef struct
{
    Car Stop[MAX_STOP];   // 用于停放车辆的栈
    int top;                  // 标记栈顶位置
}Stopping;

// 等候队列
typedef struct
{
    int count;                // 用来指示队中的数据个数
    Car Pave[MAX_PAVE];   // 等候停车的队列
    int front, rear;          // 标记队头和队尾位置
}Pavement;

// 让路栈
typedef struct
{
    Car Help[MAX_STOP];   // 用于让路的队列
    int top;                  // 标记站定位置
}Buffer;

Stopping s;
Pavement p;
Buffer   b;
Car      c;
char     C[10];

void stop_to_pave();       // 车停入便道
void car_come    ();       // 车停入停车位
void stop_to_buff();       // 车进入让路栈
void car_leave   ();       // 车离开
void welcome     ();       // 主界面函数
void Display     ();       // 显示车辆信息

#endif 
