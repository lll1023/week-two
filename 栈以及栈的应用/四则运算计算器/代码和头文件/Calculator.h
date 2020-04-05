#ifndef CALCULATOR_H_INCLUDE
#define CALAULATOR_H_INCLUDE

void getExpression(char* s,char* ss);//获取后缀表达式 
double getResult(char* num);//获取结果 
void push(char* out,char* in,int* fOut,int* fIn);//入运算符栈
void pop(char* out,char* in,int* fOut,int* fIn);//出运算符栈 
double TransformToD(char m);//字符转换成double 
int TransformToQianzhui(char* s,char* qianzhui);

#endif 
