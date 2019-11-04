#include "testc.h"

int main(int argc, char **argv)
{
	Classmate stu = initStu();
	outStu(stu);
	printf("%s's record: %f\n", stu.name, stu.record);

	return 0;
}
