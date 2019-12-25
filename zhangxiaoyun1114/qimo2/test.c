#include"zxy.h"

void main()

{

printf("\t*******************************************************\n");

printf("\t*******************************************************\n");

printf("\t******\t\t\t欢迎进入\t\t*******\n");

printf("\t******\t\t 银行管理系统\t\t*******\n");

printf("\t*******************************************************\n");

printf("\t*******************************************************\n");

printf("\n");

printf("\n");

timeBankopen,close;//银行开关门的时间

double CancleNumber=0;//用户要注销的号码

int i,j,judge1,judge2,temporary=0;//judge1判断客户是取号还是销号,judge2判断销号是否成功

timeBank t1,t2;

t1=GetTimeBank(); //取系统时间

printf("此时系统时间:%02d:%02d:%02d\n",t1.h,t1.m,t1.s);

/****************************************/ int tab1=1,tab2=1;//判断开关门时间输入是否合法1合法，0不合法

char c1[10],c2[10],c3[10],c4[10],c5[10];//c1取开门时间字符串，c2关门时间字符串,
//c3选择操作字符窜，c4销号字符串(协助判断输入是否合法)

/****************************************/ printf("*****************************************************

************************\n");

printf("查看此系统的说明和帮助是否(1/其他):");

scanf("%s",c5);

if(c5[0]=='1'&&c5[1]=='\0')

HelpBank();

printf("===============================================================================\n");

printf("请设置银行开门时间:");

scanf("%s",c1);

tab1=EntertimeBank(c1);

printf("请设置银行关门时间:");

scanf("%s",c2);

tab2=EntertimeBank(c2); while(tab1==0||tab2==0)

{

printf("请您细心的在英文状态下，输入标准的时间格式\n"); printf("请设置银行开门时间:");

scanf("%s",c1);

tab1=EntertimeBank(c1); printf("请设置银行关门时间:");

scanf("%s",c2);

tab2=EntertimeBank(c2);

};

open.h=(c1[0]-'0')*10+(c1[1]-'0'); open.m=(c1[3]-'0')*10+(c1[4]-'0'); open.s=(c1[6]-'0')*10+(c1[7]-'0'); close.h=(c2[0]-'0')*10+(c2[1]-'0'); close.m=(c2[3]-'0')*10+(c2[4]-'0'); close.s=(c2[6]-'0')*10+(c2[7]-'0'); printf("=====================================================

==========================\n");printf("\n");

printf("\n");

/****************************************/ printf("*****************************************************

**************************\n");

if((t1.h<open.h)||(t1.h==open.h&&t1.m<open.m)||(t1.h==open.h&&t1.

m==open.m&&t1.s<=open.s))//银行还未开门

NoCloseBank();

else

if((t1.h>close.h)||(t1.h==close.h&&t1.m>close.m)||(t1.h==close.h&&t1.

m==close.m&&t1.s>=close.s))

CloseBank();

else

{

LinkBank l;

InitChainBank(&l);//客户信息链表初始化

LinkSeek s;

InitBank(&s);//初始化存储客户信息的队列

do{

printf("\n");

printf("\n");

printf("\n");

printf("\n");

printf("********************************打印线

*****************************************\n");

printf("==================================================

=============================\n");

ExportNumberBank(l);

/**************************************************/

printf("\n银行正在营业，请选择你需要的操作\n取号输入1，销

号输入0,查看平均逗留时间输入2:");

scanf("%s",c3);

if(c3[1]!='\0')

judge1=-1;

else if(!(c3[0]>='0'&&c3[0]<='2'))

judge1=-1;

else judge1=c3[0]-'0';

while(judge1==-1)

{

printf("对不起～您输入的数字不合法，请重新操作\n");
printf("银行正在营业，请选择你需要的操作\n取号输入1，销号输入0,查看平均逗留时间输入2:");

scanf("%s",c3);

if(c3[1]!='\0')

judge1=-1;

else if(!(c3[0]>='0'&&c3[0]<='2'))

judge1=-1;

else judge1=c3[0]-'0';

}

/**************************************************/

if(judge1==1)

GetNumberBank(l);//取号函数

else if(judge1==0)//销号

{

/******************************************************/

CancleNumber=0;

printf("你好～请输入你要销的号码:");

scanf("%s",c4);

for(i=0;c4[i]!='\0';i++)

{

if(!(c4[i]>='0'&&c4[i]<='9'))

judge2=0;

}

for(i=i-1,j=0;i>=0;i--,j++)

{

temporary=c4[j]-'0';

CancleNumber=CancleNumber+temporary*pow(10,i);

}

judge2=ConnectionGooutBank(&s,l, CancleNumber);//销号成功返回1，销号失败返回0

while(judge2==0)

{

CancleNumber=0;

printf("销号失败，可能是您要销的号不存在或输入不合法，请重新输入:");

scanf("%s",c4);

for(i=0;c4[i]!='\0';i++)

if(!(c4[i]>='0'&&c4[i]<='9'))

judge2=0;

for(i=i-1,j=0;i>=0;i--,j++)

{

temporary=c4[j]-'0';

CancleNumber=CancleNumber+temporary*pow(10,i);

}

judge2=ConnectionGooutBank(&s,l, CancleNumber);

}

/******************************************************/

printf("===============================================================================\n");

printf("*******************************************************************************\n");

}

else if(judge1==2)

{

AveragetimeBank();

ShowBank(&s);

}

t2=GetTimeBank();

}
while(((t2.h>open.h)||(t2.h==open.h&&t2.m>open.m)||(t2.h==open.h&&t2.m==open.m&&t2.s>=open.s))&&((t2.h<close.h)||(t2.h==close.h&&t2.m<close.m)||(t2.h==close.h&&t2.m==close.m&&t2.s<=close.s)));

printf("********************************打印线*****************************************\n");

printf("===============================================================================\n");

ClearConnectionBank(&s,l);//银行关门清理客户

AveragetimeBank();//客户平均逗留时间

ShowBank(&s);

printf("\n");

printf("\n");

printf("\n");

printf("\n");

printf("\t*******************************************************\n");

printf("\t*******************************************************\n");

printf("\t******\t\t\t银行下班\t\t*******\n");

printf("\t******\t\t 系统关闭 \t\t*******\n");

printf("\t*******************************************************\n");

printf("\t*******************************************************\n");

t1=GetTimeBank(); //取系统时间

printf("此时系统时间为:%02d:%02d:%02d\n",t1.h,t1.m,t1.s);

}

system("PAUSE");

}


