       #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
int main()
{
    int num;
        srand((unsigned)time(NULL));
             num=rand();
            printf("%d\n",num);
        int temp=num;
        for(int i=0;i<attr.length-1;i++)
                {
        for(int j=0;j<attr.length-i-1;j++){
                if(attr[j]>attr[j+1]){
                        temp=attr[j];
                        attr[j]=attr[j+i];
   attr[j+1]=temp;
                }
        }
                }
                                        return 0;
}
