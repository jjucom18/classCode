void CreateBiTree(BiTree &T)
{
char ch;
scanf("%c",&ch);//读入一个字符
if(ch==' ')T=NULL;

 else
{
T=(BiTNpde*)malloc(siezof(BiTNode));
//生成一个新结点
T->data=ch;
CreateBiTree(T->lchild);//生成左子树
CreateBiTree(T->rchild);//生成右子树
}
}
//先序遍历的递归
void PreOrder(BiTree T)
{
if(T)
{
printf(%c,T->data);//访问结点
PreOrder(T->lchild);//遍历左子树
PreOrder(T->rchild);//遍历右子树
}
}
//中序遍历的递归
void inOrder(BiTree T)
{
if(T)
{
inOrder(T->lchild);//遍历左子树
printf("%c",T->data);//访问结点
inOrder(T->rchild);//遍历右子树
}
}
//后续遍历的递归
void PostOrder(BiTree T)
{
if(T)
{
PostOrder(T->lchild);//遍历左子树
PostOrder(T-rchild);//访问结点
printf("%c",T->data);//遍历右子树
}
}

//以层次顺序遍历二叉树
void LevelOrder(TreeNode *t){
     TreeNode *q[MaxSize];
     int front=0,rear=0;
     TreeNode *p;
     if(t ==NULL) return;
     q[rear] = t;
     rear =(rear+1) % MaxSize;
     while (front != rear) {
	 p = q[front];
	 front = (front +1) % MaxSize;
         printf("%c", p->data);
	 if (p->left) {
             q[rear] = p ->left;
	     rear = (rear+1) % MaxSize;
	  }
	 if (p->right) {
	     q[rear] = p->right;
	     rear = (rear+1) % MaxSize;
	 }
     }
 }
