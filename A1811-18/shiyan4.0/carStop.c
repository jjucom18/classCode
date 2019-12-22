#include "carStop.h"

void init_carStop(carStop *s){
	s = (carStop *)malloc(sizeof(carStop));
	s->top->next == NULL;
	s->count = 0;

}
int empty_carStop(carStop *s){
	if(s->top->next == NULL)
		return -1;
}
int push_carStop(carStop *s,car *x){
	stackNode *p;
	p = (stackNode *)malloc(sizeof(stackNode));
	//if(empty_carStop(top))
		//printf("栈为空！\n");
	p->data = *x;
	p->next = s->top->next;
	s->top->next = p;
	s->count++;
	return ;
}//入栈
int pop_carStop(carStop *s,car *x){
	if(empty_carStop(top))
		printf("栈空！\n");
	else{
		carStop p;
		p = (stackNode *)malloc(sizeof(carStop));
		*x = s->top->data;
		p = s->top;
		s->top = s->top->next;
		free(p);
		s->count --;
		return ;
	}
}


