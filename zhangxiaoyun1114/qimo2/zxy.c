#include"zxy.h"
int window[N];//窗口管理，如window[1]=2,说明此窗口正有2个人在排队;

double TotalTime=0;//客户逗留总时间时间

double TotalNumber=0;//今天来到银行客户总数

void CloseBank()//银行已经下班的操作函数

{

printf("\n尊敬的客户你好～～\n银行已经下班，请您明天再来～～～谢谢光临～～～\n");

}

void NoCloseBank()//银行未开门的操作函数

{

printf("\n尊敬的客户，您好～银行还未开门，请您稍等片刻～～～\n");

}

void GetNumberBank(LinkBank H)//取号函数

{

timeBank t;

ConnectionNumberBank();//总客户人数加1

printf("尊敬的客户，您的号码牌是%.f\n",TotalNumber);

int x=OptWindowBank();//x记录该客户所在的窗口

t=GetTimeBank();

ConnectionEnterBank(H,TotalNumber,x,t);//客户信息进入临时链表

}

void ExportNumberBank(LinkBank H)//输出正在银行逗留客户号码 {

LinkBank1 *p;

p=H;

if(p->next==NULL)//临时客户信息链表为空

{

printf("\n银行现在没有客户\n");

}

else{

printf("\n此时以下编号客户还在银行排队:\n");

for(p=p->next;p->next!=NULL;p=p->next)

printf("%.f-",p->num);

printf("%.f",p->num);

}

}

intOptWindowBank()//选择窗口

