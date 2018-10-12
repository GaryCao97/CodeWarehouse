#include <iostream>
using namespace std;
int main()
{
loop:
	cout << "请输入一个整数：";
	int num;
	cin >> num;
	cout << "Integer " << num << " is a ";
	if (num >= 0) {cout << "positive ";}
	else {cout << "negative ";}
	if (num % 2 == 0) {cout << "even number, ";}
	else {cout << "odd number, ";}
	cout << "and its range is ";
	if (num >= -10 && num <= 10) cout << "small than 10.";
	else if ((num >= 10 && num <= 99) || (num >= -99 && num <= -10)) cout << "from 10 to 99.";
	else if ((num >= 100 && num <= 999) || (num >= -999 && num <= -100)) cout << "from 100 to 999.";
	else if ((num >= 1000 || num <= -1000)) cout << "large than 1000.";
	cout << endl;
	goto loop;
	return 0;
}