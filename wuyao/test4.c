#include<stdio.h>
#include<malloc.h>
typedef int dataType;
typedef struct node
{
   dataType data;
   struct node *next;
} Linklist;
Linklist *createlist()
{
   Linklist *head;
   head = (Linklist *)malloc(sizeof(Linklist));
   head->next = NULL;
   return head;
}
Linklist *head_insert(Linklist *head,int value)
{
   Linklist *p,*t;
   t = head;
   p = (Linklist *)malloc(sizeof(Linklist));
   p->data = value;
   p->next = t->next;
   t->next = p;
   return head;
}
Linklist *tail_insert(Linklist *head,int value)
{
   Linklist *p,*t;
   t = head;
   p = (Linklist *)malloc(sizeof(Linklist));
   p->data = value;
   while(t->next! = NULL)
   t = t->next;
   t->next = p;
   p->next = NULL;
   return head;
}
Linklist *delete(Linklist *head,int value)
{
   Linklist *p,*t;
   p = head;
   while(p->next! = NULL)
   {
      if(p->next->data==value)	    
      {
         t = p->next;
	 p->next = t->next;
	 free(t);
	 t = NULL;
      }
      else
	 p = p->next;
    }
    return head;
}
Linklist *display(Linklist *head)
{
    Linklist *p;
    p = head->next;
    if(p==NULL)
    {
       printf("Linklist is empty...\n");
       return;
    }
    while(p! = NULL)
    {
       printf("%5d",p->data);
       p = p->next;
    }
    printf("\n");
    return head;
}
