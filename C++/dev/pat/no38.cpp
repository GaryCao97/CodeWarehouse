#include<iostream>
using namespace std;
int main(){
	int n,score;
	int num[101];
	for(int i = 0;i < 101;i++) num[i] = 0;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d",&score);
		num[score]++;
	}
	int m;
	scanf("%d",&m);
	for(int i = 0;i < m;i++){
		scanf("%d",&score);
		printf("%d",num[score]);
		if(i!=m-1)printf(" ");
	}
	return 0;
}
