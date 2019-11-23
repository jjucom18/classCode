#include"data.h"

int main(int argc, char **argv)
{
	DataType data;
	SeqList *list,*List;
	list = init_SeqList();
	printf("please input data and input -1 end\n");
	scanf("%d",&data);
	while(data != -1)
	{
		Input_SeqList(list,data);
		scanf("%d",&data);
	}
	Out_SeqList(list);
	List = Del_data(list);
	Out_SeqList(List);

	return 0;
}