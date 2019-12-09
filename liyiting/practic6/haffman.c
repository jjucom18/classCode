#include "haffman.h"

void PrintBTree_int(struct BTreeNode* BT)  
{  
	    if (BT != NULL)  
{  
                printf("%d", BT->data);   
                if (BT->left != NULL || BT->right != NULL)  
	        {  
	          printf("(");  
	          PrintBTree_int(BT->left);  
                  if (BT->right != NULL)  
                     printf(",");  
                     PrintBTree_int(BT->right);  
                     printf(")");}  
	    }  
}  

struct BTreeNode* CreateHuffman(ElemType a[], int n)  
{  
	    int i, j;  
	    struct BTreeNode **b, *q;  
	    b = malloc(n*sizeof(struct BTreeNode));  
	    for (i = 0; i < n; i++) 
	       {b[i] = malloc(sizeof(struct BTreeNode));  
	        b[i]->data = a[i];  
	        b[i]->left = b[i]->right = NULL;}  
	    for (i = 1; i < n; i++)  
	        {int k1 = -1, k2;  
		 for (j = 0; j < n; j++) 
                 { if (b[j] != NULL && k1 == -1)  
		    {         k1 = j;  
		              continue;  
		              }
		    if (b[j] != NULL)  
                    {  
			    k2 = j;  
                            break;  
                              }  
                       }  
                    for (j = k2; j < n; j++)
		    {  
			    if (b[j] != NULL)  		
			    {  
				    if (b[j]->data < b[k1]->data)  
				    { 	    k2 = k1;  	
					    k1 = j;  
				    }  
				    else if (b[j]->data < b[k2]->data)  
					    k2 = j; 
			    }  
		    }  

		    q = malloc(sizeof(struct BTreeNode));  
		    q->data = b[k1]->data + b[k2]->data;  
		    q->left = b[k1];  
		    q->right = b[k2];                	    
		    b[k1] = q;
		    b[k2] = NULL;	   
		}  
	    free(b); 
	    return q; 
}

ElemType WeightPathLength(struct BTreeNode* FBT, int len)  
{  	    if (FBT == NULL)   
	        return 0;  
	        else  
	        {  
	           if (FBT->left == NULL && FBT->right == NULL)  
	                return FBT->data * len;  
	           else  
	                return WeightPathLength(FBT->left,len+1)+WeightPathLength(FBT->right,len+1);  
	        }  
}  

void HuffManCoding(struct BTreeNode* FBT, int len)  
{  	    static int a[10];  
	     if (FBT != NULL ){
 		if (FBT->left == NULL && FBT->right == NULL){  
			int i;  
                        printf("结点权值为%d的编码：", FBT->data);  
	                for (i = 0; i < len; i++)  
				printf("%d", a[i]);  
                        printf("\n");  
	                }  
	         else
		 {      a[len] = 0;  
		        HuffManCoding(FBT->left, len + 1);  
		        a[len] = 1;  
		        HuffManCoding(FBT->right, len + 1);  
		           }  
		    }  
}  
