#include<cstdio>
#include<cmath>
long gcd(long num1,long num2){
	while(num2!=0){
		int tmp = num1%num2;
		num1 = num2;
		num2 = tmp;
	}
	return num1;
}
int main(){
	long p,q,x0,y0;
	long ji;
	int ans = 0;
	scanf("%ld%ld",&x0,&y0);
	ji = x0*y0;
	for(p = 1;p <= sqrt(ji);p++){
		q = ji / p;
		if((p*q == ji) && (gcd(p,q) == x0))ans++;
	} 
	ans *= 2;
	printf("%d",ans);
	return 0;
} 
