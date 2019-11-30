#include"HFMTree.h"

void CreateHFMTree(HNodeType HFMTree[], int n){
	srand(time(NULL));
	int min1,min2,address1,address2;
	int i,j;
	for (i = 0; i < 2*n-1; ++i){
		HFMTree[i].weight = 0;
		HFMTree[i].parent = -1;
		HFMTree[i].lchild = -1;
		HFMTree[i].rchild = -1;
	}
	for (i = 0; i < n; ++i){
		HFMTree[i].weight = rand()%100;
	}
	for (i = 0; i < n - 1; ++i){
		min1 = min2 = MaxValue;
		address1 = address2 = 0;
		for (j = 0; j < n + i; ++j){
			if (HFMTree[j].parent == -1 && HFMTree[j].weight < min1){
				min2 = min1; 
				address2 = address1;
				min1 = HFMTree[j].weight;
				address1 = j;
			}else if(HFMTree[j].parent == -1 && HFMTree[j].weight < min2){
				min2 = HFMTree[j].weight;
				address2 = j;
			}
		}
		HFMTree[address1].parent = n + i;
		HFMTree[address2].parent = n + i;
		HFMTree[n + i].weight = HFMTree[address1].weight + HFMTree[address2].weight;
		HFMTree[n + i].lchild = address1;
		HFMTree[n + i].rchild = address2;
	}
}

