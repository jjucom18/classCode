#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*strcpy(ptrStr1, ptrStr2);
strcmp(ptrStr1, ptrStr2);
strcat(ptrStr1, ptrStr2);*/

//1 defination
//struct _stu{
struct _stu{
	char name[30];
	bool sex; 
	int age;
	double record;
//};
} stu1;

//2 defination
//typedef struct _stu1{
typedef struct {
	char name[30];
	bool sex; 
	int age;
	double record;
} Student;

void outStudent(struct _stu stu1){
	printf("-----------------------------------------");
	printf("%s info:\n", stu1.name);
	printf("sex: %d\t",  stu1.sex);
	printf("age: %d\t",  stu1.age);
	printf("record: %f\n",  stu1.record);
	printf("-----------------------------------------");

	return;
}

void outStudent1(Student stu1){
	printf("-----------------------------------------");
	printf("%s info:\n", stu1.name);
	printf("sex: %d\t",  stu1.sex);
	printf("age: %d\t",  stu1.age);
	printf("record: %f\n",  stu1.record);
	printf("-----------------------------------------");

	return;
}

int main(int argc, char **argv)
{
	struct _stu stu1;
	strcpy(stu1.name, "zhangsan");
	stu1.sex = 1;
	stu1.age = 20;
	stu1.record = 19.5;

	Student stu2;
	strcpy(stu2.name, "lisi");
	stu2.sex = 0;
	stu2.age = 18;
	stu2.record = 91.5;

	Student *ptrStu = (Student *)malloc(sizeof(Student));
	strcpy((*ptrStu).name, "wangwu");
	(*ptrStu).sex = 1;
	(*ptrStu).age = 28;
	(*ptrStu).record = 61.5;

	Student *ptrStu1 = (Student *)malloc(sizeof(Student));
	strcpy(ptrStu1->name, "wangwu1");
	ptrStu1->sex = 0;
	ptrStu1->age = 18;
	ptrStu1->record = 71.5;

	outStudent(stu1);
	outStudent1(stu2);
	outStudent1(*ptrStu);
	outStudent1(*ptrStu1);

	return 0;
}
