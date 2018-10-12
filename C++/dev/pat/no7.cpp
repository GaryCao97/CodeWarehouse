#include<iostream>
#include<math.h>
using namespace std;
int prime(long long num){
	int flag = 1;
	long long i = 2;
	for(;i <= sqrt(num);i++){
		if(num % i==0){
			flag = 0;
			break;
		}
	}
	return flag;
}
int main(){
	long long n,sum = 0;
	cin >> n;
	for(long long i = 5;i<=n;i=i+2){
		if(prime(i)==1 && prime(i-2)==1)
			sum++;
	}
	cout << sum;
	return 0;
}
