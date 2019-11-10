#include"data.h"

SeqList *init_SeqList(){
	SeqList *list;
	list = (SeqList *)malloc(sizeof(SeqList));
	list->last = -1;
	return list;
}
void Input_SeqList(SeqList *list, DataType data){
	if (MAXSIZE-1 == list->last)
	{
		printf("full !\n");
		
	}else{
		list->last++;
		list->data[list->last] = data;
	}
	return;
}



void Out_SeqList(SeqList *list){
	int tmp = list->last;
	if (-1 == list->last)
	{
		printf("empty !\n");
	}else{
		int i = 0;
		while(i < tmp+1){
			if(list->data[i] != 0)
				printf("%d\t",list->data[i] );
			i++;
		}
		printf("\n");
	}
	list->last = tmp;
	return;
}
SeqList *bubbleSort(SeqList *list){
	DataType tmp;
	int i,j;
	for (i = 0; i < list->last; ++i)
		for (j = 0; j < list->last-i; ++j){
			if (list->data[j] > list->data[j+1]){
				tmp = list->data[j];
				list->data[j] = list->data[j+1];
				list->data[j+1] = tmp;
			}
		}
		return list;
}
SeqList *Del_data(SeqList *list){
	int tmp = list->last;
	//SeqList *List = bubbleSort(list);
	DataType tmpdata;
	int n,m;
	for (n = 0; n < list->last; ++n)
		for (m = 0; m < list->last-n; ++m){
			if (list->data[m] > list->data[m+1]){
				tmpdata = list->data[m];
				list->data[m] = list->data[m+1];
				list->data[m+1] = tmpdata;
			}
		}
	DataType x,y;
	printf("please input range x,y\n");
	scanf("%d,%d",&x,&y);
	int i = 0;
	int j = 0;
	while(y > list->data[i]){
		i++;
	}
	while(x > list->data[j]){
		j++;
	}
	while(list->data[j]){
		list->data[j] = list->data[i];
		i++;
		j++;
	}
	return list;

}
