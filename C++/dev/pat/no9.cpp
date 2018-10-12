#include<iostream>
using namespace std;
int main(){
	char ch[81];
	int num[80];
	int n = 0,i,j;
	num[0] = 0;
	for(i = 0;i < 81;i++){
		ch[i] = getchar();
		if(ch[i] == 10){
			ch[i] = 0;
			break;
		}
		else if(ch[i] == ' '){
			num[++n] = i;
		}
	}
	num[n+1] = i;
	for(i = n;i >= 0;i--){
		for(j = num[i]+(i == 0?0:1);j < num[i+1];j++)
			cout << ch[j];
		if(i != 0)
			cout << ' ';
	}
	return 0;
}
