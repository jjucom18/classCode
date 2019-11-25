#include<iostream>
using namespace std;
#define PRICE 10
#define MAXN  2

class Car
{
public:
    string CarNum;
    int ArrTime;
    int AwayTime;
public:
    Car(string s,int arrtime):CarNum(s),ArrTime(arrtime)
    {
        AwayTime=-1;
    }
    Car()
    {

    }
    void SetAwayTime(int awaytime)
    {
        AwayTime=awaytime;
    }
    void SetArrTime(int arrtime)
    {
        ArrTime=arrtime;
    }
};
class Manager
{
private:
    queue<Car> SideWalkOfCar;
    stack<Car> Parking;
    stack<Car> MidCar;
public:
    Manager()
    {
        while(!SideWalkOfCar.empty())
            SideWalkOfCar.pop();
        while(!Parking.empty())
            Parking.pop();
        while(!MidCar.empty())
            MidCar.pop();
    }
    bool AddCar(Car car)//添加车
    {
        /*
        如果停车场没满就加入停车场
        满 则停到过道，并且把进入停车场时间设为-1
        */
        if(Parking.size()<MAXN)
            Parking.push(car);
        else
        {
            SideWalkOfCar.push(car);
            car.ArrTime=-1;
        }
        return 1;
    }
    Car DelCar(string carnum,int awaytime)//删除车 根据车牌号删除车辆
    {
        int flag=0;//查看车是否在停车场
        Car nowcar;
        while(!Parking.empty())
        {
            if(Parking.top().CarNum==carnum)
            {
                flag=1;
                nowcar=Parking.top();
                nowcar.AwayTime=awaytime;
                Parking.pop();
                break;
            }
            MidCar.push(Parking.top());
            Parking.pop();
        }
        while(!MidCar.empty())
        {
            Parking.push(MidCar.top());
            MidCar.pop();
        }
        if(flag)//从停车场出来了
        {
            if(!SideWalkOfCar.empty())
            {
                //将便道上的车 进入停车场并且设定进入停车场时间
                Car mmm;
                mmm=SideWalkOfCar.front();
                mmm.ArrTime=awaytime;
                SideWalkOfCar.pop();
                Parking.push(mmm);
            }
            return nowcar;
        }
        else//停车场没有
        {
            int cnt=SideWalkOfCar.size();
            while(cnt--)
            {
                Car mmm;
                mmm=SideWalkOfCar.front();
                SideWalkOfCar.pop();
                if(mmm.CarNum==carnum)
                {
                    mmm.ArrTime=-1;
                    flag=1;
                    nowcar=mmm;
                }
                else
                  SideWalkOfCar.push(mmm);
            }
        }
        if(flag)
            return nowcar;
        return Car("ERROR",-1);
    }
    int Charge(Car car)//根据车算出收费
    {
        if(car.ArrTime==-1)
            return 0;
        return (car.AwayTime-car.ArrTime)*PRICE;
    }
};
