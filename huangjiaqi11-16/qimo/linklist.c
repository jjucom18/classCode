#include "linklist.h"
//根据房间的价格大小来进行排序
void bubble_price(linklist *head){
	linklist *temp = head;
	count(head);
	printf("请输入酒店的客数：\n");
	int m;
	scanf("%d",&m);
	for(int i = 0;i < m - 1;i++ ){
		for(int j = 0;j < m -i -1;j++){
			linklist *tmp;
			tmp = (linklist *)malloc(sizeof(linklist));
			if(temp->data.price > temp->next->data.price){
				tmp->data = temp->data;
				temp->data = temp->next->data;
				temp->next->data = tmp->data;
				free(tmp);
			}
			temp = temp->next;
		}
	}

}
//根据房号来进行查询并返回id
int findByname(linklist *head){
	linklist *temp = head;
	int i;
	char names[20];
	printf("请输入要查询房号：\n");
	scanf("%s",names);
	//printf("%s\n",names);
	while(temp->next){
		temp = temp->next;
		i = strcmp(temp->data.name,names);
		if(i == 0){
			printf("该房间的房号:%d\n",temp->data.id);
			return 1;
		}
		else{
			printf("没有该房间！\n");
		}
		
	}
	return -1;
}


linklist *Init(){
	linklist *head;//单链表必须设定一个头指针；还有一个指向头指针的指针进行头指针进行遍历
	head = (linklist *)malloc(sizeof(linklist));
	head->next = NULL;
	head->count = 0;//
	if(head->next == NULL){
		printf("初始化成功！\n");
	}
	return head;
}

int seacher(linklist *head)
{
	int b;
	linklist *temp = head;
	printf("请输入你要查找的房间：\n");
	scanf("%d",&b);
	while(temp->next){
		temp = temp->next;
		if(temp->data.id == b){
			printf("该房间的房号：%s\n",temp->data.name);
			return temp->data.id;
		}
	}
	return -1;
}

linklist *change(linklist *head)
{
	int i;
	int j;
	linklist * temp;
	printf("请输入所要修改的房间房号：\n");
	scanf("%d",&j);
	while(temp->next){
		if(temp->data.id == j){
			printf("请输入你要更改的信息类型：\n");
			printf("1:id                 2:name\n");
			printf("3:DATA(预定日期)\n");	
			printf("4:info               5:publish\n");
			printf("6:price                          \n");
			scanf("%d",&i);
			switch(i){
				case 1:
					printf("id更改为：\n");
					scanf("%d",&(temp->data.id));
					break;
				case 2:
					printf("顾客更改为：\n");
					scanf("%s",temp->data.name);
					break;
				case 3:
					printf("房号为：\n");
					scanf("%s",temp->data.publish);
					break;
				case 4:
					printf("价格更改为:\n");
					scanf("%lf",&(temp->data.price));

				default:
					printf("输入的选择有误！\n");
			}
			return temp;
		}
		else{
			printf("编号输入错误！\n");
		}
	} 

}

linklist *insert(linklist *head)
{
	int i;
	linklist *temp = head;
	printf("请输入添加多少间房：\n");
	scanf("%d",&i);
	for(int j = 0;j < i;j++){
	linklist *c;
	c = (linklist *)malloc(sizeof(linklist));
	head->count++;//计数器加一
	printf("请输入房间的id：\n");
	scanf("%d",&(c->data.id));
	while(temp->next){
		if(temp->data.id == c->data.id){
			printf("该编号已存在！请重新输入编号！\n");
			scanf("%d",&(c->data.id));
		}
		break;
	}
	printf("请输入该房间的可预定时间：\n");
	scanf("%d",&(c->data.DATA.year));
	scanf("%d",&(c->data.DATA.month));
	scanf("%d",&(c->data.DATA.day));
	printf("请输入房间相关简介：\n");
	scanf("%s",c->data.info);
	printf("请输入房间的价格：\n");
	scanf("%lf",&(c->data.price));
	c->next = temp->next;
	temp->next = c;
	temp = temp->next;
	}
	return temp;
}
void display(linklist *head)
{
	linklist *temp = head;
	printf("*********酒店内所有的客房及其相关信息**********\n");
	while(temp->next){
		temp = temp->next;
		printf("房间的id为：%d\n",temp->data.id);
		printf("可预定时间为：%d  年 %d 月 %d 日 \n",temp->data.DATA.year,temp->data.DATA.month,temp->data.DATA.day);
		//printf("房间为：%s\n",temp->data.name);
		printf("房间的简介为：%s\n",temp->data.info);
		printf("房间的单价为：%lf\n",temp->data.price);

	}
	printf("\n");
}
int dle(linklist *head)
{
	int i;
	linklist *temp = head;//创建一个指向头指针的指针，进行遍历
	printf("请输入你要删除的房间的id：\n");
	scanf("%d",&i);
		while(temp->next){
			if(temp->next->data.id == i){
				linklist *p;
				p = (linklist *)malloc(sizeof(linklist));
				p = temp->next;
				temp->next = temp->next->next;
				free(p);
				head->count--;
				return 1;
			}
			temp = temp->next;
		}
		linklist *p;
		p = (linklist *)malloc(sizeof(linklist));
		p = temp->next;
		temp->next = temp->next->next;
		free(p);
		head->count--;
		return -1;//手动释放c指针以免造成内存泄露
} 
void count (linklist *head)
{
	printf("一共有%d 几间房\n",head->count);
}
