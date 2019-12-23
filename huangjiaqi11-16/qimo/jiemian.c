#include "jiemian.h"

void menu(linklist *head,customer *tip){
	int i;
	printf("-------------维也纳大酒店欢迎您--------------\n");
	printf("----------------------------------------------\n");
	printf("1：前台                            2：顾客\n");
	printf("------------------------------------------------\n");
	printf("-----------请输入你对应的身份名称--------------\n");
	scanf("%d",&i);
	switch(i){
		case 1:
			manager(head,tip);
			break;
		case 2:
			user(head,tip);
			break;
		default:
			printf("选择有误！\n");
		} 
} 
void manager(linklist *head,customer *tip){
			int j;
			int mima;
			int m;
			m = 123456;
			printf("请输入前台密码：\n");
			scanf("%d",&mima);
			if(mima == m){
			printf("------------------前台--------------\n");
			printf("1 ：添加客房               \n");
			printf("2 ：按价格排序             3：计算客房总数\n");
			printf("4 ：删除指定编号客房       \n");
			printf("5 ：按id进行查找\n         ");
			printf("6 ：修改指定相关信息       7：查看客房相关信息\n");
			printf("8 ：返回上一界面\n");
			printf("请输入你的选择");
			scanf("%d",&j);
			switch(j){
				case 1:
					insert(head);
					manager1(head,tip);
					break;
				case 2:
					bubble_price(head);
					manager1(head,tip);
					break;
				case 3:
					count(head);
					manager1(head,tip);
					break;
				case 4:
					dle(head);
					manager1(head,tip);
					break;
				case 5:
					seacher(head);
					manager1(head,tip);
					break;
				case 6:
					change(head);
					manager1(head,tip);
					break;
				case 7:
					display(head);
					manager1(head,tip);
					break;
				case 8:
					menu(head,tip);
					break;
				default:
					printf("输入选项错误！\n");
				}
			}
		} 

void user(linklist *head,customer *tip){
				int k;
				printf("-------------顾客--------------\n");
				printf("1：查找客房                2：预定房间\n");
				printf("3：退房                    4：查看已顶房间\n");
				printf("5：返回上一层\n");
				printf("请输入你的选择\n");
				scanf("%d",&k);
				switch(k){
					case 1:
						findByname(head);
						user(head,tip);
						break;
					case 2:
						push(head,tip);
						user(head,tip);
						break;
					case 3:
						pop(head,tip);
						user(head,tip);
						break;
					case 4:
						displaycustomer(tip);
						user(head,tip);
						break;
					case 5:
						menu(head,tip);
						break;
					default:
						printf("选择错误！\n");
				}
			}


void manager1(linklist *head,customer *tip){
			int j;
			int mima;
			printf("--------------前台------------\n");
			printf("1：添加客房              ");
			printf("2：按价格排序             3：计算房间总数\n");
			printf("4：删除指定编号房间       5：按id进行查找 \n");
			printf("6：修改指定客房相关信息   7：查看全部房间相关信息\n");
			printf("8：返回上一界面\n");
			printf("请输入你的选择");
			scanf("%d",&j);
			switch(j){
				case 1:
					insert(head);
					manager1(head,tip);
					break;
				case 2:
					bubble_price(head);
					manager1(head,tip);
					break;
				case 3:
					count(head);
					manager1(head,tip);
					break;
				case 4:
					dle(head);
					manager1(head,tip);
					break;
				case 5:
					seacher(head);
					manager1(head,tip);
					break;
				case 6:
					change(head);
					manager1(head,tip);
					break;
				case 7:
					display(head);
					manager1(head,tip);
					break;
				case 8:
					menu(head,tip);
					break;
				default:
					printf("输入选项错误！\n");
				}
			}
