#include"parking.h"

void InitStack(SqStack &s)
{
s=(SqStack )malloc(sizeof(SqStack));
s->top=-1;
}
int StackEmpty(SqStack s)
{
return(s->top==-1);
}
int StackFull(SqStack s)
{
return(s->top==N-1);
}
int Push(SqStack &s,int e1,int e2)
{
if (s->top==N-1)
return 0;
s->top++;
s->CarNo[s->top]=e1;
s->CarTime[s->top]=e2;
return 1;
}
int Pop(SqStack &s,int &e1,int &e2)
{
if (s->top==-1)
return 0;
e1=s->CarNo[s->top];
e2=s->CarTime[s->top];
s->top--;
return 1;
}
void DispStack(SqStack s)
{
int i;
for (i=s->top; i>=0; i--)
printf("%d ",s->CarNo[i]);
printf("\n");
}
