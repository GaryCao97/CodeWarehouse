#include<iostream>
using namespace std;
//GPLT
int main(){
	int ch[4];
	ch[0] = ch[1] = ch[2] = ch[3] = 0;
	char str[10001];
	cin >> str;
	for (int i = 0; i < strlen(str); i++){
		if (str[i] == 'g' || str[i] == 'G')ch[0] += 1;
		if (str[i] == 'p' || str[i] == 'P')ch[1] += 1;
		if (str[i] == 'l' || str[i] == 'L')ch[2] += 1;
		if (str[i] == 't' || str[i] == 'T')ch[3] += 1;
	}
	while (ch[0] > 0 || ch[1] > 0 || ch[2] > 0 || ch[3] > 0){
		if (ch[0] > 0){
			cout << 'G';
			ch[0]--;
		}
		if (ch[1] > 0){
			cout << 'P';
			ch[1]--;
		}
		if (ch[2] > 0){
			cout << 'L';
			ch[2]--;
		}
		if (ch[3] > 0){
			cout << 'T';
			ch[3]--;
		}
	}
	return 0;
}