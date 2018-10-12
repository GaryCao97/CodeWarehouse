//双向循环链表
#include<iostream>
#include<stdlib.h>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
typedef int Status;
typedef char ElemType;//自行定义元素类型 

typedef struct DuLNode{
	ElemType data;
	struct DuLNode *prior, *next;
}*DLink, *DuLPosition;
typedef struct {
	DLink head, tail;
	int  len;
}DuLinkList;

Status MakeNode(DLink &p, ElemType e);//分配由p指向的结点并赋值为e
void FreeNode(DLink &p);//释放p所指向的结点
Status InitList(DuLinkList &L);//构造一个由L指向的空的线性表
Status DestroyList(DuLinkList &L);//销毁由L指向的线性表
Status InsertElem(DuLinkList &L, int i, DLink s);//插入
Status DeleteElem(DuLinkList &L, int i);//删除
Status SetCurElem(DLink &p, ElemType e);//用e更新p所指向的当前结点
ElemType GetCurElem(DLink p);//返回p所指结点中元素的值
Status LisEmpty(DuLinkList L);//判断线性表是否为空
int Listlength(DuLinkList L);//返回线性表中元素个数
Status LocatePos(DuLinkList L, int i, DLink &p);//用p返回线性表l中第i个结点的位置，并返回ok
Status ListTraverse(DuLinkList L, Status(*visit)(ElemType));//用一个函数遍历表中所有结点

Status MakeNode(DLink &p, ElemType e){
	//分配由p指向的结点并赋值为e
	p = (DLink)malloc(sizeof(struct DuLNode));
	if (p){
		p->data = e;
		p->next = NULL;
		p->prior = NULL;
	}
	else
		return ERROR;
	return OK;
}
void FreeNode(DLink &p){
	//释放p所指向的结点
	free(p);
}
Status InitList(DuLinkList &L){
	//构造一个由L指向的空的线性表
	DLink p = NULL;
	MakeNode(p, 0);
	if (!p) exit(ERROR);
	L.head = p;
	L.head->next = L.head;
	L.head->prior = L.head;
	L.tail = p;
	L.len = 0;
	for (int i = 1; i <= 5; i++){
		DLink s;
		ElemType e = i + '0';
		MakeNode(s, e);
		InsertElem(L, i, s);
	}
	return OK;
}
Status DestroyList(DuLinkList &L){
	//销毁由L指向的线性表
	DLink p = NULL;
	DLink t = NULL;
	p = L.head;
	while (p->next != L.head){
		t = p->next;
		FreeNode(p);
		p = t;
	}
	L.len = 0;
	return TRUE;
}
Status InsertElem(DuLinkList &L, int i, DLink s){
	//插入 
	DLink p;
	if (i < 1 || i > L.len + 1)
		return ERROR;
	p = L.head;
	i--;
	while (i){
		p = p->next;
		i--;
	}
	s->next = p->next;
	p->next = s;
	s->next->prior = s;
	s->prior = p;
	if (p->next == L.head)
		L.tail = s;
	L.len++;
	return OK;
}
Status DeleteElem(DuLinkList &L, int i){
	//删除
	DLink p;
	if (i < 2 || i > L.len + 1)
		return ERROR;
	p = L.head;
	i -= 2;
	while (i){
		p = p->next;
		i--;
	}
	p->next = p->next->next;
	p->next->prior = p;
	L.len--;
	return OK;
}
Status SetCurElem(DLink &p, ElemType e){
	//用e更新p所指向的当前结点
	p->data = e;
	return OK;
}
ElemType GetCurElem(DLink p){
	//返回p所指结点中元素的值
	return p->data;
}
Status LocatePos(DuLinkList L, int i, DLink &p){
	//用p返回线性表l中第i个结点的位置，并返回ok
	p = L.head;
	if (i <= 0 || i > L.len)
		return ERROR;
	while (i){
		p = p->next;
		i--;
	}
	return OK;
}
Status VisitElem(ElemType e){
	if (e == '\0')
		return ERROR;
	cout << e;
	return OK;
}
Status ListTraverse(DuLinkList L, Status(*visit)(ElemType)){
	//用一个函数遍历表中所有结点
	DLink p;
	int i = 0;
	if (!L.len)
		return ERROR;
	p = L.head->next;
	while (p && (*visit)(p->data) && (++i)){
		p = p->next;
		cout << ' ';
		if (i % 5 == 0) cout << endl;
	}
	if (p != L.head)
		return ERROR;
	return OK;
}
int main(){
	DuLinkList DLL;
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
	char i;
	int m, n;
	ElemType e;
	DLink x, y;
	cin >> i;
	switch (i){
	case '1':
		system("cls");
		if (InitList(DLL) == OK)
			cout << "初始化成功" << endl << "初始化表长为5，内容分别为1,2,3,4,5" << endl;
		cout << "返回请按1" << endl;
		cin >> m;
		if (m == 1)goto loop1;
		break;
	case '2':
	loop2 :
		system("cls");
		  cout << "请输入插入位置与元素（形式为：序号 元素）：";
		  cin >> n >> e;
		  if (MakeNode(x, e) && InsertElem(DLL, n, x)) cout << "插入成功！" << endl;
		  else cout << "插入失败！" << endl;
		  cout << "继续请按1" << endl << "返回请按2" << endl;
		  cin >> m;
		  if (m == 1)goto loop2;
		  if (m == 2)goto loop1;
		  break;
	case '3':
	loop3 :
		system("cls");
		  cout << "请输入删除的位置（形式为：序号）：";
		  cin >> n;
		  if (DeleteElem(DLL, n)) cout << "删除成功！" << endl;
		  else  cout << "删除失败！" << endl;
		  cout << "继续请按1" << endl << "返回请按2" << endl;
		  cin >> m;
		  if (m == 1)goto loop3;
		  if (m == 2)goto loop1;
		  break;
	case '4':
	loop4 :
		system("cls");
		  cout << "请输入更新的位置与元素（形式为：序号 元素）：";
		  cin >> n >> e;
		  if (LocatePos(DLL, n, x) && SetCurElem(x, e)) cout << "更新成功！" << endl;
		  else cout << "更新失败！" << endl;
		  cout << "继续请按1" << endl << "返回请按2" << endl;
		  cin >> m;
		  if (m == 1)goto loop4;
		  if (m == 2)goto loop1;
		  break;
	case '5':
	loop5 :
		system("cls");
		  cout << "请输入查找的位置（形式为：序号）：";
		  cin >> n;
		  if (LocatePos(DLL, n, y) && MakeNode(x, GetCurElem(y))) cout << x->data << endl << "查找成功！" << endl;
		  else cout << "查找失败！" << endl;
		  cout << "继续请按1" << endl << "返回请按2" << endl;
		  cin >> m;
		  if (m == 1)goto loop5;
		  if (m == 2)goto loop1;
		  break;
	case '6':
		system("cls");
		if (ListTraverse(DLL, VisitElem) != OK)
			cout << "遍历失败" << endl;
		cout << "返回请按1" << endl;
		cin >> m;
		if (m == 1)goto loop1;
		break;
	case '7':
		system("cls");
		if (DestroyList(DLL) == OK)
			cout << "销毁成功" << endl;
		cout << "返回请按1" << endl;
		cin >> m;
		if (m == 1)goto loop1;
		break;
	default:
		return 0;
		break;
	}
	return 0;
}