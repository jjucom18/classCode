#ifndef tushu_h
#define tushu_h

#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct book
{
    char bookISBN[20];
    char bookname[20];
    char bookauthor[20];
    char bookpublisher[20];
    char bookdate[20];
    char bookprice[20];
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
