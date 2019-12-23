#ifndef stack_h
#define stack_h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 10
typedef int DataType;
typedef struct 
{
    DataType data [MaxSize];
    int top;
}SeqStack;

SeqStack *initStack();
bool EmptyStack(SeqStack *stack);
bool FullStack(SeqStack *stack);
void PushStack(SeqStack *stack,DataType data);
void PopStack(SeqStack *stack);
void TopStack(SeqStack *stack);


#endif
