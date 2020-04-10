#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Calculator.h"

int init(){ 
    
    int choice;
    char check[100];
    	printf(
    
		"\n\t_________________计算器功能菜单___________________________\t\n"
		"\t|1:计算表达式                                             |\t\n"
		"\t|2:退出程序                                               |\t\n"
		"\t|_________________________________________________________|\t\n\n"
	);
    	printf("\t请输入你想进行的操作：");
        scanf("%s",check);
	//输入检测
     while(1){
        while(strlen(check)!=1){ 
                	printf("请输入供参考的选项：");
                   scanf("%s",check);
    //  fflush(stdin);
        }
           choice=(int)check[0]-48;
       if(choice==1||choice==2){
	      break;
       }
           	printf("请输入供参考的选项：");
           scanf("%s",check);
     }

//	while (choice<1||choice>2){//判断执行1-6，并且检测合法输入
//		printf("\t您的输入: '%d' 有误!请重新输入：", choice);
//		scanf(" %d", &choice); 
//	}
    
	return choice;
}

int main(){
    int choice;
    double result;
    char s[100],houzhui[100],qianzhui[100];
    while(1){
	        choice=init();
        switch(choice){
	        case 1: printf("请用英文输入法输入表达式：\n");
                              scanf("%s",s);
                    while(1){
                        if(TransformToQianzhui(s,qianzhui)){
                                          getExpression(qianzhui,houzhui);	                                
                                          result=getResult(houzhui);
                                          printf("计算结果为:%lf\n",result);
                            break;
                        }else{
	                                      printf("输入表达式出错,重新输入:\n");
                                          scanf("%s",s);
                        } 
                    }
                    break;
            case 2:exit(0);
        }
    }
}

