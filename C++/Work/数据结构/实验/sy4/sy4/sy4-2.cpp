//˫��ѭ������
#include<iostream>
#include<stdlib.h>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
typedef int Status;
typedef char ElemType;//���ж���Ԫ������ 

typedef struct DuLNode{
	ElemType data;
	struct DuLNode *prior, *next;
}*DLink, *DuLPosition;
typedef struct {
	DLink head, tail;
	int  len;
}DuLinkList;

Status MakeNode(DLink &p, ElemType e);//������pָ��Ľ�㲢��ֵΪe
void FreeNode(DLink &p);//�ͷ�p��ָ��Ľ��
Status InitList(DuLinkList &L);//����һ����Lָ��Ŀյ����Ա�
Status DestroyList(DuLinkList &L);//������Lָ������Ա�
Status InsertElem(DuLinkList &L, int i, DLink s);//����
Status DeleteElem(DuLinkList &L, int i);//ɾ��
Status SetCurElem(DLink &p, ElemType e);//��e����p��ָ��ĵ�ǰ���
ElemType GetCurElem(DLink p);//����p��ָ�����Ԫ�ص�ֵ
Status LisEmpty(DuLinkList L);//�ж����Ա��Ƿ�Ϊ��
int Listlength(DuLinkList L);//�������Ա���Ԫ�ظ���
Status LocatePos(DuLinkList L, int i, DLink &p);//��p�������Ա�l�е�i������λ�ã�������ok
Status ListTraverse(DuLinkList L, Status(*visit)(ElemType));//��һ�����������������н��

