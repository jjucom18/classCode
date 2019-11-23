
#include <stdio.h>
#include <stdlib.h>
void out_car(car *out,int carroom);
void out_car(car *outcar,int carroom )
{
	int A1,A2,B1,B2;
	printf("请输入离开的时间\n");
	scanf("%d:%d",&(outcar->out.hours),&(outcar->out.minte));
	printf("离开的车牌号为：\n");
	scanf("%s",&(outcar->number));
	printf("其到达的时间为：\n",outcar->in.hours,outcar->in.minte);
	A1 = outcar->in.hours;
	A2 = outcar->in.minte;
	B1 = outcar->out.hours;
	B2 = outcar->out.minte;
	printf("应交费用：%2.1f\n",(B1 - A1) * price + ((B2 - A2) / 60) * price);//price停车单价未定义！
	
}
