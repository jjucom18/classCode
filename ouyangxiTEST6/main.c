#include"huffman.h"
int main(void)
{
    HuffmanTree ht;
    huffmanCode hc;
    int n,i;
    int w[100];     //用来存取权值
    int chlist[100];//用来存取相应的字符

    int cal[128] = {0};
    char str[10001];
    char code[10001];
    char tmp;
    while((tmp=getchar())!='#')
    {
        str[i] = tmp;
        i++;
    }
    str[i] = '\0';

    getchar();
    gets(code);

    //计算各个字符出现的频度
    for(i=0;i<strlen(str);i++)
        cal[str[i]]++;

    //将各个字符及权值存下来
    int j = 1;
    for(i=32;i<=122;i++){
    //空格为32,z为122，题中所出现的字符都在这个范围中
        if(cal[i]>0){
            w[j] = cal[i];
            chlist[j] = i;
            j++;
        }
    }

    //计算字符个数并构建哈夫曼树
    n=j-1; 
    CrtHuffmanTree(ht,w,n);

    //存取哈夫曼编码
    hc = malloc(sizeof(char)*(n+1)*(n+1));
    CrtHuffmanCode1(ht,hc,n);

    //编码，并计算编码结果的总长度
    long long codelength = 0;
    for(i=0;i<strlen(str);i++){
        for(int x=1;x<=n;x++){
            if(str[i]== chlist[x]){
                printf("%s",hc[x]);
                codelength +=strlen(hc[x]); 
                break;
            }
        }
    }
    printf("\n");

    //译码
    char temp[100];
    int result;
    int k = 0;
    for(i=0;i<strlen(code);i++){
        temp[k] = code[i];
        if(find_code(hc,n,temp,&result)){//看是否匹配
            putchar(chlist[result]);
            k = 0;
            memset(&temp,0,sizeof(temp));//若是匹配要输出结果，并将临时数组置空
        }
        else{
            k++;                        //不匹配将下一个字符添加进来再判断
        }
    }
    printf("\n");

    //输出平均码长，平均码长为：编码总长/原始数据长度
    printf("%0.2f\n",(codelength*1.0)/strlen(str));

    free(hc);//要注意malloc和free要搭配使用，学习了

    return 0;
}
