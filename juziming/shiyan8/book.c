#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#define B_INFO_URL "E:\\图书信息表.csv"
tyepedef struct Book{
	int id;
	char name[40];
	char auth[20];
	char publish[50];
	struct Book *next;
}Book_info;
struct temp{
	char value[50];
	int max_number;
}T[3],max;
void SetEnum();
void jumpPage(int id);
int Deletelnfo();
int Addlnfo();
int Checklnfo();
int Updatelnfo();
Book_info*ShowBooklnfo(){
	FILE *fp = fopen(B_INFO_URL,"r");
	if(fp==NULL){
		printf("文件打开失败！");
		exit(0);
	}
	fseek(fp,31,SEEK_SET);
	int n = 0,v = 0;
	Book_info *p,*q,*head;
	p=q=(struct Book*)malloc(sizeof(struct Book));
	while(feof(fp)==0){
		v++;
		fscanf(fp,"%d,%s\n",&p->id,&p->name);
		char
	}
}
