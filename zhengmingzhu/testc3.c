#include "testc2.h"
#include "testc2.c"
#include<stdlib.h>

int main(int argc, char **argv)
    {
       List *list = (List *)malloc(sizeof(List));
       printf("the first:\n");
       initList(list);
       addHead(list, 9,6,4,7);
       addTail(list, 5,9,4,0);

       displayList(list);

       printf("the second:\n");
       deleteNode(list, 6);
       displayList(list);
    
       Node *node = getNode(list, 4);
       printf("The getNode : %d\n", node->data);
     return 0;
    }

