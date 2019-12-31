#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

// 定义事件类型，元素类型
typedef struct Event 
{
	int OccurTime;	// 事件发生时刻 
	// 事件类型，Qu表示到达事件,0至Qu-1表示Qu个窗口的离开事件
	int NType; 
} Event, ElemType;	// 事件类型，有序链表LinkList的数据元素类型 

// 线性链表结点类型 
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} LNode, *Link, *Position;

// 链表类型 
typedef struct _LinkList
{
	Link head, tail;	// 分别指向线性链表中的头结点和最后一个结点 
	int len;			// 指示线性链表中数据元素的个数 
} LinkList;

typedef LinkList EventList;	// 事件链表类型，定义为有序链表 

// 定义QElemType(队列的数据元素类型) 
typedef struct
{
	int ArrivalTime;	// 到达时刻 
	int Duration;		// 办理事务所需时间 
} QElemType;		
 
// 单链队列--队列的链式存储结构 
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front,rear;	// 队头、队尾指针 
}LinkQueue;

#define Qu 4	// 客户队列数 
#define Khjg 5	// 两相邻到达的客户的时间间隔最大值 
#define Blsj 20 // 每个客户办理业务的时间最大值 

// 程序中用到的主要变量(全局)  
EventList ev;			// 事件表 
Event en;				// 事件 
Event et;				// 临时变量 
LinkQueue q[Qu];		// Qu个客户队列 
QElemType customer;		// 客户记录
int CloseTime;			// 银行营业时间(单位是分) 
int TotalTime = 0;		// 累计客户逗留时间初始为0
int	CustomerNum = 0;	// 客户数(初值为0)


// 释放p所指结点 
void FreeNode(Link *p)
{ 
	free(*p);
	*p = NULL;
}

// 构造一个空的线性链表。
int InitList(LinkList *L)
{ 
   Link p;
   p = (Link)malloc(sizeof(LNode));		// 生成头结点 
   if( p )
   {
	   p->next = NULL;
	   (*L).head = (*L).tail = p;
	   (*L).len = 0;
	   return 1;
   }
   else
	   return 0;
}

// 将线性链表L重置为空表，并释放原链表的结点空间 
int ClearList(LinkList *L)
{

	Link p,q;
	if((*L).head != (*L).tail)// 不是空表 
	{
		p = q = (*L).head->next;
		(*L).head->next = NULL;
		while(p != (*L).tail)
		{ 
			p = q->next;
			free(q);
			q = p;
		}
		free(q);
		(*L).tail = (*L).head;
		(*L).len = 0;
	}
	return 1;
}
 

// 销毁线性链表L，L不再存在 
int DestroyList(LinkList *L)
{
	ClearList(L); // 清空链表 
	FreeNode(&(*L).head);
	(*L).tail = NULL;
	(*L).len = 0;
	
	return 1;
}

// 	h指向L的一个结点，把h当做头结点，删除链表中的第一个结点并以q返回。
//	若链表为空(h指向尾结点)，q=NULL，返回0。 
int DelFirst(LinkList *L,Link h,Link *q) // 形参增加L,因为需修改L 
{
	*q = h->next;
	if( *q )	// 链表非空 
	{
		h->next = (*q)->next;
		if( !h->next )		// 删除尾结点 
			(*L).tail = h;	// 修改尾指针 
		(*L).len--;
		return 1;
	}
	else
		return 0; // 链表空 
}

// 已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值 
ElemType GetCurElem(Link p)
{
	return p->data;
}

// 	若线性链表L为空表，则返回1，否则返回0。
int ListEmpty(LinkList L)
{
	if(L.len)
		return 0;
	else
		return 1;
}

// 返回线性链表L中头结点的位置 
Position GetHead(LinkList L)
{
	return L.head;
}

