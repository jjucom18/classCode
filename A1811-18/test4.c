#include "4.1.c"

int main(int argc,char **argv)
{
	int m;
	printf("请输入您的选择：1为变量自家2为指针自加\n");
	scanf("%d",&m);
	switch(m)
	{
		case 1:
			var();
			break;
		case 2:
			ptr();
			break;
	}
	const1var();
	constptr();

	return 0;
}
