#ifndef shiyan4g_h
#define shiyan4g_h

#define Price                //定义单价
#define MAX_STOP 10
#define MAX_PAVE 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>            //包含时间函数的头文件
#include <string.h>

typedef struct{              //车辆信息
	int timein;              //进入停车场的时间
	int timeout;             //离开停车场的时间
	char plate[10];          //车辆牌照号码，定义一个字符指针类型
}Car;

typedef struct{              //停车场(栈)
	Car Stop[MAX_STOP];      //用于停放车辆的栈
	int top;                 //标记栈顶位置
}Stopping;

typedef struct{             //便道队列
	int count;              //用于指示队中的数据个数
	Car Pave[MAX_PAVE];     //等候停车的便道队列
	int front,rear;         //标记队头和队尾的位置
}Pavement;

typedef struct{             //辅助栈
	Car Help[MAX_STOP];     //用于让路的辅助栈
	int top;                //标记栈顶位置
}Buffer;

Stopping s;                 //定义指针变量
Pavement p;
Buffer b;
Car c;
char C[10];

void car_come();            //车辆进入停车场
void car_leave();           //车辆离开停车场
void stop_to_pave();        //车辆停入便道
void stop_to_buff();        //车辆停入辅助栈
void welcome();             //主界面函数
void Display();             //显示车辆信息

#endif
