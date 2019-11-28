#include <stdio.h>
#include <stdlib.h>
void out_car(car *out,int carroom);
void out_car(car *outcar,int carroom )
{
        int X1,X2,Y1,Y2;
        printf("请输入离开的时间\n");
        scanf("%d:%d",&(outcar->out.hours),&(outcar->out.minte));
        printf("离开的车牌号为：\n");
        scanf("%s",&(outcar->number));
        printf("其到达的时间为：\n",outcar->in.hours,outcar->in.minte);
        X1 = outcar->in.hours;
        X2 = outcar->in.minte;
        Y1 = outcar->out.hours;
        Y2 = outcar->out.minte;
        printf("应交费用：%2.1f\n",(Y1 - X1) * price + ((Y2 - X2) / 60) * price);//price停车单价未定义！

}
~       
