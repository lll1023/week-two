#ifndef CALCULATOR_H_INCLUDE
#define CALAULATOR_H_INCLUDE

void getExpression(char* s,char* ss);//��ȡ��׺���ʽ 
double getResult(char* num);//��ȡ��� 
void push(char* out,char* in,int* fOut,int* fIn);//�������ջ
void pop(char* out,char* in,int* fOut,int* fIn);//�������ջ 
double TransformToD(char m);//�ַ�ת����double 
int TransformToQianzhui(char* s,char* qianzhui);

#endif 
