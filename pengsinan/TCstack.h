#ifndef TCstack_h
#define TCstack_h

#include "TCqueue.h"

#define Maxsize 10

typedef struct NODE{
	/*int *stack[Maxsize + 1];*/
	CarNode *stack[Maxsize + 1];
	int top;

}SeqStackCar;

void StackInit(SeqStackCar *s);
/*void Leavestack(SeqStackCar *Enter ,SeqStackCar *Temp);*/
/*void Leave(SeqStackCar *Enter ,SeqStackCar *Temp);*/
void List2(SeqStackCar *S);
int Arrive(SeqStackCar *Enter);
/*int Arrivestack(SeqStackCar *Enter);*/


#endif
