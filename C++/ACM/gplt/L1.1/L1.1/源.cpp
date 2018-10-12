#include<iostream>
using namespace std;
int main(){
	char num[52];
	cin >> num;
	double count = 0;
	int i;
	for (i = 0; i < 52; i++){
		if (num[i] == '2')
			count += 1.0;
		if (num[i] == '\0')
			break;
	}
	if ((num[i - 1] - '0') % 2 == 0)
		count *= 2.0;
	if (num[0] == '-'){
		count *= 1.5;
		i -= 1;
	}
	count = (count / (double)i) * 100.0;
	printf_s("%.4g%%", count);
	return 0;
}