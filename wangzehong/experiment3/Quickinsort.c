#include"intersort.h"

int main(int argc,int **argv){
        int i;
        srand(time(NULL));
        int data[Maxsize];
        for(i = 1;i < Maxsize;++i)
        data[i]=rand()%100;
        Quickinsort(data,Maxsize);
        for(i = 1;i < Maxsize;++i)
                printf("%d\t",data[i]);
        printf("\n");

        return 0;

}
