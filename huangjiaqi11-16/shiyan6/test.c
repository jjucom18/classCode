#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//******宏定义参数******
#define NO 0
#define OK 1
#define EORRO 0
#define WordMaxSize 10
#define DATAMAXSIZE 10000
//******定义数据类型别名******
typedef int Status;
//******声明数据结构******
typedef struct
{
int Size;
char word[WordMaxSize];
}ElemType;
typedef struct TNode
{
ElemType data;
struct TNode *lchild;
struct TNode *rchild;
}BinaryTree,*BiTreePoint;
typedef struct LNode
{
BiTreePoint data;
struct LNode *next;
}ListNode,*ListPoint;
typedef struct
{
int length;
ListPoint next;
}HeadNode,*HeadPoint;
//******以下为二叉树数据结构操作******
BiTreePoint InitBiTree()
{
return NULL;
}
Status BiTreeEmpty(BiTreePoint T)
{
if(T==NULL)
return OK;
return NO;
}
void BiTreeDelete(BiTreePoint *T) //释放HuffmanTree
{
if(*T==NULL)
return ;
BiTreeDelete(&(*T)->lchild);
BiTreeDelete(&(*T)->rchild);
free(*T);
return ;
}
void previsitHuffmanTree(BiTreePoint T,char *s,int ans) //先序访问huffman树,结点编码
{
if(T==NULL)
return ;
else if(T->lchild==NULL && T->rchild==NULL)
{
s[ans]=0;
printf("单词:%s 频数:%d 编码:%s\n",T->data.word,T->data.Size,s);
return ;
}
s[ans]='1';
previsitHuffmanTree(T->lchild,s,ans+1);
s[ans]='0';
previsitHuffmanTree(T->rchild,s,ans+1);
return ;
}
unsigned int HuffmanWPL(BiTreePoint T,unsigned int L)
{
if(T==NULL)
return 0;
else if(T->lchild==NULL && T->rchild==NULL)
return T->data.Size*L;
return HuffmanWPL(T->lchild,L+1)+HuffmanWPL(T->rchild,L+1);
}
//******以上为二叉树数据结构操作******
//******以下为链表操作******
ListPoint ListNode_Search(ListPoint Head,int ans)
{
if(Head->next==NULL || Head->next->data->data.Size > ans)
return Head;
return ListNode_Search(Head->next,ans);
}
ListPoint Init(int *n)
{
ListPoint Head,p,q;
int ans;
char temp[10]={'1'};
Head=NULL;
while(temp[0]!='0')
{
scanf("%d ",&ans);
q=(ListPoint)malloc(sizeof(ListNode));
q->data=(BiTreePoint)malloc(sizeof(BinaryTree));
q->data->data.Size=ans;
strcpy(q->data->data.word,temp);
q->data->lchild=q->data->rchild=NULL;
if(*n==0 || Head->data->data.Size>ans) q->next=Head,Head=q;
else
{
p=ListNode_Search(Head,ans);
q->next=p->next;
p->next=q;
}
*n++;
}
return Head;
}
HeadPoint HeadInit()
{
HeadPoint Head;
Head=(HeadPoint)malloc(sizeof(HeadNode));
Head->length=0;
Head->next=Init(&Head->length);
return Head;
}
BiTreePoint CreatHuffmanTree(ListPoint *Head)
{
ListPoint q,p,temp;
if(*Head==NULL)
return NULL;
while((*Head)->next)
{
q=(*Head);
p=(*Head)->next;
(*Head)=p->next;
temp=(ListPoint)malloc(sizeof(ListNode));
temp->data=(BiTreePoint)malloc(sizeof(BinaryTree));
strcpy(temp->data->data.word,"Parent");
if(q->data->data.Size < p->data->data.Size)
{
temp->data->lchild=q->data;
temp->data->rchild=p->data;
}
else
{
temp->data->lchild=p->data;
temp->data->rchild=q->data;
}
temp->data->data.Size=q->data->data.Size + p->data->data.Size;
free(q);
free(p);
if((*Head) && (*Head)->data->data.Size < temp->data->data.Size)
{
q=ListNode_Search((*Head),temp->data->data.Size);
temp->next=q->next;
q->next=temp;
}
else
{
temp->next=(*Head);
(*Head)=temp;
}
}
return (*Head)->data;
}
//******以上为链表数据结构操作******
int main()
{
BiTreePoint T;
HeadPoint Head;
char *s=(char *)malloc(DATAMAXSIZE*sizeof(char));
Head=HeadInit();
T=CreatHuffmanTree(&Head->next);
printf("\n先序遍历HuffmanTree结点编码:\n");
previsitHuffmanTree(T,s,0);
printf("\nHuffmanTree的带权路径长度:\n");
printf("%u\n",HuffmanWPL(T,0));
free(s);
BiTreeDelete(&T);
return 0;
}
