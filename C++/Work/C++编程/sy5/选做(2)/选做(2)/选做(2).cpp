#include <iostream>
using namespace std;
int _gcd,_mul;
void gcd(int a,int b)					/*���Լ��*/
{
	int m = a,n = b,temp;
	for(;n!=0;)
	{
		temp = m;
		m = n;
		n = temp % n;
	}
	_gcd = m;
}
void mul(int a,int b,int g)				/*��С������*/
{
	_mul = (a * b) / g;
}
int main()
{
	int a,b;
	cout << "����������������";
	cin >> a >> b;
	gcd(a,b);
	mul(a,b,_gcd);
	cout << "���Լ��Ϊ��" << _gcd << " ,��С������Ϊ��" << _mul << endl;
}