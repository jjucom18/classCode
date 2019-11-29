#include "queue.h"
int main(int argc,char **argv)
{   CSeqqueue *queue=initqueue();
	if(emptyqueue(queue)){
	printf("队空\n");
	}
datatype arr[]={89,23,14,56,75,61,91};
int size=sizeof(arr)/sizeof(arr(0));
for(int i=0;i<size;i++;)
{	push(queue,arr[i]);
}
if(emptyqueue(queue)){
printf("队空\n");
}
else {
 printf("队不空\n")
}
int frontv=0;
frontqueue(queue,&frontv);
printf("queue front:%d\n",frontv);
datatype arr1[size];
for(int i=0;i<size;i++){
front(queue,arr1[i]);

return 0;
}
queue *initqueue();
bool emptyqueue(CSeqQueue *queue);

}
