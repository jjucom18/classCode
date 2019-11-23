#include<stdio.h>
#include<conio.h>//为了使用getch();
#include <iostream>//为了string类型用cin,cout
#include <string>
using namespace std;
 
double parkArea[3] = { 1, 2, 3 };//车位面积
double const priceper = 0.005;//单位时间单位面积停车价格（RMB）
int const maxsize =50;//停车位数量（大中小都有maxsize个停车位），maxsize定义范围为1-100
string kind[3] = { "small", "medium", "big" };//车型
int size[3] = { 0, 0, 0 };//大、中、小车位停的车辆个数，初始化停车位为空
int const N = 11;//每一个候车道能排的车数，最大数量为N-1(根据队列的性质可知)
 
//定义车结构体
typedef struct CAR
{
	string kind;//车型
	string carID;//车牌
	int parkID;//停车位
	time_t enterTime;//停车开始时间
}Car;
 
 
//定义队列
//定义队列结构体
struct QueueCar
{
	Car *que;
	int front;
	int rear;
	int maxsize;
	int sizeinQueue;
};
 
//初始化
bool Initqueue(QueueCar &s)
{
	s.maxsize = N;
	s.que = new Car[s.maxsize];
	if (!s.que)
	{
		printf("分配失败\n");
		return false;
	}
	s.front = 0;
	s.rear = 0;
	return true;
}
 
//入队
void enqueue(QueueCar &s, Car item)
{
	if ((s.rear + 1) % s.maxsize == s.front)
		printf("\n候车道已满，欢迎有空光临\n");
	else
	{
		//打开文件（文件不存在会自动新建）
		FILE *fpqueue;
		if ((fpqueue = fopen("D:\\VS2013\\停车场\\queue.1", "wb+")) == NULL){
			printf("Cannot open file strike any key exit!");
			getch();
			exit(1);
		}
 
		s.rear = (s.rear + 1) % s.maxsize;
		s.que[s.rear] = item;//队尾入元素
 
		//将候车道数据存入文件
		s.sizeinQueue++;
		fprintf(fpqueue, "%d", s.sizeinQueue);//写入数据
 
		/*
		//将候车道数据取出
		rewind(fpqueue);
		fscanf(fpqueue, "%d", &s.sizeinQueue);//读出数据
		printf("\n读取候车道文件中...\n");
		printf("您车型的候车道车辆数量:%d\n", s.sizeinQueue);
		*/
		fclose(fpqueue); //关闭文件
		return;
	}
}
 
//出队
bool outqueue(QueueCar &s, Car &item)
{
	//打开文件（文件不存在会自动新建）
	FILE *fpqueue;//指针名与前面的入队里的文件指针可以不同，只要指向相同的文件即可
	if ((fpqueue = fopen("D:\\VS2013\\停车场\\queue.1", "wb+")) == NULL)
	{
		printf("Cannot open file strike any key exit!");
		getch();
		exit(1);
	}
 
	if (s.rear == s.front)
	{
		printf("队列为空\n");
	}
	s.front = (s.front + 1) % s.maxsize;
	item = s.que[s.front];
 
	//将候车道数据存入文件
	s.sizeinQueue--;
	fprintf(fpqueue, "%d", s.sizeinQueue);//写入数据
	
	/*
	//将候车道数据取出
	rewind(fpqueue);
	fscanf(fpqueue, "%d", &s.sizeinQueue);//读出数据
	printf("\n读取候车道文件中...\n");
	printf("\n您车型的候车道车辆数量:%d\n",s.sizeinQueue);
	*/
	fclose(fpqueue); //关闭文件
	return true;
}
 
//判空
bool isemptyqueue(QueueCar s)
{
	if (s.front == s.rear)
		return true;
	return false;
}

