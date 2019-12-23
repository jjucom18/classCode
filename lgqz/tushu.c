#include<stdio.h>
#include<string.h>

struct BookData
{
	char name[20];
	char writer[20];
	int outDate;
	int id;
	int price;
}book[100] = { NULL };
//已有书籍的数量
int bookHave = 0;



void addBook()
{
	printf("请输入书名：");
	scanf_s("%s", book[bookHave].name, 18);
	getchar();
	printf("请输入作者：");
	scanf_s("%s", book[bookHave].writer, 18);
	getchar();
	printf("请输入出版日期：");
	scanf_s("%d", &book[bookHave].outDate);
	getchar();
	printf("请输入书籍编号：");
	scanf_s("%d", &book[bookHave].id);
	getchar();
	printf("请输入价格：");
	scanf_s("%d", &book[bookHave].price);
	getchar();
	printf("已存入\n");
	bookHave++;
}

void changeBook()
{

	printf("请选择修改的依据：\n");
	printf("1、书名\n2、作者\n3、出版日期\n4、编号\n5、价格\n");
	int num;
	scanf_s("%d", &num);
	printf("请输入数据：");
	int changeNum = -1;
	if (num == 1)
	{
		char c[20];
		scanf_s("%s", c, 18);
		getchar();
		for (int i = 0; i < bookHave; i++)
		{
			if (strcmp(c, book[i].name) == 0)
			{
				changeNum = i;
				break;
			}
		}
	}
	else if (num == 2)
	{
		char c[20];
		scanf_s("%s", c, 18);
		getchar();
		for (int i = 0; i < bookHave; i++)
		{
			if (strcmp(c, book[i].writer) == 0)
			{
				changeNum = i;
				break;
			}
		}
	}
	else if (num == 3)
	{
		int num1;
		scanf_s("%d", &num1);
		getchar();
		for (int i = 0; i < bookHave; i++)
		{
			if (num1 == book[i].outDate)
			{
				changeNum = i;
				break;
			}
		}
	}
	else if (num == 4)
	{
		int num1;
		scanf_s("%d", &num1);
		getchar();
		for (int i = 0; i < bookHave; i++)
		{
			if (num1 == book[i].id)
			{
				changeNum = i;
				break;
			}
		}
	}
	else if (num == 5)
	{
		int num1;
		scanf_s("%d", &num1);
		getchar();
		for (int i = 0; i < bookHave; i++)
		{
			if (num1 == book[i].price)
			{
				changeNum = i;
				break;
			}
		}
	}
	if (changeNum == -1)
	{
		printf("未找到\n");
	}
	else
	{
		printf("请输入书名：");
		scanf_s("%s", book[changeNum].name, 18);
		getchar();
		printf("请输入作者：");
		scanf_s("%s", book[changeNum].writer, 18);
		getchar();
		printf("请输入出版日期：");
		scanf_s("%d", &book[changeNum].outDate);
		getchar();
		printf("请输入书籍编号：");
		scanf_s("%d", &book[changeNum].id);
		getchar();
		printf("请输入价格：");
		scanf_s("%d", &book[changeNum].price);
		getchar();
		printf("已修改\n");
	}

}

void countBook()
{
	int num[7] = { 0 };
	for (int i = 0; i < bookHave; i++)
	{
		if (book[i].price <= 10)
		{
			num[0]++;
		}
		else if (book[i].price <= 20)
		{
			num[1]++;
		}
		else if (book[i].price <= 30)
		{
			num[2]++;
		}
		else if (book[i].price <= 40)
		{
			num[3]++;
		}
		else if (book[i].price <= 50)
		{
			num[4]++;
		}
		else if (book[i].price <= 100)
		{
			num[5]++;
		}
		else 
		{
			num[6]++;
		}
	}
	printf("价格分类：\n");
	printf("小于等于10元：%d\n", num[0]);
	printf("10元到20元：%d\n", num[1]);
	printf("20元到30元：%d\n", num[2]);
	printf("30元到40元：%d\n", num[3]);
	printf("40元到50元：%d\n", num[4]);
	printf("50元到100元：%d\n", num[5]);
	printf("大于100元：%d\n", num[6]);





}

