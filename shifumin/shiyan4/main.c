#include"parking.h"

void main()
{
	SeqStackCar Enter,temp;
	LinkQueueCar Wait;
	int ch;
	system("color 4A");
	InitStack(&Enter);
	InitStack(&Temp);
	InitQueue(&Wait);
	while(1)
	{
		printf("\n************》》欢迎使用停车管理系统《《************\t\n\n");
		printf("\n\t########### 1.车辆到达登记 ###########\t\n");
		printf("\n\t########### 2.车辆离开登记 ###########\t\n");
		printf("\n\t########### 3.车辆列表显示 ###########\t\n");
		printf("\n\t########### 4.退出系统     ###########\t\n\n");
		while(1)
		{
			printf("请选择:");
			scanf("%d,&ch");
			if(ch>=1&&ch<=4)break;
			else printf("\n输入有误，请重新选择：");
		}
		switch(ch)
		{
			case 1:Arrival(&Enter,&Wait);break;
		    case 2:Leave(&Enter,&Temp,&Wait);break;
			case 3:List(Enter,Wait);break;
			case 4:exit(0);
			default:break;
		}
	}
}

