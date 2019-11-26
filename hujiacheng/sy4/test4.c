#include"polt.h"
void StackInit(SeqStackCar *s){
	int i;
	s->top=0;
	for(i=0;i<=maxnum;i++){
	s->stack[s->top]=NULL;
	}
} 
int QueueInit(LinkQueueCar *Q)
{
	Q->head=(QueueNode*)malloc(sizeof(QueueNode));
	if(Q->head !=NULL){
	Q->head->next=NULL;
	Q->rear =Q->head;
	return 1;
	} else return 0;
}
void Print(CarNode *p,int room){
	int A1,A2,B1,B2;
	printf("\n请输入离开时间：/**：**/");
	scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
	printf("\n离开车车牌：");
	puts(p->num);
	printf("\n其到达时间为：%d:%d",p->reach.hour,p->reach.min);                                                                                          printf("离开时间为：%d:%d",p->leave.hour,p->leave.min); 
	A1 = p->reach.hour;
	A2 = p->reach.min;
	B1 = p->leave.hour;
	B2 = p->leave.min;
	printf("\n收费: %2.1f元",(((B1-A1) * 60+(B2-A2)) * 0.1));
	free(p);	
	}
void list1(SeqStackCar *S){
	int i;
	if(S->top = 0){
	printf("\n车场:");
	printf("\n位置 到达时间 车牌号\n");
	for(i=1; i<S->top; i++){
	printf(" %d ",i);
	printf("%d:%d ",S->stack[i]->reach.hour,S->stack[i]->reach.min);
	puts(S->stack[i]->num);
	}
} else 
	printf("\n车场里面没有车");
}
void list2(LinkQueueCar *W){
	QueueNode *p;
	p = W->head->next;
	if(W->head != W->rear){
	printf("\n等候车号码：");
	while (p!=NULL){
	puts(p->data->num);
	p = p->next;
	    }
	}
	else 
	 printf("\n便道里没有车");
}
void list(SeqStackCar S,LinkQueueCar W){
	int flag,tag;
	flag = 1;
	while(flag){
	printf("\n请选择 1|2|3:");
	printf("\n1.车道\n2.便道\n3.返回\n");
	while(1)
	{ scanf("%d",&tag);
	   if(tag>=1||tag<=3) break;
	   else printf("\n请选择 1|2|3:");
         	}	
    switch (tag){
    	case 1: list1(&S);
		break;
	case 2: list2(&W);
		break;
	case 3: flag = 0;
	    	break;
	default : break;}	
       	}	
}

int Arrival (SeqStackCar *Enter ,LinkQueueCar *W){
	CarNode *p;
	QueueNode *t;
	p = (CarNode*)malloc(sizeof(CarNode));
	printf("\n请输入车牌号(赣B8888):");
	getchar();
	gets(p->num);
	if(Enter->top < maxnum){
		Enter->top++;
		printf("\n车辆在第%d位置.",Enter->top);
		printf("\n请输入到达时间：/**：**/");
		scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
		Enter->stack[Enter->top]=p;
		return 1;
		}
	else {
		printf("\n该车须在便道等候.");
		t = (QueueNode*)malloc(sizeof(QueueNode));
		t->data = p;
		t->next = NULL;
		W->rear->next=t;
		W->rear = t;
		return 1;
	}
}


void Leave (SeqStackCar *Enter ,SeqStackCar * Temp ,LinkQueueCar *W){
	int room;
	CarNode *p,*t;
	QueueNode *q;
 	if (Enter->top>0)  //有车否
	{
		while(1)  /*输入离开车辆信息*/
		{
			printf("\n/1--%d: ",Enter->top);
			scanf("%d",&room);
			if(room>1 && room<=Enter->top) break;
			}
		while(Enter->top > room){ /*车辆离开*/
			Temp->top++;
			Temp->stack[Temp->top] = Enter->stack[Enter->top];
			Temp->stack[Enter->top]  = NULL;
			Enter->top--;
					}
		p = Enter->stack[Enter->top];
		Enter->stack[Enter->top] = NULL;
		Enter->top--;
		while(Enter->top >= 1){
			Enter->top++;
			Enter->stack[Enter->top] = Temp->stack[Temp->top];
			Temp->stack[Temp->top]  = NULL;
			Temp->top--;
					}
		Print(p, room);
		//判断便道是否有车及车场是否已满
		if((W->head != W->rear) && Enter->top<maxnum){
			q = W->head->next;
			t  = q->data;
			Enter->top;
			printf("\n便道的%s号车进入车场第%d位置.",t->num,Enter->top);
			printf("\n请输入现在时间/**:**/:");
			scanf("%d:%d",&(t->reach.hour),&(t->reach.min));
			W->head->next == q->next;
			if(q == W->rear)  W->rear = W->head;
			Enter->stack[Enter->top] = t;
			free(q); 
			}

		else	
			printf("\n便道里没有车 .\n");
}	else 
		printf("\n车场里没有车."); /*没车*/


}
