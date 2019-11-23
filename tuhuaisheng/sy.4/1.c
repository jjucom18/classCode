#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define size 50
 typedef struct{
	 char elem[size][size];
	 int starttime[size];
	 int endtime[size];
	 int top;
 }stack1;
//队列
 typedef struct queue2{
	 char elem[size];
	 struct queue2 next;
 }queue2;
typedef struct{
	queue2 front;
	queue2 rear;
}queue;
//初始化
void initStack1(stack1 s)
{
	printf("初始化1完成、n");
	s->top=-1;
}
//初始化
void initqueue2(queue q)
{
	q->front=(queue2)malloc(sizeof(queue2));
	if(q->front!=NULL){
		q->rear=q->front;
		q->front->next=NULL;
		printf("初始化2队列完成\n");
	}else 
		printf("初始化2队列失败\n")
}
_Bool isfull(stack1 s){
	//z判1号栈是否为满（即车库的车位是否满）
	if(s->top<=size-1)
		return 0;
	else
		return 1;
}
int enterqueue2(queue q,char str[])//进队列（准备排队进入车库）
{
	printf("\n您已进入便道排队，请等候....");
	int i=0;
	queue2 temp;
	temp=(queue2)malloc(sizeof(queue2));
	if(temp==NULL){
		printf("申请内存空间失败\n");
		return 0;
	}else if(str[i]!='\0')
	{
		temp->elem[i]=str[i];
		printf("%c",str[i]);
		i++;
	}
	temp->next=NULL;
	q->rear->next=temp;
	q->rear=temp;
	return 1;
}
int pushstack(stack1 s,char str[],int stracttime,int endtime)//进栈（车库）
{
	int i=0;
	if(s->top<=size-1){
    if(s->top=-1)
		s->top++;
	else if(str[i]!='\0'){
		s->elem[s->top][i]=str[i];
		printf("%c",str[i]);
		i++;
	}
	s->starttime[s->top]=starttime;
	s->endtime[s->top]=endtime;
	printf("\n您当前的在车库位置是第%d位，开始停车是%d，结束的时间是%d",s->top+1,s-starttime[s->top],s->endtime[s->top]);
	s->top++;
	}else {
		printf("\n车库栈已满，请等待其他车出库后您在停车入库");
	}return 0;
}
int find(stack1 s,char str[])//寻找车库中对应车辆的位置
	//确定车库中准确的位置
	int flag=0;
	printf("\n正在检测您车的位置...");
	int i,j;
	j=s->top;
	for(i=0;i<=j;i++){
		int m,n=0;
		for(m=0;s->elem[i][m]!='\0';m++){
			if(s->elem[i][m]==str[m]){
				n++;
			}else break;
		}if(strcmp(s->elem[i],str)==0){
			flag=i;
			printf("\n当前的车牌号为%s，在车库中是第%d个"，s-elem[i],flag);
			break;
		}
		if(n==m){
			flag=i+1;
			printf("\n当前的车牌号为%s，在车库中是第%d个"，s-elem[i],flag);
			break;
		}
	}
if(flag==0){
	printf("\n车库中暂时找不到您的爱车");
}
return flag;
} 
int pop(stack1 s,int flag)//出车库，同时修改车库栈中汽车的位置
{
	//停车费
	int money=0;
	money=s->endtime[flag-1]-s->starttime[flag-1];
	printf("\n当前停车的费用为%d"，money);
	printf("\n当前汽车正在准备出库....");
	int i;
	for(i=flag+1;i<s->top;i++){
		strcpy(s->elem[i-1],s->elem[i]);
		s->starttime[i-1]=s->starttime[i];
		s->endtime[i-1]=s->endtime[i];

	}s->top;
	printf("\n当前汽车完成出库....车库中还有%d辆车"，s->top);
}int main()
{
	stack1 s1;
	queue q2;
	int choice,starttime,endtime,flag;
	char str[50];
	initStack(&s1);
	initqueue(&q2);
	printf("请选择到达（1）还是离去（2）退出程序（-1）\n");
	scantf("%d",&choice);//-1代表退出
	while(choice!=-1)
	{
		if(choice==1){
			printf("\n您当前选择到达（1）")；
				if（isfull(&s1)==1) {
					printf("\n（1号栈）车库位置以达到上限，请等待，开始进入便道排队")；
						printf("请输入您的车牌号\n");
					scanf("%s",&str);
					enterqueue2(&q2,str);
				}else{
					printf("\n请输入您的车牌号");
					scanf("%s",&str);
					printf("\n请输入您的开始时间");
					scanf("%d",&starttime);
					printf("\n请输入您的结束时间");
					scanf("%d",&endtime);
					pushstack(&s1,str,starttime,endtime);
				}
		}else if(choice==2){
			printf("\n您当前选择为退出车库（2）");
			printf("\n请输入您的车牌号")；
				scanf("%s",&str);
			flag=find(&s1,str);
			if(flag==1)
				pop(&s1,flag);
		}printf("\n请继续选择到达（1）还是离去（2）退出程序（-1）");
		scanf("%d",&choice);
	}printf("\n本次服务结束，欢迎下次使用");
	return 0;
}
