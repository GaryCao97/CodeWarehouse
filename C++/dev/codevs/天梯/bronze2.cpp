#include<cstdio>
int main(){
	long long num,sum = 0;
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%lld",&num);
		sum += num;
	}
	printf("%lld",sum);
	return 0;
} 
