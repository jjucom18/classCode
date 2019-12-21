#ifndef _STUDENT_H
#define _STUDENT_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

typedef struct student
{
    int id;
    char name[20];
    float score[3];
}Student;

typedef struct _node
{
    Student data;
    struct _node *next;
}Node;

Node *pH = NULL;
void menu();
Node *CreatNode();
Node *initlist();
void addtail();
void SaveInf();
void PrintfStudent();
void ReadInf();
void Quit();
void SearchId();
void SearchName();
void SearchChoice();
void Change();
void Delete();
void SortId();

#endif