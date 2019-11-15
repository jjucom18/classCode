1 #include<stdio.h>
  
   int swap(int *p1,int *p2)
   {
       int *p;
       p=*p1;p1=*p2;p2=*p;
           
 }
   int main()
  {
      int a,b;
      int *pt_1,*pt_2;
      scanf("%d%d,&a,&b");
      pt_1=&a;pt_2=&b;
      if(a<b)  swap(pt_1,pt_2);
      else printf("%d,%d\n",*pt_1,pt_2);
  }
