#ifndef linkstack_h
#define linkstack_h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int DataType;
 typedef struct StackNode
 {
     DataType data;//数据域
     struct StackNode *next;//指针域
 }LinkStack,StackNode;

 LinkStack *initstack();
 bool EmptyStack(LinkStack *stack);
 bool FullStack(LinkStack *stack);
 void PushStack(LinkStack *stack,DataType data);
 void PopStack(LinkStack *stack);
void TopStack(LinkStack *stack);

#endif
