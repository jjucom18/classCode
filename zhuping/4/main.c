#include"park.h"
int main(int argc ,char  **argv){ 
	int come,num,time,i,j,k,l,t;
	SqStack *St,*St1;//St为停车场，St1为有车离开时，该车辆
	SqQueue *Qu;//Qu为候车场
	InitStack(St);InitStack(St1);
	InitQueue(Qu);
	do{printf("1:到达 2:离开 3:显示停车场 4:显示候车场");
    scanf("%d",&come);
	switch(come){
		case 1:printf("输入车牌号和时间");//汽车到达
			   scanf("%d%d",&num,&time);
			   if(!StackFull(St)){//停车场未满
				   Push(St,num,time);
				   printf("停车场位置：%d\n",St->top+1);}
			   else{if(!QueueFull(Qu)){//侯车场不满
				   InQueue(Qu,num);
				   printf("候车场位置:%d\n",Qu->rear);} 
				   else printf("候车场已满，不能停车\n");break;}
		case 2:printf("输入车牌号和时间");//车辆离开
			   scanf("%d%d",&num,&time);
			   for(k=0;k<=St->top&&St->num[k]!=num;k++);//栈中寻找该车
			   if(i>St->top) printf("未找到该车\n");
			   else{
				   t=St->top-k;//需要出栈车辆数
				   for(l=0;l<t;l++){
					   Pop(St,i,j);
					   Push(St1,i,j);}//倒车到临时栈
				   Pop(St,i,j);
		       	   printf("停车费用:%d%d\n",num,(time-j)*Price);
				   while(!StackEmpty(St1)){//临时栈回到St中
					   Pop(St1,i,j);
					   Push(St,i,j);}
				   if(!QueueEmpty(Qu)){//队不空时，将队头进入栈
					   OutQueue(Qu,i);
					   Push(St,i,time);}}//以当前时间开始计费
			   break;
		case 3:if(!StackEmpty(St)){//显示停车场情况
				   printf("停车场中的车辆:");
				   DispStack(St);}
			   else printf("停车场中无车辆");
			   break;
		case 4:if(!QueueEmpty(Qu)){//显示候车场车辆
				   printf("侯车场中的车辆:");
				   DispQueue(Qu);}
			   else printf("候车场无车辆\n")
			   break;
		default:printf("输入命令有误\n");//其他错误
				break;}}
	while(come!=0);
	return 0;}
