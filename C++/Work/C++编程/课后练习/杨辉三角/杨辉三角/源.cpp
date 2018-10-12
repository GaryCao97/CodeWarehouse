#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n[10],m[10];
	for (int i = 1;i <= 10;i++) {n[i] = 0;m[i] = 0;}
	n[1]=1;
	for (int i = 1;i <= 10;i++)
	{
		cout << setiosflags(ios::right) << setw(30 - 3 * i) << " ";
		for (int o = 1;o <= i; o++)
		{
			m[o] = n[o];
			if (o == 1 || o == i) n[o] = 1;
			else n[o] = m[o] + m[o-1];
			cout <<setw(6) << n[o];
		}
		cout << endl;
	}
	return 0;
}