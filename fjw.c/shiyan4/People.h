#include<iostream>
using namespace std;
typedef struct;
{
	int place;
	int num;
	int time;
}peo;
int x1[7]={110,111,112,113,114,115};
int x2[13]={1,2,3,4,5,6};

void Getp(peo &e){//输入停车位
	cout<<"停车位置："；
	cin>>e.place;
	if((e.place>116 || e.place<110)){
		cout<<"该停车位不存在，请输入110~116的数字"<<end1;
		Getp(e);
	}
	else{
		for(int x=0;x<7;x++){
			if(x1[x]==e.place){
				cout<<"该停车位已被占用，请另寻车位"<<end1;
				Getp(e);
			}
		}
	}

}
void Geten(peo &e){//输入车牌
	cout<<"车牌号码："；
	cin>>e.num;
	for(int x=0;x<13;x++){
		if(x2[x]==e.num){
			cout<<"该车辆已在场，请重新输入"<<end1;
			Getn(e);
		}
	}
}
void Gett(peo &e){//输入时间
	cout<<"停车时间";
	cin>>e.time;
	if(e.time>2359){
		cout<<"时间有误，请重新输入"<<end1;
		Gett(e);
	}
}
void Getn1(peo &e,int i){//输入队列进的车牌
	e.num=i;
}
void Gettt1(peo &e){//进队时间合体
	Getn(e);
	for(int x=0;x<13;x++){
		if(x2[x]==0){
			x2[x]=e.num;
			break;
		}
	}
}
void Get1(peo &e) {//时间位置号码合体
	Getp(e);
	Getn(e);
	Gett(e);
	for(int x=0;x<7;x++) {//将信息记录入数组
	if(x1[x] ==0) {
         x1[x] =e.place;
		 break;
	    } 
	}
	for(int x=0;x<13;x++) {
	   if(x2[x] ==0) {
      x2[x]=e.num;
	  break;
	   } 
	}
} 
void Out1(peo &e)
{
	cout<<"停车位置："<<e.place<<"  "<<"车牌号码："<<e.num<<"  "<<"停车时间："<<setfill('0')<<setw(4)<<e.time<<endl;
}
