#include<iostream>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;
typedef int SElemType;
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 1
typedef struct{
	SElemType *base, *top;
	int stacksize;
}SqStack;
Status InitStatck(SqStack &S){
	S.base = (SElemType*)malloc(STACK_INIT_SIZE*(sizeof(SElemType)));
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
int StackLength(SqStack S){
	if (S.base == S.top)
		return ERROR;
	else
		return (S.top - S.base);
}
Status StackEmpty(SqStack S){
	if (S.base == S.top)
		return TRUE;
	else
		return FALSE;
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
int main(){
	char input;
	int num = 0;
	do{
		input = getchar();
		if (input < '0' || input > '9')
			break;
		num += (int)(input - '0');
	} while (true);
	SqStack number;
	InitStatck(number);
	while (num != 0){
		Push(number, num % 10);
		num /= 10;
	}
	int n = StackLength(number);
	for (int i = 0; i < n; i++){
		int j;
		Pop(number, j);
		switch (j){
		case 0:cout << "ling"; break;
		case 1:cout << "yi"; break;
		case 2:cout << "er"; break;
		case 3:cout << "san"; break;
		case 4:cout << "si"; break;
		case 5:cout << "wu"; break;
		case 6:cout << "liu"; break;
		case 7:cout << "qi"; break;
		case 8:cout << "ba"; break;
		case 9:cout << "jiu"; break;
		}
		if (i < n - 1)
			cout << ' ';
	}
	return 0;
}