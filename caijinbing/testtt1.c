   typedef struct time
{
        int hour;
        int min;
}Time;//时间节点                                                                                                                                                                                                                             typedef struct node                                                                                                                                                                                                                          {
        char num[10];
        Time reach;
        Time leave;
}CarNode;//车辆信息节点                                                                                                                                                                                                                      typedef struct NODE                                                                                                                                                                                                                          {
        CarNode*stack[MAXNUM+1];
        int top;
}SeqStackCar;//模拟车场                                                                                                                                                                                                                      typedef struct car                                                                                                                                                                                                                           {
        CarNode*data;
        struct car*next;
}QueueNode;                                                                                                                                                                                                                                  typedef struct Node                                                                                                                                                                                                                          {
        QueueNode*head;
        QueueNode*rear;
}LinkQueueCar;//模拟通道                                                                                                                                                                                                                     void StackInit(SeqStackCar*s)//初始化车场

{
        int i;
        s->top=0;
        for(i=0;i<=MAXNUM;i++)
                s->stack[s->top]=NULL;
}  
void stop_to_pave()                         // 车停入便道



void stop_to_pave()                     



{



    // 判断队满



    if (p.count > 0 && (p.front == (p.rear + 1) % MAX_PAVE))



    {



        printf ("便道已满，请下次再来\n");



    }



    else



    {



        strcpy(p.Pave[p.rear].plate, C);    // 车进入便道



        p.rear = (p.rear + 1) % MAX_PAVE;   // 队尾指示器加1



        p.count++;                          // 计数器加1



        strcpy(p.Pave[p.rear].plate, C);



        p.rear = (p.rear + 1) % MAX_PAVE;



        p.count++;                      



        printf ("牌照为%s的汽车停入便道上的%d的位置\n", C, p.rear);



    }



}







void car_come()                             // 车停入停车位



void car_come()                             



{



    printf ("请输入即将停车的车牌号:");     // 输入车牌号



    scanf ("%s", &C);



    if (s.top >= MAX_STOP - 1)              // 如果停车位已满，停入便道



    printf ("请输入即将停车的车牌号:");     



    scanf("%s",&C);



    if (s.top >= MAX_STOP - 1)              



    {



        stop_to_pave();                     // 停入便道



        stop_to_pave();                     



    }



    else



    {



        s.top++;                            // 停车位栈顶指针加1



        s.top++;                            



        time_t t1;



        long int t = time(&t1);             // 记录进入停车场的时间



        long int t = time(&t1);             



        char* t2;



        t2 = ctime (&t1);                   // 将当前时间转换为字符串



        t2 = ctime (&t1);                   



        s.Stop[s.top].timeIn = t;







        strcpy(s.Stop[s.top].plate, C);     // 将车牌号登记



        strcpy(s.Stop[s.top].plate, C);     



        printf ("牌照为%s的汽车停入停车位的%d车位, 当前时间:%s\n", C, s.top + 1, t2);



    }







    return ;



}







void stop_to_buff()                         // 车进入让路栈



void stop_to_buff()                         



{



    // 停车位栈压入临时栈，为需要出栈的车辆让出道



    while (s.top >= 0)



    {



        if (0 == strcmp(s.Stop[s.top].plate, C))



        {



            break;



        }







        // 让出的车进入让路栈



        strcpy(b.Help[b.top++].plate, s.Stop[s.top].plate);



        printf ("牌照为%s的汽车暂时退出停车场\n", s.Stop[s.top--].plate);



    }







    // 如果停车位中的车都让了道，说明停车位中无车辆需要出行



    if (s.top < 0)



    {



        printf ("停车位上无此车消息\n");

@@ -65,27 +59,23 @@ void stop_to_buff()                         // 车进入让路栈



        printf ("牌照为%s的汽车从停车场开走\n", s.Stop[s.top].plate);



        time_t t1;



        long int t = time (&t1);



        c.timeOut = t;                        // 标记离开停车场的时间



        c.timeOut = t;                      



        char* t2;



        t2 = ctime (&t1);                   // 获取当前时间



        printf ("离开时间%s\n需付%ld元\n", t2, Price * (c.timeOut - s.Stop[s.top].timeIn));



        t2 = ctime (&t1);               



        printf ("离开时间%s\n需付%d元\n",t2,Price * (c.timeOut - s.Stop[s.top].timeIn));



        s.top--;



    }







    // 将让路栈中的车辆信息压入停车位栈



    while (b.top > 0)



    {



        strcpy(s.Stop[++s.top].plate, b.Help[--b.top].plate);



        printf ("牌照为%s的汽车停回停车位%d车位\n", b.Help[b.top].plate, s.top);



    }







    // 从便道中 -> 停车位



    while (s.top < MAX_STOP-1)



    {



        if (0 == p.count)               // 判断队列是否为空



        if (0 == p.count)           



        {



            break;



        }   // 不为空，将便道中优先级高的车停入停车位



        }   



        else



        {



            strcpy(s.Stop[++s.top].plate, p.Pave[p.front].plate);

@@ -96,11 +86,11 @@ void stop_to_buff()                         // 车进入让路栈



    }



}







