#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"car.h"

void main(int agrc,char **argv){
		system("cls");
	void welcom();
	void StackInit(SeqStackCar *s);
	int QueueInit(LinkQueueCar *Q);
	void Print(CarNode *p,int room);
	int Arrival(SeqStackCar *Enter,LinkQueueCar *W);
	void Leave(SeqStackCar *Enter,SeqStackCar *Temp,LinkQueueCar *W);
	void List1(SeqStackCar *S);
	void List2(LinkQueueCar *W);
	void List(SeqStackCar S,LinkQueueCar W);
}
