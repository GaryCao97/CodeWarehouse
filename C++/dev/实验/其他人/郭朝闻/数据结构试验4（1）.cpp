#include<iostream>
#include<malloc.h>
#include<windows.h>
using namespace std;
#define OK 1
#define ERROR 0 
typedef int Status;
typedef int ElemType;


typedef struct DuLNode{
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode, *DuLinkList;

//1) 在双向链表中查找第i个结点。

DuLinkList GetElemP_DuL(DuLinkList L, int i) {
	// L为带头结点的单链表的头指针。
	DuLinkList p;
	p = L->next;
	int j = 1;  // 初始化，p指向第一个结点，j为计数器
	while (p != L && j<i) { //顺指针向后查找，直到p指向第i个元素或p为空
		p = p->next;
		++j;
	}
	if (p == L && j<i) return NULL;  // 第i个元素不存在
	else return p;
} // GetElem_L

//2) 在双向链表的第i个结点前插入一个结点。

Status ListInsert_DuL(DuLinkList &L, int i, ElemType e){
	//在带头结点的双链循环线性表L中第i个位置之前插入元素e
	DuLNode *s;
	DuLNode *p;
	if (!(p = GetElemP_DuL(L, i)))
		return ERROR;
	if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))
		return ERROR;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;//与前一个节点的操作 
	s->next = p;
	p->prior = s;//与后一个结点的操作 
	return OK;
}//ListInsert_DuL

//3) 在双向链表的第i个结点前删除一个结点。

Status ListDelete_DuL(DuLinkList &L, int i, ElemType &e){
	DuLNode *p;
	if(!(p=GetElemP_DuL(L,i)))
		return ERROR;
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}//ListDelete_DuL

//4) 更新双向链表中第i个结点的值

Status UpdateLinkList_DuL(DuLinkList &L, int i, ElemType e){
	DuLNode *p = L->next;
	int j = 1;
	for (j; j<i - 1; j++){
		p = p->next;
	}
	if (!(p || j>i - 1))
		return ERROR;
	p->data = e;
	return OK;
}//UpdateLinkList_DuL

//5) 遍历双向链表

Status DuLinkListTraverse_DuL(DuLinkList L){
	DuLNode *p = L->next;
	if (!p)
		return ERROR;
	cout << "当前双向链表值： ";
	while (p != L){
		cout << p->data << " ";
		p = p->next;
	}
	return OK;
}

int main(){
	ElemType e;
	DuLinkList L;
	int N, num;
	L = (DuLinkList)malloc(sizeof(DuLNode));
	L->next = L;
	L->prior = L;
	DuLNode *p = L->next;
	//cout<<"——欢迎进入功能菜单——"<<endl; 
	cout << "请输入双向链表的元素个数： ";
	cin >> num;
	cout << endl << endl;
	cout << "请依次输入元素的值： ";
	for (int j = 1; j <= num; j++){
		cout << "第" << j << "个元素的值： " << endl;
		cin >> e;
		ListInsert_DuL(L, j, e);
	}
	Sleep(1000);
	system("cls");
loop:{
	cout << "***--欢迎进入菜单--***" << endl;
	cout << endl;
	cout << "~~请选择想要进行的功能的序号：" << endl;
	cout << "1) 在第i个节点之前插入一个节点；" << endl;
	cout << "2) 在第i个节点之前删除一个节点；" << endl;
	cout << "3) 在双向链表中查找第i个结点;" << endl;
	cout << "4) 更新双向链表中第i个结点的值;" << endl;
	cout << "5) 遍历双向链表;" << endl;
	cin >> num;
	switch (num)
	{
	case 1:
		cout << "请输入想要插入的位置： ";
		cin >> N;
		cout << endl;
		cout << "请输入想要插入的元素值： ";
		cin >> e;
		ListInsert_DuL(L, N, e);
		DuLinkListTraverse_DuL(L);
		break;
	case 2:
		cout << "请输入想要删除的位置： ";
		cin >> N;
		cout << endl;
		ListDelete_DuL(L, N, e);
		cout << "被删除的结点的值为" << e << endl;
		DuLinkListTraverse_DuL(L);
		break;
	case 3:
		cout << "请输入您想要查找的结点的位置： ";
		cin >> N;
		cout << endl;
		e = GetElemP_DuL(L, N)->data;
		cout << "该结点的值为" << e << endl;
		DuLinkListTraverse_DuL(L);
		break;
	case 4:
		cout << "请输入您想更新的结点的位置： ";
		cin >> N;
		cout << endl;
		cout << "请输入想要更新的值： ";
		cin >> e;
		cout << endl;
		UpdateLinkList_DuL(L, N, e);
		DuLinkListTraverse_DuL(L);
		break;
	case 5:
		DuLinkListTraverse_DuL(L);
		exit(0);
	default:
		cout << "请输入1—5之间的数字！" << endl;
		break;
	}
	goto loop;
}
}
