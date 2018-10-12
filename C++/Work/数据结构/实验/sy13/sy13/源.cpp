#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int KeyType;
typedef struct {
	KeyType key;
}ElemType;
#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define LQ(a,b) ((a) <= (b))
typedef struct {
	ElemType *elem;
	int length;
}SSTable;
Status Create(SSTable &ST, int n);
int Search_Seq(SSTable ST, KeyType key);
int Search_Bin(SSTable ST, KeyType key);
int main() {
	SSTable st;
	cout << "请输入建立的静态搜索表的元素个数：" << endl;
	int n;
	cin >> n;
	Create(st, n);
	while (cout << "请输入查找的元素：" && cin >> n) {
		cout << "顺序查找：" << Search_Seq(st, n) << " ； 折半查找：" << Search_Bin(st, n) << endl;
	}
	return 0;
}
Status Create(SSTable &ST, int n) {
	ST.elem = (ElemType*)malloc((n + 1) * sizeof(ElemType));
	ST.length = n;
	for (int i = 1; i <= n; i++) {
		cout << "请顺序输入第" << i << "个元素:";
		cin >> ST.elem[i].key;
	}
	return OK;
}
int Search_Seq(SSTable ST, KeyType key) {
	int i;
	ST.elem[0].key = key;
	for (i = ST.length; !EQ(ST.elem[i].key, key); --i);
	return i;
}
int Search_Bin(SSTable ST, KeyType key) {
	int low = 1, high = ST.length, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (EQ(key, ST.elem[mid].key)) return mid;
		else if (LT(key, ST.elem[mid].key)) high = mid - 1;
		else low = mid + 1;
	}
	return 0;
}