#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct stackstruct                     /*栈的结构体*/
{
	int id;
	int time;
	struct stackstruct *pre;
	struct stackstruct *next;
};
 
struct queuestruct
{
	int id;
	struct queuestruct *next;
};
 
struct stackstruct *stackhead1, *stackend1;
struct stackstruct *stackhead2, *stackend2;
struct queuestruct *queuehead, *queueend;
int stack1count, stack2count;                         /*栈中元素总数*/
int queuecount;                         /*队列中元素总数*/
 
void push(int flag, struct stackstruct *p)
{
	struct stackstruct *stack;
	if (flag == 0)                  /*栈1进栈操作*/
	{
		if (stack1count == 0)
		{
			stackhead1 = (struct stackstruct *)malloc(sizeof(struct stackstruct));
			stackhead1->id = p->id;
			stackhead1->time = p->time;
			stackhead1->next = NULL;
			stackhead1->pre = NULL;
			stackend1 = stackhead1;
		}
		else
		{
			stack = (struct stackstruct *)malloc(sizeof(struct stackstruct));
			stack->id = p->id;
			stack->time = p->time;
			stackend1->next = stack;
			stack->pre = stackend1;
			stack->next = NULL;
			stackend1 = stack;
		}
		stack1count++;
	}
	else if (flag == 1)               /*栈2进栈操作*/
	{
		if (stack2count == 0)
		{
			stackhead2 = (struct stackstruct *)malloc(sizeof(struct stackstruct));
			stackhead2->id = p->id;
			stackhead2->time = p->time;
			stackhead2->next = NULL;
			stackhead2->pre = NULL;
			stackend2 = stackhead2;
		}
		else
		{
			stack = (struct stackstruct *)malloc(sizeof(struct stackstruct));
			stack->id = p->id;
			stack->time = p->time;
			stackend2->next = stack;
			stack->pre = stackend2;
			stack->next = NULL;
			stackend2 = stack;
		}
		stack2count++;
	}
}
 
struct stackstruct *pop(int id, int time)
{
	struct stackstruct *stack;
	stack = (struct stackstruct *)malloc(sizeof(struct stackstruct));
 
	if (stackend1->id != id)
	{
		stack->id = stackend1->id;
		stack->time = stackend1->time;
		stack->pre = stackend1->pre;
		free(stackend1);
		stackend1 = stack->pre;
		stackend1->next = NULL;
		stack1count--;
	}
	else
	{
		stack->id = stackend1->id;
		stack->time = stackend1->time;
		stack->pre = stackend1->pre;
		printf("%d号汽车出停车场\n", id);
		printf("停车场停留时间: %d\n", time - stack->time);
		printf("应该缴纳的费用(单价: 5): %d\n", 5 * (time - stack->time));
		free(stackend1);
		if (--stack1count == 0)
			stackend1 = stackhead1 = NULL;
		else
		{
			stackend1 = stack->pre;
			stackend1->next = NULL;
		}
		stack = NULL;
	}
	return stack;
}
 
struct stackstruct *pop1()
{
	struct stackstruct *stack;
	stack = (struct stackstruct *)malloc(sizeof(struct stackstruct));
 
	stack->id = stackend2->id;
	stack->time = stackend2->time;
	stack->pre = stackend2->pre;
	free(stackend2);
	stackend2 = stack->pre;
	stack2count--;
 
	return stack;
}
 
void Enqueue(struct stackstruct *p)
{
	struct queuestruct *queue;
	if (queuecount == 0)
	{
		queuehead = (struct queuestruct *)malloc(sizeof(struct queuestruct));
		queuehead->id = p->id;
		queuehead->next = NULL;
		queueend = queuehead;
	}
	else
	{
		queue = (struct queuestruct *)malloc(sizeof(struct queuestruct));
		queue->id = p->id;
		queue->next = NULL;
		queueend->next = queue;
		queueend = queue;
	}
	queuecount++;
}
 
struct stackstruct *Dequeue(int time)
{
	struct stackstruct *stack;
	stack = (struct stackstruct *)malloc(sizeof(struct stackstruct));
 
	stack->id = queuehead->id;
	stack->time = time;
	if (--queuecount == 0)
	{
		queuehead = NULL;
		queueend = NULL;
	}
	else
		queuehead = queuehead->next;
	return stack;
}
int main()
{
	int n;
	char s;
	struct stackstruct *p;
 
	printf("输入狭长通道可停放汽车数量: ");
	scanf("%d", &n);
	getchar();
	stack1count = stack2count = queuecount = 0;
	p = (struct stackstruct *)malloc(sizeof(struct stackstruct));
 
	while (scanf("(%c,%d,%d)", &s, &p->id, &p->time) != EOF)
	{
		getchar();
		if (s == 'E')
			break;
		else if (s == 'A')                /*汽车到达*/
		{
			if (stack1count < n)                 /*栈未满，进栈操作*/
			{
				push(0, p);
				printf("%d号汽车进入停车场\n", stackend1->id);
				printf("进入停车场时间: %d\n", stackend1->time);
				printf("停车位置: %d\n", stack1count);
			}
			else                                /*栈满，进队列操作*/
			{
				Enqueue(p);
				printf("%d号汽车进入便道\n", p->id);
				printf("进入便道时间: %d\n", p->time);
				printf("便道位置: %d\n", queuecount);
			}
		}
		else if (s == 'D')                /*汽车离去*/
		{
			struct stackstruct *temp;
			while ((temp = pop(p->id, p->time)) != NULL)
			{
				push(1, temp);                  
			}
			while (stack2count != 0)
			{
				push(0, pop1());
			}
			if (queuecount != 0)
			{
				push(0, Dequeue(p->time));
				printf("%d号汽车进入停车场\n", stackend1->id);
				printf("进入时间: %d\n", stackend1->time);
				printf("停车位置: %d\n", stack1count);
			}
		}
	}
	return 0;
}
