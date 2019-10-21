#include "linkg.h"

int main(int argc, char **argv)
{
	int dataArr[] = {21, 34, 56, 78, 91};

	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	initList(list);
	printf("init success!\n");
	/*addHead(list, stu0);
	addHead(list, stu1);
	addHead(list, stu2);
	addHead(list, stu3);
	addHead(list, stu4);*/

	addTail(list, &dataArr[0]);
	addTail(list, &dataArr[1]);
	addTail(list, &dataArr[2]);
	addTail(list, &dataArr[3]);
	addTail(list, &dataArr[4]);
	
	displayList(list);


	return 0;
}

