#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	double num,sum = 0;
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%lf",&num);
		sum += num * (i+1) * (n-i);
	}
	printf("%.2lf",sum);
	return 0;
}
