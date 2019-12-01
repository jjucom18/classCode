#include"CarStack.h"

CarStack *initCarStack()
{
	CarStack *stack;
	stack = (CarStack *)malloc(sizeof(CarStack));
	stack->top = -1;
	return stack;
}

int EmptyCar(CarStack *stack)
{
	return stack->top = -1;
}

int FullCar(CarStack *stack)
{
	return stack->top = MaxSize-1;
}

void PushCarStack(CarStack *stack,Car data)
{
	if( !FullCar(stack))
	{
		stack->top++;
		stack->data[stack->top] = data;
	}
}

void PopCarStack(CarStack *stack,Car *data)
{
	if( !EmptyCar(stack))
	{
		*data = stack->data[stack->top];
		stack->top--;
	}
}

void TopCarStack(CarStack *stack,Car *data,int temp)
{
	if(!EmptyCar(stack))
	{
		*data = stack->data[temp];
	}
}

int PlaceStack(CarStack *stack,char number[])
{
	int temp = stack->top;
	while(temp !=-1 && strcmp(stack->data[temp].number,number))
	{
		temp--;
	}
	return temp;
}//寻找车在栈中的位置

