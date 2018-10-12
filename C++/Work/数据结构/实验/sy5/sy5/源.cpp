#include <iostream>
#include<Windows.h>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
typedef int Status;
typedef char SElemType;
//˳��ջ
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct {
	SElemType *base, *top;
	int stacksize;
}SqStack;
Status InitStack_Sq(SqStack &S);   //��ʼ��ջ
Status StackEmpty_Sq(SqStack S);         //ջ�Ƿ�Ϊ��
int StackLength_Sq(SqStack S);        //ջ�ĳ���
Status GetTop_Sq(SqStack S, SElemType &e);  //�õ�ջ��
Status Push_Sq(SqStack &S, SElemType e);   //ѹջ
Status Pop_Sq(SqStack &S, SElemType &e);   //��ջ
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
//��ջ
typedef struct SNode {
	SElemType data;
	SNode *next;
}*SLink, *SPosition;
typedef struct {
	SLink head, tail;
	int  len;
}LinkStack;
Status MakeNode(SLink &p, SElemType e) {
	//������pָ��Ľ�㲢��ֵΪe
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
	//����һ����Lָ��Ŀյ����Ա�
	SLink p = NULL;
	MakeNode(p, 0);
	if (!p) exit(ERROR);
	L.head = p;
	L.tail = NULL;
	L.len = 0;
	return OK;
}
Status Push_Link(LinkStack &L, SLink s) {
	//��sָ��Ľ�������������ĵ�һ�����֮ǰ
	s->next = L.head->next;
	if (!L.head->next)
		L.tail = s;
	L.head->next = s;
	L.len++;
	return OK;
}
Status Pop_Link(LinkStack &L, SLink &q) {
	//ɾ�����е�һ����㲢��q����
	if (!L.head->next)
		return ERROR;
	q = L.head->next;
	L.head->next = L.head->next->next;
	L.len--;
	return OK;
}
Status GetTop_Link(LinkStack L, SElemType &e) {
	//���ջ���ڵ��ֵ
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
		cout << "˳��ջ����ջ��ʼ���ɹ�" << endl;
	else return 1;
	Sleep(1000 * 1.5);
	char c1, c2, c3;
	SElemType e;
	do {
		system("cls");
		cout << "��ѡ����Ҫ���в�����ջ��" << endl << "����1ѡ��˳��ջ" << endl << "����2ѡ����ջ" << endl << "���������ַ��˳�" << endl;
		cin >> c1;
		if (c1 == '1') {
			do {
				system("cls");
				cout << "������Ϊ˳��ջ" << endl;
				cout << "��ѡ��Ҫ���еĲ���:" << endl;
				cout << "��ջ-------1" << endl;
				cout << "��ջ-------2" << endl;
				cout << "���ջ��---3" << endl;
				cout << "����-------4" << endl;
				cout << "����-------����" << endl;
				cin >> c2;
				switch (c2) {
				case '1':
					do {
						system("cls");
						cout << "����Ԫ��e��";
						cin >> e;
						if (Push_Sq(Q1, e)) {
							cout << "����ɹ�" << endl;
							cout << "˳��ջԪ��Ϊ��";
							StackTraverse_Sq(Q1);
						}
						else
							cout << "����ʧ��" << endl;
						cout << "�����밴1" << endl << "�����밴����" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '2':
					do {
						system("cls");
						if (Pop_Sq(Q1, e)) {
							cout << "ɾ���ɹ�" << endl;
							cout << "��ɾ����Ԫ��Ϊ��" << e << endl;
							cout << "˳��ջԪ��Ϊ��";
							StackTraverse_Sq(Q1);
						}
						else
							cout << "ɾ��ʧ��" << endl;
						cout << "�����밴1" << endl << "�����밴����" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '3':
					do {
						system("cls");
						if (GetTop_Sq(Q1, e)) {
							cout << "��ȡ�ɹ�" << endl;
							cout << "����ȡ��Ԫ��Ϊ��" << e << endl;
							cout << "˳��ջԪ��Ϊ��";
							StackTraverse_Sq(Q1);
						}
						else
							cout << "��ȡʧ��" << endl;
						cout << "�����밴1" << endl << "�����밴����" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '4':
					do {
						system("cls");
						cout << "˳��ջԪ��Ϊ��";
						if (StackTraverse_Sq(Q1)) {
							cout << endl << "�����ɹ�" << endl;
						}
						else
							cout << endl << "����ʧ��" << endl;
						cout << "�����밴1" << endl << "�����밴����" << endl;
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
				cout << "������Ϊ��ջ" << endl;
				cout << "��ѡ��Ҫ���еĲ���:" << endl;
				cout << "��ջ-------1" << endl;
				cout << "��ջ-------2" << endl;
				cout << "���ջ��---3" << endl;
				cout << "����-------4" << endl;
				cout << "����-------����" << endl;
				cin >> c2;
				SLink q = NULL;
				switch (c2) {
				case '1':
					do {
						system("cls");
						cout << "����Ԫ��e��";
						cin >> e;
						MakeNode(q, e);
						if (Push_Link(Q2, q)) {
							cout << "����ɹ�" << endl;
							cout << "��ջԪ��Ϊ��";
							StackTraverse_Link(Q2);
						}
						else
							cout << "����ʧ��" << endl;
						cout << "�����밴1" << endl << "�����밴����" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '2':
					do {
						system("cls");
						if (Pop_Link(Q2, q)) {
							cout << "ɾ���ɹ�" << endl;
							cout << "��ɾ����Ԫ��Ϊ��" << q->data << endl;
							cout << "��ջԪ��Ϊ��";
							StackTraverse_Link(Q2);
						}
						else
							cout << "ɾ��ʧ��" << endl;
						cout << "�����밴1" << endl << "�����밴����" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '3':
					do {
						system("cls");
						if (GetTop_Link(Q2, e)) {
							cout << "��ȡ�ɹ�" << endl;
							cout << "����ȡ��Ԫ��Ϊ��" << e << endl;
							cout << "��ջԪ��Ϊ��";
							StackTraverse_Link(Q2);
						}
						else
							cout << "��ȡʧ��" << endl;
						cout << "�����밴1" << endl << "�����밴����" << endl;
						cin >> c3;
					} while (c3 == '1');
					break;
				case '4':
					do {
						system("cls");
						cout << "��ջԪ��Ϊ��";
						if (StackTraverse_Link(Q2)) {
							cout << endl << "�����ɹ�" << endl;
						}
						else
							cout << endl << "����ʧ��" << endl;
						cout << "�����밴1" << endl << "�����밴����" << endl;
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