#include<iostream>
using namespace std;
int main(){
	int non[256];
	for(int i = 0;i < 256;i++) non[i] = 0;
	char input,output[100005];
	int i;
	for(;;){
		input = getchar();
		if(input != 10){
			non[input] = 1;
			if(input >= 'A' && input <= 'Z') non[input+'a'-'A'] = 1;
		}
		else break;
	}
	for(i = 0;;){
		input = getchar();
		if(input != 10){
			if((input >= 'A' && input <= 'Z') && non['+']!=0) continue;
			else if(non[input]==0){
				output[i++] = input;
			}
		}
		else break;
	}
	output[i] = 0;
	cout << output;
	return 0;
}
