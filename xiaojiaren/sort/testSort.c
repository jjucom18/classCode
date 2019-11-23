#include"Sort.h"

void main()
{	DataType *R;
	R=Random_Numble();
	D_inSort(R);
	Bubble_Sort(R);
	ShellSort(R);
	Select_Sort(R);
}
