#include"park.h"
int main(int argc ,char  **argv){ 
	int come,num,time,i,j,k,l,t;
	SqStack *St,*St1;
	SqQueue *Qu;
	InitStack(St);InitStack(St1);
	InitQueue(Qu);
	do{printf("1:到达 2:离开 3:显示停车场 4:显示候车场");
    scanf("%d",&come);
	switch(come){
		case 1:printf("输入车牌号和时间");
			   scanf("%d%d",&num,&time);
			   if(!StackFull(St)){
				   Push(St,num,time);
				   printf("停车场位置：%d\n",St->top+1);}
			   else{if(!QueueFull(Qu)){
				   InQueue(Qu,num);
				   printf("候车场位置:%d\n",Qu->rear);} 
				   else printf("候车场已满，不能停车\n");break;}
		case 2:printf("输入车牌号和时间");
			   scanf("%d%d",&num,&time);
			   for(k=0;k<=St->top&&St->num[k]!=num;k++);
			   if(i>St->top) printf("未找到该车\n");
			   else{
				   t=St->top-k;
				   for(l=0;l<t;l++){
					   Pop(St,i,j);
					   Push(St1,i,j);}
				   Pop(St,i,j);
		       	   printf("停车费用:%d%d\n",num,(time-j)*Price);
				   while(!StackEmpty(St1)){
					   Pop(St1,i,j);
					   Push(St,i,j);}
				   if(!QueueEmpty(Qu)){
					   OutQueue(Qu,i);
					   Push(St,i,time);}}
			   break;
		case 3:if(!StackEmpty(St)){
				   printf("停车场中的车辆:");
				   DispStack(St);}
			   else printf("停车场中无车辆");
			   break;
		case 0:if(!StackEmpty(St)){
				   printf("停车场中的车辆:");
				   DispStack(St);}
			   if(!QueueEmpty(Qu)){
				   printf("候车场中的车辆:");
				   DispQueue(Qu);}
			   break;
		default:printf("输入命令有误\n");
				break;}}
	while(come!=0);
	return 0;}
