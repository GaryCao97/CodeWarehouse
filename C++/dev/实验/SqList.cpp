#include <stdlib.h>
#include "SqList.h"
Status SqList::InitList_Sq() {
	// ����һ���յ����Ա�L��
	elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!elem)
		return OK;
	length = 0;
	listsize = LIST_INIT_SIZE;
	return OK;
}
Status SqList::DestroyList_Sq(){
	//����һ��˳���
	if (elem)
		free(elem);
	elem=NULL;
	return OK;
}
Status SqList::ClearList_Sq(){
	//���һ��˳���
	length = 0;
	return OK;
}
Status SqList::ListEmpty_Sq(){
	//�ж�˳����Ƿ�Ϊ��
	return length == 0;
}
int SqList::ListLength_Sq(){
	//��˳���ĳ���
	return (length);
}
Status SqList::GetElem_Sq(int i, ElemType &e){
	//����˳����еĵ�i��Ԫ��
	if (i<1 || i>length)
		return ERROR;
	e = elem[i - 1];
	return OK; 
}
int SqList::LocateElem_Sq(ElemType e, Status(*compare)(ElemType, ElemType)) {
	// ��˳�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
	// ���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0��
	int i;
	ElemType *p;
	i = 1;
	p = elem;
	while (i <= length && !(*compare)(*p++, e))
		++i;
	if (i <= length)
		return i;
	else
		return 0;
}
Status SqList::PriorElem_Sq(ElemType cur_e, ElemType &pre_e){
	//����һ��������Ԫ�ص�ǰ��
	int i = 2;
	if (cur_e == elem[0])
		return ERROR;
	while (i <= length && (elem[i - 1] != cur_e))
		i++;
	if (i == length + 1)
		return ERROR;
	else
		pre_e = elem[i - 2];
	return OK;
}
Status SqList::NextElem_Sq(ElemType cur_e, ElemType &next_e){
	//����һ������ĩԪ�صĺ��
	int i = 1;
	while (i < length && (elem[i - 1] != cur_e))
		i++;
	if (i == length)
		return ERROR;
	else next_e = elem[i];
	return OK;
}
Status SqList::ListInsert_Sq( int i, ElemType e) {
	// ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
	// i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)+1
	ElemType *p;
	if (i < 1 || i > length+1)
		return ERROR;
	if (length >= listsize) {
		ElemType *newbase = (ElemType *)realloc(elem, (listsize+LISTINCREMENT)*sizeof (ElemType));
		if (!newbase)
			return ERROR;
		elem = newbase;
		listsize += LISTINCREMENT;
	}
	ElemType *q = &(elem[i-1]);
	for (p = &(elem[length - 1]); p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++length;
	return OK;
}
Status SqList::ListChange_Sq(int i, ElemType e, ElemType &q){
	//����˳�����Ա� �ĵ�i��Ԫ�� 
	if (i < 1 || i > length+1)
		return ERROR;
	q = elem[i-1];
	ElemType *p = &(elem[i-1]);
	*p = e;
	return OK;
} 
Status SqList::ListDelete_Sq(int i, ElemType &e) {
	// ��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ��
	// i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)��
	ElemType *p, *q;
	if (i<1 || i>length)
		return ERROR;
	p = &(elem[i - 1]);
	e = *p;
	q = elem + length - 1;
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--length;
	return OK;
}
Status SqList::ListTraverse_Sq(Status(*visit)(ElemType)){
	//����˳�����Ա�
	if (ListEmpty_Sq())return ERROR;
	for (int i = 0; i < length; i++){
		(*visit)(elem[i]);
	}
}
