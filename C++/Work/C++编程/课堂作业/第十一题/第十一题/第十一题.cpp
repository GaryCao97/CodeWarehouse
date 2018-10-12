#include <iostream>
using namespace std;

int division11(int x)
{
	if (x % 11 == 0) return 1;
	else return 0;
}

int no_repeat(int x)
{
	int a = x / 100 , b = (x % 100) / 10 , c = x % 10;
	if (a != b && a != c && b != c)return 1;
	else return 0;
}

int main()
{
	int n = 0;
	for (int i = 100;i <= 999;i++)
	{
		if((division11(i) && no_repeat(i)) == 1)
		{
			cout << i << " ";
			n++;
		}
	}
	cout << endl << "¹²" << n << "¸ö" << endl;
	return 0;
}