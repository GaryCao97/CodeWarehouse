#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int n,m;
	int *num;
	cin >> n >> m;
	m = m%n;
	num = (int*)malloc((n+m)*sizeof(int));
	for(int i = 0;i < n;i++) cin >> num[i];
	for(int i = n+m-1;i >= m;i--)
		num[i] = num[i-m];
	for(int i = 0;i < m;i++)
		num[i] = num[i+n];
	for(int i = 0;i < n;i++){
		cout << num[i];
		if(i != n-1)cout << ' ';
	}	
	return 0;
}
