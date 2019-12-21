#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdbool.h>

typedef struct QNode
{ 
    char account[5];
    char password[5];
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{ 
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

/* 1、初始化链式队列 */
void InitQueue(LinkQueue *Q)
{ 
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
    if (!(Q->front)) exit(0);
    Q->front->next=NULL; 
}

/* //3、清空链式队列 
void ClearQueue(LinkQueue *Q)
{ QueuePtr p;
p=Q->front->next;
while (p)
{ Q->front->next=p->next;
free(p); }
Q->rear=Q->front;
} */

/* 4、判断空队列 */
int QueueEmpty(LinkQueue Q)
{ if (Q.front==Q.rear)
return 1;
else
return 0; }

/* 5、求链式队列长度 */
/* int QueueLength(LinkQueue Q)
{ QueuePtr p; int n=0;
p=Q.front;
while (p!=Q.rear)
{ n++; p=p->next; }
return n;
} */

/* 6、取队头元素 */
/* int GetHead(LinkQueue Q)
{ if (Q.front!=Q.rear)
return Q.front->next->data;
} */

/* 7、入队列 */
void EnQueue(LinkQueue *Q)
{ 
    char account[5];
    char password[5];
    char repassword[5];
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));
    if (!p) exit(0);
    printf("\n请输入帐号:");
    scanf("%s",account);
    printf("\n请输入密码:");
    scanf("%s",password);
    printf("\n请确认密码:");
    scanf("%s",repassword);
    if(strcmp(password,repassword) != 0)
    {
        printf("\n密码有误!\n");
        sleep(2);
        return;
    }
	strcpy(p->account,account);
    strcpy(p->password,password);
    p->next=NULL;
    Q->rear->next=p;
    Q->rear=p; 
    printf("\n注册成功!\n");
    sleep(2);
}

/* 8、出队列 */
/* void DeQueue(LinkQueue *Q, ElemType *e)
{ QueuePtr p;
if (Q->front!=Q->rear)
{ p=Q->front->next;
*e=p->data;
Q->front->next=p->next;
if (Q->rear==p) Q->rear=Q->front;
free(p); }
} */

/* 9、遍历链式队列并输出元素 */
bool QueueTraverse(LinkQueue Q)
{ 
    QueuePtr p;
    char account[5],password[5];
    printf("\n请输入帐号:");
    scanf("%s",account);
    printf("\n请输入密码:");
    scanf("%s",password);
    if (Q.front==Q.rear)
    {
        printf("\n查无此人!请先注册!\n");
        sleep(2);
        return false;
    }
       
    p=Q.front->next;
    while (p)
    { 
        if(strcmp(p->account,account) == 0&&strcmp(p->password,password) ==0)
        {
            printf("\n欢迎登录!\n");
            sleep(2);
            return true;
        }
		p = p -> next;
        if(p == NULL)
        {
            printf("查无此人!请重新输入!\n");
            sleep(2);
            return false;
        }
    }
}

void QueueChoice()
{
    int n;
    while(1)
    {  
        queuemenu();
        scanf("%d",&n);      
        switch(n)
        {
            case 1:ReadInf();break;
            case 2:PrintfStudent();break;
            case 3:SearchChoice();break;
            case 4:exit(0);break;
            default: break;
        }
    } 
}

void queuechoice()
{
    LinkQueue Q;
    InitQueue(&Q);
    int l;
    while(1)
    {
        choicemenu();
        scanf("%d",&l);
        switch (l)
        {
            case 1:
            {
                if(QueueTraverse(Q))
                QueueChoice();
            }
            break;
        case 2:
            EnQueue(&Q);break;
        case 3:
            exit(0);
            break;
        default:
            break;
        }
    }
}