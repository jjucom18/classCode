#include "carStop.h"

void init_carStop(carStop top){
	top->next == NULL;
}
int empty_carStop(carStop top){
	if(top->next == NULL)
		return -1;
}
int push_carStop(carStop top,car *x){
	stackNode *p;
	p = (stackNode *)malloc(sizeof(stackNode));
	//if(empty_carStop(top))
		//printf("栈为空！\n");
	p->data = *x;
	p->next = top->next;
	top->next = p;
	return 1;
}//入栈
int pop_carStop(carStop top,car *x){
	if(empty_carStop(top))
		printf("栈空！\n");
	else{
		carStop p;
		p = (stackNode *)malloc(sizeof(carStop));
		*x = top->data;
		p = top;
		top = top->next;
		free(p);
		return top->data.number;
	}
}


