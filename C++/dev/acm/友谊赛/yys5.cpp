#include <iostream>
#define SIZE 1001
using namespace std;
int main() {
	int i, j, n, max;
	int a[SIZE], d[SIZE];
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}
	max = 0;
	for (i = 1; i <= n; i++) {
		d[i] = 1;
		for (j = 1; j <= i - 1; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
		if (d[i] > max) max = d[i];
	}
	cout << max;
	return 0;
}
