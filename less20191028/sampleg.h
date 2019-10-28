#ifndef sampleg_h
#define sampleg_h

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	int id;
	float record;
} Student;

Student initStu();
void outStu(Student stu);
float getRec(Student stu);
void setRec(int id, float record);

#endif
