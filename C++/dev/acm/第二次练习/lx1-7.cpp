#include<iostream>
using namespace std;
#define sum(n) ((1+n)*n/2)
int main(){
	__int64 n;
	while(cin >> n){
		cout << sum(n) << endl << endl;
	}
	return 0;
}
