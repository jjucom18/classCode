#include"park.h"
void InitStack(SqStack *s)
{
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
int StackEmpty(SqStack *s)
{
	return(s->top==-1);
}
int StackFull(SqStack *s)
{int top;
	return(s->top==N-1);
}
int Push(SqStack *s,int i,int j)
{int top;
	if(s->top==-1)
		return 0;
	s->top++;
	s->num[s->top]=i;
	s->time[s->top]=j;
	s->top--;
	return 1;
}
int Pop(SqStack *s,int i,int j)
{
	if(s->top==-1)
		return 0;
	s->num[s->top]=i;
	s->time[s->top]=j;
	s->top--;
	return 1;
}
void DispStack(SqStack *s)
{
	int i;
	for(i=s->top;i>=0;i--)
		printf("%d",s->num[i]);
	printf("\n");
}

