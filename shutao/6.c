nclude<stdio.h>
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
//增加功能：用三个队列
#include "1.h"
#include <time.h> //为了调用时间函数
 
Car car[3][maxsize];
QueueCar smallqueue;
QueueCar mediumqueue;
QueueCar bigqueue;
 
//获取当地时间
void Calendar(time_t t)
{
	time(&t);
	struct  tm* tminfo;
	tminfo = localtime(&t);
	printf("Date: %04d-%02d-%02d %02d时%02d分%02d秒\n", tminfo->tm_year + 1900,
		tminfo->tm_mon + 1, tminfo->tm_mday, tminfo->tm_hour, tminfo->tm_min, tminfo->tm_sec);
	return;
}
 
//查询停车场整体情况
void findPark()
{
	printf("剩余小型车停车位：%d  ", maxsize - size[0]);
	printf("剩余中型车停车位：%d  ", maxsize - size[1]);
	printf("剩余大型车停车位：%d\n", maxsize - size[2]);
	printf("剩余小型车候车位：%d  ", N - 1 - smallqueue.sizeinQueue);
	printf("剩余中型车候车位：%d  ", N - 1 - mediumqueue.sizeinQueue);
	printf("剩余大型车候车位：%d\n", N - 1 - bigqueue.sizeinQueue);
	
	//查看停车场所有车的carID,kind和parkID
	FILE *fppark;
	if ((fppark = fopen("D:\\VS2013\\停车场\\park.1", "wb+")) == NULL)
	{
		printf("Cannot open file strike any key exit!");
		getch();
		exit(1);
	}		
 
	rewind(fppark);
	fread(car, sizeof(Car), 1, fppark);	//读取停车场数据
	printf("\n读取停车场文件中...\n停车场全部车辆信息：\n");
	int flagfile=0;//标志停车场内有无车，默认无车
	for(int i=0;i<3;i++)
	{
		for (int k = 0; k < maxsize;k++)
		{
			if(car[i][k].kind != "0"&&car[i][k].carID != "0")
			{
				printf("carID：%s\tkind：%s\t", car[i][k].carID.c_str(), car[i][k].kind.c_str());
				if (i == 0)//对小型车特殊处理
				{
					if (k < 10)
						printf("parkID：00%d\n", car[i][k].parkID);//显示结果为00*
					else
						printf("parkID：0%d\n", car[i][k].parkID);//显示结果为0**
				}
				else
					printf("parkID：%d\n", car[i][k].parkID);
				flagfile += 1;
			}
		}
	}
	if (flagfile == 0)
		printf("停车场内无车");
	
	fclose(fppark);//关闭文件
 
	return;
}
 
//判断停车场是否停满车，规定不同车型只能停在对应车型的车位
bool notFull(string kind)
{
	if (kind == "small")
		return maxsize - size[0];
	else if (kind == "medium")
		return maxsize - size[1];
	else return maxsize - size[2];
}
 
