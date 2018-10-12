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

Status InitStatck(SqStack &S);   //初始化栈
Status DestoryStatck(SqStack &S);  //销毁栈
Status ClearStack(SqStack &S);    //清除栈
Status StackEmpty(SqStack S);         //栈是否为空
int StackLength(SqStack S);        //栈的长度
Status GetTop(SqStack S, SElemType &e);  //得到栈顶
Status Push(SqStack &S, SElemType e);   //压栈
Status Pop(SqStack &S, SElemType &e);   //出栈
Status StackTraverse(SqStack S, Status(*visit)(SElemType));    //显示栈内的元素

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