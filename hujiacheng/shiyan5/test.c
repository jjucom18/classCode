#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef char ElemType;
typedef struct node
{
    ElemType data; // 数据元素
    struct node *lchild; // 指向左孩子结点
    struct node *rchild; // 指向右孩子结点
}BTNode; // 声明二叉链结点类型

/*-------------由括号表示串str创建二叉链b-----------------*/
static void create_btree(BTNode *&b, char *str){ // 创建二叉树(形参b:指针的引用)
    BTNode *p;
    BTNode *St[MAX_SIZE]; // 定义一个顺序栈
    int k;
    int j = 0;
    int top = -1; // 栈顶指针初始化
    char ch;

    b = NULL; // 建立的二叉树初始时为空
    ch = str[j]; // 取第一个字符
    while(ch != '\0') // str未扫描完时循环
    {
        switch(ch)
        {
        case '(': // 开始处理左子树
            top++;
            St[top] = p;
            k = 1;
            break;
        case ')': // 子树处理完毕
            top--;
            break;
        case ',': // 开始处理右子树
            k = 2;
            break;
        default:
            p = (BTNode *)malloc(sizeof(BTNode)); // 动态分配结点p的存储空间
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if(b == NULL) // 若b为空,p置为二叉树的根结点
                b = p;
            else // 已建立二叉树根结点
            {
                switch(k)
                {
                case 1:
                    St[top]->lchild = p;
                    break;
                case 2:
                    St[top]->rchild = p;
                    break;
                }
            }
            break;
        }
        // 取下一个字符
        j++;
        ch = str[j];
    }
}

/*--------------------------以括号表示法输出二叉树b----------------------*/
// "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))"
static void disp_btree(BTNode *b)
{
    if(b != NULL)
    {
        printf("%c", b->data);
        if(b->lchild != NULL || b->rchild != NULL)
        {
            printf("("); // 有孩子结点时才输出(
            disp_btree(b->lchild); // 递归处理左子树
            if(b->rchild != NULL) // 有右孩子结点时才输出,
                printf(",");
            disp_btree(b->rchild); // 递归处理右子树
            printf(")"); // 有孩子结点时才输出)
        }
    }
}

/*--------------------------释放二叉树b的所有结点----------------------*/
static void destroy_btree(BTNode *b) // 销毁二叉树(形参b:指针的引用)
{
    if(b != NULL)
    {
        destroy_btree(b->lchild);
        destroy_btree(b->rchild);
        free(b);
    }
}

/*--------------------------二叉树b的层次遍历算法----------------------*/
static void trav_level(BTNode *b)
{
    BTNode *que[MAX_SIZE]; // 定义环形队列(指针数组)
    int que_front, que_rear; // 定义队头和队尾指针

    que_front = que_rear = 0; // 设置队列为空队
    if(b != NULL)
        printf("%c ", b->data);
    que_rear++;
    que[que_rear] = b; // 根结点进队
    while(que_rear != que_front) // 队列不为空
    {
        que_front = (que_front + 1) % MAX_SIZE; // 计算队头指针
        b = que[que_front]; // 出队结点b
        if(b->lchild != NULL) // 输出左孩子,并进队
        {
            printf("%c ", b->lchild->data);
            que_rear = (que_rear + 1) % MAX_SIZE; // 计算队尾指针
            que[que_rear] = b->lchild;
        }
        if(b->rchild != NULL) // 输出右孩子,并进队
        {
            printf("%c ", b->rchild->data);
            que_rear = (que_rear + 1) % MAX_SIZE; // 计算队尾指针
            que[que_rear] = b->rchild;
        }
    }

    printf("\n");
}

/*--------------------------二叉树b的先序遍历递归算法----------------------*/
static void pre_order(BTNode *b)
{
    if(b == NULL)
        return;

    printf("%c ", b->data); // 访问根结点
    pre_order(b->lchild); // 递归访问左子树
    pre_order(b->rchild); // 递归访问右子树
}

