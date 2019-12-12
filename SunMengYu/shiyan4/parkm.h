#ifndef parkm_h
#define parkm_h
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <ctype.h>

#define MAX_SIZE_PARK N
#define MAX_SIZE_SERVICE_ROAD M
#define OK 1
#define ERROR 0
typedef char Elementtype;
typedef char Status;

void StackInit(SeqStackCar *s)
int QueueInit(LinkQueueCar *Q)
	void Print(CarNode *p,int room)
	int Arrival(SeqStackCar*Enter,LinkQueueCar *W)
	void Leave(SeqStackCar*Enter,SeqStackCar*Temp,LinkQueueCar*W)
	void List1(SeqStackCar*S)
	void List2(LinkQueueCar*W)
#endif
