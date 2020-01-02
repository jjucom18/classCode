#ifndef _STACK_H
#define _STACK_H
#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct node{
	char account[5],password[5];
	struct node *next;
}stacknode, *plinkstack;

typedef struct stack{
	plinkstack top;		//栈顶指针 
	int count;				//计数器 
}Linkstack; 

void push(Linkstack *S)	;
void traversestack(Linkstack s);
void InitStack(Linkstack *S);
bool match(Linkstack *S);
void stackchoice();

#endif