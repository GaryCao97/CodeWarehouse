#include<iostream>
using namespace std;
void f(__int64 *n){
	n[0] = 0;
	n[1] = 1;
	for(int i = 2;i <= 50;i++)
		n[i] = n[i-1] + n[i-2];
}
int main(){
	__int64 n[50],m;
	f(n);
	cin >> m;
	while(m!=-1){
		cout << n[m] << endl;
		cin >> m;
	}
	return 0;
}
