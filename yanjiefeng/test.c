void reverse(Linklist)
{
	LNode *p;
	p=H->next;
	H->next=NULL;
	while(p)
	{q=p;   p=p->next;
		q->next=H->next;
		H->next=q;
	}
}
