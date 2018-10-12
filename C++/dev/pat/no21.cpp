#include<iostream>
#include<string.h> 
using namespace std;
int main(){
	char ch[1001];
	scanf("%s",ch);
	int len = strlen(ch);
	int num[10];
	for(int i = 0;i < 10;i++) num[i] = 0;
	for(int i = 0;i < len;i++)
		num[ch[i]-'0']++;
	for(int i = 0;i < 10;i++){
		if(num[i]!=0){
			printf("%d:%d\n",i,num[i]);
		}
	}
	return 0;
}
