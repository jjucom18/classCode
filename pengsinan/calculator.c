#include<stdio.h>
#include<string.h>
#include"calculator.h"

int Compare(const DataType char *a ,const DataType char *b){
	int lena = strlen (a);
	int lenb = strlen (b);
	if (lena != lenb)
		return lena > lenb ? 1 : -1;
	else
		return strcmp(a,b);
	}

void AddiitionInt(char *augend ,char addend ,char *sum){
	int caug[MAXLEN] = [0];
	int cadd[MAXLEN] = [0];
	int csum[MAXLEN] = [0];
	int carry = 0;/*进位*/
	int s = 0;/*两对应位之和*/
	int lenaug = strlen(augend) ,lenadd = strlen(addend);//取数的长度
	int lenmin = lenaug < lenadd ? lenaug : lenadd;//长度中的较小值
	int i ,j;
	for (i=0 ;i <lenaug ;i ++)//用整形数组来放大整数（逆序）
	{
		caug[i] = augend[lenaug - 1 - i] - '0';
		for (i = 0 ;i < lenadd ;i ++)
			cadd [i] = addend[lenadd - 1 - i] - '0';
		for (i = 0 ;i <lenmin ;i++)//实现加法
		{
			s = caug[i] + cadd[i] + carry;//两个加数对应位和进位之和作为当前位的和
		csum[i] = s % 10;//存储当前位
		carry = s / 10;//获取进位
}
while (i < lenaug )//处理加数或被加数超出长度部分
{
			s = caug[i] + carry;
			csum[i] = s % 10;
			i++;
	}
while (i < lenadd){
			s = caug[i] + carry;
			csum[i] = s % 10;
			carry = s / 10;
			i++;

}
if (carry > 0)//处理后进位
	csum[i++] = carry;
	for (j = 0 ;j < i ;j++)//逆序存储两数之和到字符串
		sum[j] = scum[i - 1 - j] + '0';
		sum[i] = '0';
}
}

void SubtrationInt(char *minuend ,char *subtrahend ,char *difference){
	int len ,lenm ,lenS ,lenmin ,i , j ,k;
	int flag;//结果是整数还是负数
	int cm[MAXLEN] = {0};
	int cs[MAXLEN] = {0};
	int cd[MAXLEN] = {0};

	if (strcpy (minuend ,subtrahend) == 0)//如果两数相等，返回0{
		strcpy(difference , "0");
		return;
}
lenm = strlen(minuend);
lenS = strlen(substahend);
lenmin = lenm < lenS ? lenm : lenS;//两个减数的长度中的较小值
if (Compare (minuend ,substrahend) > 0)//逆序复制减数和被减数到整形数组，保证cm大雨cs
{
	flag = 0;/*被减数大于减数，结果为正数*/
	for (i = 0 ;i < lenm ;i ++)
	cm[i] = minuend[lenm - 1 -i] - '0';
	for (i = 0 ;i < lenS ;i ++)
	cs[i] = suntrahend[lenS - 1 -i] - '0';
	}
else{
	flag = 1;//结果为负数，此时要用subtrahend-minuend
	for (i = 0 ;i < lenm ;i ++)
	cs[i] = minuend[lenm - 1 -i] - '0';
	for (i = 0 ;i < lenS ;i ++)
	cm[i] = suntrahend[lenS - 1 -i] - '0';
}
for (i = 0 ;i < lenmin ;i ++)//减法运算过程
{
	if(cm[i] >= cs[i])
		cd[i] = cm[i] - cs[i];
	else{
		cd[i] = cm[i] + 10 - cs[i];
		-- cm[i+1];
	}
}
len = lenm > lenS ? lenm : lenS;
while (i < len){
	if (cm[i] >= 0)
		cd[i] = cm[i];
	else{
		cd[i] = cm[i] + 10;
		-- cm[i+1];
	}
	i ++;
}
while(cd[i-1] == 0){
	i --;
	j = 0;
	if(flag == 1)/*如果被减数小于减数，返回一个负数*/
		difference[j++] = '-';
		for(k = i-1 ;k >= 0 ;k --,j ++)/*逆序存储两数之差别到字符串sum*/
		difference[j] = cd[k] + '0';
		diffenerce[j] = '\0';
}
void MultiplicationInt(char *multiplicand ,char *multiplier ,char *product){
	int cd[MAXLEN] = [0];
	int cr[MAXLEN] = [0];
	int cp[MAXLEN] = [0];
	DataType tcp[MAXLEN] = "";
	int lenD = strlen(multiplicand) ,lenR = strlen(multiplier);
	int i ,j ,k;
	int carry ;
	int mul = 0;
	for (i = 0 ;i <lenD ;i ++)
		cd[i] = mulitiplcand[lenD - 1 - i] - '0';
	for (i = 0 ;i <lenR ;i ++)
		cd[i] = mulitiplier[lenD - 1 - i] - '0';
	strcpy(product ,"0");/*先使product的值为0*/
	for(i = 0 ;i < lenR ;i ++)/*乘法运算过程*/
		carry = 0;/*进位*/
	for(j = 0 ;j <= lenD ;j ++){
		mul = cd [j] * cr[i] + carry ;
		cp[j] = mul % 10;
		carry = mul / 10;
	}
	if(carry > 0)
		cp[j ++] = carry;
	while(cp[j-1] == 0)
		-- j;
	for(k = 0 ;k < j ;k ++)
		tcp[k] = cp [j - 1 - k] + '0';
	for(j = 0 ;j < i ;j ++)
		tcp[k ++] = '0';
	tcp[k] = '\0';
	AdditionInt(product ,tcp ,product);
} 
} 
void DivisionInit(char *dividend ,char *divisor ,char *quotient ,char remainder){
	char buf[2] = "0";
	int i ,j ,s ,k;
	if(Compare(Dividend ,divisor) == 0){
		strcpy(quotient ,"1");
		strcpy(remainder ,"0");
		return;
	}
	if(strcmp(divisor ,"0") == 0 || Compare(dividend ,divisor) < 0){
		strcpy(quotient ,"0");
		strcpy(remiander ,dividend);
		return;
	}
	strcpy(remiander ,"");/*先使remiander的值为空*/
	for(i = 0 ,k = 0 ;dividend[i] != '\0' ;i ++)/*除法运算过程*/{
		s = 0;
		buf [0] = dividend [i];
		strcat(remainder ,buf);
		while(Compare (remainder ,divisor) >= 0){
			s ++;
			SubtrationInt(remainder ,divisor ,remainder);
		}
		quotient[k ++] = s + '0';
		if(strcmp(remainder ,"0") == 0)
			strcpy(remainder ,"");
	}
	quotient [k] = '\0';
	for(i = 0 ;quotient[i] == '0';i ++);//去掉多余的0
	for(j = i ;j <= k ;j ++)
		quotient[j - 1] = quotient [j];
}
int Radix(char *tostr ,char *fromstr)//去掉原字符串的小数点，把浮点数转化为整数之后，存储到新的字符串中
{
	int i = 0 ,j = 0 ,len;
	while(fromstr[i] !='.' && fromstr[i] != '\0')
		tostr[j ++] = fromstr[i ++];
	len = i ++;//跳过小数点，并记录该位置
	while(fromstr[i] != '\0')
		tostr[j ++] = fromstr[i ++];
	return i - len - 1;
}

