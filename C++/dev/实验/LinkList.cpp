#include<stdlib.h>
#include"LinkList.h"
Status LinkList::MakeNode(Link &p, ElemType e){
	//������pָ��Ľ�㲢��ֵΪe
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
	//�ͷ�p��ָ��Ľ��
	free(p);
}
Status LinkList::InitList(){
	//����һ����Lָ��Ŀյ����Ա�
	Link p = NULL;
	MakeNode(p, 0);
	if (!p) exit(ERROR);
	head = p;
	tail = NULL;
	len = 0;
	return OK;
}
Status LinkList::DestroyList(){
	//������Lָ������Ա�
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
	//�����Ա�L��Ϊ�ձ����ͷ�ԭ�����ͷ���
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
	//��sָ��Ľ�������������ĵ�һ�����֮ǰ
	s->next = head->next;
	if (!head->next)
		tail = s;
	head->next = s;
	len++;
	return OK;
}
Status LinkList::DelFirst(Link &q){
	//ɾ�����е�һ����㲢��q����
	if (!head->next)
		return ERROR;
	q = head->next;
	head->next = head->next->next;
	return OK;
}
Status LinkList::Append(Link s){
	//��ָ��s����һ��������������Ա�L�����һ�����
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
	//ɾ�����Ա�l�е�β���
	if (!tail)
		return ERROR;
	q = tail;
	tail = PriorPos(q);
	tail->next = NULL;
	len--;
	return OK;
}
Status LinkList::InsBefore(Link &p, Link s){
	//��s��ָ���������p��ָ���֮ǰ
	Link q;
	q = PriorPos(p);
	s->next = p;
	q->next = s;
	p = s;
	len++;
	return OK;
}
Status LinkList::InsAfter(Link &p, Link s){
	//��s��ָ���������p��ָ���֮��
	s->next = p->next;
	p->next = s;
	p = s;
	len++;
	return OK;
}
Status LinkList::SetCurElem(Link &p, ElemType e){
	//��e����p��ָ��ĵ�ǰ���
	p->data = e;
	return OK;
}
ElemType LinkList::GetCurElem(Link p){
	//����p��ָ�����Ԫ�ص�ֵ
	return p->data;
}
Status LinkList::LisEmpty(){
	//�ж����Ա��Ƿ�Ϊ��
	if (head == tail)
		return TRUE;
	return FALSE;
}
int LinkList::Listlength(){
	//�������Ա���Ԫ�ظ���
	return len;
}
Position LinkList::GetHead(){
	//�������Ա�l��ͷ����λ��
	return head;
}
Position LinkList::GetLast(){
	//�������Ա�l�����һ������λ��
	return tail;
}
Position LinkList::PriorPos(Link p){
	//����p��ָ����ֱ��ǰ����λ��
	Link q;
	q = head;
	if (q->next == p)
		return NULL;
	while (q->next != p)
		q = q->next;
	return q;
}
Position LinkList::NextPos(Link p){
	//����p��ָ����ֱ�Ӻ�̵�λ��
	return p->next;
}
Status LinkList::LocatePos(int i, Link &p){
	//��p�������Ա�l�е�i������λ�ã�������ok
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
	//���ر��е�һ����e����һ��������ϵ�Ľ�����λ��
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
	//��һ�����������������н��
	Link p;
	p = head;
	while (!(*visit)(p->data))
		p = p->next;
	if (p != NULL)
		return ERROR;
	return OK;
}