/*--------------------------二叉树b的先序遍历非递归算法----------------------*/
static void pre_order1(BTNode *b)
{
    BTNode *p;
    BTNode *st[MAX_SIZE]; // 定义一个顺序栈(指针数组)
    int top = -1; // 定义栈顶指针

    if(b == NULL)
        return;

    top++;
    st[top] = b; // 根结点进栈
    while(top > -1) // 栈不空时循环
    {
        p = st[top]; // 出栈并访问该结点
        top--;
        printf("%c ", p->data);
        if(p->rchild != NULL) // 有右孩子,将其进栈
        {
            top++;
            st[top] = p->rchild;
        }
        if(p->lchild != NULL) // 有左孩子,将其进栈
        {
            top++;
            st[top] = p->lchild;
        }
    }
    printf("\n");
}

/*--------------------------二叉树b的中序遍历递归算法----------------------*/
static void in_order(BTNode *b)
{
    if(b == NULL)
        return;

    in_order(b->lchild); // 递归访问左子树
    printf("%c ", b->data); // 访问根结点
    in_order(b->rchild); // 递归访问右子树
}

/*--------------------------二叉树b的中序遍历非递归算法----------------------*/
// A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))
static void in_order1(BTNode *b)
{
    BTNode *p;
    BTNode *st[MAX_SIZE];
    int top = -1;

    if(b == NULL)
        return;

    p = b; // A
    while(top > -1 || p != NULL)
    {
        while(p != NULL) // 扫描结点p的所有左下结点并进栈
        {
            top++;
            st[top] = p;
            p = p->lchild;
        }
        if(top > -1)
        {
            p = st[top]; // 出栈结点p并访问
            top--;
            printf("%c ", p->data);
            p = p->rchild;
        }
    }
    printf("\n");
}

/*--------------------------二叉树b的后序遍历递归算法----------------------*/
static void post_order(BTNode *b)
{
    if(b == NULL)
        return;

    post_order(b->lchild); // 递归访问左子树
    post_order(b->rchild); // 递归访问右子树
    printf("%c ", b->data); // 访问根结点
}

/*--------------------------二叉树b的后序遍历非递归算法----------------------*/
static void post_order1(BTNode *b)
{
    int top = -1; // 栈指针设置初值
    BTNode *st[MAX_SIZE]; // 定义顺序栈
    BTNode *p;
    bool flag;

    if(b == NULL)
        return;
    do
    {
        while(b != NULL) // 将b结点的所有左下结点进栈
        {
            top++;
            st[top] = b;
            b = b->lchild;
        }
        p = NULL; // p指向当前结点的前一个已访问的结点
        flag = true; // flag为真表示正在处理栈顶结点
        while(top != -1 && flag)
        {
            b = st[top]; // 取出当前的栈顶元素
            if(b->rchild == p) // 右子树不存在或已被访问,访问之
            {
                printf("%c ", b->data); // 访问b结点
                top--;
                p = b; // p指向被访问的结点
            }
            else
            {
                b = b->rchild; // b指向右子树
                flag = false; // 表示当前不是处理栈顶结点
            }
        }
    }while(top != -1);

    printf("\n");
}

int main(int argc, char *argv[])
{
    BTNode *b;

    create_btree(b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("二叉树b:");
    disp_btree(b);
    printf("\n");

    printf("层次遍历序列:");
    trav_level(b);

    printf("先序遍历序列:\n");
    printf("    递归算法:");
    pre_order(b);
    printf("\n");
    printf("  非递归算法:");
    pre_order1(b);
    printf("\n");

    printf("中序遍历序列:\n");
    printf("    递归算法:");
    in_order(b);
    printf("\n");
    printf("  非递归算法:");
    in_order1(b);
    printf("\n");

    printf("后序遍历序列:\n");
    printf("    递归算法:");
    post_order(b);
    printf("\n");
    printf("  非递归算法:");
    post_order1(b);
    printf("\n");

    destroy_btree(b);

    return 0;
}
