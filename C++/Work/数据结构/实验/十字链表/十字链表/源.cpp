#include<iostream>
using namespace std;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
typedef int Status;
typedef int ElemType; // �����޸���Ӧ��Ԫ������ 
typedef struct Node {//ʮ������Ľڵ� 
	int i, j;
	ElemType e;
	Node *down, *right;
}OLNode, *OLink;
class SMatrix_OL {
private:
	OLink *rhead, *chead;//ʮ��������ָ�롢��ָ�� 
	int mu, nu, tu;//ʮ����������ʾ���������mu������nu������Ԫ����tu 
public:
	SMatrix_OL(int m = 0, int n = 0, int t = 0);//������󣬼�����szlb���ͬʱ��������������������Ԫ��������������Ӧ�ĳ�ʼ�� 
	Status InsertOLNode(OLNode *p);//�ڵ�Ĳ��� 
	Status DeleteOLNode(int i, int j, OLNode *e);//�ڵ��ɾ�� ������ ��ʱ��û��ʲô���� 
	OLink GetRHead(int i) { // �����ָ�������ͷָ�� 
		return rhead[i];
	}
	OLink GetCHead(int i) { // �����ָ�������ͷָ�� 
		return chead[i];
	}
	int GetMu() { return mu; } //������Լ��������� �ֱ��þ��������mu������nu������Ԫ����tu 
	int GetNu() { return nu; }
	int GetTu() { return tu; }
	Status Create(); // ����ʮ������ 
	SMatrix_OL Transpose(); // ת��ʮ����������ֵΪ ת�ú�������� 
	SMatrix_OL operator+(SMatrix_OL b); //  ������Լ��������� �ֱ��Ƕ�szlb���� + - * ��������������� 
	SMatrix_OL operator-(SMatrix_OL b);
	SMatrix_OL operator*(SMatrix_OL b);
	void Output(); // szlb����� 
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
void MakeNode(int i, int j, ElemType e, OLNode *p) { // �����ڵ�ĺ��������ǽ���Ӧ��ֵ��ֵ����Ӧ�ı��� 
	p->i = i;
	p->j = j;
	p->e = e;
	p->down = NULL;
	p->right = NULL;
}//MakeNode()
Status SMatrix_OL::InsertOLNode(OLNode *p) { //���������㷨ʵ�ֵĽڵ���� 
	int i = p->i, j = p->j;
	OLNode *q;
	//�в��� 
	if (rhead[i] == NULL || rhead[i]->j > j) {
		p->right = rhead[i];
		rhead[i] = p;
	}//if
	else {
		for (q = rhead[i]; (q->right) && (q->right->j < j); q = q->right);//��ȡ����λ�õ�ǰһ���ڵ� 
		if ((q->right) && (q->right->j == j))return ERROR;
		p->right = q->right;
		q->right = p;
	}//else
	 //�в��� 
	if (chead[j] == NULL || chead[j]->i > i) {
		p->down = chead[j];
		chead[j] = p;
	}//if
	else {
		for (q = chead[j]; (q->down) && (q->down->i < i); q = q->down);//��ȡ����λ�õ�ǰһ���ڵ� 
		if ((q->down) && (q->down->i == i))return ERROR;
		p->down = q->down;
		q->down = p;
	}//else
	tu++;//����Ԫ������һ 
	return OK;
}//InsertOLNode() 
Status SMatrix_OL::DeleteOLNode(int i, int j, OLNode *e) { // ���� ��㿴���ͺ� 
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
	cout << "��ֱ�����m,n,t";
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
		cout << "��ֱ�����i,j,e";
		cin >> i >> j >> e;
		if (!(p = (OLNode *)malloc(sizeof(OLNode)))) return ERROR;
		MakeNode(i, j, e, p);
		InsertOLNode(p);
	}//for
	return OK;
}//Create()
SMatrix_OL SMatrix_OL::Transpose() { // ת�ú��� 
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
SMatrix_OL SMatrix_OL::operator+(SMatrix_OL b) {//ʵ��ʮ�������ʾ�ľ������� 
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
SMatrix_OL SMatrix_OL::operator-(SMatrix_OL b) {//ʵ��ʮ�������ʾ�ľ������� 
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
SMatrix_OL SMatrix_OL::operator*(SMatrix_OL b) {//ʵ��ʮ�������ʾ�ľ������� 
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
				if (p->j == q->i) {		//���������� ǰ�ߵĵ�i��  ���ߵĵ�j�� 
					e += p->e * q->e;	//��ӦԪ����ˣ���� 
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
	cout << "����m�Ĵ���" << endl;
	m.Create();
	cout << "����n�Ĵ���" << endl;
	n.Create();
	system("pause");
	system("cls");
	o = m.Transpose();
	cout << "����m" << endl;
	m.Output();
	cout << "��ת��" << endl;
	o.Output();
	system("pause");
	system("cls");
	o = m + n;
	cout << "����m" << endl;
	m.Output();
	cout << "����n" << endl;
	n.Output();
	cout << "�ĺ�" << endl;
	o.Output();
	system("pause");
	system("cls");
	o = m * n;
	cout << "����m" << endl;
	m.Output();
	cout << "����n" << endl;
	n.Output();
	cout << "�Ļ�" << endl;
	o.Output();
	return 0;
}
