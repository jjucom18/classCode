#include "stackg.h"

int main(int argc,  char **argv)
{
	SeqStack *stack = initStack();
	if(emptyStack(stack)){
		printf("empty\n");
	}
	DataType arr[] = {89, 23, 14, 56, 75, 61, 91};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	for(int i = 0; i < size; i++){
		push(stack, arr[i]);
	}
	if(emptyStack(stack)){
		printf("empty\n");
	}else{
		printf("No empty!\n");
	}
	
	int topV = 0;
	topStack(stack, &topV);
	printf("stack top: %d\n", topV);
	DataType arr1[size];
	for(int i = 0; i < size; i++){
		pop(stack, &arr1[i]);
	}
	for(int i = 0; i < size; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
	for(int i = 0; i < size; i++){
		printf("%d\t", arr1[i]);
	}
	printf("\n");
		
	return 0;
}

SeqStack *initStack();
bool emptyStack(SeqStack *stack);
bool fullStack(SeqStack *stack);
void push(SeqStack *stack, DataType data);
void pop(SeqStack *stack, DataType *data);
void topStack(SeqStack *stack, DataType *data);
