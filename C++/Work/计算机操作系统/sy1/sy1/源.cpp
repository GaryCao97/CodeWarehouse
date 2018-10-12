#include<iostream>
#include<iomanip>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef int Status;
typedef struct {
	int ResourceNum, ProcessNum;
	int *Available;
	int **Max;
	int **Allocation;
	int **Need;
	int *SaveOrder;
}Dijkstra;
void InitDij(Dijkstra &D, int n, int m);//初始化
void CopyDij(Dijkstra D, Dijkstra &d);//复制银行家数组
Status CheckSave(Dijkstra D);//安全性检查并得出安全序列
Status DijkstraRequest(Dijkstra &D, int i, int *Request);//资源请求
void InputDij(Dijkstra &D);//输入Dij数组
void OutputDij(Dijkstra D);//输出Dij数组
void InitDij(Dijkstra &D, int n, int m) {
	D.ResourceNum = m;
	D.ProcessNum = n;
	D.Available = (int *)malloc(m * sizeof(int));
	D.Max = (int **)malloc(n * sizeof(int));
	D.Allocation = (int **)malloc(n * sizeof(int));
	D.Need = (int **)malloc(n * sizeof(int));
	D.SaveOrder = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		D.Max[i] = (int *)malloc(m * sizeof(int));
		D.Allocation[i] = (int *)malloc(m * sizeof(int));
		D.Need[i] = (int *)malloc(m * sizeof(int));
	}
}
void CopyDij(Dijkstra D, Dijkstra &d) {
	int m = D.ResourceNum;
	int n = D.ProcessNum;
	InitDij(d, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			d.Max[i][j] = D.Max[i][j];
			d.Allocation[i][j] = D.Allocation[i][j];
			d.Need[i][j] = D.Need[i][j];
		}
	}
	for (int j = 0; j < m; j++) {
		d.Available[j] = D.Available[j];
	}
}
Status CheckSave(Dijkstra D) {
	int sign = 0;
	int *Work = (int *)malloc(D.ResourceNum * sizeof(int)),
		*Finish = (int *)malloc(D.ProcessNum * sizeof(int));
	for (int j = 0; j < D.ResourceNum; j++)
		Work[j] = D.Available[j];
	for (int i = 0; i < D.ProcessNum; i++)
		Finish[i] = FALSE;
	do {
		int tag = 0;
		for (int i = 0; i < D.ProcessNum; i++) {
			tag = 0;
			if (Finish[i] != FALSE)continue;
			for (int j = 0; j < D.ResourceNum; j++) {
				if (D.Need[i][j] <= Work[j])
					tag++;
			}
			if (tag == D.ResourceNum) {
				for (int j = 0; j < D.ResourceNum; j++)
					Work[j] = Work[j] + D.Allocation[i][j];
				Finish[i] = TRUE;
				D.SaveOrder[sign++] = i;
				//break;
			}
		}
		if (tag != D.ResourceNum)break;
	} while (TRUE);
	for (int i = 0; i < D.ProcessNum; i++) {
		if (Finish[i] == FALSE) return ERROR;
	}
	return OK;
}
Status DijkstraRequest(Dijkstra &D, int i, int *Request) {
	Dijkstra d;
	CopyDij(D, d);
	for (int j = 0; j < d.ResourceNum; j++) {
		if (Request[j] > d.Need[i][j]) return ERROR;
		if (Request[j] > d.Available[j]) return ERROR;
	}
	for (int j = 0; j < d.ResourceNum; j++) {
		d.Available[j] = d.Available[j] - Request[j];
		d.Allocation[i][j] = d.Allocation[i][j] + Request[j];
		d.Need[i][j] = d.Need[i][j] - Request[j];
	}
	if (CheckSave(d) == OK) {
		for (int j = 0; j < d.ResourceNum; j++) {
			D.Available[j] = d.Available[j];
			D.Allocation[i][j] = d.Allocation[i][j];
			D.Need[i][j] = d.Need[i][j];
		}
		CheckSave(D);
		return OK;
	}
	return ERROR;
}
void InputDij(Dijkstra &D) {
	cout << "请输入Available数组：" << endl;
	for (int j = 0; j < D.ResourceNum; j++)
		cin >> D.Available[j];
	cout << "请输入Max矩阵：" << endl;
	for (int i = 0; i < D.ProcessNum; i++)
		for (int j = 0; j < D.ResourceNum; j++)
			cin >> D.Max[i][j];
	cout << "请输入Allocation矩阵：" << endl;
	for (int i = 0; i < D.ProcessNum; i++)
		for (int j = 0; j < D.ResourceNum; j++)
			cin >> D.Allocation[i][j];
	cout << "请输入Need矩阵：" << endl;
	for (int i = 0; i < D.ProcessNum; i++)
		for (int j = 0; j < D.ResourceNum; j++)
			cin >> D.Need[i][j];
}
void OutputDij(Dijkstra D) {
	cout << setw(D.ResourceNum * 4.5) << "Max";
	cout << setw(D.ResourceNum * 5.5) << "Allocation";
	cout << setw(D.ResourceNum * 3) << "Need";
	cout << endl;
	cout << setw(4) << ' ';
	for (int j = 0; j < D.ResourceNum; j++)
		cout << setw(4) << (char)('A' + j);
	for (int j = 0; j < D.ResourceNum; j++)
		cout << setw(4) << (char)('A' + j);
	for (int j = 0; j < D.ResourceNum; j++)
		cout << setw(4) << (char)('A' + j);
	cout << endl;
	for (int i = 0; i < D.ProcessNum; i++) {
		int sign = i;//D.SaveOrder[i];
		cout << setw(4) << sign;
		for (int j = 0; j < D.ResourceNum; j++)
			cout << setw(4) << D.Max[sign][j];
		for (int j = 0; j < D.ResourceNum; j++)
			cout << setw(4) << D.Allocation[sign][j];
		for (int j = 0; j < D.ResourceNum; j++)
			cout << setw(4) << D.Need[sign][j];
		cout << endl;
	}
}
int main() {
	Dijkstra D;
	int m, n;
	cout << "请输入资源类别的数目：";
	cin >> m;
	cout << "请输入进程总数：";
	cin >> n;
	InitDij(D, n, m);
	InputDij(D);
	if(CheckSave(D) == OK)
		for (int i = 0; i < D.ProcessNum; i++)
			cout << D.SaveOrder[i] << ' ';
	else cout << "T0时刻不安全";
	cout << endl;
	do {
		cout << "请输入资源请求：（i，A，B,C，...）" << endl;
		int n, *arr;
		cin >> n;
		arr = (int *)malloc(D.ResourceNum * sizeof(int));
		for (int j = 0; j < D.ResourceNum; j++)
			cin >> arr[j];
		if (DijkstraRequest(D, n, arr) == OK)
			for (int i = 0; i < D.ProcessNum; i++)
				cout << D.SaveOrder[i] << ' ';
		else cout << "未分配资源";
		cout << endl;
	} while (TRUE);
	return 0;
}