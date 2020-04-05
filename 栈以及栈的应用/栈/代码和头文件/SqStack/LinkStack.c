#include "LinkStack.h"
#include <stdio.h>
#include <malloc.h>


//链栈

//初始化栈
Status initLStack(LinkStack *s){
	if(s==NULL){
	        printf("栈指针为空\n");
        return ERROR;
    }
      s->top=NULL;
      s->count=0;
    return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if(s==NULL){
	        printf("栈指针为空\n");
        return ERROR;
    }
    if(!s->top){
	        printf("栈为空\n");
        return SUCCESS;
    }
      printf("栈不为空\n");
    return ERROR;
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s==NULL){
	        printf("栈指针为空\n");
        return ERROR;
    }
    if(e==NULL){
	        printf("指针e为空\n");
        return ERROR;
    }
    if(!s->top){
	        printf("没有栈顶元素\n");
        return ERROR;
    }
    *e=s->top->data;
    return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack *s){
	if(s==NULL){
	        printf("栈指针为空\n");
        return ERROR;
    }
    while(s->count){
	        LinkStackPtr freeNode=s->top;
            s->top=freeNode->next;
            s->count--;
            free(freeNode);
    }
      s->top=NULL;
    return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack *s){
    return	clearLStack(s);
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	if(s==NULL){
	        printf("栈指针为空\n");
        return ERROR;
    }
    if(length==NULL){
	        printf("指针length为空\n");
        return ERROR;
    }
    *length=s->count;
    return SUCCESS;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
	if(s==NULL){
	        printf("栈指针为空\n");
        return ERROR;
    }
      LinkStackPtr newNode=(LinkStackPtr)malloc(sizeof(StackNode));
      newNode->data=data;
      newNode->next=s->top;
      s->top=newNode; 
      s->count++;
      printf("入栈成功\n");
    return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	if(s==NULL){
	        printf("栈指针为空\n");
        return ERROR;
    }
    if(data==NULL){
	        printf("指针data为空\n");
        return ERROR;
    }
    if(s->count==0){
	        printf("栈内没有元素,出栈失败\n");
        return ERROR;
    }
      LinkStackPtr outNode=s->top;
    *data=outNode->data;
      s->top=outNode->next;
      s->count--;
      free(outNode);
    return SUCCESS;
}


