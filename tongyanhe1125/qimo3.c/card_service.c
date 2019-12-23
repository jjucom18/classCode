#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"model.h"
#include"global.h"
#include"tool.h"
#include"card_file.h"
#include"card_service.h"

Card cardmessage[100];  //卡信息
lpnode list = NULL;
lpnode head = NULL;

//链表初始化
int initlist()
{
	head = (lpnode)malloc(sizeof(node));
	if (head != NULL)
	{
		head->next = NULL;
		list = head;
		return TRUE;
	}
	return FALSE;
}

//释放链表
void freelist()
{
	lpnode p1;
	if (list != NULL)
	{
		p1 = list->next;
		while (p1 != NULL)
		{
			p1 = p1->next;
			free(p1);
			p1 = NULL;
		}
	}
}

//将文件的卡信息保存到链表中
int putcard()
{
	int k = 0;
	int j;
	Card *fcard = NULL;
	lpnode node1 = NULL;
	lpnode p1 = NULL;
	if (list != NULL)
		freelist();
	initlist();
	k = getcardnum(CARDPATH);  //获取卡数量
	fcard = (Card *)malloc(sizeof(Card)*k);     //动态分配内存
	if (fcard == NULL)
		return FALSE;
	if (readcard(fcard, CARDPATH) == FALSE)      //获取卡信息
	{
		free(fcard);
		fcard = NULL;
		return FALSE;
	}
	for (j = 0, node1 = list; j < k; j++)
	{
		p1 = (lpnode)malloc(sizeof(node));//为节点分配内存
		if (p1 == NULL)                    //分配内存失败，返回FALSE
		{
			free(fcard);
			fcard = NULL;
			return FALSE;
		}
		memset(p1, 0, sizeof(node));      //初始化新空间全部赋值为0
		p1->data = fcard[j];              //将信息保存到节点中
		p1->next = NULL;
		node1->next = p1;                 //将节点添加到链表尾
		node1 = p1;
	}
	free(fcard);
	fcard = NULL;
	return TRUE;
}

//添加卡时查询是否重复
int checkcardname(const char* fcardname)
{
	lpnode node = NULL;
	//获取卡信息
	if (putcard() == FALSE)
		return TRUE;
	node = list->next;
	while (node != NULL)
	{
		if (strcmp(node->data.aName, fcardname) == 0)
			return TRUE;
		node = node->next;
	}
	return FALSE;
}

//精确查询
Card* querycard(const char* bcardname)
{
	lpnode node1 = NULL;

	if (putcard() == FALSE)
		return FALSE;
	node1 = list->next;   //链表头节点指向下一个节点
	while (node1 != NULL)
	{
		if (strcmp(node1->data.aName, bcardname) == 0)
			return &node1->data;
		node1 = node1->next;
	}
	return NULL;
}

//模糊查询
Card* querycards(const char* bcardname, int *p2)
{
	lpnode node1 = NULL;
	Card* fcard = NULL;
	if (putcard() ==  FALSE)
		return FALSE;
	fcard = (Card*)malloc(sizeof(Card));
	if (fcard == NULL)
		return NULL;
	node1 = list->next;
	while (node1 != NULL)
	{
		if (strstr(node1->data.aName, bcardname) != NULL)
		{
			fcard[*p2] = node1->data;
			(*p2)++;
			fcard = (Card *)realloc(fcard, ((*p2) + 1) * sizeof(Card));
		}
		node1 = node1->next;
	}
	return fcard;
}

//上机状态更改
Card* doLogin(const char* fcardname, const char* fpassword)
{
	char llogin[20] = { '\0' };
	lpnode node = NULL;
	//获取卡信息
	if (putcard() == FALSE)
		return NULL;
	node = list->next;
	head = node;
	//判断能否上机
	while (node != NULL)
	{
		if (strcmp(node->data.aName, fcardname) == 0 
			&& strcmp(node->data.aPwd, fpassword) == 0)
		{   //状态确认
			if (node->data.nStatus == 1)           
			{
				printf("\n该卡已上机\n");
				return NULL;
			}
			if (node->data.nStatus == 2)
			{
				printf("\n该卡已注销\n若想继续使用请重新激活\n");
				return NULL;
			}
			node->data.tLast = time(NULL);
			if (node->data.tLast - node->data.tEnd >= 0)
			{
				printf("\n该卡已过期\n若需要退款请直接注销卡\n若想继续使用请重新激活\n");
				return NULL;
			}
			if (node->data.fBalance <= 0)          //余额确认
			{
				printf("\n该卡余额不足\n");
				return NULL;
			}
			//更新链表卡信息
			node->data.nStatus = 1;
			node->data.nUseCount++;
			node->data.tLast = time(NULL);
			//更新卡文件信息
			if (renewcard(head, CARDPATH) == TRUE)
				return &node->data;
		}
		node = node->next;
	}
	printf("\n卡号或密码输入错误\n");
	return NULL;
}

