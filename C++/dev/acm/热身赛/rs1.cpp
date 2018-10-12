#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int n,maxN = 0,*s,o,p;
	cin >> n;
	s = (int*)malloc(n*sizeof(int));
	for(int i = 0;i < n;i++)
		s[i] = 0;
	for(int i = 0;i < n;i++){
		cin >> o >> p;
		s[o]+=p;
		if(s[o]>s[maxN])maxN = o;
	}
	cout << maxN << ' '<< s[maxN];
	return 0;
} 
