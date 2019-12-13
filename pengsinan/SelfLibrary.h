#ifndef book_h
#define book_h

typedef struct{
	int year;
	int month;
	int day;
}Data;

typedef struct _book{
	Date date;
	int id;
	int isbn;
	int type;
	char name[50];
	char author[50];
	char info[50];
	char other[50];
	bool isEnd;
}Book;

int DateSerch

#endif
