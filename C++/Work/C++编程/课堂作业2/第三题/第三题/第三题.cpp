#include <iostream>
using namespace std;
int main()
{
	double num , max , n = 0;
loop:
	cout << "Enter a number: ";
	cin >> num;
	if (n++ == 0) max = num;
	else max = max > num ? max : num;
	if (num > 0) goto loop;
	cout << "The largest number entered was " << max << endl;
	return 0;
}