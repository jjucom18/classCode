//This is c program code!
/* *=+=+=+=+* *** *=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
  * 文档信息: *** :~/classCode/zhengmingzhu/main3.c
  * 版权声明: *** :(魎魍魅魑)MIT
  * 联络信箱: *** :guochaoxxl@163.com
  * 创建时间: *** :2019年12月04日的下午12:30
  * 文档用途: *** :数据结构与算法分析-c语言描述
  * 作者信息: *** :guochaoxxl(http://cnblogs.com/guochaoxxl)
  * 修订时间: *** :2019年第48周 12月04日 星期三 下午12:30 (第338天)
  * 文件描述: *** :自行添加
 * *+=+=+=+=* *** *+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+*/
#include "test1.c"

int main(int argc,char **argv)
{	DataType data;
	char flat;
	List *list = (List *)malloc(sizeof(List));
	int DataArr[] = {1,2,3,4,5,6,7,8,9};
	initList(list);
	printf("使用头插法输入h,使用尾插法输入t\n");
	scanf("%c",&flat);

	if(flat == 'h')
	{	
		for (int i=0;i<(sizeof(DataArr)/sizeof(DataArr[0]));i++)
		{
			addHead(list,DataArr[i]);
		}

	}else if(flat == 't'){

		for (int i=0;i<(sizeof(DataArr)/sizeof(DataArr[0]));i++)
		addTail(list,DataArr[i]);
	}
	displayList(list);
	printf("请输入你要删除的数据\n");
	scanf("%d",&data);
	deleteNode(list,getData(list,data));
	printf("删除完成\n");
	displayList(list);
	printf("\n");

	return 0;
} 
 






