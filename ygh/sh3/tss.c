#include "sort.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define MAXSIZE 20

int main()

{
        SeqList *L;
	L = Init_SeqList();
	int i=0;
    Bubble_Sort(L);
    D_InserSort(L);
	Select_Sort(L);
	ShellSort(L);
}
