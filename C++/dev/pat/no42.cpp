#include<iostream>
using namespace std;
int main(){
	char ch;
	int num[256];
	int maxTag = 'a';
	for(int i = 0;i < 256;i++) num[i] = 0;
	do{
		ch = getchar();
		if(ch >= 'A' && ch <= 'Z') ch += 'a' - 'A';
		num[ch]++;
	}while(ch!=10);
	for(int i = 'a';i <= 'z';i++){
		if(num[i] > num[maxTag]) 
			maxTag = i;
	}
	printf("%c %d",maxTag,num[maxTag]);
	return 0;
}
