void BubbleSort(SqList &L, int &bubble_c, int &bubble_s){
    //冒泡排序算法
    int i,j;
    RcdType temp;
    int reg=1;          //改进的冒泡排序中增加的reg变量，用于判断循环是否继续
    for(i=L.length; i>1&&reg; i--){
        reg=0;              //reg赋值为0
        for(j=1; j<i; j++){
            bubble_c++;         //比较一次
            if(L.rcd[j].key > L.rcd[j+1].key){
                bubble_s += 3;      //交换一次
  temp = L.rcd[j];
                L.rcd[j] = L.rcd[j+1];
                L.rcd[j+1] = temp;
                reg=1;          //如果没有进入该for循环，则reg为0，最外层循环将结束
            }
        }
    }
}

void InsertSort(SqList &L, int &insert_c, int &insert_s){
    //直接插入排序
    int i,j;
    for(i=1; i<L.length; i++){
        insert_c++;     //比较一次
        if(L.rcd[i+1].key < L.rcd[i].key){ //需要将L.elem[i+1]插入有序序列

            L.rcd[0] = L.rcd[i+1]; //先将L.elem[i+1]保存在空闲的0号单元
            insert_s++;     //关键字移动一次
            j=i+1;
            do{
            //循环将关键字后移，直到找到合适的位置进行0号元素的插入操作
                j--;
                L.rcd[j+1]=L.rcd[j];
                insert_s++;     //移动一次
                insert_c++;     //在while中将会比较一次
            }while(L.rcd[0].key < L.rcd[j-1].key);
            L.rcd[j] = L.rcd[0];
            insert_s++;     //移动一次
        }
    }
}
void SelectEasy(SqList &L, int &Easy_c, int &Easy_s){
    //简单选择排序
    int i,j,k;
    RcdType temp;
    for(i=1; i<L.length; i++){
        for(j=i,k=i; j<L.length; j++){
               Easy_c++;//比较一次
            if(L.rcd[k].key > L.rcd[j+1].key){
                k=j+1;//记录最小值下标
            }
        }
        if(k!=i){
            temp = L.rcd[i];
            L.rcd[i] = L.rcd[k];
            L.rcd[k] = temp;
            Easy_s += 3;//关键字交换
        }
    }
}
void QSort(RcdType rcd[], int s, int t, int &quick_c, int &quick_s){
    //快速排序
    int pivotloc;
    if(s<t){
        pivotloc = Partition(rcd, s, t, quick_c, quick_s);
        QSort(rcd, s, pivotloc-1, quick_c, quick_s);
        QSort(rcd, pivotloc+1, t, quick_c, quick_s);
    }
}


void QuickSort(SqList &L, int &quick_c, int &quick_s){
    QSort(L.rcd, 1, L.length, quick_c, quick_s);

}
