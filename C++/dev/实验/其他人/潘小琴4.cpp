//˫������Ļ�������
// 1)˫����������Ķ��塣
//2)˫��������Ķ��塣
//3)��˫������ĵ�i�����ǰ����һ����㡣
//4)��˫������ĵ�i�����ǰɾ��һ����㡣
//5)��˫�������в��ҵ�i����㡣
//6)����˫�������е�i������ֵ��
//7)����˫������

# include<iostream>
#include <stdlib.h>
#include <stdio.h>

# define OK 1
# define ERROR 0
# define OVERFLOW -2 

typedef int ElemType;
typedef int Status;
using namespace std;
typedef struct DNode{
	ElemType  data;
	struct  DNode *prior;
	struct  DNode *next;
}*DuLNode;
typedef struct {          //�������� 
	DuLNode head;
	int len;
}DuLinkList;


Status InitList(DuLinkList &L)          //��ʼ�������� 
{
	L.head = (DuLNode)malloc(sizeof(DNode));
	if (!L.head) exit(OVERFLOW);
	L.head->next = NULL;
	L.head->prior = NULL;
	L.head->data = 0;
	L.len = 0;
	return OK;
}
Status MakeNode(DuLNode &p, ElemType e){       //������� 
	p = (DuLNode)malloc(sizeof(DNode));
	if (!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	p->prior = NULL;
	return OK;
}
Status ListInsert(DuLinkList &L, int i, ElemType e)    //�ڵ�i��λ��ǰ����Ԫ��e 
{
	DuLNode p = L.head, s;
	int j = 0;
	while (p&&j<i-1)    //�ҵ���i-1��λ�� 
	{
		p = p->next;
		++j;
	}
	if (!p || j>i-1)
		return ERROR;
	MakeNode(s, e);
	s->next = p->next;
	s->prior = p;
	if (p->next)
		p->next->prior = s;
	p->next = s;
	++L.len;
	return OK;
}

Status ListDelet(DuLinkList &L, int i, ElemType &e)    //�ڵ�i��λ��ɾ����e 
{
	DuLNode p = L.head;
	int j = 0;
	while (p->next&&j<i){        //�ҵ���i�����
		p = p->next;
		++j;
	}
	if (!p || j>i)  //�жϵ�i������Ƿ���� 
		return ERROR;
	e = p->data;
	p->prior->next = p->next;
	if (p->next)
		p->next->prior = p->prior;
	--L.len;
	return OK;
}




Status ChangeElem(DuLinkList &L, int i, ElemType e){            //����˫�����е�i��Ԫ�ص�ֵ��
	DuLNode p = L.head;
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
Status GetElem(DuLinkList L, int i, ElemType &e){              //˫�����в��ҵ�i��Ԫ�ء�
	DuLNode p = L.head;
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
Status ListTraversse(DuLinkList L)                      //����˫���� 
{
	DuLNode p = L.head;
	while (p->next){                 //Ӧ����Ҫ�жϵ�ǰ������һ���ڵ��Ƿ�ΪNULL
		p = p->next;
		cout << p->data << " ";
	}
	return OK;
}
void menu(){
	cout << endl << "--------------�˵�---------------" << endl;
	cout << "1).��ʾ˫����" << endl;
	cout << "2).��˫����ĵ�i��Ԫ��ǰ����һ��Ԫ��" << endl;
	cout << "3).��˫����ĵ�i��Ԫ��ǰɾ��һ��Ԫ�ء�" << endl;
	cout << "4).��˫�����в��ҵ�i��Ԫ��" << endl;
	cout << "5).����˫�����е�i��Ԫ�ص�ֵ��" << endl;
	cout << "   (�����������ݽ�������)" << endl;

}

int main(){
	DuLinkList LL;
	int n = 0;
	InitList(LL);
	cout << "˫����" << endl << "����Ҫ��������ݸ���n��";
	cin >> n;
	cout << "������n������:";
	for (int i = 1; i <= n; i++){
		ElemType a = 0;
		cin >> a;
		ListInsert(LL, i, a);
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
				while (i<0 || i>LL.len)
				{
					cout << "����λ�ò��������������룡" << endl;
					cout << "����λ�ã�";	cin >> i;
				}
				cout << "�������ݣ�"; cin >> e;
				ListInsert(LL, i, e);
				break;
			case 3:
				cout << "ɾ��λ�ã�";	cin >> i;
				while (i<0 || i>LL.len)
				{
					cout << "����λ�ò��������������룡" << endl;
					cout << "ɾ��λ�ã�";	cin >> i;
				}
				ListDelet(LL, i, e);
				cout << "ɾ������Ϊ��" << e << endl;
				break;
			case 4:
				cout << "����λ�ã�";	cin >> i;
				while (i<0 || i>LL.len)
				{
					cout << "����λ�ò��������������룡" << endl;
					cout << "����λ�ã�";	cin >> i;
				}
				GetElem(LL, i, e);
				cout << "���ҵ�����Ϊ��" << e << endl;
				break;
			case 5:
				cout << "���µ�����λ�ã�";	cin >> i;
				while (i<0 || i>LL.len)
				{
					cout << "����λ�ò��������������룡" << endl;
					cout << "����λ�ã�";	cin >> i;
				}
				cout << "���º������Ϊ��"; cin >> e;
				ChangeElem(LL, i, e);
				break;
			}
		}
	} while (xh>0 && xh<6);
	return 0;
}
