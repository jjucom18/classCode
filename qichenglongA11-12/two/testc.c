#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;
typedef struct Node
{
    Elemtype data;
    struct Node *next;
}Node, *LinkedList;

// 单链表的初始化
LinkedList LinkedListInit()
{
    Node *L;
    L = (Node*)malloc(sizeof(Node));
    if (L == NULL)
    {
        printf("申请内存空间失败\n");
    }
    L->next = NULL;
    return L;
}

// 单链表的创建一：头插法建立单链表
LinkedList LinkedListCreatH()
{
    Node *L;
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;

    Elemtype x;
    while (scanf("%d", &x) != EOF)
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        p->data = x;
        p->next = L->next;
        L->next = p;
    }
    return L;
}

// 单链表的创建二：尾插法建立单链表
LinkedList LinkedListCreatT()
{
    Node *L;
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;

    Node *r;
    r = L;
    Elemtype x;
    while (scanf("%d", &x) != EOF)
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        p->data = x;
        // p->next = NULL;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return L;
}

// 单链表的插入，在链表的第i个位置插入x的元素
// 要在第i个位置插入，就得先找到第(i-1)个位置，插在它后面
LinkedList LinkedListInsert(LinkedList L, int i, Elemtype x)
{
    Node *pre;
    pre = L;
    int tempi = 0;
    for (tempi = 1; tempi < i; tempi++)
        pre = pre->next;
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = pre->next;
    pre->next = p;
    return L;
}

// 单链表的删除，在链表中删除第一个值为x的元素
LinkedList LinkedListDelete(LinkedList L, Elemtype x)
{
    Node *pre, *p;
    p = L->next;
    while (p->data != x)
    {
        pre = p;
        p = p->next;
    }
    pre->next = p->next;
    free(p);
    return L;
}

    


int main()
{
    LinkedList list, start;

    // 单链表的创建一：头插法建立单链表
    printf("请输入单链表的数据：");
    list = LinkedListCreatH();
    for (start = list->next; start != NULL; start = start->next)
        printf("%d", start->data);
    printf("\n");

    // 单链表的创建二：尾插法建立单链表
    printf("请输入单链表的数据：");
    list = LinkedListCreatT();
    for (start = list->next; start != NULL; start = start->next)
        printf("%d", start->data);
    printf("\n");

    // 单链表的插入，在链表的第i个位置插入x的元素
    int i,x;
    printf("请输入插入数据的位置：");
    scanf("%d", &i);
    printf("请输入插入数据的值：");
    scanf("%d", &x);
    LinkedListInsert(list, i, x);
    for (start = list->next; start != NULL; start = start->next)
        printf("%d", start->data);
    printf("\n");

    // 单链表的删除，在链表中删除第一个值为x的元素
    printf("请输入要删除的元素的值：");
    scanf("%d", &x);
    LinkedListDelete(list, x);
    for (start = list->next; start != NULL; start = start->next)
        printf("%d", start->data);
    printf("\n");

  
}
