#include "testc.h"

Classmate initStu(){
	Classmate *ptrStu = (Classmate *)malloc(sizeof(Classmate));
	printf("please input name: ");
	scanf("%s", ptrStu->name);
	printf("please input id: ");
	scanf("%d", ptrStu->id);
	printf("please input record: ");
	scanf("%f", ptrStu->record);

	return *ptrStu;
}

void outStu(Classmate stu){
	printf("%s's id: %d and record: %f\n", stu.name, stu.id, stu.record);

	return;
}

float getRec(Classmate stu){
	return stu.record;
}

void setRec(int id, float record){
	Classmate stu;
	if(stu.id == id){
		stu.record = record;
	}

	return;
}
