#include<iostream>
using namespace std;
void sort(long long *num) {
	int n;
	for (n = 0; num[n]; n++);
	int i = n - 1;
	while (i > 0) {
		int pos = 0;
		for (int j = 0; j< i; j++){
			if (num[j] > num[j + 1]) {
				pos = j;
				long long tmp = num[j];
				num[j] = num[j + 1]; 
				num[j + 1] = tmp;
			}
		}
		i = pos;
	}
}
int main() {
	return 0;
}