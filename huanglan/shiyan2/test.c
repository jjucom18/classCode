#include "Linklist.h"
#include  <stdlib.h>
  int main(int argc,char **argv)
{Linklist *list1 =(Linklist*)malloc(size(Linklist));
	printf("the first:\n");
	initLinklist(list1);
	addHead(list1,1);
	addHead(list1,3);
	addHead(list1,5);
	addHead(list1,7);
	addHead(list1,9);
	dispLinklist(list1);
	printf("the second:\n");
	deleNode(list1,1);
	dispLinklist(list1);
	printf("The length:%d\n",getLength(list1));
	Node *node =getNode(list1,7);
	printf("The getNode result: %d\n",node->data);
	return 0;

}
