#include <stdio.h>
#include <stdlib.h>

typedef  struct LinkList
{
   int date;
   struct LinkList *next;
}Node,*LinkList;

LinkList Creat_LinkList()
{
        LinkList L = NULL;
        Node *s;
        int x;
        scanf("%d",&x);
        printf("please input -1 over\n");
        while(x!=-1)
        {
                s =(Node *)malloc(sizeof(Node));
                s->date = x;
                s->next = L;
                L = s;
                scanf("%d",&x);
                printf("input %d\n",x);
        }
        return L;
}

LinkList Creat_LinkList2()
{
	LinkList L = NULL;
	LinkList r = NULL;
	Node *s;
	int x;
	printf("input number");
	scanf("%d",&x);
	while(x!=-1)
	{
		s = (Node *)malloc(sizeof(Node));
		s->date = x;
		if(L = NULL)
			L = s;
		else
			r->next = s;
		r = s;
		scanf("%d",&x);
	}
	if(r != NULL)
		r->next = NULL;
	return L;
}

int Del_LinkList()
{
	LinkList p , s;
	p = Get_LinkList(L,i-1);
		if(p == NULL)
		{
			printf("have not i");
			return -1;
		}
		else if(p->next==NULL)
		{
			printf("have not i");
			return 0;	
		}
		else
		{
			s = p->next;
			p->=s->next;
			free(s);
			return 1;
		}

}

Node *Get_LinkList(LinkList L,int i)
{
	Node *p = L;
	int j = 0;
	while(p->next!=NULL&&j<i)
	{
		p = p->next;
		j++;
		if(j = i)
			return p;
		else
			return NULL;
	}
}

int main()
{
        LinkList L;
        L = Creat_LinkList2();
	 while(L!=NULL)
          {
                 printf("%d\n",L->date);
                 L = L->next;
          }
//      printf("hhhh%d",L->date);
//      while(L!=NULL);
//      printf("mmm%d",(L->next->date));
	
}
