#include <iostream>
#include <stdlib.h>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int Status;
typedef int ElemType;//自行定义元素类型 
class SqList{
private:
	ElemType *elem;
	int length;
	int listsize;
public:
	Status InitList_Sq();// 构造一个空的线性表L。
	Status DestroyList_Sq();//销毁一个顺序表
	Status ListEmpty_Sq();//判断顺序表是否为空
	int ListLength_Sq();//求顺序表的长度
	Status GetElem_Sq(int i, ElemType &e);//返回顺序表中的第i个元素
	Status ListInsert_Sq(int i, ElemType e);// 在顺序线性表L的第i个元素之前插入新的元素e，
	Status ListChange_Sq(int i, ElemType e);//更新顺序线性表 的第i个元素 
	Status ListDelete_Sq(int i, ElemType &e);// 在顺序线性表L中删除第i-1个元素，并用e返回其值。
	Status ListTraverse_Sq(Status(*visit)(ElemType));//遍历顺序线性表
};
Status SqList::InitList_Sq() {
	// 构造一个空的线性表L。
	elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!elem)
		return OK;
	length = 0;
	listsize = LIST_INIT_SIZE;
	for(int q = 0; q < 5; q++)
		ListInsert_Sq(q+1,q+1);
	return OK;
}
Status SqList::DestroyList_Sq(){
	//销毁一个顺序表
	if (elem)
		free(elem);
	elem=NULL;
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
Status SqList::ListChange_Sq(int i, ElemType e){
	//更新顺序线性表 的第i个元素 
	if (i < 1 || i > length+1)
		return ERROR;
	ElemType *p = &(elem[i - 1]);
	*p = e;
	return OK;
} 
Status SqList::ListDelete_Sq(int i, ElemType &e) {
	// 在顺序线性表L中删除第i-1个元素，并用e返回其值。
	// i的合法值为1≤i≤ListLength_Sq(L)。
	ElemType *p, *q;
	if (i<1 || i>length)
		return ERROR;
	p = &(elem[i - 1]);
	e = *p;
	q = elem + length - 1;
	for (p; p <= q; ++p)
		*(p - 1) = *p;
	--length;
	return OK;
}
Status SqList::ListTraverse_Sq(Status(*visit)(ElemType)){
	//遍历顺序线性表
	if (ListEmpty_Sq())return ERROR;
	for (int i = 0; i < length; i++){
		if(!(*visit)(elem[i]))
			return ERROR;
		if((i+1) % 5 == 0)cout << endl;
	}
	cout << endl;
	return OK;
}
Status VisitElem(ElemType e){
	cout << e << ' ';
}
int main(int argc, char** argv) {
	SqList SQL;
loop1:
	system("cls");
	cout << "请输入序号选择相应的功能：" << endl;
	cout << "初始化---1" << endl; 
	cout << "插入-----2" << endl; 
	cout << "删除-----3" << endl; 
	cout << "更新-----4" << endl; 
	cout << "查找-----5" << endl; 
	cout << "遍历-----6" << endl; 
	cout << "销毁-----7" << endl; 
	cout << "退出-----其他" << endl; 
	int n, m;
	int x, y;
	cin >> n;
	switch(n){
		case 1:
			system("cls");
			if(SQL.InitList_Sq() == OK)
				cout << "初始化成功" << endl << "初始化表长为5，内容分别为1,2,3,4,5" << endl;
			cout << "返回请按1" << endl;
			cin >> m;
			if(m == 1)goto loop1;
			break;
		case 2:
			loop2:
			system("cls");
			cout << "请输入插入位置与元素（形式为：序号 元素）：";
			cin >> x >> y;
			if(SQL.ListInsert_Sq(x, y) != OK) cout << "插入失败！" << endl;
			else cout << "插入成功！" << endl;
			cout << "继续请按1" << endl << "返回请按2" << endl;
			cin >> m;
			if(m == 1)goto loop2;
			if(m == 2)goto loop1;
			break;
		case 3:
			loop3:
			system("cls");
			cout << "请输入删除的位置（形式为：序号）：";
			cin >> x;
			if(SQL.ListDelete_Sq(x, y) != OK) cout << "删除失败！" << endl;
			else cout << "删除成功！" << endl;
			cout << "继续请按1" << endl << "返回请按2" << endl;
			cin >> m;
			if(m == 1)goto loop3;
			if(m == 2)goto loop1;
			break;
		case 4:
			loop4:
			system("cls");
			cout << "请输入更新的位置与元素（形式为：序号 元素）：";
			cin >> x >> y;
			if(SQL.ListChange_Sq(x, y) != OK) cout << "更新失败！" << endl;
			else cout << "更新成功！" << endl;
			cout << "继续请按1" << endl << "返回请按2" << endl;
			cin >> m;
			if(m == 1)goto loop4;
			if(m == 2)goto loop1;
			break;
		case 5:
			loop5:
			system("cls");
			cout << "请输入查找的位置（形式为：序号）：";
			cin >> x;
			if(SQL.GetElem_Sq(x, y) != OK) cout << "查找失败！" << endl;
			else cout << y << endl << "查找成功！" << endl;
			cout << "继续请按1" << endl << "返回请按2" << endl;
			cin >> m;
			if(m == 1)goto loop5;
			if(m == 2)goto loop1;
			break;
		case 6:
			system("cls");
			if(SQL.ListTraverse_Sq(VisitElem) != OK)
				cout << "遍历失败" << endl;
			cout << "返回请按1" << endl;
			cin >> m;
			if(m == 1)goto loop1;
			break;
		case 7:
			system("cls");
			if(SQL.DestroyList_Sq() == OK)
				cout << "销毁成功" << endl;
			cout << "返回请按1" << endl;
			cin >> m;
			if(m == 1)goto loop1;
			break; 
		default:
			return 0;
			break;
	}
	return 0;
}
