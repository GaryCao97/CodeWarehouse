#include<iostream>
using namespace std;
int main(){
	long long m,n,sum1,sum2;
	while(cin >> m >> n){
		sum1 = 0;
		sum2 = 0;
		if(m > n){
			int tmp = m;
			m = n;
			n = tmp;
		}
		for(int i = m;i <= n;i++){
			if(i%2 ==0)sum1+=i*i;
			else sum2+=i*i*i;
		}
		cout << sum1 << " " << sum2 << endl;
	}
	return 0;
}
