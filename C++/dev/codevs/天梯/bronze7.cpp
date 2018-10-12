#include<cstdio>
#include<cstring>
int main(){
	char str[500];
	gets(str);
	int len = strlen(str);
	for(int i = len - 1;i >= 0;i--){
		if(str[i] == ' '){
			for(int j = i + 1;j < len;j++){
				printf("%c",str[j]);
			}
			len = i;
			printf(" ");
		}
		else if(i == 0){
			for(int j = i;j < len;j++){
				printf("%c",str[j]);
			}
		}
	}
	return 0;
}
