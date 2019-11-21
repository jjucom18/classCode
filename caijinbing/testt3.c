    #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
int main()
{
                int num;
                        srand((unsigned)time(NULL));
                                num=rand();
                                        printf("%d\n",num);
        void selectSort(int arr[],int len)
        {
                int i,j;
                int min;
                int tmp;
                for(i=0;i<len-1;++i)
                {
                        min=i;
                        for(j=i+1;j<len;++j)
                        {
                                if(arr[j]<arr[min])
                      {
                              min=j;
                      }
                        }
                        tmp=arr[i];
                        arr[i]=arr[min];
                        arr[min]=tmp;
                }
        }
        return 0;
}
