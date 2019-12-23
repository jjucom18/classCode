#include"Book.h"


List_Book *initList_Book (){
	
	List_Book *list = (List_Book *)malloc(sizeof(List_Book));
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;

	return list;
}//链表初始化

void PromptInput_Type(Book *book){
	int flat;
	printf("请选择书目类型\n");
	printf("1.哲学\t2.心理\t3.语言\t4.医学\t5.数学\t6.物理\t7.机械\t8.电信\n");
	scanf("%d",&flat);
	switch(flat){
			case 1: strcpy(book->type,"哲学");
					break;
			case 2:	strcpy(book->type,"心理");
					break;
			case 3:	strcpy(book->type,"语言");
					break;
			case 4:	strcpy(book->type,"医学");
					break;
			case 5:	strcpy(book->type,"数学");
					break;
			case 6:	strcpy(book->type,"物理");
					break;
			case 7: strcpy(book->type,"机械");
					break;
			case 8: strcpy(book->type,"电信");
			default:printf("未找到命令 ！\n");
	}
	return;
}


NodeBook *Find_Book_name(List_Book *list,char name[]){
	NodeBook *tmp = list->head;
	while(tmp != NULL && strcmp(tmp->data->name,name)){
		tmp = tmp->next;
	}
	return tmp;
}//通过name查找节点并返回

NodeBook *Find_Book_Author(List_Book *list,char author[]){
	NodeBook *tmp = list->head;
	while(tmp != NULL && strcmp(tmp->data->author,author)){
		tmp = tmp->next;
	}
	return tmp;
}//通过author查找节点并返回

NodeBook *Find_Book_Type(List_Book *list,char type[]){
	NodeBook *tmp = list->head;
	while(tmp != NULL && strcmp(tmp->data->type,type)){
		tmp = tmp->next;
	}
	return tmp;
}//通过type查找节点并返回

NodeBook *PromptFind_Book_name(List_Book *list){
	char name[20];
	NodeBook *book;
	printf("\n请输入您要删除的书名\n");
	scanf("%s",name);
	book = Find_Book_name(list,name);
	
	return book;
}

int Judge_BookName(List_Book *list,char name[]){

	char nameTmp[20];
	FILE *fp;
	fp = fopen("bookdata.txt", "r");
	if (fp != NULL)
	{
		while(!feof(fp)){
			fscanf(fp,"%s",nameTmp);
			if ( !strcmp(nameTmp,name)){
				printf("数据已存在请重新输入 ！\n");
				return 1;
			}
		}

		fclose(fp);

	}else{
		printf("文件打开失败 ！\n");
	}	

	if(Find_Book_name(list,name) == NULL){
		return 0;
	}else{
		printf("数据已存在请重新输入 ！\n");
		return 1;
	}
	
}

int Order_Number(){
	int order = 1,id = 0;
	long int isbn;
	char name[20],author[20],type[20];
	float price;
	time_t time;

	FILE *fp;
	fp = fopen("bookdata.txt", "r");
	if (fp != NULL)
	{
		while(!feof(fp)){
			fscanf(fp,"%d",&id);
			fscanf(fp,"%s",name);
			fscanf(fp,"%s",author);
			fscanf(fp,"%ld",&isbn);
			fscanf(fp,"%f",&price);
			fscanf(fp,"%s",type);
			fscanf(fp,"%ld",&time);
			order = id + 1;
		}
		fclose(fp);

	}else{
		printf("文件打开失败 ！\n");
	}
	return order;

}

Book *PromptInput_Data(List_Book *list){
	Book *book = (Book *)malloc(sizeof(Book));
	int id;
	long int isbn;
	char name[20];
	char author[20];
	id = Order_Number();
	book->id = id;
	
	book->time = time(0);
	printf("请输入书名\n");
	scanf("%s",name);
	while(Judge_BookName(list,name)){
				printf("请输入书名\n");
				scanf("%s",name);
	}
	strcpy(book->name,name);
	printf("请输入作者名\n");
	scanf("%s",author);
	strcpy(book->author,author);

	printf("请输入编号\n");
	scanf("%ld",&isbn);
	book->isbn = isbn;

	printf("请输入价格\n");							//价格的输入
	scanf("%f",&(book->price));

	PromptInput_Type(book);						//类型的选择

	return book;

}

void addTail_Book(List_Book *list){
	
	NodeBook *node = (NodeBook *)malloc(sizeof(NodeBook));
	node->data = PromptInput_Data(list);
	node->next = NULL;

	if(list->head == NULL){
		list->head = node;
	}else{
		list->tail->next = node;
	}
	list->tail = node;

	return;
}


void delNode_Book(List_Book *list){
	NodeBook *node = PromptFind_Book_name(list);
	if(node == list->head){
		if(list->head->next == NULL){
			list->head = list->tail = NULL;
		}else{
			list->head = list->head->next;
		}
	}else{
		NodeBook *tmp = list->head;
		while(tmp != NULL && tmp->next != node){
			tmp = tmp->next;
		}
		if(tmp != NULL){
			tmp->next = node->next;
		}
	}
	free(node);

	return;
}

