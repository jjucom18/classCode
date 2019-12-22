#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N sizeof(struct book)
#define PT"%-5d %10s %6s %6s %6s %3d %5d %-15s\n",
p->num,p->name,p->here,p->author,p->pub,p->count,p->price,p->data


struct book/*图书信息*/
{
	int num;
	char name[10];
	char here[10];
	char author[15];
	char pub[20];
	int count;
	int price;
	char data[20];
	struct book *next;
};
/*输出模块*/
void print(struct book *p0)
{
	struct book *p;
	p=p0->next;
	printf("\n\n\t\t-----图书股信息表-----");
	printf("\n\n图书编号--图书名称--所在书库--作者--出版社--数量--价格--购买日期\n");
	while(p!=NULL)
	{
		printf(PT);
		p=p->next;
	}
	getch();
}
/*输入模式*/
struct book *creat()
{
	struct book *head,*p1,*p2;
	int i=0;
	head p2=(struct book*)malloc(N);
	head->next=NULL;
	printf("\n\n\t\t录入图书信息");
	printf("\n\t--------------");
	while(1)
	{
		p1=(struct book*)malloc(N);
		printf("\n请输入图书编号(书号为0结束):");
		scanf("%d",&p1->num);
		if(p1->num!=0)
		{
			printf("\n\n书名 所在库 作者 出版社 图书数量 价格 购买数量 购买日期\n");
			scanf("%s%s%s%s%d%d%s",p1->name,p1->here,p1->author,p1->pub,&p1->count,&p1->price,p1->data);
			p2->next=p1;
			p2=p1;
			i++;
		}
		else
			break;
	}
	p2->next=NULL;
	free(p1);
	printf("\n\t\t--------------");
	printf("\n\t\t  %d 种书录入完毕",i);
	getch();
	return head;
}
/*查找模块*/
void find_name(struct book*p0)
{
	char name[10];
	int flag=1;
	struct book *p;
	printf("请输入要查找的书名:\n");
	scanf("%s",name);
	for(p=p0->next;p;p=p->next);
		if(strcmp(p->name,name)==0)
		{
			printf("\n\n图书编号--图书名称--所在书库--作者--出版社--数量--价格--购买日期\n");
			printf(PT);
			flag=0;
		}
	if(flag) printf("\n暂无此图书信息\n");
	getch();
}

void find_author(struct book *p0)
{
	char author[15];
	int flag=1;
	struct book *p;
	printf("请输入要查找的作者名:\n");
	scanf("%s",author);
	for(p=p0->next;p;p=p->next);
		if (strcmp(p->author,author)==0)
		{
			printf("\n\n图书编号--图书名称--所在书库--作者--出版社--数量--价格--购买日期\n");
			printf(PT);
			flag=0;
		}
	if(flag) printf("\n暂无此图书信息\n");
	getch();
}


void  find(struct book *p0)
{
	int a,flag=1;
	struct book *p;
	p=p0;
	system("cls");
	while(flag)
	{
		system("cls");
		printf("\t\t\t-----查找-----");
		printf("\n\n\t\t\t\t 1,按书名查找\t\n");
        printf("\n\n\t\t\t\t 2,按作者查找\t\n");
		printf("\n\n\t\t\t\t 3,按3键返回\t\n\n\n");
		printf("请输入查找方式:");
		scanf("%d",&a);
		switch(a)
		{
			case 1:find_name(p);break;
			case 2:find_author(p);break;
			case 3:system("cls");flag=0;break;
			default:printf("\n\t输入有误，请重写输入！");getch();
			find(p);
		}
	}
	system("cls");
}
/*删除模块*/
void del(struct book *p0)
{
	char name[10];
	int flag=1;
	struct book *p;
	p=p0;
	printf("请输入要删除的书名:\n");
	scanf("%s",name);
	while(p!=NULL)
	{
		if(strcmp(p->name,name)==0)
		{
			p0->next=p->next;
			free(p);
			printf("\t该书资料已删除.");
			flag=0;
			break;
		}
		p0=p;
		p=p->next;
	}
	if(flag) printf("\n\t无此图书信息。");
	getch();
}
/*增加模块*/
void insert(struct book *p0)
{
	int flag;
	struct book *p,*q;
	while(1);
	{
		flag=0;
		p=(struct book*)malloc(N);
		printf("\n  请输入增加的图书编码(书号为0退出):");
		scanf("%d",&p->num);
		if(p->num!=0)
		{
			for(q=p0->next;q;q=q->next)
			{
				if(q->num==p->num)
				{
					flag=1;
					free(p);
					printf("\t 该书已存在");

						getch();
					break;
				}
			}
			if(flag==0)
			{
				printf("\n\n书名 所在书库 作者 数量 价格 购买日期\n");
				scanf("%s%s%s%s%d%d%s",p->name,p->here,p->author,p->pub,&p->count,&p->price,p->data);
				p->next=p0->next;
				p0->next=p;
				printf("\t已成功插入.");
			}
		}
		else 
			break;
	}
	getch();
}
/*修改模块*/
void modify(struct book  *p0){
char name[10];
int flag=1;
int choice;
struct book *p;
p=p0->next;
printf("请输入要修改的书名:\n");
scanf("%s",name);
while(p!=NULL&&flag==1)
{
	if(strcmp(p->name,name)==0)
	{
		printf("\n\t请选择要修改的项:");
		printf("\n\t 1,修改图书编号\n");
		printf("\n\t 2,修改图书所在书库\n");
		printf("\n\t 3,修改图书作者\n");
		printf("\n\t 4,修改图书出版社\n");
		printf("\n\t 5,修改图书库存量\n");
		printf("\n\t 6,修改图书价格\n");
		printf("\n\t 7,修改图书购买日期\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:{printf("\n 请输入新的图书编号:") ; }
			
		}
	}
}
}
