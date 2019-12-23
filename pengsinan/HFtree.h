#ifndef HFtree_h
#define HFtree_h
	
#define MAXVALUE 100000

typedef struct {
	int weight ;
	int parent ;
	int lchild ;
	int rchild ;
}HNodeType;
/*HNodeType HFMTree[2*n - 1] ;*/

typedef struct {
	int bit [n] ;
	int start ;
}HCodeType
/*HCodeType HuffCode [n] ;*/

void Creat _HuffMTree(HNodeTree [] int n){
	int m1 ,x1 ,m2 ,x2 ;
	int i ,j ;
	for(i =0 ;i < 2 * n - 1 ;i ++){
		HuffMTree [i] . weight = 0 ;
		HFMTree [i] . parent = -1 ;
		HFMTree [i] . lchild = -1 ;
		HFMTree [i] . rchild = -1 ;
	}
	for (i = 0 ;i < n ;i ++){
		scanf("%d" ,&HFMTree [i] . weight);
	for (i = 0 ;i < n - 1 ;i ++){
		x1 = x2 =MAXVALUE ;
		m1 = m2 = 0 ;
		for (j = 0 ;j < n + 1 ;j ++){
			if (HFMTree [j] . parent == -1 && HFMTree [j] . weight < x1){
				x2 = x1 ;
				m2 = m1 ;
				x1 = HFMTree [j] . weight ;
				m1 = j ;
			}
			else if (HTMTree [j] . parent == -1 && HFMTree [j] . weight < x1){
				x2 = HFMTree [j] .weight ;
				m2 = j ;
			}
		}
		HFMTree[m1] . parent = n + i ;HFMTree[m2] . parent = n + 1 ;
		HFMTree[n + i] . weight = HFMTree[m1] . weight + HFMTree[m2] . weight ;
		HFMTree[n + i] . lchild = m1 ;HFMTree[n + i] . rchild = m2 ;
	
	}
}


HNodeType HFMTree[2 * n - 1] ;
HCodeType HuffCode [n] ;

void HaffmanCode (HNodeType HFMTree [] ,HCodetType HuffCode []){
	HCodeType cd ;
	int i ,j ,c ,p ;
	for (i = 0 ;i < n ;i ++) {
		cd .start = n - 1 ;
		c = i ;
		p = HFMTree [c] . parent ;
		while (p != -1){
			if (HFMTree [p] .lchild == c)
				cd . bit [cd . start] = 0 ;
			else cd . bit [cd . start] = 1 ;
			cd . start -- ;
			p =HFMTree [c] . parent ;
		}
		for (j = cd . start = 1 ;j < n ;j ++)
			HuffCode[i] . bit = cd . bit[j] ;
		HuffCode[i] . start = cd . start + 1 ;
	}
}

#endif
