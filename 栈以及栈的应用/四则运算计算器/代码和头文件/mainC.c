#include <stdio.h>
#include <stdlib.h>
#include "Calculator.h"

int init(){ 
    
    int choice;
    	printf(
    
		"\n\t_________________���������ܲ˵�___________________________\t\n"
		"\t|1:������ʽ                                             |\t\n"
		"\t|2:�˳�����                                               |\t\n"
		"\t|_________________________________________________________|\t\n\n"
	);
    	printf("\t������������еĲ�����");
    
	//������
   while(scanf("%d",&choice)!=1){
    	printf("�����빩�ο���ѡ�");
       fflush(stdin);
   }
	while (choice<1||choice>2){//�ж�ִ��1-6�����Ҽ��Ϸ�����
		printf("\t��������: '%d' ����!���������룺", choice);
		scanf(" %d", &choice); 
	}
    
	return choice;
}

int main(){
    int choice;
    double result;
    char s[100],houzhui[100],qianzhui[100];
    while(1){
	        choice=init();
        switch(choice){
	        case 1: printf("����Ӣ�����뷨������ʽ��\n");
                              scanf("%s",s);
                    while(1){
                        if(TransformToQianzhui(s,qianzhui)){
                                          getExpression(qianzhui,houzhui);	                                
                                          result=getResult(houzhui);
                                          printf("������Ϊ:%lf\n",result);
                            break;
                        }else{
	                                      printf("������ʽ����,��������:\n");
                                          scanf("%s",s);
                        } 
                    }
                    break;
            case 2:exit(0);
        }
    }
}

