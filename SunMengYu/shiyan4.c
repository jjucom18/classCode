#include <stdio.h>
#include <malloc.h>
typedef struct
{
	int no[3];
	int time[3];
	int top;
}sq1;
void init sq1(sq1 * &L)
{
	L=(sq1 *)malloc(sizeof(sq1));
	L->top=-1;
}
bool push sq1(sq1 * &L,int &e1,int &e2)
{
	if(L->top == 2)return 0;
	L->top++;
	L->no[L->top]=e1;
	L->top[L->top]=e2;
	return 1;
}
bool popsq1(sq1 * &L,int &e1,int &e2)
{
	int q=1;
	int i;
	if(L->top=-1)return 0;
       for(i=0,i<=L->top;i++)
       {
if(e1 == L->no[i])
{
e2=L->time[i];
for(;i<L->top;i++)
{
	L->no[i]=L->no[i+1];
	L->time[i]=L->time[i+1];
}
L->top--;
q=0;
break;
    }
}
if(q)
{
	printf("没有此车牌,请重新输入!\n");
	e1=-1;
}
return 1;
print sq1(sq1 * &L)

	if(L->top ==-1)
	printf("NO CAR!\n");
	printf("此时有%d辆车\n",L->top+1);
	printf("车牌分别是:");
	for(int i=0)

