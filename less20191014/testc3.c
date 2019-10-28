#include <stdio.h>

int main(int argc, char **argv)
{
	int (*(d2Arr[])) = {
		(int[]){1, 2, 3, 4},
		(int[]){5, 6},
		(int[]){7, 8, 9},
	};

	int arrSize[] = {4, 2, 3};
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < arrSize[i]; j++){
			printf("%d\t", d2Arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
