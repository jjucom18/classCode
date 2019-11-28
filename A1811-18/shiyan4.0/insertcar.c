#include "insertcar.h"

int insertcar(carStop top,carWait *q){//车辆到达
	car *x;
	stackNode *incar;//创建结点
	queuenode *m;//创建结点
	incar = (stackNode *)malloc(sizeof(stackNode));
	for(int i= 0;i < 20;i++){
	printf("欢迎光临！\n");
	printf("请输入车牌号：\n");
	scanf("%s",&(incar->data.number));
	printf("请输入车辆到场时间**:**\n");
	scanf("%d:%d",&(incar->data.in.hours),&(incar->data.in.minte));
	if(top->data.number < maxnumber) {
		*x = incar->data;
		push_carStop(top,x);
		//to do 打印车辆信息
		printf("车在第几个车位：%d\n",top->data.number);
			}
	else{
		printf("停车场已满，请进入便道！\n");//停车场已满，进入便道
		m = (queuenode *)malloc(sizeof(queuenode));
		*x = incar->data;
		in_carWait(q,x);//传参类型需要进行修改！！！！
		printf("车辆停放在等候通道中！\n");
	}
} 
} 

