#include"parking.h"

int main(int argc, char **argv){
	CarStack *stack = InitCarStack();
	ListQueue *list = InitQueue();
	while(1){
		int flat;
		if(PromptInput(stack,list)) break;
	}
	return 0;
}