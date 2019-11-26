#ifndef pack_h
#define pack_h

#define price 1
#define Max_stop 10   //车辆停放
#define Max_wait 10   //车辆等候

#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<string.h>

typedef sturct
{
	int timereach;
	int timeleave;
	char carplate[10]
}c;//汽车信息

typedef sturct
{
	car stop[Max_stop];
	int top;
}s;//停放入栈

typedey sturct
{
	int count;
	car wait[Max_wait];
	int head,tail;
}p;//等候入队

typedef struct
{
	car help[Max_stop];
	int top;
}b;//让路栈

void stop_p();         //车辆进入便道
void car_reach();      //车辆j停入停车位 
void stop_buff();      //让路栈
void car_leave();      //车辆离开 
void welcome();        //欢迎界面函数
void dispiay();        // 显示车辆信息


#endif
