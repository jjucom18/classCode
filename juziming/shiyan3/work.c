void Bubble_Sort(SeqList *L)
{
        printf("冒泡排序法\n");
        datetype i,j;
        datetype swap;
        for(i = 1;i<=MAXSIZE;i++)
        {swap = 0;
        for(j =1;j<=MAXSIZE-1;j++)
                if(L->date[j] > L->date[j+1])
                {
                        L->date[0] = L->date[j+1];
                        L->date[j+1] = L->date[j];
                        L->date[j] = L->date[0];
                        swap = 1;
                }
        if(swap == 0) break;
        }
        printf("输出排序后的值\n");
		for(datetype i = 0;i <= MAXSIZE -1; i++)
        printf("%d\t",L->date[i]);
        printf("\n");
}

void D_InserSort(SeqList *L)                    
{
        printf("插入排序\n");
        for(datetype i = 1;i<=MAXSIZE;i++)
                if(L->date[i] < L->date[i-1])
                {
                datetype temp;
                temp = L->date[i];
                datetype j = i-1;
        for( j ;temp < L->date[j] ; j--)
                        L->date[j+1] = L->date[j];
                L->date[j+1] = temp;
                }
        printf("输出排序后的值\n");
        for(datetype i = 0;i <= MAXSIZE -1; i++)
        printf("%d\t",L->date[i]);
        printf("\n");
}

void D_InserSort(SeqList *L)                    
{
        printf("插入排序\n");
        for(datetype i = 1;i<=MAXSIZE;i++)
                if(L->date[i] < L->date[i-1])
                {
                datetype temp;
                temp = L->date[i];
                datetype j = i-1;
        for( j ;temp < L->date[j] ; j--)
                        L->date[j+1] = L->date[j];
                L->date[j+1] = temp;
                }
        printf("输出排序后的值\n");
        for(datetype i = 0;i <= MAXSIZE -1; i++)
        printf("%d\t",L->date[i]);
        printf("\n");
}

void ShellSort(SeqList *L)
{
        printf("希尔排序\n");
        datetype i,j,k,h;
        datetype t = 5;
        datetype d[]={5,4,3,2,1};
        for(k = 0; k < t ;k++)
        {
        h= d[k];
        for(i = h;i<MAXSIZE;i++)
                if(L->date[i]<L->date[i-h])
                {
                        datetype temp;
                        temp = L->date[i];
                        for(j=i-h;j>0 && temp<L->date[j];j = j-h)
                        L->date[j+h] = L->date[j];
                        L->date[j+h] = temp;
                }
        }
        printf("输出排序后的值\n");
        for(datetype i = 0;i <= MAXSIZE -1; i++)
        printf("%d\t",L->date[i]);
        printf("\n");

}
