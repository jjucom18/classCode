#include "sampleg.h"

int main(int argc, char **argv)
{
	Student stu = initStu();
	outStu(stu);
	printf("%s's record: %f\n", stu.name, stu.record);

	return 0;
}
