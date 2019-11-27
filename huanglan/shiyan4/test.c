#include"zhan.c"
int main(){
	int comm;
	int num,e1,time,e2;
	int i,j,t;
	SqStack *St,*St1;//St是停车场，St1是离开位置的车辆
	SqQueue *Qu;//候车场
	do{
		printf("输入指令（0:退出 1:到达 2:离开 3:显示停车场 4:显示候车处）：");
			scanf("%d",&comm);
		switch(comm)
		   {printf("输入车号与时间：");//汽车到达
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

		
