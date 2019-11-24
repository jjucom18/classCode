//main.cpp
#include<iomanip>
#include"LinkQueue.h"
#include"SqList.h"
int main(int argc, char** argv)
{
    LinkQuNode *q1,*q2,*q3;//队列
    SqList *L;//链表
    InitQueue(q1);//进队
    InitQueue(q2);//出队结算
    InitQueue(q3);//出队结算
    InitList(L);//链表
    int i;
    ElemType e;//表自定类型对象 
    ElemType1 e1,e2,e3;//队列自定类型对象 
    int x11[]={110,111,112,113,114,115,116};//车位重复性检测 
    int x22[]={1,2,3,4,5,6,7};//车牌检测 
    peo x33[7];//一开始进场6辆车 
    for(int j=0;j<6;j++){
        x33[j].place=x11[j];
        x33[j].num=x22[j];
        x33[j].time=0; 
    }
    CreateList(L,x33,6);//初始6辆车
    cout<<"===========欢迎使用slyarh的停车场==========="<<endl<<endl;
    cout<<"          本停车场最多可停放7辆汽车"<<endl<<endl;
    while(i!=4){
        cout<<"================slyarh的系统================"<<endl<<endl;
        cout<<"             当前已停放"<<ListLength(L)<<"辆汽车~"<<endl;
        DispList(L);
        cout<<"您可以选择："<<endl<<endl; 
        cout<<" 1:入站"<<"  "<<"2:出站"<<"  "<<"3:出库汽车计费"<<"  "<<"4:退出系统"<<endl<<endl;
        cout<<"请选择:";
        cin>>i;
        switch(i){
            case 1:
                if(ListLength(L)==7){//停车场顺序表长度满7
                    if(QueueLength(q1)==3)  cout<<"     目前停车场已满，还请另寻他处停车~"<<endl<<endl;
                    else if(QueueLength(q1)!=3){
                        cout<<"     目前停车场已满，还请在通道内等待~"<<endl<<endl;
                        Gettt1(e);//车牌 
                        e1=e.num;
                        EnQueue(q1,e1);//进队等
                    }
                }
                else{
                    if(ListLength(L)==0)  cout<<"         您是本停车场的第一位顾客^v^"<<endl;
                    else{
                        cout<<"当前已被使用的车位有：";
                        for(int x=0;x<ListLength(L);x++){//遍历显示被用的车位 
                            for(int y=0;y<7;y++){
                                if(L->data[x].place==x1[y])  cout<<x1[y]<<" ";
                            }
                        }
                    }
                    cout<<endl<<"请输入入站汽车的相关信息："<<endl;
                    Get1(e);//获取车牌车位时间 
                    ListInsert(L,ListLength(L)+1,e);//插入停车场 
                }
                cout<<"当前停放的车辆有："<<endl;
                DispList(L);//显示停的车 
                if(!QueueEmpty(q1)){//候车区非空 
                    cout<<"当前候车区停放的车辆有："<<endl;
                    DispQueue(q1);
                }
                else  cout<<"当前候车区暂无车辆~"<<endl;
                if(!QueueEmpty(q2)){//结算区非空 
                    cout<<"当前等待结算离开的车辆有："<<endl;
                    DispQueue(q2);
                }
                else  cout<<"当前暂无等待结算离开的车辆~"<<endl;
                break;
            case 2:
                if(QueueLength(q2)==3)  cout<<"目前等待结算的车辆太多了~待其出库后您方可出站~！"<<endl;
                else{
                    if(ListEmpty(L))  cout<<"             没生意啊好心酸TvT~"<<endl;
                    else{
                        cout<<endl<<"请输入要出站的车的车牌号:";
                        ElemType i1;
                        cin>>i1.num;//车牌 
                        if(ListDelete(L,LocateElem(L,i1),e)){//查找并删除，e是被删的车
                            cout<<"车牌号为"<<e.num<<"的汽车已驶入结算区~"<<endl;
                            e2=e.num;//获取车牌 
                            EnQueue(q2,e2);//进结算队等
                            e3=e.time;
                            EnQueue(q3,e3);//获取该车最开始进入停车场时间
                            if(!QueueEmpty(q1)){//进队列非空
                                DeQueue(q1,e1);//出队（车牌
                                Getn1(e,e1);//车牌获取
                                cout<<"车牌为"<<e.num<<"的车辆现可以入库~！还请确定入库时间："<<endl;
                                Gett(e);//进场时间
                                ListInsert(L,ListLength(L)+1,e);//插入 
                            }
                            else{
                                for(int x=0;x<7;x++){//车位删除 
                                    if(x1[x]==e.place){
                                        x1[x]=0;
                                        break;
                                    }
                                }
                            }
                        }
                        else cout<<"不存在此车辆哦~请检查后重新输入~~"<<endl;
                        if(ListEmpty(L))  cout<<"             没生意啊好心酸TvT~"<<endl;
                        else{
                            cout<<"当前停放的车辆有："<<endl;
                            DispList(L);
                            }
                    } 
                }
                if(!QueueEmpty(q1)){
                    cout<<"当前候车区停放的车辆有："<<endl;
                    DispQueue(q1);
                }
                else  cout<<"当前候车区暂无车辆~"<<endl;
                if(!QueueEmpty(q2)){
                    cout<<"当前等待结算离开的车辆有："<<endl;
                    DispQueue(q2);
                }
                else  cout<<"当前暂无等待结算离开的车辆~"<<endl;
                break;
            case 3:
                if(QueueEmpty(q2))  cout<<"当前暂无等待结算离开的车辆~"<<endl;
                else{
                    DeQueue(q2,e2);//出队（车牌
                    cout<<"车牌为"<<e2<<"的车辆现进行费用结算~！还请输入当前时间：";
                    DeQueue(q3,e3);//出队（时间
                    Gettt(e3);//算钱 
                    cout<<"车牌号为"<<e2<<"的汽车已驶出停车场~~~!"<<endl;
                    for(int x=0;x<13;x++){//出场的车销毁车牌
                        if(x2[x]==e2){
                            x2[x]=0;
                            break;
                        }
                    }
                }
                if(!QueueEmpty(q1)){//非空 
                    cout<<"当前候车区停放的车辆有："<<endl;
                    DispQueue(q1);
                }
                else  cout<<"当前候车区暂无车辆~"<<endl;
                if(!QueueEmpty(q2)){
                    cout<<"当前等待结算离开的车辆有："<<endl;
                    DispQueue(q2);
                }
                else  cout<<"当前暂无等待结算离开的车辆~"<<endl;
                break;
            case 4:
                cout<<endl<<"     slyarh竭诚为您服务，欢迎下次再来~"<<endl;
                //销毁 
                DestroyList(L);
                DestroyQueue(q1);
                DestroyQueue(q2);
                DestroyQueue(q3);
                break;
            default:
                cout<<"您的输入有误，请检查后重新输入~"<<endl;
        }
    }
    return 0;
}
