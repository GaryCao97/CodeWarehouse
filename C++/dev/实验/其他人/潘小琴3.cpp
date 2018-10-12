//实验三 单链表的基本操作
//1）单链表结点类的定义
//2）单链表类的定义
//3)	在单链表前删除一个元素。
//4)	在单链表找第i个元素。
//5)	更新单链表i个元素的值。
//6)	遍历单链表

# include<iostream>
#include <stdlib.h>
#include <stdio.h>

# define OK 1
# define ERROR 0
# define OVERFLOW -2
typedef int ElemType;
typedef int Status;
using namespace std;

typedef struct  LNode {            //结点类型 
	ElemType data;
	struct  LNode *next;
} *Link, *Position;

typedef struct {          //链表类型 
	Link head, tail;
	int len;
} LinkList;

Status InitList(LinkList &L)          //初始化单链表 
{
	L.head = (Link)malloc(sizeof(LNode));
	if (!L.head) exit(OVERFLOW);
	L.tail = L.head;
	L.head->next = NULL;
	L.len = 0;
	return OK;
}

Status MakeNode(Link &p, ElemType e){       //创建结点 
	p = (Link)malloc(sizeof(LNode));
	if (!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	return OK;
}

Status ListInsert_L(LinkList &L, int i, ElemType e){   //插入结点
	Link p = L.head, s;
	int j = 0;
	while (p&&j<i - 1){
		p = p->next;
		++j;
	}
	if (!p || j>i - 1)
		return ERROR;
	MakeNode(s, e);
	s->next = p->next;
	p->next = s;
	++L.len;
	return OK;
}
Status ListDelete_L(LinkList &L, int i, ElemType &e){  //删除结点
	Link p = L.head;
	int j = 0;
	while (p->next&&j<i - 1){        //找到第i个结点,并使得p指向它的前驱
		p = p->next;
		++j;
	}
	if (!(p->next) || j>i + 1)  //判断第i个结点是否存在 
		return ERROR;
	e = p->next->data;
	p->next = p->next->next;
	--L.len;
	return OK;
}

Status GetElem(LinkList L, int i, ElemType &e){              //在单链表中查找第i个元素。
	Link p = L.head;
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

Status ChangeElem(LinkList &L, int i, ElemType e){            //更新单链表中第i个元素的值。
	Link p = L.head;
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

Status ListTraversse(LinkList L)                            //遍历顺序表。
{
	Link p = L.head->next;
	while (p)//应该是要判断当前结点的下一个节点是否为NULL
	{
		cout << p->data << " ";
		p = p->next;
	}
	return OK;
}


void menu(){
	cout << endl << "--------------菜单---------------" << endl;
	cout << "1).显示单链表" << endl;
	cout << "2).在单链表的第i个元素前插入一个元素" << endl;
	cout << "3).在单链表的第i个元素前删除一个元素。" << endl;
	cout << "4).在单链表中查找第i个元素" << endl;
	cout << "5).更新单链表中第i个元素的值。" << endl;
	cout << "   (输入其他数据结束操作)" << endl;
}

int main(){
	LinkList LL;
	int n;
	InitList(LL);
	cout << "单链表" << endl << "请入要输入的数据个数n：";
	cin >> n;
	cout << "请输入n个数据:";
	for (int i = 1; i <= n; i++){
		int a = 0;
		cin >> a;
		ListInsert_L(LL, i, a);
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
				cout << "插入数据："; cin >> e;
				ListInsert_L(LL, i, e);
				break;
			case 3:
				cout << "删除位置：";	cin >> i;
				ListDelete_L(LL, i, e);
				cout << "删除数据为：" << e << endl;
				break;
			case 4:
				cout << "查找位置：";	cin >> i;
				GetElem(LL, i, e);
				cout << "查找的数据为：" << e << endl;
				break;
			case 5:
				cout << "更新的数据位置：";	cin >> i;
				cout << "更新后的数据为："; cin >> e;
				ChangeElem(LL, i, e);
				break;
			}
		}
	} while (xh>0 && xh<6);
	return 0;
}
