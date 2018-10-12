//双向链表的基本操作
// 1)双向链表结点类的定义。
//2)双向链表类的定义。
//3)在双向链表的第i个结点前插入一个结点。
//4)在双向链表的第i个结点前删除一个结点。
//5)在双向链表中查找第i个结点。
//6)更新双向链表中第i个结点的值。
//7)遍历双向链表。

# include<iostream>
#include <stdlib.h>
#include <stdio.h>

# define OK 1
# define ERROR 0
# define OVERFLOW -2 

typedef int ElemType;
typedef int Status;
using namespace std;
typedef struct DNode{
	ElemType  data;
	struct  DNode *prior;
	struct  DNode *next;
}*DuLNode;
typedef struct {          //链表类型 
	DuLNode head;
	int len;
}DuLinkList;


Status InitList(DuLinkList &L)          //初始化单链表 
{
	L.head = (DuLNode)malloc(sizeof(DNode));
	if (!L.head) exit(OVERFLOW);
	L.head->next = NULL;
	L.head->prior = NULL;
	L.head->data = 0;
	L.len = 0;
	return OK;
}
Status MakeNode(DuLNode &p, ElemType e){       //创建结点 
	p = (DuLNode)malloc(sizeof(DNode));
	if (!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	p->prior = NULL;
	return OK;
}
Status ListInsert(DuLinkList &L, int i, ElemType e)    //在第i个位置前插入元素e 
{
	DuLNode p = L.head, s;
	int j = 0;
	while (p&&j<i-1)    //找到第i-1个位置 
	{
		p = p->next;
		++j;
	}
	if (!p || j>i-1)
		return ERROR;
	MakeNode(s, e);
	s->next = p->next;
	s->prior = p;
	if (p->next)
		p->next->prior = s;
	p->next = s;
	++L.len;
	return OK;
}

Status ListDelet(DuLinkList &L, int i, ElemType &e)    //在第i个位置删除素e 
{
	DuLNode p = L.head;
	int j = 0;
	while (p->next&&j<i){        //找到第i个结点
		p = p->next;
		++j;
	}
	if (!p || j>i)  //判断第i个结点是否存在 
		return ERROR;
	e = p->data;
	p->prior->next = p->next;
	if (p->next)
		p->next->prior = p->prior;
	--L.len;
	return OK;
}




Status ChangeElem(DuLinkList &L, int i, ElemType e){            //更新双链表中第i个元素的值。
	DuLNode p = L.head;
	int j = 0;
	while (p &&j<i)     //找到第i个结点
	{
		p = p->next; ++j;
	}
	if (!p || j>i)
		return ERROR;
	p->data = e;
	return OK;
}
Status GetElem(DuLinkList L, int i, ElemType &e){              //双链表中查找第i个元素。
	DuLNode p = L.head;
	int j = 0;
	while (p &&j<i)    //找到第i个结点
	{
		p = p->next; ++j;
	}
	if (!p || j>i)
		return ERROR;
	e = p->data;
	return OK;
}
Status ListTraversse(DuLinkList L)                      //遍历双链表 
{
	DuLNode p = L.head;
	while (p->next){                 //应该是要判断当前结点的下一个节点是否为NULL
		p = p->next;
		cout << p->data << " ";
	}
	return OK;
}
void menu(){
	cout << endl << "--------------菜单---------------" << endl;
	cout << "1).显示双链表" << endl;
	cout << "2).在双链表的第i个元素前插入一个元素" << endl;
	cout << "3).在双链表的第i个元素前删除一个元素。" << endl;
	cout << "4).在双链表中查找第i个元素" << endl;
	cout << "5).更新双链表中第i个元素的值。" << endl;
	cout << "   (输入其他数据结束操作)" << endl;

}

int main(){
	DuLinkList LL;
	int n = 0;
	InitList(LL);
	cout << "双链表" << endl << "请入要输入的数据个数n：";
	cin >> n;
	cout << "请输入n个数据:";
	for (int i = 1; i <= n; i++){
		ElemType a = 0;
		cin >> a;
		ListInsert(LL, i, a);
	}
	int xh = 0;
	int i = 0, e = 0;
	do
	{
		menu();
		cout << endl << "请输入菜单序号:";                          //输入菜单选项 
		cin >> xh;
		if (xh>0 && xh<6)
		{
			switch (xh){
			case 1:
				ListTraversse(LL);
				break;
			case 2:
				cout << "插入位置：";	cin >> i;
				while (i<0 || i>LL.len)
				{
					cout << "插入位置不合理，请重新输入！" << endl;
					cout << "插入位置：";	cin >> i;
				}
				cout << "插入数据："; cin >> e;
				ListInsert(LL, i, e);
				break;
			case 3:
				cout << "删除位置：";	cin >> i;
				while (i<0 || i>LL.len)
				{
					cout << "输入位置不合理，请重新输入！" << endl;
					cout << "删除位置：";	cin >> i;
				}
				ListDelet(LL, i, e);
				cout << "删除数据为：" << e << endl;
				break;
			case 4:
				cout << "查找位置：";	cin >> i;
				while (i<0 || i>LL.len)
				{
					cout << "查找位置不合理，请重新输入！" << endl;
					cout << "查找位置：";	cin >> i;
				}
				GetElem(LL, i, e);
				cout << "查找的数据为：" << e << endl;
				break;
			case 5:
				cout << "更新的数据位置：";	cin >> i;
				while (i<0 || i>LL.len)
				{
					cout << "更新位置不合理，请重新输入！" << endl;
					cout << "更新位置：";	cin >> i;
				}
				cout << "更新后的数据为："; cin >> e;
				ChangeElem(LL, i, e);
				break;
			}
		}
	} while (xh>0 && xh<6);
	return 0;
}
