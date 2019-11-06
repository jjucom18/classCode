nclude "queueg.h"
 
int main(int  argc, char **argv) {

		SeqQueue *q = initQueue() ;
			
			DataType  arr[] ={
				89,23,14,56,75,61,91} ;
				int size =sizeof(arr) /sizeof(arr[0] ) ;
				      if(emptyQueue(SeqQueue *q) ) {

					    	printf("full") ;
									} 
					  
						for (int i = 0;i < size; i++) {

							inQueue(q,arr[i] ) ;
										} 
						for(int i = 0; i < size; i++) {

							outQueue(q, &arr[i] ) ;
											} 
								
