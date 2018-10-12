#include<cstdio>
#include<cmath>
#include<cstring>
int main(){
	int m,ans = 0;
	char n[10];
	const char base[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	scanf("%s%d",n,&m);
	int l = strlen(n) - 1;
	for(int i = l;i >= 0;i--){
		for(int j = 0;j <= 15;j++){
			if(n[i]==base[j]){
				ans += pow(m,l-i) * j;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
