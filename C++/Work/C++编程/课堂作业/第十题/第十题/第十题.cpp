#include <iostream>
using namespace std;

int Daffodil(int x)
{
	int a = x / 100 ,b = (x % 100) / 10, c = x % 10;
	int cube = a*a*a + b*b*b + c*c*c;
	if (x == cube) return 1;
	else return 0;
}

int main()
{
	cout << "三位数中的水仙花数分别是：" ;
	for (int n = 100; n <= 999; n++)
	{
		if (Daffodil(n) == 1) cout << n << ", ";
	}
	cout << endl;
	return 0;
}