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
	cout << "��1995��1��1�յ�2000��12��10�չ�" << day << "��" << endl;
	return 0;
}