#include "shiyan4g.h"

void stop_to_pave(){
	if(p.count > 0 && (p.front==(p.rear + 1)% MAX_PAVE)){
		printf("抱歉，便道已经满了哦，请下次再来吧！\n");
	}
	else{
		strcpy(p.Pave[p.rear].plate,C);
		p.rear = (p.rear + 1)% MAX_PAVE;
		p.count++;
		printf("牌照为%s的汽车已停入便道上%d的位置\n",C,p.rear);
	}
}

void car_come(){
	printf("请输入需要停车的车辆的车牌号:");
		scanf("%s",&C);
		if(s.top >= MAX_STOP-1){
			stop_to_pave();
		}
		else{
			s.top++;
			time_t t1;
			long int t = time(&t1);
			char t2;
			t2 = ctime(&t1);
			s.Stop[s.top].timein = t;
			strcpy(s.Stop[s.top].plate,C);
			printf("车牌照为%s的车辆已停入车位为%d车位，当前时间为:%s\n",C,s.top + 1,t2);
		}
		return;
}

void stop_to_buff(){
	while(s.top >= 0){
		if(0== strcmp(s.Stop[s.top].plate,C)){
			break;
		}
		strcpy(b.Help[b.top++].plate,s.Stop[s.top].plate);
		printf("车牌照为%s的车辆暂时离开停车场\n",s.Stop[s.top--].plate);
	}
	if(s.top < 0){
		printf("停车场中无此车信息\n");
	}
	else{
		printf("车牌照为%s的车辆已从停车场开走\n",s.Stop[s.top].plate);
		time_t t1;
		long int t = time(&t1);
		c.timeout = t;
		char t2;
		t2 = ctime(&t1);
		printf("离开时间：%s\n需付：%ld元\n",t2,Price(c.timeout - s.Stop[s.top].timein));
		s.top--;
	}
	while(b.top > 0){
		strcpy(s.Stop[++s.top].plate,b.Help[--b.top].plate);
		printf("车牌照为%s的车辆停回其停车位%d车位\n",b.Help[b.top].plate,s.top);
	}
	while(s.top < MAX_STOP-1){
		if(0==p.count){
			break;
		}
		else{
			strcpy(s.Stop[++s.top].plate,p.Pave[p.front].plate);
			printf("车牌照为%s的车辆已从便道进入停车场的%d车位\n",p.Pave[p.front].plate,s.top);
			p.front = (p.front + 1) % MAX_PAVE;
			p.count--;
		}
	}
}

void car_leave(){
	printf("请输入即将离开的车辆的车牌号：\n");
	scanf("%s",&C);
	if(s.top < 0){
		printf("停车场中车位已空，无任何车辆信息！\n");
	}
	else{
		stop_to_buff();
	}
}

void Display(){
	int i = s.top;
	if(i==-1){
		printf("停车场中无车辆\n");
	}
	time_t t1;
	long int t = time(&t1);
	printf("\t车牌号：\t\t\t停放时间：\t\t当前所需支付金额：\n");
	while(i!= -1){
		printf("\t%s\t\t%d秒\t\t\t%d元\n",s.Stop[i].plate,t - s.Stop[i].timein,Price(t - s.Stop[i].timein)/10);
		i--;
	}
}

void welcome(){
	printf("\t目前停车场的状况\n");
	printf("\t停车场共有%d个车位，当前停车场共有%d辆车，便道上共有%d辆车\n",MAX_STOP,s.top+1,(p.rear+MAX_PAVE-p.front)%MAX_PAVE);
	printf("\t\n");
	printf("\t------------Welcome to my Car Parking----------\n");
	printf("\t 1.Parking \n");
	printf("\t 2.Leaving \n");
	printf("\t 3.Situation \n");
	printf("\t 4.Exit \n");
	printf("\t-----------------------------------------------\n");
}

int main(){
	s.top = -1;
	b.top = 0;
	p.front = 0;
	p.rear = 0;
	p.count = 0;

	while(1){
		//system("clear");
		welcome();
		int i,e;
		scanf("%d",&i);

		if(1==i) car_come();
		if(2==i) car_leave();
		if(3==i) Display();
		if(4==i) break;

		printf("返回请输入1\n");
		scanf("%d",&e);
		if(1==e){
			continue;
		}
		else{
			printf("您的输入有误，请重新输入\n");
			scanf("%d",&e);
			continue;
		}
	}
	return 0;
}






//Stopping s;
Pavement p;
Buffer b;
Car c;
char C[10];

void car_come();      //车辆进入停车场
void car_leave();     //车辆离开停车场
void stop_to_pave();  //车辆停入便道
void stop_to_buff();  //车辆停入辅助让路栈
void welcome();       //主界面函数
void Display();       //显示车辆信息