/* 
// 依次对L的每个数据元素调用函数visit() 
int ListTraverse(LinkList L,void(*visit)(ElemType))
{
	Link p = L.head->next;
	int j;
	for(j = 1; j <= L.len; j++)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return 1;
}
*/
// 已知L为有序线性链表，将元素e按非降序插入在L中。（用于一元多项式）
int OrderInsert(LinkList *L,ElemType e,int (*comp)(ElemType,ElemType))
{
	Link o,p,q;
	q = (*L).head;
	p=q->next;
	while(p!=NULL&&comp(p->data,e)<0) // p不是表尾且元素值小于e 
	{
		q=p;
		p=p->next;
	}
	o=(Link)malloc(sizeof(LNode)); // 生成结点 
	o->data=e; // 赋值 
	q->next=o; // 插入 
	o->next=p;
	(*L).len++; // 表长加1 
	if(!p) // 插在表尾 
		(*L).tail=o; // 修改尾结点 
	return 1;
}


// 构造一个空队列Q 
int InitQueue(LinkQueue *Q)
{
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if( !(*Q).front )
		exit(0);
	(*Q).front->next = NULL;

	return 1;
}

// 	销毁队列Q(无论空否均可)。
int DestroyQueue(LinkQueue *Q)
{
	while((*Q).front)
	{
		(*Q).rear = (*Q).front->next;
		free((*Q).front);
		(*Q).front = (*Q).rear;
	}
	return 1;
}

// 若Q为空队列,则返回1,否则返回0 
int QueueEmpty(LinkQueue Q)
{
	if(Q.front == Q.rear)
		return 1;
	else
		return 0;
}

// 求队列的长度 
int QueueLength(LinkQueue Q)
{
	int i = 0;
	QueuePtr p;
	
	p = Q.front;
	while(Q.rear != p)
	{
		i++;
		p = p->next;
	}

	return i;
}

// 若队列不空,则用e返回Q的队头元素,并返回1,否则返回0 
int GetHead_Q(LinkQueue Q,QElemType *e)
{
	QueuePtr p;

	if(Q.front == Q.rear)
		return 0;
	p = Q.front->next;
	*e = p->data;
	return 1;
}

// 插入元素e为Q的新的队尾元素 
int EnQueue(LinkQueue *Q,QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if( !p ) // 存储分配失败 
	     exit(0);
	p->data = e;
	p->next = NULL;
	(*Q).rear->next = p;
	(*Q).rear = p;
	return 1;
}

// 若队列不空,删除Q的队头元素,用e返回其值,并返回1,否则返回0。 
int DeQueue(LinkQueue *Q,QElemType *e)
{
	QueuePtr p;
	if((*Q).front == (*Q).rear)
		return 0;
	p = (*Q).front->next;
	*e = p->data;
	(*Q).front->next = p->next;
	if((*Q).rear == p)
		(*Q).rear = (*Q).front;
	free(p);
	return 1;
}

//	从队头到队尾依次对队列Q中每个元素调用函数vi()。
int QueueTraverse(LinkQueue Q,void(*vi)(QElemType))
{
	QueuePtr p;
	
	p = Q.front->next;
	while( p )
	{
		vi(p->data);
		p = p->next;
	}
	printf("\n");
	return 1;
}


// 依事件a的发生时刻<、=或>事件b的发生时刻分别返回-1、0或1。 
int cmp(Event a,Event b)
{
	if(a.OccurTime == b.OccurTime)
		return 0;
	else
		return 
			(a.OccurTime - b.OccurTime) / abs(a.OccurTime - b.OccurTime);
}

// 	银行的开门的时候，进行的初始化操作。
void OpenForDay()
{
	int i;
	
	InitList( &ev );		// 初始化事件链表为空 
	for(i = 0; i < Qu; ++i)	// 置空各个窗口的队列 
		InitQueue( &q[i] );
	
	en.OccurTime =0;	// 设定第一个客户到达事件 
	en.NType = Qu;		// 到达 
	
	OrderInsert(&ev, en, cmp);	// 插入事件表 
}

