#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define random_1(a,b)((rand()%(b -a)) + a)
#define random_2(a,b)((rand()%(b -a + 1)) + a)
int createrandom(int arr[]);
int createrandom(int arr[])
{
	srand((int)time(NULL));
	
	for(int i = 0;i < 10;i++){
		arr[i] = random_1(1,20);

	}
	return 0;
}
