#include<stdio.h>
#include<stdlib.h>

typedef int Status;
typedef int ElemType;

//结点定义
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//单链表的初始化
Status InitList_L(LinkList L)
{
	L = (LNode *)malloc(sizeof(LNode));   //申请结点空间
	if(L == NULL)        //判断是否有足够的内存d空间
             printf("申请内存空间失败\n");
	L->next = NULL;         //将next设置为NUlll,初始长度为0的单链表
	return 1;
}

//链表的头节点插入
Status Creat_HeadList(LinkList L)
{
	LinkList s;
	int x;        //设数据元素的类型为int
	L = (LNode *)malloc(sizeof(LNode));    //为头节点分配存储空间
	L->next = NULL;
	scanf("%d",&x);
	while(x!='$')
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data=x;      //申请结点，填装数据
		s->next=L;
		L = s;         //将结点ss插入到链表头部
		scanf("%d",&x);
	}
	return 1;
}

//链表的尾节点插入
Status Create_TailList(LinkList L)
{
	LinkList r,s;
        int x;         //设数据元素的类型为int
        L = (LNode *)malloc(sizeof(LNode));      //为尾节点分配存储空间
        L->next = NULL;
	scanf("%d",&x);
	while(x!=flag)         //flag表示结束标志
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r = s;
		scanf("%d",&x);
	}
	return 1;
}

//实现链表结点的删除
Status Delete_LinkList(LinkList L,int i)      //删除单链表L上第i个数据节点
{
	LinkList p,s;
	p = Get_LinkList(L,i-1);      //查找第i-1个结点
	if(p==NULL)
	{
		printf("第i-1个结点不存在");
		return-1;
	}
	else if(p->next==NULL)
	{
		printf("第i个结点不存在");
                return 0;
	}
	else
	{
		s = p->next;          //s指向第i个结点
		p->next=s->next;      //从链表中删除
		free(s);              //释放*s
		return 1;
	}
}

//实现链表中特定数据结点的返回,返回值为e
Status GetElem_List(LinkList L,int i,ElemType e)
{
	LNode *p;
	int j;
	p = L->next;  j = 1;           //从头结点开始扫描
	while(p && j<i)
	{
	p = p->next; ++j;        //扫描下一结点
	}
        if(!p||i>j)
	return 0;
        e = p->data;
        return 1;
}

//实现链表的打印输出
void PrintElem(LinkList L)
{
	LinkList p = L->next;
	printf("当前链表元素为：");
	while(p)
	{
		printf("%d",p->data);
		p = p->next;
	}
	printf("\n");
}