//下机状态更改
Card* doSettle(const char* acardname, const char* apassword)
{
	char tlogout[20] = { '\0' };
	lpnode node = NULL;
	time_t logintime;
	double money = 0;
	//获取卡信息
	if (putcard() == FALSE)
		return NULL;
	node = list->next;
	head = node;
	//判断能否下机
	while (node != NULL)
	{
		if (strcmp(node->data.aName, acardname) == 0 
			&& strcmp(node->data.aPwd, apassword) == 0)
		{   //状态确认
			if (node->data.nStatus == 0)           
			{
				printf("\n该卡未上机\n");
				return NULL;
			}
			else if (node->data.nStatus == 2)
			{
				printf("\n该卡已注销\n若想继续使用请重新激活\n");
				return NULL;
			}
			node->data.tLast = time(NULL);
			if (node->data.tLast - node->data.tEnd >= 0)
			{
				printf("\n该卡已过期\n若需要退款请直接注销卡\n若想继续使用请重新激活\n");
				return NULL;
			}
			//更新链表卡信息
			node->data.nStatus = 0;
			logintime = node->data.tLast;
			node->data.tLast = time(NULL);
			money = consume(logintime, node->data.tLast);
			printf("\n此次消费金额：%.2lf\n",money);
			//更新卡文件信息
			if (renewcard(head, CARDPATH) == TRUE)
				return &node->data;
		}
		node = node->next;
	}
	printf("\n卡号或密码输入错误\n");
	return NULL;
}

//计算消费金额
double consume(time_t tstar, time_t tend)
{
	time_t sec = 0;
	time_t min = 0;
	time_t hour = 0;
	double money = 0;
	sec = tend - tstar;   //秒
	min = sec / 60;       //分
	hour = sec / 60;

	money = hour * CHARGE;

	return money;
}

//充值
Card* doAddMoney(const char* fcardname, const char* fpassword, double money)
{
	lpnode node = NULL;
	//获取卡信息
	if (putcard() == NULL)
		return NULL;
	node = list->next;
	head = node;
	while (node != NULL)                             //判断账号密码是否输入正确
	{
		if (strcmp(node->data.aName, fcardname) == 0 
			&& strcmp(node->data.aPwd, fpassword) == 0)
		{   //状态确认
			if (node->data.nStatus == 2)
			{
				printf("\n该卡已注销\n若想继续使用请重新激活\n");
				return NULL;
			}
			node->data.tLast = time(NULL);
			if (node->data.tLast - node->data.tEnd >= 0)
			{
				printf("\n该卡已过期\n若需要退款请直接注销卡\n若想继续使用请重新激活\n");
				return NULL;
			}
			//更新链表卡信息
			node->data.fBalance = node->data.fBalance + money;
			//更新卡文件信息
			if (renewcard(head, CARDPATH) == TRUE)
				return &node->data;
		}
		node = node->next;
	}
	printf("\n卡号或密码输入错误\n");
	return NULL;
}

//退费
Card* doRefunMoney(const char* fcardname, const char* fpassword, double money)
{
	lpnode node = NULL;
	//获取卡信息
	if (putcard() == NULL)
		return NULL;
	node = list->next;
	head = node;
	while (node != NULL)                            //判断账号密码是否输入正确
	{
		if (strcmp(node->data.aName, fcardname) == 0 
			&& strcmp(node->data.aPwd, fpassword) == 0)
		{   //状态确认
			if (node->data.nStatus== 2)          
			{
				printf("\n该卡已注销\n");
				return NULL;
			}
			node->data.tLast = time(NULL);
			if (node->data.tLast - node->data.tEnd >= 0)
			{
				printf("\n该卡已过期\n若需要退款请直接注销卡\n若想继续使用请重新激活\n");
				return NULL;
			}
			if (node->data.fBalance < money)          //余额确认
			{
				printf("\n该卡余额不足\n");
				return NULL;
			}
			//更新链表卡信息
			node->data.fBalance = node->data.fBalance - money;
			//更新卡文件信息
			if (renewcard(head, CARDPATH) == TRUE)
				return &node->data;
		}
		node = node->next;
	}
	printf("\n卡号或密码输入错误\n");
	return NULL;
}

