#include"stack.h"

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
        {       printf("%d\t",arr[i]);
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

