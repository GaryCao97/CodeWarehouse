#include<cstdio>
#include<cstdlib>
#include<cstring> 
int main(){
	char str[100][100];
	int n,i = 0;
	scanf("%d",&n);
	while(i < n){
		scanf("%s",str[i]);
		int len = strlen(str[i]);
		if(len > 10){
			printf("%c%d%c\n",str[i][0],len - 2,str[i][len-1]);
		}
		else printf("%s\n",str[i]);
		i++;
	}
	return 0;
} 