{

inti,x,number;//x记录人数最少的窗口序号，number最少人数窗口的人数

number=window[0];

x=1;

for(i=1;i<N;i++)

if(number>window[i])

{

number=window[i];

x=i+1;

}

printf("%d窗口排队人数为%d,为所有窗口人数最少，请您前往排

队\n",x,number);

printf("=====================================================

==========================\n");

printf("*****************************************************

**************************\n");

window[x-1]++;

return x;

}

void

ConnectionEnterBank(LinkBankH,doublenum,intn,timeBankArriveTime)/

/客户信息输入链表

{

LinkBankpre,s,p;

pre=H;

s=(LinkBank1 *)malloc(sizeof(LinkBank1));

s->num=num;

s->n=n;

s->ArriveTime.h=ArriveTime.h;

s->ArriveTime.m=ArriveTime.m;

s->ArriveTime.s=ArriveTime.s;

if(pre->next==NULL)

{

pre->next=s;

s->next=NULL;

}

else

{

p=s;

s->next=pre->next;

pre->next=p;

}

}

intConnectionGooutBank(LinkSeek *Q,LinkBankH,intnum)//销号 {

LinkBankp,r;

int n;

double num1,StypTime=0;

timeBank t1,t2;

int k;

r=H;k=0;

p=r->next;

for(;p->next!=NULL;p=p->next,r=r->next)//查找客户销号的号码

{

if(p->num==num)

{

window[p->n-1]--;

n=p->n;

num1=p->num;

t1.h=p->ArriveTime.h;

t1.m=p->ArriveTime.m;

t1.s=p->ArriveTime.s;

t2=GetTimeBank();

EnterBank(Q,num,n,t1,t2);

StypTime=CountTimeBank(t1,t2);

TimeNumberBank(StypTime);

r->next=p->next;//删除结点p

free(p);

return 1;

}

}

if(p->num==num)//最后一个结点为所要删除的结点

{

window[p->n]--;

n=p->n;

num1=p->num;

t1.h=p->ArriveTime.h;

t1.m=p->ArriveTime.m;

t1.s=p->ArriveTime.s;

t2=GetTimeBank();

EnterBank(Q,num,n,t1,t2);

StypTime=CountTimeBank(t1,t2);

TimeNumberBank(StypTime);

r->next=p->next;//删除结点p

free(p);

return 1;

}

return 0;

}

timeBankGetTimeBank()//取系统当前的时间

{

time_ttimep;//取系统时间

struct tm *p;

time(&timep);

p=localtime(&timep); /*取得当地时间*/

//printf ("当前系统时间为:%d/%d/%d ", (1900+p->tm_year),( 1+p->tm_mon), p->tm_mday);

//printf("%d:%d:%d\n",p->tm_hour, p->tm_min, p->tm_sec);

timeBank t;//t是当前系统时间

t.h= p->tm_hour;

t.m= p->tm_min;

t.s= p->tm_sec;

return(t);

}

void ConnectionNumberBank()//总客户人数加1

{

TotalNumber=TotalNumber+1; }

void TimeNumberBank(double t)//总共逗留时间累加

{

TotalTime=TotalTime+t; }

void AveragetimeBank()//客户平均逗留时间

{

double average1,TotalNum;

inti,h,m,s,average,x,sum=0;

for(i=0;i<N;i++)

sum=sum+window[i];

if(sum!=0)

{

TotalNum=TotalNumber-sum;

}

elseTotalNum=TotalNumber;

if(TotalNumber==0)

{

printf("此时还不能计算客户在银行平均逗留时间\n");

}else{

average1=TotalTime/TotalNum+0.5;

average=(int)average1;

h=average/3600;

x=average%3600;

m=x/60;

s=x%60;

printf("\n今天客户在银行平均逗留的时间

为: %02d:%02d:%02d\n",h,m,s);

}

}

void ClearConnectionBank(LinkSeek *Q,LinkBank H)//银行关门清理客户

{

LinkBank1 *p;

doublepp[100];

int i;

p=H;

if(p->next==NULL)//临时客户信息链表为空

{

printf("客户清理完成\n");

}

else{

for(i=0,p=p->next;p->next!=NULL;p=p->next,i++)

{

pp[i]=p->num;

}

pp[i]=p->num;

pp[i+1]=0;

for(i=0;pp[i]!=0;i++)

{

ConnectionGooutBank(Q,H,pp[i]);

}

}

}

intInitBank(LinkSeek *Q)//初始化存储客户信息的队列 {

Q->front=(QueueBank *)malloc(sizeof(QueueBank));

if(Q->front!=NULL)

{

Q->rear=Q->front;

Q->front->next=NULL;

return 1;

}

return 0;

}

intEnterBank(LinkSeek

*Q,doublenum,intn,timeBankArriveTime,timeBankLeaveTime)//客户信

息入列

{

QueueBank *NuwQueue;

NuwQueue=(QueueBank *)malloc(sizeof(QueueBank));

if(NuwQueue!=NULL)

{

NuwQueue->num=num;

NuwQueue->n=n;

NuwQueue->ArriveTime.h=ArriveTime.h;

NuwQueue->ArriveTime.m=ArriveTime.m;

NuwQueue->ArriveTime.s=ArriveTime.s;

NuwQueue->LeaveTime.h=LeaveTime.h;

NuwQueue->LeaveTime.m=LeaveTime.m;

NuwQueue->LeaveTime.s=LeaveTime.s;

Q->rear->next=NuwQueue;

Q->rear=NuwQueue;

return 1;

}

else return 0;

}

intInitChainBank(LinkBank *H)//客户信息链表初始化

{

*H=(LinkBank)malloc(sizeof(LinkBank1));

(*H)->next=NULL;

return 1;

}

double CountTimeBank(timeBankArriveTime,timeBankLeaveTime)//计算

客户逗留时间

{

inth,m,s,sum;

h=LeaveTime.h-ArriveTime.h;

m=LeaveTime.m-ArriveTime.m;

s=LeaveTime.s-ArriveTime.s;

sum=h*3600+m*60+s;

return sum;

}

void ShowBank(LinkSeek *Q)//见队列中客户信息输出

{

if(Q->front==Q->rear)

printf("现在还没有客户信息\n");

else

{

printf("今日客户到银行来办理业务的信息是:\n");

QueueBank *s;

s=Q->front;

for(s=s->next;s!=Q->rear;s=s->next)

printf("%.f号客户%02d:%02d:%02d进入银行,在%d号窗口排队,%02d:%02d:%02d离开银行

\n",s->num,s->ArriveTime.h,s->ArriveTime.m,s->ArriveTime.s,s->n,s->LeaveTime.h,s->LeaveTime.m,s->LeaveTime.s);

printf("%.f号客户%02d:%02d:%02d进入银行,在%d号窗口排

队,%02d:%02d:%02d离开银行

\n",s->num,s->ArriveTime.h,s->ArriveTime.m,s->ArriveTime.s,s->n,s->LeaveTime.h,s->LeaveTime.m,s->LeaveTime.s);

}

printf("===============================================================================\n");

printf("*******************************************************************************\n");

}

intEntertimeBank(char c[])//判断输入的时间是否符合标准

{

int tab=1;

/****************************************/

if(c[8]!='\0')

tab=0;

if( ! (c[2]==':'&&c[5]==':') )//判断输入的第三个字符和第六个字符是否为‘:’

tab=0;

if( !(c[0]>='0'&&c[0]<='2') )//小时第一位只能是0、1、2

tab=0;

if(c[0]=='2')

if(!(c[1]>='0'&&c[1]<'4') )//如果小时第一位是2，那么小时第二位只能是0到4之间，不包括4

tab=0;

if( c[0]=='0'&&c[0]=='1')

if(!(c[1]>='0'&&c[1]<='9'))//小时第一位是0、1，小时第二位可以是0-9

tab=0;

if( !(c[3]>='0'&&c[3]<='5') )//分钟第一位只能是0-5

tab=0;

if( !(c[6]>='0'&&c[6]<='6') )//秒钟第一位可以是0-6

tab=0;

if( c[6]=='6')

if(!(c[7]=='0'||c[7]=='1') )//当秒钟第一位是6，则第二位是0、1

tab=0;

if( !( c[4]>='0'&&c[4]<='9') )//分钟第二位一定是0-9

tab=0;

if(!(c[7]>='0'&&c[7]<='9') ) //秒钟第二位一定是0-9

tab=0;

return tab;

}

voidHelpBank()

{

printf("=====================================================

==========================\n");printf("=====================================================

==========================\n");printf("*****************************说明与帮助

****************************************\n"); printf("说明:\n");

printf("银行模拟系统，计算一天中客户在银行逗留的平均时间。银行

有5个窗口对外接待客户，从");

printf("早晨银行开门起不断有客户进入银行。由于每个窗口在某个时

刻只能接待一个客户，因此在");

printf("客户人数众多时需在每个窗口前顺次排队，对于刚进入银行的客户，如果某个窗口的业务员");

printf("正空闲，则可上前办理业务;反之，若N个窗口均有客户所占，他便会排在人数最少的队伍");

printf("后面。本系统主要功能:\n");

printf("(1)在界面上设定银行的对外营业时间(银行的开门时间以及银行的关门时间)。\n");

printf("(2)记录客户的到达时间以及客户的离开时间，客户的号码牌和办理业务的窗口;并在计\n");

printf("\t算客户平均逗留时间时，输出客户信息。\n"); printf("(3)可以计算出今天银行中客户在银行逗留的平均时间，并输出输出记录客户的信息。\n");

printf("(4)银行下班，将自动退出系统，并清理当前银行的客户，计算客户平均逗留时间，和输\n");

printf("\t出今日记录客户的信息\n");

printf("===============================================================================\n");
printf("帮助:\n");

printf("输入银行开关门时间必须注意以下问题:\n"); printf("1)不存在分钟为61，小时为24，秒钟为62等情况;\n");
printf("2)时间必须输入标准格式(**:**:**型)，小时、分钟、秒钟都是两位数(如小时是8，那");
printf("\t么我们用08表示)\n");

printf("3)时间间隔符“:”，是在英文状态下输入的，汉语输入“:”是非法输入,英语输入“:”");

printf("\t是正确的输入\n");

printf("4)银行开门时间一定是小于关门时间，如果输入关门时间小于开门时间\n");

printf("如不遵守以上输入，都将不能进入此系统\n"); 
printf("==============================================================================\n")

printf("\n");

}




