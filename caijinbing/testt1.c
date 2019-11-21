 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
int main()
{
        int num;
        srand((unsigned)time(NULL));
        num=rand();
        printf("%d\n",num);
 void insert_sort(int a[],int n)
{
        int i,j,temp;
        for(i=num;i<n;++i)
        {
                temp=a[i];
                for(j=i;j>0&&temp<a[j-num];--j)
                {
                        a[j]=a[j-num];
                }
                a[j]=temp;
        }
}
      return 0;
      }
