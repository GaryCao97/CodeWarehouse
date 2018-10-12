#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define LQ(a,b) ((a) <= (b))
#define MT(a,b) ((a) > (b))
#define MQ(a,b) ((a) >= (b))
typedef int Status;
typedef int KeyType;
typedef struct {
}InfoType;
typedef struct {
	KeyType key;
	InfoType otherinfo;
}RedType;
typedef struct {
	RedType *r;
	int length;
}SqList;

Status CreateList(SqList &L) {
	cout << "请输入顺序表的长度" << endl;
	cin >> L.length;
	L.r = new RedType[L.length + 1];
	for (int i = 1; i <= L.length; i++) {
		cout << "请输入第" << i << "个元素的关键字：";
		cin >> L.r[i].key;
	}
	return OK;
}
void PrintList(SqList L) {
	for (int i = 1; i <= L.length; i++)
		cout << L.r[i].key << " ";
	cout << endl;
}
Status InsertSort(SqList &L) {
	int i, j, n;
	n = 0;
	for (i = 2; i <= L.length; i++) {
		if (LT(L.r[i].key, L.r[i - 1].key)) {
			L.r[0] = L.r[i];
			L.r[i] = L.r[i - 1];
			for (j = i - 2; LT(L.r[0].key, L.r[j].key); j--) L.r[j + 1] = L.r[j];
			L.r[j + 1] = L.r[0];
		}
		cout << "第" << ++n << "趟排序后" << endl;
		PrintList(L);
	}
	return OK;
}
Status BubbleSort(SqList &L) {
	int i, j, k, n;
	k = L.length;
	n = 0;
	while (1) {
		i = k;
		for (j = 1; j < i; j++) {
			if (LT(L.r[j + 1].key, L.r[j].key)) {
				L.r[0] = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = L.r[0];
				k = j;
			}
		}
		if (i == k)break;
		cout << "第" << ++n << "趟排序后" << endl;
		PrintList(L);
	}
	return OK;
}
int SelectMinKey(SqList L, int i) {
	int j, min = i;
	for (j = i; j <= L.length; j++) {
		if (LT(L.r[j].key, L.r[min].key))min = j;
	}
	return min;
}
Status SelectSort(SqList &L) {
	int i, j;
	for (i = 1; i < L.length; i++) {
		j = SelectMinKey(L, i);
		if (i != j) {
			L.r[0] = L.r[j];
			L.r[j] = L.r[i];
			L.r[i] = L.r[0];
		}
		cout << "第" << i << "趟排序后" << endl;
		PrintList(L);
	}
	return OK;
}
int Partition(SqList &L, int low, int high) {
	L.r[0] = L.r[low];
	KeyType pivotkey = L.r[low].key;
	while (low < high) {
		while (low<high&&MQ(L.r[high].key, pivotkey))--high;
		L.r[low] = L.r[high];
		while (low<high&&LQ(L.r[low].key, pivotkey))++low;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}
Status QSort(SqList &L, int low, int high) {
	static int num = 0;
	if (low < high) {
		int pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivotloc + 1, high);
	}
	cout << "第" << ++num << "趟排序后" << endl;
	PrintList(L);
	return OK;
}

void CopyList(SqList &L1, SqList L2) {
	L1.length = L2.length;
	L1.r = new RedType[L1.length + 1];
	for (int i = 1; i <= L1.length; i++) {
		L1.r[i].key = L2.r[i].key;
	}
}
int main() {
	SqList L1, L2, L3, L4;
	CreateList(L1);
	CopyList(L2, L1);
	CopyList(L3, L1);
	CopyList(L4, L1);
	cout << "直接插入排序" << endl;
	InsertSort(L1);
	cout << "冒泡排序" << endl;
	BubbleSort(L2);
	cout << "简单选择排序" << endl;
	SelectSort(L3);
	cout << "快速排序" << endl;
	QSort(L4, 1, L4.length);
	return 0;
}
