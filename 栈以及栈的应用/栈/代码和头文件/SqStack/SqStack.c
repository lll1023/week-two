#include "SqStack.h"
#include <malloc.h>
#include <stdio.h>

//基于数组的顺序栈

//初始化栈
Status initStack(SqStack *s,int sizes){
    if(s==NULL){
	        printf("栈指针为空\n");
	    return ERROR;
    }
      s->elem=(ElemType*)malloc(sizes*sizeof(ElemType));
    if(!s->elem){
	     printf("初始化失败\n");
      return ERROR;
    }
      s->top=-1;
      s->size=sizes;
      printf("初始化栈成功\n");
    return SUCCESS;
}

//判断栈是否为空
Status isEmptyStack(SqStack *s){
	if(s==NULL){
       	  printf("栈指针为空\n");
       return ERROR;
    }
	if(s->top>-1){
	        printf("栈不为空\n");
        return ERROR;
    }
      printf("栈为空\n");
    return SUCCESS;
}

//得到栈顶元素
Status getTopStack(SqStack *s,ElemType *e){
	if(s==NULL){
	        printf("栈指针为空\n");
        return ERROR;
    }
    if(e==NULL){
	        printf("指针e为空\n");
        return ERROR;
    }
    if(s->top==-1){
	        printf("没有栈顶元素\n");
        return ERROR;
    }
    *e=s->elem[s->top];
    return SUCCESS;
}

//清空栈
Status clearStack(SqStack *s){
	if(s==NULL){
	        printf("栈指针为空\n");
        return ERROR;
    }
    if(!s->elem){
    	    printf("栈未初始化\n");
        return ERROR;
    }else if(s->top==-1){
            printf("栈内没有元素,无需清空\n");	
        return ERROR;
    }
    while(s->top!=-1){
	        s->top--;
    }
      printf("成功清空栈\n");
    return SUCCESS;
}

//销毁栈
Status destroyStack(SqStack *s){
	if(s==NULL){
	        printf("栈指针为空\n");
        return ERROR;
    }
    if(!s->elem){
	        free(s->elem);
    }
      s->top=-1;
      s->size=0;
      printf("销毁栈成功\n");
    return SUCCESS;
}

//检测栈长度
Status stackLength(SqStack *s,int *length){
	if(s==NULL){
	        printf("栈指针为空\n");
        return ERROR;
    }
	if(length==NULL){
	        printf("指针length为空\n");
        return ERROR;  
    }
    *length=s->top+1;
    return SUCCESS;
}

//入栈
Status pushStack(SqStack *s,ElemType data){
	if(s==NULL){
	        printf("栈指针为空\n");
        return ERROR;
    }
    if(s->top+1>=s->size){
     	    printf("栈长度超出,无法入栈\n");
        return ERROR;
    }
      s->top++;
      s->elem[s->top]=data;
    return SUCCESS;
}

//出栈
Status popStack(SqStack *s,ElemType *data){
	if(s==NULL){
	        printf("栈指针为空\n");
        return ERROR;
    }
    if(s->top==-1){
	        printf("栈内没有值\n");
        return ERROR;
    }
    *data=s->elem[s->top];
      s->top--;
    return SUCCESS;
}

