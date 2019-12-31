#define _CRT_SECURE_NO_WARNINGS   
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#include"model.h"
#include"global.h"
#include"tool.h"
#include"card_service.h"
#include"card_file.h"

void outputMenu() {
	printf("\n---------菜单---------\n");
	printf("1.添加卡\n");
	printf("2.查询卡\n");
	printf("3.上机\n");
	printf("4.下机\n");
	printf("5.充值\n");
	printf("6.退费\n");
	printf("7.注销卡\n");
	printf("8.修改密码\n");
	printf("9.重新激活卡\n");
	printf("10.显示所有卡信息\n");
	printf("0.退出\n");
	printf("请输入菜单编号（0-8）:");
}

//添加卡
void add() {
	struct tm* stime;
	struct tm* etime;
	struct Card card;
	char newCardName[30] = { "\0" };
	char newCardPwd[15] = { "\0" };
	int namesize = 0, passwordsize = 0;
	printf("---------添加卡---------\n");
	printf("请输入卡号<长度为1-18>：");
	scanf("%s", newCardName);
	namesize = strlen(newCardName);
	printf("请输入密码<长度为1-8>：");
	scanf("%s", newCardPwd);
	passwordsize = strlen(newCardPwd);
	if (namesize > 18 || passwordsize > 8) {
		printf("卡号或密码输入长度超出规定！\n");
		return;
	}	
/*	if (checkcardname(newCardName) == TRUE)         //查重
	{
		printf("该卡已存在，不能重复添加\n");
		return;
	}
*/
	//将输入的卡号和密码保存到卡结构体中
	strcpy(card.aName, newCardName);
	strcpy(card.aPwd, newCardPwd);

	printf("请输入开卡金额<RMB>：");
	//该循环用来解决输入字符(串)后会进入死循环的问题，与main函数中用法相同
	while (scanf("%lf", &card.fBalance) != 1) {
		printf("您输入的开卡金额有误。(请输入整数或小数)\n");
		printf("请重新输入:\n");
		while (getchar() != '\n');
	}
	card.fTotalUse = 0;		//累计使用
	card.nStatus = 0;       //卡状态
	card.nUseCount = 0;     //使用次数
	card.nDel = 0;          //删除标识
	card.tStart = card.tEnd = card.tLast = time(NULL);
	stime = localtime(&card.tStart);
	etime = localtime(&card.tEnd);
	etime->tm_year = stime->tm_year + 1;
	card.tEnd = mktime(etime);

	//将卡结构体信息储存在文件中
	savecard(&card, CARDPATH);
	printf("\n-----添加的卡信息如下-----\n");
	printf("  卡号  ：%s\n  密码  ：%s\n 卡状态 ：%d\n开卡金额：%.2lf\n"
		, card.aName, card.aPwd, card.nStatus, card.fBalance);
}

//查询卡
void query()
{
	int choice = 0;
	int p = 0;
	char aName[18] = { '\0' };
	char tlast[20] = { '\0' };
	Card* ccard = NULL;
	printf("请选择<1.精确查询 2.模糊查询>：");
	while (scanf("%d", &choice) != 1) {	//循环作用与main函数中相同
		printf("您输入的选项有误,请重新输入。\n");
		while (getchar() != '\n')  ;
	}
	switch (choice)
	{
	case 1:
		printf("请输入查询卡号：");
		scanf("%s", aName);
		ccard = querycard(aName);
		if (ccard == NULL)
			printf("\n没有该卡的信息!\n");
		else {
			timeToString(ccard->tLast, tlast);
			printf("\n查询的卡信息：\n");
			printf("    卡号    ：%s\n   卡状态   ：%d\n    余额    ：%g\n累计使用金额：%.2lf\n  累计次数  ：%d\n上次使用时间：%s\n",
				ccard->aName, ccard->nStatus, ccard->fBalance, ccard->fTotalUse, ccard->nUseCount, tlast);
		}
		break;
	case 2:
	{
		printf("请输入查询卡号<长度为1-18>：");
		scanf("%s", aName);
		ccard = querycards(aName, &p);
		if (ccard == NULL || p == 0)
			printf("\n没有该卡的信息\n");
		else
		{
			printf("\n查询到的卡信息：\n");
			for (int k = 0; k < p; k++)
			{
				printf("\n-----卡%d-----\n", k + 1);
				timeToString(ccard[k].tLast, tlast);          //将时间转换为字符串
				printf("    卡号    ：%s\n   卡状态   ：%d\n    余额    ：%.2lf\n累计使用金额：%.2lf\n  累计次数  ：%d\n上次使用时间：%s\n"
					, ccard[k].aName, ccard[k].nStatus, ccard[k].fBalance, ccard[k].fTotalUse, ccard[k].nUseCount, tlast);
			}
			free(ccard);
			ccard = NULL;
		}
	}
	break;
	default:
		printf("您输入的选项有误,请重新输入。\n");
		break;
	}
}

