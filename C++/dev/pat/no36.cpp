#include<iostream>
using namespace std;
int main(){
	int n,m;
	char ch;
	cin >> n >> ch;
	m = 0.5 + n/2.0;
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			if(i == 0 || i == m-1)cout << ch;
			else{
				if(j == 0 || j == n-1) cout << ch;
				else cout << ' ';
			}
		}
		cout <<  endl;
	}
	return 0;
}
