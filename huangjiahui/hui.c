#include<stdio.h>
void InsertSort(Table &S)
{
        int i,j;
        for(i=2;i<=S.length;i++)
                if(S.elem[i].score>S.elem[i-1].score)
                {
                        S.elem[0]=S.elem[i];
                        S.elem[i]=S.elem[i-1];
                        for(j=i-2;S.elem[0].score>S.elem[j].score;j--)
                                S.elem[j+1]=S.elem[j];
                        S.elem[j+1]=S.elem[0];
                }
         }
void BubbleSort(Table &S)
{
        int i,j;
        for(i=1;i<=S.length;i++)
        {
                for(j=1;j<=S.length-i;j++)
                {
                        if(S.elem[j].score<S.elem[j+1].score)
                        {
                                S.elem[0]=S.elem[j];
                                S.elem[j]=S.elem[j+1];
                                S.elem[j+1]=S.elem[0];
                        }
                }
        }
void QuickSort(Table &S)
{
QSort(S,1,S.length);
{
         void SelectSort(Table &S）
       {

                         int i,j,k;
                         for(i=1;i<S.length;i++)
              {
                         k=i;
                         for(j=i+1;j<=S.length;j++)
                       {
                         if(S.elem[j].score>S.elem[j-1].score)
                                  {
                         k=j;
                                  }
                       }
                         if(i!=k)
                                 {
                         S.elem[0]=S.elem[i];
                         S.elem[i]=S.elem[k];
                         S.elem[k]=S.elem[0];
                       }
             }
      }
printf("%d  %s  %.2f  %d\n",S.elem[i].num,S.elem[i].name,S.elem[i].score,S.elem[i].mc);

}
