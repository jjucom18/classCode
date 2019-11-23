#include "tcc.h"

SeqStack *initStack(){
	SeqStack *stack = (SeqStack *)malloc(sizeof(SeqStack));
	stack->top = -1;

	return stack;
}

bool emptyStack(SeqStack *stack){
	return stack->top == -1;
}

bool fullStack(SeqStack *stack){
	return stack->top == MaxSize - 1;
}

void push(SeqStack *stack, DataType data){
	if(fullStack(stack)){
		return;
	}else{
		stack->top++;
		stack->data[stack->top] = data;
	}
	return;
}

void pop(SeqStack *stack, DataType *data){
	if(emptyStack(stack)){
		return;
	}else{
		*data = stack->data[stack->top];
		stack->top--;
	}

	return;

}
void topStack(SeqStack *stack, DataType *data){
	if(emptyStack(stack)){
		return;
	}else{
		*data = stack->data[stack->top];
	}
	
	return;
}
