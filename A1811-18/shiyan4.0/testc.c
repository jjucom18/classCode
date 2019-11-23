#include "carStop.c"
#include "carWait.c"
#include "insertcar.c"

int main (int argc,char **argv)
{

	carWait *q;
	q = (carWait *)malloc(sizeof(carWait));
	carStop top;
	top = (stackNode *)malloc(sizeof(carStop));
	car *x;
	x = (car *)malloc(sizeof(car));
	init_carStop(top);
	init_carWait(q);
	insertcar(top,q);
	empty_carStop(top);
	return 0;
} 
