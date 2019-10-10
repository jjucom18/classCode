#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	//\0 
	char arr[15] = "Hello world! jj uu";
	char *ptrCh = arr;
	char *ptrCh1 = (char *)malloc(sizeof(char) * 14);
	//strcpy(ptrCh1, arr);
	strcpy(ptrCh1, "zhangsan");
	printf("%s\n", ptrCh);
	printf("%s\n", ptrCh1);
	printf("%s: %d\n", arr, strlen(arr));
	char arrc[6];
	arrc[0] = 'H';
	arrc[1] = 'e';
	arrc[2] = 'l';
	arrc[3] = 'l';
	arrc[4] = 'o';
	arrc[5] = '\0';
	printf("%s\n", arrc);

	return 0;
}
