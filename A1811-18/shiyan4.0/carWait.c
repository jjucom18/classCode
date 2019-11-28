#include "carWait.h"

int init_carWait(carWait *q){
	//q = (carWait *)malloc (sizeof(carWait));
	if(q->head != NULL){
		q->rear = q->head;
		q->head->next = NULL;
	}
}//初始化等候路线
int in_carWait(carWait *q,car *x){
	queuenode *p;
	//x = (car *)malloc(sizeof(car));
	p = (queuenode *)malloc(sizeof(queuenode));
	if(p = NULL)
		printf("分配内存不成功！\n");
	p->data = x;
	p->next = NULL;
	q->rear->next = p;
	q->rear = q->rear->next;
	free(p);
}//入队
int out_carWait(carWait *q,car *x){
	queuenode *p;
	p = (queuenode *)malloc(sizeof(queuenode));
	if(emoty_carWait(q))
		printf("停车场为空！\n");
	else{
		//p = (queuenode *)malloc(sizeof(queuenode));
		p = q->head->next;
		x = p->data;
		q->head->next = p->next;
		free(p);//头指针只有指针域}
			} 

}
int emoty_carWait(carWait *q){
	q->head->next = q->rear->next;
}




