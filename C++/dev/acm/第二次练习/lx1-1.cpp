#include<iostream>
using namespace std;
int main(){
	int n,num,flat,ans;
	while(scanf("%d",&n)!=EOF){
		flat = 0;
		for(int i = 0;i < n;i++){
			scanf("%d",&num);
			if(num%2){
				if(flat == 0){
					flat = 1;
					ans = num;
				}
				else ans*=num;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
