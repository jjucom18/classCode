  //可排序表的元素类型 
    #define MAXSIZE 10000 //用作示例的顺序表的最大长度 typedef int BOOL; 
    typedef struct{ 
    int key; //关键字项 
    } RedType; //记录类型 
    typedef struct LinkList{ 
    RedType r[MAXSIZE]; 
    int Length; //顺序表长度 } LinkList; 
    int RandArray[MAXSIZE]; //内部操作 
    void RandomNum(){ 
    int i; 
    srand(20000); 
    for (i = 0; i < MAXSIZE; i++) 
    RandArray[i] = (int)rand(); //构建随机序列 } 
    void InitLinkList(LinkList *L){ //建立表 
    int i; 
    memset(L, 0, sizeof(LinkList)); 
    RandomNum(); 
    for (i = 0; i < MAXSIZE; i++) 
    L->r[i].key = RandArray[i]; //赋值 
    L->Length = i; 
    } 
    bool LT(int i, int j, int *CmpNum){ //比较i与j大小，返回0或1 
    (*CmpNum)++; 
    if (i < j) 
    return TRUE; 
    else 
    return FALSE; 
    } 
    void Display(LinkList *L){ //存储表到SortRes.txt文件中 
    FILE *f; 
    int i; 
    if ((f = fopen("SortRes.txt", "w")) == NULL){ 
    printf("can't open file\n"); 
    exit(0); 
    } 
    for (i = 0; i < L->Length; i++) 
    fprintf(f, "%d\n", L->r[i].key); 
    fclose(f); 
    } 
    //部分操作的伪码算法 
    //希尔排序 
    void ShellInsert(LinkList *L, int dk, int *CmpNum, int *ChgNum){ 
    int i, j; 
    RedType Temp; 
    for (i = dk; i < L->Length; i++){ 
    if (LT(L->r[i].key, L->r[i - dk].key, CmpNum)){ 
    memcpy(&Temp, &L->r[i], sizeof(RedType)); 
    for (j = i - dk; j >= 0 && LT(Temp.key, L->r[j].key, CmpNum); j -= dk){ 
    (*ChgNum)++; 
    memcpy(&L->r[j + dk], &L->r[j], sizeof(RedType)); 
    } 
    memcpy(&L->r[j + dk], &Temp, sizeof(RedType)); 
    } 
    } 
    } 
    void ShellSort(LinkList *L, int dlta[], int t, int *CmpNum, int *ChgNum){ 
    int k; 
    for (k = 0; k < t; k++) 
    ShellInsert(L, dlta[k], CmpNum, ChgNum); 
    } 
    //快速排序 
    int Partition(LinkList *L, int low, int high, int *CmpNum, int *ChgNum){ 
    RedType Temp; 
    int PivotKey; 
    memcpy(&Temp, &L->r[low], sizeof(RedType)); 
    PivotKey = L->r[low].key; 
    while (low < high){ 
    while (low < high && L->r[high].key >= PivotKey){ 
    high--; 
    (*CmpNum)++; 
    } 
    (*ChgNum)++; 
    memcpy(&L->r[low], &L->r[high], sizeof(RedType)); 
    while (low < high && L->r[low].key <= PivotKey){ 
    low++; 
    (*CmpNum)++; 
    } 
    (*ChgNum)++; 
    memcpy(&L->r[high], &L->r[low], sizeof(RedType)); 
    } 
    memcpy(&L->r[low], &Temp, sizeof(RedType)); 
    return low; 
    } 
    void QSort(LinkList *L, int low, int high, int *CmpNum, int *ChgNum){ 
    int PivotLoc = 0; 
    if (low < high){ 
    PivotLoc = Partition(L, low, high, CmpNum, ChgNum); 
    QSort(L, low, PivotLoc - 1, CmpNum, ChgNum); 
    QSort(L, PivotLoc + 1, high, CmpNum, ChgNum); 
    } 
    } 
    void QuickSort(LinkList *L, int *CmpNum, int *ChgNum){ 
    QSort(L, 0, L->Length - 1, CmpNum, ChgNum); } 
    //堆排序 
    void HeapAdjust(LinkList *L, int s, int m, int *CmpNum, int *ChgNum){ 
    RedType Temp; 
    int j = 0; 
    s++; 
    memcpy(&Temp, &L->r[s - 1], sizeof(RedType)); 
    for (j = 2 * s; j <= m; j *= 2){ 
    if (j < m && LT(L->r[j - 1].key, L->r[j].key, CmpNum)) 
    ++j; 
    if (!LT(Temp.key, L->r[j - 1].key, CmpNum)) 
    break; 
    (*ChgNum)++; 
    memcpy(&L->r[s - 1], &L->r[j - 1], sizeof(RedType)); 
    s = j; 
    } 
    memcpy(&L->r[s - 1], &Temp, sizeof(RedType)); } 
    void HeapSort(LinkList *L, int *CmpNum, int *ChgNum){ 
    int i = 0; 
    RedType Temp; 
    for (i = L->Length / 2-1; i >= 0; i--) 
    HeapAdjust(L, i, L->Length, CmpNum, ChgNum); 
    for (i = L->Length; i > 1; i--){ 
    memcpy(&Temp, &L->r[0], sizeof(RedType)); 
    (*ChgNum)++; 
    memcpy(&L->r[0], &L->r[i - 1], sizeof(RedType)); 
    memcpy(&L->r[i - 1], &Temp, sizeof(RedType)); 
    HeapAdjust(L, 0, i - 1, CmpNum, ChgNum); 
    } 
    } 
    //冒泡排序 
    void BubbleSort(LinkList *L, int *CmpNum, int *ChgNum){ 
    int i, j; 
    RedType temp; 
    for (i = 1; i <= MAXSIZE; i++){ 
    for (j = 1; j <= MAXSIZE - i; j++){ 
    if (!LT(L->r[j].key, L->r[j + 1].key, CmpNum)){ 
    (*ChgNum)++; 
    memcpy(&temp, &L->r[j], sizeof(RedType)); 
    memcpy(&L->r[j], &L->r[j + 1], sizeof(RedType)); 
    memcpy(&L->r[j + 1], &temp, sizeof(RedType)); 
    } 
    } 
    } 
    } 
    //选择排序 
    int SelectMinKey(LinkList *L, int k, int *CmpNum){ 
    int Min = k; 
    for (; k < L->Length; k++){ 
    if (!LT(L->r[Min].key, L->r[k].key, CmpNum)) 
    Min = k; 
    } 
    return Min; 
    } 
    void SelSort(LinkList *L, int *CmpNum, int *ChgNum){ 
    int i, j; 
    RedType temp; 
    for (i = 0; i < L->Length; i++){ 
    

