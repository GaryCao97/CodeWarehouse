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
Status CreateBiTree(BiTree &T);//���򴴽�������
int GetLevesNum(BiTree T);//Ҷ�ӽ����
int GetNonlevesNum(BiTree T);//��Ҷ�ӽ����
int GetAllNum(BiTree T);//���н����
int Depth(BiTree T);//�������
Status SearchFromTree(BiTree T, TElemType value);//����
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
	cout << "�����򴴽���������" << endl;
	CreateBiTree(T);
	cout << "������Ҷ�ӽڵ���Ϊ��" << GetLevesNum(T) << endl;
	cout << "�����ķ�Ҷ�ӽڵ���Ϊ��" << GetNonlevesNum(T) << endl;
	cout << "�������ܽڵ���Ϊ��" << GetAllNum(T) << endl;
	cout << "�����ĸ߶�Ϊ��" << Depth(T) << endl;
	TElemType value;
	do {
		cout << "������Ҫ���ҵ�valueֵ��";
		cin >> value;
		if (SearchFromTree(T, value)) {
			cout << "���ҳɹ�" << endl;
		}
		else {
			cout << "����ʧ��" << endl;
			break;
		}
	} while (1);
}