#include<iostream>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
typedef int Status;
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
Status CreateBiTree(BiTree &T);//先序创建二叉树
int GetLevesNum(BiTree T);//叶子结点数
int GetNonlevesNum(BiTree T);//非叶子结点数
int GetAllNum(BiTree T);//所有结点数
int Depth(BiTree T);//树的深度
Status SearchFromTree(BiTree T, TElemType value);//查找
Status CreateBiTree(BiTree &T) {
	TElemType ch;
	if (cin.peek() == ' ' || cin.peek() == 13) {
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
int GetLevesNum(BiTree T) {
	if (!T)return 0;
	else if (!T->lchild && !T->rchild)return 1;
	else return GetLevesNum(T->lchild) + GetLevesNum(T->rchild);
}
int GetNonlevesNum(BiTree T) {
	if (!T || (!T->lchild && !T->rchild))return 0;
	else return GetNonlevesNum(T->lchild) + GetNonlevesNum(T->rchild) + 1;
}
int GetAllNum(BiTree T) {
	if (!T)return 0;
	else return GetAllNum(T->lchild) + GetAllNum(T->rchild) + 1;
}
int Depth(BiTree T) {
	int hl, hr;
	if (!T)return 0;
	if (T && (!T->lchild && !T->rchild))return 1;
	else {
		hl = Depth(T->lchild);
		hr = Depth(T->rchild);
		if (hl > hr)return hl + 1;
		else return hr + 1;
	}
}
Status SearchFromTree(BiTree T, TElemType value) {
	if (T) {
		if (T->data == value) {
			return OK;
		}
		else {
			return SearchFromTree(T->lchild, value) || SearchFromTree(T->rchild, value);
		}
	}
	return ERROR;
}
int main() {
	BiTree T;
	cout << "按先序创建二叉树：" << endl;
	CreateBiTree(T);
	cout << "该树的叶子节点数为：" << GetLevesNum(T) << endl;
	cout << "该树的非叶子节点数为：" << GetNonlevesNum(T) << endl;
	cout << "该树的总节点数为：" << GetAllNum(T) << endl;
	cout << "该树的高度为：" << Depth(T) << endl;
	TElemType value;
	do {
		cout << "请输入要查找的value值：";
		cin >> value;
		if (SearchFromTree(T, value)) {
			cout << "查找成功" << endl;
		}
		else {
			cout << "查找失败" << endl;
			break;
		}
	} while (1);
}