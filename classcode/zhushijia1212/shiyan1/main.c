这样做只是交换了指针的地址，却没有交换a，b的值
修改方法：
void swap (int*p1,int*p2)
{
	int p;
	p=*p1;
	*p1=*p2;
	*p2=p;
}