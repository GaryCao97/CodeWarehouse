#include<iostream>
#include<stdlib.h> 
using namespace std;
int main(){
	int n,m = 0;
	scanf("%d",&n);
	int *num = (int *)malloc(n*sizeof(int));
	int *tmp = (int *)malloc(n*sizeof(int));
	int *ans = (int *)malloc(n*sizeof(int));
	int i,j;
	int maxTag = 0,minTag = n-1;
	for(i = 0;i < n;i++){
		scanf("%d",&num[i]);
		tmp[i] = 0;
	}
	for(i = 0;i < n;i++){
		if(num[maxTag] <= num[i]){
			maxTag = i;
			tmp[i]++;
		}
	}
	for(i = n-1;i >= 0;i--){
		if(num[minTag] >= num[i]){
			minTag = i;
			tmp[i]++;
		}
	}
	for(i = 0;i < n;i++){
		if(tmp[i] == 2){
			ans[m++] = num[i];
		}
	}
	printf("%d\n",m);
	for(i = 0;i < m;i++){
		printf("%d",ans[i]);
		if(i < m-1)printf(" ");
	} 
	printf("\n");
	return 0;
}
