#include "text.h" 

int main(int argc, char **argv){
    srand((int)time(NULL));
    int arr[10];
    for(int i=0;i<10;i++){
        arr[i]=random_1(1,20);
    }
    for(int i=0;i<10;i++){
        printf("%d\t",arr[i]);
    return 0;
    }

    bubble_sort(arr[i],10);
    printf("%d\t",arr[i]);
    printf("\n");
    return 0;

    quick_sort(1,10);
    for(i=1;i<10;i++)
        printf("%d\t",arr[i]);
    printf("\n");
    return 0;

    int len = sizeof(arr)/sizeof(arr[0]);
    select_sort(arr,len);
    printf("%d\t",arr[i]);
    printf("\n");

    insert_sort(1,10);
    printf("%d\t",arr[10]);
    printf("\n");
}
