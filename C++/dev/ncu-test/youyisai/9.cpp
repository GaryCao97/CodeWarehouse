#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
using namespace std;
bool isprime[20005];
int getMaxPrimeFactor(int g){
	for(int i = g;i > 0;i--){
		if(g % i == 0){
			if(isprime[i]){
				return i;
			}
		}
	}
}
void setPrime(){
	isprime[0] = isprime[1] = false;
    for (int i = 2; i <= 20000; i++){
    	int j;
    	for(j = 2;j <= sqrt(i);j++){
    		if(i%j == 0){
    			isprime[i] = false;
    			break;
			}
		}
		if(j>sqrt(i))isprime[i] = true;
    }
}
int main(){
	setPrime();
	int n,max = 0,index;
	while(scanf("%d",&n)!=EOF){
		max = 0;
		int num[n],prime[n];
		for(int i = 0;i < n;i++){
			scanf("%d",&num[i]);
			prime[i] = getMaxPrimeFactor(num[i]);
		}
		for(int i = 0;i < n;i++){
			if(max < prime[i]){
				max = prime[i];
				index = i;
			}
		}
		printf("%d\n",num[index]);
	}
	return 0;
} 
