#include<stdio.h>

void main()
{
	        int *ptr_arr;
		        int x;
			        printf("input x:\n");
				        scanf("%d",&x);
					        if(x<=0) x=100;
						        ptr_arr=(int*)malloc(sizeof(int)*x);
							        if(!ptr_arr){
									                printf("alloc ptr_arr error!\n");
											                exit(0);
													        }
								        else{
										                printf("alloc ptr_arr success!\n");
												        }
}
