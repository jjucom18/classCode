#ifndef CarStack_h
#define CarStack_h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//#include<time.h>
//#include<unistd.h>
#include<string.h>

#define MaxSize 3

typedef int DataType;

typedef struct 
{
        bool arrive;
        bool leave;
        char number[30];
        time_t atime;
        time_t ltime;
        double price;
}Car;

typedef struct 
{
	Car data[MaxSize];
	int top;
}CarStack;

CarStack *initCarStack();
int EmptyCar(CarStack *s);
int FullCar(CarStack *s);
void PushCarStack(CarStack *s,Car data);
void PopCarStack(CarStack *s,Car *data);
void TopCarStack(CarStack *s,Car *data,int temp);
void DisplayStack(CarStack *s);
int placeStack(CarStack *s,char numble[]);

#endif
