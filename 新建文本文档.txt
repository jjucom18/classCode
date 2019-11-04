typedef struct LNode
{ElemType data;
struct LNode * next;
}LinkList;
void Reverse(LinkList & head)
{
        p=head->next;q=NULL;
        while(p)
        {r=q;
                q=p;
                p=p->next;
                q->next=r;
        }
        head ->next=q;
}