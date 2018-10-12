#include<stdlib.h>
#include"LinkList.h"
Status LinkList::MakeNode(Link &p, ElemType e){
	//分配由p指向的结点并赋值为e
	p = (Link)malloc(sizeof(LNode));
	if (p){
		p->data = e;
		p->next = NULL;
	}
	else
		return ERROR;
	return OK;
}
void LinkList::FreeNode(Link &p){
	//释放p所指向的结点
	free(p);
}
Status LinkList::InitList(){
	//构造一个由L指向的空的线性表
	Link p = NULL;
	MakeNode(p, 0);
	if (!p) exit(ERROR);
	head = p;
	tail = NULL;
	len = 0;
	return OK;
}
Status LinkList::DestroyList(){
	//销毁由L指向的线性表
	Link p = NULL;
	Link t = NULL;
	p = head;
	while (p->next){
		t = p->next;
		FreeNode(p);
		p = t;
	}
	return OK;
}
Status LinkList::ClearList(){
	//将线性表L置为空表，并释放原链表的头结点
	Link p;
	p = tail;
	while (p != head){
		p = PriorPos(p);
		FreeNode(p->next);
	}
	FreeNode(head);
	tail = NULL;
	len = 0;
	return OK;
}
Status LinkList::InsFirst(Link s){
	//将s指向的结点插入线性链表的第一个结点之前
	s->next = head->next;
	if (!head->next)
		tail = s;
	head->next = s;
	len++;
	return OK;
}
Status LinkList::DelFirst(Link &q){
	//删除表中第一个结点并以q返回
	if (!head->next)
		return ERROR;
	q = head->next;
	head->next = head->next->next;
	return OK;
}
Status LinkList::Append(Link s){
	//将指针s所的一串结点链接在线性表L的最后一个结点
	Link q;
	q = head;
	if (!tail){
		head->next = s;
		while (q->next)
			q = q->next;
		tail = q;
	}
	else{
		tail->next = q = s;
		while (q->next)
			q = q->next;
		tail = q;
	}
	Link p = s;
	while (p->next != NULL){
		p = p->next;
		len++;
	}
	return OK;
}
Status LinkList::Remove(Link &q){
	//删除线性表l中的尾结点
	if (!tail)
		return ERROR;
	q = tail;
	tail = PriorPos(q);
	tail->next = NULL;
	len--;
	return OK;
}
Status LinkList::InsBefore(Link &p, Link s){
	//将s所指向结点插入在p所指结点之前
	Link q;
	q = PriorPos(p);
	s->next = p;
	q->next = s;
	p = s;
	len++;
	return OK;
}
Status LinkList::InsAfter(Link &p, Link s){
	//将s所指向结点插入在p所指结点之后
	s->next = p->next;
	p->next = s;
	p = s;
	len++;
	return OK;
}
Status LinkList::SetCurElem(Link &p, ElemType e){
	//用e更新p所指向的当前结点
	p->data = e;
	return OK;
}
ElemType LinkList::GetCurElem(Link p){
	//返回p所指结点中元素的值
	return p->data;
}
Status LinkList::LisEmpty(){
	//判断线性表是否为空
	if (head == tail)
		return TRUE;
	return FALSE;
}
int LinkList::Listlength(){
	//返回线性表中元素个数
	return len;
}
Position LinkList::GetHead(){
	//返回线性表l中头结点的位置
	return head;
}
Position LinkList::GetLast(){
	//返回线性表l中最后一个结点的位置
	return tail;
}
Position LinkList::PriorPos(Link p){
	//返回p所指结点的直接前驱的位置
	Link q;
	q = head;
	if (q->next == p)
		return NULL;
	while (q->next != p)
		q = q->next;
	return q;
}
Position LinkList::NextPos(Link p){
	//返回p所指结点的直接后继的位置
	return p->next;
}
Status LinkList::LocatePos(int i, Link &p){
	//用p返回线性表l中第i个结点的位置，并返回ok
	p = head;
	if (i <= 0 || i>Listlength())
		return ERROR;
	while (i){
		p = p->next;
		i--;
	}
	return OK;
}
Position LinkList::LocatElem(ElemType e, Status(* compare)(ElemType,ElemType)){
	//返回表中第一个与e满足一定函数关系的结点次序位置
	int i = 0;
	Link p;
	p = head->next;
	while ((*compare)(p->data, e) && p){
		p = p->next;
		++i;
	}
	if (!p)
		return NULL;
	return p;
}
Status LinkList::ListTraverse(Status(*visit)(ElemType)){
	//用一个函数遍历表中所有结点
	Link p;
	p = head;
	while (!(*visit)(p->data))
		p = p->next;
	if (p != NULL)
		return ERROR;
	return OK;
}
