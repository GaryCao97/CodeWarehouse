#include <iostream>
using namespace std;
int gcd(int a,int b)					/*���Լ��*/
{
	int m = a,n = b,temp;
	for(;n!=0;)
	{
		temp = m;
		m = n;
		n = temp % n;
	}
	return m;
}
int mul(int a,int b,int g)				/*��С������*/
{
	return ((a * b) / g);
}
int main()
{
	int a,b;
start:
	cout << "����������������";
	cin >> a >> b;
	cout << "���Լ��Ϊ��" << gcd(a,b) << " ,��С������Ϊ��" << mul(a,b,gcd(a,b)) << endl;
	goto start;
}