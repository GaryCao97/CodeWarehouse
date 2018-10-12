#include <iostream>
using namespace std;

int Day(int x)
{
	if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0)) return 366;
	else return 365;
}

int main()
{
	int day = 0;
	for (int year = 1995;year <= 2000;year++)
	{
		day += Day(year);
	}
	day -= 21;
	cout << "从1995年1月1日到2000年12月10日共" << day << "天" << endl;
	return 0;
}