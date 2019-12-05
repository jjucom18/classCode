#include "stack.h"

SeqStack *initStack()
{
    SeqStack *stack = (SeqStack *)malloc (sizeof(SeqStack));
    stack->top = -1;

    return stack;
}

bool EmptyStack(SeqStack *stack)
{
    return stack->top == -1;
}

bool FullStack(SeqStack *stack)
{
    return stack->top == MaxSize-1;
}

void PushStack(SeqStack *stack,DataType data)
{
    if(FullStack(stack))
         printf("stack is full!\n");
    stack->top = data;
    stack->top++;
}

void PopStack(SeqStack *stack)
{
    if(EmptyStack(stack)) printf("stack is empty!\n");
    DataType data = stack->top;
    stack->top--;
}

void TopStack(SeqStack *stack)
{
    if( !EmptyStack(stack))
    printf("stack top:%d\n",stack->top-1);
}

