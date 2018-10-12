#include<cstdio>
#include<cmath>
int main(){
	int n,m;
	const char base[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	scanf("%d%d",&n,&m);
	char ans[10];
	ans[9] = 0;
	int l = 8;
	while(n!=0){
		ans[l--]=base[n%m];
		n/=m;
	}
	printf("%s",&ans[l+1]);
	return 0;
} 
