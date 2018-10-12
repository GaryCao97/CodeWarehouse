#include<iostream>
using namespace std;
int main(){
	long n,k;
	while(scanf("%ld%ld",&n,&k)!=EOF){
		long long ans,t;
		t = 2*k;
		if(t>=n)t = n-1;
		ans = ((n - 1 + n - t)*t)/2;
		cout << ans << endl;
	}
	return 0;
} 
