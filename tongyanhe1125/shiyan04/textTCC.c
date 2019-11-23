#include <stdio.h>
#include <malloc.h>
#define N 10              
#define M 10             
#define Price 2        
typedef struct
{
    int CarNo[N];     
    int CarTime[N];      
    int top;            
} SqStack;             

typedef struct
{
    int CarNo[M];         
    int front,rear;      
} SqQueue;              

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
{
    return(s->top==N-1);
}
int Push(SqStack *s,int e1,int e2)
{
    if (s->top==N-1)
        return 0;
    s->top++;
    s->CarNo[s->top]=e1;
    s->CarTime[s->top]=e2;
    return 1;
}
int Pop(SqStack *s,int e1,int e2)
{
    if (s->top==-1)
        return 0;
    e1=s->CarNo[s->top];
    e2=s->CarTime[s->top];
    s->top--;
    return 1;
}
void DispStack(SqStack *s)
{
    int i;
    for (i=s->top; i>=0; i--)
        printf("%d ",s->CarNo[i]);
    printf("\n");
}

void InitQueue(SqQueue *q)
{
    q=(SqQueue *)malloc (sizeof(SqQueue));
    q->front=q->rear=0;
}
int QueueEmpty(SqQueue *q)
{
    return(q->front==q->rear);
}
int QueueFull(SqQueue *q)       
{
    return ((q->rear+1)%M==q->front);
}
int enQueue(SqQueue *q,int e)    
{
    if ((q->rear+1)%M==q->front)  
        return 0;
    q->rear=(q->rear+1)%M;
    q->CarNo[q->rear]=e;
    return 1;
}
int deQueue(SqQueue *q,int e)
{
    if (q->front==q->rear)    
        return 0;
    q->front=(q->front+1)%M;
    e=q->CarNo[q->front];
    return 1;
}
void DispQueue(SqQueue *q)     
{
    int i;
    i=(q->front+1)%M;
    printf("%d ",q->CarNo[i]);
    while ((q->rear-i+M)%M>0)
    {
        i=(i+1)%M;
        printf("%d ",q->CarNo[i]);
    }
    printf("\n");
}

int main()
{
    int comm;
    int no,e1,time,e2;
    int i,j,t;
    SqStack *St,*St1; 
    SqQueue *Qu;  
    InitStack(St);
    InitStack(St1);
    InitQueue(Qu);
    do
    {
        printf("输入指令(1:到达 2:离开 3:显示停车场 4:显示候车场 0:退出):");
        scanf("%d",&comm);
        switch(comm)
        {
        case 1:     
            printf("输入车号和时间(设车号和时间均为整数): ");
            scanf("%d%d",&no,&time);
            if (!StackFull(St))     
            {
                Push(St,no,time);
                printf("  >>停车场位置:%d\n",St->top+1);
            }
            else                 
            {
                if (!QueueFull(Qu))  
                {
                    enQueue(Qu,no);
                    printf("  >>候车场位置:%d\n",Qu->rear);
                }
                else
                    printf("  >>候车场已满,不能停车\n");
            }
            break;
        case 2:     
            printf("输入车号和时间(设车号和时间均为整数): ");
            scanf("%d%d",&no,&time);
            for (i=0; i<=St->top && St->CarNo[i]!=no; i++);
            if (i>St->top)
                printf("  >>未找到该编号的汽车\n");
            else
            {
                t = St->top - i;  
                for (j=0; j<t; j++) 
                {
                    Pop(St,e1,e2);
                    Push(St1,e1,e2);       
                }
                Pop(St,e1,e2);            
                printf("  >>%d汽车停车费用:%d\n",no,(time-e2)*Price);
                while (!StackEmpty(St1))   
                {
                    Pop(St1,e1,e2);
                    Push(St,e1,e2);
                }
                if (!QueueEmpty(Qu))        
                {
                    deQueue(Qu,e1);
                    Push(St,e1,time);       
                }
            }
            break;
        case 3:     
            if (!StackEmpty(St))
            {
                printf("  >>停车场中的车辆:"); 
                DispStack(St);
            }
            else
                printf("  >>停车场中无车辆\n");
            break;
        case 4:    
            if (!QueueEmpty(Qu))
            {
                printf("  >>候车场中的车辆:"); 
                DispQueue(Qu);
            }
            else
                printf("  >>候车场中无车辆\n");
            break;
        case 0:     
            if (!StackEmpty(St))
            {
                printf("  >>停车场中的车辆:"); 
                DispStack(St);
            }
            if (!QueueEmpty(Qu))
            {
                printf("  >>候车场中的车辆:"); 
                DispQueue(Qu);
            }
            break;
        default:    
            printf("  >>输入的命令错误\n");
            break;
        }
    }
    while(comm!=0);
    return 0;
}

