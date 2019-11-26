#ifndef shiyan4g_h
#define shiyan4g_h   //定义头文件

#define Price        //定义单价
#define MAX_STOP 10   //设定停停车场单价
#define MAX_PAVE 5    //设定停便道单价

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>  //包含时间函数的头文件
#include <string.h>

typedef struct{      //汽车相关信息
	int timein;      //进入停车场的时间
	int timeout;     //离开停车场的时间
	char plate[8];   //汽车牌照号码，定义一个字符指针类型
}Car;

typedef struct{      //模拟停车场的栈    
	Car Stop[MAX_STOP];  //停放车辆的栈
	int top;             //标记栈顶位置
}Stopping;

typedef struct{      //模拟便道的队列
	int count;       //用于指示队列中的数据个数
	Car Pave[MAX_PAVE];   //便道队列
	int front,rear;       //标记队头和队尾的位置
}Pavement;

typedef struct{      //辅助栈
	Car Help[MAX_STOP];  //用于让路的栈
	int top;             //标记栈顶位置
}Buffer;

Stopping s;
Pavement p;
Buffer b;
Car c;
char C[10];

void car_come();      //车辆进入停车场
void car_leave();     //车辆离开停车场
void stop_to_pave();  //车辆停入便道
void stop_to_buff();  //车辆停入辅助让路栈
void welcome();       //主界面函数
void Display();       //显示车辆信息

#endif

