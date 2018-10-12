#include<cstdio>
int ans[1001];
int all(){
	ans[1] = 1;
	for(int i = 2;i <= 1000;i++){
		ans[i] = 1;
		for(int j = i/2;j > 0;j--){
			ans[i]+=ans[j];
		}
	}
}
int main(){
	all();
	int n;
	scanf("%d",&n);
	printf("%d",ans[n]);
	return 0;
} 
