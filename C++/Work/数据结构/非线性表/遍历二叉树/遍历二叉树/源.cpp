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

Status CreateBiTree(BiTree &T);//先序创建二叉树
Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType));//先序遍历二叉树
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType));//中序遍历二叉树
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType));//后序遍历二叉树
Status LevelOrderTraverse(BiTree T, Status(*Visit)(TElemType));//层序遍历二叉树

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
	cout << "以先序方式输入一个二叉树，用空格代表空节点：" << endl;
	CreateBiTree(T);
	cout << "该树的先序遍历为：" << endl;
	PreOrderTraverse(T, PrintElement);
	cout << endl << "该树的中序遍历为：" << endl;
	InOrderTraverse(T, PrintElement);
	cout << endl << "该树的后序遍历为：" << endl;
	PostOrderTraverse(T, PrintElement);
	cout << endl << "该树的层序遍历为：" << endl;
	LevelOrderTraverse(T, PrintElement);
	cout << endl;
	return 0;
}