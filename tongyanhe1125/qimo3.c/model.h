#ifndef MODEL_H
#define MODEL_H
#include<stdio.h>
#include<time.h>
typedef struct Card
{
	char aName[18];         // 卡号
	char aPwd[8];           // 密码
	int  nStatus;           // 卡状态(0-未上机；1-正在上机；2-已注销)
	time_t tStart;          // 开卡时间
	time_t tEnd;            // 卡的截止时间 
	double fTotalUse;        // 累计金额
	time_t tLast;           // 最后使用时间
	int nUseCount;          // 使用次数
	double fBalance;         // 余额
	int nDel;               // 删除标识 0-未删除,1-删除
}Card;

typedef struct node
{
	Card data;
	struct node *next;
}node, *lpnode;

#endif

