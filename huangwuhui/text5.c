#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
}LinkNode,*LinkList;
LinkList head;

void InitList(LinkList *head)
{
	head=(LinkList*)malloc(sizeof(LinkList));
		(*head)->next=NULL;
}
LinkList CreatFormHead()
{
	LinkList head;
	LinkList s;
	char ch;
	int flag=1;
	head=(LinkList*)malloc(sizeof(LinkList));
	head->next=NULL;
	while(flag)
	{
		ch=getchar();
		if(ch!='$')
		{
			s=(LinkList*)malloc(sizeof(LinkList));
			s->data=ch;
			s->next=head->next;
			head->next=s;
		}
		else
			flag=0;
	}
	return head;
}
LinkList CreatFromTail()
{
	LinkList head,r,s;
	char ch;
	int flag=1;
	head=(LinkList*)malloc(sizeof(LinkList));
	head->next=NULL;
	r=head;
	while(flag)
	{
		ch=getchar();
		if(ch!='$')
		{
		s=(LinkList*)malloc(sizeof(LinkList));
		s->data=ch;
		r->next=s;
		r=s;
		} 
		else
		{
		flag=0;
		r->next=NULL;
		} 
		}
	return head;
} 
void DeleteList(LinkList head,int i)
{
	LinkList pre,r;
	int j;
	pre=head; j=0;
	while(pre->next!=NULL&&j<i-1)
	{
		pre=pre->next;
		j++;
	}
	if(j!=i-1||pre->next==NULL)
	{
		printf("\nPosition Error\n");
		return ;
	}
	r=pre->next;
	pre->next=r->next;
	free(r);
}
LinkList GetElem(LinkList head,int i)
{
	int j;
	LinkNode *p;

	p=head;j=0;
	while(p->next!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(i==j&&i!=0)
		return p;
	else
		return NULL;
}
int main(int argc,char **argv)
{
	LinkList head;
	int x,i;
	head=CreatFromHead();
	printf("please input insert location\n");
	scanf("%d",&i);
	printf("please input insert data\n");
	scanf("%d",&x);
	head=CreatFronTail();
	printf("please input insert location\n");
    scanf("%d",i);
	printf("please input insert data\n");
	scanf("%d",&x);

}
