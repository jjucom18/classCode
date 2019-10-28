#include <stdio.h>
#define LINE 5

//void out2DArr(int row, int arr[][LINE]){
void out2DArr(int row, int (*arr)[LINE]){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < LINE; j++){
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return;
}

int main(int argc, char **argv)
{
	int arr2D[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int line = 5;
	//int row = sizeof(arr2D)/sizeof(int)/line;
	int row = 2;

	out2DArr(row, arr2D);

	printf("arr2D: %p\n", arr2D);
	printf("arr2D + 1: %p\n", (arr2D + 1));
	printf("&arr2D: %p\n", &arr2D);
	printf("&arr2D[0][0]: %p\n", &arr2D[0][0]);
	printf("&arr2D[0]: %p\n", &(arr2D[0]));

	return 0;
}
