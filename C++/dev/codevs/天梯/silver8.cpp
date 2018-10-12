#include<cstdio>
int ans[41];
int all(){
	ans[1] = 1;
	ans[2] = 1;
	for(int i = 3;i <= 40;i++){
		ans[i] = ans[i-2] + ans[i-1];
	}
}
int main(){
	all();
	int n;
	scanf("%d",&n);
	printf("%d",ans[n]);
	return 0;
} 
