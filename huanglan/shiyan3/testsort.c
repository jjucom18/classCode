#include"sort.h"

#include <time.h>

#define random_1(a,b)((rand()%(b - a))+ a)

#define random_2(a,b)((rand()%(b - a + 1)) + a)



int *Random_Numble()

{

	srand((int)time(NULL));

	for(int i = 0; i< 20;i++){

		r[i]= random_1(1,20);

	}

	for(int i= 0;i<20;i++){

		printf("%d\t",r[i]);

	} 	printf("\n");

	

	return &r[0];

	//D_inSort(R,n);

	//Bubble_Sort(R,n);

	//Select_Sort(R,n);

	//QSort(R);



}
