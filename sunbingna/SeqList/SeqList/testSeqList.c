#include"SeqList.h"

int main(int argc,char **argv)
{
     SeqList *list = initSeqList();
        if(EmptyList(list)){
                printf("the list is empty!\n");
        }

        DataType arr[] = {99, 43, 21, 19, 36, 55, 64, 72, 81};
        int size = sizeof(arr)/sizeof(arr[0]);

        for(int i = 0; i < size; i++){
                inLocalList(list, i + 1, arr[i]);
      }
        outList("init: ", list);
         printf("%d is loacal: %d\n", 81, searchLocalList(list, 81));
        printf("local %d: is %d\n", 8, searchElementList(list, 8));
        outList("del local 8 before: ", list);
        deLocalList(list, 8);
        outList("del local 8 after: ", list);
        outList("del element 36 before: ", list);
        deElementList(list, 36);
        outList("del element 36 after: ", list);
}

