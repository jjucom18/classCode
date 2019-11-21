#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Node{
	ElemType data
		struct Node *next;
} 
void LinkList Creat_LinkList1()
{
	LinkList L=NULL;  //定义L为空链表
	LNode *s;
	int x;  //设数据元素的类型为int
	scanf("%d",&x);
	while (x!=flag)//flag为根据实际情况设定的结束数据输入的标志数据{
		s=(LNode*)malloc(sizeof(LNode));
	s->data=x;  
	s->next=L;L=s;
	scanf("%d",&x);
}
return L;
}
void Del_LinkList(LinkList L,  int i){
	//删除单链表L上的第i个数据节点
	LinkList p,s;
	p=Get_LinkList(L,i-1);
	if(p==NULL)
	{
		printf("第i-1个节点不存在")；
			return -1；
	}
else if(p->next==NULL)
{
printf("第i个节点不存在");
return 0;
}else{
	s=p->next;
	p->next=s->next;
	free(s);
	return 1;
}
}
  

