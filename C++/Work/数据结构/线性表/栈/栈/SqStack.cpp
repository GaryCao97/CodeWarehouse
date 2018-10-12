#include <iostream>
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;

typedef SElemType;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct{
	SElemType *base, *top;
	int stacksize;
}SqStack;

Status InitStatck(SqStack &S);   //��ʼ��ջ
Status DestoryStatck(SqStack &S);  //����ջ
Status ClearStack(SqStack &S);    //���ջ
Status StackEmpty(SqStack S);         //ջ�Ƿ�Ϊ��
int StackLength(SqStack S);        //ջ�ĳ���
Status GetTop(SqStack S, SElemType &e);  //�õ�ջ��
Status Push(SqStack &S, SElemType e);   //ѹջ
Status Pop(SqStack &S, SElemType &e);   //��ջ
Status StackTraverse(SqStack S, Status(*visit)(SElemType));    //��ʾջ�ڵ�Ԫ��

Status InitStatck(SqStack &S){
	S.base = (SElemType*)malloc(STACK_INIT_SIZE*(sizeof(SElemType)));
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
Status DestoryStatck(SqStack &S){
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	return OK;
}
Status ClearStack(SqStack &S){
	S.top = S.base;
	S.stacksize = 0;
	return OK;
}
Status StackEmpty(SqStack S){
	if (S.base == S.top)
		return TRUE;
	else
		return FALSE;
}
int StackLength(SqStack S){
	if (S.base == S.top)
		return ERROR;
	else
		return (S.top - S.base);
}
Status GetTop(SqStack S, SElemType &e){
	if (StackEmpty(S))
		return ERROR;
	e = *(S.top - 1);
	return OK;
}
Status Push(SqStack &S, SElemType e){
	if (S.top - S.base >= S.stacksize){
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!S.base)exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}
Status Pop(SqStack &S, SElemType &e){
	if (StackEmpty(S))
		return ERROR;
	e = *(--S.top);
	return OK;
}
Status StackTraverse(SqStack S, Status(*Visit)(SElemType)){
	if (StackEmpty(S))
		exit(ERROR);
	while (S.top != S.base)
		(*Visit)(--S.top);
	return OK;
}