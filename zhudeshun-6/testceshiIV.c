#include "sorts.h"
int main()
{
SqStack *parkstack;            //parkstack为表示停车场的栈
LinkQueue *parkqueue;      //parkqueue为表示便道的队列
struct Node car;
int n,a=0,t;                      //n为停车场栈的最大容量
time_t rawtime;
struct tm * timeinfo;
time (&rawtime);
timeinfo = localtime (&rawtime);
parkstack=Init_SeqStack();
parkqueue=Init_LQueue(); //初始界面
printf("当前日期及时间为:%s",asctime(timeinfo));
printf("请输入停车场最大容量n=\n");
scanf("%d",&n);
printf("请输入要处理车辆的状态（A表示到达，D表示离开,E表示退出程序），编号，当前时刻\n");
printf("请输入车辆信息\n");
scanf("%c,%d,%d",&car.AL,&car.NO,&car.time);
	while(car.AL!='E')
	{
		if(car.AL=='A' )
		{                                //    汽车到达的情况
			if(ISFULL_SeqStack(parkstack,n)==1)        //栈满的情况
			{
				IN_Lqueue(parkqueue,car);                //进入队列等待
				printf("这辆车在门外便道上第%d个位置\n",parkqueue->num);
				printf("请输入车辆信息\n");
			}
			else
			{
				Push_SeqStack(parkstack,car);        //入栈
				printf("这辆车在停车场内第%d个位置\n",parkstack->num);
				printf("请输入车辆信息\n");
			}
		}
		if(car.AL=='D' )                    //汽车离开的情况
		{
			t=POP_SeqStack(parkstack,car);//出栈
			printf("这辆车停留时间为%d\n",t);
			printf("这辆车需要交费%d元\n",t);
			printf("请输入车辆信息\n");
			if(ISEmpty_LQueue(parkqueue)==0)  //队列不为空需要进栈
				Push_SeqStack(parkstack,Out_LQueue(parkqueue) );     
		}
		if(car.AL=='P'&&car.NO==0&&car.time==0 )//显示停车场的车数
		{
			printf("停车场的车数为%d\n",parkstack->num);
			printf("请输入车辆信息\n");
		}
		if(car.AL=='W'&&car.NO==0&&car.time==0 )//显示候车场的车数
		{
			printf("候车场的车数为%d\n",parkqueue->num);
			printf("请输入车辆信息\n");
		}
		scanf("%c,%d,%d",&car.AL,&car.NO,&car.time);       
	}
	printf("输入结束\n");
	printf("当前日期及时间为:%s",asctime(timeinfo));
	return 1;
}
