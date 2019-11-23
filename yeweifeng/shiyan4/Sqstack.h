#ifndef SQSTACK_H_INCLUDED
#define SQSTACK_H_INCLUDED
#define STACKINCREMENT 10    //存储空间分配增量
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#include "Car.h"
typedef   int Status;
typedef   Car  SElemType;
typedef struct {
      SElemType *Base;
      SElemType *Top;
      int StackSize;
}SqStack;

Status InitStack(SqStack *S,int N){
     S->Base=(SElemType *)malloc(N*sizeof(SElemType));
     if(!S->Base)
         exit(-1);
     S->Top=S->Base;
     S->StackSize=N;
     return OK;
}

Status  Push(SqStack *S,SElemType e){
      int Length=S->Top-S->Base;
      if(Length>=S->StackSize)
      {
         S->Base=(SElemType*)realloc(S->Base,(S->StackSize+STACKINCREMENT)*sizeof(SElemType));
         if(!S->Base)
             exit(-1);
         S->Top=S->Base+S->StackSize;
         S->StackSize=S->StackSize+STACKINCREMENT;
      }
      *S->Top++=e;
      return OK;
}

Status Pop(SqStack *S,SElemType *e){
     if(S->Top==S->Base)
            return ERROR;
     *e=*(--S->Top);
     return OK;
}

Status GetTop(SqStack *S,SElemType *e){
     if(S->Top==S->Base)
            return ERROR;
     *e=*(S->Top-1);
     return OK;
}

Status StackFull(SqStack *S){
     if(S->Top-S->Base==S->StackSize)
          return TRUE;
     else
         return  FALSE;
}

Status StackEmpty(SqStack *S){
     if(S->Base==S->Top)
          return TRUE;
     else
         return  FALSE;
}
#endif // SQSTACK_H_INCLUDED
