#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<stdio.h>

void timeToString(time_t t, char* pBuf)
{
	struct tm *timeinfo;

	timeinfo = localtime(&t);
	strftime(pBuf, 20, "%Y-%m-%d %H:%M", timeinfo);
}

time_t  stringToTime(char* pTime)
{
	struct tm tml;
	time_t   time1;

	sscanf(pTime, "%d-%d-%d %d:%d", &tml.tm_year, &tml.tm_mon,
		&tml.tm_mday, &tml.tm_hour, &tml.tm_min);

	tml.tm_year -= 1900;  //年份为从1900年开始
	tml.tm_mon -= 1;      //月份为1^11
	tml.tm_sec = 0;
	tml.tm_isdst -= -1;

	time1 = mktime(&tml);

	return time1;
}

