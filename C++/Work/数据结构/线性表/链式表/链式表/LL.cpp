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
	// L为带头结点的单链表的头指针。
	// 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
	LinkList p;
	p = L->next;
	int j = 1;           // 初始化，p指向第一个结点，j为计数器
	while (p && j<i) {   // 顺指针向后查找，直到p指向第i个元素或p为空
		p = p->next;  ++j;
	}
	if (!p || j>i) return ERROR;  // 第i个元素不存在
	e = p->data;   // 取第i个元素
	return OK;
}

Status ListInsert_L(LinkList &L, int i, ElemType e) {
	// 在带头结点的单链线性表L的第i个元素之前插入元素e
	LinkList p, s;
	p = L;
	int j = 0;
	while (p && j < i - 1) {  // 寻找第i-1个结点
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return ERROR;      // i小于1或者大于表长
	s = (LinkList)malloc(sizeof(LNode));  // 生成新结点
	s->data = e;  s->next = p->next;      // 插入L中
	p->next = s;
	return OK;
}

Status ListDelete_L(LinkList &L, int i, ElemType &e) {
	// 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
	LinkList p, q;
	p = L;
	int j = 0;
	while (p->next && j < i - 1) {  // 寻找第i个结点，并令p指向其前趋
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1) return ERROR;  // 删除位置不合理
	q = p->next;
	p->next = q->next;           // 删除并释放结点
	e = q->data;
	free(q);
	return OK;
}

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc) {
	// 已知单链线性表La和Lb的元素按值非递减排列。
	// 归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列。
	LinkList pa, pb, pc;
	pa = La->next;    pb = Lb->next;
	Lc = pc = La;             // 用La的头结点作为Lc的头结点
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;   pc = pa;   pa = pa->next;
		}
		else { pc->next = pb;   pc = pb;   pb = pb->next; }
	}
	pc->next = pa ? pa : pb;  // 插入剩余段
	free(Lb);                 // 释放Lb的头结点
}