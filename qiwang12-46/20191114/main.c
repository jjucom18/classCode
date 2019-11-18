#include "repoteq.h"

int main(int argc, char **argv)
{
    List *listq = (List *)malloc(sizeof(List));
    DataType n;
    initList(listq);
    for (int i = 0; i < 9; ++i)
    {
        addHead(listq,i+1);
    }
    dispList(listq);
    printf("请输入要删除的数据\n");
    scanf("%d",&n);
    deleNode(listq, n);
    dispList(listq);
    printf("请输入要获取的节点\n");
    scanf("%d",&n);
    Node *node = getNode(listq, n);
    printf("获取节点的结果: %d\n", node->data);

    return 0;
}