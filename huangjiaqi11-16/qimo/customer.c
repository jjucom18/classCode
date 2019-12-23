#include "customer.h"

customer *Initcustomer(){
	customer *tip;
	tip = (customer *)malloc(sizeof(customer));
	tip->next = NULL;

	if(tip->next == NULL){
		printf("初始化成功！\n");
	}
	return tip;//没有该返回值代码运行是则会出现段错误！造成空指针错误
}

int push(linklist *head,customer *tip){ 
	int i;//用来接住返回数据
	int m;
	linklist *temp = head; 
	i = findByname(head);
	if(i == 1){
		customer *q;//用于接住数据、
		q = (customer *)malloc(sizeof(customer));
		printf("请输入你要预订房间的id：\n");
		scanf("%d",&(q->datacustomer.id));
		printf("请输入你想要预订房间的类型：\n");
		scanf("%s",q->datacustomer.name);
		m = q->datacustomer.id;
		q->next = tip->next;
		tip->next = q;
		tip->length++;
		dle(head);
		//return 1;
	}
	else{
		printf("预定成功!\n");
	}
	return -1;
}//订房

int pop(linklist *head,customer *tip){
	customer *temp = tip;
	int i;
	printf("请输入你想要退订客房的id：\n");
	scanf("%d",&i);
	while(temp->next){
		if(temp->next->datacustomer.id == i){
			customer *q;
			q = (customer *)malloc(sizeof(customer));
			q = temp->next;
			temp->next = temp->next->next;
			free(q);
			printf("退房成功！\n");
			displaycustomer(tip);
			return -1;
		}
		temp = temp->next;
	} 
	return -1;
}//退房

void serchroom(customer *tip){
	int i;
	customer *temp = tip;
	printf("请输入的客房的id：\n");
	scanf("%d",&i);
	while(temp->next){
		if(temp->datacustomer.id == i){
			printf("该客房的名字为：%s",temp->datacustomer.name);
		}
		printf("你未预定该客房\n");
	}
}//查看所预定的房间

void displaycustomer(customer *tip){
	customer *temp = tip;
	printf("********所顶房间信息如下********：\n");
	while(temp->next){
		temp = temp->next;
		printf("顾客的id：%d\n",temp->datacustomer.id);
	}
	printf("\n");

}
//查看顾客所预定的房间
void countcustomer(customer *tip){
	printf("%d",tip->length);
	displaycustomer(tip);
}
