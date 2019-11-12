#include"test.h"

int main(int argc, char **argv)
{
	DataType data;
	SeqList *list;
	list = init_SeqList();
	printf("please input data and input -1 end\n");
	scanf("%d",&data);
	while(data != -1)
	{
		Input_SeqList(list,data);
		scanf("%d",&data);
	}
	Out_SeqList(list);
	Del_data(list);
	Out_SeqList(list);

	return 0;
}
