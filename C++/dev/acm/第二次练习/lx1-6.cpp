#include<iostream>
#include<cmath>
using namespace std;
#define f(n) (n * n + n + 41)
int isPrime(int num){
	int tag = 1;
	for(int i = 2;i <= sqrt(num);i++){
		if(!(num%i)){
			tag = 0;
			break;
		}
	}
	return tag;
}
int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	while(x!=0||y!=0){
		int tag=1;
		for(int i = x;i <= y;i++){
			if(!isPrime(f(i))){
				tag = 0;
				break;
			}
		}
		if(tag==0)printf("Sorry\n");
		else printf("OK\n");
		scanf("%d %d",&x,&y);
	}
	return 0;
}
