#include<cstdio>
#include<cstdlib>
int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	char ch[n+1];
	scanf("%s",ch);
	while(t--){
		for(int i = 0;i < n;i++){
			if(ch[i] == 'B' && i<(n-1) && ch[i+1] == 'G'){
				ch[i] = 'G';
				ch[i+1] = 'B';
				i++;
			}
		}
	}
	printf("%s",ch);
	return 0;
} 
