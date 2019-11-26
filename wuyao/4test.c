#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct
{
        int place;
        int num;
        int time;

}peo;
int x1[7]={110,111,112,113,114,115};
int x2[13]={1,2,3,4,5,6};

void Getp(peo &e){
        cout<<"tingcheweizhi:";
        cin>>e.place;
        if((e.place>116 || e.place<110)){
                cout<<"gaitingcheweibucunzai,qingshuru110~116deshuzi"<<end1;
                Getp(e);
        }
        else{
                for(int x=0;x<7;x++){
                        if(x1[x]==e.place){
                                cout<<"gaitingcheweiyibeizhanyong,qinglingzhaochewei"<<end1;
                                Getp(e)
                        }
                }
        }
}
void Gett(peo &e){
        cout<<"tingcheshijian:";
        cin>>e.time;
        if(e.time>2359){
                cout<<"shijianyouwu,qingjianchahoushuru"<<end1;
                Gett(e);
        }
}
void Getn1(peo &e,int i){
        e.num=i;
}
void Gettt1(peo &e){
        Getn(e);
        for(int x=0;x<13;x++){
                if(x2[x]==0){
                        x2[x]=e.num;
                        break;
                }
        }
}
void Get1(peo &e){
        Getp(e);
        Getn(e);
        Gett(e);
        for(int x=0;x<7;x++){
                if(x1[x]==0){
                        x1[x]=e.place;
                        break;
                }
                                                                                                      
                }
        }
        for(int x=0;x<13;x++){
                if(x2[x]==0){
                        x2[x]=e.num;
                        break;
                }
        }
}
void Out1(peo &e)
{
        cout<<"tingcheweizhi:"<<e.place<<" "<<"chepaihaoma:"<<e.num<<" "<<"tingcheshijian:"<<setfill('0')<<setw(4)<<e.ti
me<<end1;
}
int Gett(int i)
{
        int j;
        cin>>j;
        if(j<i){
                cout<<"shijianyouwu,qingjianchahouchongxinshuru"<<end1;
                Gett(i);
        }
        else{
                cout<<"bencitingchefeiyongwei:"<<0.05*(j-i)<<"fen"<<end1;
        }

