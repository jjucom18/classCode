#ifndef testc_h
#define testc_h

#include <stdio.h>
#include <stdib.h>

typedef struct{
	char name[20];
	int id;
	float record;
} Classmate;

Classmate initStu();
void outStu(Classmate stu);
float getrRec(Classmate stu);
void setRec(int id, float record);

#endif
