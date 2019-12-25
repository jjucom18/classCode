#ifndef  zxy_h
#define  zxy_h
#include<stdio.h> 
#include<time.h>

#include<malloc.h> 
#include<stdlib.h>
#include<string.h> 
#include<math.h>

#define N 5//窗口数目

typedefstructTimeBank {

int h;

int m;

int s;

}timeBank;//记录某一刻的时间

typedefstruct LinkBank1 {

int n;//客户分配反而窗口

double num;//客户编号

timeBankArriveTime;//客户进入银行的时间

struct LinkBank1 *next;

} *LinkBank;//临时存储客户信息

typedefstruct Node {

double num;//记录客户的编号

int n;//记录客户办理业务的窗口

timeBankArriveTime;//客户进入银行的时间 
timeBankLeaveTime;//客户离开银行的时间 
struct Node *next;//指针域

}QueueBank;//存储客户的到达事件和客户的离开事件的队列

typedefstruct

{

QueueBank *front; QueueBank *rear; }LinkSeek;

void CloseBank();//银行已经下班的操作函数 
void NoCloseBank();//银行未开门的操作函数

void GetNumberBank(LinkBank H);//取号函数

void ExportNumberBank(LinkBank H);//输出正在银行逗留客户号码 
int OptWindowBank();//选择窗口

int InitChainBank(LinkBank *H);//客户信息链表初始化

void ConnectionEnterBank(LinkBankH,doublenum,intn,timeBankArriveTime);

//客户信息存储到链表

int ConnectionGooutBank(LinkSeek *Q,LinkBankH,intnum);//客户信息从链表删除

int InitBank(LinkSeek *Q);//初始化存储客户信息的队列 
int EnterBank(LinkSeek *Q,doublenum,int n,timeBankArriveTime,timeBankLeaveTime);//客户信息入队操作

void ShowBank(LinkSeek *Q);//将队列中客户信息输出 
timeBankGetTimeBank();//取系统当前的时间

void ConnectionNumberBank();//总客户人数加1

void TimeNumberBank(double t);//总共逗留时间累加

void AveragetimeBank();//客户平均逗留时间

void ClearConnectionBank(LinkSeek *Q,LinkBank H);//银行关门清理客户

double CountTimeBank(timeBankArriveTime,timeBankLeaveTime);//计算客户逗留时间

int EntertimeBank(char c[]);//判断开输入开关门时间是否合法 
void HelpBank();//系统说明和帮助

