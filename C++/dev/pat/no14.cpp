#include<iostream>
#include<string.h>
using namespace std;
int main() {
	char ch[4][60];
	for (int i = 0; i < 4; i++) scanf("%s", ch[i]);
	int mark = 0;
	for (int i = 0; i < strlen(ch[0]) && i < strlen(ch[1]); i++) {
		if (ch[0][i] == ch[1][i] && (ch[1][i] >= 'A'&&ch[1][i] <= 'G')) {
			switch (ch[0][i]) {
			case 'A':  cout << "MON "; break;
			case 'B':  cout << "TUE "; break;
			case 'C':  cout << "WED "; break;
			case 'D':  cout << "THU "; break;
			case 'E':  cout << "FRI "; break;
			case 'F':  cout << "SAT "; break;
			case 'G':  cout << "SUN "; break;
			}
			mark = i;
			break;
		}
	}
	for (int j = mark + 1; j < strlen(ch[0]) && j < strlen(ch[1]); j++) {
		if (ch[0][j] == ch[1][j] && (ch[0][j] >= 'A' &&ch[0][j] <= 'N' || ch[0][j] >= '0'&&ch[0][j] <= '9')) {
			if (ch[0][j] >= 'A'&&ch[0][j] <= 'N') {
				int x = ch[0][j] - 'A' + 10;
				cout << x / 10 << x % 10 << ":";
			}
			else {
				int y = ch[0][j] - '0';
				cout << y / 10 << y % 10 << ":";
			}
			break;
		}
	}
	for (int k = 0; k < strlen(ch[2]) && k < strlen(ch[3]); k++) {
		if (ch[2][k] == ch[3][k] && (ch[2][k] >= 'A'&&ch[2][k] <= 'Z' || ch[2][k] >= 'a'&&ch[2][k] <= 'z')) {
			cout << k / 10 << k % 10;
		}
	}
	return 0;
}
