#include"carpark.h"
#include"carpark.c"

void Display()
{
    int i = s.top;
    if (-1 == i)
    {
        printf ("停车场为空\n");
    }
    time_t t1;
    long int t = time(&t1);             // 标记显示时的时间
    printf ("\t车牌号\t\t\t停放时间\t\t当前所需支付金额\n");
    while (i != -1)
    {
        printf ("\t%s\t\t%d秒\t\t\t%d元\n", s.Stop[i].plate, t - s.Stop[i].timeIn, Price * (t - s.Stop[i].timeIn) / 10);
        i--;
    }
}

void welcome()
{
    printf ("\t*******************目前停车场状况***********************\n");
    printf ("\t停车场共有%d个车位,当前停车场共有%d辆车,等候区共有%d辆车\n", MAX_STOP, s.top+1, (p.rear + MAX_PAVE - p.front)
                                                                       % MAX_PAVE);
    printf ("\t********************************************************\n");
    printf ("\t---------------Welcome to our Car Parking---------------\n");
    printf ("\t*                     1.Parking                        *\n");
    printf ("\t*                     2.leaving                        *\n");
    printf ("\t*                     3.situation                      *\n");
    printf ("\t*                     4.exit                           *\n");
    printf ("\t--------------------------------------------------------\n");
}
