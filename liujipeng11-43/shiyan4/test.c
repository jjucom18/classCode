#include "PLot.c"


int main()
{
    // 初始化
    s.top   = -1;
    b.top   =  0;
    p.rear  =  0;
    p.count =  0;
    p.front =  0;


    while(1)
    {
        //system("clear");
        welcome();
        int i, cho;
        scanf ("%d", &i);

        if (1 == i) car_come();
        if (2 == i) car_leave();
        if (3 == i) Display();
        if (4 == i) break;

        printf ("返回请输入1\n");
        scanf ("%d", &cho);
        if (1 == cho)
        {
            continue;
        }
        else
        {
            printf ("您的输入有误，请重新输入\n");
            scanf ("%d", &cho);
            continue;
        }
    }
    return 0;
}
