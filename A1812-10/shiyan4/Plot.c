#include"Plot.h"

void stop_to_pave()                     
{
    if (p.count > 0 && (p.front == (p.rear + 1) % MAX_PAVE))
    {
        printf ("便道已满，请下次再来\n");
    }
    else
    {
        strcpy(p.Pave[p.rear].plate, C);
        p.rear = (p.rear + 1) % MAX_PAVE;
        p.count++;                      
        printf ("牌照为%s的汽车停入便道上的%d的位置\n", C, p.rear);
    }
}

void car_come()                             
{
    printf ("请输入即将停车的车牌号:");     
    scanf("%s",&C);
    if (s.top >= MAX_STOP - 1)              
    {
        stop_to_pave();                     
    }
    else
    {
        s.top++;                            
        time_t t1;
        long int t = time(&t1);             
        char* t2;
        t2 = ctime (&t1);                   
        s.Stop[s.top].timeIn = t;

        strcpy(s.Stop[s.top].plate, C);     
        printf ("牌照为%s的汽车停入停车位的%d车位, 当前时间:%s\n", C, s.top + 1, t2);
    }

    return ;
}

void stop_to_buff()                         
{
    while (s.top >= 0)
    {
        if (0 == strcmp(s.Stop[s.top].plate, C))
        {
            break;
        }
        strcpy(b.Help[b.top++].plate, s.Stop[s.top].plate);
        printf ("牌照为%s的汽车暂时退出停车场\n", s.Stop[s.top--].plate);
    }
    if (s.top < 0)
    {
        printf ("停车位上无此车消息\n");
    }
    else
    {
        printf ("牌照为%s的汽车从停车场开走\n", s.Stop[s.top].plate);
        time_t t1;
        long int t = time (&t1);
        c.timeOut = t;                      
        char* t2;
        t2 = ctime (&t1);               
        printf ("离开时间%s\n需付%d元\n",t2,Price * (c.timeOut - s.Stop[s.top].timeIn));
        s.top--;
    }
    while (b.top > 0)
    {
        strcpy(s.Stop[++s.top].plate, b.Help[--b.top].plate);
        printf ("牌照为%s的汽车停回停车位%d车位\n", b.Help[b.top].plate, s.top);
    }
    while (s.top < MAX_STOP-1)
    {
        if (0 == p.count)           
        {
            break;
        }   
        else
        {
            strcpy(s.Stop[++s.top].plate, p.Pave[p.front].plate);
            printf ("牌照为%s的汽车从便道中进入停车位的%d车位\n", p.Pave[p.front].plate, s.top);
            p.front = (p.front + 1) % MAX_PAVE;
            p.count--;
        }
    }
}

void car_leave()                        
{
    printf ("请输入即将离开的车牌号:\n");
    scanf ("%s", &C);
    if (s.top < 0)                  
    {
        printf ("车位已空，无车辆信息！\n");
    }
    else
    {
        stop_to_buff();
    }
}

void Display()
{
    int i = s.top;
    if (-1 == i)
    {
        printf ("停车场为空\n");
    }
    time_t t1;
    long int t = time(&t1);             
    printf ("\t车牌号\t\t\t停放时间\t\t当前所需支付金额\n");
    while (i != -1)
    {
        printf("\t%s\t\t%d秒\t\t\t%d元\n",s.Stop[i].plate,t-s.Stop[i].timeIn,Price*(t-s.Stop[i].timeIn)/10);
        i--;
    }
}

void welcome()
{
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
