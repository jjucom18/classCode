#include <stdio.h>
#include <stdlib.h>

void outPut(char* ptrCh){
	printf("%s\n", ptrCh);
}

char* outPutI(){
	printf("please input your name: ");
	char *ptrCh = (char *)malloc(30);
	scanf("%s", ptrCh);

	return ptrCh;
}

int main(int argc, char **argv)
{
	char arr[] = "Hello world!";
	outPut(arr);
	char *ptrCh = outPutI();
	outPut(ptrCh);

	return 0;
}

