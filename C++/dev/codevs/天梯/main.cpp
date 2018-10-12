#include<cstdio>
#include<cstdlib>
#include<deque>
using namespace std;
typedef struct Bin{
	int index;
	Bin *lchild;
	Bin *rchild;
}*BTree;
int Depth(BTree T){
	int hl, hr;
	*T;
	if (!T)return 0;
	else if (!T->lchild && !T->rchild)return 1;
	else {
		hl = Depth(T->lchild);
		hr = Depth(T->rchild);
		if (hl > hr)return hl + 1;
		else return hr + 1;
	}
}
int Width(BTree T){
	int max = 0;
	deque<BTree> Qh, Ql;
	BTree t;
	Ql.push_back(T);
	do {
		max = Ql.size() > max ? Ql.size() : max;
		Qh.swap(Ql);
		Ql.clear();
		while (!Qh.empty()) {
			t = Qh.front();
			Qh.pop_front();
			if (t) {
				if (t->lchild)Ql.push_back(t->lchild);
				if (t->rchild)Ql.push_back(t->rchild);
			}
		}
	} while (!Ql.empty());
	return max;
}
int main(){
	BTree root;
	int n, l, r;
	scanf("%d",&n);
	root = (BTree)malloc(n * sizeof(Bin));
	for(int i = 0;i < n;i++){
		scanf("%d%d",&l,&r);
		root[i].index = i + 1;
		if(l){
			root[i].lchild = &root[l - 1];
		}
		else root[i].lchild = NULL;
		if(r){
			root[i].rchild = &root[r - 1];
		}
		else root[i].rchild = NULL;
	}
	printf("%d %d",Width(root),Depth(root));
	return 0;
} 
