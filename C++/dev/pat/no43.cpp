#include<iostream>
using namespace std;
int main(){
	//PATest
	char ch;
	int num[6] = {0,0,0,0,0,0};
	char c[6] = {'P','A','T','e','s','t'};
	do{
		ch = getchar();
		if(ch == 'P')num[0]++;
		if(ch == 'A')num[1]++;
		if(ch == 'T')num[2]++;
		if(ch == 'e')num[3]++;
		if(ch == 's')num[4]++;
		if(ch == 't')num[5]++;
	}while(ch!=10);
	while(num[0]||num[1]||num[2]||num[3]||num[4]||num[5]){
		for(int i = 0;i < 6;i++){
			if(num[i]){
				num[i]--;
				cout << c[i];
			}
		}
	}
	return 0;
}
