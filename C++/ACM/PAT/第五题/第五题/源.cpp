#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[11117], b[1117];
void Find(int n){
	while (n != 1){
		if (n % 2){
			n = (3 * n + 1) / 2;;
			a[n] = 1;
		}
		else{
			n /= 2;
			a[n] = 1;
		}
	}
}
int main(){
	int n;
	int c[1117];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> b[i];
		Find(b[i]);
	}
	int l = 0;
	for (int i = 0; i < n; i++){
		if (a[b[i]] == 0)
			c[l++] = b[i];
	}
	sort(c, c + l);
	cout << c[l - 1];
	for (int i = l - 2; i >= 0; i--)
		cout << ' ' << c[i];
	return 0;
}