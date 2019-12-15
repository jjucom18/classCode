#ifndef student_h
#define student_h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

typedef struct student
{
    int id;
    char name[20];
    float score[3];
    struct student *next;
}Student;

void menu();
Student *CreatNode(Student *pH);
Student *initlist();
void addtail(Student *pH);
void SaveInf(Student *pH);
void PrintfStudent(Student *pH);
void ReadInf();

#endif