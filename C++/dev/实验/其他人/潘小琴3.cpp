//ʵ���� ������Ļ�������
//1������������Ķ���
//2����������Ķ���
//3)	�ڵ�����ǰɾ��һ��Ԫ�ء�
//4)	�ڵ������ҵ�i��Ԫ�ء�
//5)	���µ�����i��Ԫ�ص�ֵ��
//6)	����������

# include<iostream>
#include <stdlib.h>
#include <stdio.h>

# define OK 1
# define ERROR 0
# define OVERFLOW -2
typedef int ElemType;
typedef int Status;
using namespace std;

typedef struct  LNode {            //������� 
	ElemType data;
	struct  LNode *next;
} *Link, *Position;

typedef struct {          //�������� 
	Link head, tail;
	int len;
} LinkList;

Status InitList(LinkList &L)          //��ʼ�������� 
{
	L.head = (Link)malloc(sizeof(LNode));
	if (!L.head) exit(OVERFLOW);
	L.tail = L.head;
	L.head->next = NULL;
	L.len = 0;
	return OK;
}

Status MakeNode(Link &p, ElemType e){       //������� 
	p = (Link)malloc(sizeof(LNode));
	if (!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	return OK;
}

Status ListInsert_L(LinkList &L, int i, ElemType e){   //������
	Link p = L.head, s;
	int j = 0;
	while (p&&j<i - 1){
		p = p->next;
		++j;
	}
	if (!p || j>i - 1)
		return ERROR;
	MakeNode(s, e);
	s->next = p->next;
	p->next = s;
	++L.len;
	return OK;
}
Status ListDelete_L(LinkList &L, int i, ElemType &e){  //ɾ�����
	Link p = L.head;
	int j = 0;
	while (p->next&&j<i - 1){        //�ҵ���i�����,��ʹ��pָ������ǰ��
		p = p->next;
		++j;
	}
	if (!(p->next) || j>i + 1)  //�жϵ�i������Ƿ���� 
		return ERROR;
	e = p->next->data;
	p->next = p->next->next;
	--L.len;
	return OK;
}

Status GetElem(LinkList L, int i, ElemType &e){              //�ڵ������в��ҵ�i��Ԫ�ء�
	Link p = L.head;
	int j = 0;
	while (p &&j<i)    //�ҵ���i�����
	{
		p = p->next; ++j;
	}
	if (!p || j>i)
		return ERROR;
	e = p->data;
	return OK;
}

Status ChangeElem(LinkList &L, int i, ElemType e){            //���µ������е�i��Ԫ�ص�ֵ��
	Link p = L.head;
	int j = 0;
	while (p &&j<i)     //�ҵ���i�����
	{
		p = p->next; ++j;
	}
	if (!p || j>i)
		return ERROR;
	p->data = e;
	return OK;
}

Status ListTraversse(LinkList L)                            //����˳���
{
	Link p = L.head->next;
	while (p)//Ӧ����Ҫ�жϵ�ǰ������һ���ڵ��Ƿ�ΪNULL
	{
		cout << p->data << " ";
		p = p->next;
	}
	return OK;
}


void menu(){
	cout << endl << "--------------�˵�---------------" << endl;
	cout << "1).��ʾ������" << endl;
	cout << "2).�ڵ�����ĵ�i��Ԫ��ǰ����һ��Ԫ��" << endl;
	cout << "3).�ڵ�����ĵ�i��Ԫ��ǰɾ��һ��Ԫ�ء�" << endl;
	cout << "4).�ڵ������в��ҵ�i��Ԫ��" << endl;
	cout << "5).���µ������е�i��Ԫ�ص�ֵ��" << endl;
	cout << "   (�����������ݽ�������)" << endl;
}

int main(){
	LinkList LL;
	int n;
	InitList(LL);
	cout << "������" << endl << "����Ҫ��������ݸ���n��";
	cin >> n;
	cout << "������n������:";
	for (int i = 1; i <= n; i++){
		int a = 0;
		cin >> a;
		ListInsert_L(LL, i, a);
	}
	int xh = 0;
	int i = 0, e = 0;
	do
	{
		menu();
		cout << endl << "������˵����:";                          //����˵�ѡ�� 
		cin >> xh;
		if (xh>0 && xh<6)
		{
			switch (xh){
			case 1:
				ListTraversse(LL); 
				break;
			case 2:
				cout << "����λ�ã�";	cin >> i;
				cout << "�������ݣ�"; cin >> e;
				ListInsert_L(LL, i, e);
				break;
			case 3:
				cout << "ɾ��λ�ã�";	cin >> i;
				ListDelete_L(LL, i, e);
				cout << "ɾ������Ϊ��" << e << endl;
				break;
			case 4:
				cout << "����λ�ã�";	cin >> i;
				GetElem(LL, i, e);
				cout << "���ҵ�����Ϊ��" << e << endl;
				break;
			case 5:
				cout << "���µ�����λ�ã�";	cin >> i;
				cout << "���º������Ϊ��"; cin >> e;
				ChangeElem(LL, i, e);
				break;
			}
		}
	} while (xh>0 && xh<6);
	return 0;
}
