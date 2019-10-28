
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct _stu{
	char *name;
	bool sex; 
	int *age;
	double *record;
} Student;

void outStudent(Student stu){
	printf("-----------------------------------------");
	printf("%s info:\n", stu.name);
	printf("sex: %d\t",  stu.sex);
	printf("age: %d\t",  stu.age);
	printf("record: %f\n",  stu.record);
	printf("-----------------------------------------");

	return;
}

Student* stuInit(char *name, bool sex, int *age, double *record){
	Student *ptrStu = (Student *)malloc(sizeof(Student));
	ptrStu->name = (char *)malloc(sizeof(char) * 30);
	strcpy(ptrStu->name, name);
	ptrStu->sex = &sex;
	ptrStu->age = (int *)malloc(sizeof(int));
	ptrStu->age = &age;
	ptrStu->record = (double *)malloc(sizeof(double));
	ptrStu->record = &record;

	return ptrStu;
}

int main(int argc, char **argv)
{
	char *name = "zhangsan";
	int agez = 18;
	double recordz = 18.5;
	Student* ptrStu = stuInit(name, 0, &agez, &recordz);

	outStudent(*ptrStu);

	return 0;
}
