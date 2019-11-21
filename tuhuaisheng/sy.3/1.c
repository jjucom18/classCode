//冒泡
void bubblingSort(int msort[],int num){
	int temp,flag;
		for(int i=0;i<num-1;i++){
			flag=0;
			for(int j=0;j<num-i-1;j++){
				if(msort[j]>msort[j+1];){
					flag=1;
					temp=msort[j];
					msort[j]=msort[j+1];
					msort[j+1]=temp;
				}
			}
			if(!flag) break;
		}
		for(int i =0;i<num;i++){
			printf("%d",msort[i]);
		}printf("\n");
}
//直接插入
void insertSort(int msort[],int num){
	int temp,j;
	for(int i=1;i<num;i++){
		temp = msort[i];
		for(j=i-1;j>=0;j--){
			if(tmp<msort[j]){
				msort[j+1]=msort[j];
			}else{
				break;
			}
		}msort[j+1]=tmp;
	}for(int i=0;i<num;i++){
		printf("%d",msort[i]);
	}printf("\n");
}
//简单选择
void selectSort(int msort[],int num){
	int minn,pos;
	for(int i=0;i<num-1;i++){
		minn=1111111;
	for(int j=i;j<num;j++){
		if(msort[j]<minn){
			minn=msort[j];
			pos=j;
		}
	}
	if(i!=pos) {
		int tmp;
		tmp=msort[pos];
		msort[pos]=msort[i];
		msort[i]=tmp;
	} 
	}
	for(int i=0;i<num;i++){
		printf("%d",msort[i]);
	}printf("\n");
}
//快速
int mpartition(int msort[],int low,int high){
	int pivotkey=msort[low];
	int tmp;
	while(low<high){
		while(low<high&&msort[high]>=pivotkey) --high;
		tmp=msort[low];
		msort[low]=msort[high];
		msort[high]=tmp;
		while(low<high&&msort[low]<=pivotkey) ++low;
		temp=msort[low];
		msort[low]=msort[high];
		msort[high]=tmp;
	}
	return low;
}
