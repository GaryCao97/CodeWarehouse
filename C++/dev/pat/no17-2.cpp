#include<iostream>
using namespace std;
int charToInt(char ch) { if (ch >= '0' && ch <= '9') return ch - '0'; else return -1; }
int main() {
	char ch[1001];
	int n;
	scanf("%s %d", ch, &n);
	int num = 0,i,flat = 0;
	for (i = 0; ch[i]; i++) {
		num = 10 * num + charToInt(ch[i]);
		if (num >= n){
			printf("%d", num / n);
			flat = 1;
		}
		else if(flat) printf("0");
		num = num % n;
	}
	if(flat == 0)printf("0");
	printf(" %d", num);
	return 0;
}
