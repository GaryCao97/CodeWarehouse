#include<iostream>
#include <vector>
using namespace std;
typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
void LongestPath(BiTree bt)//求二叉树中的第一条最长路径长度,并输出最长路径上的节点
{
	BiTree p = bt; //l, s是栈，元素是二叉树结点指针，l中保留当前最长路径中的结点
	vector<BiTree> l, s;
	int i, top = 0, longest = 0;
	vector<int> tag;
	while (p || top >0) {
		while (p) {
			s[++top] = p;
			tag[top] = 0;
			p = p->lchild;
		} //沿左分枝向下
		if (tag[top] == 1) {    //当前结点的右分枝已遍历
			if (!s[top]->lchild && !s[top]->rchild)  //只有到叶子结点时，才查看路径长度
				if (top>longest) {
					for (i = 1; i <= top; i++)
						l[i] = s[i];
					longest = top;
					top--;
				}//保留当前最长路径到l栈，记住最高栈顶指针，退栈
		}
		else if (top>0) {
			tag[top] = 1;
			p = s[top]->rchild;
		}   //沿右子分枝向下
	}//while(p!=null||top>0)
	int k = 0;
	for (k = 0; k < longest; k++) {
		printf("%c ", l[k]->data);
	}
}//结束LongestPath


int CreateBiTree(BiTree &T) {
	char ch;
	if (cin.peek() == ' ') {
		cin.get();
		T = NULL;
	}
	else {
		cin >> ch;
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))return 0;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return 1;
}