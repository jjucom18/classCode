#ifndef book_h
#define book_h
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<string.h>

typedef struct{
        int year;
        int month;
        int day;
}Date;

typedef struct _book{
        int id;
        Date date;
        int isbn;
        char name[50];
        char author[20];
        int type;
        char info[100]
        double price;
        char other[10]
        bool isEnd;
}BOOK;

int findByDate(Date date);
int findByName(char name[]);
int findByAuthor(char author[]);
int findByType(int type);

void bubble(void *index);
void sortByDate(Date date){
        for(int i=0;i<idmax-1;i++){
                if(books[i].date>books[i+1].date){
                         swapBook(books[i],books[i+1]);
                }
        }
}

void dispiaBook(Book book){
        printf()
}
void dispiaBook(){
        int id=1;
        while(!book[i].isEnd){
                dispiaBook(book[i]);
        }
}

#endif
 
