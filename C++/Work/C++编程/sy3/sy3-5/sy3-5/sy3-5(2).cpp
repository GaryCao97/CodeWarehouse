#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	float pi = 0;
	int n = 1;
	do 
	{
		pi = pi + 1.0 / (n * n);
		n++;
	}while ( (1.0 / (n * n)) >= 0.0001);
	pi = pi * 6;
	pi = sqrt(pi);
	cout << "��=" << pi << "  n=" << n - 1 << endl;
	return 0;
}