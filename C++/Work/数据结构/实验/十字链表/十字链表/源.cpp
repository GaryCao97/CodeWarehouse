#include<iostream>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
typedef int Status;
typedef int ElemType; // 自行修改相应的元素类型 
typedef struct Node {//十字链表的节点 
	int i, j;
	ElemType e;
	Node *down, *right;
}OLNode, *OLink;
class SMatrix_OL {
private:
	OLink *rhead, *chead;//十字链表行指针、列指针 
	int mu, nu, tu;//十字链表所表示矩阵的行数mu、列数nu、非零元个数tu 
public:
	SMatrix_OL(int m = 0, int n = 0, int t = 0);//构造矩阵，即声明szlb类的同时传入行数、列数、非零元个数、并进行相应的初始化 
	Status InsertOLNode(OLNode *p);//节点的插入 
	Status DeleteOLNode(int i, int j, OLNode *e);//节点的删除 。。。 暂时并没有什么卵用 
	OLink GetRHead(int i) { // 获得行指针数组的头指针 
		return rhead[i];
	}
	OLink GetCHead(int i) { // 获得列指针数组的头指针 
		return chead[i];
	}
	int GetMu() { return mu; } //这个，以及下面两个 分别获得矩阵的行数mu、列数nu、非零元个数tu 
	int GetNu() { return nu; }
	int GetTu() { return tu; }
	Status Create(); // 创建十字链表 
	SMatrix_OL Transpose(); // 转置十字链表，返回值为 转置后的链表类 
	SMatrix_OL operator+(SMatrix_OL b); //  这个，以及下面两个 分别是对szlb类中 + - * 三种运算符的重载 
	SMatrix_OL operator-(SMatrix_OL b);
	SMatrix_OL operator*(SMatrix_OL b);
	void Output(); // szlb的输出 
};//szlb
SMatrix_OL::SMatrix_OL(int m, int n, int t) {
	mu = m;
	nu = n;
	tu = t;
	rhead = (OLink *)malloc((m + 1) * sizeof(OLink));
	chead = (OLink *)malloc((n + 1) * sizeof(OLink));
	for (int x = 1; x <= m; x++)
		rhead[x] = NULL;
	for (int y = 1; y <= n; y++)
		chead[y] = NULL;
}//SMatrix_OL()
void MakeNode(int i, int j, ElemType e, OLNode *p) { // 创建节点的函数，就是将相应的值赋值给相应的变量 
	p->i = i;
	p->j = j;
	p->e = e;
	p->down = NULL;
	p->right = NULL;
}//MakeNode()
Status SMatrix_OL::InsertOLNode(OLNode *p) { //根据书上算法实现的节点插入 
	int i = p->i, j = p->j;
	OLNode *q;
	//行插入 
	if (rhead[i] == NULL || rhead[i]->j > j) {
		p->right = rhead[i];
		rhead[i] = p;
	}//if
	else {
		for (q = rhead[i]; (q->right) && (q->right->j < j); q = q->right);//获取插入位置的前一个节点 
		if ((q->right) && (q->right->j == j))return ERROR;
		p->right = q->right;
		q->right = p;
	}//else
	 //列插入 
	if (chead[j] == NULL || chead[j]->i > i) {
		p->down = chead[j];
		chead[j] = p;
	}//if
	else {
		for (q = chead[j]; (q->down) && (q->down->i < i); q = q->down);//获取插入位置的前一个节点 
		if ((q->down) && (q->down->i == i))return ERROR;
		p->down = q->down;
		q->down = p;
	}//else
	tu++;//非零元个数加一 
	return OK;
}//InsertOLNode() 
Status SMatrix_OL::DeleteOLNode(int i, int j, OLNode *e) { // ：） 随便看看就好 
	OLNode *p, *q;
	if (rhead[i] == NULL || rhead[i]->j > j || chead[j] == NULL || chead[j]->i > i) return ERROR;
	else {
		for (q = rhead[i]; (q->right) && (q->right->j < j); q = q->right)p = q;
		if ((q->right) && (q->right->j == j)) {
			q->right = q->right->right;
		}//if
		else return ERROR;
		for (q = chead[j]; (q->down) && (q->down->i < i); q = q->down);
		if ((q->down) && (q->down->i == i)) {
			q->down = q->down->down;
		}//if
		else return ERROR;
	}//else
	return OK;
}//DeleteOLNode()
Status SMatrix_OL::Create() {
	int m, n, t;
	OLNode *p;
	int i, j;
	ElemType e;
	cout << "请分别输入m,n,t";
	cin >> m >> n >> t;
	mu = m;
	nu = n;
	if (!(rhead = (OLink *)malloc((m + 1) * sizeof(OLink)))) return ERROR;
	if (!(chead = (OLink *)malloc((n + 1) * sizeof(OLink)))) return ERROR;
	for (int x = 1; x <= m; x++)
		rhead[x] = NULL;
	for (int y = 1; y <= n; y++)
		chead[y] = NULL;
	for (int z = 1; z <= t; z++) {
		cout << "请分别输入i,j,e";
		cin >> i >> j >> e;
		if (!(p = (OLNode *)malloc(sizeof(OLNode)))) return ERROR;
		MakeNode(i, j, e, p);
		InsertOLNode(p);
	}//for
	return OK;
}//Create()
SMatrix_OL SMatrix_OL::Transpose() { // 转置函数 
	SMatrix_OL b(nu, mu);
	OLNode *p, *q;
	int i, j;
	ElemType e;
	for (int x = 1; x <= nu; x++) {
		q = chead[x];
		while (q) {
			p = (OLNode *)malloc(sizeof(OLNode));
			i = q->j;
			j = q->i;
			e = q->e;
			MakeNode(i, j, e, p);
			b.InsertOLNode(p);
			q = q->down;
		}//while 
	}//for 
	return b;
}// Transpose()
SMatrix_OL SMatrix_OL::operator+(SMatrix_OL b) {//实现十字链表表示的矩阵的相加 
	SMatrix_OL c(mu, nu);
	OLNode *p, *q, *r;
	int i, j;
	ElemType e;
	for (int x = 1; x <= mu; x++) {
		p = rhead[x];
		q = b.GetRHead(x);
		while (p || q) {
			r = (OLNode *)malloc(sizeof(OLNode));
			i = x;
			if (!q || (p && p->j < q->j)) {
				j = p->j;
				e = p->e;
				MakeNode(i, j, e, r);
				p = p->right;
			}//if
			else if (!p || (q && p->j > q->j)) {
				j = q->j;
				e = q->e;
				MakeNode(i, j, e, r);
				q = q->right;
			}//else if
			else {
				j = p->j;
				e = p->e + q->e;
				MakeNode(i, j, e, r);
				p = p->right;
				q = q->right;
			}//else
			if (e == 0)continue;
			c.InsertOLNode(r);
		}//while
	}//for
	return c;
}//operator+()
SMatrix_OL SMatrix_OL::operator-(SMatrix_OL b) {//实现十字链表表示的矩阵的相减 
	SMatrix_OL c(mu, nu);
	OLNode *p, *q, *r;
	int i, j;
	ElemType e;
	for (int x = 1; x <= mu; x++) {
		p = rhead[x];
		q = b.GetRHead(x);
		while (p || q) {
			r = (OLNode *)malloc(sizeof(OLNode));
			i = x;
			if (!q || (p && p->j < q->j)) {
				j = p->j;
				e = p->e;
				MakeNode(i, j, e, r);
				p = p->right;
			}//if
			else if (!p || (q && p->j > q->j)) {
				j = q->j;
				e = -q->e;
				MakeNode(i, j, e, r);
				q = q->right;
			}//else if
			else {
				j = p->j;
				e = p->e - q->e;
				MakeNode(i, j, e, r);
				p = p->right;
				q = q->right;
			}//else 
			if (e == 0)continue;
			c.InsertOLNode(r);
		}//while
	}//for
	return c;
}//operator-()
SMatrix_OL SMatrix_OL::operator*(SMatrix_OL b) {//实现十字链表表示的矩阵的相乘 
	SMatrix_OL c(mu, b.GetNu());
	OLNode *p, *q, *r;
	int i, j;
	ElemType e;
	for (i = 1; i <= mu; i++) {
		for (j = 1; j <= b.nu; j++) {
			p = rhead[i];
			q = b.GetCHead(j);
			e = 0;
			while (p && q) {
				if (p->j == q->i) {		//两个链表中 前者的第i行  后者的第j列 
					e += p->e * q->e;	//对应元素相乘，求和 
					p = p->right;
					q = q->down;
				}//if
				else {
					if (p->j > q->i) {
						q = q->down;
					}//if
					else if (p->j < q->i) {
						p = p->right;
					}//else if
				}//else
			}//while
			r = (OLNode *)malloc(sizeof(OLNode));
			MakeNode(i, j, e, r);
			if (e == 0)continue;
			c.InsertOLNode(r);
		}//for
	}//for
	return c;
}//operator*()
void SMatrix_OL::Output() {
	for (int m = 1; m <= mu; m++) {
		OLNode *p = rhead[m];
		while (p) {
			cout << "(" << p->i << "," << p->j << ")" << p->e << ' ';
			p = p->right;
		}//while 
		cout << endl;
	}//for
}//Output()
int main() {
	SMatrix_OL m, n, o;
	cout << "矩阵m的创建" << endl;
	m.Create();
	cout << "矩阵n的创建" << endl;
	n.Create();
	system("pause");
	system("cls");
	o = m.Transpose();
	cout << "矩阵m" << endl;
	m.Output();
	cout << "的转置" << endl;
	o.Output();
	system("pause");
	system("cls");
	o = m + n;
	cout << "矩阵m" << endl;
	m.Output();
	cout << "矩阵n" << endl;
	n.Output();
	cout << "的和" << endl;
	o.Output();
	system("pause");
	system("cls");
	o = m * n;
	cout << "矩阵m" << endl;
	m.Output();
	cout << "矩阵n" << endl;
	n.Output();
	cout << "的积" << endl;
	o.Output();
	return 0;
}
