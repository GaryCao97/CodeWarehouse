#include<cstdio>
int f(int n,int step = 0){
	if(n == 1)return step;
	else if(n % 2)return f(3*n + 1,step+1);
	else return f(n / 2,step + 1);
}
int main(){
	int t,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&m);
		printf("%d",f(m));
		if(t!=0)printf("\n");
	}
	return 0;
} 
