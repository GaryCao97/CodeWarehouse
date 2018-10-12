#include <stdlib.h>
#include "SqList.h"
Status SqList::InitList_Sq() {
	// 构造一个空的线性表L。
	elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!elem)
		return OK;
	length = 0;
	listsize = LIST_INIT_SIZE;
	return OK;
}
Status SqList::DestroyList_Sq(){
	//销毁一个顺序表
	if (elem)
		free(elem);
	elem=NULL;
	return OK;
}
Status SqList::ClearList_Sq(){
	//清空一个顺序表
	length = 0;
	return OK;
}
Status SqList::ListEmpty_Sq(){
	//判断顺序表是否为空
	return length == 0;
}
int SqList::ListLength_Sq(){
	//求顺序表的长度
	return (length);
}
Status SqList::GetElem_Sq(int i, ElemType &e){
	//返回顺序表中的第i个元素
	if (i<1 || i>length)
		return ERROR;
	e = elem[i - 1];
	return OK; 
}
int SqList::LocateElem_Sq(ElemType e, Status(*compare)(ElemType, ElemType)) {
	// 在顺序线性表L中查找第1个值与e满足compare()的元素的位序。
	// 若找到，则返回其在L中的位序，否则返回0。
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
	//返回一个不是首元素的前驱
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
	//返回一个不是末元素的后继
	int i = 1;
	while (i < length && (elem[i - 1] != cur_e))
		i++;
	if (i == length)
		return ERROR;
	else next_e = elem[i];
	return OK;
}
Status SqList::ListInsert_Sq( int i, ElemType e) {
	// 在顺序线性表L的第i个元素之前插入新的元素e，
	// i的合法值为1≤i≤ListLength_Sq(L)+1
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
	//更新顺序线性表 的第i个元素 
	if (i < 1 || i > length+1)
		return ERROR;
	q = elem[i-1];
	ElemType *p = &(elem[i-1]);
	*p = e;
	return OK;
} 
Status SqList::ListDelete_Sq(int i, ElemType &e) {
	// 在顺序线性表L中删除第i个元素，并用e返回其值。
	// i的合法值为1≤i≤ListLength_Sq(L)。
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
	//遍历顺序线性表
	if (ListEmpty_Sq())return ERROR;
	for (int i = 0; i < length; i++){
		(*visit)(elem[i]);
	}
}
