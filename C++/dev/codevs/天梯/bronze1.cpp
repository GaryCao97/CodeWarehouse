#include<cstdio>
int main(){
	long long num[101],min,max;
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%lld",&num[i]);
		if(i == 0){
			max = min = num[i];
		}
		else{
			max = max > num[i] ? max : num[i];
			min = min < num[i] ? min : num[i];
		}
	}
	printf("%lld %lld",min,max);
	return 0;
} 
