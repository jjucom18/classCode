#include"sort.h"
int main(int argc,char **argv)
{int i,R[20];
	srand((int)time(NULL));
	for(int i=0;i<20;i++)
		R[i]=random_1(1,20);
	
    for(i=0;i<20;i++)
	insertSort(R,20);
	for(int i=0;i<10;i++)
		printf("%d\t",R[i]);
	
return 0;
}