void Random(int *d,int *i)
{
	*d = rand() % Blsj + 1;			// 1到Blsj之间的随机数 
	*i = rand() % Khjg + 1;			// 1到Khjg之间的随机数 
	printf("\n随机产生，处理时间%d， 间隔%d\n", *d, *i);
}

// 	返回最短队列的序号。
int Minimum(LinkQueue Q[]) 
{
	int l[Qu];
	int i, k;
	
	for(i = 0; i < Qu; i++)
		l[i] = QueueLength(Q[i]);
	k = 0;
	for(i = 1; i < Qu; i++)
		if(l[i] < l[0])
		{
			l[0] = l[i];
			k = i;
		}
	
	return k;
}

// 处理客户到达事件 
void CustomerArrived()
{
	QElemType f;
	int durtime, intertime, i;
	
	printf("当前时间：%d", en.OccurTime);
	++CustomerNum;
	Random(&durtime, &intertime);			// 生成两随机数 
	et.OccurTime = en.OccurTime + intertime;// 下一客户到达时刻 
	et.NType = Qu;							// 队列中只有一个客户到达事件 
	printf("当前客户(%d)的处理时间是%d，下一个客户到达的时间是：%d\n",
		CustomerNum, durtime, et.OccurTime);
	if(et.OccurTime < CloseTime)			// 银行尚未关门，插入事件表 
		OrderInsert(&ev, et, cmp);
	
	// 求长度最短队列的序号,等长为最小的序号。然后将这个事件插入到队列中。 
	i = Minimum(q);
	f.ArrivalTime = en.OccurTime;
	f.Duration = durtime;
	EnQueue(&q[i], f);
	// 设定第i队列的一个离开事件并插入事件表。 
	if(1 == QueueLength(q[i]))
	{
		et.OccurTime = en.OccurTime + durtime;
		et.NType = i;
		OrderInsert(&ev, et, cmp);
		printf("离开事件发生时间是：%d，离开的窗口是%d\n\n", 
			et.OccurTime, et.NType + 1); 
	}
}

// 处理客户离开事件，en.NTyPe < Qu 
void CustomerDeparture()
{
	int i;
	
	i = en.NType;
	DeQueue(&q[i], &customer);	// 删除第i队列的排头客户
	// 累计客户逗留时间						 
	TotalTime += en.OccurTime - customer.ArrivalTime; 
	// 设定第i队列的队头为一个离开事件并插入事件表。
	if( !QueueEmpty(q[i]) )
	{
		GetHead_Q(q[i], &customer);
		et.OccurTime = en.OccurTime + customer.Duration;
		et.NType = i;
		OrderInsert(&ev, et, cmp);
	}
}
 
// 	模拟银行业务，计算客户在银行的逗留时间。 
void Bank_Simulation()
{
	Link p;
	ElemType t; 
	
	OpenForDay();	// 银行开业初始化 
	
	// 马上处理事件，判断事件表是否为空
	while( !ListEmpty(ev) )
	{
		// 删除事件表的第一个结点，并返回给p。
		DelFirst(&ev, GetHead(ev), &p);

		// 获取刚刚删除的事件结点
		t = GetCurElem(p);
		// 从中获取当前时间，当前事件类型。
		en.OccurTime = t.OccurTime;
		en.NType = t.NType;

		if( Qu == en.NType )
			CustomerArrived();		// 处理客户到达事件 
		else
			CustomerDeparture();	// 处理客户离开事件 
	}
	
	printf("顾客总数:%d, 所有顾客共耗时:%d分钟, 平均每人耗时: %d分钟\n",
		CustomerNum, TotalTime, TotalTime / CustomerNum);
}


int main()
{
	int i;
	printf("请输入银行营业时间长度(单位:分)\n");
	scanf("%d", &CloseTime);
	srand((unsigned)time(NULL));	// 随机种子 	
	
	// 模拟银行事务处理。
	Bank_Simulation();
	
	DestroyList(&ev);
	for (i = 0; i < Qu; i++)
		DestroyQueue(&q[i]);
	return 0;
}
