#ifndef _STACK_H
#define _STACK_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include <unistd.h>

typedef struct  _node
{
    char account[5];
    char password[5];
    struct _node *next;
}NodeStack;

typedef struct stack
{
    NodeStack *top;
    int count;
}Linkstack;



#endif