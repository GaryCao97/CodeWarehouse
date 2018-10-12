#include<iostream>
#include<malloc.h>
#include<windows.h>
using namespace std;
#define OK 1
#define ERROR 0 
typedef int Status;
typedef int ElemType;


typedef struct DuLNode{
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode, *DuLinkList;

//1) ��˫�������в��ҵ�i����㡣

DuLinkList GetElemP_DuL(DuLinkList L, int i) {
	// LΪ��ͷ���ĵ������ͷָ�롣
	DuLinkList p;
	p = L->next;
	int j = 1;  // ��ʼ����pָ���һ����㣬jΪ������
	while (p != L && j<i) { //˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
		p = p->next;
		++j;
	}
	if (p == L && j<i) return NULL;  // ��i��Ԫ�ز�����
	else return p;
} // GetElem_L

//2) ��˫������ĵ�i�����ǰ����һ����㡣

Status ListInsert_DuL(DuLinkList &L, int i, ElemType e){
	//�ڴ�ͷ����˫��ѭ�����Ա�L�е�i��λ��֮ǰ����Ԫ��e
	DuLNode *s;
	DuLNode *p;
	if (!(p = GetElemP_DuL(L, i)))
		return ERROR;
	if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))
		return ERROR;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;//��ǰһ���ڵ�Ĳ��� 
	s->next = p;
	p->prior = s;//���һ�����Ĳ��� 
	return OK;
}//ListInsert_DuL

//3) ��˫������ĵ�i�����ǰɾ��һ����㡣

Status ListDelete_DuL(DuLinkList &L, int i, ElemType &e){
	DuLNode *p;
	if(!(p=GetElemP_DuL(L,i)))
		return ERROR;
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}//ListDelete_DuL

//4) ����˫�������е�i������ֵ

Status UpdateLinkList_DuL(DuLinkList &L, int i, ElemType e){
	DuLNode *p = L->next;
	int j = 1;
	for (j; j<i - 1; j++){
		p = p->next;
	}
	if (!(p || j>i - 1))
		return ERROR;
	p->data = e;
	return OK;
}//UpdateLinkList_DuL

//5) ����˫������

Status DuLinkListTraverse_DuL(DuLinkList L){
	DuLNode *p = L->next;
	if (!p)
		return ERROR;
	cout << "��ǰ˫������ֵ�� ";
	while (p != L){
		cout << p->data << " ";
		p = p->next;
	}
	return OK;
}

int main(){
	ElemType e;
	DuLinkList L;
	int N, num;
	L = (DuLinkList)malloc(sizeof(DuLNode));
	L->next = L;
	L->prior = L;
	DuLNode *p = L->next;
	//cout<<"������ӭ���빦�ܲ˵�����"<<endl; 
	cout << "������˫�������Ԫ�ظ����� ";
	cin >> num;
	cout << endl << endl;
	cout << "����������Ԫ�ص�ֵ�� ";
	for (int j = 1; j <= num; j++){
		cout << "��" << j << "��Ԫ�ص�ֵ�� " << endl;
		cin >> e;
		ListInsert_DuL(L, j, e);
	}
	Sleep(1000);
	system("cls");
loop:{
	cout << "***--��ӭ����˵�--***" << endl;
	cout << endl;
	cout << "~~��ѡ����Ҫ���еĹ��ܵ���ţ�" << endl;
	cout << "1) �ڵ�i���ڵ�֮ǰ����һ���ڵ㣻" << endl;
	cout << "2) �ڵ�i���ڵ�֮ǰɾ��һ���ڵ㣻" << endl;
	cout << "3) ��˫�������в��ҵ�i�����;" << endl;
	cout << "4) ����˫�������е�i������ֵ;" << endl;
	cout << "5) ����˫������;" << endl;
	cin >> num;
	switch (num)
	{
	case 1:
		cout << "��������Ҫ�����λ�ã� ";
		cin >> N;
		cout << endl;
		cout << "��������Ҫ�����Ԫ��ֵ�� ";
		cin >> e;
		ListInsert_DuL(L, N, e);
		DuLinkListTraverse_DuL(L);
		break;
	case 2:
		cout << "��������Ҫɾ����λ�ã� ";
		cin >> N;
		cout << endl;
		ListDelete_DuL(L, N, e);
		cout << "��ɾ���Ľ���ֵΪ" << e << endl;
		DuLinkListTraverse_DuL(L);
		break;
	case 3:
		cout << "����������Ҫ���ҵĽ���λ�ã� ";
		cin >> N;
		cout << endl;
		e = GetElemP_DuL(L, N)->data;
		cout << "�ý���ֵΪ" << e << endl;
		DuLinkListTraverse_DuL(L);
		break;
	case 4:
		cout << "������������µĽ���λ�ã� ";
		cin >> N;
		cout << endl;
		cout << "��������Ҫ���µ�ֵ�� ";
		cin >> e;
		cout << endl;
		UpdateLinkList_DuL(L, N, e);
		DuLinkListTraverse_DuL(L);
		break;
	case 5:
		DuLinkListTraverse_DuL(L);
		exit(0);
	default:
		cout << "������1��5֮������֣�" << endl;
		break;
	}
	goto loop;
}
}
