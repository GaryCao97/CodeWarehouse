#include <iostream>
#include<Windows.h>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
typedef int Status;
typedef char SElemType;
//顺序栈
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct {
	SElemType *base, *top;
	int stacksize;
}SqStack;
Status InitStack_Sq(SqStack &S);   //初始化栈
Status StackEmpty_Sq(SqStack S);         //栈是否为空
int StackLength_Sq(SqStack S);        //栈的长度
Status GetTop_Sq(SqStack S, SElemType &e);  //得到栈顶
Status Push_Sq(SqStack &S, SElemType e);   //压栈
Status Pop_Sq(SqStack &S, SElemType &e);   //出栈
Status InitStack_Sq(SqStack &S) {
	S.base = (SElemType*)malloc(STACK_INIT_SIZE*(sizeof(SElemType)));
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
Status StackEmpty_Sq(SqStack S) {
	if (S.base == S.top)
		return TRUE;
	else
		return FALSE;
}
int StackLength_Sq(SqStack S) {
	if (S.base == S.top)
		return ERROR;
	else
		return (S.top - S.base);
}
Status GetTop_Sq(SqStack S, SElemType &e) {
	if (StackEmpty_Sq(S))
		return ERROR;
	e = *(S.top - 1);
	return OK;
}
Status Push_Sq(SqStack &S, SElemType e) {
	if (S.top - S.base >= S.stacksize) {
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base)exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}
Status Pop_Sq(SqStack &S, SElemType &e) {
	if (StackEmpty_Sq(S))
		return ERROR;
	e = *(--S.top);
	return OK;
}
Status StackTraverse_Sq(SqStack S) {
	//
	if (StackEmpty_Sq(S))
		return ERROR;
	for (SElemType *i = S.top - 1; i >= S.base; i--) {
		cout << *i << ' ';
	}
	cout << endl;
	return OK;
}
//链栈
typedef struct SNode {
	SElemType data;
	SNode *next;
}*SLink, *SPosition;
typedef struct {
	SLink head, tail;
	int  len;
}LinkStack;
Status MakeNode(SLink &p, SElemType e) {
	//分配由p指向的结点并赋值为e
	p = (SLink)malloc(sizeof(SNode));
	if (p) {
		p->data = e;
		p->next = NULL;
	}
	else
		return ERROR;
	return OK;
}
Status InitStack_Link(LinkStack &L) {
	//构造一个由L指向的空的线性表
	SLink p = NULL;
	MakeNode(p, 0);
	if (!p) exit(ERROR);
	L.head = p;
	L.tail = NULL;
	L.len = 0;
	return OK;
}
Status Push_Link(LinkStack &L, SLink s) {
	//将s指向的结点插入线性链表的第一个结点之前
	s->next = L.head->next;
	if (!L.head->next)
		L.tail = s;
	L.head->next = s;
	L.len++;
	return OK;
}
Status Pop_Link(LinkStack &L, SLink &q) {
	//删除表中第一个结点并以q返回
	if (!L.head->next)
		return ERROR;
	q = L.head->next;
	L.head->next = L.head->next->next;
	L.len--;
	return OK;
}
Status GetTop_Link(LinkStack L, SElemType &e) {
	//获得栈顶节点的值
	if (!L.head->next)
		return ERROR;
	e = L.head->next->data;
	return OK;
}
Status StackTraverse_Link(LinkStack L) {
	//
	if (!L.head->next)
		return ERROR;
	SLink p;
	p = L.head->next;
	while (p) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
	return OK;
}

int main() {
	SqStack Q1;
	LinkStack Q2;
	if (InitStack_Link(Q2) && InitStack_Sq(Q1))
		cout << "顺序栈与链栈初始化成功" << endl;
	else return 1;
	Sleep(1000 * 1.5);
	char c1, c2, c3;
	SElemType e;
	do {
		system("cls");
		cout << "请选择需要进行操作的栈：" << endl << "输入1选择顺序栈" << endl << "输入2选择链栈" << endl << "输入其他字符退出" << endl;
		cin >> c1;
		if (c1 == '1') {
			do {
				system("cls");
				cout << "本队列为顺序栈" << endl;
				cout << "请选择要进行的操作:" << endl;
				cout << "入栈-------1" << endl;
				cout << "出栈-------2" << endl;
				cout << "获得栈顶---3" << endl;
				cout << "遍历-------4" << endl;
				cout << "返回-------其他" << endl;
				cin >> c2;
				switch (c2) {
				case '1':
					do {
						system("cls");
						cout << "输入元素e：";
						cin >> e;
						if (Push_Sq(Q1, e)) {
							cout << "插入成功" << endl;
							cout << "顺序栈元素为：";
							StackTraverse_Sq(Q1);
						}
						else
							cout << "插入失败" << endl;
						cout << "继续请按1" << endl << "返回请按其他" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '2':
					do {
						system("cls");
						if (Pop_Sq(Q1, e)) {
							cout << "删除成功" << endl;
							cout << "被删除的元素为：" << e << endl;
							cout << "顺序栈元素为：";
							StackTraverse_Sq(Q1);
						}
						else
							cout << "删除失败" << endl;
						cout << "继续请按1" << endl << "返回请按其他" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '3':
					do {
						system("cls");
						if (GetTop_Sq(Q1, e)) {
							cout << "获取成功" << endl;
							cout << "被获取的元素为：" << e << endl;
							cout << "顺序栈元素为：";
							StackTraverse_Sq(Q1);
						}
						else
							cout << "获取失败" << endl;
						cout << "继续请按1" << endl << "返回请按其他" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '4':
					do {
						system("cls");
						cout << "顺序栈元素为：";
						if (StackTraverse_Sq(Q1)) {
							cout << endl << "遍历成功" << endl;
						}
						else
							cout << endl << "遍历失败" << endl;
						cout << "继续请按1" << endl << "返回请按其他" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				default:
					break;
				}
			} while (c2 >= '1' && c2 <= '4');
		}
		else if (c1 == '2') {
			do {
				system("cls");
				cout << "本队列为链栈" << endl;
				cout << "请选择要进行的操作:" << endl;
				cout << "入栈-------1" << endl;
				cout << "出栈-------2" << endl;
				cout << "获得栈顶---3" << endl;
				cout << "遍历-------4" << endl;
				cout << "返回-------其他" << endl;
				cin >> c2;
				SLink q = NULL;
				switch (c2) {
				case '1':
					do {
						system("cls");
						cout << "输入元素e：";
						cin >> e;
						MakeNode(q, e);
						if (Push_Link(Q2, q)) {
							cout << "插入成功" << endl;
							cout << "链栈元素为：";
							StackTraverse_Link(Q2);
						}
						else
							cout << "插入失败" << endl;
						cout << "继续请按1" << endl << "返回请按其他" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '2':
					do {
						system("cls");
						if (Pop_Link(Q2, q)) {
							cout << "删除成功" << endl;
							cout << "被删除的元素为：" << q->data << endl;
							cout << "链栈元素为：";
							StackTraverse_Link(Q2);
						}
						else
							cout << "删除失败" << endl;
						cout << "继续请按1" << endl << "返回请按其他" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '3':
					do {
						system("cls");
						if (GetTop_Link(Q2, e)) {
							cout << "获取成功" << endl;
							cout << "被获取的元素为：" << e << endl;
							cout << "链栈元素为：";
							StackTraverse_Link(Q2);
						}
						else
							cout << "获取失败" << endl;
						cout << "继续请按1" << endl << "返回请按其他" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '4':
					do {
						system("cls");
						cout << "链栈元素为：";
						if (StackTraverse_Link(Q2)) {
							cout << endl << "遍历成功" << endl;
						}
						else
							cout << endl << "遍历失败" << endl;
						cout << "继续请按1" << endl << "返回请按其他" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				default:
					break;
				}
			} while (c2 >= '1' && c2 <= '4');
		}
		else
			break;
	} while (c1 == '1' || c1 == '2');
	return 0;
}