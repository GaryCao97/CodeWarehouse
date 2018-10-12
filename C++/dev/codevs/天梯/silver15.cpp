#include<cstdio>
#include<cstdlib>
#include<deque>
using namespace std;
typedef struct Bin{
	int index;
	Bin *lchild;
	Bin *rchild;
}*BTree;
void PreOrderTraverse(BTree T) {
	if(T){
		printf("%d ",T->index);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
void InOrderTraverse(BTree T) {
	if(T){
		InOrderTraverse(T->lchild);
		printf("%d ",T->index);
		InOrderTraverse(T->rchild);
	}
}
void PostOrderTraverse(BTree T) {
	if(T){
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%d ",T->index);
	}
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
	PreOrderTraverse(root);
	printf("\n");
	InOrderTraverse(root);
	printf("\n");
	PostOrderTraverse(root);
	return 0;
} 
