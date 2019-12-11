#include"linkstack.h"

int main()
{
    LinkStack *stack = initstack();
    if(EmptyStack(stack)) printf("stack is empty!\n");
    PushStack(stack,2);
    PushStack(stack,5);
    PushStack(stack,8);
    TopStack(stack);
    PopStack(stack);
    TopStack(stack);


    return 0;
}