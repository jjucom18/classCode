#include "linklist.c"
#include "customer.c"
#include "jiemian.c"
int main(int argc,char **argv)
{	
	linklist *head;
	head = (linklist *)malloc(sizeof(linklist));
	customer *tip;
	tip = (customer *)malloc(sizeof(customer));
	tip = Initcustomer();
	head = Init();
	menu(head,tip);
	return 0;
}
