#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"model.h"
#include"global.h"
#include"tool.h"
#include"card_file.h"
#include"card_service.h"

Card analyzecard(char* bcup);

int savecard(const Card* fcard, const char* fpath)
{
	FILE* fp = NULL;
	char stime[20] = { '\0' };     //开卡时间
	char etime[20] = { '\0' };     //截止时间
	char ltime[20] = { '\0' };     //最后使用时间
	//打开文件
	if ((fp = fopen(fpath, "a")) == NULL)
		if ((fp = fopen(fpath, "r+")) == NULL)
		{
			printf("文件打开失败。\n");
			return FALSE;
		}
	//将时间转换为字符串
	timeToString(fcard->tStart, stime);
	timeToString(fcard->tEnd, etime);
	timeToString(fcard->tLast, ltime);
	//写入文件
	fprintf(fp, "%s##%s##%d##%s##%s##%.2lf##%s##%d##%.2lf##%d\n"
		, fcard->aName, fcard->aPwd, fcard->nStatus,stime, etime, 
		fcard->fTotalUse, ltime, fcard->nUseCount, fcard->fBalance, fcard->nDel);
	//关闭文件
	fclose(fp);

	return TRUE;
}

//读取卡文件
int readcard(Card* fcard, const char* fpath)
{
	FILE* fp = NULL;
	char  acup[256] = { 0 };
	int i = 0;
	//打开文件
	if ((fp = fopen(fpath, "r")) == NULL)
	{
		printf("文件打开失败。\n");
		return FALSE;
	}
	//读取文件
	while (!feof(fp))
	{
		memset(acup, 0, 256);   //清空数组
		if (fgets(acup, 256, fp) != NULL)
		{
			if (strlen(acup) > 0)
			{
				fcard[i] = analyzecard(acup);
				i++;
			}
		}
	}
	//关闭文件
	fclose(fp);

	return TRUE;
}

Card analyzecard(char* bcup)
{
	Card icard;
	const char *separative = "##";   //字符串中的分隔符
	char* cup = NULL;
	char* app = NULL;
	char flag[10][20] = { '\0' };       //保存分割之后的字符串
	int count = 0;
	cup = bcup;     //cup为解析字符串

	while ((app = strtok(cup, separative)) != NULL)
	{
		strcpy(flag[count], app);
		cup = NULL;
		count++;
	}
	strcpy(icard.aName, flag[0]);
	strcpy(icard.aPwd, flag[1]);
	icard.nStatus = atoi(flag[2]);
	icard.tStart = stringToTime(flag[3]);
	icard.tEnd= stringToTime(flag[4]);
	icard.fTotalUse = atof(flag[5]);
	icard.tLast = stringToTime(flag[6]);
	icard.nUseCount = atoi(flag[7]);
	icard.fBalance = atof(flag[8]);
	icard.nDel = atoi(flag[9]);

	return icard;
}

int getcardnum(const char* fpath)
{
	FILE* fp = NULL;
	char  acup[256] = { '\0' };
	int k = 0;
	//打开文件
	fp = fopen(fpath, "r");
	if (fp == NULL)
		return FALSE;
	//读取文件
	while (!feof(fp))
	{
		//初始化
		memset(acup, 0, 256);
		if (fgets(acup, 256, fp) != NULL)
		{
			if (strlen(acup) > 0)
			{
				k++;
			}
		}
	}
	fclose(fp);

	return k;
}

int renewcard(lpnode node, const char* fpath)
{
	FILE* fp = NULL;

	char acup[256] = { '0' };
	char startime[20] = { '0' };            //开卡时间
	char endime[20] = { '0' };              //卡的截止时间
	char lasttimeime[20] = { '0' };         //最后使用时间

	int fline = 0;
	long fpos = 0;

	fp = fopen(fpath, "w");
	if (fp == NULL)
		return FALSE;

	while (node != NULL)
	{
		timeToString(node->data.tStart, startime);
		timeToString(node->data.tEnd, endime);
		timeToString(node->data.tLast, lasttimeime);

		fprintf(fp, "%s##%s##%d##%s##%s##%.2lf##%s##%d##%.2lf##%d\n"
			, node->data.aName, node->data.aPwd, node->data.nStatus,
			startime, endime, node->data.fTotalUse, lasttimeime,
			node->data.nUseCount, node->data.fBalance, node->data.nDel);            //将数据写入文件
		node = node->next;
	}

	fclose(fp);
	return TRUE;
}

