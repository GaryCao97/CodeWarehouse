#include <iostream>
#include <iomanip>
using namespace std;

int chengfabiao(int m)
{
	cout << setiosflags(ios::left);
	for(int n = 1; n <= m; n++)
	{
		cout << n << "*" << m << "=" << setw(4) << n*m;
	}
	cout << endl;
	return 0;
}

int main()
{
	for (int n=1;n<=9;n++)
	{
		chengfabiao(n);
	}
}