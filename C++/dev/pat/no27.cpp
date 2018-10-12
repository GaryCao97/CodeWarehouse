#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main(){
	int n;
	char ch;
	cin >> n >> ch;
	int m = sqrt((n+1)/2.0);
	for(int i = m;i > 0;i--){
		cout << setw(m-i+1);
		for(int j = 1;j <= (2 * i - 1);j++){
			cout << ch;
		}
		cout << endl;
	}
	for(int i = 2;i <= m;i++){
		cout << setw(m-i+1);
		for(int j = 1;j <= (2 * i - 1);j++){
			cout << ch;
		}
		cout << endl;
	}
	cout << n - 2 * (m*m) + 1;
	return 0;
} 
