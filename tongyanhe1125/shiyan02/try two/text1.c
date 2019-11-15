#include "text.h"

int main(){
    LinkList *list=CreateList();
    Insert(list,1,10);
    Insert(list,1,20);
    Delete(list,2);
    Insert(list,1,30);
    Insert(list,1,40);
    printf("%d\n",Size(list));
    Print(list);
    printf("%d",GetData(list,2));
    system("pause");
}
