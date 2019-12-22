#include"4.h"


int main(int argc, char **argv)
{
	int var1;
	int cvar1,var2;
	scanf("%d",&var1);
	Ptr1(var1);
	scanf("%d",&var1);
	scanf("%d",&cvar1);
	Ptr2(var1,cvar1);
	scanf("%d",&var1);
	scanf("%d",&var2);
	Ptr3(var1,var2);
	
	return 0;
}
