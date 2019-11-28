#include "pack.h"

int main()
{
	s.stop  = -1;
	b.top   = 0;
	p.tail  = 0;
	p.head  = 0;
	p.count = 0;

	whlie (1)
	{
		welcome();
		int i,ch;
		scanf ("%d",&i);

		if ( i==1 ) car_reach();
		if ( i==2 ) car_leave();
		if ( i==3 ) display();
		if ( i==4 ) break;

		printf("返回请输入1\n");
		scanf("%d",&ch);
		if (ch==1)
			continue;
		else
		{
			printf("您的输入有误，请重新输入\n");
			scanf("%d",&ch);
			continue;
		}
	}
	return 0;
}
