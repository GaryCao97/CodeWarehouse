#include <iostream>
using namespace std;
int gcd(int a,int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b,a%b);
}
int mul(int a,int b,int g)
{
	return ( (a * b) / g);
}
int main()
{
	int a,b;
	cout << "����������������";
	cin >> a >> b;
	cout << "���Լ��Ϊ��" << gcd(a,b) << " ,��С������Ϊ��" << mul(a,b,gcd(a,b)) << endl;
}