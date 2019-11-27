#include "list.h"
#include <stdlib.h>

int main(int argc, char **argv){
     List *list = (List *)malloc(sizeof(List));
     initList(list1);
     for (int i = 0; i < 7; ++i)
     {
       addHead(list, i); 
     
     }
     
     dispList(list);
     deleNode(list, 5);
     dispList(list);
     Node *node = getNode(list, 4);
     printf("查找结果: %d\n", node->data);

     return 0;
}