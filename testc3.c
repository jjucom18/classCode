#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char *ptrCh = (char *)malloc(30);
	printf("please input your com: ");
	scanf("%s", ptrCh);
	printf("%s\n", ptrCh);
	int tmp = strcmp(ptrCh, "add");
	if(!tmp){
		printf("+\n");
	}

	strcpy(ptrCh, "Name: ");
	strcat(ptrCh, "zhangsan");
	printf("%s\n", ptrCh);


	return 0;
}
