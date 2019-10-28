#include "sampleg.h"

Student initStu(){
	Student *ptrStu = (Student *)malloc(sizeof(Student));
	printf("please input name: ");
	scanf("%s", ptrStu->name);
	printf("please input id: ");
	scanf("%d", ptrStu->id);
	printf("please input record: ");
	scanf("%f", ptrStu->record);

	return *ptrStu;
}

void outStu(Student stu){
	printf("%s's id: %d and record: %f\n", stu.name, stu.id, stu.record);

	return;
}

float getRec(Student stu){
	return stu.record;
}

void setRec(int id, float record){
	Student stu;
	if(stu.id == id){
		stu.record = record;
	}

	return;
}
