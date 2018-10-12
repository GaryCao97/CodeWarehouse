#include<iostream>

#define TRUE        1;
#define FALSE       0;
#define OK          1;
#define ERROR       0;
#define INFEASIBLE  -1;
#define OVERFLOW    -2;
typedef int Status;

typedef ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

Status GetElem_L(LinkList &L, int i, ElemType &e) {
	// LΪ��ͷ���ĵ������ͷָ�롣
	// ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
	LinkList p;
	p = L->next;
	int j = 1;           // ��ʼ����pָ���һ����㣬jΪ������
	while (p && j<i) {   // ˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
		p = p->next;  ++j;
	}
	if (!p || j>i) return ERROR;  // ��i��Ԫ�ز�����
	e = p->data;   // ȡ��i��Ԫ��
	return OK;
}

Status ListInsert_L(LinkList &L, int i, ElemType e) {
	// �ڴ�ͷ���ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
	LinkList p, s;
	p = L;
	int j = 0;
	while (p && j < i - 1) {  // Ѱ�ҵ�i-1�����
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return ERROR;      // iС��1���ߴ��ڱ�
	s = (LinkList)malloc(sizeof(LNode));  // �����½��
	s->data = e;  s->next = p->next;      // ����L��
	p->next = s;
	return OK;
}

Status ListDelete_L(LinkList &L, int i, ElemType &e) {
	// �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
	LinkList p, q;
	p = L;
	int j = 0;
	while (p->next && j < i - 1) {  // Ѱ�ҵ�i����㣬����pָ����ǰ��
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1) return ERROR;  // ɾ��λ�ò�����
	q = p->next;
	p->next = q->next;           // ɾ�����ͷŽ��
	e = q->data;
	free(q);
	return OK;
}

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc) {
	// ��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����С�
	// �鲢La��Lb�õ��µĵ������Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����С�
	LinkList pa, pb, pc;
	pa = La->next;    pb = Lb->next;
	Lc = pc = La;             // ��La��ͷ�����ΪLc��ͷ���
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;   pc = pa;   pa = pa->next;
		}
		else { pc->next = pb;   pc = pb;   pb = pb->next; }
	}
	pc->next = pa ? pa : pb;  // ����ʣ���
	free(Lb);                 // �ͷ�Lb��ͷ���
}