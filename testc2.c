#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char *command = (char *)malloc(sizeof(char) * 30);
	printf("Enter a comand: ");
	scanf("%s", command);
	printf("You Enter: %s\n", command);

	return 0;
}
