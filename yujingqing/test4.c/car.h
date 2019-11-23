#ifndef car_h
#define car_h
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include <malloc.h>

#define MAX_SIZE_PARK 5
#define MAX_SIZE_SERVICE_ROAD `5
#define ok 1
#define ERROR 0
typedf char Elementtype;
typedf char Status;

typedef struct car
{     
	Elementtype car_licence[20];
	int         timearv_hours;
        int         timearv_mins;
      	int         timeleave_hours;
        int         timeleave_mins;
}Car_infor;

typedef struct stack
{
	Car_infor data[MAX_SIZE_PARK];
	Car_infor data_temp[MAX_SIZE_PARK];
        int       top;
}S_node;

typedf struct queue
{
	car_infor    data[MAX_SIZE_SERVICE_ROAD];
	struct queue *next;
}Q_node;

Status init(S_node *head);
Status stack_is_empty(S_node head);
Status stack_is_full(S_node head);
Status stack_push(S_node *head,car_infor car_msg);
Status stack_pop(S_node *head,S_node *temp_head,Car_informa car_msg,Q_node* q_head,int count);


Status init_queue(Q_node **q_head);
Status queue_push(Q_node* q_head,Car_infor car_msg);


void printf_stack(S_node *head,Car_infor  car_msg);
void printf_queue(Q_node *q_head,Car_infor car_msg);
 
int length(Q_node *q_head);
Q_node *q_head;


#endif













