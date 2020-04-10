#include <stdio.h>
#include <stdlib.h>
#include "Calculator.h"

//获取后缀表达式
void getExpression(char* s,char* ss){
    char operate[100];
    int i=0,j=0,k=0;
    while(s[i]!='\0'){
	    if((s[i]>='0'&&s[i]<='9')||s[i]=='.' ){  //当s[i]为数字或小数点，直接入栈 
	              push(s,ss,&i,&j);
        }
        else{
	              ss[j]=' ';j++;//加上空号方便计算两位及两位以上的数字 
	        switch(s[i]){ //判断运算符的优先级并进行入栈和出栈的处理 
	            case '+':if(k==0){
	                                      push(s,operate,&i,&k);
                         }else{
	                        while(k!=0&&operate[k-1]!='('){
	                                            pop(operate,ss,&k,&j);
                            }
                                          push(s,operate,&i,&k);
                         }
                         break;
                case '-':if(k==0){
	                                      push(s,operate,&i,&k);
                         }else{
	                        while(k!=0&&operate[k-1]!='('){
	                                            pop(operate,ss,&k,&j);
                            }
                                          push(s,operate,&i,&k);
                         }
                         break;
                case '*':if(k==0){
	                                      push(s,operate,&i,&k);
                         }else{
	                        if(operate[k-1]=='*'||operate[k-1]=='/'){
	                            while(k!=0&&operate[k-1]!='+'&&operate[k-1]!='-'&&operate[k-1]!='('){
	                                                  pop(operate,ss,&k,&j);
                                }
                            }
                                          push(s,operate,&i,&k);
                         }
                         break;
                case '/':if(k==0){
	                                      push(s,operate,&i,&k);
                         }else{
	                        if(operate[k-1]=='*'||operate[k-1]=='/'){
	                            while(k!=0&&operate[k-1]!='+'&&operate[k-1]!='-'&&operate[k-1]!='('){
	                                                  pop(operate,ss,&k,&j);
                                }
                            }
                                          push(s,operate,&i,&k);
                         }
                         break;
                case '(':push(s,operate,&i,&k);
                         break;
                case ')':while(k!=0&&operate[k-1]!='('){
	                                      pop(operate,ss,&k,&j);
                         }
                                     k--;
                                     i++;
                         break;   
            }
        }
    }
    while(k>0){
	        pop(operate,ss,&k,&j);
    } 
      ss[j]='\0';
//printf("%s",ss);
}

//获取结果 
double getResult(char* ss){
    double num[100];
    int i=0,j=0,k=10,havePoint=0;
    double sum=0,instance,point=0.1;
    while(ss[j]!='\0'){
	    if(ss[j]==' '){
	              j++;
        }else if((ss[j]>='0'&&ss[j]<='9')&&(ss[j+1]=='+'||ss[j+1]=='-'||ss[j+1]=='*'||ss[j+1]=='/'||ss[j+1]==' ')) {
	              num[i]=TransformToD(ss[j]);
                  i++;
                  j++;
        }else if(ss[j]=='+'||ss[j]=='-'||ss[j]=='*'||ss[j]=='/'){
	        switch(ss[j]){
	            case '+':num[i-2]=num[i-1]+num[i-2];
                         break;
                case '*':num[i-2]=num[i-1]*num[i-2];
                         break;
                case '-':num[i-2]=num[i-2]-num[i-1];
                         break;
                case '/':num[i-2]=num[i-2]/num[i-1];
                         break;    
            } 
                  i--;
                  j++;
        }else if( (ss[j]>='0'&&ss[j]<='9')&&( (ss[j+1]>='0'&&ss[j+1]<='9')||ss[j+1]=='.') ){
	        while( (ss[j]>='0'&&ss[j]<='9')||ss[j]=='.'){
	            if(ss[j]=='.'){
	                          havePoint=1;
                              j++;
                }else{
	                if(havePoint==0){
	                                instance=TransformToD(ss[j]);
                                    sum=sum*k+instance;
                                    j++;
                    }else{
	                                instance=TransformToD(ss[j]);
                                    sum=sum+instance*point;
                                    point=point*0.1;
                                    j++;
                    }
                }    	            
            }   
                  num[i]=sum;
                  i++;
                  sum=0;point=0.1;havePoint=0;
        }
    }
    return num[0];
}


void push(char* out,char* in,int* fOut,int* fIn){
	in[*fIn]=out[*fOut];
   (*fOut)++;
   (*fIn)++;
}

void pop(char* out,char* in,int* fOut,int* fIn){
	in[*fIn]=out[*fOut-1];
   (*fIn)++;
   (*fOut)--;
}

double TransformToD(char m){
	return(double)( m-'0');
}

int TransformToQianzhui(char* s,char* qianzhui){
	int i=0,j=0,left=0,right=0;
    while(s[i]!='\0'){
	    if(s[i]>='0'&&s[i]<='9'){
	              push(s,qianzhui,&i,&j);
        }else{
	        switch(s[i]){
	            case '+':
                case '-':if(j==0){
                                          push(s,qianzhui,&i,&j);	
                         }else{
	                        if(qianzhui[j-1]>='0'&&qianzhui[j-1]<='9'){
	                                            push(s,qianzhui,&i,&j);
                            }else if(qianzhui[j-1]=='('){
	                                            qianzhui[j]='0';
                                                j++;
                                                push(s,qianzhui,&i,&j);
                            }else if(qianzhui[j-1]=='+'||qianzhui[j-1]=='-'||qianzhui[j-1]=='*'||qianzhui[j-1]=='/'){
	                           //                 printf("输入错误\n");
                                return 0;
                            }else{
	                                           push(s,qianzhui,&i,&j);
}
                         }
                         break;
                case '*':
	            case '/':if(j==0){
	                                      push(s,qianzhui,&i,&j);
                         }else{
	                        if( (qianzhui[j-1]>='0'&&qianzhui[j-1]<='9')||qianzhui[j-1]=='('||qianzhui[j-1]==')' ){
                                                push(s,qianzhui,&i,&j);	                                    
                            }else{
	                            //                printf("输入错误\n");
                                return 0;
                            }
                         }
                         break;
                case '.':if(j==0){
	                        return 0;	
                         }else{
	                        if(qianzhui[j-1]<'0'||qianzhui[j-1]>'9'){
	                           return 0;
                            }
                                          push(s,qianzhui,&i,&j);
                        }
                         break;
                case '(':push(s,qianzhui,&i,&j);
                                     left++;
                         break;
	            case ')':push(s,qianzhui,&i,&j);
                                      right++;
                         break;
                default:return 0;
            }
        }
    }
      qianzhui[j]='\0';
//printf("%s",qianzhui);
   if(left!=right){
	return 0;
   } 
   return 1;
}
