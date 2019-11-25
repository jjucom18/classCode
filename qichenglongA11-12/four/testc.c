#include<stdio.h>
#include<stdlib.h>
#include "abc.c"
 
 
 int main()
 {
     SeqStackCar Enter,Temp;
     LinkQueueCar Wait;
      int ch;
      system("color 1A");
      InitStack(&Enter);
       InitStack(&Temp);
        InitQueue(&Wait);
        while(1)
{
 
    printf("\n ___________________________________________________________________  ");
    printf("\n                     __________________");
    printf("\n \t            |[_][_][_][_][_][_]|        ");
    printf("\n\t            |o _         _  _  |       ");
    printf("\n\t             `(_)-------(_)(_)-    ");
    printf("\n ___________________________________________________________________  ");
 
    printf("\n    §※§※§※§※§※§ 欢迎使用停车场系统.§※§※§※§ ※§※§\t\n");
    printf("\n\t  ※◎※◎※◎※◎  1. 车辆到达登记.※◎※◎※◎※◎\t\n");
    printf("\n\t  ※◎※◎※◎※◎  2. 车辆离开登记.※◎※◎※◎※◎\t\n");
    printf("\n\t  ※◎※◎※◎※◎  3. 车辆列表显示.※◎※◎※◎※◎\t\n");
    printf("\n\t  ※◎※◎※◎※◎  4. 退出管理系统.※◎※◎※◎※◎\t\n");
    printf(" ___________________________________________________________________  ");
     while(1)
{
    printf(" \n\n请选择: ");
     scanf("%d",&ch);
     if(ch>=1&&ch<=4)break;
       else printf("\n 输入有误，请重新选择： 1~4: ");
    }
    switch(ch)
    {
    case 1:Arrival(&Enter,&Wait);
     break;
     case 2:Leave(&Enter,&Temp,&Wait);
     break;
     case 3:List(Enter,Wait);break;
     case 4:exit(0);
default: break;
 }
 }
}
