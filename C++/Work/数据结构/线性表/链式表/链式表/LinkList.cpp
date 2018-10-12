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

Status MakeNode(Link &p, ElemType e);//分配由p指向的结点并赋值为e
void FreeNode(Link &p);//释放p所指向的结点
Status InitList(LinkList &L);//构造一个由L指向的空的线性表
Status DestroyList(LinkList &L);//销毁由L指向的线性表
Status ClearList(LinkList &L);//将线性表L置为空表，并释放原链表的头结点
Status InsFirst(LinkList &L, Link s);//将s指向的结点插入线性链表的第一个结点之前
Status DelFirst(LinkList &L, Link &q);//删除表中第一个结点并以q返回
Status Append(LinkList &L, Link s);//将指针s所的一串结点链接在线性表L的最后一个结点
Status Remove(LinkList &L, Link &q);//删除线性表l中的尾结点
Status InsBefore(LinkList &L, Link &p, Link s);//将s所指向结点插入在p所指结点之前
Status InsAfter(LinkList &L, Link &p, Link s);//将s所指向结点插入在p所指结点之后
Status SetCurElem(Link &p, ElemType e);//用e更新p所指向的当前结点
ElemType GetCurElem(Link p);//返回p所指结点中元素的值
Status LisEmpty(LinkList L);//判断线性表是否为空
int Listlength(LinkList L);//返回线性表中元素个数
Position GetHead(LinkList L);//返回线性表l中头结点的位置
Position GetLast(LinkList L);//返回线性表l中最后一个结点的位置
Position PriorPos(LinkList L, Link p);//返回p所指结点的直接前驱的位置
Position NextPos(LinkList L, Link p);//返回p所指结点的直接后继的位置
Status LocatePos(LinkList L, int i, Link &p);//用p返回线性表l中第i个结点的位置，并返回ok
Position LocatElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));//返回表中第一个与e满足一定函数关系的结点次序位置
Status ListTraverse(LinkList L, Status(*visit)(ElemType));//用一个函数遍历表中所有结点
int Length(Link s);//返回以该节点为首的链表的长度

Status MakeNode(Link &p, ElemType e){
	//分配由p指向的结点并赋值为e
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
	//释放p所指向的结点
	free(p);
}
Status InitList(LinkList &L){
	//构造一个由L指向的空的线性表
	Link p = NULL;
	MakeNode(p, 0);
	if (!p) exit(ERROR);
	L.head = p;
	L.tail = NULL;
	L.len = 0;
	return OK;
}
Status DestroyList(LinkList &L){
	//销毁由L指向的线性表
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
	//将线性表L置为空表，并释放原链表的头结点
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
	//将s指向的结点插入线性链表的第一个结点之前
	s->next = L.head->next;
	if (!L.head->next)
		L.tail = s;
	L.head->next = s;
	L.len++;
	return OK;
}
Status DelFirst(LinkList &L, Link q){
	//删除表中第一个结点并以q返回
	if (!L.head->next)
		return ERROR;
	q = L.head->next;
	L.head->next = L.head->next->next;
	return OK;
}
Status Append(LinkList &L, Link s){
	//将指针s所的一串结点链接在线性表L的最后一个结点
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
	//删除线性表l中的尾结点
	if (!L.tail)
		return ERROR;
	q = L.tail;
	L.tail = PriorPos(L, q);
	L.tail->next = NULL;
	L.len--;
	return OK;
}
Status InsBefore(LinkList &L, Link &p, Link s){
	//将s所指向结点插入在p所指结点之前
	Link q;
	q = PriorPos(L, p);
	s->next = p;
	q->next = s;
	p = s;
	L.len++;
	return OK;
}
Status InsAfter(LinkList &L, Link &p, Link s){
	//将s所指向结点插入在p所指结点之后
	s->next = p->next;
	p->next = s;
	p = s;
	L.len++;
	return OK;
}
Status SetCurElem(Link &p, ElemType e){
	//用e更新p所指向的当前结点
	p->data = e;
	return OK;
}
ElemType GetCurElem(Link p){
	//返回p所指结点中元素的值
	return p->data;
}
Status LisEmpty(LinkList L){
	//判断线性表是否为空
	if (L.head == L.tail)
		return TRUE;
	return FALSE;
}
int Listlength(LinkList L){
	//返回线性表中元素个数
	return L.len;
}
Position GetHead(LinkList L){
	//返回线性表l中头结点的位置
	return L.head;
}
Position GetLast(LinkList L){
	//返回线性表l中最后一个结点的位置
	return L.tail;
}
Position PriorPos(LinkList L, Link p){
	//返回p所指结点的直接前驱的位置
	Link q;
	q = L.head;
	if (q->next == p)
		return NULL;
	while (q->next != p)
		q = q->next;
	return q;
}
Position NextPos(LinkList L, Link p){
	//返回p所指结点的直接后继的位置
	return p->next;
}
Status LocatePos(LinkList L, int i, Link &p){
	//用p返回线性表l中第i个结点的位置，并返回ok
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
	//返回表中第一个与e满足一定函数关系的结点次序位置
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
	//用一个函数遍历表中所有结点
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