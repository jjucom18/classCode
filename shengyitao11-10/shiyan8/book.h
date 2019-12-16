#ifndef tushu_h
#define tushu_h

#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct book
{
    char bookISBN[50];
    char bookname[50];
    char bookauthor[50];
    char bookpublisher[50];
    char bookdate[50];
    char bookprice[50];
    struct book *next;
}BOOK;

    BOOK *Read();
    BOOK *HeadCreate();
    void addbook(BOOK *head);
    void Changebook(BOOK *head);
    void Searchbook(BOOK *head);
    void Deletebook(BOOK *head);
    void countbook(BOOK *head);
    void Save(BOOK *head);







#endif
