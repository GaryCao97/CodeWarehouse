#include <iostream>
using namespace std;
int _gcd,_mul;
void gcd(int a,int b)					/*最大公约数*/
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
void mul(int a,int b,int g)				/*最小公倍数*/
{
	_mul = (a * b) / g;
}
int main()
{
	int a,b;
	cout << "请输入两个整数：";
	cin >> a >> b;
	gcd(a,b);
	mul(a,b,_gcd);
	cout << "最大公约数为：" << _gcd << " ,最小公倍数为：" << _mul << endl;
}