//停车
void enterCar(QueueCar &q, string kind, string carID)
{
	if (notFull(kind))//有剩余车位
	{
		int i = 0;
		if (kind == "small")
			i = 0;
		else if (kind == "medium")
			i = 1;
		else if (kind == "big")
			i = 2;
		else
		{
			printf("请您输入正确的车型\n");
			printf("程序将退到主菜单......\n");
			return;
		}
		//查找具体剩余的车位是哪些
		printf("剩余车位:\n");
		for (int j = 0; j < maxsize; j++)
		{
			if (car[i][j].kind == "0"&&car[i][j].carID == "0")//Menu函数中已将结构体kind和carID初始化为"0",表示该车位是空着的
			{
				int parkNumber = 100 * i + j;//获取停车位
				if (i == 0)//对小型车特殊处理
				{
					if (j < 10)
						printf("00%d ", parkNumber);//显示结果为00*
					else
						printf("0%d ", parkNumber);//显示结果为0**
				}
				else
					printf("%d ", parkNumber);
			}
		}
		printf("\n请选择车位:");
		int parkID;
		scanf("%d", &parkID);
 
		int k = 0;
		k = parkID % 100;//作用同上面for循环的j
 
		//判断parkID是否合法，且车不能停在已经有车的车位
		if (parkID >= 100 * i && parkID < 100 * i + maxsize&&car[i][k].kind == "0"&&car[i][k].carID == "0")
		{
			//打开文件（文件不存在会自动新建）
			FILE *fppark;
			if ((fppark = fopen("D:\\VS2013\\停车场\\park.1", "wb+")) == NULL)
			{
				printf("Cannot open file strike any key exit!");
				getch();
				exit(1);
			}
 
			car[i][k] = { kind, carID, parkID, time(NULL) };
			printf("进入停车场的时间：  ");
			Calendar(car[i][k].enterTime);
			if (i == 0)//对小型车特殊处理
			{
				if (k < 10)
					printf("请停在 00%d 号车位\n", car[i][k].parkID);//显示结果为00*
				else
					printf("请停在 0%d 号车位\n", car[i][k].parkID);//显示结果为0**
			}
			else
				printf("请停在 %d 号车位\n", car[i][k].parkID);
			size[i]++;//停车场对应车型停车数+1		
 
			//将停车场数据存入文件
			fwrite(car, sizeof(Car), 1, fppark);
			
			/*
			//将停车场数据取出
			rewind(fppark);
			fread(car, sizeof(Car), 1, fppark);
			printf("\n读取停车场文件中...\n您正操作的车的信息：\n");
			printf("进入停车场的时间：  ");
			Calendar(car[i][k].enterTime);
			printf("carID：%s\tkind：%s\t", car[i][k].carID.c_str(), car[i][k].kind.c_str());
			if (i == 0)//对小型车特殊处理
			{
				if (k < 10)
					printf("parkID：00%d\n", car[i][k].parkID);//显示结果为00*
				else
					printf("parkID：0%d\n", car[i][k].parkID);//显示结果为0**
			}
			else
				printf("parkID：%d\n", car[i][k].parkID);
			*/
			fclose(fppark);//关闭文件
		}
		else//用户选择错误
		{
			printf("sorry,您选择的车位已经有车了或者您输入了不存在的停车位\n");
			printf("程序将退到主菜单......\n");
			return;
		}
	}
	else //若无剩余车位，即停车场满时，则车进入候车道
	{
		if (N - 1 == q.sizeinQueue)//候车道满
		{
			printf("暂无您选择的车位，且候车道已满，欢迎有空再光临\n");
			return;
		}
		else//候车道未满
		{
			printf("暂无您选择的车位，请进入您的车型所在候车道排队等待\n");
			Car carinQueue = { kind, carID, 0, time(NULL) };
			enqueue(q, carinQueue);//入候车道
		}
	}
	return;
}
 