//注销卡
Card* doAnnul(const char* fcardname, const char* fpassword)
{
	lpnode node = NULL;
	//获取卡信息
	if (putcard() == NULL)
		return NULL;
	node = list->next;
	head = node;
	while (node != NULL)                           //判断账号密码是否输入正确
	{
		if (strcmp(node->data.aName, fcardname) == 0
			&& strcmp(node->data.aPwd, fpassword) == 0)
		{   //状态确认
			if (node->data.nStatus == 2)           
			{
				printf("\n该卡已注销\n");
				return NULL;
			}
			node->data.tLast = time(NULL);
			if (node->data.tLast - node->data.tEnd >= 0)
			{
				printf("\n该卡已过期\n若需要退款请直接注销卡\n");
				return NULL;
			}
			printf("\n该退余额：%.2lf\n",node->data.fBalance);
			//更新链表卡信息
			node->data.fBalance = 0.00;
			node->data.nStatus = 2;
			//更新卡文件信息
			if (renewcard(head, CARDPATH) == TRUE)
				return &node->data;
		}
		node = node->next;
	}
	printf("\n卡号或密码输入错误\n");
	return NULL;
}

//更改密码
Card* doChangePwd(const char* fcardname, const char* fpassword)
{
	lpnode node = NULL;
	char newPwd[8] = { '\0' };
	int passwordsize;
	//获取卡信息
	if (FALSE == putcard())
		return NULL;
	node = list->next;
	head = node;
	while (node != NULL)
	{   //判断账号密码是否输入正确
		if (strcmp(node->data.aName, fcardname) == 0
			&& strcmp(node->data.aPwd, fpassword) == 0)
		{   //状态确认
			if (node->data.nStatus == 2)
			{
				printf("\n该卡已注销\n若想继续使用请重新激活\n");
				return NULL;
			}
			node->data.tLast = time(NULL);
			if (node->data.tLast - node->data.tEnd >= 0)
			{
				printf("\n该卡已过期\n若需要退款请直接注销卡\n若想继续使用请重新激活\n");
				return NULL;
			}

			printf("\n请输入新密码<长度为1-8>：");
			scanf("%s", &newPwd);
			passwordsize = strlen(newPwd);
			if (passwordsize > 8) {
				printf("密码输入长度超出规定！\n");
				return;
			}
			//更新链表卡信息
			strcpy(node->data.aPwd, newPwd);
			//更新卡文件信息
			if (renewcard(head, CARDPATH ) == TRUE)
				return &node->data;
		}
		node = node->next;
	}
	printf("\n卡号或密码输入错误\n");
	return NULL;
}

//重新激活卡
Card* doRenew(const char* fcardname, const char* fpassword)
{
	struct tm* stime;
	struct tm* etime;
	lpnode node = NULL;
	//获取卡信息
	if (FALSE == putcard())
		return NULL;
	node = list->next;
	head = node;
	while (node != NULL)                           
	{   //判断账号密码是否输入正确
		if (strcmp(node->data.aName, fcardname) == 0 
			&& strcmp(node->data.aPwd, fpassword) == 0)
		{
			node->data.tLast = node->data.tStart = time(NULL);
			if ((node->data.tLast - node->data.tEnd < 0))
			{
				if (node->data.nStatus == 0 || node->data.nStatus == 1)
				{
					printf("\n该卡仍能使用，不需要重新激活\n");
					return NULL;
				}
			}
			//更新链表卡信息
			node->data.tEnd = time(NULL);
			node->data.nStatus = 0;
			stime = localtime(&node->data.tStart);
			etime = localtime(&node->data.tEnd);
			etime->tm_year = stime->tm_year + 1;
			node->data.tEnd = mktime(etime);

			//更新卡文件信息
			if (renewcard(head, CARDPATH) == TRUE)
				return &node->data;
		}
		node = node->next;
	}
	printf("\n卡号或密码输入错误\n");
	return NULL;
}

//输出所有卡信息
void showAll() {
	char stime[20] = { '\0' };     //开卡时间
	char etime[20] = { '\0' };     //截止时间
	char ltime[20] = { '\0' };     //最后使用时间
	lpnode node = NULL;
	int ncount = 0;
	//获取卡信息
	if (putcard() == NULL)
		return ;
	node = list->next;
	printf("卡号\t密码\t状态\t开卡时间\t    截止时间\t\t累计金额  最后使用时间      使用次数  余额     删除标识\n");
	while (node != NULL) {
		//将时间转换为字符串
		timeToString(node->data.tStart, stime);
		timeToString(node->data.tEnd, etime);
		timeToString(node->data.tLast, ltime);
		printf("%s\t%s\t%d\t%s    %s\t%.2lf\t  %s  %d\t      %.2lf\t%  d\n"
			, node->data.aName, node->data.aPwd, node->data.nStatus, stime, etime,
			node->data.fTotalUse, ltime, node->data.nUseCount, node->data.fBalance, node->data.nDel);
		node = node->next;
		ncount++;
	}
}

