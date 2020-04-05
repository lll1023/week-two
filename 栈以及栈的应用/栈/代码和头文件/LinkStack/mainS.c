#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

int init(){ 
    
   	int choice;
    	printf(
    
		"\n\t_________________ʵ��˳��ջ���ܲ˵�_______________________\t\n"
		"\t|1:��ʼ��ջ                                               |\t\n"
		"\t|2:�ж�ջ�Ƿ�Ϊ��                                         |\t\n"
		"\t|3:�õ�ջ��Ԫ��                                           |\t\n"
		"\t|4:���ջ                                                 |\t\n"
        "\t|5:����ջ                                                 |\t\n"
		"\t|6:���ջ����                                             |\t\n"
		"\t|7:��ջ                                                   |\t\n"
        "\t|8:��ջ                                                   |\t\n"
		"\t|9:�˳�����                                               |\t\n"
		"\t|_________________________________________________________|\t\n\n"
	);
    	printf("\t������������еĲ�����");
    
	//ֻ������������ 
   while(scanf(" %d", &choice)!=1){
    	printf("�����빩�ο���ѡ�");
       fflush(stdin);
}
    
	while (choice<1||choice>9){//�ж�ִ��1-9,���Ҽ��Ϸ�����
		printf("\t��������: '%d' ����!���������룺", choice);
		scanf(" %d", &choice); 
	}
    
	return choice;
}

int main(){ 
	int choice,sizes,flag=0,num=0;
      SqStack s;
	while (1){ 
           choice=init();
       //ȷ��ֻ�ܳ�ʼ��һ�� 
        if(flag==0&&choice!=1){
	             printf("���ȳ�ʼ��ջ");
            continue;
        }else if(flag==1&&choice==1){
	             printf("�ѳ�ʼ������ѡ����������\n");
           continue;
        }
	   switch(choice){
	      case 1:printf("�������ʼ��ջ�ĳ���:");
                 while(scanf(" %d", &sizes)!=1){
                            	printf("����������:");
                                fflush(stdin);
                 } 
                         initStack(&s,sizes);
                         flag=1;
                 break;
          case 2:isEmptyStack(&s);
                 break;
          case 3:if(getTopStack(&s,&num)){	
                         printf("ջ��Ԫ��Ϊ:%d",num);
                 }
                 break;
          case 4:clearStack(&s);
                 break;
          case 5:destroyStack(&s);
                         flag=0;
                 break;
          case 6:stackLength(&s,&num);
                          printf("ջ����Ϊ:%d",num);
                 break;
          case 7:printf("��������ջ��ֵ:");
                 while(scanf(" %d", &num)!=1){
                            	printf("����������:");
                                fflush(stdin);
                 } 
                         pushStack(&s,num);
                 break;
          case 8:if(popStack(&s,&num) ){
                          printf("��ջ��ֵΪ:%d",num);
                 }
                 break;
          case 9:exit(0);
       }
	
    }

	
}


