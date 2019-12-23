#ifndef customer_h
#define customer_h

#include <stdio.h>
#include <stdlib.h>
/*typedef struct{
	int year;
	int month;
	int day;
}DATAcustomer;*/
typedef struct{
	int id;
	int price;
	char name[20];
	char info[50];

}customer1;
typedef struct stack{
	customer1 datacustomer;
	int length;
	struct stack *next;
}customer;

customer *Initcustomer();
int push(linklist *head,customer *tip);//订房
int pop(linklist *head,customer *tip);//退房
void displaycustomer(customer *tip);//打印函数
void countcustomer(customer *tip);

#endif
