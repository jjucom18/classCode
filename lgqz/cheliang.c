
#include<stdio.h>
#include<malloc.h>

#define N 5

//栈，停车场车位，第一位存放车牌，第二位存放时间，-1代表没有停放车辆
int stack[N][2] = { { -1, 0 }, { -1, 0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } };
//辅助栈
int helpStack[N][2] = { { -1, 0 }, { -1, 0 }, { -1, 0 }, { -1, 0 }, { -1, 0 } };
//队列，便道
struct Queue
{
	//车牌
	int carId;
	struct Queue *next;
}*queue = { NULL };

//判断该车牌是否已存在，1停在停车场，2停在便道，0不存在
int carComeHave(int carId)
{
	//看停车场里面
	for (int i = 0; i < N; i++)
	{
		if (stack[i][0] == carId)
		{
			return 1;
		}
	}
	//看便道
	struct Queue *head = queue;
	for (;head != NULL;)
	{
		if (head->carId == carId)
		{
			return 2;
		}
		head = head->next;
	}

	return 0;
}

//判断停车场内是否停满
int parkInFull()
{
	for (int i = 0; i < N; i++)
	{
		if (stack[i][0] == -1)
		{
			return 0;
		}
	}

	return 1;
}

//停在停车场里面的车离开
void parkInLeave(int carId, int carLeaveTime)
{
	//找到该车辆，i1代表车位位置，i2代表辅助栈位置
	for (int i1 = N - 1, i2 = 0; i1 >= 0; i1--)
	{
		//如果是这辆车
		if (stack[i1][0] == carId)
		{
			//将该车开走
			printf("车辆%d从%d号车位开出，停车时长%d小时, 费用为%d元\n", stack[i1][0], i1 + 1, carLeaveTime - stack[i1][1], (carLeaveTime - stack[i1][1]) * 4);
			stack[i1][0] = -1;
			stack[i1][1] = 0;
			//把辅助栈的车开回
			for (i2--;i2 >= 0; i2--, i1++)
			{
				stack[i1][0] = helpStack[i2][0];
				stack[i1][1] = helpStack[i2][1];
				printf("车辆%d开至%d号车位\n", stack[i1][0], i1 + 1);
				helpStack[i2][0] = -1;
				helpStack[i2][1] = 0;
			}
			//从便道停一辆车过来
			//如果便道有车
			if (queue != NULL)
			{
				stack[N - 1][0] = queue->carId;
				stack[N - 1][1] = carLeaveTime;
				struct Queue *q1 = queue;
				queue = queue->next;
				free(q1);
				printf("车辆%d从便道开至%d号车位\n", stack[N - 1][0], N - 1);
			}
			break;
		}
		//如果不是这辆车
		else
		{
			if (stack[i1][0] != -1)
			{
				helpStack[i2][0] = stack[i1][0];
				helpStack[i2][1] = stack[i1][1];
				printf("车辆%d从%d号车位开出\n", stack[i1][0], i1 + 1);
				stack[i1][0] = -1;
				stack[i1][1] = 0;
				i2++;
			}
			
		}
	}
}

//车辆开到停车场内
void parkInNew(int carId, int carTime)
{
	//找到空位，停放车辆
	int parkInId = 0;
	for (parkInId = 0; parkInId < N; parkInId++)
	{
		if (stack[parkInId][0] == -1)
		{
			stack[parkInId][0] = carId;
			stack[parkInId][1] = carTime;
			printf("车辆%d停放在%d号车位\n", carId, parkInId + 1);
			break;
		}
	}
}

//车辆开到便道
void parkOutNew(int carId)
{
	//停放在便道（队列）中
	struct Queue *head = queue, *newCar = (struct Stack *)malloc(sizeof(struct Queue));
	newCar->carId = carId;
	newCar->next = NULL;
	//如果便道没有车
	if (queue == NULL)
	{
		queue = newCar;
	}
	//如果便道有车
	else
	{
		for (; head->next != NULL;)
		{
			head = head->next;
		}
		head->next = newCar;
	}
	printf("车辆%d停放在便道\n", carId);

}

//便道车辆离开
void parkOutLeave(int carId)
{
	struct Queue *q1 = queue;
	//如果便道第一辆是该车辆
	if (queue->carId == carId)
	{
		queue = queue->next;
		free(q1);
	}
	else
	{
		//找到该车辆
		for (; q1->next->carId != carId;)
		{
			q1 = q1->next;
		}
		struct Queue *q2 = q1->next;
		q1 = q1->next->next;
		free(q2);
	}
	printf("车辆%d从便道离开\n", carId);
}


int main()
{
	printf("本系统模拟停车场管理，假设存在%d个车位，车牌号全为数字\n时间格式输入为小时（即从0时开始到+∞时），车费为4元/小时\n", N);
	int carCome, carId, carTime;
	for (;;)
	{
		printf("\n请输入车辆到达还是离去：\n1、到达\n2、离去\n");
		scanf_s("%d", &carCome);
		if (!(carCome == 1 || carCome == 2))
		{
			printf("输入错误，请重新输入！\n");
			continue;
		}
		getchar();
		printf("请输入车牌号：\n");
		scanf_s("%d", &carId);
		getchar();
		//如果是车到达
		if (carCome == 1)
		{
			printf("请输入到达时刻：\n");
			scanf_s("%d", &carTime);
			getchar();
			//判断是否已存在该车牌
			//如果已存在
			if (carComeHave(carId) == 1 || carComeHave(carId) == 2)
			{
				printf("该车牌已存在！\n");
			}
			//如果不存在
			else
			{
				//判断停车场内是否停满
				//如果已停满
				if (parkInFull() == 1)
				{
					parkOutNew(carId);
				}
				//如果未停满
				else
				{
					parkInNew(carId, carTime);
				}
			}
		}
		//如果是车离开
		else if (carCome == 2)
		{
			printf("请输入离开时刻：\n");
			scanf_s("%d", &carTime);
			getchar();
			//如果未找到该车辆
			if (carComeHave(carId) == 0)
			{
				printf("车辆%d不存在！\n");
			}
			//如果停在停车场里面
			else if (carComeHave(carId) == 1)
			{
				parkInLeave(carId, carTime);
			}
			//如果停在便道
			else if (carComeHave(carId) == 2)
			{
				parkOutLeave(carId);
			}
		}
	}

	return 0;
}
