nclude <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 
#include <windows.h> 
#include <winbase.h> 
#define MAXSIZE 5000 
#define TRUE 1 
#define FALSE 0 
typedef int BOOL; 
typedef struct{ 
	int key; 
} RedType; 
typedef struct LinkList{ 
	RedType r[MAXSIZE+1]; 
	int Length; 
} LinkList; 
int RandArray[MAXSIZE+1]; 
void RandomNum(){ 
	int i; 
	srand(2000); 
	for (i = 1; i <= MAXSIZE; i++) 
		RandArray[i] = (int)rand(); } 
		void InitLinkList(LinkList *L){ 
			int i; 
			memset(L, 0, sizeof(LinkList)); 
			RandomNum(); 
			for (i = 1; i <= MAXSIZE; i++) 
				L->r[i].key = RandArray[i]; 
			L->Length = i; 
		} 
bool LT(int i, int j, int *CmpNum){ 
	(*CmpNum)++; 
	if (i < j) 
		return TRUE; 
	else 
		return FALSE; 
} 
void Display(LinkList *L){ 
	FILE *f; 
	int i; 
	if ((f = fopen("SortRes.txt", "w")) == NULL){ 
		printf("can't open file\n"); 
		exit(0); 
	} 
	for (i = 0; i < L->Length; i++) 
		fprintf(f, "%d\n", L->r[i].key); 
	fclose(f); 
} 
//希尔排序 
//void ShellInsert(LinkList *L, int dk, int *CmpNum, int *ChgNum){ 
//int i, j; 
//RedType Temp; 
//for (i = dk; i < L->Length; i++){ 
//if (LT(L->r[i].key, L->r[i - dk].key, CmpNum)){ 
//memcpy(&Temp, &L->r[i], sizeof(RedType)); 
//for (j = i - dk; j >= 0 && LT(Temp.key, L->r[j].key, CmpNum); j -= dk){ 
//(*ChgNum)++; 
//memcpy(&L->r[j + dk], &L->r[j], sizeof(RedType)); 
//} 
//memcpy(&L->r[j + dk], &Temp, sizeof(RedType)); 
//} 
//} 
//} 
//void ShellSort(LinkList *L, int dlta[], int t, int *CmpNum, int *ChgNum){ 
//int k; 
//for (k = 0; k < t; k++) 
//ShellInsert(L, dlta[k], CmpNum, ChgNum); } 
////快速排序 
//int Partition(LinkList *L, int low, int high, int *CmpNum, int *ChgNum){ 
//RedType Temp; 
//int PivotKey; 
//memcpy(&Temp, &L->r[low], sizeof(RedType)); 
//PivotKey = L->r[low].key; 
//while (low < high){ 
//while (low < high && L->r[high].key >= PivotKey){ 
//high--; 
//(*CmpNum)++; 
//} 
//(*ChgNum)++; 
//memcpy(&L->r[low], &L->r[high], sizeof(RedType)); 
//while (low < high && L->r[low].key <= PivotKey){ 
//low++; 
//(*CmpNum)++; 
//} 
//(*ChgNum)++; 
//memcpy(&L->r[high], &L->r[low], sizeof(RedType)); 
//} 
//memcpy(&L->r[low], &Temp, sizeof(RedType)); 
//return low; 
//} 
//void QSort(LinkList *L, int low, int high, int *CmpNum, int *ChgNum){ 
//int PivotLoc = 0; 
//if (low < high){ 
//PivotLoc = Partition(L, low, high, CmpNum, ChgNum); 
//QSort(L, low, PivotLoc - 1, CmpNum, ChgNum); 
//QSort(L, PivotLoc + 1, high, CmpNum, ChgNum); 
//} 
//} 
//void QuickSort(LinkList *L, int *CmpNum, int *ChgNum){ 
//QSort(L, 0, L->Length - 1, CmpNum, ChgNum); } 
////堆排序 
//void HeapAdjust(LinkList *L, int s, int m, int *CmpNum, int *ChgNum){ 
//RedType Temp; 
//int j = 0; 
//s++; 
//memcpy(&Temp, &L->r[s - 1], sizeof(RedType)); 
//for (j = 2 * s; j <= m; j *= 2){ 
//if (j < m && LT(L->r[j - 1].key, L->r[j].key, CmpNum)) 
//++j; 
//if (!LT(Temp.key, L->r[j - 1].key, CmpNum)) 
//break; 
//(*ChgNum)++; 
//memcpy(&L->r[s - 1], &L->r[j - 1], sizeof(RedType)); 
//s = j; 
//} 
//memcpy(&L->r[s - 1], &Temp, sizeof(RedType)); } 
//void HeapSort(LinkList *L, int *CmpNum, int *ChgNum){ 
//int i = 0; 
//RedType Temp; 
//for (i = L->Length / 2-1; i >= 0; i--) 
//HeapAdjust(L, i, L->Length, CmpNum, ChgNum); 
//for (i = L->Length; i > 1; i--){ 
//memcpy(&Temp, &L->r[0], sizeof(RedType)); 
//(*ChgNum)++; 
//memcpy(&L->r[0], &L->r[i - 1], sizeof(RedType)); 
//memcpy(&L->r[i - 1], &Temp, sizeof(RedType)); 
//HeapAdjust(L, 0, i - 1, CmpNum, ChgNum); 
//} 
//} 
////冒泡排序 
//void BubbleSort(LinkList *L, int *CmpNum, int *ChgNum){ 
//int i, j; 
//RedType temp; 
//for (i = 1; i <= MAXSIZE; i++){ 
//for (j = 1; j <= MAXSIZE - i; j++){ 
//if (!LT(L->r[j].key, L->r[j + 1].key, CmpNum)){ 
//(*ChgNum)++; 
//memcpy(&temp, &L->r[j], sizeof(RedType)); 
//memcpy(&L->r[j], &L->r[j + 1], sizeof(RedType)); 
//memcpy(&L->r[j + 1], &temp, sizeof(RedType)); 
//} 
//} 
//} 
//} 
////选择排序 
//int SelectMinKey(LinkList *L, int k, int *CmpNum){ 
//int Min = k; 
//for (; k < L->Length; k++){ 
//if (!LT(L->r[Min].key, L->r[k].key, CmpNum)) 
//Min = k; 
//} 
//return Min; 
//} 
//void SelSort(LinkList *L, int *CmpNum, int *ChgNum){ 
//int i, j; 
//RedType temp; 
//for (i = 0; i < L->Length; i++){ 
//j = SelectMinKey(L, i, CmpNum); 
//if (i != j){ 
//(*ChgNum)++; 
//memcpy(&temp, &L->r[i], sizeof(RedType)); 
//memcpy(&L->r[i], &L->r[j], sizeof(RedType)); 
//memcpy(&L->r[j], &temp, sizeof(RedType)); 
//} 
//} 
//} 
//void SelectSort(){ 
//printf("1. 插入排序\n"); 
//printf("2. 希尔排序\n"); 
//printf("3. 快速排序\n"); 
//printf("4. 堆排序\n"); 
//printf("5. 冒泡排序\n"); 
//printf("6. 选择排序\n"); 
//printf("7. 以上所有排序方式\n"); 
//printf("8. 退出程序\n\n"); 
//printf("Please Select the Operate:"); } 
//void AllAbove(LinkList *L, int *CmpNum, int *ChgNum){ 
//int TempTime, i,j; 
//int SpendTime; 
//int dlta[3] = { 
//7, 3, 1 
//}; 
//int Indata[1] = { 
//1 
//}; 
//for (i = 1; i <= MAXSIZE; i++) 
//L->r[i].key = RandArray[i]; //随机数列复位 
//printf("\n插入排序:\n"); 
//TempTime = (int)GetTickCount(); 
//ShellSort(L, Indata, 1, &CmpNum[0], &ChgNum[0]); 
//SpendTime = (int)GetTickCount() - TempTime; 
//printf("\nCompareNumber=%d\tChageNumber=%d\tTimeSpent=%dms\n", CmpNum[0], 
//ChgNum[0],SpendTime); 
//for (i = 1; i <= MAXSIZE; i++) 
//L->r[i].key = RandArray[i]; //随机数列复位 
//printf("\n希尔排序:\n"); 
//TempTime = (int)GetTickCount(); 
//ShellSort(L, dlta, 3, &CmpNum[1], &ChgNum[1]); 
//SpendTime = (int)GetTickCount() - TempTime; 
//printf("\nCompareNumber=%d\tChageNumber=%d\tTimeSpent=%dms\n", CmpNum[1], 
//ChgNum[1],SpendTime); 
//for (i = 1; i <= MAXSIZE; i++) 
//L->r[i].key = RandArray[i]; //随机数列复位 
//printf("\n快速排序:\n"); 
//TempTime = (int)GetTickCount(); 
//QuickSort(L, &CmpNum[2], &ChgNum[2]); 
//SpendTime = (int)GetTickCount() - TempTime; 
//printf("\nCompareNumber=%d\tChageNumber=%d\tTimeSpent=%dms\n", CmpNum[2], 
//ChgNum[2],SpendTime); 
//for (i = 1; i <= MAXSIZE; i++) 
//L->r[i].key = RandArray[i]; //随机数列复位 
//printf("\n堆排序:\n"); 
//TempTime = (int)GetTickCount(); 
//HeapSort(L, &CmpNum[3], &ChgNum[3]); 
//SpendTime = (int)GetTickCount() - TempTime; 
//printf("\nCompareNumber=%d\tChageNumber=%d\tTimeSpent=%dms\n", CmpNum[3], 
//ChgNum[3],SpendTime); 
//for (i = 1; i <= MAXSIZE; i++) 
//L->r[i].key = RandArray[i]; //随机数列复位 
//printf("\n冒泡排序:\n"); 
//TempTime = (int)GetTickCount(); 
//BubbleSort(L, &CmpNum[4], &ChgNum[4]); 
//SpendTime = (int)GetTickCount() - TempTime; 
//printf("\nCompareNumber=%d\tChageNumber=%d\tTimeSpent=%dms\n", CmpNum[4], 
//ChgNum[4],SpendTime); 
//for (i = 1; i <= MAXSIZE; i++) 
//L->r[i].key = RandArray[i]; //随机数列复位 
//printf("\n选择排序:\n"); 
//TempTime = (int)GetTickCount(); 
//SelSort(L, &CmpNum[5], &ChgNum[5]); 
//SpendTime = (int)GetTickCount() - TempTime; 
//printf("\nCompareNumber=%d\tChageNumber=%d\tTimeSpent=%dms\n", CmpNum[5], 
//ChgNum[5],SpendTime); 
//} 
//void main(){ 
//int i,j; 
//int select = 0; 
//int dlta[3] = {7, 3, 1}; 
//int Indata[1] = {1}; 
//int CmpNum[8], ChgNum[8]; 
//int SpendTime = 0; 
//int TempTime; 
//LinkList L; 
//InitLinkList(&L); 
//memset(CmpNum, 0, sizeof(CmpNum)); 
//memset(ChgNum, 0, sizeof(ChgNum)); 
//do{ 
//SelectSort(); 
//for (i = 0; i < MAXSIZE; i++) 
//L.r[i].key = RandArray[i]; //随机数列复位 
//scanf("%d", &select); 
//switch (select){ 
//case 1: 
//printf("\n插入排序:\n"); 
//TempTime = (int)GetTickCount(); 
//ShellSort(&L, Indata, 1, &CmpNum[select], &ChgNum[select]); 
//SpendTime = (int)GetTickCount() - TempTime; 
//for(i=1;i<=MAXSIZE;i++){ 
//printf("%5d ",L.r[i].key); 
//if(++j%10==0)printf("\n"); 
//} 
//printf("\n\nCompareNumber=%d\tChageNumber=%d\tTimeSpent=%dms\n", 
//CmpNum[select],ChgNum[select], SpendTime); 
//break; 
//case 2: 
//printf("\n希尔排序:\n"); 
//TempTime = (int)GetTickCount(); 
//ShellSort(&L, dlta, 3, &CmpNum[select], &ChgNum[select]); 
//SpendTime = (int)GetTickCount() - TempTime; 
//for(i=1;i<=MAXSIZE;i++){ 
//printf("%5d ",L.r[i].key); 
//if(++j%10==0)printf("\n"); 
//} 
//printf("\n\nCompareNumber=%d\tChageNumber=%d\tTimeSpent=%dms\n", 
//CmpNum[select],ChgNum[select], SpendTime); 
//break; 
//case 3: 
//printf("\n快速排序:\n"); 
//TempTime = (int)GetTickCount(); 
//QuickSort(&L, &CmpNum[select], &ChgNum[select]); 
//SpendTime = (int)GetTickCount() - TempTime; 
//for(i=1;i<=MAXSIZE;i++){ 
//printf("%5d ",L.r[i].key); 
//if(++j%10==0)printf("\n"); 
//} 
//printf("\n\nCompareNumber=%d\tChageNumber=%d\tTimeSpent=%dms\n", 
//CmpNum[select],ChgNum[select], SpendTime); 
//break; 
//case 4: 
//printf("\n堆排序:\n"); 
//TempTime = (int)GetTickCount(); 
//HeapSort(&L, &CmpNum[select], &ChgNum[select]); 
//SpendTime = (int)GetTickCount() - TempTime; 
//for(i=1;i<=MAXSIZE;i++){ 
//printf("%5d ",L.r[i].key); 
//if(++j%10==0)printf("\n"); 
//} 
//printf("\n\nCompareNumber=%d\tChageNumber=%d\t\tTimeSpent=%dms\n",CmpNum[select], 
//ChgNum[select], SpendTime); 
//break; 
//case 5: 
//printf("\n冒泡排序:\n"); 
//TempTime = (int)GetTickCount(); 
//BubbleSort(&L, &CmpNum[select], &ChgNum[select]); 
//SpendTime = (int)GetTickCount() - TempTime; 
//for(i=1;i<=MAXSIZE;i++){ 
//printf("%5d ",L.r[i].key); 
//if(++j%10==0)printf("\n"); 
//} 
//printf("\n\nCompareNumber=%d\tChageNumber=%d\tTimeSpent=%dms\n", 
//CmpNum[select],ChgNum[select], SpendTime); 
//break; 
//case 6: 
//printf("\n选择排序:\n"); 
//TempTime = (int)GetTickCount(); 
//SelSort(&L, &CmpNum[select], &ChgNum[select]); 
//SpendTime = (int)GetTickCount() - TempTime; 
//for(i=1;i<=MAXSIZE;i++){ 
//printf("%5d ",L.r[i].key); 
//if(++j%10==0)printf("\n"); 
//} 
//printf("\n\nCompareNumber=%d\tChageNumber=%d\tTimeSpent=%dms\n", 
//CmpNum[select],ChgNum[select], SpendTime); 
//break; 
//case 7: 
//AllAbove(&L, CmpNum, ChgNum); 
//break; 
//} 
//} 
//while (select != 8 ); 
//Display(&L); 
//} 
//
