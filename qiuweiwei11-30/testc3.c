     #include"stdio.h"
  #include"stdlib.h"
  void main()
	  {
		    int var1, *ptr_arr;
		      ptr_arr=&var1;
		        scanf("%d",&var1);
			  *ptr_arr=(int*)malloc(sizeof(int));
			  printf("var1=%d,ptr_arr=%p",var1,&ptr_arr);
			 }
