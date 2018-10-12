#include<iostream>
#include<string.h>
using namespace std;
int charToint(char ch) {
	if (ch >= '0' && ch <= '9')return ch - '0';
	else return -1;
}
int main() {
	char ch1[101], ch2[101], ans[101], sub[14] = "0123456789JQK";
	scanf("%s%s", ch1, ch2);
	int n1 = strlen(ch1), n2 = strlen(ch2), i, j;
	ans[n2] = '\0';
	int num;
	for (i = n2 - 1, j = n1 - 1; i >= 0 && j >= 0; i--, j--) {
		if ((n2 - i) % 2 == 0) {
			ans[i] = (charToint(ch2[i]) - charToint(ch1[j]) + 10) % 10;
		}
		else {
			ans[i] = (charToint(ch1[j]) + charToint(ch2[i])) % 13;
		}
		ans[i] = sub[ans[i]];
	}
	for (j = 0; j < (n2 - n1); j++)ans[j] = ch2[j];
	printf("%s\n", ans);
	return 0;
}
