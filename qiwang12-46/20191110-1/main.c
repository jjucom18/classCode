#include"workclass.h"

int main(int argc, char **argv)
{
	DataType data;
	SeqList *list,*List;
	list = init_SeqList();
	printf("请输入数据并且输入-1结束\n");
	scanf("%d",&data);
	while(data != -1)
	{
		Input_SeqList(list,data);
		scanf("%d",&data);
	}
	Inout_SeqList(list);
	List = Delete_element(list);
	Inout_SeqList(List);

	return 0;
}