#include<cstdio>
#include<cmath>
int main(){
	int num,isPrime = 1;
	scanf("%d",&num);
	for(int i = 2;i <= sqrt(num);i++){
		if(num%i==0){
			isPrime = 0;
			break;
		}
	}
	printf("\\%c",isPrime?'t':'n');
	return 0;
} 
