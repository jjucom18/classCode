#include <stdio.h>
#include <malloc.h>

//创建结构体并创建头指针
struct Data{
	int num;
	struct Data *next;
}*data;

//删除节点
void deleteNode()
{
	printf("请输入你要删除的节点序号（从1开始）：");
	int num;
	scanf("%d", &num);
	getchar();
	struct Data *d1 = data;
	int nodeNum = 0;
	//统计节点数量
	for (nodeNum = 0; d1 != NULL;nodeNum++)
	{
		d1 = d1->next;
	}
	//如果不合法
	if (num < 1 || nodeNum < num)
	{
		printf("该节点位置不合法或不存在！\n");
		return;
	}
	struct Data *d2 = data;
	//如果删除第一个位置
	if (num == 1)
	{
		d2 = data->next;
		free(data);
		data = d2;

	}
	//如果删除最后一个位置
	else if (num == nodeNum)
	{
		for (;d2->next->next != NULL;)
		{
			d2 = d2->next;
		}
		free(d2->next);
		d2->next = NULL;
	}
	//如果不是删除第一个位置
	else
	{
		//找到相应位置
		for (int i = 2; i < num; i++)
		{
			d2 = d2->next;
		}
		struct Data *d3 = d2->next;
		d2->next = d2->next->next;
		free(d3);
	}
	printf("已删除！\n");

}



//初始化
void initList()
{
	data = NULL;
	printf("该链表允许每个节点存储一个数字\n");
	printf("已初始化\n");
}

//头部插入
void insertHead()
{
	printf("请输入一个你要存储的数字：");
	int num;
	scanf("%d", &num);
	getchar();
	//如果未存储数据
	if (data == NULL)
	{
		//创建空间并赋值
		data = (struct Data *)malloc(sizeof(struct Data));
		data->num = num;
		data->next = NULL;

	}
	//如果已存储数据
	else
	{
		//创建空间并赋值
		struct Data * d1 = (struct Data *)malloc(sizeof(struct Data));
		d1->num = num;
		d1->next = data;
		data = d1;
	}
	printf("保存成功\n");


}

//尾部插入
void insertTail()
{
	printf("请输入一个你要存储的数字：");
	int num;
	scanf("%d", &num);
	getchar();
	//如果未存储数据
	if (data == NULL)
	{
		data = (struct Data *)malloc(sizeof(struct Data));
		data->num = num;
		data->next = NULL;

	}
	else
	{
		//创建空间并赋值
		struct Data * d1 = (struct Data *)malloc(sizeof(struct Data));
		d1->num = num;
		d1->next = NULL;
		data->next = d1;
	}
	printf("保存成功\n");

}

//显示所有数据
void showAllNode()
{
	if (data == NULL)
	{
		printf("未存储数据\n");
		return;
	}
	struct Data * d1 = data;
	for (; d1 != NULL;)
	{
		printf("%d\n", d1->num);
		d1 = d1->next;

	}
	printf("已全部输出\n");
}

void returnNode()
{

	printf("请输入你要查询的节点序号（从1开始）：");
	int num;
	scanf("%d", &num);
	getchar();
	struct Data *d1 = data;
	int nodeNum = 0;
	//统计节点数量
	for (nodeNum = 0; d1 != NULL; nodeNum++)
	{
		d1 = d1->next;
	}
	//如果不合法
	if (num < 1 || nodeNum < num)
	{
		printf("该节点位置不合法或不存在！\n");
		return;
	}
	struct Data *d2 = data;
	for (int i = 1; i < num;i++)
	{
		d2 = d2->next;
	}
	printf("结果值：%d\n", d2->num);
}



int main()
{
	initList();
	for (int num = 0;;)
	{
		printf("请输入你的选项：\n");
		printf("1、在头部插入\n2、在尾部插入\n3、删除节点\n4、返回特定位置的数据\n5、输出所有内容\n0、退出\n");
		scanf("%d", &num);
		getchar();
		if (num == 1)
		{
			insertHead();
		}
		else if (num == 2)
		{
			insertTail();
		}
		else if (num == 3)
		{
			deleteNode();

		}
		else if (num == 4)
		{
			returnNode();

		}
		else if (num == 5)
		{
			showAllNode();

		}
		else if (num == 0)
		{

			break;
		}
		else
		{
			printf("输入错误！请重新输入\n");
		}
	}

	return 0;
