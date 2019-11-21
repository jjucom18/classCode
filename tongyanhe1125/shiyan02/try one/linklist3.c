#include<stdio.h>

int main(int argc,char **argv){
    

LinkedList linkedList;
    Employee *samuel=(EMployee *)malloc(sizeof(Employee));
    strcpy(samuel->name, "Samuel");
    samuel->age=32;
    
    Employee *sally=(Employee *)malloc(sizeof(Employee));
    strcpy(sally->name,"Sally");
    sally->age=28;

    Employee *susan =(Employee *)malloc(sizeof(Employee));
    strcpy(susan->name,"susan");
    susan->age=45;

    initializeList(&linkedList);

    addTail(&linkedList,susan);
    addTail(&linkedList,sally);
    addTail(&linkedList,samuel);

    addHead(&linkList,samuel);
    addHead(&linkList,sally);
    addHead(&linkList,susan);

    Node *node=getNode(&linkedList,(int (*)(void *))compareEmploy,sally);
    delete(&linkedList,node);
}
