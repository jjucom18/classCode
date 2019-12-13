#ifndef calculator_h
#define calculator_h

#define MAXLEN 100

typedef struct{
	int *a,*b;
	void *augend ,*addend ,*sum;
	void *minuend ,*suntrahend ,*difference;
	void *multiplicand ,*mulitiplier ,*product;
	void *dividend ,*divisor ,*quotient ,*remiander;
	void *tostr ,*formstr;
}DataType;

int Compare(const DataType *a ,const DataType *b);//两个大整数比较
void AdditionInt(DataType *augend ,DataType *addend ,DataType *sum);//两个大整数的加法
void SubtrationInt(DataType *minuend ,DataType *subtrahend ,DataType *difference);//两个大整数的减法
void MultiplicationInt(DataType *multiplicand ,DataType *mulitiplier ,DataType *product);//两个大整数的乘法
void DivisionInt(DataType *dividend ,DataType *divisor ,DataType *quotient ,DataType *remainder);//除法
void Radix(DataType *tostr ,DataType *formstr);//去掉原字符串小数点，把浮点数转化为正数之后，存储到新字符串中

#endif
