#include "1.h"
int main()
{
	StackCar Enter,Temp;
	LinkQueueCar Wait;
	int a;
	int b=1;
	lnitStack(&Enter);
	lnitStack(&Temp);
	lnitQueue(&Wait);
	while(b)
	{
		cout<<endl;
		cout<<"*********"<<endl;
		cout<<"<1>.汽车近战登记 <2>.汽车出站登记 <3>.车位状态显示 <4>.退出系统";
		cout<<"\n*********"<<endl;
		cout<<"请输入要进行的操作："<<endl;
		cin>>a;
		while(b)
		{
			if(a==||a==2||a==3||a==4) break;
			else
			{
				cout<<"\n错误！\n";
				b=0;

			}
		}
		switch(a)
		{
			case 1:Arrival(&Enter,&Wait);break;
			case 2:Leave(&Enter,&Temp,&Wait);break;
			case 3:List(Enter,Wait);break;
			case 4:exit(0);
			default:break;
		}
	}
	return 0
}















