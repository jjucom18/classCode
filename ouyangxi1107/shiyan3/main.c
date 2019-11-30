#include "File.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define MAXSIZE 20

int main()

{
        SeqList *L;
	L = Init_SeqList();
	int i=0;
	printf("L的地址：%p\n",L);
	while(L->date[i])
	{
		printf("L->date[%d]的地址:%p\n",i,&L->date[i]);
		i++;
	}
	Menu( L );
}
