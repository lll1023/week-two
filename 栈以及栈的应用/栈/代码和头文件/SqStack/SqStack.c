#include "SqStack.h"
#include <malloc.h>
#include <stdio.h>

//���������˳��ջ

//��ʼ��ջ
Status initStack(SqStack *s,int sizes){
    if(s==NULL){
	        printf("ջָ��Ϊ��\n");
	    return ERROR;
    }
      s->elem=(ElemType*)malloc(sizes*sizeof(ElemType));
    if(!s->elem){
	     printf("��ʼ��ʧ��\n");
      return ERROR;
    }
      s->top=-1;
      s->size=sizes;
      printf("��ʼ��ջ�ɹ�\n");
    return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack *s){
	if(s==NULL){
       	  printf("ջָ��Ϊ��\n");
       return ERROR;
    }
	if(s->top>-1){
	        printf("ջ��Ϊ��\n");
        return ERROR;
    }
      printf("ջΪ��\n");
    return SUCCESS;
}

//�õ�ջ��Ԫ��
Status getTopStack(SqStack *s,ElemType *e){
	if(s==NULL){
	        printf("ջָ��Ϊ��\n");
        return ERROR;
    }
    if(e==NULL){
	        printf("ָ��eΪ��\n");
        return ERROR;
    }
    if(s->top==-1){
	        printf("û��ջ��Ԫ��\n");
        return ERROR;
    }
    *e=s->elem[s->top];
    return SUCCESS;
}

//���ջ
Status clearStack(SqStack *s){
	if(s==NULL){
	        printf("ջָ��Ϊ��\n");
        return ERROR;
    }
    if(!s->elem){
    	    printf("ջδ��ʼ��\n");
        return ERROR;
    }else if(s->top==-1){
            printf("ջ��û��Ԫ��,�������\n");	
        return ERROR;
    }
    while(s->top!=-1){
	        s->top--;
    }
      printf("�ɹ����ջ\n");
    return SUCCESS;
}

//����ջ
Status destroyStack(SqStack *s){
	if(s==NULL){
	        printf("ջָ��Ϊ��\n");
        return ERROR;
    }
    if(!s->elem){
	        free(s->elem);
    }
      s->top=-1;
      s->size=0;
      printf("����ջ�ɹ�\n");
    return SUCCESS;
}

//���ջ����
Status stackLength(SqStack *s,int *length){
	if(s==NULL){
	        printf("ջָ��Ϊ��\n");
        return ERROR;
    }
	if(length==NULL){
	        printf("ָ��lengthΪ��\n");
        return ERROR;  
    }
    *length=s->top+1;
    return SUCCESS;
}

//��ջ
Status pushStack(SqStack *s,ElemType data){
	if(s==NULL){
	        printf("ջָ��Ϊ��\n");
        return ERROR;
    }
    if(s->top+1>=s->size){
     	    printf("ջ���ȳ���,�޷���ջ\n");
        return ERROR;
    }
      s->top++;
      s->elem[s->top]=data;
    return SUCCESS;
}

//��ջ
Status popStack(SqStack *s,ElemType *data){
	if(s==NULL){
	        printf("ջָ��Ϊ��\n");
        return ERROR;
    }
    if(s->top==-1){
	        printf("ջ��û��ֵ\n");
        return ERROR;
    }
    *data=s->elem[s->top];
      s->top--;
    return SUCCESS;
}

