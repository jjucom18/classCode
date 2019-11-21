#include<stdio.h>
#include<stdlib.h>
	typedef struct node
	void *data{
	struct node *next;
}	node,*LinkList;

LinkList *init_LinkList
{
		node *p;
	p=(node*)malloc(sizeof(node));
        	p->data = data;
	  p->next = NULL;
	return p;}//初始化

LinkList Creat_LinkListH()
{
		LinkList L = NULL;
		 node *s;
	  s=(node*)malloc(sizdof(node));
 	int n;
  	scanf("%d",&n);
   	   	while(n != flag)
		{s->data=n;
		 s->next=L->next	;
				 L->next=s
	}
	return L;}//头节点插入


LinkList Creat_LinkListT()
{
		LinkList L=NULL;
			node *S.*r=NULL;
			S=(node*)malloc(sizdof(node));
		int x;
		scanf("%d",x);
		while(x != flag)
	    		{s->data=x;
			if (L==NULL)L=S;
			else r->next=s;
				 r=s;
				 scanf("%d",&x);
	}
	if (r!=NULL) r->next=NULL;
	return L;}//尾结点插入


LinkList Delete_LinkList(LinkList L,int i)

{
    Linklist *p;

    int i;

    for(i=0;i<n;i++)

    {
        p=(Linklist *)malloc(sizeof(Linklist));

        scanf("%d",&p->data);

        p->next=phead->next;

        phead->next=p;

    }

}
