void Exchangesort(int data[],int n){
        int i,j;
        int k;
                        for(j = i + 1;j<n;j++){
                        if(data [i] > data [j]){
                        k= data [i];
                        data [i] = data [j];
                        data [j] = k;
                        }
                }
        }
}
        printf("%d/t",input 20 number:)
void Bubblesort(int data[],int n){
        int i,j;
int k,flag=1;
for (i=0;i < n - 1;i++){
for (i =0;i < 1&&flag;i++){
flag=0;
for(j=0;j< n - i -1;j++){
        if(data [j] > data [j+1]){
                flag = 1;
                k = data [j];
                data [i] = data [j + 1];
                data [j+1] = k;
                }
                }
                }
                }
                
                void Quickinsort(int data[], int n){
        int i,j;
        int low,high,m;
        int k;
        for(i = 1;i < n;i++){
        k=data[i];
        low = 0;
        high = i - 1;
        while (low <= high){
        m=(low + high) / 2;
        if (k < data [m])
                high = m - 1;
                else
                low = m + 1;
        }
        for(j = i - 1;j >= high + 1;j--){
                data [ j + 1 ] =data [ j ];
        }
        data [ high + 1] = k;
        }

void Easychsort(int data[],int n){
        int i,j,min;
        int tmp;
        for (i = 0;i < n;i++){
                min = i;
                for(j = i;j < n;j++){
                        if( data[min] > data[j])
                                min = j;
   }
                if(i != min){
                        tmp = data[i];
                        data [i] = data[min];
                        data [min] = tmp;
                }
        }
