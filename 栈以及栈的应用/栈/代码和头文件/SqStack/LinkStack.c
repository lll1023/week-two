#include "LinkStack.h"
#include <stdio.h>
#include <malloc.h>


//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s){
	if(s==NULL){
	        printf("ջָ��Ϊ��\n");
        return ERROR;
    }
      s->top=NULL;
      s->count=0;
    return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if(s==NULL){
	        printf("ջָ��Ϊ��\n");
        return ERROR;
    }
    if(!s->top){
	        printf("ջΪ��\n");
        return SUCCESS;
    }
      printf("ջ��Ϊ��\n");
    return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s==NULL){
	        printf("ջָ��Ϊ��\n");
        return ERROR;
    }
    if(e==NULL){
	        printf("ָ��eΪ��\n");
        return ERROR;
    }
    if(!s->top){
	        printf("û��ջ��Ԫ��\n");
        return ERROR;
    }
    *e=s->top->data;
    return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s){
	if(s==NULL){
	        printf("ջָ��Ϊ��\n");
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

//����ջ
Status destroyLStack(LinkStack *s){
    return	clearLStack(s);
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	if(s==NULL){
	        printf("ջָ��Ϊ��\n");
        return ERROR;
    }
    if(length==NULL){
	        printf("ָ��lengthΪ��\n");
        return ERROR;
    }
    *length=s->count;
    return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	if(s==NULL){
	        printf("ջָ��Ϊ��\n");
        return ERROR;
    }
      LinkStackPtr newNode=(LinkStackPtr)malloc(sizeof(StackNode));
      newNode->data=data;
      newNode->next=s->top;
      s->top=newNode; 
      s->count++;
      printf("��ջ�ɹ�\n");
    return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	if(s==NULL){
	        printf("ջָ��Ϊ��\n");
        return ERROR;
    }
    if(data==NULL){
	        printf("ָ��dataΪ��\n");
        return ERROR;
    }
    if(s->count==0){
	        printf("ջ��û��Ԫ��,��ջʧ��\n");
        return ERROR;
    }
      LinkStackPtr outNode=s->top;
    *data=outNode->data;
      s->top=outNode->next;
      s->count--;
      free(outNode);
    return SUCCESS;
}


