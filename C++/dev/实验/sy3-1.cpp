#include<iostream>
#include<stdlib.h>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
typedef int Status;
typedef char ElemType;//���ж���Ԫ������ 
typedef struct LNode{
	ElemType      data;
	struct LNode  *next;
}*Link, *Position;
typedef struct {
	Link head, tail;
	int  len;
}LinkList;
Status MakeNode(Link &p, ElemType e);//������pָ��Ľ�㲢��ֵΪe
void FreeNode(Link &p);//�ͷ�p��ָ��Ľ��
Status InitList(LinkList &L);//����һ����Lָ��Ŀյ����Ա�
Status DestroyList(LinkList &L);//������Lָ������Ա�
Status InsertElem(LinkList &L, int i, Link s);//����
Status DeleteElem(LinkList &L, int i);//ɾ��
Status SetCurElem(Link &p, ElemType e);//��e����p��ָ��ĵ�ǰ���
ElemType GetCurElem(Link p);//����p��ָ�����Ԫ�ص�ֵ
Position PriorPos(LinkList L, Link p);//����p��ָ����ֱ��ǰ����λ��
Status LocatePos(LinkList L, int i, Link &p);//��p�������Ա�l�е�i������λ�ã�������ok
Position LocatElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));//���ر��е�һ����e����һ��������ϵ�Ľ�����λ��
Status ListTraverse(LinkList L, Status(*visit)(ElemType));//��һ�����������������н��

Status MakeNode(Link &p, ElemType e){
	//������pָ��Ľ�㲢��ֵΪe
	p = (Link)malloc(sizeof(struct LNode));
	if (p){
		p->data = e;
		p->next = NULL;
	}
	else
		return ERROR;
	return OK;
}
void FreeNode(Link &p){
	//�ͷ�p��ָ��Ľ��
	free(p);
}
Status InitList(LinkList &L){
	//����һ����Lָ��Ŀյ����Ա�
	Link p = NULL;
	MakeNode(p, 0);
	if (!p) exit(ERROR);
	L.head = p;
	L.tail = NULL;
	L.len = 0;
	for (int i = 1; i <= 5; i++){
		Link s;
		ElemType e = i + '0';
		MakeNode(s, e);
		InsertElem(L, i, s);
	}
	return OK;
}
Status DestroyList(LinkList &L){
	//������Lָ������Ա�
	Link p = NULL;
	Link t = NULL;
	p = L.head;
	while (p->next){
		t = p->next;
		FreeNode(p);
		p = t;
	}
	L.len = 0;
	return TRUE;
}
Status InsertElem(LinkList &L, int i, Link s){
	//���� 
	Link p;
	if (i < 1 || i > L.len + 1)
		return ERROR;
	p = L.head;
	i--;
	while (i){
		p = p->next;
		i--;
	}
	s->next = p->next;
	if (!p->next)
		L.tail = s;
	p->next = s;
	L.len++;
	return OK;
}
Status DeleteElem(LinkList &L, int i){
	//ɾ��
	Link p;
	if (i < 2 || i > L.len + 1)
		return ERROR;
	p = L.head;
	i -= 2;
	while (i){
		p = p->next;
		i--;
	}
	p->next = p->next->next;
	L.len--;
	return OK;
}
Status SetCurElem(Link &p, ElemType e){
	//��e����p��ָ��ĵ�ǰ���
	p->data = e;
	return OK;
}
ElemType GetCurElem(Link p){
	//����p��ָ�����Ԫ�ص�ֵ
	return p->data;
}
Position PriorPos(LinkList L, Link p){
	//����p��ָ����ֱ��ǰ����λ��
	Link q;
	q = L.head;
	if (q->next == p)
		return NULL;
	while (q->next != p)
		q = q->next;
	return q;
}
Status LocatePos(LinkList L, int i, Link &p){
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
Status ListTraverse(LinkList L, Status(*visit)(ElemType)){
	//��һ�����������������н��
	Link p;
	int i = 0;
	if (!L.len)
		return ERROR;
	p = L.head->next;
	while (p && (*visit)(p->data) && (++i)){
		p = p->next;
		cout << ' ';
		if (i % 5 == 0) cout << endl;
	}
	if (p != NULL)
		return ERROR;
	return OK;
}
int main(){
	LinkList LList;
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
	Link x, y;
	cin >> i;
	switch (i){
	case '1':
		system("cls");
		if (InitList(LList) == OK)
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
		  if (MakeNode(x, e) && InsertElem(LList, n, x)) cout << "����ɹ���" << endl;
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
		  if (DeleteElem(LList, n)) cout << "ɾ���ɹ���" << endl;
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
		  if (LocatePos(LList, n, x) && SetCurElem(x, e)) cout << "���³ɹ���" << endl;
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
		  if (LocatePos(LList, n, y) && MakeNode(x, GetCurElem(y))) cout << x->data << endl << "���ҳɹ���" << endl;
		  else cout << "����ʧ�ܣ�" << endl;
		  cout << "�����밴1" << endl << "�����밴2" << endl;
		  cin >> m;
		  if (m == 1)goto loop5;
		  if (m == 2)goto loop1;
		  break;
	case '6':
		system("cls");
		if (ListTraverse(LList, VisitElem) != OK)
			cout << "����ʧ��" << endl;
		cout << "�����밴1" << endl;
		cin >> m;
		if (m == 1)goto loop1;
		break;
	case '7':
		system("cls");
		if (DestroyList(LList) == OK)
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
