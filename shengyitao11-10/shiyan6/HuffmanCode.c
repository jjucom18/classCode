#include <stdio.h>
#include <stdlib.h>
typedef int Elem Type;
struct BTreeNode

{
Elem Type data;

struct BTreeNode*left;

struct BTreeNode
{

Elem Type data;

struct BTreeNode* left;

struct BTreeNode* right;

}；
//遍历哈夫曼树

void PrintBTree_int(struct BTreeNode*BT)

{
printf("%d",BT->data);

if (BT->left != NULL || BT->right !=NULL)

{
printf("(");

PrintfBTree_int(BT->left);//输出左子树

if (BT->right != NULL)

printf(",");

PrintfBTree_int(BT->right);//输出右子树

printf(")");
}

}

}

//创建哈夫曼树

struct BTreeNode*
CreateHuffman(Elem Type a[],int n)

{
int i,j;

struct BTreeNode **b,*q;

b =malloc(n*sizeof(struct BTreeNode));

for (i =0; i < n; i++)   //动态分配内存
{
b[i] =malloc(sizeof(struct BTreeNode));
 
b[i]->data =a[i];

b[i]->left =b[i]->right = NULL;

}

for (i = 1;i< n;i++)

{

//k1表示森林中具有最小权值的树根结点的下标，k2为次最小的下标

int k1 = -1,k2;

for (j = 0; j < n;j++)//让k1初始指向森林中第一棵树，k2指向第二棵

{

if (b[j] != NULL && k1 == -1)

{

k1 = j;

continue;

}

if (b[i] != NULL)

{

k2 = j;

break;

}

}

for (j= k2;j < n; j++)  //构造最优解

{
if (b[j]->data < b [k1] ->data)

{
   k2 = k1;
   k1 = j;
}

else if (b[j]->data <b[k2]->data)

k2 = j;

}

}

q = malloc(sizeof(struct BTreeNode));

q->data = b[k1]->data + b[k2]->data;

q->left = b[k1];

q->right = b[k2];

b[k1] = q;

b[k2] = NULL;

}

free(b);

return q;

}
//计算带权路径

ElemType WeightPathLength(struct BTreeNode * FBT,int len)//len初始为0

{
   if (FBT == NULL)//空树返回0

   return 0;
   
   else
  
{
  if (FBT->left ==NULL && FBT->right == NULL)
  
  return FBT->data *Len;
  
  else
  
  return WeightPathLength(FBT->left,len+1)+WeightPathLength(FBT->right,len+1);

}

}

//构造哈夫曼编码


void HuffManCoding(struct BTreeNode *FBT,int len)
 
｛

static int a[10];

if (F B T != NULL)

{

if ( F B T->left == NULL && F B T->right == NULL)
 
{

int i;

printf( "结点的值为%d的编码 ：",F B T->data);

for (i=0; i < len; i++)

printf("%d",a[i]);

printf("\n");

}
else

{

a[len] =0;

HuffManCoding(FBT->left,len+1);

a[len] =1;

HuffManCoding(F B T->left,len+1);

}

}

}

}
int main()

{
int n,i;

Elem Type*a;

struct BTreeNode*fbt;

printf("输入带权结点数n: \n");

while(1)

{
scanf("%d",&n);

if(n>1)

break;

else

printf("重输n值：");

}
a=malloc(n*sizeof(Elem Type));

printf("输入%d个整数作为权值:\n",n);

for( i =0; i < n;i++)

scanf("%d",&a[i]);

fbt = CreateHuffman(a,n);

printf("哈夫曼树如下：\n");

PrintBTree_int(fbt);

printf("\n");

printf("哈夫曼树的带权路径长度： \n");

printf("%d\n",WeightPathLength(fbt,0));

printf("哈夫曼树如下 ：\n");

PrintBTree_int(bt);

printf("\n");

printf("哈夫曼树的带权路径长度：\n");

printf("%d\n",WeightPathLength(fbt,0));

printf("树中每个叶子结点的哈夫曼编码:\n");

HuffManCoding(fbt,0);

return 0;

}
















