#include <iostream>
using namespace std;

int Prime(int x)
{
	for (int n = 2 ; n < x; n++)
	{
		if (x % n == 0){return 0;break;}
	}
	return 1;
}

int main()
{
	cout << "10到40的所有质数之和" << endl;
	int sum = 0;
	for (int i = 10 ; i <= 40; i++)
	{
		if (Prime(i) == 1) 
		{
			sum += i;
			cout << i << " + ";
		}
	}
	cout << '\b' << '\b';
	cout << "= " << sum << endl;
	return 0;
}