#ifndef reorder_h
#define reorder_h
#include <stdio.h>

#define Maxnum = 20

/*typedef struct Shellsort{
	int datatype R[];
	int n;
	int d[];
	int t;
	keytype key;
}shelltype;
shelltype R[Maxnum];*/

/*typedef struct Bubblesort{
	int arr[];
	int arrsize;
	keytype key;
}bubbletype;
bubbletype B[Maxnum];*/

/*typedef struct Quick_sort{
	int datatype Q[];
	int s;
	int z;
	keytype key;
}quicktype;
quicktype Q[Maxnum];

typedef struct Select_sort{
	int datatype S[];
	int n;
	keytype key;
}selecttype;
selecttype S[Maxnum];*/

void Shellsort(int datatype R[] ,int number ,int d[] ,int t);
void Bubblesort(int arr[] ,int arrsize);
void Quick_sort(int datatype Q[] ,int s ,int z);
void Select_sort(int datatype S[] ,int n);







#endif
