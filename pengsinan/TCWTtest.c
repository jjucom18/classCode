#include<stdio.h>
#include"TCqueue.h"
#include"TCstack.h"
 
#include"TCWT.c"
 
void StackInit(SeqStackCar *s);
int QueueInit(LinkQueueCar *Q);
void Print(CarNode *p ,int room);
int Arrival(SeqStackCar *Enter ,LinkQueueCar *W);
void leave(SeqStackCar *Enter ,SeqStackCar *Temp ,LinkQueueCar);
void List2(SeqStackCar *S);
void List1(LinkQueueCar *W);