void BookToFile(List_Book *list){
	
	NodeBook *tmp = list->head;
	FILE *fp;
	fp = fopen("bookdata.txt","a");
	if (fp != NULL)
	{
		while(tmp != NULL){
			fprintf(fp, "%d\t\t", tmp->data->id);
			fprintf(fp, "%s\t\t", tmp->data->name);
			fprintf(fp, "%s\t\t", tmp->data->author);
			fprintf(fp, "%ld\t\t", tmp->data->isbn);
			fprintf(fp, "%.2f\t\t", tmp->data->price);
			fprintf(fp, "%s\t\t", tmp->data->type);
			fprintf(fp, "%ld\n", tmp->data->time);

			tmp = tmp->next;
		}
		fclose(fp);
	}else{
		printf("文件保存失败 ！\n");
	}
}

void BookToFile_Del(List_Book *list){
	
	NodeBook *tmp = list->head;
	FILE *fp;
	int id = 0;
	fp = fopen("bookdata.txt","w");
	if (fp != NULL)
	{
		while(tmp != NULL){
				if (tmp->data->price == 0) break;
				id++;
				fprintf(fp, "%d\t\t", id);
				fprintf(fp, "%s\t\t", tmp->data->name);
				fprintf(fp, "%s\t\t", tmp->data->author);
				fprintf(fp, "%ld\t\t", tmp->data->isbn);
				fprintf(fp, "%.2f\t\t", tmp->data->price);
				fprintf(fp, "%s\t\t", tmp->data->type);
				fprintf(fp, "%ld\n", tmp->data->time);

				tmp = tmp->next;
			
		}
		fclose(fp);
	}else{
		printf("文件保存失败 ！\n");
	}
}

void addTail_Book_File(List_Book *list,Book *data){
	NodeBook *node = (NodeBook *)malloc(sizeof(NodeBook));
	node->data = data;
	node->next = NULL;

	if(list->head == NULL){
		list->head = node;
	}else{
		list->tail->next = node;
	}
	list->tail = node;

	return;
}

void BookFromFile(List_Book *list){
	FILE *fp;
	fp = fopen("bookdata.txt", "r");
	if (fp != NULL)
	{
		while(!feof(fp)){
			Book *book = (Book *)malloc(sizeof(Book));
			fscanf(fp,"%d",&(book->id));
			fscanf(fp,"%s",book->name);
			fscanf(fp,"%s",book->author);
			fscanf(fp,"%ld",&(book->isbn));
			fscanf(fp,"%f",&(book->price));
			fscanf(fp,"%s",book->type);
			fscanf(fp,"%ld",&(book->time));

			addTail_Book_File(list,book);
		}

		fclose(fp);

	}else{
		printf("文件打开失败 ！\n");
	}
	return;
}

void Free_Booklist(NodeBook *list){

	NodeBook *tmp;
	while(list != NULL){
		tmp = list;
		list = list->next;
		free(tmp);
		tmp = NULL;
	}
	return;
}

/************************************************************/


void CreateTree(Tree *tree, Book *data){
	TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	if (tree->root == NULL){
		tree->root = node;
	}else{
		TreeNode *tmp = tree->root;
		while(tmp != NULL){
			if (data->id < tmp->data->id){
				if (tmp->left == NULL){
					tmp->left = node;
					return;
				}else{
					tmp = tmp->left;
				}
			}else{
				if (tmp->right ==NULL){
					tmp->right = node;
					return;
				}else{
					tmp = tmp->right;
				}
			}
		}
	}
	return;
}
void display_Book(NodeBook *node){
	timeform *form;	
	form = localtime(&(node->data->time));
	if(node->data->price != 0 && node->data->id > 0){
		printf("书籍序号: %d\t", node->data->id);
		printf("书名: %s\t\t", node->data->name);
		printf("作者: %s\t\t", node->data->author);
		printf("编号: %ld\t", node->data->isbn);
		printf("价格: %.2f￥\t", node->data->price);
		printf("类型: %s\t", node->data->type);
		printf("入库时间:%04u-%02u-%02u  %02u:%02u:%02u\n",
		form->tm_year+1900,form->tm_mon+1,form->tm_mday,form->tm_hour,form->tm_min,form->tm_sec );
	}
	return;
}


void displayTree_Book(TreeNode *tree){
	timeform *form;	
	form = localtime(&(tree->data->time));
	if(tree->data->price != 0 && tree->data->id > 0){
		printf("书籍序号: %d\t", tree->data->id);
		printf("书名: %s\t\t", tree->data->name);
		printf("作者: %s\t\t", tree->data->author);
		printf("编号: %ld\t", tree->data->isbn);
		printf("价格: %.2f￥\t", tree->data->price);
		printf("类型: %s\t", tree->data->type);
		printf("入库时间:%04u-%02u-%02u  %02u:%02u:%02u\n",
		form->tm_year+1900,form->tm_mon+1,form->tm_mday,form->tm_hour,form->tm_min,form->tm_sec );
	}
	return;
}

