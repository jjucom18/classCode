#include"test2.h"

int main(int argc,char **argv){
	List *list1=(List *)malloc(sizeof(List));
	printf("the first:\n");
	initList(list1);
	addHead(list1,1);
	addHead(list1,3);
	addHead(list1,5);
	addHead(list1,7);
	addHead(list1,9);
	dispList(list1);
	printf("the second:\n");
	

	Node *node=getNode(list1,7);
	printf("The getNode result: %d\n",node->data);

	return 0;
}



	

              


	
	


