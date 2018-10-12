#include<stdio.h>
#include<string.h>
int main(){
	char s[301];
	int l;
	while(scanf("%s",s)!=EOF){
		l = strlen(s);
		for(int i = l-1;i>=0;i--)printf("%c",s[i]);
		printf("\n");
	}
	return 0;
} 