Status MakeNode(DLink &p, ElemType e){
	//������pָ��Ľ�㲢��ֵΪe
	p = (DLink)malloc(sizeof(struct DuLNode));
	if (p){
		p->data = e;
		p->next = NULL;
		p->prior = NULL;
	}
	else
		return ERROR;
	return OK;
}
void FreeNode(DLink &p){
	//�ͷ�p��ָ��Ľ��
	free(p);
}
Status InitList(DuLinkList &L){
	//����һ����Lָ��Ŀյ����Ա�
	DLink p = NULL;
	MakeNode(p, 0);
	if (!p) exit(ERROR);
	L.head = p;
	L.head->next = L.head;
	L.head->prior = L.head;
	L.tail = p;
	L.len = 0;
	for (int i = 1; i <= 5; i++){
		DLink s;
		ElemType e = i + '0';
		MakeNode(s, e);
		InsertElem(L, i, s);
	}
	return OK;
}
Status DestroyList(DuLinkList &L){
	//������Lָ������Ա�
	DLink p = NULL;
	DLink t = NULL;
	p = L.head;
	while (p->next != L.head){
		t = p->next;
		FreeNode(p);
		p = t;
	}
	L.len = 0;
	return TRUE;
}
Status InsertElem(DuLinkList &L, int i, DLink s){
	//���� 
	DLink p;
	if (i < 1 || i > L.len + 1)
		return ERROR;
	p = L.head;
	i--;
	while (i){
		p = p->next;
		i--;
	}
	s->next = p->next;
	p->next = s;
	s->next->prior = s;
	s->prior = p;
	if (p->next == L.head)
		L.tail = s;
	L.len++;
	return OK;
}
Status DeleteElem(DuLinkList &L, int i){
	//ɾ��
	DLink p;
	if (i < 2 || i > L.len + 1)
		return ERROR;
	p = L.head;
	i -= 2;
	while (i){
		p = p->next;
		i--;
	}
	p->next = p->next->next;
	p->next->prior = p;
	L.len--;
	return OK;
}
Status SetCurElem(DLink &p, ElemType e){
	//��e����p��ָ��ĵ�ǰ���
	p->data = e;
	return OK;
}
ElemType GetCurElem(DLink p){
	//����p��ָ�����Ԫ�ص�ֵ
	return p->data;
}
Status LocatePos(DuLinkList L, int i, DLink &p){
	//��p�������Ա�l�е�i������λ�ã�������ok
	p = L.head;
	if (i <= 0 || i > L.len)
		return ERROR;
	while (i){
		p = p->next;
		i--;
	}
	return OK;
}
Status VisitElem(ElemType e){
	if (e == '\0')
		return ERROR;
	cout << e;
	return OK;
}
Status ListTraverse(DuLinkList L, Status(*visit)(ElemType)){
	//��һ�����������������н��
	DLink p;
	int i = 0;
	if (!L.len)
		return ERROR;
	p = L.head->next;
	while (p && (*visit)(p->data) && (++i)){
		p = p->next;
		cout << ' ';
		if (i % 5 == 0) cout << endl;
	}
	if (p != L.head)
		return ERROR;
	return OK;
}
int main(){
	DuLinkList DLL;
loop1:
	system("cls");
	cout << "���������ѡ����Ӧ�Ĺ��ܣ�" << endl;
	cout << "��ʼ��---1" << endl;
	cout << "����-----2" << endl;
	cout << "ɾ��-----3" << endl;
	cout << "����-----4" << endl;
	cout << "����-----5" << endl;
	cout << "����-----6" << endl;
	cout << "����-----7" << endl;
	cout << "�˳�-----����" << endl;
	char i;
	int m, n;
	ElemType e;
	DLink x, y;
	cin >> i;
	switch (i){
	case '1':
		system("cls");
		if (InitList(DLL) == OK)
			cout << "��ʼ���ɹ�" << endl << "��ʼ����Ϊ5�����ݷֱ�Ϊ1,2,3,4,5" << endl;
		cout << "�����밴1" << endl;
		cin >> m;
		if (m == 1)goto loop1;
		break;
	case '2':
	loop2 :
		system("cls");
		  cout << "���������λ����Ԫ�أ���ʽΪ����� Ԫ�أ���";
		  cin >> n >> e;
		  if (MakeNode(x, e) && InsertElem(DLL, n, x)) cout << "����ɹ���" << endl;
		  else cout << "����ʧ�ܣ�" << endl;
		  cout << "�����밴1" << endl << "�����밴2" << endl;
		  cin >> m;
		  if (m == 1)goto loop2;
		  if (m == 2)goto loop1;
		  break;
	case '3':
	loop3 :
		system("cls");
		  cout << "������ɾ����λ�ã���ʽΪ����ţ���";
		  cin >> n;
		  if (DeleteElem(DLL, n)) cout << "ɾ���ɹ���" << endl;
		  else  cout << "ɾ��ʧ�ܣ�" << endl;
		  cout << "�����밴1" << endl << "�����밴2" << endl;
		  cin >> m;
		  if (m == 1)goto loop3;
		  if (m == 2)goto loop1;
		  break;
	case '4':
	loop4 :
		system("cls");
		  cout << "��������µ�λ����Ԫ�أ���ʽΪ����� Ԫ�أ���";
		  cin >> n >> e;
		  if (LocatePos(DLL, n, x) && SetCurElem(x, e)) cout << "���³ɹ���" << endl;
		  else cout << "����ʧ�ܣ�" << endl;
		  cout << "�����밴1" << endl << "�����밴2" << endl;
		  cin >> m;
		  if (m == 1)goto loop4;
		  if (m == 2)goto loop1;
		  break;
	case '5':
	loop5 :
		system("cls");
		  cout << "��������ҵ�λ�ã���ʽΪ����ţ���";
		  cin >> n;
		  if (LocatePos(DLL, n, y) && MakeNode(x, GetCurElem(y))) cout << x->data << endl << "���ҳɹ���" << endl;
		  else cout << "����ʧ�ܣ�" << endl;
		  cout << "�����밴1" << endl << "�����밴2" << endl;
		  cin >> m;
		  if (m == 1)goto loop5;
		  if (m == 2)goto loop1;
		  break;
	case '6':
		system("cls");
		if (ListTraverse(DLL, VisitElem) != OK)
			cout << "����ʧ��" << endl;
		cout << "�����밴1" << endl;
		cin >> m;
		if (m == 1)goto loop1;
		break;
	case '7':
		system("cls");
		if (DestroyList(DLL) == OK)
			cout << "���ٳɹ�" << endl;
		cout << "�����밴1" << endl;
		cin >> m;
		if (m == 1)goto loop1;
		break;
	default:
		return 0;
		break;
	}
	return 0;
}