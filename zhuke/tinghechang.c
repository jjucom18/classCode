#include"tingchechang.h"
#include<stdio.h>

int main(int argc,char **argv)
{
	DataType temp;
	SqStack Park,TemPark;
	SqQueue Q;
	initstack(&Park);
	initstack(&TemPark);
	QueueInitiate(&Q);
	printf("请输入第一辆车的信息：\n");
	scanf("%c %d %d",&temp.tag,&temp.id,&temp.time);
	while(temp.tag=='A'||temp.tag=='D')
	{
		Process(temp,&Park,&TemPark,&Q);
		printf("\n请输入下一辆车的信息：\n");
		scanf("%c",&temp.tag);
		scanf("%c %d %d",&temp.tag,&temp.id,&temp.time);
	}
	printf("所有车辆的信息已处理完毕，程序结束。\n");
}

