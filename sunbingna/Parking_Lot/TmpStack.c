#include"TmpStack.h"

TmpStack *InitTmpStack()
{
        TmpStack *stack;
        stack = (TmpStack *)malloc(sizeof(TmpStack));
        stack->top = -1;
        return stack;
}

int EmptyTmp(TmpStack *stack)
{
        return stack->top == -1;
}

int FullTmp(TmpStack *stack)
{
        return stack->top == MaxSize-1;
}

void PushTmpStack(TmpStack *stack, Car data)
{
        if( !FullTmp(stack)){
                stack->top++;
                stack->data[stack->top] = data;
        }
}

void PopTmpStack(TmpStack *stack, Car *data)
{
        if( !EmptyTmp(stack)){
                *data = stack->data[stack->top];
                stack->top--;
        }
}

void TopTmpStack(TmpStack *stack, Car *data)
{
        if( !EmptyTmp(stack)){
                *data = stack->data[stack->top];
        }
}//
