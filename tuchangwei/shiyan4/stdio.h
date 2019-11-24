//定义结构体
#include <stdio.h>
#include <stdlib.h>

#define F 0
#define T 1
#define MAX 3

typedef struct Node   //数据
{
    int number;
    int time;
}Node;

typedef struct QueueNode   //队列结点
{
    struct Node infom;
    struct QueueNode * next;
}*QueueNode;

typedef struct LinkQueue    //链队列
{
    struct QueueNode * front;
    struct QueueNode * rear;
}LinkQueue;

typedef struct stack         //栈结点
{
    struct Node data;
    struct stack *next;
}*StackNode;

typedef struct LinkStack     //链栈
{
    StackNode top;
    int count;
}LinkStack;
void menu(LinkQueue *wait,LinkQueue *park,LinkStack *giveway,int num,int t);
int init(LinkQueue *wait,LinkQueue *park,LinkStack *giveway);//初始化
int linklength(LinkQueue q);//查看长度
int enqueue(LinkQueue *q,int num,int t);//入队列
int dequeue(LinkQueue *q,int *num,int *t);//出队列
void park1(LinkQueue *wait,LinkQueue *park);//停车函数
int push(LinkStack *s,int num,int t);//入栈
int pop(LinkStack *s,int *num,int *t);//出栈
void leave2(LinkQueue *wait,LinkQueue *park,LinkStack *giveway,int num,int t);//离开函数
void view3(LinkQueue wait,LinkQueue park);

int main()
{
    LinkQueue wait;
    LinkQueue park;
    LinkStack giveway;
    int num = 0;
    int t = 0;
    init(&wait,&park,&giveway);
    menu(&wait,&park,&giveway,num,t);
    return 0;
}

int init(LinkQueue *wait,LinkQueue *park,LinkStack *giveway)
{
    QueueNode newnode1 = (QueueNode)malloc(sizeof(struct QueueNode));
    if(NULL == newnode1)
    {
        return F;
    }
    newnode1->next = NULL;
    wait->front = newnode1;
    wait->rear = newnode1;

    QueueNode newnode2 = (QueueNode)malloc(sizeof(struct QueueNode));
    if(NULL == newnode2)
    {
        return F;
    }
    newnode2->next = NULL;
    park->front = newnode2;
    park->rear = newnode2;

    giveway->top = NULL;
    giveway->count = 0;
}

void menu(LinkQueue *wait,LinkQueue *park,LinkStack *giveway,int num,int t)
{
    printf("**********Welcome to our Car Parking !**********\n");
    printf("**********  Please choose function    **********\n");
    printf("**********         1 : park.          **********\n");
    printf("**********         2 : leave.         **********\n");
    printf("**********         3 : view.          **********\n");
    printf("**********         4 : exit.          **********\n");
    int option;
    scanf("%d",&option);
    switch(option)
    {
        case 1:{
            park1(wait,park);
            printf("停车完成！\n");
            menu(wait,park,giveway,num,t);
            break;
        }
        case 2:{
            leave2(wait,park,giveway,num,t);
            menu(wait,park,giveway,num,t);
            break;
        }
        case 3:{
            view3(*wait,*park);
            menu(wait,park,giveway,num,t);
            break;
        }
        case 4:{
            printf("**********     欢迎再次使用，谢谢！   **********\n");
            break;
        }
        default:{
            printf("**********      请输入正确的指令！    **********\n");
            menu(wait,park,giveway,num,t);
            break;
        }
    }

}

int linklength(LinkQueue q)
{
    int i = 0;
    while(q.front != q.rear)
    {
        i++;
        q.front = q.front->next;
    }
    return i;
}

int enqueue(LinkQueue *q,int num,int t)
{
    QueueNode newnode = (QueueNode)malloc(sizeof(struct QueueNode));
    if(NULL == newnode)
    {
        return F;
    }
    newnode->infom.number = num;
    newnode->infom.time = t;
    newnode->next = NULL;
    q->rear->next = newnode;
    q->rear = newnode;
    return T;
}

int dequeue(LinkQueue *q,int *num,int *t)
{
    if(q->front == q->rear)
    {
        printf("the queue is empty!\n");
        return F;
    }
    *num = q->front->next->infom.number;
    *t = q->front->next->infom.time;
    QueueNode temp = q->front->next;
    q->front->next = temp->next;
    if(temp->next == NULL)
    {
        q->rear = q->front;
    }
    free(temp);
    return T;
}

void park1(LinkQueue *wait,LinkQueue *park)
{
    printf("请输入车号和停车时间\n");
    int num,t;
    scanf("%d,%d",&num,&t);
    if(linklength(*park) >= MAX)
    {
        printf("停车场已满，进入等待区！\n");
        enqueue(wait,num,t);
    }
    else
    {
        enqueue(park,num,t);
    }
}

int push(LinkStack *s,int num,int t)
{
    StackNode newnode = (StackNode)malloc(sizeof(struct stack));
    if(NULL == newnode)
    {
        return F;
    }
    newnode->data.number = num;
    newnode->data.time = t;
    newnode->next = s->top;
    s->top = newnode;
    s->count++;
    return T;
}

int pop(LinkStack *s,int *num,int *t)
{
    if(0 == s->count)
    {
        printf("the stack is empty !\n");
        return F;
    }
    *num = s->top->data.number;
    *t = s->top->data.time;
    StackNode temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->count--;
    return T;
}

void leave2(LinkQueue *wait,LinkQueue *park,LinkStack *giveway,int num,int t)
{
    printf("请输入要离开车的车号\n");
    int leavenumber;
    scanf("%d",&leavenumber);
    int i = 0;
    QueueNode head = park->front;
    while(head != park->rear)
    {
        if(head->next->infom.number != leavenumber)
        {
            head = head->next;
            i++;
        }
        else
            break;
    }
    int j = 0;
    if(i <= MAX-1)
    {
        while(j != i)
        {
            dequeue(park,&num,&t);
            push(giveway,num,t);
            j++;
        }
        dequeue(park,&num,&t);
    }
    else
    {
        printf("查无此车！\n");
    }
    while(giveway->top != NULL)
    {
        pop(giveway,&num,&t);
        enqueue(park,num,t);
    }
    if(linklength(*wait) != 0)
    {
        dequeue(wait,&num,&t);
        enqueue(park,num,t);
    }
}

void view3(LinkQueue wait,LinkQueue park)
{
    printf("********************    目前停车场状况    ********************\n");
    printf("停车场共%d个车位，当前停车场共有%d量车，等待区共有%d量车\n",
        MAX,linklength(park),linklength(wait));
    printf("**************************************************************\n");
    printf("车    号：");
    QueueNode head1 = park.front;
    QueueNode head2 = park.front;
    while(head1 != park.rear)
    {
        printf("%d  ",head1->next->infom.number);
        head1 = head1->next;
    }
    printf("\n");
    printf("停车时间：");
    while(head2 != park.rear)
    {
        printf("%d ",head2->next->infom.time);
        head2 = head2->next;
    }
    printf("\n");
}
