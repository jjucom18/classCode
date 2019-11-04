#ifndef stackg_h

#define stackg_h

#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>



#define MaxSize 10

typedef int DataType;

typedef struct{

		DataType data[MaxSize];

			int top;

}SeqStack;



SeqStack *initStack();

bool emptyStack(SeqStack *stack);

bool fullStack(SeqStack *stack);

void push(SeqStack *stack, DataType data);

void pop(SeqStack *stack, DataType *data);

void topStack(SeqStack *stack, DataType *data);







#endif
