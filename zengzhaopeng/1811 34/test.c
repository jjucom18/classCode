#include <stdio.h>
int main ()
{
        typedef struct Lnod
        {
        int data ;
        struct Lnod*next;
        }
        Lnod,*Linklist;
Linklist p,m,n,r,L,a,b;
int i;
L=(Linklist)malloc(sizeof(Lnod)*5);
if(!L)exit(0);
L->next = NULL;
for(i=0;i<5;i++);
        {
        p=(Linklist)malloc(sizeof(Lnod));
        if(!p)exit(0);
        scanf("%d",&p->data);
        p->next=L->next;
        L->next=p;
        }
a=L->next;
printf("原来的链表中的元素为:");
while(a)
        {
        printf("%d",a->data);
        a=a->next;
        }
        printf("");
m=L->next;
n=m->next;
while(n->next)
        {
        r=n->next;
        n->next=m;
        m=n;
        n=r;
        }
n->next=m;
L->next->next=NULL;
L->next=n;
b=L->next;
printf("逆置之后链表中的元素为:");
while(b)
        {
        printf("%d",b->data);
        b=b->next;
        }
printf("");
return 0;
}
