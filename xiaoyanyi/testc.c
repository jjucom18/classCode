int *ptrvar;
ptrvar=ptrvar1;ptrvar1=ptrvar2;ptrvar2=ptrvar
 } 
 main() 
{ int a,b;int*ptrvar1,*ptrvar2;
  scanf("%d，%d,",&a,&b) ;
 ptrvar1=&a;ptrvar2=&b;
 if(a<b) swap(ptrvar1,ptrvar2);
 printf("%d,%d\n,*ptrvar1,*ptrvar2");
}
