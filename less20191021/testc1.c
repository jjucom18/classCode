#include <stdio.h>

int main(int argc, char **argv)
{
	int arr[] = {11, 23, 35, 43, 54, 98, 76, 65, 84};
	int arrSize = sizeof(arr)/sizeof(int);
	
	int tmp = 55;
	int flag = 0;

	for(int i = 0; i < arrSize; i++){
		if(tmp == arr[i]){
			printf("yes, %d\n", i + 1);
			flag = 1;
			break;
		}
	}
	if(!flag){
		printf("no found!\n");
	}

	return 0;
}