void car_leave()                        // 车离开



void car_leave()                        



{



    printf ("请输入即将离开的车牌号:\n");



    scanf ("%s", &C);



    if (s.top < 0)                      // 判断停车位是否有车辆信息



    if (s.top < 0)                  



    {



        printf ("车位已空，无车辆信息！\n");



    }

@@ -118,25 +108,24 @@ void Display()



        printf ("停车场为空\n");



    }



    time_t t1;



    long int t = time(&t1);             // 标记显示时的时间



    long int t = time(&t1);             



    printf ("\t车牌号\t\t\t停放时间\t\t当前所需支付金额\n");



    while (i != -1)



    {



        printf ("\t%s\t\t%d秒\t\t\t%d元\n", s.Stop[i].plate, t - s.Stop[i].timeIn, Price * (t - s.Stop[i].timeIn) / 10);



        printf("\t%s\t\t%d秒\t\t\t%d元\n",s.Stop[i].plate,t-s.Stop[i].timeIn,Price*(t-s.Stop[i].timeIn)/10);



        i--;



    }



}







void welcome()



{



    printf ("\t*******************目前停车场状况***********************\n");



    printf ("\t停车场共有%d个车位,当前停车场共有%d辆车,等候区共有%d辆车\n", MAX_STOP, s.top+1, (p.rear + MAX_PAVE - p.front)



                                                                       % MAX_PAVE);



    printf ("\t********************************************************\n");



    printf ("\t---------------------欢迎来到JJU停车场---------------------\n");



    printf ("\t*                     1.进入停车场                        *\n");



    printf ("\t*                     2.离开停车场                        *\n");



    printf ("\t*                     3.停车场信息                        *\n");



    printf ("\t*                     4.退出本系统                        *\n");



    printf ("\t-----------------------------------------------------------\n");



    printf("\t*******************目前停车场状况***********************\n");



    printf("\t停车场共有%d个车位,当前停车场共有%d辆车,等候区共有%d辆车\n",MAX_STOP,s.Stop+1,(p.rear + MAX_PAVE - p.front)%MAX_PAVE);



    printf("\t********************************************************\n");



    printf("\t---------------------欢迎来到JJU停车场---------------------\n");



    printf("\t*                     1.进入停车场                        *\n");



    printf("\t*                     2.离开停车场                        *\n");



    printf("\t*                     3.停车场信息                        *\n");



    printf("\t*                     4.退出本系统                        *\n");



    printf("\t-----------------------------------------------------------\n");



}
55 A1812-10/shiyan4/Plot.h 



@@ -1,46 +1,37 @@



#ifndef  __PLOT_H__



#ifndef __PLOT_H__



#define __PLOT_H__







#define Price    1          // 单价可以自己定义n



#define Price    1      



#define MAX_STOP 10



#define MAX_PAVE 10







#include <stdlib.h>



#include <stdio.h>



#include <windows.h>



#include <time.h>                           // 包含时间函数的头文件



#include <string.h>







// 汽车信息



#include<stdlib.h>



#include<stdio.h>



#include<unistd.h>



#include<time.h>                        



#include<string.h>



typedef struct



{







    int timeIn;              // 进入停车场时间



    int timeOut;             // 离开停车场时间



    int timeIn;             



    int timeOut;             



    char plate[10];



    // 汽车牌照号码，定义一个字符指针类型



}Car;







// 停放栈（用于停放车辆）



typedef struct



{



    Car Stop[MAX_STOP];   // 用于停放车辆的栈



    int top;                  // 标记栈顶位置



    Car Stop[MAX_STOP];   



    int top;                  



}Stopping;







// 等候队列



typedef struct



{



    int count;                // 用来指示队中的数据个数



    Car Pave[MAX_PAVE];   // 等候停车的队列



    int front, rear;          // 标记队头和队尾位置



    int count;          



    Car Pave[MAX_PAVE]; 



    int front, rear;          



}Pavement;







// 让路栈



typedef struct



{



    Car Help[MAX_STOP];   // 用于让路的队列



    int top;                  // 标记站定位置



    Car Help[MAX_STOP];   



    int top;                  



}Buffer;







Stopping s;

@@ -49,11 +40,11 @@ Buffer   b;



Car      c;



char     C[10];







void stop_to_pave();       // 车停入便道



void car_come    ();       // 车停入停车位



void stop_to_buff();       // 车进入让路栈



void car_leave   ();       // 车离开



void welcome     ();       // 主界面函数



void Display     ();       // 显示车辆信息



void stop_to_pave();       



void car_come    ();       



void stop_to_buff();       



void car_leave   ();       



void welcome     ();



void Display     ();       







#endif //__PLOT_H__



#endif
