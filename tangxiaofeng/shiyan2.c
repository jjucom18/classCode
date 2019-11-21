#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{

	    int data;
		    struct LNode *next;
} LNode,*LinkList;
LinkList Init_LNode()
{

	LNode *L;
	L = (LinkList) malloc(sizeof(LNode) ) ;
	if(L == NULL) 					
}
{

	        printf("初始化失败!\n") ;
			        exit(-1) ;
					    } 
    L->next = NULL;
	        return L;
			} 
 
void Creat_List1(LNode *L)  
}
{

	    int i,n,num;
		    LNode *pnew;			    
printf("请输入要输入的元素个数：n = ") ;
	scanf("%d",&n) ;
  for(i=0;i<n;i++)
  {
printf("请输入第%d个数：",i+1) ;
	scanf("%d",&num) ;
  pnew = (LinkList) malloc(sizeof(LNode) ) ;
pnew->data = num;
        pnew->next = L->next;
		        L->next = pnew;} 
}

void Creat_List(LNode *L)  

{i
	    int i,n,num;
		    LNode *p,*pnew;
p  L;
printf("请输入要输入的元素个数：n = ") ;
	scanf("%d",&n) ;						 
for(i=0;i<n;i++) 
{
printf("请输入第%d个数：",i+1) ;
	scanf("%d",&num) ;
pnew = (LinkList) malloc(sizeof(LNode) ) ;
	if(pnew == NULL) 
	{

		            printf("初始化失败!\n") ;
					            exit(-1) ;
	}
 pnew->data = num;
         p->next = pnew;
		         p = pnew;
				     } 
    p->next =NULL;
	} 
void Delete_List(LNode *L)
{
int i , n ;
   LNode *p,*s;
p = L;i=1;
	printf("请输入你要删除的位置：n=") ;
	scanf("%d",&n) ;
	while(p&&i<n)
	{
	p = p->next;
	++i;
	}
if(!(p->next)  || i>n) 
 printf("删除的位置不合法!\n") ;
s = p->next;
    p->next = s->next;
	    free(s) ;
}
	 
