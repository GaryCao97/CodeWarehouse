#include<iostream>
#include<math.h>
using namespace std;
int main()
{
loop:
	float pi = 0;
	int n;
	cout<<"����������n��";
	cin >> n;
	for ( int i = 1;i<=n;i++)
	{
		pi += 1.0/pow(i,2);
	}
	pi = pi * 6;
	pi = sqrt(pi);
	cout << "��=" << pi << endl;
	goto loop;
	return 0;
}