#include “Plot.h”


Int main()
{
// 初始化
s.top   = -1;
b.top   =  0;
p.rear  =  0;
p.count =  0;
p.front =  0;


while(1)
{
        //system(“clear”);
        Welcome();
        Int I, cho;
        Scanf (“%d”, &i);

        If (1 == i) car_come();
        If (2 == i) car_leave();
        If (3 == i) Display();
        If (4 == i) break;

        Printf (“返回请输入1\n”);
        Scanf (“%d”, &cho);
        If (1 == cho)
        {
            Continue;
        }
        Else
        {
            Printf (“您的输入有误，请重新输入\n”);
            Scanf (“%d”, &cho);
            Continue;
        }
}
Return 0;
}

