#include<iostream>
using namespace std;

void Bubble_1(int r[], int n) {
	int i = n - 1;  //初始时,最后位置保持不变  
	while (i> 0) {
		int pos = 0; //每趟开始时,无记录交换  
		for (int j = 0; j< i; j++)
			if (r[j]> r[j + 1]) {
				pos = j; //记录交换的位置   
				int tmp = r[j]; r[j] = r[j + 1]; r[j + 1] = tmp;
			}
		i = pos; //为下一趟排序作准备  
	}
}

int main(){
	int num[10], n = 10;
	for (int o = 0; o < n; o++){
		cout << "请输入" << endl;
		cin >> num[o];
	}
	for (int o = 0; o < n; o++){
		cout << num[o] << ' ';
	}
	cout << endl;
	Bubble_1(num, n);
	for (int o = 0; o < n; o++){
		cout << num[o] << ' ';
	}
}