//取车
void leaveCar(string carID)
{
	printf("请输入车牌号：");
	cin >> carID;
	int flag = 0;
	for (int i = 0; i < 3; i++)
	{
	for (int j = 0; j < maxsize; j++)
		{
			if (car[i][j].kind == "0"&&car[i][j].carID == "0")//该停车位无车
				continue;
			if (car[i][j].carID == carID)//找到车了
			{
				string kind = car[i][j].kind;
				//打开文件（文件不存在会自动新建）
				FILE *fppark;
				if ((fppark = fopen("D:\\VS2013\\停车场\\park.1", "wb+")) == NULL)
				{
					printf("Cannot open file strike any key exit!");
					getch();
					exit(1);
				}
				time_t leaveTime = time(NULL);//车离开的时间
				printf("离开停车场的时间：  ");
				Calendar(leaveTime);
				printf("共计在停车场停留 %d 秒\t", leaveTime - car[i][j].enterTime);
				printf("总费用为：%.2fRMB\n", priceper*parkArea[i] * (leaveTime - car[i][j].enterTime));
				size[i]--;//停车场对应车车辆数-1
 
				//将停车场数据存入文件
				fwrite(car, sizeof(Car), 1, fppark);
			
				/*
				//将停车场数据取出
				rewind(fppark);
				fread(car, sizeof(Car), 1, fppark);
				printf("\n读取停车场文件中...\n您正操作的车的信息：\n");
				printf("离开停车场的时间： ");
				Calendar(leaveTime);
				printf("carID：%s\tkind：%s\t", car[i][j].carID.c_str(), car[i][j].kind.c_str());
				if (i == 0)//对小型车特殊处理
				{
					if (j < 10)
						printf("parkID：00%d\n", car[i][j].parkID);//显示结果为00*
					else
						printf("parkID：0%d\n", car[i][j].parkID);//显示结果为0**
				}
				else
					printf("parkID：%d\n", car[i][j].parkID);
				*/
				string leavecarKind = car[i][j].kind;//离开的车的车型
 
				//将新的该车位的新数据存入文件
				car[i][j].kind = "0";
				car[i][j].carID = "0";
				fwrite(car, sizeof(Car), 1, fppark);
				fclose(fppark);//关闭文件
 
				//通知候车道
				if (kind == "small")//小型车
				{
					if (!isemptyqueue(smallqueue))//如果候车道有车
					{
						//停车场出现空位，通知候车道		
						Car item;
						printf("请小型车候车道队首车出队，前往咨询处");
						outqueue(smallqueue, item);
						if (item.kind == leavecarKind)
							printf("\n请在咨询处的车进行操作（选菜单）：");
					}
				}
				else if (kind == "medium")//中型车
				{
					if (!isemptyqueue(mediumqueue))//如果候车道有车
					{
						//停车场出现空位，通知候车道		
						Car item;
						printf("请中型车候车道队首车出队，前往咨询处");
						outqueue(mediumqueue, item);
						if (item.kind == leavecarKind)
							printf("\n请在咨询处的车进行操作（选菜单）：");
					}
				}
				else//大型车
				{
					if (!isemptyqueue(bigqueue))//如果候车道有车
					{
						//停车场出现空位，通知候车道		
						Car item;
						printf("请大型车候车道队首车出队，前往咨询处");
						outqueue(bigqueue, item);
						if (item.kind == leavecarKind)
							printf("\n请在咨询处的车进行操作（选菜单）：");
					}
				}
					flag = 1;
					break;//已经取了车，跳车第一层循环
				}
			}
			if (flag == 1)
				break;//已经取了车，跳出第二层循环
		}
		if (flag == 0)//没找到车牌号对应的车
		{
			printf("sorry,您要取的车并未停在贵大停车场,请检查您输入的车牌号是否正确，\n");
			printf("程序将退到主菜单......\n");
		}
		return;
	
}
 
//菜单
void Menu()
{
	//初始化
 
	//将全部结构体成员kind和carID初始化为“0”
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < maxsize; j++)
		{
			car[i][j].carID = "0";
			car[i][j].kind = "0";
		}
	}
	//初始化候车道为空
	Initqueue(smallqueue);
	Initqueue(mediumqueue);
	Initqueue(bigqueue);
	system("color 2E");//更改dos窗口背景和前景颜色
	do{
		printf("\n");
		for (int i = 0; i<20; i++)
			printf("*");
		printf("*****欢迎来到**停车场！*****");
		for (int i = 0; i<20; i++)
			printf("*");
		printf("\n");
		printf("1:存入车辆  2：取出车辆  3:查询停车场整体情况  4：退出\n");
		printf("请选择：");
		int key;
		scanf("%d", &key);
		switch (key)
		{
			case 1:
			{
 
						printf("请分别输入车型（small,medium or big），车牌\n");
						string kind, carID;
						printf("车型（输入车型后请按回车键）:");
						cin >> kind;
						printf("车牌:");
						cin >> carID;
						if (kind == "small")
							enterCar(smallqueue, kind, carID);
						else if (kind == "medium")
							enterCar(mediumqueue, kind, carID);
						else
							enterCar(bigqueue, kind, carID);
						printf("\n"); break; }
			case 2:
			{
						string carID;
						leaveCar(carID);
						printf("\n"); break;
			}
			case 3:
				findPark(); printf("\n"); break;
 
			case 4:
				exit(0); printf("\n"); break;
			default:
			{
						printf("您输入了错误的指示，请您重新输入！\n");
						printf("如果您喜欢输入奇怪的东西，程序可能崩溃且不能进入主菜单\n");
						printf("请您记得崩溃后按ctrl+c结束程序\n");
						printf("程序将退到主菜单......\n");
			}
		}
	} while (true);
	return;
}
 
	int main()//主函数
	{
		Menu();
		return 0;
	}
 
