#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

int init(){ 
    
   	int choice;
    	printf(
    
		"\n\t_________________实现链栈功能菜单__________________________\t\n"
		"\t|1:初始化栈                                               |\t\n"
		"\t|2:判断栈是否为空                                         |\t\n"
		"\t|3:得到栈顶元素                                           |\t\n"
		"\t|4:清空栈                                                 |\t\n"
        "\t|5:销毁栈                                                 |\t\n"
		"\t|6:检测栈长度                                             |\t\n"
		"\t|7:入栈                                                   |\t\n"
        "\t|8:出栈                                                   |\t\n"
		"\t|9:退出程序                                               |\t\n"
		"\t|_________________________________________________________|\t\n\n"
	);
    	printf("\t请输入你想进行的操作：");
    
	//只允许输入数字 
   while(scanf(" %d", &choice)!=1){
    	printf("请输入供参考的选项：");
       fflush(stdin);
}
    
	while (choice<1||choice>9){//判断执行1-9,并且检测合法输入
		printf("\t您的输入: '%d' 有误!请重新输入：", choice);
		scanf(" %d", &choice); 
	}
    
	return choice;
}

int main(){ 
	int choice,flag=0,num=0;
      LinkStack s;
	while (1){ 
           choice=init();
       //确定只能初始化一次 
        if(flag==0&&choice>1&&choice<9){
	             printf("请先初始化栈");
            continue;
        }else if(flag==1&&choice==1){
	             printf("已初始化，请选择其他操作\n");
           continue;
        }
	   switch(choice){
	      case 1:if(initLStack(&s)){
                              printf("初始化栈成功\n");
                              flag=1;
                 }
                 break;
          case 2:isEmptyLStack(&s);
                 break;
          case 3:if(getTopLStack(&s,&num)){	
                         printf("栈顶元素为:%d\n",num);
                 }
                 break;
          case 4:if(clearLStack(&s) ){
	                          printf("清空栈成功\n");
                 }
                 break;
          case 5:if(destroyLStack(&s) ){
	                          printf("销毁栈成功\n");
                              flag=0;
                 }
                 break;
          case 6:if(LStackLength(&s,&num) ){
                          printf("栈长度为%d",num);
                 }
                 break;
          case 7:printf("请输入入栈的值:");
                 while(scanf(" %d", &num)!=1){
                            	printf("请输入整数:");
                                fflush(stdin);
                 } 
                         pushLStack(&s,num);
                 break;
          case 8:if(popLStack(&s,&num) ){
                          printf("出栈的值为:%d",num);
                 }
                 break;
          case 9:exit(0);
       }
	
    }

	
}


