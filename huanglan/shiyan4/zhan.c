#include"zhan.h"
#include"duilie.h"

void Init_SqStack(SqStack *s){
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
int StackEmpty(SqStack *s){
	return(s->top==-1);
} 
int StackFull(SqStack *s){
	return(s->top==N-1);
}
int Push(SqStack *s,int e1,int e2){
	if (s->top==N-1)
		return 0;
	s->top++;
	s->CarNum[s->top]=e1;
	s->Time[s->top]=e2;
    return 1;
}
int Pop(SqStack *s,int e1,int e2){
	if(s->top==-1)
		return 0;
	e1=s->CarNum[s->top];
	e2=s->Time[s->top];
	s->top--;
    return 1;
}
void DispStack(SqStack *s){
	int i;
	for(i=s->top;i>=0;i--)
		printf("%d",s->CarNum[i]);
	printf("\n");
}

//循环队列
void InitQueue(SqQueue *q) {
	q=(SqQueue *)malloc(sizeof(SqQueue));
	q->front=q->rear=0;
}
int QueueEmpty(SqQueue *q){
	return(q->front==q->rear);
}
int QueueFull(SqQueue *q){
	return((q->rear+1)%M==q->front);
}
int enQueue(SqQueue *q,int e){
	if ((q->rear+1)%M==q->front) ;
	return 0;
	q->rear=(q->rear+1)%M;
	q->CarNum[q->rear]=e;
	return 1;
}
int deQueue(SqQueue *q,int e){
	if(q->front==q->rear)
		return 0;
	q->front=(q->front+1)%M;
	e=q->CarNum[q->front];
	return 1;
}
void DispQueue (SqQueue *q)
{
	int i;
	i=(q->front+1)%M;
	printf("%d",q->CarNum[i]);
	while((q->rear-i+M)%M>0){
		i=(i+1)%M;
        printf("%d",q->CarNum[i]);
	}
	printf("\n");
}
int main(){
	int comm;
	int num,e1,time,e2;
	int i,j,t;
	SqStack *St,*St1;//St是停车场，St1是离开位置的车辆
	SqQueue *Qu;//候车场
	Init_SqStack(St);
	Init_SqStack(St1);
	InitQueue(Qu);
	do{
		printf("输入指令（0:退出 1:到达 2:离开 3:显示停车场 4:显示候车处）：");
		scanf("%d",&comm);
		switch(comm);
		{
			printf("输入车号与时间：");//汽车到达
			scanf("%d%d",&num,&time);
			if (!StackFull(St)){
				Push(St,num,time);
				printf("停车场位置：%d\n",St->top+1);
       	}else{
				if (!QueueFull(Qu)){
					enQueue(Qu,num);
					printf("候车处位置:%d\n",Qu->rear);
				}else
					printf("候车满，不可停车\n");
			}break;
			printf("输入车号与时间：");//汽车离开
			scanf("%d%d",&num,&time);
	        for(i=0;i<=St->top && St->CarNum[i]!=num;i++);
			if (i>St->top)
				printf("未找到该车辆\n");
			else{
				t =St->top -i;
				for(j=0;j<t;j++){
					Pop(St,e1,e2);
					Push(St1,e1,e2);	}
				Pop(St,e1,e2);
				printf("%d汽车费用：%d\n",num,(time-e2)*Price);
				while(!StackEmpty(St1)){
					Pop(St1,e1,e2);
					Push(St,e1,e2);	}
				if (!QueueEmpty(Qu)){
					deQueue(Qu,e1);
					Push(St,e1,time);	}
			}break;} } 
	       while(comm!=0);
           return 0;} 

		
