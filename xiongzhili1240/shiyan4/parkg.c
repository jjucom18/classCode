#include<staio.h>
#include<stdlib.h>
#include<parkg.h>

void Print(CarNode *p,int room ) //打印离开车辆的信息
{
	int A1,A2,B1,B2;
	printf("\n请输入离开的时间:/**:**/");
	scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
	printf("\n离开车辆的车牌号为：")；
	puts(p->num);
	printf("\n其到达时间为：%d:%d",p->reach.hour,p->reach.min);
	printf("\n离开时间为：%d：%d",p->leave.hour,p->leave.min);
	A1=p->reach.hour;
	A2=p->reach.min;
	B1=p->leave.hour;
	B2=p->leach.min;
	printf("\n应交费用为：%2.1f元",((B1-A1)*60+(B2-A2))*price);
	free(p);
}

int Arrival (SeqStackCar *Enter ,LinkQueueCar *w) //车辆到达
{
	CarNode *p;
	QueueNode *t;
	p = (CarNode *)malloc(sizeof(CarNode));
	printf("\n 请输入车牌号 (例：陕A1234):");
	getchar();
	gets(p->num);
	if(Enter->top<MAXNUM)/*车场未满，车进车场*/
	{
		Enter->top++;
		printf("\n车辆在车场第%d位置.",Enter->top);
		printf("\n 请输入到达时间:/**:**/");
		scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
		Enter->stack[Enter->top] = p;
		return OK;
	}else /*车辆已满，车进便道*/
	{
      printf("\n该车须在便道等待!");
	  t = (QueueNode *)malloc(sizeof(QueueNode));
	  t->data = p;
	  t->next = NULL;
	  w->rear->next = t;
	  w->rear = t;
	  return OK;
	}
}
	}

}

