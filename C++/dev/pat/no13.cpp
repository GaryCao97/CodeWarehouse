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
	int n,m,j = 0,k = 0;
	long long i;
	cin >> n >> m;
	for(i = 2;;i++){
		if(prime(i)){
			j++;
			if(j>=n){
				cout<<i;
				k++;
			}
			if(j==m) break;
			if(k%10!=0) cout << ' ';
			else if(k%10 ==0 && k!=0)cout << endl;
		}
	}
	return 0;
}
