typedef struct Node
{
  int data;//数据
  struct Node *next;//下一个节点
}Node，*List;//list==Node *


//初始化,头结点已经存在
void InitList(List plist)
{
	assert(plist !=NULL);
	plist->next=NULL;
} 
int main()
{
	Node head;//CreateList();
	InitList(&head);
	List p://Node *p
		InitList(p);
}




LinkList* Cread_End()
{
	LinkList *head,*node,*end;
	int num;
	head=new LinkList;
	head->next = NULL;
	end =head;
	cout<<"请输入，以0结束"<<end1;
	cin>>num;
	while(num !=0)
	{
		node = new LinkList;
		node->val = num;
		end->next = node;
		end = node;
		cin >> num;
	}
	end->next = NULL;
	return head;


}


void Del_LinkList_val(LinkList *List,int n)
{
	int num = 0
	int size = Get_LinkList_Size(List);
	LinkList *end;
	//删除的位置大于或等于节点的个数，直接删除
	if(size <=n)
		while((List->next !=NULL)&&(num<n-1)){
			List = Lis->next;
			num++;
		}
	end = List->next;
	List->next = NULL;
	free(end);
}
else
{
	while((List->next !=NULL)&&(num<n)){
		List = List->next;
		num++;
	}
	if(n==num)
	{
end = List->next;
List->next = end->next;
free(end);}
} 
} 
int _tmain(int argc,_TCHAR* argv[]) 
	LinkList *list1 = Creat_Head();
	//LinkList *list2 = Cread_End();
	//Insert(list1,list2,2);
	//Print_LinkList(list1);
	De1_LinkList_va1(List1,2);
	Print_LinkList(list1);
	return 0
	






















