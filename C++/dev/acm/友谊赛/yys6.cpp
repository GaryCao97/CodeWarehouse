#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e6;
int num[maxn];
int main() {
	int n;
	scanf("%d", &n);
	int cnt = 0;
	int m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
			num[++cnt] = i;
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &m);
		printf("%d\n", num[m]);
	}
	return 0;
}
