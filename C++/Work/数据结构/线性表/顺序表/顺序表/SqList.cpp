#include <iostream>
using namespace std; 
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef ElemType;//���ж���Ԫ������ 
typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;

Status InitList_Sq(SqList &L);// ����һ���յ����Ա�L��
Status DestroyList_Sq(SqList &L);//����һ��˳���
Status ClearList_Sq(SqList &L);//���һ��˳���
Status ListEmpty_Sq(SqList L);//�ж�˳����Ƿ�Ϊ��
int ListLength_Sq(SqList L);//��˳���ĳ���
Status GetElem_Sq(SqList L, int i, ElemType &e);//����˳����еĵ�i��Ԫ��
int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));// ��˳�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType &pre_e);//����һ��������Ԫ�ص�ǰ��
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType &next_e);//����һ������ĩԪ�صĺ��
Status ListInsert_Sq(SqList &L, int i, ElemType e);// ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
Status ListDelete_Sq(SqList &L, int i, ElemType &e);// ��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ��
Status ListTraverse_Sq(SqList L, Status(*visit)(ElemType));//����˳�����Ա�

Status InitList_Sq(SqList &L) {
	// ����һ���յ����Ա�L��
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!L.elem)
		return OK;
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

Status DestroyList_Sq(SqList &L){
	//����һ��˳���
	if (L.elem)
		free(L.elem);
	L.elem=NULL;
	return OK;
}

Status ClearList_Sq(SqList &L){
	//���һ��˳���
	L.length = 0;
	return OK;
}

Status ListEmpty_Sq(SqList L){
	//�ж�˳����Ƿ�Ϊ��
	return L.length == 0;
}

int ListLength_Sq(SqList L){
	//��˳���ĳ���
	return (L.length);
}

Status GetElem_Sq(SqList L, int i, ElemType &e){
	//����˳����еĵ�i��Ԫ��
	if (i<1 || i>L.length)
		return ERROR;
	e = L.elem[i - 1];
	return OK; 
}

int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
	// ��˳�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
	// ���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0��
	int i;
	ElemType *p;
	i = 1;
	p = L.elem;
	while (i <= L.length && !(*compare)(*p++, e))
		++i;
	if (i <= L.length)
		return i;
	else
		return 0;
}

Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType &pre_e){
	//����һ��������Ԫ�ص�ǰ��
	int i = 2;
	if (cur_e == L.elem[0])
		return ERROR;
	while (i <= L.length && (L.elem[i - 1] != cur_e))
		i++;
	if (i == L.length + 1)
		return ERROR;
	else
		pre_e = L.elem[i - 2];
	return OK;
}

Status NextElem_Sq(SqList L, ElemType cur_e, ElemType &next_e){
	//����һ������ĩԪ�صĺ��
	int i = 1;
	while (i < L.length && (L.elem[i - 1] != cur_e))
		i++;
	if (i == L.length)
		return ERROR;
	else next_e = L.elem[i];
	return OK;
}

Status ListInsert_Sq(SqList &L, int i, ElemType e) {
	// ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
	// i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)+1
	ElemType *p;
	if (i < 1 || i > L.length+1)
		return ERROR;
	if (L.length >= L.listsize) {
		ElemType *newbase = (ElemType *)realloc(L.elem, (L.listsize+LISTINCREMENT)*sizeof (ElemType));
		if (!newbase)
			return ERROR;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	ElemType *q = &(L.elem[i-1]);
	for (p = &(L.elem[L.length - 1]); p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++L.length;
	return OK;
}

Status ListDelete_Sq(SqList &L, int i, ElemType &e) {
	// ��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ��
	// i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)��
	ElemType *p, *q;
	if (i<1 || i>L.length)
		return ERROR;
	p = &(L.elem[i - 1]);
	e = *p;
	q = L.elem + L.length - 1;
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--L.length;
	return OK;
}

Status ListTraverse_Sq(SqList L, Status(*visit)(ElemType)){
	//����˳�����Ա�
	if (ListEmpty_Sq(L))return ERROR;
	for (int i = 0; i < L.length; i++){
		(*visit)(L.elem[i]);
	}
}
