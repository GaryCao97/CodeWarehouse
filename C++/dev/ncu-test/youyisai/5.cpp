#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	long n;
	cin >> n;
	long l[n],sum = 0;
	bool s[n];
	for(long i = 0;i < n;i++){
		scanf("%ld",&l[i]);
	}
	memset(s,false,sizeof(s));
	long now = n - l[n - 1] - 1;
	for(long i = n - 2;i >= 0;i--){
		if(i >= now) s[i]=true;
		now = min(now,i-l[i]);
	}
	for(long i = 0;i < n;i++){
		if(!s[i])sum++;
	}
	cout << sum;
	return 0;
} 
