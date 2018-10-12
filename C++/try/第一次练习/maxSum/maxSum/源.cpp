#include<iostream>
using namespace std;
void main(){
	int t, n[20];
	int max[20], start[20], end[20];
	scanf_s("%d", &t);
	for (int o = 0; o < t; o++){
		scanf_s("%d", &n[o]);
		int arr[100000];
		for (int p = 0; p < n[o]; p++){
			scanf_s("%d", &arr[p]);
		}
		int tmp = 0;
		start[o] = 0;
		end[o] = 0;
		int sum = arr[0];
		max[o] = arr[0];
		for (int i = 1; i < n[o]; i++){
			if (sum < 0){
				tmp = i;
				sum = 0;
			}
			sum += arr[i];
			if (sum > max[o]){
				start[o] = tmp;
				end[o] = i;
				max[o] = sum;
			}
		}
	}
	for (int q = 0; q < t; q++){
		if (q != 0)
			printf_s("\n");
		printf_s("Case %d:\n%d %d %d\n", q + 1, max[q], start[q] + 1, end[q] + 1);
	}
}