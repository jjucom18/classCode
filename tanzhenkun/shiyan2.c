#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Linklist;

Linklist *create() 
{
	Linklist *head;
	head=(Linklist *)malloc(sizeof(Linklist));
	head->next=NULL;
	return head;	
}
void InitLinkedList() //初始化

Linklist *head_insert(Linklist *head,int value) //头插法
{
	Linklist *p,*t;
	t=head;
	p=(Linklist *)malloc(sizeof(Linklist));
	p->data=value;
	p->next=t->next;
	t->next=p;
	return head;
}

Linklist *tail_insert(Linklist *head, int value) //尾插法
{
	Linklist *p,*t;
	t=head;
	p=(Linklist *)malloc(sizeof(Linklist));
	p->data=value;
	while(t->next!=NULL) 
	t=t->next;

	t->next=p;
	p->next=NULL;
	return head;	
}

int DeleteEleSgLinkList(pNODE pHead, int pos)
{
	pNODE pt = NULL;
 
	if (pos > 0 && pos < GetLengthSgLinkList(pHead) + 1)
	{
		while (1)
		{
			pos--;
			if (0 == pos)
				break;
			pHead = pHead->pNext;
		}
 
		pt = pHead->pNext->pNext;
		free(pHead->pNext);
		pHead->pNext = pt;
 
		return 1;
	}
	else
		return 0;
                   }

LinkList FindValLinkList(LinkList list,void * data,int(*myFunc)(void *,void *))
    {
      struct LList *mPtr = NULL;
      struct LinkNode *mPcur = NULL;
      if (NULL == list||NULL == data||NULL == myFunc)
      {
       return NULL;
      }
      mPtr = (struct LList *)list;
      mPcur = mPtr->header.next;
      while (mPcur != NULL)
      {
        if (myFunc (mPcur->data,data))
        {
         break;
        }
        mPcur = mPcur->next;
      }
      if (NULL == mPcur)
      {
        return NULL;
      }

     return  mPcur->data; 
    }
    
    Linklist *display(Linklist *head) //打印链表
{
	Linklist *p;
	p=head->next;
	if(p==NULL)
	{
		printf("linklist is empty...\n");
		return ;
	}
	while(p!=NULL)
	{
	  printf("%5d",p->data);
	  p=p->next;	
	}
	printf("\n");	
	return head;
}

int main()
{
	Linklist *head;
	int i,num;
	head=create();

	printf("head_insert:\n");
	for(i=1;i<20;i=i+3)
	head_insert(head,i);
	display(head);

printf("tail_insert:\n");
	for(i=2;i<20;i=i+4)
	tail_insert(head,i);
	display(head);
	
	printf("delete a node:");
	scanf("%d",&num);
	delete(head,num);
	display(head);
  
  return 0;
                           }

