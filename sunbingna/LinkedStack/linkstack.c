#include"linkstack.h"

LinkStack *initstack()
{
    LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));
    stack->next = NULL;//生成空栈 以单链表表头为栈顶 注：链栈没有头结点
    return stack;
}

bool EmptyStack(LinkStack *stack)
{
    return stack->next == NULL;
}

void PushStack(LinkStack *stack,DataType data)
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = data;
    //printf("%d\t",p->data);  
    p->next = stack;
    stack = p;
    //printf("%d\t",stack->data);
    //p->next = NULL;
}

void PopStack(LinkStack *stack)
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    if(EmptyStack(stack)) printf("stack is empty!\n");
    else
    {
       // data = stack->data;
        p = stack;
        stack = stack->next;
        free(p);
    }
}

void TopStack(LinkStack *stack)
{
     if(stack->next = NULL) {printf("stack is empty!\n"); printf("\n");}
     else printf("%d\t",stack->data);
}
