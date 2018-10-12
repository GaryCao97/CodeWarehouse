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
typedef ElemType;//自行定义元素类型 
typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;

Status InitList_Sq(SqList &L);// 构造一个空的线性表L。
Status DestroyList_Sq(SqList &L);//销毁一个顺序表
Status ClearList_Sq(SqList &L);//清空一个顺序表
Status ListEmpty_Sq(SqList L);//判断顺序表是否为空
int ListLength_Sq(SqList L);//求顺序表的长度
Status GetElem_Sq(SqList L, int i, ElemType &e);//返回顺序表中的第i个元素
int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));// 在顺序线性表L中查找第1个值与e满足compare()的元素的位序。
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType &pre_e);//返回一个不是首元素的前驱
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType &next_e);//返回一个不是末元素的后继
Status ListInsert_Sq(SqList &L, int i, ElemType e);// 在顺序线性表L的第i个元素之前插入新的元素e，
Status ListDelete_Sq(SqList &L, int i, ElemType &e);// 在顺序线性表L中删除第i个元素，并用e返回其值。
Status ListTraverse_Sq(SqList L, Status(*visit)(ElemType));//遍历顺序线性表

Status InitList_Sq(SqList &L) {
	// 构造一个空的线性表L。
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!L.elem)
		return OK;
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

Status DestroyList_Sq(SqList &L){
	//销毁一个顺序表
	if (L.elem)
		free(L.elem);
	L.elem=NULL;
	return OK;
}

Status ClearList_Sq(SqList &L){
	//清空一个顺序表
	L.length = 0;
	return OK;
}

Status ListEmpty_Sq(SqList L){
	//判断顺序表是否为空
	return L.length == 0;
}

int ListLength_Sq(SqList L){
	//求顺序表的长度
	return (L.length);
}

Status GetElem_Sq(SqList L, int i, ElemType &e){
	//返回顺序表中的第i个元素
	if (i<1 || i>L.length)
		return ERROR;
	e = L.elem[i - 1];
	return OK; 
}

int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
	// 在顺序线性表L中查找第1个值与e满足compare()的元素的位序。
	// 若找到，则返回其在L中的位序，否则返回0。
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
	//返回一个不是首元素的前驱
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
	//返回一个不是末元素的后继
	int i = 1;
	while (i < L.length && (L.elem[i - 1] != cur_e))
		i++;
	if (i == L.length)
		return ERROR;
	else next_e = L.elem[i];
	return OK;
}

Status ListInsert_Sq(SqList &L, int i, ElemType e) {
	// 在顺序线性表L的第i个元素之前插入新的元素e，
	// i的合法值为1≤i≤ListLength_Sq(L)+1
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
	// 在顺序线性表L中删除第i个元素，并用e返回其值。
	// i的合法值为1≤i≤ListLength_Sq(L)。
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
	//遍历顺序线性表
	if (ListEmpty_Sq(L))return ERROR;
	for (int i = 0; i < L.length; i++){
		(*visit)(L.elem[i]);
	}
}
