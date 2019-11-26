#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define queueSize_Max 256 //队列的最大长度
#define code_Max 256 //编码的最大长度
 
typedef struct hfmTreeNode{
    int symbol;
    struct hfmTreeNode *left;
    struct hfmTreeNode *right;
} hfmTreeNode, *phTreeNode;
 
typedef struct hHfmTreeNode{
    hfmTreeNode* rootNode;
} hHfmTreeNode;
 
typedef struct queueNode{
    phTreeNode ptr;
    int count;
    struct queueNode *next;
} queueNode, *ptrQueue;
 
typedef struct hQueueNode{
    int size;
    ptrQueue first;
} hQueueNode;
 
typedef struct tableNode{
    char symbol;
    char* code;
    struct tableNode *next;
} tableNode;
 
typedef struct hdTableNode{
    tableNode *first;
    tableNode *last;
} hdTableNode;
 
void initQueue(hQueueNode** hQueue)
{
    *hQueue=(hQueueNode*)malloc(sizeof(hQueueNode));
    (*hQueue)->size=0;
    (*hQueue)->first=NULL;
}
 
void addQueueNode(hQueueNode **hQueue,hfmTreeNode *hNode,int count)//新建一个队列节点并按统计的结果从小到大的顺序加入队列
{
    queueNode *qNode=NULL;
 
    if((*hQueue)->size==queueSize_Max)//队列规模检查，正常情况下不会出现
    {
        printf("\nERR: The queue is full!!!");
    }
    else    //如果正常，则按照从小到大的顺序，寻找正确的位置插入节点
    {
        if(0==(*hQueue)->size)//如果是添加的第一个节点，直接添加即可
        {
            qNode=(queueNode*)malloc(sizeof(queueNode));
            (*hQueue)->first=qNode;
            qNode->count=count;
            qNode->ptr=hNode;
            qNode->next=NULL;
            (*hQueue)->size++;
        }
        else if(count<(*hQueue)->first->count)//如果要添加的字符的统计数量小于现有最小的，则直接放在第一个节点处
        {
            qNode=(queueNode*)malloc(sizeof(queueNode));
            qNode->next=(*hQueue)->first;
            (*hQueue)->first=qNode;
            qNode->count=count;
            qNode->ptr=hNode;
            (*hQueue)->size++;
        }
        else    //对于第三类情况，则需要遍历队列，直到寻找到合适的位置
        {
            queueNode* p=(*hQueue)->first;
            qNode=(queueNode*)malloc(sizeof(queueNode));
            qNode->count=count;
            qNode->ptr=hNode;
            (*hQueue)->size++;
 
            while(p->next!=NULL && count>=p->next->count)
                p=p->next;
            qNode->next=p->next;
            p->next=qNode;
        }
    }
}
 
hfmTreeNode* getHfmTreeNode(hQueueNode* hQueue)
{
    hfmTreeNode* getNode;
    if(hQueue->size>0)
    {
        getNode=hQueue->first->ptr;
        hQueue->first=hQueue->first->next;
        hQueue->size--;
    }
    else
    {
        printf("\nERR: Can't get a node\n");
    }
    return getNode;
}
 
 
hHfmTreeNode* crtHfmTree(hQueueNode** hQueue)
{
    int count=0;
    hfmTreeNode *left, *right;
 
    while((*hQueue)->size>1)
    {
        count=(*hQueue)->first->count+(*hQueue)->first->next->count;
        left=getHfmTreeNode(*hQueue);
        right=getHfmTreeNode(*hQueue);
 
        hfmTreeNode *newNode=(hfmTreeNode*)malloc(sizeof(hfmTreeNode));
 
        newNode->left=left;
        newNode->right=right;
 
        addQueueNode(hQueue,newNode,count);
    }
 
    hHfmTreeNode* tree=(hHfmTreeNode*)malloc(sizeof(hHfmTreeNode));
    tree->rootNode=getHfmTreeNode(*hQueue);
    return tree;
}
 
hHfmTreeNode* creatTree(void)
{
    int *countArray;
    char c;
    int i;
 
    countArray=(int*)malloc(sizeof(int)*256);//分配空间用于存储各字符出现的次数,并初始化为零
    for(i=0;i<256;i++)
    {
        countArray[i]=0;
    }
 
    hQueueNode *hQueue;
    initQueue(&hQueue);
    for(i=0;i<256;i++)
    {
        if(countArray[i])
        {
            //printf("%c %d\n",i, countArray[i] );
            hfmTreeNode *hNode=(hfmTreeNode*)malloc(sizeof(hfmTreeNode));//创建一个树节点，并初始化（用来对应队列queueNode中的ptr）
 
            hNode->symbol=(char)i;
            hNode->left=NULL;
            hNode->right=NULL;
 
            addQueueNode(&hQueue,hNode,countArray[i]);//将该节点插入队列中的适当位置（按统计的结果，从小到大排列）
        }
    }
    free(countArray);//释放不用的内存
 
    queueNode* q=hQueue->first;
    printf("\n");
    do
    {
        printf("\n%c %d",q->ptr->symbol, q->count);
        q=q->next;
    }    while(q!=NULL);
    //printf("%d",hQueue->size);
 
    hHfmTreeNode *tree=crtHfmTree(&hQueue);
    return tree;
}
 
void traverseTree( hdTableNode** table, hfmTreeNode* tree, char* code, int k)
{
    if(tree->left==NULL && tree->right==NULL)   //递归结束检查，即找到叶子节点
    {
        code[k]='\0';   //添加字符串结束标记
        tableNode *tNode=(tableNode*)malloc(sizeof(tableNode)); //创建一个节点，并将其添加到table链表中
        tNode->code=(char*)malloc(sizeof(char)*256+1);
        strcpy(tNode->code,code);
        tNode->symbol=tree->symbol;
        tNode->next=NULL;
 
        if((*table)->first==NULL)   //如果是第一个节点，直接添加即可， 否则添加到尾部即可
        {
            (*table)->first=tNode;
            (*table)->last=tNode;
        }
        else
        {
            (*table)->last->next=tNode;
            (*table)->last=tNode;
        }
    }
 
    if(tree->left!=NULL)    //向左边递归，并记录编码为0
    {
        code[k]='0';
        traverseTree(table,tree->left, code, k+1);
    }
 
    if(tree->right!=NULL)   //向右边递归，并记录编码为1
    {
        code[k]='1';
        traverseTree(table, tree->right, code, k+1);
    }
}
 
hdTableNode* crtTable(hHfmTreeNode* hfmTree)
{
    hdTableNode* hdTable=(hdTableNode*)malloc(sizeof(hdTableNode));
    hdTable->first=NULL;
    hdTable->last=NULL;
 
    char code[code_Max];
    int k=0; //记录树的层级
 
    traverseTree(&hdTable, hfmTree->rootNode, code, k);
    return hdTable;
}
 
 
 
int main(void)
{
    hHfmTreeNode* tree;
    hdTableNode* table;
 
    tree=creatTree();
    table=crtTable(tree);
    int i=0, j=0;
    tableNode* t=table->first;
    char* s=t->code;
    printf("The Huffman code is:\n");
    while(t!=NULL)
    {
 
        for(i=0;i<257;i++)
        {
            if((*s)!='\0')
            {
                printf("%c",*s);
                s++;
            }
        }
            printf("%8c\n",t->symbol);
            t=t->next;
            if(t)
                s=t->code;
 
    }
}

