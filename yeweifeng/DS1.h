ST_INIT_SIZE 150 /*线性表存储空间的初始分配量*/
#define LISTINCREMENT  50 /*线性表存储空间的分配增量*/
typedef char KeyType;
typedef struct {
	    KeyType key;   //记录中的关键字类型元素
} RcdType;


typedef struct {
	    RcdType * rcd;   //存储空间的基址
	        int length;        //当前长度，不包括下标为0的元素
		    int size;          //存储容量
		        int increment;     //扩容容量
} SqList;  //顺序表

Status InitList(SqList &L){
	    L.rcd = (RcdType*)malloc(sizeof(RcdType)*(LIST_INIT_SIZE));
	        if(NULL == L.rcd)return OVERFLOW;
		    L.length=0;
		        L.size = LIST_INIT_SIZE;
			    L.increment = LISTINCREMENT;
			        return OK;
}

Status Destroy(SqList &L){
	    free(L.rcd);
	        L.rcd = NULL;
		    return OK;
}

Status Append(SqList &L, KeyType e){
	    RcdType *newbase;
	        //如果长度大于顺序表存储容量，进行扩容
		    if(L.length+1 >= L.size){
		            newbase = (RcdType*)realloc(L.rcd, (L.size+L.increment)*
		                                                 sizeof(RcdType));
                                                       if(NULL==newbase)return OVERFLOW;
		                                                                 L.rcd = newbase;
		                                                                         L.size += L.increment;
		                                                                             }
                                                                        L.rcd[L.length+1].key=e;
		                                                                                     L.length++;
		                                                                              return OK;
		                                                                             }
                                                                   Status Print(SqList &L){
		                                                    for(i=1; i<L.length+1; i++){
	                                                                        printf("%c",L.rcd[i].key);
                                                                                                      }	                                                                                                   
									   printf("\n");
}
