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

int main(int argc,  char **argv)
{
        SeqStack *stack = initStack();
        if(EmptyStack(stack)){
                printf("empty\n");
        }
        DataType arr[] = {89, 23, 14, 56, 75, 61, 91};
        int size = sizeof(arr)/sizeof(arr[0]);

        for(int i = 0; i < size; i++){
                PushStack(stack, arr[i]);
        }

        if(EmptyStack(stack)){
                printf("empty\n");
        }else{
                printf("No empty!\n");
        }

        TopStack(stack);
	for(int i=0;i<7;i++)
	{	printf("%d\t",arr[i]);
	}printf("\n");

	PopStack(stack);
	 for(int i=0;i<6;i++)
        {       printf("%d\t",arr[i]);
        }printf("\n");

       // printf("stack top: %d\n", topV);
        // DataType arr1[size];
        // for(int i = 0; i < size; i++){
        //         PopStack(stack, &arr1[i]);
        // }
        // for(int i = 0; i < size; i++){
        //         printf("%d\t", arr[i]);
        // }
        // printf("\n");
        // for(int i = 0; i < size; i++){
        //         printf("%d\t", arr1[i]);
        // }
        // printf("\n");

        return 0;
}
