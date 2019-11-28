#ifndef  __PARK_H__
#define __PARK_H__

#define Price    1
#define MAX_STOP 5
#define MAX_PAVE 5

#include <stdlib.h>
#include <stdio.h>
#include <time.h>                         
#include <string.h>

				// 汽车信息
typedef struct
{

    int timeIn;  		// 进入停车场时间
    int timeOut;       		// 离开停车场时间
    char plate[5];
    				// 汽车牌照号码
}Car;

				// 停放栈  用于停放车辆
typedef struct
{
    Car Stop[MAX_STOP];  
    int top;                  // 标记栈顶位置
}Stopping;

				// 等候队列
typedef struct
{
    int count;                // 用来指示队中的数据个数
    Car Pave[MAX_PAVE];	 	// 等候停车的队列
    int front, rear;          // 标记队头和队尾位置
}Pavement;

				// 让路
typedef struct
{
    Car Help[MAX_STOP];   // 用于让路的队列
    int top;                  // 标记站定位置
}Buffer;

Stopping s;
Pavement p;
Buffer   b;
Car      c;
char     C[5];

void stop_to_pave();       // 车停入便道
void car_come    ();       // 车停入停车位
void stop_to_buff();       // 车进入让路栈
void car_leave   ();       // 车离开
void Display     ();       // 显示车辆信息

#endif
