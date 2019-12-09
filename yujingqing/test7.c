#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define Max 11
#define MX 1000000
using namespace std;
int D[Max][Max];
int path[Max][Max];
typedef struct Node{ 
	char num[5];
	char name[51];
	char instruct[101];
}Node;
typedef struct{
	Node vex[Max];
	int arcs[Max][Max];
	int vnum,arcnum;
}AMGragh;void menu(){
	cout<<"**********************九江学院*********************"<<end1;
	cout<<"*         1.查看所有景点 *”<<end1;

