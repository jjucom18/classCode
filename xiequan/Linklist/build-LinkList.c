typedef struct Inode {
	int data;struct *next;
}LNode,*LinkList;



LinkList creat_LinkList1(){
	LinkList L = NULL	
     LNode *s;int x;
	scanf("%d",&x);
	while(x!=flag){
    s=(LNode*)malloc(sizeof(LNode));
	s->data=x;
	s->next=L;
	L=s;
	scanf("%d",&x);

	}
	return L;
}