//上机
void login()
{
	Card* acard = NULL;
	char llogin[20] = { '\0' };
	char fcardname[18] = { '\0' };
	char fpassword[8] = { '\0' };
	//接收卡号和密码
	printf("请输入上机卡号：");
	scanf("%s", &fcardname);
	printf("请输入密码：");
	scanf("%s", &fpassword);
	//上机状态更改
	acard = doLogin(fcardname, fpassword);
	if (acard == NULL)
		printf("\n上机失败！\n");
	else
	{
		printf("\n上机成功！\n");
		printf("卡号：%s\n", acard->aName);
		printf("余额：%.2f\n", acard->fBalance);
		timeToString(acard->tLast, llogin);
		printf("上机时间：%s\n", llogin);
	}
}

//下机
void settle() {
	Card* acard = NULL;
	char tlogout[20] = { '\0' };
	char acardname[18] = { '\0' };
	char apassword[8] = { '\0' };
	//接收卡号和密码
	printf("请输入下机卡号：");
	scanf("%s", &acardname);
	printf("请输入密码：");
	scanf("%s", &apassword);
	acard = doSettle(acardname, apassword);       //上机状态更改
	if (acard == NULL)
		printf("\n下机失败!\n");
	else
	{
		printf("卡号：%s\n", acard->aName);
		printf("余额：%.2f\n",acard->fBalance);
		timeToString(acard->tLast, tlogout);
		printf("下机时间：%s\n", tlogout);
		printf("\n下机成功!\n");
	}
}

//充值
void addMoney() {
	Card* acard = NULL;
	double money;
	char fcardname[18] = { '\0' };
	char fpassword[8] = { '\0' };
	printf("请输入卡号<长度为1-18>：");
	scanf("%s", &fcardname);           //接收卡号和密码
	printf("请输入密码<长度为1-8>：");
	scanf("%s", &fpassword);
	printf("请输入充值金额<RMB>：");
	//该循环用来解决输入字符(串)后会进入死循环的问题，与main函数中用法相同
	while (scanf("%lf", &money) != 1) {
		printf("您输入的充值金额有误。(请输入整数或小数)\n");
		printf("请重新输入:\n");
		while (getchar() != '\n');
	}
	acard = doAddMoney(fcardname, fpassword, money);
	if (acard == NULL)
		printf("\n充值失败\n");
	else
	{
		printf("\n充值成功\n");
		printf("卡号：%s\n", acard->aName);
		printf("余额：%.2f\n", acard->fBalance);
	}
}

//退费
void refundMoney() {
	Card* acard = NULL;
	double money;
	char fcardname[18] = { '\0' };
	char fpassword[8] = { '\0' };
	printf("请输入卡号<长度为1-18>：");
	scanf("%s", &fcardname);
	printf("请输入密码<长度为1-8>：");
	scanf("%s", &fpassword);
	printf("请输入退费金额<RMB>：");
	//该循环用来解决输入字符(串)后会进入死循环的问题，与main函数中用法相同
	while (scanf("%lf", &money) != 1) {
		printf("您输入的退费金额有误。(请输入整数或小数)\n");
		printf("请重新输入:\n");
		while (getchar() != '\n');
	}
	acard = doRefunMoney(fcardname, fpassword, money);
	if (acard == NULL)
		printf("\n退费失败\n");
	else
	{
		printf("\n退费成功\n");
		printf("卡号：%s\n", acard->aName);
		printf("余额：%.2f\n", acard->fBalance);
	}
		
}

//注销卡
void annul() {
	Card* acard = NULL;
	int n = 0;
	char fcardname[18] = { '\0' };
	char fpassword[8] = { '\0' };
	printf("请输入卡号<长度为1-18>：");
	scanf("%s", &fcardname);
	printf("请输入密码<长度为1-8>：");
	scanf("%s", &fpassword);

	acard = doAnnul(fcardname, fpassword);
	if (acard == NULL)
		printf("\n注销失败\n");
	else
		printf("\n注销成功\n");
}

//更改密码
void changePwd() {
	Card* acard = NULL;
	char fcardname[18] = { '\0' };
	char fpassword[8] = { '\0' };
	printf("请输入卡号<长度为1-18>：");
	scanf("%s", &fcardname);           //接收卡号和密码
	printf("请输入密码<长度为1-8>：");
	scanf("%s", &fpassword);

	acard = doChangePwd(fcardname, fpassword);
	if (acard == NULL)
		printf("\n更改密码失败\n");
	else
	{
		printf("\n更改密码成功\n");
		printf("卡号：%s\n", acard->aName);
		printf("更改后的密码：%s\n", acard->aPwd);
	}
}

//重新激活卡
void renew()
{
	Card* acard = NULL;
	char tend[20] = { '\0' };
	int n = 0;
	char fcardname[18] = { '\0' };
	char fpassword[8] = { '\0' };
	printf("请输入卡号<长度为1-18>：");
	scanf("%s", &fcardname);
	printf("请输入密码<长度为1-8>：");
	scanf("%s", &fpassword);
	acard = doRenew(fcardname, fpassword);
	if (acard == NULL)
		printf("\n重新激活失败\n");
	else
	{
		printf("\n重新激活成功\n");
		printf("卡号：%s\n", acard->aName);
		timeToString(acard->tEnd, tend);
		printf("卡截止时间已更改为：%s\n", tend);
	}
}

//显示所有卡信息
void allCard() {
	printf("所有的卡信息如下：\n");
	showAll();
}

//退出
void exitApp() {
	freelist();
	printf("按任意键退出系统\n");
	getchar();
}

