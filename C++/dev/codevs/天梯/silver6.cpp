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
	long p,q;
	scanf("%ld%ld",&p,&q);
	printf("%ld",gcd(p,q));
	return 0;
} 
