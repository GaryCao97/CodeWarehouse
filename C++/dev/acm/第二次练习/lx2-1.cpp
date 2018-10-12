#include<iostream>
using namespace std;
int main(){
	int n,tag;
	while(scanf("%d",&n)!=EOF){
		tag=0;
		for(int i = 1;i <= n;i++){
			if(n%i==0)tag++;
		}
		printf("%d\n",tag%2);
	}
	return 0;
} 
