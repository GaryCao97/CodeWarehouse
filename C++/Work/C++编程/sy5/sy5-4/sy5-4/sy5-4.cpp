#include <iostream>
using namespace std;
int gcd(int a,int b)					/*最大公约数*/
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
int mul(int a,int b,int g)				/*最小公倍数*/
{
	return ((a * b) / g);
}
int main()
{
	int a,b;
start:
	cout << "请输入两个整数：";
	cin >> a >> b;
	cout << "最大公约数为：" << gcd(a,b) << " ,最小公倍数为：" << mul(a,b,gcd(a,b)) << endl;
	goto start;
}