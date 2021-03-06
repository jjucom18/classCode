#ifndef book_h
#define book_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct _Book{

	int id;				
	char name[20]; 		
	char author[20];	
	long int isbn;		
	float price;		
	char type[20];	


}Book;

typedef struct  _TreeNodeBook{
	Book *data;
	struct _TreeNodeBook *left, *right;
}TreeNode;

typedef struct _TreeBook{
	TreeNode *root;
}Tree;

typedef struct _nodeBook{
	Book  *data;
	struct _nodeBook *next;

}NodeBook;

typedef struct _linkedListBook{
	NodeBook *head;
	NodeBook *tail;

}List_Book;

List_Book *initList_Book();
void PromptInput_Type(Book *book);

NodeBook *Find_Book_name(List_Book *list,char name[]);
NodeBook *Find_Book_Author(List_Book *list,char author[]);
NodeBook *Find_Book_Type(List_Book *list,char type[]);

NodeBook *PromptFind_Book_name(List_Book *list);
int Judge_BookName(List_Book *list,char name[]);
int Order_Number();
Book *PromptInput_Data(List_Book *list);
void addTail_Book(List_Book *list);
void delNode_Book(List_Book *list);
void BookToFile(List_Book *list);
void BookToFile_Del(List_Book *list);
void addTail_Book_File(List_Book *list,Book *data);
void BookFromFile(List_Book *list);
void Free_Booklist(NodeBook *list);
void display_Book(NodeBook *book);


void CreateTree(Tree *tree, Book *data);
void displayTree_Book(TreeNode *tree);
void InOrder(TreeNode *tree);
void BookFromFile_Tree(Tree *tree);
void FreeTree_Book(TreeNode *tree);


void Seek_name();
void Seek_Author();
void Seek_Type();
void Seek_Menu();

void Book_MenuCheck();
void Book_MenuAdd();
void Book_MenuDel();
void Book_Menu();



























#endif
