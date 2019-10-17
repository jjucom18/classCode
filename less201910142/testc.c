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
	char *nameArr[] = {"zhangsan", "lisi", "wangwu", "zhaoliu","zhouqi"};
	//Student *stu0 = initStu("zhangsan", 20, 77.5);
	Student *stu0 = initStu(nameArr[0], 20, 77.5);
	Student *stu1 = initStu(nameArr[1], 21, 78.5);
	Student *stu2 = initStu(nameArr[2], 20, 77.5);
	Student *stu3 = initStu(nameArr[3], 21, 78.5);
	Student *stu4 = initStu(nameArr[4], 21, 78.5);

	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	initList(list);
	printf("init success!\n");
	addHead(list, stu0);
	addHead(list, stu1);
	addHead(list, stu2);
	addHead(list, stu3);
	addHead(list, stu4);
	
	displayList(list);


	return 0;
}

