#include<iostream>
#include<string>
#include<fstream>
#define MaxChe 3
#define Chefei 0.5

using namespace std;
class Time
{
	public;
	int year;
	int mouth;
	int day;
	int hour;
	int minute;
	int second;
  void setTime()
  {
	  cout<<"Time"<<endl;
	  cout>>"year:";
	  cin>>year;
	  cout<<"mouth:";
	  cin>>mouth;
	  cout<<"day:";
	  cin>>day;
	  coutt<<"hour:";
	  cin>>hour;
	  cout<<"minute:";
	  cin>>minute;
	  cout<<"second:";
	  cin>>second;
  }void showTime(){
	  cout<<year<<mouth<<day<<hour<<minute<<seconde;
  }
};
class Che{
	public: string ID;
			stringColor;
			string CheXing
				Time aTime;
			Che *Next;
			Che(){}
			void Set()
			{
				cout<<"ID=";
				cin>>ID;
				cout<<"Color=";
				cin>>Color;
				cout<<"CheXing=(xiaoqiche xiaoka zhangka daka)"<<endl;
				cin>>CheXing;
				aTime.setTime();
			}void show()
			{
				cout<<ID;
				cout<<Color;
				cout<<CheXing;
				aTime.showTime();
			}~Che(){}
};
void Shouye();//首页
void Input();//车辆进入停车场
void Output();//车辆离开停车场并计算停车费用
void Chaxun();//按车牌查询停车信息
void Xianshi();//现实车库中的车辆信息
void Tongji();//统计车库中的车
void Bianji();//修改车库中的车的信息
void Cuo1();//
void main()
{
	Shouye();
}
void Shouye()//首页
{
	int 1;
	cout<<"**************************\n";
	cout<<"\t"<<"1.汽车进入停车场\n";
	cout<<"\t"<<"2.汽车出停车场\n";
    cout<<"\t"<<"3.汽车信息查询\n";
	cout<<"\t"<<"4.显示所有汽车\n";
	cout<<"\t"<<"5.汽车信息查询\n";
	cout<<"\t"<<"选择操作:";
	cin>>i
		switch(i)
		{
			case 1:{
					   system("cls");
					   Input();
                       break;
				   }break;
			case 2:{
					   system("cls");
					   Output();
					   break;
				   }break;
				   case 3{
					   system("cls");
					   Chaxun();
					   break;
				   }break;
			case 4:{
					   system("cls");
					   Xianshi();
					   break;
				   }break;
			case 5:{
					   system("cls");
					   Tongji();
					   break;
				   }break;
			default:{
						cout<<"无此选项"<<endl;
						cout<<"返回首页重新选择"<<endl;
						string h;
						cin.clear();
						cin>>h;
						if(h=="1")
						{
							system("cls");
							Shouye();

						}else{
							cou1();
						}
					}

		}

}  void Input()//车辆进入停车场
{
	istream fin("text.txt",ios::in);
	if(!fin){
		cout<<"文件打开失败！"<<endl;
	}int !;
	fin>>i;
	cout<<"停车场中已有车"<<i<<"辆"<<endl;
Che p[MaxChe];
for(int j=0;j<i;j++){
	fin>>p[j].ID>>p[j].Color>>p[j].CheXing>>p[j].aTime.year>>p[j].aTime.mouth
		>>p[j].aTime.day>>p[j].aTime.hour>>p[j].aTime.minute>>p[j]a.Time.seco
		cout<<p[j].ID<<"\t"<<p[j].Color<<"\t"<<p[j].CheXing<<"\t"p[j].a.Time.year<<"-"<<Time.mouth<<"-"
		<<p[j].aTimr.day<<"--"<<p[j]aTime.hour<<":"<<p[j].aTime.minute<<":"<<p[j].aTime.end<<endl;
} fin.close();
if(i<MaxChe){
	cout<<"车辆可以进入停车场"<<endl
		p[i].Set();
	ofstream fout("text.txt",ios::out);
	fout<<i+1<<endl;
	for(int j=0;j<i+1;j++){
		fout<<p[j].ID<<"\t"<<p[j].Color<<"\t"<<p[j].CheXing<<"\t"<<p[j].aTime.year<<"\t"<<p[j].aTime.mouth
	<<"\t"<<p[j].ID<<"\t"<<p[j].Color<<"\t"p[j].aTime.hour<<"\t"<<p[j].aTime.minute<<"\t"<<p[j].aTime.second
	<<"\n";
	}fout.close();
	cout<<"****************************************************"<<endl;
	cout<<"继续停车"<<endl;
	cout<<"返回首页"<<endl;
	int h;
	cin>>h;
	if(h==1)
		Input();
	if(h==2)
	{
		system("cls");
		Shouye();
	}if(h!=1&&h!=2)
	Cou1();
}else{
	cout<<"***************************************************";
	cout<<"停车场已满"<<endl;
	cout<<"返回首页"<<endl;
	int h;
    cin>>h;
	if(h==1){
		system("cls");
		Shouye();
	}else
		Cuo1();
}
}
void Output()//车辆离开停车场并计算停车费用
{
	ifstream fin("text.txt",ios::in);
	if(!fin){
		cout<<"文件打开失败"<<endl;
	} int i;
	fin>>i;
	cout<<"停车场中已有车"<<"辆"<<endl;
	Che p[MaxChe];
	for(int j=0;j<i;j++)
	{
		fin>>p[j].ID>>p[j].Color>>p[j].CheXing>>p[j].aTime.year>>p[j].aTime.mouth>>p[j].aTime.day>>p[j]
			.aTime.hour>>p[j].aTime.minute>>p[j].aTime.second<<endl;
		cout<<p[j].ID<<"\t"<<p[j].Color<<"\t"<<p[j].CheXing<<"\t"<<p[j].aTime.year<<"-"<<p[j].aTime.mouth
		<<"-"<<p[j].aTime.day<<"-"<<p[j].aTime.hour<<":"<<p[j].aTime.minute<<":"<<p[j].aTime.second<<endl;
	}fin.cloes();
	if(1!=0){
		string cp;
		out<<"按车牌查询"<<endl;
		cout<<"离开停车场车牌:";
			cin>>cp;
			cout<<"出场时间"<<endl;
			Time bTime;
              bTime.setTime();
			  ofstream fout("text.txt",ios::out);
			  fout<<i-1<<endl;
			  for(j=0;j<1;j++){
				  if(p[j].ID==cp){
					  cout<<"******************************************************"<<endl;
					  cout<<"该车辆进入停车场的时间为:";
        cout<<p[j].aTime.year<<"-"<<p[j].aTime.mouth<<"-"<<p[j].aTime.day<<"-"<<p[j].aTime.hour<<":"<<P[j]
			.aTime.minute<<":"<<p[j].aTime.second<<endl;
		cout<<"每分钟"<<Chefei<<"元钱"<<endl;
		int money;
     money=(bTime.year-p[j].aTime.year)*12*31*24*60+(bTime.mouth-p[j].aTime.mouth)*31*24*60+(bTime.day-
			 p[j].aTime.day)*24*60+(bTime.hour-p[j].aTime.hour)*60+(bTime.minute-p[j].aTime.minute)*10;
	 cout<<"共计"<<money<<"元钱"<<endl;
			  }
	}for(j=0;j<i;j++){
		if(p[j].ID==cp){
		int a;
		a=j;
		for(j=0;j<a;j++){
			fout<<p[j].ID<<"\t"<<p[j].Color<<"\t"<<p[j].CheXing<<"\t"<<p[j].aTime.year<<"\t"<<p[j].aTime.
				mouth<<"\t"<<p[j].aTime.day<<"\t"<<p[j].aTime.hour<<"\t"<<p[j].aTime.minute<<"\t"<<p[j].
				aTime.second<<endl;	
		}for(int j=a+1;j<1;j++){
			fout<<p[j].ID<<"\t"<<p[j].Color<<"\t"<<p[j].CheXing<<"\t"<<p[j].aTime.year<<"\t"<<p[j].aTime
				.mouth<<"\t"<<p[j].aTime.day<<"\t"<<p[j].aTime.hour<<"\t"<<p[j].aTime.minute<<"\t"<<p[j].
                 aTime.second<<endl;
		}cout<<"离场成功*********************"<<endl;
		cout<<"返回首页";
		int h;
		cin>>h;
		if(h==1){
			system("cls");
			Shouye();
		}else Cuo1();
		break;
	}
}
fout.close();
}
else{
	cout<<"停车场中无车辆"<<endl;
	cout<<"车辆进入停车场"<<endl;
	cout<<"返回首页"<<endl;
	int h;
	cin>>h;
	if(h==1)
		Input();
	if(h==2){
		system("cls");
				Shouye();
	}if(h!=1&&h!=2)
	Cuo1();
}
} 
