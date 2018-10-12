#include <iostream>
using namespace std;

int no_repeat(int x)
{
	int a = x/1000 , b = (x % 1000) / 100, c = (x%100) / 10, d = x % 10;
	if (a != b && a != c && a != d && b != c && b != d && c != d) return 1;
	else return 0;
}

int main()
{
	for (int num = 1010; num <= 9999; num+=2)
	{
		if (no_repeat(num) == 1) cout << num << " ";
	}
	return 0;
}