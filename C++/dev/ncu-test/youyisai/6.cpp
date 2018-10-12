#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int n,s,d,sum = 0;
	cin >> n;
	while(n--){
		cin >> s >> d;
		if(sum >= s){
			int i = ((sum - s) / d) + 1;
			sum = s + i * d;
		}
		else sum = s;
	}
	cout << sum;
	return 0;
} 
