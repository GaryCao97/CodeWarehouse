#include<iostream>

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;

typedef ElemType;
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
Status ClearList(LinkList &L);//�����Ա�L��Ϊ�ձ����ͷ�ԭ�����ͷ���
Status InsFirst(LinkList &L, Link s);//��sָ��Ľ�������������ĵ�һ�����֮ǰ
Status DelFirst(LinkList &L, Link &q);//ɾ�����е�һ����㲢��q����
Status Append(LinkList &L, Link s);//��ָ��s����һ��������������Ա�L�����һ�����
Status Remove(LinkList &L, Link &q);//ɾ�����Ա�l�е�β���
Status InsBefore(LinkList &L, Link &p, Link s);//��s��ָ���������p��ָ���֮ǰ
Status InsAfter(LinkList &L, Link &p, Link s);//��s��ָ���������p��ָ���֮��
Status SetCurElem(Link &p, ElemType e);//��e����p��ָ��ĵ�ǰ���
ElemType GetCurElem(Link p);//����p��ָ�����Ԫ�ص�ֵ
Status LisEmpty(LinkList L);//�ж����Ա��Ƿ�Ϊ��
int Listlength(LinkList L);//�������Ա���Ԫ�ظ���
Position GetHead(LinkList L);//�������Ա�l��ͷ����λ��
Position GetLast(LinkList L);//�������Ա�l�����һ������λ��
Position PriorPos(LinkList L, Link p);//����p��ָ����ֱ��ǰ����λ��
Position NextPos(LinkList L, Link p);//����p��ָ����ֱ�Ӻ�̵�λ��
Status LocatePos(LinkList L, int i, Link &p);//��p�������Ա�l�е�i������λ�ã�������ok
Position LocatElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));//���ر��е�һ����e����һ��������ϵ�Ľ�����λ��
Status ListTraverse(LinkList L, Status(*visit)(ElemType));//��һ�����������������н��
int Length(Link s);//�����Ըýڵ�Ϊ�׵�����ĳ���

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
	return OK;
}
Status DestroyList(LinkList &L){
	//������Lָ������Ա�
	Link p = NULL;
	Link t = NULL;
	p = L.head;
	while (p->next){
		t = p->next;
		free(p);
		p = t;
	}
	return TRUE;
}
Status ClearList(LinkList &L){
	//�����Ա�L��Ϊ�ձ����ͷ�ԭ�����ͷ���
	Link p;
	p = L.tail;
	while (p != L.head){
		p = PriorPos(L, p);
		FreeNode(p->next);
	}
	FreeNode(L.head);
	L.tail = NULL;
	L.len = 0;
	return OK;
}
Status InsFirst(LinkList &L, Link s){
	//��sָ��Ľ�������������ĵ�һ�����֮ǰ
	s->next = L.head->next;
	if (!L.head->next)
		L.tail = s;
	L.head->next = s;
	L.len++;
	return OK;
}
Status DelFirst(LinkList &L, Link q){
	//ɾ�����е�һ����㲢��q����
	if (!L.head->next)
		return ERROR;
	q = L.head->next;
	L.head->next = L.head->next->next;
	return OK;
}
Status Append(LinkList &L, Link s){
	//��ָ��s����һ��������������Ա�L�����һ�����
	Link q;
	q = L.head;
	if (!L.tail){
		L.head->next = s;
		while (q->next)
			q = q->next;
		L.tail = q;
	}
	L.tail->next = q = s;
	while (q->next)
		q = q->next;
	L.tail = q;
	L.len += Length(s);
	return OK;
}
Status Remove(LinkList &L, Link &q){
	//ɾ�����Ա�l�е�β���
	if (!L.tail)
		return ERROR;
	q = L.tail;
	L.tail = PriorPos(L, q);
	L.tail->next = NULL;
	L.len--;
	return OK;
}
Status InsBefore(LinkList &L, Link &p, Link s){
	//��s��ָ���������p��ָ���֮ǰ
	Link q;
	q = PriorPos(L, p);
	s->next = p;
	q->next = s;
	p = s;
	L.len++;
	return OK;
}
Status InsAfter(LinkList &L, Link &p, Link s){
	//��s��ָ���������p��ָ���֮��
	s->next = p->next;
	p->next = s;
	p = s;
	L.len++;
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
Status LisEmpty(LinkList L){
	//�ж����Ա��Ƿ�Ϊ��
	if (L.head == L.tail)
		return TRUE;
	return FALSE;
}
int Listlength(LinkList L){
	//�������Ա���Ԫ�ظ���
	return L.len;
}
Position GetHead(LinkList L){
	//�������Ա�l��ͷ����λ��
	return L.head;
}
Position GetLast(LinkList L){
	//�������Ա�l�����һ������λ��
	return L.tail;
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
Position NextPos(LinkList L, Link p){
	//����p��ָ����ֱ�Ӻ�̵�λ��
	return p->next;
}
Status LocatePos(LinkList L, int i, Link &p){
	//��p�������Ա�l�е�i������λ�ã�������ok
	p = L.head;
	if (i <= 0 || i>Listlength(L))
		return ERROR;
	while (i){
		p = p->next;
		i--;
	}
	return OK;
}
Position LocatElem(LinkList L, ElemType e, Status(* compare)(ElemType,ElemType)){
	//���ر��е�һ����e����һ��������ϵ�Ľ�����λ��
	int i = 0;
	Link p;
	p = L.head->next;
	while ((*compare)(p->data, e) && p){
		p = p->next;
		++i;
	}
	if (!p)
		return NULL;
	return p;
}
Status ListTraverse(LinkList L, Status(*visit)(ElemType)){
	//��һ�����������������н��
	Link p;
	p = L.head;
	while (!(*visit)(p))
		p = p->next;
	if (p != NULL)
		return ERROR;
	return OK;
}
int Length(Link s){
	int i = 0;
	Link p = NULL;
	p = s;
	while (p->next != NULL){
		p = p->next;
		i++;
	}
	return i;
}