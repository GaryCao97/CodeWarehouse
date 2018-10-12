#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
char nor[13][5] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
char high[13][5] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
typedef struct {
	int num;
	int tag;
}number;
int main() {
	char *ch;
	int num, tag = 0;
	int n, i = 0;
	cin >> n;
	number *all = (number*)malloc(n * sizeof(number));
	do {
		tag = 0;
		num = 0;
		ch = (char*)malloc(10 * sizeof(char));
		if (cin.peek() == 10) cin.get();
		if (cin.peek() >= '0' && cin.peek() <= '9') cin >> num;
		else {
			tag = 1;
			do {
				cin >> ch;
				for (int i = 0; i < 13; i++) {
					if (!strcmp(ch, nor[i])) {
						num += i;
						break;
					}
					if (!strcmp(ch, high[i])) {
						num += i * 13;
						break;
					}
				}
			} while (cin.peek() == ' ');
		}
		all[i].num = num;
		all[i].tag = tag;
		i++;
	} while (i < n);
	i = 0;
	int a, b;
	do {
		if (all[i].tag == 1)cout << all[i].num;
		else {
			a = all[i].num / 13, b = all[i].num % 13;
			if (a) cout << high[a];
			if(a&&b) cout << ' ';
			if(b || (!a && !b))cout << nor[b];
		}
		if (i != n - 1) cout << endl;
		i++;
	} while (i < n);
	return 0;
}