void InOrder(TreeNode *tree){
	if (tree){
		InOrder(tree->left);
		displayTree_Book(tree);
		InOrder(tree->right);
	}
	return;
}

void BookFromFile_Tree(Tree *tree){
	FILE *fp;
	fp = fopen("bookdata.txt", "r");
	if (fp != NULL)
	{
		while(!feof(fp)){
			Book *book = (Book *)malloc(sizeof(Book));
			fscanf(fp,"%d",&(book->id));
			fscanf(fp,"%s",book->name);
			fscanf(fp,"%s",book->author);
			fscanf(fp,"%ld",&(book->isbn));
			fscanf(fp,"%f",&(book->price));
			fscanf(fp,"%s",book->type);
			fscanf(fp,"%ld",&(book->time));

			CreateTree(tree, book);
		}

		fclose(fp);

	}else{
		printf("文件打开失败 ！\n");
	}
	return;	
}

void FreeTree_Book(TreeNode *tree){
	if (tree){
		FreeTree_Book(tree->left);
		free(tree->data);
		free(tree);
		FreeTree_Book(tree->right);
	}
}


/***************************************************/

void Seek_name(){
	system("clear");
	char name[20];
	NodeBook *book;
	List_Book *list = initList_Book();
	BookFromFile(list);
	
	printf("请输入你要查找的书名\n");
	scanf("%s",name);
	book = Find_Book_name(list,name);
	if(book != NULL)
		display_Book(book);
	else
		printf("未找到 !\n");
	
	Free_Booklist(list->head);
	printf("\n");
	printf("请按任意键返回\n");
	getchar();
	getchar();
	system("clear");

	return;
}

void Seek_Author(){
	system("clear");
	char author[20];
	NodeBook *book;
	List_Book *list = initList_Book();
	BookFromFile(list);

	printf("请输入你要查找的作者\n");
	scanf("%s",author);
	book = Find_Book_Author(list,author);
	if(book != NULL)
		display_Book(book);
	else
		printf("未找到 !\n");

	Free_Booklist(list->head);
	printf("\n");
	printf("请按任意键返回\n");
	getchar();
	getchar();
	system("clear");

	return;
}

void Seek_Type(){
	system("clear");
	char type[20];
	NodeBook *book;
	List_Book *list = initList_Book();
	BookFromFile(list);

	printf("请输入你要查找的类型\n");
	scanf("%s",type);
	book = Find_Book_Author(list,type);
	if(book != NULL)
		display_Book(book);
	else
		printf("未找到 !\n");

	Free_Booklist(list->head);
	printf("\n");
	printf("请按任意键返回\n");
	getchar();
	getchar();
	system("clear");
}

void Seek_Menu(){
	system("clear");
	char flat;
	while(1){
		printf("请选择你要进行的操作\n");
		printf("1.书名查找\n");
		printf("2.作者查找\n");
		printf("3.类型查找\n");
		printf("4.退出\n");
		flat = getchar();
		switch(flat){
			case '1':	Seek_name();
						break;
			case '2':	Seek_Author();
						break;
			case '3':	Seek_Type();
						break;
			case '4':	system("clear");
						return;
		}

	}


	return;
}



/****************************************************/

void Book_MenuCheck(){
	system("clear");
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	tree->root = NULL;
	BookFromFile_Tree(tree);
	InOrder(tree->root);
	FreeTree_Book(tree->root);
	printf("\n");
	printf("请按任意键返回\n");
	getchar();
	getchar();
	system("clear");

	return;
}

void Book_MenuAdd(){
	system("clear");
	char flat = 'n';
	List_Book *list = initList_Book();
	while(flat != 'y'){

		addTail_Book(list);
		printf("是否退出y or n\n");
		getchar();
		scanf("%c",&flat);
	}
	BookToFile(list);
	Free_Booklist(list->head);
	printf("\n");
	printf("请按任意键返回\n");
	getchar();
	getchar();
	system("clear");

	return;
}

void Book_MenuDel(){
	system("clear");
	char flat = 'n';
	List_Book *list = initList_Book();
	BookFromFile(list);
	while(flat != 'y'){
		delNode_Book(list);
		printf("是否退出y or n\n");
		getchar();
		scanf("%c",&flat);
	}
	BookToFile_Del(list);
	Free_Booklist(list->head);
	printf("\n");
	printf("请按任意键返回\n");
	getchar();
	system("clear");

	return;
}

void Book_Menu(){
	system("clear");
	char flat;
	while(1){
		printf("请选择你要进行的操作\n");
		printf("1.查看书籍\n");
		printf("2.添加书籍\n");
		printf("3.删除书籍\n");
		printf("4.查找书籍\n");
		printf("5.退出\n");
		flat = getchar();
		switch(flat){
			case '1':	Book_MenuCheck();
						break;
			case '2':	Book_MenuAdd();
						break;
			case '3':	Book_MenuDel();
						break;
			case '4':	getchar();
						Seek_Menu();
						getchar();
						break;
			case '5':	system("clear");
						return;
		}

	}
	return;
}