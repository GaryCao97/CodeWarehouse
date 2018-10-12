#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct {
	double num;
	double allM;
	double perM;
}mooncake;
int main() {
	int n;
	double m;
	int i;
	cin >> n >> m;
	mooncake *mc = (mooncake*)malloc(n * sizeof(mooncake));
	for (i = 0; i < n; i++) {
		cin >> mc[i].num;
	}
	for (i = 0; i < n; i++) {
		cin >> mc[i].allM;
		mc[i].perM = mc[i].allM / mc[i].num;
	}
	i = n - 1;
	while (i> 0) {
		int pos = 0;
		for (int j = 0; j< i; j++)
			if (mc[j].perM < mc[j + 1].perM) {
				pos = j;
				mooncake *tmp = (mooncake*)malloc(sizeof(mooncake));
				tmp->num = mc[j].num;
				tmp->allM = mc[j].allM;
				tmp->perM = mc[j].perM;
				mc[j].num = mc[j + 1].num;
				mc[j].allM = mc[j + 1].allM;
				mc[j].perM = mc[j + 1].perM;
				mc[j + 1].num = tmp->num;
				mc[j + 1].allM = tmp->allM;
				mc[j + 1].perM = tmp->perM;
			}
		i = pos;
	}
	double sum = 0;
	i = 0;
	while (m&&i<n) {
		if (mc[i].num >= m) {
			sum += ((double)m / (double)mc[i].num)*mc[i].allM;
			m -= m;
		}
		else {
			sum += mc[i].allM;
			m -= mc[i].num;
			i++;
		}
	}
	printf("%.2lf\n", sum);
	return 0;
}