void delBook()
{
	printf("请选择删除的依据：\n");
	printf("1、书名\n2、作者\n3、出版日期\n4、编号\n5、价格\n");
	int num;
	scanf_s("%d", &num);
	printf("请输入数据：");
	int delNum = 0;
	if (num == 1)
	{
		char c[20];
		scanf_s("%s", c, 18);
		getchar();
		for (int i = 0; i < bookHave; i++)
		{
			if (strcmp(c, book[i].name) == 0)
			{
				for (int j = i; j < bookHave - 1; j++)
				{
					book[j] = book[j + 1];
				}
				i--;
				bookHave--;
				delNum++;
			}
		}
	}
	else if (num == 2)
	{
		char c[20];
		scanf_s("%s", c, 18);
		getchar();
		for (int i = 0; i < bookHave; i++)
		{
			if (strcmp(c, book[i].writer) == 0)
			{
				for (int j = i; j < bookHave - 1; j++)
				{
					book[j] = book[j + 1];
				}
				i--;
				bookHave--;
				delNum++;
			}
		}
	}
	else if (num == 3)
	{
		int num1;
		scanf_s("%d", &num1);
		getchar();
		for (int i = 0; i < bookHave; i++)
		{
			if (num1 == book[i].outDate)
			{
				for (int j = i; j < bookHave - 1; j++)
				{
					book[j] = book[j + 1];
				}
				i--;
				bookHave--;
				delNum++;
			}
		}
	}
	else if (num == 4)
	{
		int num1;
		scanf_s("%d", &num1);
		getchar();
		for (int i = 0; i < bookHave; i++)
		{
			if (num1 == book[i].id)
			{
				for (int j = i; j < bookHave - 1; j++)
				{
					book[j] = book[j + 1];
				}
				i--;
				bookHave--;
				delNum++;
			}
		}
	}
	else if (num == 5)
	{
		int num1;
		scanf_s("%d", &num1);
		getchar();
		for (int i = 0; i < bookHave; i++)
		{
			if (num1 == book[i].price)
			{
				for (int j = i; j < bookHave - 1; j++)
				{
					book[j] = book[j + 1];
				}
				i--;
				bookHave--;
				delNum++;
			}
		}
	}
	if (delNum == 0)
	{
		printf("未删除任何内容\n");
	}
	else
	{
		printf("成功删除%d本书的数据\n", delNum);
	}


}

void initAll()
{
	bookHave = 0;
	printf("已清空所有数据\n");
}

void sortBook()
{
	printf("请输入排序方式：");
	printf("1、书名\n2、作者\n3、出版日期\n4、编号\n5、价格\n");
	int num;
	scanf_s("%d", &num);
	if (num == 1)
	{
		for (int i = bookHave - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (strcmp(book[j].name, book[j + 1].name) > 0)
				{
					struct BookData b1 = book[j];
					book[j] = book[j + 1];
					book[j + 1] = b1;
				}
			}
		}
	}
	else if (num == 2)
	{
		for (int i = bookHave - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (strcmp(book[j].writer, book[j + 1].writer) > 0)
				{
					struct BookData b1 = book[j];
					book[j] = book[j + 1];
					book[j + 1] = b1;
				}
			}
		}
	}
	else if (num == 3)
	{
		for (int i = bookHave - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (book[j].outDate > book[j + 1].outDate)
				{
					struct BookData b1 = book[j];
					book[j] = book[j + 1];
					book[j + 1] = b1;
				}
			}
		}
	}
	else if (num == 4)
	{
		for (int i = bookHave - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (book[j].id > book[j + 1].id)
				{
					struct BookData b1 = book[j];
					book[j] = book[j + 1];
					book[j + 1] = b1;
				}
			}
		}
	}
	else if (num == 5)
	{
		for (int i = bookHave - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (book[j].price > book[j + 1].price)
				{
					struct BookData b1 = book[j];
					book[j] = book[j + 1];
					book[j + 1] = b1;
				}
			}
		}
	}






}

int main()
{
	
	printf("图书管理系统\n");
	for (int choice;;)
	{
		printf("请输入你的选项：\n");
		printf("1、初始化（清空）\n2、添加书籍信息\n3、删除书籍信息\n4、修改书籍信息\n5、统计书籍信息\n6、书籍信息排序\n0、退出\n");
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			initAll();
		}
		else if (choice == 2)
		{
			addBook();
		}
		else if (choice == 3)
		{
			delBook();
		}
		else if (choice == 4)
		{
			changeBook();
		}
		else if (choice == 5)
		{
			countBook();
		}
		else if (choice == 6)
		{
			sortBook();
		}
		else if (choice == 0)
		{
			break;
		}
	}





	return 0;
}
