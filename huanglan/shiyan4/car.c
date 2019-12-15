#include"car.h"

int init(LinkQueue *wait,LinkQueue *park,Linkstack *giveway){
	QueueNode newnode1=(QueueNode)malloc(sizeof(struct QueueNode));
	if(NULL==newnode1){
		return F;
	}
	newnode1->next =NULL;
	wait->front=newnode1;
	wait->rear =newnode1;
	QueueNode newnode2=(QueueNode)malloc(sizeof(struct QueueNode));
	if(NULL==newnode1){
		return F;
	}
	newnode2->next =NULL;
	park->front=newnode1;
	park->rear =newnode1;
	
    giveway->top=NULL;
	giveway->count=0;
}
void menu(LinkQueue *wait,LinkQueue *park,Linkstack *giveway,int num,int t){
	printf("**********Welcome to our Car Parking**********\n");
	printf("********** Please choose function  **********\n");
	printf("**********     1:park.      **********\n");
	printf("**********     2:leave.     **********\n");
	printf("**********     3:view.      **********\n");
	printf("**********     4:exit.      **********\n");
	int option;
	scanf("%d",&option);
	switch(option){
		case 1:{
			park1(wait,park);
			printf("停车完成。\n");
			menu(wait,park,giveway,num,t);
			break;
		}
        case 2:{
			leave2(wait,park,giveway,num,t);
			menu(wait,park,giveway,num,t);
			break;
			   }
        case 3:{
            view3(*wait,*park);
			menu(wait,park,giveway,num,t);
			break;
			   }
        case 4:{
			printf("**********   欢迎再次使用，谢谢。  ************\n");
			break;
			   }
        default:{
			printf("**********   请输入正确的指令！   **********\n");
			menu(wait,park,giveway,num,t);
			break;
				}
        	}
 
		}

 int linklength(LinkQueue q){
	 int i = 0;
	 while(q.front != q.rear)
	 {
		 i++;
		 q.front = q.front -> next;
	 }
	 return i;
 }

 int inqueue(LinkQueue *q,int num,int t){
	 QueueNode  newnode = (QueueNode)malloc(sizeof(struct QueueNode));
	 int b;
	 if(NULL==newnode){
		 return F;
	 }
	 newnode->inform.number = num;
	 newnode->inform.time = t;
	 newnode->next = NULL;
	 q->rear->next = newnode;
	 q->rear = newnode;
	 return T;
 }

   
int outqueue(LinkQueue *q,int *num,int *t){
	if(q->front == q->rear)
	{
		printf("the queue is empty!\n");
		return F;
	}
	*num = q->front->next->inform.number;
	*t   = q->front->next->inform.time;
	QueueNode temp = q->front->next;
	q->front->next =temp->next;
	if(temp -> next == NULL){
		q->rear = q->front;
	}
	free(temp);
	return T;
}

 void park1(LinkQueue *wait,LinkQueue *park){
	 printf("请输入车号和停车时间。\n");
	 int num,t,b;
	 scanf("%d,%d",&num,&t);
	 printf("当前单价为6元每小时。\n");
	 printf("需付车费为：");
	 b = t * 6;
	 printf("%d\n",b);
	 if(linklength(*park)  >=  Max){
		 printf("停车场已满，进入等待区。\n");
		 inqueue(wait,num,t);
	 }
	 else{
		 inqueue(park,num,t);
	 }
 }



 int push(Linkstack *s,int num, int t){
	 stackNode newnode = (stackNode)malloc(sizeof(struct stack));
	 if(NULL==newnode){
		 return F;
	 }
	 newnode->data.number = num;
	 newnode->data.time = t;
	 newnode->next = s->top;
	 s->top = newnode;
	 s->count++;
	 return T;
 }

int pop(Linkstack *s,int *num,int *t){
	if(0 == s ->count)
	{
		printf("the stack is empty !\n");
		return F;
	}
	*num = s->top->data.number;
	*t   = s->top->data.time;
	stackNode temp = s->top;
	s->top =s ->top->next;
	free(temp);
	s->count--;
	return T;
}

void leave2(LinkQueue *wait,LinkQueue *park,Linkstack *giveway,int num,int t){
	printf("请输入要离开车的车号\n");
	int leavenumber;
	scanf("%d",&leavenumber);
	int i = 0,j=0;
	QueueNode head = park->front;
	while(head != park->rear)
	{
		if(head->next->inform.number != leavenumber)
		{
			head = head->next;
			i++;
		}
		else
	break;
	}
	if(i <= Max-1){
		while(j !=i ){
	outqueue(park,&num,&t);
	push(giveway,num,t);
	j++;
		}
		outqueue(park,&num,&t);
	}
	else
	{
		printf("查无此车!\n"); 
	}
	while(giveway->top != NULL){
		pop(giveway,&num,&t);
		inqueue(park,num,t);
	}
	if(linklength(*wait)  != 0){
		outqueue(wait,&num,&t);
		inqueue(park,num,t);
	}
}

 void view3(LinkQueue wait,LinkQueue park){
	 printf("******************** 目测停车场状况 *******************\n");
	 printf("停车场共%d个车位，当前停车场共有%d量车，等待区共有%d量车\n",Max,linklength(park),linklength(wait));
	 printf("******************************************************\n");
	 printf("车   号");
	 QueueNode  head1 =park.front;
	 QueueNode  head2 =park.front;
	 while(head1 != park.rear){
		 printf("%d",head1->next->inform.number);
		 head1 = head1->next;
	 }
	 printf("\n");
	 printf("停车时间：");
	 while(head2 != park.rear){
		 printf("%d",head2->next->inform.time);
		 head2 = head2->next;
	 }
	 printf("\n");
 }






