#include "linkg.h"

/*Student initStu(char *name, int age, double record);
void outStu(Student stu);
void initList(LinkedList *);
void addHead(LinkedList *, void *);
void addTail(LinkedList *, void *);
void delNode(LinkedList *, Node *);
Node *getNode(LinkedList *, void *);
void displayList(LinkedList *);*/

int main(int argc, char **argv)
{
	Student stu0 = initStu("zhangsan", 20, 77.5);
	Student stu1 = initStu("lisi", 21, 78.5);
	Student stu2 = initStu("wangwu", 20, 77.5);
	Student stu3 = initStu("zhaoliu", 21, 78.5);
	Student stu4 = initStu("zhouqi", 21, 78.5);

	//LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	LinkedList list;
	initList(&list);
	addHead(&list, &stu0);
	addHead(&list, &stu1);
	addHead(&list, &stu2);
	addHead(&list, &stu3);
	addHead(&list, &stu4);
	
	displayList(&list);


	return 0;
}

