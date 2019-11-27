#include<stdio.h>
#include<stdlib.h>
#include "TCqueue.h"
#include "TCstack.h"

void StackInit(SeqStackCar *s){
	int i;
	s -> top = 0;
	for(i = 0 ;i <= Maxsize ;i ++)
		s -> stack[s -> top] = NULL;
}

int QueueInit(LinkQueueCar *Q){
	Q -> head = (QueueNode *)malloc(sizeof(QueueNode));
	if(Q -> head != NULL){
		Q -> head -> next = NULL;
		Q -> rear = Q -> head;
		return 1;
	}
	else{
		return 0;
	}
}

void Print(CarNode *p ,int room){
	int a1 ,a2 ,b1 ,b2 ;
	printf("Please input the leaving time of the car :");
	scanf("%d:%d" , &(p -> leave .hour) ,&(p -> leave . min));
	printf("Please input the number of the car :");
	puts(p -> num);
	printf("\nThe arrival time is:%d:%d" , p -> arrive .hour ,p -> arrive . min);
	printf("The leaving time is:%d:%d" , p -> leave .hour ,p -> leave . min);

}

int Arrival(LinkQueueCar *W ,SeqStackCar *Enter){
	char *fgets(char *s ,int n ,FILE *stream);
	CarNode *p;
	QueueNode *t;
	p = (CarNode *)malloc(sizeof(CarNode));
	printf("Please input the car number:");
	/*getchar();
	gets(p -> num);*/
	fgets(p ,(CarNode *)malloc(sizeof(CarNode)) ,stdin);
	if(Enter -> top < Maxsize){
	Enter -> top ++;
	printf("The parking place is:%d" ,Enter -> top);
	printf("Please input the arriving time: **:** ");
	scanf("%d:%d" ,&(p -> arrive .hour) ,&(p -> arrive .min));
	Enter -> stack[Enter -> top] = p ;
	return 1;

	}
	else{
		printf("waiting!");
		t = (QueueNode *)malloc(sizeof(QueueNode));
		t -> data = p;
		t -> next = NULL;
		W -> rear -> next = t;
		W -> rear -> = t;
		return 1;
	}
}

void leave(SeqStackCar *Enter ,SeqStackCar *Temp ,LinkQueueCar){
	int room;
	CarNode *p ,*t;
	QueueNode *q;

	if(Enter -> top > 0){
		while(Enter -> top > 0/*TURE*/){
			printf("Please input the parking place :%d" ,Enter -> top);
			scanf("%d",&room);
				if(room > 1 && room <= Enter -> top) break;

		}
		while(Enter -> top > room){
			Temp -> top ++;
			Temp -> stack[Temp -> top] = Enter -> stack[Enter -> top];
			Enter -> stack [Enter -> top] = NULL;
			Enter -> top --;
		}
		p = Enter -> stack[Enter -> top];
		Enter -> stack[Enter -> top] = NULL;
		Enter -> top --;
		while(Temp -> top >= 1){
			Enter -> top ++;
			Enter -> stack[Enter -> top] = Temp -> stack[Temp -> top];
			Temp ->stack[Temp -> top] = NULL;
			Temp -> top --;
		}
		print(p room);
	if((W -> head != W -> rear) && Enter -> top < Maxsize){
		q = W -> head -> next;
		t = q -> data;
		Enter -> top ++;
		printf("parking place named %d car enter the place named %d" ,t -> num ,Enter -> top);
		printf("Please input the time right now: **:**" );
		scanf("%d:%d" ,&(t -> arrive .hour) ,&(t -> arrive .min));
		W -> head -> next = q -> next;
		if(q == W -> rear) W-> rear = W -> head;
		Enter -> stack[Enter -> top] = t;
		free(q);
	}
	else
		printf("\nno car in queue.\n");
	}
	else
		printf("\nno car in stack.\n");
}

void List2(SeqStackCar *S){
	int i ;
	if(S -> top > 0){
		printf("\n position,arrive time,car number\n");
		for(i = 1; i <= S -> top; i ++){
			printf("%d" ,i);
			printf("%d,%d",S -> stack[i] -> arrive .hour ,S -> stack[i] -> arrive . min);
			puts(S -> stack[i] -> num);
		}
	}
	else
		printf("no cars in parking lot");

}

void List1(LinkQueueCar *W){
	QueueNode *p;
	p = W -> head ->next;
	if(W -> head != W -> rear){
		printf("The waiting car's number is:");
		while(p != NULL){
			puts(p -> data -> num);
			p = p ->next;
		}
		else{
			printf("no cars in queue");
		}
	}
}
