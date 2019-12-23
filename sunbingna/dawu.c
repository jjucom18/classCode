#include<stdio.h>
#include<math.h>
//未修正
int main()
{
    float time;
    float s,v;
    float y,y1;
    float re;
    printf("请下落长度L与时间time:");
    scanf("%f%f",&s,&time);
    v = s/time;
    printf("速度为:%f\n",v);
    y = 0.00446235/v;
    printf("未修正值为  :%f\n",y);
    re = (v*1.1096)/y;
    printf("雷诺数为    :%f\n",re);
    if(re>0.1&&re<1)
    {
        y1 = y-0.20805*v;
        printf("修正后值为:%f\n",y1);
    }

}

