#include<iostream>
#include<deque>
using namespace std;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
//#define INFEASIBLE  -1
//#define OVERFLOW    -2
typedef int Status;
typedef char TElemType;

typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

Status CreateBiTree(BiTree &T);//���򴴽�������
Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType));//�������������
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType));//�������������
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType));//�������������
Status LevelOrderTraverse(BiTree T, Status(*Visit)(TElemType));//�������������

Status CreateBiTree(BiTree &T) {
	TElemType ch;
	if (cin.peek() == ' ') {
		cin.get();
		T = NULL;
	}
	else {
		cin >> ch;
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))return ERROR;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}
Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType)) {
	if (T) {
		if (Visit(T->data))
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR;
	}
	else return OK;
}
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType)) {
	if (T) {
		if (InOrderTraverse(T->lchild, Visit))
			if (Visit(T->data))
				if (InOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR;
	}
	else return OK;

}
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType)) {
	if (T) {
		if (PostOrderTraverse(T->lchild, Visit))
			if (PostOrderTraverse(T->rchild, Visit))
				if (Visit(T->data))
					return OK;
		return ERROR;
	}
	else return OK;

}
Status LevelOrderTraverse(BiTree T, Status(*Visit)(TElemType)) {
	if (!T)return ERROR;
	deque<BiTree> Qh, Ql;
	BiTree t;
	Ql.push_back(T);
	do {
		Qh.swap(Ql);
		Ql.clear();
		while (!Qh.empty()) {
			t = Qh.front();
			Qh.pop_front();
			if (t) {
				Visit(t->data);
				if (t->lchild)Ql.push_back(t->lchild);
				if (t->rchild)Ql.push_back(t->rchild);
			}
		}
	} while (!Ql.empty());
	return OK;
}
Status PrintElement(TElemType e) {
	printf("%c ", e);
	return OK;
}
Status Swap(BiTree &T) {
	if (T) {
		Swap(T->lchild);
		Swap(T->rchild);
		BiTree tmp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = tmp;
	}
	return OK;
}

int main() {
	BiTree T;
	cout << "������ʽ����һ�����������ÿո����սڵ㣺" << endl;
	CreateBiTree(T);
	cout << "�������������Ϊ��" << endl;
	PreOrderTraverse(T, PrintElement);
	cout << endl << "�������������Ϊ��" << endl;
	InOrderTraverse(T, PrintElement);
	cout << endl << "�����ĺ������Ϊ��" << endl;
	PostOrderTraverse(T, PrintElement);
	cout << endl << "�����Ĳ������Ϊ��" << endl;
	LevelOrderTraverse(T, PrintElement);
	cout << endl;
	return 0;
}